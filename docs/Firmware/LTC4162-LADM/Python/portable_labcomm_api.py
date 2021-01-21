'''Standalone Python module for performing SMBus transactions remotely
over byte-oriented serial links via the Labcomm packet protocol.

RS232, USB virtual serial ports, and TCP/IP sockets are commonly-used
byte-oriented serial links.

Work-in-progress; useable if necessary to ship something right now
to a customer, but should be cleaned up before general publication.

In particular, we should finish implementing all the read/write byte
protocols, and consider moving the debug print statements in
Labcomm_pyserial_interface.ask() to spew to Python's logging module.

FL 2018-05-16'''

# Copyright 2018 by Analog Devices, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a 
# copy of this software and associated documentation files (the "Software"), 
# to deal in the Software without restriction, including without limitation 
# the rights to use, copy, modify, merge, publish, distribute, sublicense, 
# and/or sell copies of the Software, and to permit persons to whom the 
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in 
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
# DEALINGS IN THE SOFTWARE.

try:
    import serial  # PySerial 3.x required.
except ImportError as e:
    print ("PySerial 3.x required, 3.4+ preferred. "
           "Couldn't find PySerial at all.")
    raise e
if hasattr(serial, "__version__"):
    _serial_version = float(serial.__version__)
elif hasattr(serial, "VERSION"):
    _serial_version = float(serial.VERSION)
else:
    raise TypeError, ("\n\n*** PySerial found but couldn't determine which version. "
                      "PySerial 3.x required, 3.4+ preferred.")
if _serial_version < 3.0:
    raise TypeError, ("\n\n*** PySerial 3.x required, 3.4+ preferred. "
                      "Found PySerial {}. "
                      "Please upgrade.").format(_serial_version)
elif _serial_version < 3.4:
    print ("WARNING: PySerial 3.4+ preferred. "
           "Found PySerial {} only, which I'll try "
           "to use.").format(_serial_version)

from serial.serialutil import SerialException, SerialTimeoutException

# Python standard library imports:
import struct, time, random, sys
from array import array
from numbers import Real, Integral
from collections import Sequence
import logging
errlog = logging.getLogger(__name__)
dbgprint = errlog.debug

# Utility modules included with this API:
import structtuple

#
# Define exceptions we can throw:
#
#   robust_serial exceptions
#
class robust_serial_exception(Exception):
    "Base class for exceptions from the robust_serial wrapper"
    pass
class no_serial_object(robust_serial_exception):
    "No serial port found (yet)"
    pass
class no_board_connected(robust_serial_exception): #not implemented
    "No board is connected to the previously connected serial port"
    pass
class communication_error(robust_serial_exception): #not implemented
    "There was either an i2c error or a PEC error"
    pass
#
#   Labcomm exceptions:
#
class Labcomm_Exception(Exception):
    "Base class for all exceptions from the Labcomm packet interface"
    pass
class timeout(Labcomm_Exception):
    "Generic Labcomm timeout"
    pass
class send_timeout(timeout):
    "Labcomm send/transmit timeout"
    pass
class receive_timeout(timeout):
    "Labcomm receive timeout"
    pass
#
#   SMBus errors from the Labcomm peer are raised as Python exceptions:
#
class SMBus_Exception(Exception):
    "Base class for all exceptions from the SMBus interface"
    pass
class i2c_error(SMBus_Exception):
    "Unexpected NACKs"
    pass
class PEC_error(SMBus_Exception):
    "Packet Error Check (PEC) failure / SMBus traffic corruption"
    pass
class command_not_implemented(SMBus_Exception):
    "SMBus Labcomm firmware module did not recognize command"
    pass

#
# Public classes
#
class SMBus_interface(object):
    '''Base class defining an API to hardware that provides the following SMBus protocols:
            ReadWord
            WriteWord
            ReadByte
            WriteByte
            ReceiveByte
            SendByte
            AlertResponse '''
    def alert_response(self):
        '''SMBus Alert Response Protocol.
           Returns None if no response to ARA, otherwise the responding device address
           is placed in the 7 most significant bits of the returned byte.'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def read_smbalert(self):
        '''Returns the state of the SMBALERT# signal, where
           True means SMBALERT# is asserted (active low),
           False means SMBALERT# is not asserted (high).'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def read_byte(self, addr_7bit, command_code):
        '''SMBus Read Byte Protocol.
           Slave device address specified in 7-bit format.
           Returns 8-bit data from slave.'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def read_word(self, addr_7bit, command_code):
        '''SMBus Read Word Protocol.
           Slave device address specified in 7-bit format.
           Returns 16-bit data from slave.'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def receive_byte(self, addr_7bit):
        '''SMBus Receive Byte Protocol.
           Slave device address specified in 7-bit format.
           Returns 8-bit data from slave.'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def send_byte(self, addr_7bit, data8):
        '''SMBus Send Byte Protocol.
           Returns None.'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def write_byte(self, addr_7bit, command_code, data8):
        '''SMBus Write Byte Protocol.
        Slave device address specified in 7-bit format.
        Returns None.'''
        raise NotImplementedError  # See implementation code in subclasses below.
    def write_word(self, addr_7bit, command_code, data16):
        '''SMBus Write Word Protocol.
        Slave device address specified in 7-bit format.
        Returns None.'''
        raise NotImplementedError  # See implementation code in subclasses below.

class SMBus_Labcomm_interface(SMBus_interface):
    '''An implementation of the SMBus_interface API over serial links
       to communicate with SMBus-capable microcontrollers
       on certain Linear Technology demoboards.
       Requires PySerial.'''
    #
    #  The demoboard's SMBUS-over-Labcomm firmware module (dest_id=0x0020),
    #  understands commands of the form:
    #
    #  typedef union
    #  {
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #    } common; // fields common to all commands.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint32_t tag;
    #    } read_smbalert; // Read the logic state of the /SMBALERT SMBus signal.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint32_t tag;
    #    } read_ARA_PECorNot; // Read Alert Response Address (ARA) command, PEC or no PEC spec'd by noun.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #    } read_single_v1; // fields common to all commands that read from a single command code.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint32_t tag;
    #    } read_single_v2; // commands that read from a single command code and provide a tag
    #                      // to be sent in the response packet.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;   // must be LABCOMM_SMBUS_NOUN_BYTE_V2 == 0x0c
    #      uint8_t verb;   // must be LABCOMM_SMBUS_VERB_SEND == 3
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint32_t tag;
    #    } send_byte; // SEND BYTE command. Unlike Write Byte, this sends command code only, no data.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint8_t data8;
    #    } write_byte_v1; // // Deprecated version 1 of WRITE BYTE command. (Lacks tag)
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint8_t data8;
    #      uint32_t tag;     // Opaque value copied verbatim into the response, allowing
    #                        // the sender to match response packet to command packet.
    #    } write_byte_v2; // WRITE BYTE command.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint16_t data16;
    #    } write_word; // WRITE WORD command.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint8_t data8;
    #      uint8_t pec_opt;
    #      uint32_t tag;     // Opaque value copied verbatim into the response, allowing
    #                        // the sender to match response packet to command packet.
    #    } write_byte_pec; // WRITE BYTE_PEC command.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint16_t data16;
    #      uint8_t pec;
    #    } write_word_pec_v1; // Deprecated version 1 of WRITE WORD_PEC command.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;
    #      uint8_t verb;
    #      uint8_t addr7;
    #      uint8_t cc;
    #      uint16_t data16;
    #      uint16_t pec_opt;  // 0x0 to 0xff: passed through as PEC value to send on SMBus.
    #                         // 0x0100: automatically insert correct PEC byte to send.
    #                         // 0x0101 to 0xffff: undefined behavior re: PEC byte to send.
    #      uint32_t tag;      // Opaque value copied verbatim into the response, allowing
    #                         // the sender to match response packet to command packet.
    #                         //
    #    } write_word_pec_v2; // WRITE WORD_PEC command (version 2, current).
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;                                         // specifies SMBus command type.
    #      uint8_t verb;                                         // specifies whether read/write
    #      uint8_t addr7;                                        // 7 bit i2c address
    #      uint8_t bitmap_reg[(UINT8_MAX+1)/BITS_PER_BYTE];      // bitmap of registers to read.
    #    } read_word_list_pec_v1; // (Deprecated version 1) READ WORD_LIST_PEC command.
    #    struct __attribute__((packed))
    #    {
    #      uint8_t noun;                                         // specifies SMBus command type.
    #      uint8_t verb;                                         // specifies whether read/write
    #      uint8_t addr7;                                        // 7 bit i2c address
    #      uint32_t tag;                                         // Opaque identifier value copied
    #                                                            //   verbatim to response.
    #      uint8_t bitmap_reg[(UINT8_MAX+1)/BITS_PER_BYTE];      // bitmap of registers to read.
    #    } read_word_list_pec_v2; // READ WORD_LIST_PEC command (Current version with transaction tag).
    #  } LABCOMM_SMBUS_COMMAND_TYPE;
    #
    #  Some useful magic numbers for constructing and decoding these packets:
    class noun:
        """This SMBus module interprets commands in a verb-noun format.
        This class defines the vocabulary of possible nouns."""
        BYTE = 0x00
        WORD = 0x01
        BYTE_PEC = 0x02
        WORD_PEC = 0x03
        SMBALERT = 0x04
        RESERVED_05 = 0x05    # Not used at this time.
        RESERVED_06 = 0x06    # Not used at this time.
        STATELESS_WORD_LIST_PEC = 0x07
        ARA = 0x08
        ARA_PEC = 0x09
        WORD_PEC_V2 = 0x0a
        STATELESS_WORD_LIST_PEC_V2 = 0x0b
        BYTE_V2 = 0x0c        # Read/Write/etc. byte commands with transaction tags
                              # and timestamps
        WORD_V2 = 0x0d        # Read/Write/etc. word commands with transaction tags
                              # and timestamps
    class verb:
        """This SMBus module interprets commands in a verb-noun format.
        This class defines the vocabulary of possible nouns."""
        READ = 0
        WRITE = 1
        RESERVED_02 = 2       # Not used at this time.
        SEND = 3
    class pec_option:
        """The WRITE x_PEC commands allow the sender to either specify the exact PEC value
        to transmit on the SMBus, or a command to automatically compute and transmit
        correct PEC."""
        SEND_CORRECT_PEC = 0x0100  # WRITE WORD PEC v2 pec_opt to ask firmware to send correct PEC.
    MAX_NUMBER_OF_COMMAND_CODES = 2**8  # This module assumes 8-bit command codes.
    BITS_PER_BYTE = 8
    class smbus:
        "SMBus-related constants"
        general_call_address_7bit = 0x00
        smbus_host_address_7bit = 0x08
        smart_battery_charger_address_7bit = 0x09
        smart_battery_selector_address_7bit = 0x0a
        smart_battery_address_7bit = 0x0b
        alert_response_address_7bit = 0x0c
    class status_code:
        "SMBus firmware module status codes"
        OK = 0
        I2C_ERR = 1
        PEC_ERR = 2
        NOT_IMPLEMENTED = 3

    #
    # Command packet template definitions:
    #

    ########################### Read Word PEC command packet template #################################
    read_word_pec_v2_cmd_class = \
        structtuple.make_structtuple_class('read_word_pec_v2_cmd_class', endianness='>',
                                            fieldlist=(('noun', 'B'),
                                                       ('verb', 'B'),
                                                       ('addr_7bit', 'B'),
                                                       ('cc', 'B'),
                                                       ('tag', 'L')))
    #   READ WORD PEC command packet template
    read_word_pec_v2_cmd = read_word_pec_v2_cmd_class(noun=noun.WORD_PEC_V2, verb=verb.READ,
                                                      addr_7bit=0, cc=0, tag=0)._replace

    ########################### Write Word PEC command packet template ################################
    write_word_pec_v2_cmd_class = \
        structtuple.make_structtuple_class('write_word_pec_v2_cmd_class', endianness='>',
                                           fieldlist=(('noun', 'B'),
                                                      ('verb', 'B'),
                                                      ('addr_7bit', 'B'),
                                                      ('cc', 'B'),
                                                      ('data16', 'H'),
                                                      ('pec_opt', 'H'),
                                                      ('tag', 'L')))
    #   WRITE WORD PEC command packet template
    write_word_pec_v2_cmd = write_word_pec_v2_cmd_class(noun=noun.WORD_PEC_V2, verb=verb.WRITE,
                                                        addr_7bit=0, cc=0, data16=0,
                                                        pec_opt=0x0100, tag=0)._replace

    ########################### Read Word command packet template #####################################
    read_word_v2_cmd_class = \
        structtuple.make_structtuple_class('read_word_v2_cmd_class', endianness='>',
                                            fieldlist=(('noun', 'B'),
                                                       ('verb', 'B'),
                                                       ('addr_7bit', 'B'),
                                                       ('cc', 'B'),
                                                       ('tag', 'L')))
    #   READ BYTE command packet template
    read_word_v2_cmd = read_word_v2_cmd_class(noun=noun.WORD_V2, verb=verb.READ,
                                              addr_7bit=0, cc=0, tag=0)._replace

    ########################### Write Word command packet template ####################################
    write_word_v2_cmd_class = \
        structtuple.make_structtuple_class('write_word_v2_cmd_class', endianness='>',
                                            fieldlist=(('noun', 'B'),
                                                       ('verb', 'B'),
                                                       ('addr_7bit', 'B'),
                                                       ('cc', 'B'),
                                                       ('data16', 'H'),
                                                       ('tag', 'L')))
    #   WRITE BYTE command packet template
    write_word_v2_cmd = write_word_v2_cmd_class(noun=noun.WORD_V2, verb=verb.WRITE,
                                                addr_7bit=0, cc=0, data16=0, tag=0)._replace

    ########################### Read Word List PEC command packet template ############################
    read_word_list_pec_v2_cmd_class = \
        structtuple.make_structtuple_class(
            'read_word_list_pec_v2_cmd_class', endianness='>',
                 fieldlist=(('noun', 'B'),
                            ('verb', 'B'),
                            ('addr_7bit', 'B'),
                            ('tag', 'L'),
                            ('cc_bitmap', '{:d}s'.format(MAX_NUMBER_OF_COMMAND_CODES / BITS_PER_BYTE))))
    #   READ WORD LIST PEC command packet template
    read_word_list_pec_v2_cmd = read_word_list_pec_v2_cmd_class(noun=noun.STATELESS_WORD_LIST_PEC_V2,
                                                                verb=verb.READ,
                                                                addr_7bit=0,
                                                                tag=0,
                                                                cc_bitmap='\0'*32)._replace

    ########################### Read ARA PEC command packet template ##################################
    read_ARA_pec_cmd_class = \
        structtuple.make_structtuple_class('read_ARA_pec_cmd_class', endianness='>',
                                           fieldlist=(('noun', 'B'),
                                                      ('verb', 'B'),
                                                      ('tag', 'L')))
    #   READ ARA PEC command packet template
    read_ARA_pec_cmd = read_ARA_pec_cmd_class(noun=noun.ARA_PEC, verb=verb.READ, tag=0)._replace

    ########################### Read ARA command packet template ##################################
    read_ARA_cmd_class = \
        structtuple.make_structtuple_class('read_ARA_cmd_class', endianness='>',
                                           fieldlist=(('noun', 'B'),
                                                      ('verb', 'B'),
                                                      ('tag', 'L')))
    #   READ ARA command packet template
    read_ARA_cmd = read_ARA_cmd_class(noun=noun.ARA, verb=verb.READ, tag=0)._replace

    ########################### Read /SMBALERT command packet template ################################
    read_smbalert_cmd_class = \
        structtuple.make_structtuple_class('read_smbalert_cmd_class', endianness='>',
                                           fieldlist=(('noun', 'B'),
                                                      ('verb', 'B'),
                                                      ('tag', 'L')))
    #   READ SMBALERT command packet template
    read_smbalert_cmd = read_smbalert_cmd_class(noun=noun.SMBALERT, verb=verb.READ, tag=0)._replace

    ########################### Read Byte command packet template #####################################
    read_byte_v2_cmd_class = \
        structtuple.make_structtuple_class('read_byte_v2_cmd_class', endianness='>',
                                            fieldlist=(('noun', 'B'),
                                                       ('verb', 'B'),
                                                       ('addr_7bit', 'B'),
                                                       ('cc', 'B'),
                                                       ('tag', 'L')))
    #   READ BYTE command packet template
    read_byte_v2_cmd = read_byte_v2_cmd_class(noun=noun.BYTE_V2, verb=verb.READ,
                                              addr_7bit=0, cc=0, tag=0)._replace

    ########################### Write Byte command packet template ####################################
    write_byte_v2_cmd_class = \
        structtuple.make_structtuple_class('write_byte_v2_cmd_class', endianness='>',
                                            fieldlist=(('noun', 'B'),
                                                       ('verb', 'B'),
                                                       ('addr_7bit', 'B'),
                                                       ('cc', 'B'),
                                                       ('data8', 'B'),
                                                       ('tag', 'L')))
    #   WRITE BYTE command packet template
    write_byte_v2_cmd = write_byte_v2_cmd_class(noun=noun.BYTE_V2, verb=verb.WRITE,
                                                addr_7bit=0, cc=0, data8=0, tag=0)._replace

    ############################ Send Byte command packet template ####################################
    send_byte_cmd_class = \
        structtuple.make_structtuple_class('send_byte_cmd_class', endianness='>',
                                            fieldlist=(('noun', 'B'),
                                                       ('verb', 'B'),
                                                       ('addr_7bit', 'B'),
                                                       ('cc', 'B'),
                                                       ('tag', 'L')))
    #   SEND BYTE command packet template
    send_byte_cmd = send_byte_cmd_class(noun=noun.BYTE_V2, verb=verb.SEND,
                                        addr_7bit=0, cc=0, tag=0)._replace

    #
    # SMBus_Labcomm_interface constructor
    #
    def __init__(self, serial_port, PEC=True, src_id=None,
                 dest_id=0x0020, # Latest SMBus over Labcomm demoboard firmware module, 2018-05-08.
                 read_timeout_sequence=(0.1, 0.1, 0.1), write_timeout_sequence=(0.2,),
                 debug=False, **kwargs):
        '''Create an SMBus_interface bound to the named serial_port,
           for example: "COM24" (Windows) or "/dev/ttyACM3" (Linux/BSD/MacOS), or
           to the given PySerial serial.Serial object, or any serial.Serial-like
           object.
           Serial port should be one connected to an Analog Devices
           (legacy Linear Technology) demoboard that communicates via Labcomm packets.
           kwargs will be passed to PySerial's serial.Serial init unless
           serial_port is a PySerial serial.Serial object or any object
           with the methods read(), write(), and close(), and the properties
           timeout, write_timeout, and in_waiting that conform to the
           serial.Serial API.
           dest_id must point to an SMBus firmware module at the other side of the serial link.
           src_id is a 16-bit integer identifying us. If src_id is None, a random src_id
           will be assigned from 0x8000 and 0xffff inclusive.'''
        self._tag_val = 0
        if isinstance(serial_port, serial.Serial) or is_serial_like(serial_port):
            self.serial_port = serial_port
        else:
            assert isinstance(serial_port, basestring)
            if 'timeout' not in kwargs:
                kwargs['timeout'] = 1
            if 'baudrate' not in kwargs:
                kwargs['baudrate'] = 115200
            self.serial_port = serial.Serial(serial_port, **kwargs)
        if src_id is None:
            self.src_id = random.randint(2**(self.BITS_PER_BYTE*packet.SRC_ID_SIZE-1),  # 2^15
                                         2**(self.BITS_PER_BYTE*packet.SRC_ID_SIZE)-1)  # 2^16 - 1
        elif isinstance(src_id, Integral) and src_id > 0 and src_id < 2**(self.BITS_PER_BYTE*packet.SRC_ID_SIZE):
            self.src_id = src_id
        else:
            raise ValueError, "Labcomm src_id value must be a 16-bit integer"
        if isinstance(dest_id, Integral) and dest_id > 0 and dest_id < 2**(self.BITS_PER_BYTE*packet.DEST_ID_SIZE):
            self.dest_id = dest_id
        else:
            raise ValueError, "Labcomm dest_id value must be a 16-bit integer"
        self.intf = Labcomm_pyserial_interface(self.serial_port, debug=debug)  # Bind Labcomm interface to the port.
        self.set_pec(PEC)
        self.debug = debug
        assert isinstance(read_timeout_sequence, Sequence) and isinstance(read_timeout_sequence[0], Real)
        assert isinstance(write_timeout_sequence, Sequence) and isinstance(read_timeout_sequence[0], Real)
        self._read_timeouts = read_timeout_sequence
        self._write_timeouts = write_timeout_sequence
        #
        # Here are the Labcomm response packets that we understand, in C struct format:
        #
        #  typedef union
        #  {
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;
        #      uint8_t verb;
        #    } common; // All responses have these fields in common.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;
        #      uint8_t verb;
        #      uint8_t active;     // State of SMBALERT#:
        #                          //   1 == asserted/active low,  0 == deasserted/high
        #      uint32_t timestamp; // Arduino micros() value: timestamp in rolling 32-bit counter.
        #      uint32_t tag;       // Opaque value copied verbatim into the response, allowing
        #                          //   the sender to match response packet to command packet.
        #    } smbalert; // Response to READ SMBALERT command.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;       // Must be LABCOMM_SMBUS_NOUN_ARA
        #      uint8_t verb;       // Must be LABCOMM_SMBUS_VERB_READ
        #      uint8_t responding_addr7; // Meaningful only if status == 0, else undefined.
        #      uint8_t active;     // State of SMBALERT# after reading the Alert Response Address (ARA)
        #                          // 1 == asserted/active low,  0 == deasserted/high
        #      uint8_t got_addr7;  //   1 if we got a response from reading the ARA.
        #                          //      Response is then in responding_addr7.
        #                          //   0 if no response to reading the ARA, in which case
        #                          //      responding_addr7 should be ignored.
        #      uint32_t timestamp; // Arduino micros() value: timestamp in rolling 32-bit counter.
        #      uint32_t tag;       // Opaque value copied verbatim into the response, allowing
        #                          // the sender to match response packet to command packet.
        #    } ARA; // Reply to READ ARA command.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;       // Must be LABCOMM_SMBUS_NOUN_ARA_PEC
        #      uint8_t verb;       // Must be LABCOMM_SMBUS_VERB_READ
        #      uint8_t responding_addr7; // Meaningful only if status == OK, else undefined.
        #      uint8_t active; // State of SMBALERT# *after* reading the Alert Response Address (ARA)
        #                      // 1 == asserted/active low,  0 == deasserted/high
        #      uint8_t status;     // == LABCOMM_SMBUS_STATUS_(OK|PEC_ERR|I2C_ERR)
        #      uint8_t pec;        // Received PEC value, if status is 0 or 1, else undefined.
        #      uint32_t timestamp; // Arduino micros() value: timestamp in rolling 32-bit counter.
        #      uint32_t tag;       // Opaque value copied verbatim into the response, allowing
        #                          // the sender to match response packet to command packet.
        #    } ARA_PEC; // Reply to READ ARA_PEC command
        #    struct __attribute__((packed))
        #    { 
        #      uint8_t noun;
        #      uint8_t verb;
        #      uint8_t addr7;
        #      uint8_t cc;
        #    } single; // fields common to all responses to commands involving a single SMBus address and command code.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;   // must be LABCOMM_SMBUS_NOUN_BYTE_V2 == 0x0c
        #      uint8_t verb;   // must be LABCOMM_SMBUS_VERB_SEND == 3
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint8_t status;     // == LABCOMM_SMBUS_STATUS_(OK|I2C_ERR)
        #      uint32_t timestamp; // Arduino micros() value: timestamp in rolling 32-bit counter.
        #      uint32_t tag;       // Opaque value copied verbatim into the response, allowing
        #                          // the sender to match response packet to command packet.
        #    } send_byte; // Reply to SEND BYTE command. Unlike Write Byte, sends command code only, no data.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;
        #      uint8_t verb;
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint8_t data8;
        #    } read_byte_v1; // Deprecated version 1 of Reply to READ BYTE and WRITE BYTE commands.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;
        #      uint8_t verb;
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint8_t data8;
        #      uint8_t status;      // == LABCOMM_SMBUS_STATUS_(OK|I2C_ERR|PEC_ERR)
        #      uint32_t timestamp;  // timestamp in rolling 32-bit counter.
        #      uint32_t tag;        // Tag value copied verbatim from command packet
        #                           //   causing this response packet.
        #    } read_byte_v2; // Reply to READ BYTE and WRITE BYTE commands.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;
        #      uint8_t verb;
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint16_t data16;
        #    } read_word; // Reply to READ WORD and WRITE WORD commands.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;        // must be LABCOMM_SMBUS_NOUN_BYTE_PEC
        #      uint8_t verb;        // must be LABCOMM_SMBUS_VERB_READ
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint8_t data8;
        #      uint8_t pec;
        #      uint8_t status;      // == LABCOMM_SMBUS_STATUS_(OK|I2C_ERR|PEC_ERR)
        #      uint32_t timestamp;  // timestamp in rolling 32-bit counter.
        #      uint32_t tag;        // Tag value copied verbatim from command packet
        #                           //   causing this response packet.
        #    } read_byte_pec; // Reply to READ BYTE_PEC and WRITE BYTE_PEC commands.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;
        #      uint8_t verb;
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint16_t data16;
        #      uint8_t pec;
        #    } read_word_pec_v1; // (Deprecated version 1) Reply to READ WORD_PEC and WRITE WORD_PEC commands.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;       // == LABCOMM_SMBUS_NOUN_WORD_PEC_V2 = 0x0A
        #      uint8_t verb;
        #      uint8_t addr7;
        #      uint8_t cc;
        #      uint16_t data16;
        #      uint8_t pec;
        #      uint8_t status;     // == LABCOMM_SMBUS_STATUS_(OK|I2C_ERR|PEC_ERR)
        #      uint32_t timestamp; // timestamp in rolling 32 bit counter
        #      uint32_t tag;       // Tag value copied verbatim from command packet causing this response packet.
        #    } read_word_pec_v2;   // Reply to READ WORD_PEC and WRITE WORD_PEC commands. (Version 2, current)
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;                                         // should be LABCOMM_SMBUS_NOUN_WORD_LIST_PEC_V1
        #      uint8_t verb;                                         // should be LABCOMM_SMBUS_VERB_READ.
        #      uint8_t addr7;                                        // 7 bit i2c address of target device.
        #      uint8_t bitmap_reg[(UINT8_MAX+1)/BITS_PER_BYTE];      // bitmap of registers read.
        #      uint32_t timestamp;                                   // timestamp in rolling 32 bit counter
        #      uint16_t data16[0];                                   // data read (no PECs just data), variable length
        #      uint8_t bitmap_success[(UINT8_MAX+1)/BITS_PER_BYTE];  // bitmap of success reading registers.
        #    } read_word_list_pec_v1; // (Deprecated version 1 without tag) Reply to READ WORD_LIST_PEC command.
        #    struct __attribute__((packed))
        #    {
        #      uint8_t noun;                                         // should be LABCOMM_SMBUS_NOUN_WORD_LIST_PEC_V2
        #      uint8_t verb;                                         // should be LABCOMM_SMBUS_VERB_READ.
        #      uint8_t addr7;                                        // 7 bit i2c address of target device.
        #      uint8_t bitmap_reg[(UINT8_MAX+1)/BITS_PER_BYTE];      // bitmap of registers read.
        #      uint32_t tag;                                         // Tag value copied verbatim from command packet
        #                                                            //   causing this response packet.
        #      uint32_t timestamp;                                   // timestamp in rolling 32 bit counter
        #      uint16_t data16[0];                                   // data read (no PECs just data), variable length
        #      uint8_t bitmap_success[(UINT8_MAX+1)/BITS_PER_BYTE];  // bitmap of success reading registers.
        #    } read_word_list_pec_v2; // Reply to READ WORD_LIST_PEC command. (Current version with transaction tag)
        #  } LABCOMM_SMBUS_RESPONSE_TYPE;
        #
        # Here we define structtuples and parsers for these responses:
        #
        self.read_word_pec_v2_response = structtuple.make_structtuple_class(struct_name="read_word_pec_v2_response",
                                                                            endianness='>',
                                                                            fieldlist=[('noun', 'B'),
                                                                                       ('verb', 'B'),
                                                                                       ('addr_7bit', 'B'),
                                                                                       ('cc', 'B'),
                                                                                       ('data16', 'H'),
                                                                                       ('pec', 'B'),
                                                                                       ('status', 'B'),
                                                                                       ('timestamp', 'L'),
                                                                                       ('tag', 'L')])
        self.read_word_pec_v2_parser = self.read_word_pec_v2_response.from_bytes
        self.read_word_pec_v1_response = structtuple.make_structtuple_class(struct_name="read_word_pec_v1_response",
                                                                            endianness='>',
                                                                            fieldlist=[('noun', 'B'),
                                                                                       ('verb', 'B'),
                                                                                       ('addr_7bit', 'B'),
                                                                                       ('cc', 'B'),
                                                                                       ('data16', 'H'),
                                                                                       ('pec', 'B')])
        self.read_word_pec_v1_parser = self.read_word_pec_v1_response.from_bytes
        self.read_word_list_pec_v2_response = \
            structtuple.make_structtuple_class(
                     struct_name="read_word_list_pec_v2_response",
                     endianness='>',
                     fieldlist=[('noun', 'B'),
                                ('verb', 'B'),
                                ('addr_7bit', 'B'),
                                ('cc_bitmap', '{:d}s'.format(self.MAX_NUMBER_OF_COMMAND_CODES / self.BITS_PER_BYTE)),
                                ('tag', 'L'),
                                ('timestamp', 'L'),
                                ('data_and_errors', None)])
        self.read_word_list_pec_v2_parser = self.read_word_list_pec_v2_response.from_bytes
        self.read_ara_pec_response = structtuple.make_structtuple_class(struct_name="read_ara_pec_response",
                                                                        endianness='>',
                                                                        fieldlist=[('noun', 'B'),
                                                                                   ('verb', 'B'),
                                                                                   ('responding_addr7', 'B'),
                                                                                   ('active', 'B'),
                                                                                   ('status', 'B'),
                                                                                   ('pec', 'B'),
                                                                                   ('timestamp', 'L'),
                                                                                   ('tag', 'L')])
        self.read_ara_pec_parser = self.read_ara_pec_response.from_bytes
        self.read_ara_response = structtuple.make_structtuple_class(struct_name="read_ara_response",
                                                                    endianness='>',
                                                                    fieldlist=[('noun', 'B'),
                                                                               ('verb', 'B'),
                                                                               ('responding_addr7', 'B'),
                                                                               ('active', 'B'),
                                                                               ('got_addr7', 'B'),
                                                                               ('timestamp', 'L'),
                                                                               ('tag', 'L')])
        self.read_ara_parser = self.read_ara_response.from_bytes
        self.read_smbalert_response = structtuple.make_structtuple_class(struct_name="read_smbalert_response",
                                                                         endianness='>',
                                                                         fieldlist=[('noun', 'B'),
                                                                                    ('verb', 'B'),
                                                                                    ('active', 'B'),
                                                                                    ('timestamp', 'L'),
                                                                                    ('tag', 'L')])
        self.read_smbalert_parser = self.read_smbalert_response.from_bytes
        self.read_word_v2_response = structtuple.make_structtuple_class(struct_name="read_word_v2_response",
                                                                        endianness='>',
                                                                        fieldlist=[('noun', 'B'),
                                                                                   ('verb', 'B'),
                                                                                   ('addr_7bit', 'B'),
                                                                                   ('cc', 'B'),
                                                                                   ('data16', 'H'),
                                                                                   ('status', 'B'),
                                                                                   ('timestamp', 'L'),
                                                                                   ('tag', 'L')])
        self.read_word_v2_parser = self.read_word_v2_response.from_bytes
        self.read_byte_v1_response = structtuple.make_structtuple_class(struct_name="read_byte_v1_response",
                                                                            endianness='>',
                                                                            fieldlist=[('noun', 'B'),
                                                                                       ('verb', 'B'),
                                                                                       ('addr_7bit', 'B'),
                                                                                       ('cc', 'B'),
                                                                                       ('data16', 'H'),
                                                                                       ('pec', 'B')])
        self.read_byte_v1_parser = self.read_byte_v1_response.from_bytes
        self.read_byte_v2_response = structtuple.make_structtuple_class(struct_name="read_byte_v2_response",
                                                                            endianness='>',
                                                                            fieldlist=[('noun', 'B'),
                                                                                       ('verb', 'B'),
                                                                                       ('addr_7bit', 'B'),
                                                                                       ('cc', 'B'),
                                                                                       ('data8', 'B'),
                                                                                       ('status', 'B'),
                                                                                       ('timestamp', 'L'),
                                                                                       ('tag', 'L')])
        self.read_byte_v2_parser = self.read_byte_v2_response.from_bytes
        self.send_byte_response = structtuple.make_structtuple_class(struct_name="send_byte_response",
                                                                     endianness='>',
                                                                     fieldlist=[('noun', 'B'),
                                                                                ('verb', 'B'),
                                                                                ('addr_7bit', 'B'),
                                                                                ('cc', 'B'),
                                                                                ('status', 'B'),
                                                                                ('timestamp', 'L'),
                                                                                ('tag', 'L')])
        self.send_byte_parser = self.send_byte_response.from_bytes
    #
    # SMBus_Labcomm_interface instance methods:
    #
    def set_pec(self, PEC):
        "Call with boolean 'PEC' indicating whether SMBus communications should use Packet Error Checking."
        # First reset everything to our superclass's definitions
        assert PEC in (True, False)
        self.use_PEC_by_default = PEC
        return
    def read_word(self, addr_7bit, command_code, use_PEC=None):
        '''SMBus Read Word Protocol.
        Packet Error Checking controlled by class init.
        Slave device address specified in 7-bit format.
        Returns 16-bit data from slave,
        otherwise raises i2c_error, PEC_error, command_not_implemented,
        or possibly other flavors of SMBus_Exception.'''
        assert use_PEC in (None, True, False)
        use_PEC = self.use_PEC_by_default if use_PEC is None else use_PEC
        if use_PEC:
            return self._read_word_pec_v2(addr_7bit, command_code)
        else:
            return self._read_word_nopec(addr_7bit, command_code)
    def read_word_list(self, addr_7bit, command_code_list, use_PEC=None):
        '''Uses the SMBus Read Word Protocol to read from the given command codes.
        Slave device address specified in 7-bit format.
        Returns a dictionary mapping command codes to the values read.
        If an error occurs reading a command code, its corresponding value in the dictionary
        will be an SMBus_Exception object.'''
        assert use_PEC in (None, True, False)
        use_PEC = self.use_PEC_by_default if use_PEC is None else use_PEC
        if use_PEC:
            return self._read_word_list_pec_v2(addr_7bit, command_code_list)
        else:
            raise NotImplementedError, "TODO: implement non-PEC SMBus read word list"
    def write_word(self, addr_7bit, command_code, data16, use_PEC=None):
        '''SMBus Write Word Protocol.
        Packet Error Checking controlled by class init.
        Slave device address specified in 7-bit format.
        Returns None.'''
        assert use_PEC in (None, True, False)
        use_PEC = self.use_PEC_by_default if use_PEC is None else use_PEC
        if use_PEC:
            return self._write_word_pec_v2(addr_7bit, command_code, data16)
        else:
            return self._write_word_nopec(addr_7bit, command_code, data16)
    def alert_response(self, use_PEC=None):
        '''SMBus Send Byte Protocol.
        Packet Error Checking controlled by class init.
        Slave device address specified in 7-bit format.
        Returns None if no response to ARA, otherwise the responding device address is 
        placed in the 7 most significant bits of the returned byte.
        The returned LSB (R/W bit) will be zero in this implementation (i.e. write address).'''
        assert use_PEC in (None, True, False)
        use_PEC = self.use_PEC_by_default if use_PEC is None else use_PEC
        if use_PEC:
            return self._alert_response_pec()
        else:
            return self._alert_response_nopec()
    def send_byte(self, addr_7bit, data8, use_PEC=None):
        '''SMBus Send Byte Protocol.
        Slave device address specified in 7-bit format.
        Returns None.'''
        assert use_PEC in (None, True, False)
        use_PEC = self.use_PEC_by_default if use_PEC is None else use_PEC
        if use_PEC:
            raise NotImplementedError, "TODO: Implement SMBus Send Byte without PEC."
        else:
            return self._send_byte_nopec(addr_7bit, data8)
    def write_byte(self, addr_7bit, command_code, data8, use_PEC=None):
        '''SMBus Write Byte Protocol.
        Slave device address specified in 7-bit format.
        Returns None.'''
        assert use_PEC in (None, True, False)
        use_PEC = self.use_PEC_by_default if use_PEC is None else use_PEC
        if use_PEC:
            raise NotImplementedError, "TODO: Implement SMBus Write Byte without PEC."
        else:
            return self._write_byte_nopec(addr_7bit, command_code, data8)
    # Utility functions
    def _hex_str(self, integer):
        '''return integer formatted as a hexadecimal string'''
        return hex(integer)[2:].rjust(2,"0").upper()
    def _read_addr(self,addr_7bit):
        '''compute 8-bit read address from 7-bit address'''
        return (addr_7bit << 1) + 1
    def _write_addr(self, addr_7bit):
        '''compute 8-bit write address from 7-bit address'''
        return addr_7bit << 1
    def _word(self, low_byte, high_byte):
        '''Return 16-bit value from two SMBus bytes'''
        return ((high_byte & 0xFF) << 8) + (low_byte & 0xFF)
    def _low_byte(self, data16):
        return data16 & 0xFF
    def _high_byte(self, data16):
        return data16 >> 8
    def _pec(self,byteList):
        '''byteList is an ordered list of every byte in the transaction including address,
        command code (subaddr) and data'''
        crc = 0
        poly = 0x07 #x^8 + x^2 + x^1 + 1, discard x^8 term
        for byte in byteList:
            crc ^= byte
            for cycle in range(8):
                crc <<= 1
                if (crc & 0x100): #msb was set before left shift ( & 0x80)
                    #xor with crc if pre-shift msb was 1
                    crc ^= poly
        return int(crc & 0xFF)
    def check_size(self, data, bits):
        '''make sure data fits within word of length "bits"'''
        assert isinstance(data, Integral)
        assert isinstance(bits, Integral) and bits > 0
        assert data >= 0
        assert data < 2**bits
        return True
    # The actual API functions follow.
    def _read_byte_nopec(self, addr_7bit, command_code):
        "SMBUS read byte (no PEC)"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        data8 = None  # Return this by default if the Read Byte fails.
        cmdbytes = self.read_byte_v2_cmd(addr_7bit=addr_7bit, cc=command_code, tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_byte_v2_parser,
                             self._make_read_byte_v2_template(addr_7bit, command_code, self._tag),
                             self._read_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        elif rpkt.status == self.status_code.OK:
            return rpkt.data8
        elif rpkt.status == self.status_code.I2C_ERR:
            raise i2c_error, "i2c NACK or error"
        elif rpkt.status == self.status_code.NOT_IMPLEMENTED:
            raise command_not_implemented, ("SMBus firmware module didn't recognize "
                                            "our read_byte_v2 command")
    def _write_byte_nopec(self, addr_7bit, command_code, data8):
        "SMBUS write byte (without PEC)"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        self.check_size(data8, bits=8)
        cmdbytes = self.write_byte_v2_cmd(addr_7bit=addr_7bit, cc=command_code, data8=data8,
                                          tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_byte_v2_parser,
                             self._make_read_byte_v2_template(addr_7bit, command_code, self._tag),
                             self._write_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise timeout, "No timely response packet from demoboard"
        elif rpkt.status == self.status_code.OK:
            return rpkt.data8
        elif rpkt.status == self.status_code.I2C_ERR:
            raise i2c_error, "i2c NACK or error"
        elif rpkt.status == self.status_code.NOT_IMPLEMENTED:
            raise command_not_implemented, ("SMBus firmware module didn't recognize "
                                            "our write_byte_v2 command")
    def _read_word_nopec(self, addr_7bit, command_code):
        "SMBUS read word"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        data16 = None  # Return this by default if the read_word_pec fails.
        cmdbytes = self.read_word_pec_v2_cmd(addr_7bit=addr_7bit, cc=command_code, tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_v2_parser,
                             self._make_read_word_v2_template(addr_7bit, command_code, self._tag),
                             self._read_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        elif rpkt.status == self.status_code.OK:
            return rpkt.data16
        elif rpkt.status == self.status_code.I2C_ERR:
            raise i2c_error, "i2c NACK or error"
        elif rpkt.status == self.status_code.NOT_IMPLEMENTED:
            raise command_not_implemented, "SMBus firmware module didn't recognize our read_word_pec_v2 command"
    def _read_word_pec_v2(self, addr_7bit, command_code):
        "SMBUS read word with PEC"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        data16 = None  # Return this by default if the read_word_pec fails.
        cmdbytes = self.read_word_pec_v2_cmd(addr_7bit=addr_7bit, cc=command_code, tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_pec_v2_parser,
                             self._make_read_word_pec_v2_template(addr_7bit, command_code, self._tag),
                             self._read_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        elif rpkt.status == self.status_code.OK:
            return rpkt.data16
        elif rpkt.status == self.status_code.I2C_ERR:
            raise i2c_error, "i2c NACK or error"
        elif rpkt.status == self.status_code.PEC_ERR:
            raise PEC_error, "PEC failure"
        elif rpkt.status == self.status_code.NOT_IMPLEMENTED:
            raise command_not_implemented, "SMBus firmware module didn't recognize our read_word_pec_v2 command"
    def _read_word_list_pec_v2(self, addr_7bit, command_code_list):
        "Read a list of 16-bit words from SMBUS with PEC"
        self.check_size(addr_7bit, bits=8)
        sorted_cc_list = sorted(list(set(command_code_list)))
        # Construct bit array to indicate which command codes to read:
        cc_bitmap_bytes = bytearray(0 for i in range(self.MAX_NUMBER_OF_COMMAND_CODES / self.BITS_PER_BYTE))
        for cc in sorted_cc_list:
            which_byte = cc / self.BITS_PER_BYTE
            which_bit = cc % self.BITS_PER_BYTE
            cc_bitmap_bytes[which_byte] |= 1 << which_bit
        cc_bitmap = str(cc_bitmap_bytes)
        # Construct and send command packet.
        cmdbytes = self.read_word_list_pec_v2_cmd(addr_7bit=addr_7bit, cc_bitmap=cc_bitmap, tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_list_pec_v2_parser,
                             self._make_read_word_list_pec_v2_template(addr_7bit, cc_bitmap, self._tag),
                             self._read_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise receive_timeout("No timely response packet from demoboard")
        # If we run to here then rpkt is the correct response packet.
        # Parse the data for each command code.
        rcvd_words_fmt = ">{:d}H".format(len(sorted_cc_list))
        success_bitmap_fmt = "{:d}B".format(len(cc_bitmap_bytes))
        rcvd_word_list = struct.unpack_from(rcvd_words_fmt, rpkt.data_and_errors)
        # We start a tentative results dictionary mapping each command code
        # to the corresponding word we received.
        results = dict(zip(sorted_cc_list, rcvd_word_list))
        # Then use the success bitmap to overwrite the words with read errors as needed.
        success_bitmap = struct.unpack_from(success_bitmap_fmt, rpkt.data_and_errors, struct.calcsize(rcvd_words_fmt))
        for cc in sorted_cc_list:
            which_byte = cc / self.BITS_PER_BYTE
            which_bit = cc % self.BITS_PER_BYTE
            if success_bitmap[which_byte] & (1 << which_bit):
                # Successfully read from command code cc.
                pass
            else:
                # An error occurred reading cc. Unfortunately, this command
                # doesn't distinguish PEC errors and i2c errors.
                results[cc] = i2c_error("i2c or PEC error")
        return results
    def _read_word_pec_v1(self, addr_7bit, command_code):
        "(deprecated v1 implementation of) SMBUS read word with PEC"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        data16 = None  # Return this by default if the read_word_pec fails.
        cmdbytes = struct.pack('BBBB', self.noun.WORD_PEC, self.verb.READ, addr_7bit, command_code)
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_pec_v1_parser,
                             self._make_read_word_pec_v1_template(addr_7bit, command_code), self._read_timeouts)
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        else:
            return rpkt.data16
    def _write_word_nopec(self, addr_7bit, command_code, data16):
        "SMBUS write word with PEC. Can specify PEC code to send using 'pec' optional argument."
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        self.check_size(data16, bits=16)
        cmdbytes = self.write_word_pec_v2_cmd(addr_7bit=addr_7bit, cc=command_code, data16=data16,
                                              tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_v2_parser,
                             self._make_read_word_pec_v2_template(addr_7bit, command_code, self._tag),
                             self._write_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise timeout, "No timely response packet from demoboard"
        else:
            return rpkt.data16
    def _write_word_pec_v2(self, addr_7bit, command_code, data16, pec=None):
        "SMBUS write word with PEC. Can specify PEC code to send using 'pec' optional argument."
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        self.check_size(data16, bits=16)
        # If a particular pec byte is specified, send it, otherwise have firmware compute correct PEC.
        assert pec is None or self.check_size(pec, self.BITS_PER_BYTE)
        pec_opt = self.pec_option.SEND_CORRECT_PEC if pec is None else pec  # Use pec argument value if specified.
        cmdbytes = self.write_word_pec_v2_cmd(addr_7bit=addr_7bit, cc=command_code, data16=data16,
                                              pec_opt=pec_opt, tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_pec_v2_parser,
                             self._make_read_word_pec_v2_template(addr_7bit, command_code, self._tag),
                             self._write_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise timeout, "No timely response packet from demoboard"
        else:
            return rpkt.data16
    def _write_word_pec_v1(self, addr_7bit, command_code, data16):
        "(deprecated v1 implementation of) SMBUS write word with PEC"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        self.check_size(data16, bits=16)
        pec = self._pec([self._write_addr(addr_7bit), command_code, self._low_byte(data16), self._high_byte(data16)])
        cmdbytes = struct.pack('>BBBBHB', self.noun.WORD_PEC, self.verb.WRITE,
                               addr_7bit, command_code, data16, pec)
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_word_pec_v1_parser,
                             self._make_read_word_pec_v1_template(addr_7bit, command_code), self._write_timeouts)
        if rpkt is None:
            raise timeout, "No timely response packet from demoboard"
        else:
            return rpkt.data16
    def _alert_response_pec(self):
        "SMBUS Alert Response Address with PEC"
        cmdbytes = self.read_ARA_pec_cmd(tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_ara_pec_parser,
                             self._make_read_ara_pec_template(self._tag), self._read_timeouts)
        self._tag_increment()
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        elif rpkt.status == self.status_code.I2C_ERR:
            dbgprint('Reply ID 0x{:08x}: '
                     'No response to ARA (SMBus read byte to Alert Response Address)'.format(rpkt.tag))
            return None   # Common occurence; no need to raise exception.
        elif rpkt.status == self.status_code.PEC_ERR:
            msg = ('Reply ID 0x{:08x}: '
                   'ARA failed PEC. Got PEC == 0x{:02x} at time '
                   ' 0x{:08x}').format(rpkt.tag, rpkt.pec, rpkt.timestamp)
            dbgprint(msg)
            raise PEC_error, msg
        else:
            dbgprint('Reply to cmd ID 0x{:08x}: ARA reads 0x{:02x} at time '
                     ' 0x{:08x}'.format(rpkt.tag, rpkt.responding_addr7, rpkt.timestamp))
            return rpkt.responding_addr7
    def _alert_response_nopec(self):
        "SMBUS Alert Response Address"
        cmdbytes = self.read_ARA_cmd(tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_ara_parser,
                             self._make_read_ara_template(self._tag), self._read_timeouts)
        self._tag_increment()
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        elif rpkt.got_addr7 == 0:
            dbgprint('Reply ID 0x{:08x}: '
                     'No response to ARA (SMBus read byte to Alert Response Address)'.format(rpkt.tag))
            return None   # Common occurence; no need to raise exception.
        elif rpkt.got_addr7 == 1:
            dbgprint('Reply to cmd ID 0x{:08x}: ARA reads 0x{:02x} at time '
                     ' 0x{:08x}'.format(rpkt.tag, rpkt.responding_addr7, rpkt.timestamp))
            return rpkt.responding_addr7
        else:
            raise SMBus_Exception('Unexpected got_addr7 value of {} in reply '
                                  'to ARA read command ID 0x{:08x}'.format(rpkt.got_addr7, rpkt.tag))
    def read_smbalert(self):
        """Returns whether the SMBALERT# signal is currently asserted (active low == True).
        Returns None if no response or no meaningful response received over Labcomm."""
        cmdbytes = self.read_smbalert_cmd(tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.read_smbalert_parser,
                             None, self._read_timeouts)
        self._tag_increment()
        if rpkt is None:
            raise receive_timeout, "No timely response packet from demoboard"
        else:
            # Return True if SMBALERT# is active low, False if deasserted (high).
            dbgprint('reply ID 0x{:08x}: SMBALERT.active == {} at time 0x{:08x}'
                     ''.format(rpkt.tag, rpkt.active, rpkt.timestamp))
            return not not rpkt.active  # ... not not coerces integer to boolean
    def _send_byte_nopec(self, addr_7bit, command_code):
        "SMBUS write byte (without PEC)"
        self.check_size(command_code, bits=8)
        self.check_size(addr_7bit, bits=8)
        cmdbytes = self.send_byte_cmd(addr_7bit=addr_7bit, cc=command_code,
                                      tag=self._tag).to_bytes()
        rpkt = self.intf.ask(self.src_id, self.dest_id, cmdbytes, self.send_byte_parser,
                             self._make_send_byte_template(addr_7bit, command_code, self._tag),
                             self._write_timeouts)
        self._tag_increment()  # Increment tag so it's different for the next command.
        if rpkt is None:
            raise timeout, "No timely response packet from demoboard"
        elif rpkt.status == self.status_code.OK:
            return True
        elif rpkt.status == self.status_code.I2C_ERR:
            raise i2c_error, "i2c NACK or error"
        elif rpkt.status == self.status_code.NOT_IMPLEMENTED:
            raise command_not_implemented, ("SMBus firmware module didn't recognize "
                                            "our send_byte command")
    #
    # Templates for matching received packets
    #
    def _make_send_byte_template(self, addr_7bit, command_code, tag):
        return (self.noun.BYTE_V2, self.verb.SEND, addr_7bit, command_code,
                None, None, # wildcards for status and timestamp
                tag)  # Match tag so we know response is for this command.
    def _make_read_byte_v2_template(self, addr_7bit, command_code, tag):
        return (self.noun.BYTE_V2, self.verb.READ, addr_7bit, command_code,
                None, None, None, # wildcards for data8, status, and timestamp
                tag)  # Match tag so we know response is for this command.
    def _read_word_pec_pec_matcher(self, received_pec, response):
        "Check the PEC value of a read_word_pec_response namedtuple"
        buffer = [self._write_addr(response.addr_7bit), response.cc,
                  self._read_addr(response.addr_7bit),
                  self._low_byte(response.data16),
                  self._high_byte(response.data16), received_pec]
        passed = (self._pec(buffer) == 0)
        return passed
    def _make_read_word_pec_v2_template(self, addr_7bit, command_code, tag):
        return (self.noun.WORD_PEC_V2, self.verb.READ, addr_7bit, command_code,
                None, None, None, None, # wildcards for data16, PEC, status, and timestamp
                tag)  # Match tag so we know response is for this command.
                      # Also note in v2 commands, PEC is checked by the firmware side.
    def _make_read_word_pec_v1_template(self, addr_7bit, command_code):
        return (self.noun.WORD_PEC, self.verb.READ, addr_7bit, command_code,
                None,  # ... the data word can be anything
                self._read_word_pec_pec_matcher) # checks the PEC
    def _make_read_word_v2_template(self, addr_7bit, command_code, tag):
        return (self.noun.WORD_V2, self.verb.READ, addr_7bit, command_code,
                None, None, None, # wildcards for data16, status, and timestamp
                tag)  # Match tag so we know response is for this command.
                      # Also note in v2 commands, PEC is checked by the firmware side.
    def _make_read_word_list_pec_v2_template(self, addr_7bit, cc_bitmap, tag):
        return (self.noun.STATELESS_WORD_LIST_PEC_V2, self.verb.READ, addr_7bit, cc_bitmap,
                tag)  # Match tag so we know response is for this command.
                      # Also note in v2 commands, PEC is checked by the firmware side.
    def _read_ara_pec_pec_matcher(self, received_pec, response):
        "Check the PEC value of a read_ara_pec namedtuple"
        buffer = [self._read_addr(self.smbus.alert_response_address_7bit),
                  response.responding_addr7, received_pec]
        passed = (self._pec(buffer) == 0)
        return passed
    def _make_read_ara_pec_template(self, tag):
        return (self.noun.ARA_PEC, self.verb.READ,
                None,  # responding_addr7 can be any value
                lambda active, pkt: active == 0 or active == 1,
                lambda code, pkt: code in (self.status_code.OK, self.status_code.I2C_ERR, self.status_code.PEC_ERR),
                None,  # pass PEC value verbatim; firmware already checked it
                None,  # pass timestamp verbatim
                tag    # Use tag to match response to command.
                )
    def _make_read_ara_template(self, tag):
        return (self.noun.ARA, self.verb.READ,
                None,  # responding_addr7 can be any value
                lambda active, pkt: active == 0 or active == 1,
                None,  # got_addr7 will be 0 if no response or 1 if got a response to reading the ARA
                None,  # pass timestamp verbatim
                tag    # Use tag to match response to command.
                )
    # Properties
    @property
    def _tag(self):
        """Rolling unsigned 32-bit integer used to match responses to _v2 commands."""
        return self._tag_val
    @_tag.setter
    def _tag(self, value):
        self._tag_val = value % 2**32
    def _tag_increment(self):
        self._tag_val += 1

class Labcomm_pyserial_interface(object):
    "Sends and receives LabComm packets using the PySerial API."
    def __init__(self, raw_serial_interface, fifo_size=2**16, junk_bytes_dump=None, debug=False):
        '''Sends and receives LabComm packets using the PySerial API.
        raw_serial_interface should be a PySerial serial.Serial object.
        junk_bytes_dump is an optional argument. It's a function of one argument that
        is passed all bytes discarded by the LabComm parser as non-packet-bytes.
        junk_bytes_dump() is called every time there are bytes to discard. It can be
        used to multiplex non-Labcomm traffic across the pyserial link.
        '''
        super(Labcomm_pyserial_interface, self).__init__()
        assert isinstance(fifo_size, Integral) and fifo_size > 0
        assert hasattr(junk_bytes_dump, "__call__") or junk_bytes_dump is None
        assert isinstance(debug, bool)
        if is_serial_like(raw_serial_interface):
            self.ser = raw_serial_interface
        elif isinstance(raw_serial_interface, basestring):
            self.ser = serial.Serial(port=raw_serial_interface)
        else:
            raise ValueError, ("bad raw_serial_interface value of {}{} passed to "
                               "Labcomm_pyserial_interface.__init__()".format(type(raw_serial_interface),
                                                                              raw_serial_interface))
        self.fifo_size = fifo_size
        self.fifo = StreamWindow(stream=self.ser, buffer_size=fifo_size, debug=debug)
        self.timeout_cached = None  # Don't write to Pyserial.Serial.timeout unless we actually change
                                    # the timeout value to avoid extra control traffic on USB to the SAMD M0+ micro.
        self.write_timeout_cached = None  # Same thing for PySerial's separate write timeout.
        self.debug = debug
        if junk_bytes_dump is None:
            # By default, discard junk bytes.
            def trash(junk_bytes):
                return
            self.dump = trash
        else:
            self.dump = junk_bytes_dump
    def _advance_fifo_to_SOP(self):
        '''Search through the FIFO buffer for the first occurrence of Start of Packet.
        For example, if the first byte is 'L' and the second is 'T', we need to handle
        the following cases of FIFO content:
        
               |<-- FIFO head       ----> FIFO tail
        Case 1: {0 or more non-SOP bytes}LT{0 or more bytes of any kind}
        Case 2: {0 or more non-SOP bytes}L
        Case 3: {0 or more non-SOP bytes}'''
        psbl_SOP_position = self.fifo.find(packet.START_OF_PACKET_BYTEARRAY)
        if psbl_SOP_position > -1:
            read_how_many = psbl_SOP_position   # Case 1
        elif len(self.fifo) > 0 and self.fifo[-1] == packet.START_OF_PACKET_HIGH_BYTE:
            read_how_many = len(self.fifo)-1    # Case 2
        else:
            read_how_many = len(self.fifo)      # Case 3
            self.fifo.peek(read_how_many+1)     #    Try to read new bytes into the FIFO.
        if read_how_many > 0:
            self.dump(self.fifo.read(read_how_many)) # Advance stream position if needed.
        return read_how_many
    def send_packet(self, src_id, dest_id, buffer, timeout=0.25):
        '''Returns within 'timeout' seconds indicating SUCCESS (True) or FAIL (False).
           Returns SUCCESS if buffer successfully sent to the
           underlying interface.
           Otherwise FAIL, meaning the underlying interface
           couldn't accept buffer for some reason.'''
        assert isinstance(timeout, Real) and timeout >= 0
        if timeout != self.write_timeout_cached:
            # Issue USB traffic to change serial timeout only if it is a different value from before.
            # (Reduces USB traffic to aid debugging with a USB protocol analyzer.)
            self.ser.write_timeout = timeout
            self.write_timeout_cached = self.ser.write_timeout
        pktbytes = packet(src_id=src_id, dest_id=dest_id, length=len(buffer), data=buffer, crc=None).to_byte_array()
        result = bool(self.ser.write(pktbytes) == len(pktbytes))
        if self.debug:
            bufstr = " ".join([hex(byte) for byte in bytearray(buffer)])
            print ">>>>> send(buffer = {}) returned {}".format(bufstr, result)
        return result
    def recv_packet(self, dest_id, timeout, src_id=None,
                    receive_tries=8):
        '''Blocks for up to timeout waiting for packet matching dest_id
           and optionally src_id, continuing to receive and dispatch other
           incoming packets.
           Upon success, returns a labcomm_packet object.
           Upon timeout, returns None.'''
        # Sanity check arguments.
        assert isinstance(dest_id, Integral) and dest_id >= 0 and dest_id < 2**16
        assert isinstance(timeout, Real) and timeout >= 0
        assert src_id is None or (src_id >= 0 and src_id < 2**16)
        assert isinstance(receive_tries, Integral)
        # Actual receive logic begins here.
        tquit = time.time() + timeout  # Know when to give up trying to receive packets.
        new_ser_timeout = timeout / receive_tries
        if new_ser_timeout != self.timeout_cached:
            # Issue USB traffic to change serial timeout only if it is a different value from before.
            # (Reduces USB traffic to aid debugging with a USB protocol analyzer.)
            self.ser.timeout = new_ser_timeout  # How regularly to read from underlying stream.
            self.timeout_cached = self.ser.timeout
        result = None  # Default return value if we can't find a packet.
        for trynum in range(receive_tries):
            if time.time() >= tquit:
                # We used up too much time trying to parse a packet at this stream position,
                self.dump(self.fifo.read(1)) # so advance stream by 1 byte
                self._advance_fifo_to_SOP()  # then advance, if needed, to next Start of Packet
                break                        # and return None to the caller.
            # INITIAL READ / SEARCH FOR START OF PACKET.
            possible_hdr_bytes = self.fifo.peek(num=packet.HEADER_SIZE)
            # If Start of Packet bytes aren't at our current stream position,
            # try to seek forward and consume bytes until they are.
            if self._advance_fifo_to_SOP() > 0:
                # No Start of Packet here so we advanced to the next possible one.
                possible_hdr_bytes = self.fifo.peek(num=packet.HEADER_SIZE)
            # IF WE HAVE ENOUGH BYTES FOR A HEADER, PARSE THEM.
            if len(possible_hdr_bytes) < packet.HEADER_SIZE:
                # Wasn't able to read in a full header.
                continue  # Try to read more bytes if we still have time.
            psbl_sop, psbl_src, psbl_dest, psbl_length = struct.unpack(">HHHH", possible_hdr_bytes)
            # VERIFY START OF PACKET MARKER BYTES.
            if psbl_sop != packet.START_OF_PACKET:
                self.dump(self.fifo.read(1)) # so advance stream by 1 byte
                self._advance_fifo_to_SOP()  # then advance, if needed, to next Start of Packet
                continue                     # and retry parsing.
            # TRY TO READ IN THE ENTIRE PACKET, taking no longer than (timeout/receive_tries).
            possible_packet_length = packet.HEADER_SIZE + psbl_length + packet.CRC_SIZE
            possible_packet = self.fifo.peek(possible_packet_length)
            if len(possible_packet) < possible_packet_length:
                # Didn't read enough bytes for the full alleged packet,
                continue  # so try reading in more bytes if there's time left.
            # CHECK THE CRC.
            calcd_crc = packet.crc16(possible_packet[:-packet.CRC_SIZE])
            (rcvd_crc,) = struct.unpack(">H", possible_packet[-packet.CRC_SIZE:])
            if calcd_crc != rcvd_crc:        # BAD CRC,
                self.dump(self.fifo.read(1)) # so advance stream by 1 byte
                self._advance_fifo_to_SOP()  # then advance, if needed, to next Start of Packet
                continue                     # and retry parsing.
            # ALL CHECKS PASS. VALID PACKET.
            result = self.fifo.read(possible_packet_length)  # Consume the packet from the stream.
            if dest_id != psbl_dest or (src_id != None and src_id != psbl_src):
                print "*" * 78
                print "TODO: Implement dispatch table for non-matching packets."
                print "      Want dest_id {:04x}, got {:04x}".format(dest_id, psbl_dest)
                srcstr = "{:04x}".format(src_id) if src_id is not None else "ANY"
                print "      Want src_id {}, got {:04x}".format(srcstr, psbl_src)
                print "*" * 78
            break  # for trynum in range(receive_tries)  # Return packet as result.
        else:  # for trynum in range(receive_tries)
            # Ran out of receive tries and still couldn't fetch a full packet
            # at this stream position. Give up, consume 1 byte, and if necessary,
            # advance the stream to next SOP.
            self.dump(self.fifo.read(1))
            self._advance_fifo_to_SOP()
        # End of receive logic. All returning of results to the caller happens below:
        if result is None:
            return None
        else:
            # result is a string of bytes containing a valid packet,
            # so let's create and return a packet object with the parsed bytes.
            pkt = packet(src_id=psbl_src, dest_id=psbl_dest,
                         length=len(result)-packet.HEADER_SIZE-packet.CRC_SIZE,
                         data=result[packet.HEADER_SIZE:-packet.CRC_SIZE],
                         crc=rcvd_crc)
            return pkt
    def ask(self, src_id, dest_id, send_bytes, receive_bytes_parser=None, match_template=None,
            retry_timeout_sequence=(0.05, 0.1, 0.25), min_receive_timeout=0.005,
            receive_tries_per_send=3):
        """Make a request and receive a response via the Labcomm packet interface.
        
        ask() transmits a Labcomm packet containing send_bytes to dest_id over the
        serial link, then waits for and returns the first received response packet
        whose payload is successfully decoded by a call to
        receive_bytes_parser(rcvd_pkt, match_template).
        
        receive_bytes_parser should be created using

            receive_bytes_parser = <structtuple class>.from_bytes

        where <structuple class> defines the expected format of the response payload.

        If receive_bytes_parser is None, the payload is returned as a plain (unnamed)
        tuple of bytes.
        
        retry_timeout_sequence is a sequence of timeout values
        (positive numbers of seconds to wait) that loosely govern the retry process. ask()
        retries up to as many times as len(retry_timeout_sequence). Each (re-)try consists of
        transmitting send_bytes in a Labcomm packet, then calling recv_packet() with
        the next timeout value in the sequence (minus the time needed to send the request
        packet). Any received packet is
        then passed to receive_bytes_parser() for payload validation,
        and is returned to the caller if validated.
        
        None is returned if retry_timeout_sequence is exhausted without receiving
        a packet with payload satisfying receive_bytes_parser."""
        result = None  # Default return value if we get nothing.
        for timeout in retry_timeout_sequence:
            tquit = time.time() + timeout  # when to give up
            while time.time() < tquit:
                if self.send_packet(src_id=src_id, dest_id=dest_id, buffer=send_bytes):
                    break
                print "ask(): send_packet() failed"
                # else failed to send packet. Retry if time remains.
            else:
                print "ask() failed to send_packet(), giving up"
                break  # for timeout in retry_.... No need to try receiving if we couldn't even send.
            # Always try to receive at least once, for at least min_receive_timeout.
            for receive_try in range(receive_tries_per_send):
                receive_timeout = max(min_receive_timeout, tquit - time.time())
                rpkt = self.recv_packet(dest_id=src_id, timeout=receive_timeout, src_id=dest_id)
                if rpkt is None:
                    if self.debug:
                        print "ask() got nothing from recv_packet(), retrying if possible"
                    # Failed to receive a packet in the given time, so
                    continue  # to the next retry, if any remain.
                # We got a response packet with no errors.
                # Parse the payload and see if it's the one we're expecting.
                if receive_bytes_parser is None:
                    # No parser given. Just return the payload bytes in an unnamed tuple.
                    return tuple(rpkt.data) # RETURN
                try:
                    result = receive_bytes_parser(rpkt.data, match_template)
                except structtuple.NoMatch as e:
                    print "ask() got a valid Labcomm packet but not the expected one"
                    print "  {}".format(e)
                    print "  Dropping packet{}".format("." if receive_try == receive_tries_per_send-1
                                                       else " and retrying recv_packet()")
                    # print "      {}".format(" ".join((hex(x) for x in rpkt.data)))
                    # Not the response packet we were looking for, so drop it and
                    continue    # continue retrying if any retries remain.
                else:
                    break # if we get here, parsing succeeded, so exit the receive_try for-loop.
            if result is not None:
                break # parsing succeeded, exit the retry for-loop.
        return result
        

def is_serial_like(obj):
    def has_attribute(obj, attr_name):
        '''Improves on the built-in hasattr() function by also detecting properties whose getters
        can raise exceptions.'''
        try:
            getattr(obj, attr_name)
        except AttributeError as e:
            return False
        except Exception as e:
            dbgprint("has_attribute({}, '{}') raised {}".format(repr(obj), attr_name, repr(e)))
            return True
        else:
            return True
    return all(has_attribute(obj, attr_name) for attr_name in ["open", "read", "write", "in_waiting",
                                                               "timeout", "write_timeout"])

class robust_serial(object):
    """Wraps a PySerial serial.Serial object and attempts to reconnect automatically upon connection failures. To
    use, simply do the usual read() and write() calls as with a real serial port, and:

    1. be prepared to catch any SerialException raised by the underlying serial.Serial object as well as the
    no_serial_object exception we raise whenever we're not connected;

    2. try another read() or write() if you catch an exception. Every time you call read() or write() and the
    underlying serial_object raises an exception, the robust_serial object calls connect_function once to rescan
    available serial ports and attempt to re-open a connection.

    read(), write(), etc. requests will be passed through to serial_object. If serial_object raises an exception,
    its close() method is called, then connect_function(serial_object or None) is called. This call must return
    either an open serial.Serial object or None if unable to find a connection."""
    def __init__(self, connect_function, serial_object=None):
        assert hasattr(connect_function, "__call__"), "connect_function must be a function or method"
        assert isinstance(serial_object, serial.Serial) or is_serial_like(serial_object) or serial_object is None, \
            "bad serial_object argument to robust_serial.__init__()"
        self._port_name = ""  # Populate with something like "/dev/ttyS5" or "COM123" or the like when connected.
        try:
            self.serial_object = serial_object or connect_function(serial_object)
        except SerialException as e:
            dbgprint("Caught exception while trying to create initial serial_object\n  {}".format(repr(e)))
            self.serial_object = None
        self.connect_function = connect_function
        self._timeout = False  # False is a sentinel value meaning no timeout has been set yet.
        self._write_timeout = False  # timeouts can be None or any non-negative real number.
    #
    # open_check decorator:
    #
    def open_check(func):
        "Executes the decorated method if self.serial_object is an open serial.Serial"
        def function_wrapper(*args, **kwargs):
            dbgprint("open_check")
            self = args[0]
            if self.serial_object is None or not self.serial_object.is_open:
                # Try reconnecting once.
                self.serial_object = self.connect_function(self.serial_object)
                if self.serial_object is None:
                    raise no_serial_object("No serial connection")
            # We get here if self.serial_object is an open serial.Serial object.
            self._port_name = getattr(self.serial_object, "port", "")  # Try to get the port name.
            return func(*args, **kwargs)
        return function_wrapper
    #
    # error_check decorator:
    #
    def error_check(func):
        def function_wrapper(*args, **kwargs):
            dbgprint("error_check")
            self = args[0]
            try:
                return func(*args, **kwargs)
            except Exception as e:
                if isinstance(e, SerialTimeoutException):
                    dbgprint("SerialTimeoutException: {}".format(repr(e)))
                    if self.reconnect():
                        try:
                            return func(*args, **kwargs)
                        except Exception as e2:
                            raise e2
                elif isinstance(e, SerialException):
                    dbgprint("SerialException: {}".format(repr(e)))
                    if self.reconnect():
                        try:
                            return func(*args, **kwargs)
                        except Exception as e2:
                            raise e2
                else:
                    dbgprint("*** Caught unexpected exception {}".format(type(e)))
                    dbgprint("*** {}".format(e))
                    pass
                raise e
        return function_wrapper
    
    # attempt to reconnect to the serial_object. Returns success.
    def reconnect(self):
        if self.serial_object is not None and self.serial_object.is_open:
            self.serial_object.close()
        possible_connection = self.connect_function(self.serial_object)
        if possible_connection is not None:
            # We get here if possible_connection is an open serial.Serial object
            self.serial_object = possible_connection
            self._port_name = getattr(self.serial_object, "port", "")  # Try to get the port name.
            # Be sure serial_object's timeouts are set to what our caller wants.
            # Caller may have set these values when we didn't have an open serial.Serial object.
            # False is a sentinel value meaning no timeout has been set yet; couldn't use None
            # because None is a valid timeout setting.
            if self._write_timeout is not False and self._write_timeout != self.serial_object.write_timeout:
                self.serial_object.write_timeout = self._write_timeout
            if self._timeout is not False and self._timeout != self.serial_object.timeout:
                self.serial_object.timeout = self._timeout
            return self.serial_object.is_open
        return False
    #
    # port property
    #
    def port_setter(self, value):
        raise AttributeError("robust_serial.port is a read-only property")
    def port_getter(self):
        '''The name of the currently connected serial port, or "" if disconnected.'''
        return self._port_name
    port = property(fget=port_getter, fset=port_setter)
    #
    # timeout property passthru:
    #
    @error_check
    def timeout_setter(self, value):
        dbgprint(":::::: timeout_setter")
        assert isinstance(value, Real) and value >= 0
        if self.serial_object is not None:
            self.serial_object.timeout = value
        self._timeout = value  # In any case, save the value to (re-)apply to self.serial_object later as needed.
    @error_check
    def timeout_getter(self):
        '''The timeout value of the underlying serial object.'''
        dbgprint(":::::: timeout_getter")
        if self.serial_object is not None:
            return self.serial_object.timeout
        else:
            # Return the saved value when self.serial_object isn't yet available.
            return self._timeout if self._timeout is not False else None
    timeout = property(fget=timeout_getter, fset=timeout_setter)
    #
    # write_timeout property passthru:
    #
    @error_check
    def write_timeout_setter(self, value):
        dbgprint(":::::: write_timeout_setter")
        assert isinstance(value, Real) and value >= 0
        if self.serial_object is not None:
            self.serial_object.write_timeout = value
        self._write_timeout = value  # In any case, save the value to (re-)apply to self.serial_object later as needed.
    @error_check
    def write_timeout_getter(self):
        '''The write_timeout value of the underlying serial object.'''
        dbgprint(":::::: write_timeout_getter")
        if self.serial_object is not None:
            return self.serial_object.write_timeout
        else:
            # Return the saved value when self.serial_object isn't yet available.
            return self._write_timeout if self._write_timeout is not False else None
    write_timeout = property(fget=write_timeout_getter, fset=write_timeout_setter)
    #
    # in_waiting property passthru:
    #
    @open_check
    @error_check
    def in_waiting_setter(self, value):
        raise AttributeError("in_waiting is a read-only property")
    @open_check
    @error_check
    def in_waiting_getter(self):
        '''Passes through how many bytes are available to read
        from the underlying serial object.'''
        dbgprint(":::::: in_waiting_getter")
        return self.serial_object.in_waiting
    in_waiting = property(fget=in_waiting_getter, fset=write_timeout_setter)
    #
    # LEGACY inWaiting function passthru:
    #
    @open_check
    @error_check
    def inWaiting(self):
        dbgprint(":::::: inWaiting")
        return self.serial_object.inWaiting()
    #
    # read(), write(), open(), close() methods passthru:
    #
    @open_check
    @error_check
    def read(self, size):
        dbgprint(":::::: read")
        assert isinstance(size, Integral) and size >= 0
        return self.serial_object.read(size)
    @open_check
    @error_check
    def write(self, data):
        dbgprint(":::::: write")
        return self.serial_object.write(data)
    @error_check
    def open(*args, **kwargs):
        dbgprint(":::::: open")
        self = args[0]
        # Capture any attempts to set properties we're interested in during the open() call.
        for kword in ("timeout", "write_timeout"):
            if kword in kwargs:
                setattr(self, "_{}".format(kword), kwargs[kword]) # writes to self._timeout, self._write_timeout
        self.serial_object.open(*args[1:], **kwargs)
    @error_check
    def close(self):
        dbgprint(":::::: close")
        return self.serial_object.close()
    
#
# Labcomm packet structure definition
#
from collections import namedtuple

_labcomm_packet_field_names = ('src_id', 'dest_id', 'length', 'data', 'crc')
_packet_tuple = namedtuple('_packet_tuple', _labcomm_packet_field_names)

class packet(_packet_tuple):
    """A LabComm packet object has the following fields, in order:
    start_of_packet, src_id, dest_id, length, data, crc. It is intended to be
    used on byte-oriented communications channels such as RS232 and USB,
    so all LabComm packets can be represented as an ordered sequence of bytes.

    The sequence (start_of_packet, src_id, dest_id, length) comprises the "header".

    The start_of_packet is always 0x4C54, or ASCII "LT".

    The data (payload) field is a sequence of bytes.
    The length field is the length of the data field.

    Except for the data field, all fields are 16 bits long and in network byte order,
    meaning the most significant byte of each word is sent first.

    The crc field should be calculated over the header and data fields using the
    CRC-16 polynomial x^16 + x^15 + x^2 + 1 (0xa001) with initial value 0xffff.
    See http://users.ece.cmu.edu/~koopman/crc/crc16.html for details on this CRC
    and see the static method crc16() below for implementation. 0xa001 isn't the optimal
    CRC-16 that Koopman found for error detection capability -- 0xd175 has a slight
    edge for the range of packet sizes we expect with this protocol, but we use it
    because an assembly language implementation came with
    the Arduino Uno (ATmega328P AVR) core back when we were developing on that platform,
    and we kept using the same CRC for compatibility when we migrated
    the code to the Arduino Zero (Atmel SAMD21G ARM Cortex M0+) core.
    """
    __slots__=()
    START_OF_PACKET_HIGH_BYTE = ord('L')
    START_OF_PACKET_LOW_BYTE = ord('T')
    START_OF_PACKET = (START_OF_PACKET_HIGH_BYTE << 8) + START_OF_PACKET_LOW_BYTE
    START_OF_PACKET_BYTEARRAY = bytearray([START_OF_PACKET_HIGH_BYTE, START_OF_PACKET_LOW_BYTE])
    # All sizes in bytes:
    START_OF_PACKET_SIZE = 2
    SRC_ID_SIZE = 2
    DEST_ID_SIZE = 2
    LENGTH_SIZE = 2
    HEADER_SIZE = START_OF_PACKET_SIZE + SRC_ID_SIZE + DEST_ID_SIZE + LENGTH_SIZE
    CRC_SIZE = 2
    def __new__(cls, *args, **kwargs):
        """To create a new packet object with this class, call the constructor with five
        positional arguments:
        
            new_packet = packet(src_id, dest_id, length, data, crc)
        
        or with five keyword arguments:
        
            new_packet = packet(src_id=0x1234, dest_id=0x5678, length=None,
                                data="hello world", crc=0x0bad)
        
        If None is given as crc or length arguments to the constructor, a correct CRC-16 src_id
        and/or length will be calculated and returned when the to_byte_array() method is called.
        
        It is OK to give wrong values for the crc and length fields, as long as they
        are 16-bit integers. This can be useful in testing."""
        if len(args) == 5 and len(kwargs) == 0:
            # We're called with positional arguments only.
            (src_id, dest_id, length, data, crc) = args
        elif len(args) == 0 and len(kwargs) == 5:
            # We're called with keyword arguments only.
            (src_id, dest_id, length, data, crc) = (kwargs[field] for field in _labcomm_packet_field_names)
        else:
            raise SyntaxError, "packet constructor must be called with either 5 positional " \
                "arguments or 5 keyword arguments."
        assert isinstance(src_id, Integral) and src_id >= 0 and src_id < 2**16, "src_id must be a 16-bit integer."
        assert isinstance(dest_id, Integral) and dest_id >= 0 and dest_id < 2**16, "dest_id must be a 16-bit integer."
        assert (length is None) or isinstance(length, Integral) and length >= 0 and length < 2**16, \
            "length must be a 16-bit integer or None."
        assert (crc is None) or isinstance(crc, Integral) and crc >= 0 and crc < 2**16, \
            "crc must be a 16-bit integer or None."
        # Pass the validated arguments to the namedtuple constructor (our superclass).
        return _packet_tuple.__new__(cls, src_id, dest_id, length, data, crc)
    # @classmethod
    # def from_stream(cls, stream, consume_bytes_from_stream=True):
        # """Given a stream of bytes that can be accessed via the read() and peek() methods described
        # below, return any valid Labcomm packet found at the head of the stream as a packet object.
        
        # Returns False if we're certain there is NOT a valid packet at the head of the stream.
        # Returns None if it is possible that there's a valid packet at the head of the stream but
        # not all the bytes from the stream yet available from the stream.
        
        # stream is intended to be a stream of bytes. stream must support two methods:
        
            # stream.read(N) where N >= 0 consumes and returns N bytes from stream, and
        
            # stream.peek(N) works the same as read() but does NOT consume bytes from stream.
        
        # TODO: NOT IMPLEMENTED YET.
        # """
        # pass
    @staticmethod
    def crc16(byteString):
        # python version of this crc16 -> Polynomial: x^16 + x^15 + x^2 + 1 (0xa001) Initial value: 0xffff
        # This C code from Atmel libc was translated to python.
        # uint16_t
        # crc16_update(uint16_t crc, uint8_t a)
        # {
        #     int i;
        #
        #     crc ^= a;
        #     for (i = 0; i < 8; ++i)
        #     {
        #         if (crc & 1)
        #             crc = (crc >> 1) ^ 0xA001;
        #         else
        #             crc = (crc >> 1);
        #     }
        #
        #     return crc;
        # }
        crc = 0xFFFF # Initial value: 0xffff
        poly = 0xA001 # x^16 + x^15 + x^2 + 1 (0xa001), discard x^16 term
        for byte in byteString:
            crc = crc ^ byte
            # crc = crc ^ ord(byte) if isinstance(byte, str) else crc ^ (byte & 0xff)
            for cycle in range(8):
                if (crc & 1):
                    crc = (crc >> 1) ^ poly
                else:
                    crc = (crc >> 1)
        return int(crc & 0xFFFF)
    def to_byte_array(self):
        '''Returns the array of bytes representing this Labcomm packet.'''
        length = self.length if self.length is not None else len(self.data)
        header = array("B", struct.pack(">HHHH", self.START_OF_PACKET,
                                        self.src_id, self.dest_id, length))
        databytes = array("B", self.data)
        if self.crc is not None:
            crcbytes = array("B", struct.pack(">H", self.crc))
        else:
            crcbytes = array("B", struct.pack(">H", self.crc16(header+databytes)))
        pkt_byte_array = header + databytes + crcbytes
        return pkt_byte_array
    def __repr__(self):
        if self.crc is None:
            (crc,) = struct.unpack(">H", self.to_byte_array()[-2:])
        else:
            crc = self.crc
        return ("packet(src_id=0x{src_id:04x}, dest_id=0x{dest_id:04x}, "
                "length=0x{length:04x}, data={data}, crc=0x{crc:04x})"
                ).format(src_id=self.src_id, dest_id=self.dest_id,
                         length=len(self.data), data=repr(self.data), crc=crc)
#
# Utility functions
#
class StreamWindow(object):
    '''Wraps any non-seekable stream that has a read(number_of_bytes) method
    and provides a specifiable amount of rewindability via FIFO buffering.
    StreamWindow-wrapped streams offer a peek() method which effectively provides
    a "sliding window" over the head of the stream.
    
    stream can be any stream that follows the io.RawIOBase protocol,
    e.g., PySerial's serial.Serial objects.
    In particular, stream must support the read() method.
    
    It's really too bad that io.BufferedReader(RawIOBase, buffer_size) in the Python 2.7.13
    standard library has a broken peek() method! In testing, I found that
    io.BufferedReader refuses to read any bytes from stream into its FIFO
    as long as there is at least one valid byte in the FIFO.
    This makes it impossible to just keep calling peek(n) with larger
    and larger values of n until one peeks at a complete data packet, for the
    example use case of segmenting/parsing packets from a stream of bytes.
    
    StreamWindow was developed to fill this gap.'''
    def __init__(self, stream, buffer_size=2**16, debug=False):
        assert hasattr(stream, "read"), ("stream argument provided to StreamWindow "
                                         "constructor must have a read() method.")
        assert isinstance(buffer_size, Integral) and buffer_size >= 1
        assert isinstance(debug, bool)
        self.stream = stream
        self.buf = bytearray(buffer_size * chr(0))
        self.buffer_size = buffer_size
        self.content_size = 0
        self.debug = debug
    def _shift_buffer(self, num_bytes):
        '''Delete num_bytes of data from the front of buf, overwriting
        it with valid data slid over from the end of buf. This makes
        room at the end of buf for new data from stream.'''
        self.buf[:self.buffer_size-num_bytes] = self.buf[num_bytes:]
    def _read_buffer(self, num_bytes):
        "Consumes bytes from the FIFO buffer."
        assert num_bytes <= self.content_size
        result = bytearray(self.buf[:num_bytes]) # Save result bytes into new bytearray.
        self._shift_buffer(num_bytes)
        self.content_size -= num_bytes
        return result
    def __len__(self):
        '''Just return the number of valid bytes in the FIFO, as it is already
        known that streams have indefinite length.'''
        return self.content_size
    def __getitem__(self, k):
        '''Support x[i] indexing or x[i:j] slice peeking into the FIFO.
        0 indexes the head byte in the FIFO, -1 indexes the tail byte.'''
        if isinstance(k, Integral):
            if (k > 0 and k >= self.content_size) or (k < 0 and -k > self.content_size):
                raise IndexError
            k = k if k >= 0 else self.content_size + k
        elif isinstance(k, slice):
            # Need to adjust the slice argument based on content_size.
            start, stop, step = k.indices(self.content_size)
            k = slice(start, stop, step)
        return self.buf[k]
    def find(self, sub):
        '''Return the lowest index in FIFO buffer where subsection sub is found.
        Returns -1 if not found.'''
        return self.buf.find(sub, 0, self.content_size)
    def read(self, num=1):
        '''Try to read and consume num bytes from the FIFO-buffered stream.
        Returns at most num bytes as a string.'''
        assert num > 0
        if self.debug:
            print "read({}) called with {:d} bytes in FIFO".format(num, self.content_size),
            if self.content_size:
                print_hex_bytes(the_bytes=self[:], prefix=': ', number_of_bytes_per_line=20,
                                suffix="..." if self.content_size > 20 else "",
                                number_of_bytes_to_print=min(20, self.content_size))
            else:
                print
        # First try to fill the request from the buffer.
        if self.content_size > 0:
            # Buffer not empty, so grab as many bytes as we need
            # from it, but only grab valid content.
            num_bytes_from_buffer = min(num, self.content_size)
            num_bytes_from_stream = num - num_bytes_from_buffer
            result = self._read_buffer(num_bytes_from_buffer)
        else:
            num_bytes_from_stream = num
            result = ''
        # Do we need any additional bytes from the stream?
        if num_bytes_from_stream > 0:
            # Yes:
            new_bytes = self.stream.read(num_bytes_from_stream)
            result += new_bytes
            if self.debug:
                print ("  read({}) read {} new bytes from stream. "
                       ).format(num, len(result))
        # Postcondition: result is a string of valid bytes from the buffer
        #     plus new bytes read from stream, and len(result) <= num.
        # Postcondition: result matches the regexp b*s* , where
        #     b matches any buffer byte and s matches any stream byte.
        return result
    def peek(self, num=1):
        '''Returns a copy of at most num bytes from stream but also saves them in a FIFO
        buffer to allow future peek()s and read()s to see them. If FIFO is full,
        peek() returns only what is in the FIFO and won't read from stream until
        space is made.
        Use read() to make some space in the FIFO to continue retrieving bytes from stream.'''
        assert num > 0
        if num > self.buffer_size:
            num = self.buffer_size
        if self.debug:
            print ("peek({}) called with FIFO containing {:d} bytes"
                   ).format(num, self.content_size),
            if self.content_size:
                print_hex_bytes(the_bytes=self[:], prefix=': ', number_of_bytes_per_line=20,
                                suffix="..." if self.content_size > 20 else "",
                                number_of_bytes_to_print=min(20, self.content_size))
            else:
                sys.stdout.write("")  # Suppress leading whitespace in the print below.
                print "."
        # Precondition: 0 < num <= buffer_size
        # First try to fill the request from the buffer,
        # adding fresh bytes from stream as needed.
        num_bytes_from_buffer = min(num, self.content_size)
        num_bytes_from_stream = num - num_bytes_from_buffer
        if num_bytes_from_stream > 0:
            # Try to read fresh stream bytes into the buffer
            # to satisfy the request. Read at least as many bytes as
            # the stream reports are immediately available, but stay
            # within free buf space.
            if hasattr(self.stream, "in_waiting"):
                available = self.stream.in_waiting  # PySerial >=3.0
            elif hasattr(self.stream, "inWaiting"):
                available = self.stream.inWaiting() # PySerial <3.0
            else:
                available = 0  # Support streams without in(_w|W)aiting.
            how_many = max(available, num_bytes_from_stream)
            how_many = min(how_many, self.buffer_size-self.content_size)
            new_bytes = self.stream.read(how_many)
            self.buf[self.content_size:self.content_size+len(new_bytes)] = new_bytes
            self.content_size += len(new_bytes)  # Updated count of valid bytes in buffer.
            if self.debug:
                print ("  peek({}) read {} new bytes from stream. "
                       "FIFO now has {:d} bytes").format(num, len(new_bytes), self.content_size),
                if self.content_size:
                    print_hex_bytes(the_bytes=self[:], prefix=': ', number_of_bytes_per_line=20,
                                    suffix="..." if self.content_size > 20 else "",
                                    number_of_bytes_to_print=min(20, self.content_size))
                else:
                    sys.stdout.write("")  # Suppress leading whitespace in the print below.
                    print "."
        # The buffer now contains the bytes we'll return. Return a copy of these bytes.
        num_bytes_to_return = min(num, self.content_size)
        result = bytearray(self.buf[:num_bytes_to_return])
        return result
    def close(self):
        "Closes the underlying stream."
        return self.stream.close()

def print_hex_bytes(the_bytes, number_of_bytes_per_line=16,
                    number_of_bytes_to_print=None, prefix='',
                    suffix='', show_offsets=False, write=None):
    '''Given a list of bytes (or other iterable of bytes),
    print them like this:
    
    0a 30 01 00 f0 ff 00 00 0a 30 01 00 f0 ff 00 00
    00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f
    . . .
    
    Defaults to printing all the bytes given,
    in lines of 16 bytes each, using the built-in
    print statement. But this is all configurable.
    In particular, the write argument should be any function
    that accepts a string to be output, printed,
    or recorded in some way, such as the
    print_to_file_and_screen() method in this library.
    If number_of_bytes_per_line is None, then all bytes will
    be printed on one line AND the caller is responsible for
    ensuring that the_bytes is a finite number of bytes.'''
    # Validate arguments.
    import collections
    assert isinstance(the_bytes, collections.Iterable)
    for v in (number_of_bytes_per_line, number_of_bytes_to_print):
        assert v is None or (isinstance(v, Integral) and v >= 0)
    if write is None:
        # By default, print to the screen.
        write = print_to_screen
    else:
        # Check that user-provided write() arg is actually callable.
        assert hasattr(write, "__call__"), "write() must be callable"
    bytestream = the_bytes.__iter__()
    bytes_printed = 0
    bytes_exhausted = False
    while (not bytes_exhausted and
            (bytes_printed < number_of_bytes_to_print
            or number_of_bytes_to_print is None)):
        bytelist = []  # List of bytes to print for this line.
        if number_of_bytes_per_line is None:
            # Print all the bytes on one line.
            bytelist = tuple(b for b in the_bytes)
            bytes_exhausted = True
        else:
            for i in xrange(number_of_bytes_per_line):
                try:
                    bytelist.append(bytestream.next())
                except StopIteration:
                    bytes_exhausted = True
                    break  # for i in xrange...
        line = " ".join("{:02x}".format(b) for b in bytelist)
        if len(bytelist):
            if show_offsets:
                line = "{:>06x}: ".format(bytes_printed) + line
            write(prefix + line + suffix)
        bytes_printed += len(bytelist)

def print_to_screen(*args, **kwargs):
    """Like Python 2's built-in print statement, but is a function instead of a statement
    and so can be passed as an argument in a function call.
    Pass keyword argument 'linefeed=False' to suppress the default trailing linefeed."""
    sys.stdout.write("")  # Needed to suppress possibility of print statement's default leading whitespace.
    if args:
        for arg in args:
            print arg,    # sys.stdout.write("") above avoids the possible leading whitespace of this print.
    if "linefeed" not in kwargs or ("linefeed" in kwargs and kwargs["linefeed"] is True):
        print
    return len(args)
#
#
if __name__=='__main__':
    from serial.tools.list_ports import comports
    from serial.serialutil import SerialException, SerialTimeoutException
    while True:
        comport_list = [port for port in comports() if (port.vid and port.pid)]
        if not len(comport_list):
            print "No serial ports found. I can't see your demoboard."
            print "Try unplugging and replugging its USB connection."
            print
            print "*** For greatest reliability, connect the demoboard directly to a USB port on this computer"
            print "      without going through any hubs."
            print
            raw_input("\nPress ENTER to exit.")
            raise SystemExit
        print "I found the following serial ports on this machine:"
        for port in comports():
            if not (port.vid or port.pid):
                continue  # not a USB serial port
            print " {:>12s} : vid:pid=0x{:04x}:0x{:04x}".format(port.device, int(port.vid), int(port.pid))
        serial_port = raw_input("Which serial port should I use to talk to the demoboard (e.g. {})? ".format(port[0]))
        try:
            demoboard = SMBus_Labcomm_interface(serial_port, debug=False)
            break  # Succeeded in opening serial port
        except SerialException as e:
            print "I couldn't open port '{}'.".format(serial_port)
            print "Caught exception: {}".format(e)
            print
    #
    # Example: Reading and writing arbitrary SMBus command codes.
    #
    def test_loop_reading_and_writing_registers(addr_7bit=0x68):
        register_list = [ 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24 ]
        from collections import OrderedDict
        saved_values = OrderedDict()
        loops = 2
        delay = 1.5
        for i in range(loops):
            for cc in register_list:
                try:
                    saved_values[cc] = demoboard.read_word(addr_7bit=addr_7bit, command_code=cc)
                except SMBus_Exception as e:
                    print ("Caught exception '{}' trying to read command code "
                           "0x{:02x} from address7 0x{:02x}").format(e, cc, addr_7bit)
                    raise e
                else:
                    valstr = "0x{:04x}".format(saved_values[cc]) if saved_values[cc] is not None else "None"
                    print "Read cc 0x{:02x} == {}".format(cc, valstr)
            for cc in register_list:
                val = random.randint(0, 65535)
                reply_val = demoboard.write_word(addr_7bit, cc, val)
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print ("Writing 0x{:04x} to cc 0x{:02x} returns {}").format(val, cc, valstr)
            for cc in register_list:
                reply_val = demoboard.read_word(addr_7bit, cc)
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print "Read cc 0x{:02x} == {}".format(cc, valstr)
            for cc in saved_values:
                reply_val = demoboard.write_word(addr_7bit, cc, saved_values[cc])
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print "Restoring 0x{:04x} to cc 0x{:02x} returns {}".format(saved_values[cc], cc, valstr)
            for cc in register_list:
                reply_val = demoboard.read_word(addr_7bit, cc)
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print "Read cc 0x{:02x} == {}".format(cc, valstr)
            if i == loops - 1:
                break
            else:
                print
                print "Waiting {} seconds before repeating...".format(delay)
                time.sleep(delay)
    def test_list_reading_and_writing_registers(addr_7bit=0x68):
        register_list = [ 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24 ]
        from collections import OrderedDict
        saved_values = OrderedDict()
        loops = 2
        delay = 1.5
        for i in range(loops):
            print "=" * 78
            print "Using list-read:"
            new_cc_data = demoboard.read_word_list(addr_7bit=addr_7bit, command_code_list=register_list)
            saved_values.update(new_cc_data)
            for cc in new_cc_data:
                if isinstance(new_cc_data[cc], Integral):
                    valstr = "0x{:04x}".format(new_cc_data[cc])
                else:
                    valstr = str(new_cc_data[cc])
                print "Read cc 0x{:02x} == {}".format(cc, valstr)
            for cc in register_list:
                val = random.randint(0, 65535)
                reply_val = demoboard.write_word(addr_7bit, cc, val)
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print ("Writing 0x{:04x} to cc 0x{:02x} returns {}").format(val, cc, valstr)
            print "=" * 78
            print "Reading individually:"
            for cc in register_list:
                reply_val = demoboard.read_word(addr_7bit, cc)
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print "Read cc 0x{:02x} == {}".format(cc, valstr)
            for cc in saved_values:
                reply_val = demoboard.write_word(addr_7bit, cc, saved_values[cc])
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print "Restoring 0x{:04x} to cc 0x{:02x} returns {}".format(saved_values[cc], cc, valstr)
            for cc in register_list:
                reply_val = demoboard.read_word(addr_7bit, cc)
                valstr = "0x{:04x}".format(reply_val) if reply_val is not None else "None"
                print "Read cc 0x{:02x} == {}".format(cc, valstr)
            if i == loops - 1:
                break
            else:
                print
                print "Waiting {} seconds before repeating...".format(delay)
                time.sleep(delay)
    #
    # Actually run the example defined above
    #
    test_loop_reading_and_writing_registers()
    test_list_reading_and_writing_registers()

