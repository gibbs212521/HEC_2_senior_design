#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
# from scipy.interpolate import UnivariateSpline  # Remove this module's dependency on scipy
from interpolator import interpolator
import collections, numbers

# Copyright 2019 by Analog Devices, Inc.
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
#$Revision$
#$Date$
#Generated on 2019-03-06

class LTC4162(collections.Mapping):
    '''API for the LTC4162 Advanced Synchronous Switching Battery Charger and PowerPath Manager.

    Each bit field is read and written as an attribute of the class instance.
    Bit fields are changed in place with a read-modify-write algorithm to avoid clearing adjacent data in shared registers.
    When multiple bit fields are stored within a single command code, an additional attribute of the class instance exists to allow reads and writes to the full register.
    Presets (enumerations) and formats (transformation functions between integers and real-word units) are applied in both directions for interactive use, but can be disabled.'''
    def __init__(self, read_function, write_function=None, verbose=False, read_list_function=None):
        '''The user must supply appropriate functions to read from and write to the I²C/SMBus hardware.
        read_function should take arguments (addr_7bit, command_code) and return contents of LTC4162 register at command_code.
        write_function should take arguments (addr_7bit, command_code, data) and write data to LTC4162 register at command_code.
        Set verbose argument to True to enable printing of intermediate results of masking, shifting and data transformation operations.
        Upon error reading or writing to the LTC4162, read_function, write_function, and/or read_list_function should return an exception or other non-numeric Python object, which will be passed back to any code calling us.
        Optional: If the I²C/SMBus hardware/firmware supports reading multiple command codes at once,
        the user may supply a read_list_function that takes arguments (addr_7bit, command_code_list)
        where command_code_list is a list, tuple, or set of command codes. This can increase read frequency.
        '''
        object.__setattr__(self, 'verbose', verbose)
        object.__setattr__(self, 'read_function', read_function)
        object.__setattr__(self, 'write_function', write_function)
        object.__setattr__(self, 'read_list_function', read_list_function)
        object.__setattr__(self, 'addr_7bit', 0x68)
        object.__setattr__(self, 'word_size', 16)
        self._update_xml_formatters()
    def get_name(self):
        '''Returns the part number for the chip for which this API is designed, one that's specific
        to the particular option or variant of the chip being targeted.'''
        return 'LTC4162-LADM'
    def get_status(self):
        '''Returns dictionary containing current value of all readable registers.'''
        ret_dict = {}
        for k in self.keys():
            try:
                ret_dict[k] = self[k]
            except LTC4162_APIException:
                #bit field not readable
                pass 
        return ret_dict
    def print_status(self):
        '''Prints current value of all readable registers.'''
        status_dict = self.get_status()
        max_key = max([len(k) for k in status_dict.keys()])
        for k,v in sorted(status_dict.items(), key=lambda (k,v): k):
            print("{}	{}".format(k,v).expandtabs(max_key+4).replace(" ","."))
    def set_device_address(self, addr_7bit):
        '''Change I²C/SMBus device address of the LTC4162.
        addr_7bit is the right-justified 7-bit address with the R/W̅ bit omitted.'''
        assert isinstance(addr_7bit, int)
        assert addr_7bit < 0x80
        self.addr_7bit = addr_7bit
    def get_active_format(self, bf_name):
        '''Returns string name of format currently active for field bf_name.'''
        return self._register_map[bf_name]['active_format']
    def set_active_format(self, bf_name, format_name, force=False):
        '''Changes currently active format for field bf_name to format_name.
        If format_name is not in list of allowed_formats, set force argument to True to disable check.
        '''
        if format_name is None or format_name.lower() == 'none':
            self._register_map[bf_name]['active_format'] = 'None'
        elif format_name in self._register_map[bf_name]['allowed_formats'] or force:
            self._register_map[bf_name]['active_format'] = format_name
        else:
            self._error('Format {} not allowed for field {}'.format(format_name,bf_name))
    def enable_read_presets(self,bf_name,enabled=True):
        '''Enable presets (enumerations) for a single bit field bf_name.'''
        self._register_map[bf_name]['read_presets_enabled'] = enabled
    def disable_read_presets(self,bf_name,enabled=False):
        '''Disable presets (enumerations) for a single bit field bf_name.'''
        self.enable_read_presets(bf_name,enabled)
    def disable_binary_read_presets(self):
        '''Disable presets (enumerations) for all single-bit bit fields.'''
        for bf_name in self._register_map.keys():
            if len(self._register_map[bf_name]['size']) == 1:
                self.disable_read_presets(bf_name)
    def get_formats(self, bf_name):
        '''Returns tuple of formats defined for bit field bf_name.'''
        return tuple(self._register_map[bf_name]['allowed_formats'])
    def get_units(self, bf_name):
        '''Returns a Unicode string containing the measurement units (e.g. Volts, Ohms, Amps, deg. C)
        currently in effect for bit field bf_name.'''
        bf_format = self._register_map[bf_name]['active_format']
        if bf_format == 'None':
            return ''
        else:
            return self._xml_formats[bf_format]['transformed_units']
    def get_units_for_format(self, format_name):
        '''Returns a Unicode string depicting the measurement unit (e.g. Volts, Ohms, Amps, deg. C)
        corresponding to the named format.'''
        return self._xml_formats[format_name]['transformed_units']
    def create_format(self, format_name, format_function, unformat_function, signed=False, description=None, units=''):
        '''Create a new format definition or modify an existing definition.

        format_function should take a single argument of integer raw data from the register and return a version of the data scaled to appropriate units.
        unformat_function should take a single argument of data in real units and return an integer version of the data scaled to the register LSB weight.
        If the data is signed in two's-complement format, set signed=True.
        After creating format, use set_active_format method to make the new format active.
        '''
        self._formatters[format_name] = {'format': format_function, 'unformat': unformat_function,
                                          'description': description, 'signed': signed, 'units': units}
    def set_constant(self, constant, value):
        '''Sets the constants found in the datasheet used by the formatters to convert from real world values to digital value and back.'''
        self._constants[constant] = value
        self._update_xml_formatters()
    def get_constant(self,constant):
        '''Gets the constants found in the datasheet used by the formatters to convert from real world values to digital value and back.'''
        return self._constants[constant]
    def list_constants(self):
        '''Returns a dictionary of constants found in the datasheet used by the formatters to convert from real world values to digital value and back.'''
        return self._constants
    def disable_presets_and_formats(self):
        '''Remove all presets and formats.

        Read and write data will be passed through unmodified, except for masking and shifting.
        The dictionary of presets and formats is shared between all instances of the class and any other instances will reflect this change.
        This is permanent for the duration of the Python session.'''
        for register in self._register_map.values():
            register['presets'] = []
            register['active_format'] = 'None'
    def _error(self, message):
        '''Raises exceptions if bad data is passed to API.
        Bus Read and Write errors must be raised by the user-supplied functions.'''
        raise LTC4162_APIException(message)
    def __str__(self):
        return 'LTC4162 API instance at address 0x68'
    def __repr__(self):
        return self.__str__()
    def __iter__(self):
        return iter(self._register_map.viewkeys())
    def __getitem__(self,key):
        return getattr(self,key)
    def __setitem__(self,key,value):
        self.__setattr__(key,value)
    def __len__(self):
        return len(self._register_map)
    def __setattr__(self, name, value):
        '''Override attribute storage mechanism to prevent writes to mis-spelled bit fields.'''
        try:
            #First try writes to bit field property decorator
            LTC4162.__dict__[name].fset(self, value)
        except KeyError as e:
            if getattr(self, name, None) is not None:
                #Then try writing to existing conventional instance attributes
                object.__setattr__(self, name, value)
            else:
                #Finally, prevent creation of new instance attributes
                self._error('Attempted write to non-existent field: {}.'.format(name))
    def _read_bf(self, bf_name):
        return self._format(bf_name,self._extract(self.read_function(self.addr_7bit, self._register_map[bf_name]['command_code']),self._register_map[bf_name]['size'],self._register_map[bf_name]['offset']))
    def read_bitfield_list(self, bf_name_list, allow_formats_and_presets=True):
        '''Read the bitfields indicated by bf_name_list and return the results (and any error objects) in a dictionary
        indexed by bitfield name. By default, results may be formatted and converted to enumerated presets, but
        this may be defeated to return raw integer values.'''
        cc_set = set(self._register_map[bf_name]['command_code'] for bf_name in bf_name_list)
        cc_data = self._read_cc_list(cc_set)
        bf_data = collections.OrderedDict()
        for bf_name in sorted(bf_name_list):
            if allow_formats_and_presets:
                bf_data[bf_name] = self._format(bf_name,
                                                self._extract(cc_data[self._register_map[bf_name]['command_code']],
                                                              self._register_map[bf_name]['size'],
                                                              self._register_map[bf_name]['offset']))
            else:
                bf_data[bf_name] = self._extract(cc_data[self._register_map[bf_name]['command_code']],
                                                 self._register_map[bf_name]['size'],
                                                 self._register_map[bf_name]['offset'])
        return bf_data
    def _read_cc_list(self, cc_list):
        '''Read a list of SMBus command codes.'''
        if self.read_list_function is not None:
            return self.read_list_function(self.addr_7bit, cc_list)
        else:
            if not hasattr(self, "_read_cc_list_warning"):
                object.__setattr__(self, "_read_cc_list_warning", True)
                print("Defaulting to reading one command code at a time because "
                      "no read_list_function was given to the LTC4162 constructor.")
            cc_data = collections.OrderedDict()
            for cc in cc_list:
                cc_data[cc] = self.read_function(self.addr_7bit, cc)
            return cc_data
    def unformatted_bf_write(self, bf_name, data):
        '''Write data to bitfield. Assumes data is an integer whose binary representation is the raw bits to insert
        into the containing register in the chip, i.e. assumes data is not formatted.'''
        return self._write_bf(bf_name, data, data_is_unformatted=True)
    def _write_bf(self, bf_name, data, data_is_unformatted=None):
        '''Write to bitfield. If caller is certain that data is unformatted, set data_is_unformatted=True.
        None means uncertain. False means definitely formatted.'''
        if data_is_unformatted is not True:
            data = self._unformat(bf_name, data)
        if self._register_map[bf_name]['size'] == self.word_size: #write-in-place
            if data >= (1<<self.word_size) or data < 0:
                self._error('Data:{} does not fit in field:{} of size:{}.'.format(hex(data),bf_name,self.word_size))
            self.write_function(self.addr_7bit, self._register_map[bf_name]['command_code'],data)
        else: #read-modify-write
            self.write_function(self.addr_7bit, self._register_map[bf_name]['command_code'],self._pack(data,self._register_map[bf_name]['size'],self._register_map[bf_name]['offset'],self.read_function(self.addr_7bit, self._register_map[bf_name]['command_code'])))
    def _extract(self, data, size, offset):
        if not isinstance(data, int):
            return data  # Return any error code verbatim.
        result = (data >> offset) & ((1<<size)-1)
        if self.verbose:
            print('Extracting data:{}, size:{}, offset:{} from raw data:{:#018b}.'.format(bin(result),size,offset,data))
        return result
    def _pack(self, data, size, offset, old_register_contents=0):
        if self.verbose:
            print('Packing new data:{}, size:{}, offset:{} into {:#018b}'.format(bin(data),size,offset,old_register_contents))
        mask = ((1<<self.word_size)-1) ^ (((1<<size)-1)<<offset)
        masked = old_register_contents & mask
        if data >= (1<<size) or data < 0:
            self._error('Data:{} does not fit in field of size:{}.'.format(hex(data),size))
        data = (data<<offset) | masked
        if self.verbose:
            print('mask:{:#018b}, masked_old:{:#018b}, merged:{:#018b}'.format(mask,masked,data))
        return data
    def _transform_from_points(self, xlist, ylist, direction):
        '''Used internally to convert from register values to real world values and back again.'''
        x_evaled = []
        y_evaled = []
        only_constants = {}
        only_constants.update(self._constants)
        only_constants = {key:float(value) for key, value in self._constants.iteritems()}
        for xpoint in xlist:
            x_evaled.append(eval(xpoint, only_constants))
        for ypoint in ylist:
            y_evaled.append(eval(ypoint, only_constants))
        xyevalpoints = sorted(zip(x_evaled, y_evaled), key = lambda x: x[0])
        if direction == "format":
            # z = sorted(zip(x_evaled, y_evaled), key = lambda x: x[0])
            # return lambda x: float(UnivariateSpline(x = zip(*z)[0], y = zip(*z)[1], k=1, s = 0)(x))
            return lambda x: None if x is None else float(interpolator(xyevalpoints)(x))
        elif direction == "unformat":
            # z = sorted(zip(x_evaled, y_evaled), key = lambda x: x[1])
            # return lambda x: int(round(UnivariateSpline(x = zip(*z)[1], y = zip(*z)[0], k=1, s = 0)(x)))
            return lambda y: int(round(interpolator(xyevalpoints).get_x_val(float(y))))
        else:
            raise Exception("'transform_from_points()' requires one of either: 'format' or 'unformat'")
    def _reformat(self, bf_name, data, new_format_name, allow_presets):
        '''Takes a data value read from bf_name and convert it to a new format.'''
        raw_value = self._unformat(bf_name, data)
        return self._format(bf_name, raw_value, new_format_name, allow_presets)
    def _format(self, bf_name, data, format_name=False, allow_presets=True):
        if not isinstance(data, numbers.Number):
            return data  # Return non-numeric Python objects verbatim. Assumes they are error codes.
        format_name = self._register_map[bf_name]['active_format'] if format_name is False else str(format_name)
        if self._register_map[bf_name]['read_presets_enabled'] and allow_presets:
            for (preset,value) in self._register_map[bf_name]['presets']:
                    if (data == value):
                        if self.verbose:
                            print('Read matched preset {} with value {}'.format(preset,value))
                        return preset
        if self.verbose:
            print('Applying format: {}'.format(format_name))
        if self._formatters[format_name]['signed']:
            data = self._twosComplementToSigned(data, self._register_map[bf_name]['size'])
        return self._formatters[format_name]['format'](data)
    def _unformat(self, bf_name, data, from_chosen_format=None):
        for (preset,value) in self._register_map[bf_name]['presets']:
                if (data == preset):
                    if self.verbose:
                        print('Write matched preset {} with value {}'.format(preset,value))
                    return value
        # Try to convert data to a number if possible.
        try:
            data = float(data)
            if data == int(data):
                data = int(data)
        except ValueError:
            pass
        active_format = self._register_map[bf_name]['active_format'] if from_chosen_format is None \
                                                                     else from_chosen_format
        if active_format == 'None':
            return data  # data is already unformatted.
        if self.verbose:
            print('Un-applying format: {}'.format(active_format))
        data = self._formatters[active_format]['unformat'](data)
        assert isinstance(data, int)
        if self._formatters[active_format]['signed']:
            data = self._signedToTwosComplement(data, self._register_map[bf_name]['size'])
        else:
            if data < 0:
                print("WARNING: unformatted data {} clamped to fit bitfield".format(data))
                data = 0
            elif data > 2**self._register_map[bf_name]['size'] - 1:
                print("WARNING: unformatted data {} clamped to fit bitfield".format(data))
                data = 2**self._register_map[bf_name]['size'] - 1
        return data
    def _signedToTwosComplement(self, signed, bitCount):
        '''take Python int and convert to two's complement representation using specified number of bits'''
        if signed > 2**(bitCount-1) - 1:
            print("WARNING: unformatted data {} clamped to fit signed bitfield".format(signed))
            signed = 2**(bitCount-1) - 1
        elif signed < -2**(bitCount-1):
            print("WARNING: unformatted data {} clamped to fit signed bitfield".format(signed))
            signed = -2**(bitCount-1)
        if signed < 0:
            if self.verbose:
                print("Converting negative number:{} of size:{} to two's complement.".format(signed, bitCount))
            signed += 2**bitCount
            signed &= 2**bitCount-1
        return signed
    def _twosComplementToSigned(self, binary, bitCount):
        '''take two's complement number with specified number of bits and convert to python int representation'''
        assert binary <= 2**bitCount - 1
        assert binary >= 0
        if binary >= 2**(bitCount-1):
            original = binary
            binary -= 2**bitCount
            if self.verbose:
                print('Converting binary number:{:b} of size:{} to negative int:{}.'.format(original, bitCount, binary))
        return binary
    def _update_xml_formatters(self):
        self.create_format( format_name = 'None',
                            format_function = lambda x:x,
                            unformat_function = lambda x:x,
                            signed = False,
                            description = '''No formatting applied to data.''',
                            units = '')
        for fmt_name in self._xml_formats:
            xlist, ylist = zip(*self._xml_formats[fmt_name]["points"])
            self.create_format( format_name = fmt_name,
                                format_function = self._transform_from_points(xlist, ylist, "format"),
                                unformat_function = self._transform_from_points(xlist, ylist, "unformat"),
                                signed = self._xml_formats[fmt_name]["signed"],
                                description = self._xml_formats[fmt_name]["description"],
                                units = self._xml_formats[fmt_name]["transformed_units"])


    vbat_lo_alert_limit = property(fget=lambda self: self._read_bf('vbat_lo_alert_limit'),
                                         fset=lambda self,data: self._write_bf('vbat_lo_alert_limit',data),
                                         doc=u'''Signed number that sets a lower limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_lo_alert and can be read back and cleared at vbat_lo_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: vbat_format	Convert from volts to the per-cell vbat ADC reading.''')
    vbat_hi_alert_limit = property(fget=lambda self: self._read_bf('vbat_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('vbat_hi_alert_limit',data),
                                         doc=u'''Signed number that sets an upper limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_hi_alert and can be read back and cleared at vbat_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: vbat_format	Convert from volts to the per-cell vbat ADC reading.''')
    vin_lo_alert_limit = property(fget=lambda self: self._read_bf('vin_lo_alert_limit'),
                                         fset=lambda self,data: self._write_bf('vin_lo_alert_limit',data),
                                         doc=u'''Signed number that sets a lower limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_lo_alert and can be read back and cleared at vin_lo_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: vin_format	Convert from volts to the vin ADC reading.''')
    vin_hi_alert_limit = property(fget=lambda self: self._read_bf('vin_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('vin_hi_alert_limit',data),
                                         doc=u'''Signed number that sets an upper limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_hi_alert and can be read back and cleared at vin_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: vin_format	Convert from volts to the vin ADC reading.''')
    vout_lo_alert_limit = property(fget=lambda self: self._read_bf('vout_lo_alert_limit'),
                                         fset=lambda self,data: self._write_bf('vout_lo_alert_limit',data),
                                         doc=u'''Signed number that sets a lower limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_lo_alert and can be read back and cleared at vout_lo_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: vout_format	Convert from volts to the vout ADC reading.''')
    vout_hi_alert_limit = property(fget=lambda self: self._read_bf('vout_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('vout_hi_alert_limit',data),
                                         doc=u'''Signed number that sets an upper limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_hi_alert and can be read back and cleared at vout_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: vout_format	Convert from volts to the vout ADC reading.''')
    iin_hi_alert_limit = property(fget=lambda self: self._read_bf('iin_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('iin_hi_alert_limit',data),
                                         doc=u'''Signed number that sets an upper limit that can be used to trigger an interrupt based on input current out of range. The value is based on the A/D value, iin, which has a scaling factor of 1.466µV / RSNSI amperes/LSB. The alert is enabled by setting en_iin_hi_alert and can be read back and cleared at iin_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: iin_format	Convert from amperes to the iin ADC reading.''')
    ibat_lo_alert_limit = property(fget=lambda self: self._read_bf('ibat_lo_alert_limit'),
                                         fset=lambda self,data: self._write_bf('ibat_lo_alert_limit',data),
                                         doc=u'''Signed number that sets a lower limit that can be used to trigger an interrupt based on charge current dropping below a particular value, such as during the constant-voltage phase of charging, or, load current exceeding a particular limit when not charging. When the charger is not running, and telemetry is enabled with force_telemetry_on, this limit indicates that the battery draw has exceeded a particular value. Telemetry will be enabled automatically if the input voltage exceeds the battery voltage, in which case discharge current will be nearly zero. ibat values are positive for charging and negative for discharging so the polarity of this register should be set according to the mode in which the limit alert is of interest. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. The alert is enabled by setting en_ibat_lo_alert and can be read back and cleared at ibat_lo_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: ibat_format	Convert from amperes to the ibat ADC reading.''')
    die_temp_hi_alert_limit = property(fget=lambda self: self._read_bf('die_temp_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('die_temp_hi_alert_limit',data),
                                         doc=u'''Signed number that sets an upper limit that can be used to trigger an interrupt based on high die temperature. The value in °C can be calculated from the A/D reading, die_temp, as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C. The alert is enabled by setting en_die_temp_hi_alert and can be read back and cleared at die_temp_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: die_temp_format	Convert from °C to the die_temp ADC reading.''')
    bsr_hi_alert_limit = property(fget=lambda self: self._read_bf('bsr_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('bsr_hi_alert_limit',data),
                                         doc=u'''Sets an upper limit that can be used to trigger an interrupt based on high battery resistance. The per-cell battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from: BSR = cell_count × bsr × RSNSB / 500. The alert is enabled by setting en_bsr_hi_alert and can be read back and cleared at bsr_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: bsr_format	Convert from Ω to the per-cell bsr ADC reading.''')
    thermistor_voltage_hi_alert_limit = property(fget=lambda self: self._read_bf('thermistor_voltage_hi_alert_limit'),
                                         fset=lambda self,data: self._write_bf('thermistor_voltage_hi_alert_limit',data),
                                         doc=u'''Signed number that sets an upper limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_hi_alert can be read back and cleared at thermistor_voltage_hi_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    thermistor_voltage_lo_alert_limit = property(fget=lambda self: self._read_bf('thermistor_voltage_lo_alert_limit'),
                                         fset=lambda self,data: self._write_bf('thermistor_voltage_lo_alert_limit',data),
                                         doc=u'''Signed number that sets a lower limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_lo_alert and can be read back and cleared at thermistor_voltage_lo_alert. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    en_telemetry_valid_alert = property(fget=lambda self: self._read_bf('en_telemetry_valid_alert'),
                                         fset=lambda self,data: self._write_bf('en_telemetry_valid_alert',data),
                                         doc=u'''To ensure high measurement accuracy, the telemetry system in the LTC4162 has a nominal start-up time of approximately 12ms. Setting this interrupt request causes an SMBALERT telemetry_valid_alert when telemetry_valid indicates that the telemetry system's readings are valid. Note that the switching battery charger will not operate until this telemetry system warmup period has passed, regardless of the state of this setting. (1 bit, R/W)\n''')
    en_bsr_done_alert = property(fget=lambda self: self._read_bf('en_bsr_done_alert'),
                                         fset=lambda self,data: self._write_bf('en_bsr_done_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon bsr_done_alert when the bsr (battery-series-resistance) measurement is finished. (1 bit, R/W)\n''')
    en_vbat_lo_alert = property(fget=lambda self: self._read_bf('en_vbat_lo_alert'),
                                         fset=lambda self,data: self._write_bf('en_vbat_lo_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon vbat_lo_alert when vbat is below vbat_lo_alert_limit. (1 bit, R/W)\n''')
    en_vbat_hi_alert = property(fget=lambda self: self._read_bf('en_vbat_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_vbat_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon vbat_hi_alert when vbat is above vbat_hi_alert_limit. (1 bit, R/W)\n''')
    en_vin_lo_alert = property(fget=lambda self: self._read_bf('en_vin_lo_alert'),
                                         fset=lambda self,data: self._write_bf('en_vin_lo_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon vin_lo_alert when vin is below vin_lo_alert_limit. (1 bit, R/W)\n''')
    en_vin_hi_alert = property(fget=lambda self: self._read_bf('en_vin_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_vin_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon vin_hi_alert when vin is above vin_hi_alert_limit. (1 bit, R/W)\n''')
    en_vout_lo_alert = property(fget=lambda self: self._read_bf('en_vout_lo_alert'),
                                         fset=lambda self,data: self._write_bf('en_vout_lo_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon vout_lo_alert when vout is below vout_lo_alert_limit. (1 bit, R/W)\n''')
    en_vout_hi_alert = property(fget=lambda self: self._read_bf('en_vout_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_vout_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon vout_hi_alert when vout is above vout_hi_alert_limit. (1 bit, R/W)\n''')
    en_iin_hi_alert = property(fget=lambda self: self._read_bf('en_iin_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_iin_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon iin_hi_alert when iin is above iin_hi_alert_limit. (1 bit, R/W)\n''')
    en_ibat_lo_alert = property(fget=lambda self: self._read_bf('en_ibat_lo_alert'),
                                         fset=lambda self,data: self._write_bf('en_ibat_lo_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon ibat_lo_alert when ibat is below ibat_lo_alert_limit. (1 bit, R/W)\n''')
    en_die_temp_hi_alert = property(fget=lambda self: self._read_bf('en_die_temp_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_die_temp_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon die_temp_hi_alert when die_temp is above die_temp_hi_alert_limit. (1 bit, R/W)\n''')
    en_bsr_hi_alert = property(fget=lambda self: self._read_bf('en_bsr_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_bsr_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon bsr_hi_alert when bsr is above bsr_hi_alert_limit. (1 bit, R/W)\n''')
    en_thermistor_voltage_hi_alert = property(fget=lambda self: self._read_bf('en_thermistor_voltage_hi_alert'),
                                         fset=lambda self,data: self._write_bf('en_thermistor_voltage_hi_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon thermistor_voltage_hi_alert when thermistor_voltage is above thermistor_voltage_hi_alert_limit. Recall that the thermistor has a negative temperature coefficient so higher thermistor_voltage readings correspond to lower temperatures. (1 bit, R/W)\n''')
    en_thermistor_voltage_lo_alert = property(fget=lambda self: self._read_bf('en_thermistor_voltage_lo_alert'),
                                         fset=lambda self,data: self._write_bf('en_thermistor_voltage_lo_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon thermistor_voltage_lo_alert when thermistor_voltage is below thermistor_voltage_lo_alert_limit. Recall that the thermistor has a negative temperature coefficient so lower thermistor_voltage readings correspond to higher temperatures. (1 bit, R/W)\n''')
    EN_LIMIT_ALERTS_REG = property(fget=lambda self: self._read_bf('EN_LIMIT_ALERTS_REG'),
                                         fset=lambda self,data: self._write_bf('EN_LIMIT_ALERTS_REG',data),
                                         doc=u'''Enable limit monitoring and alert notification via SMBALERT''')
    en_bat_detect_failed_fault_alert = property(fget=lambda self: self._read_bf('en_bat_detect_failed_fault_alert'),
                                         fset=lambda self,data: self._write_bf('en_bat_detect_failed_fault_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon bat_detect_failed_fault_alert as indicated by bat_detect_failed_fault due to an inability to source power to the battery during battery detection testing (usually due to either iin_limit_active or vin_uvcl_active). (1 bit, R/W)\n''')
    en_battery_detection_alert = property(fget=lambda self: self._read_bf('en_battery_detection_alert'),
                                         fset=lambda self,data: self._write_bf('en_battery_detection_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon battery_detection_alert as indicated by battery_detection due to the LTC4162 entering battery detection testing. (1 bit, R/W)\n''')
    en_charger_suspended_alert = property(fget=lambda self: self._read_bf('en_charger_suspended_alert'),
                                         fset=lambda self,data: self._write_bf('en_charger_suspended_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon charger_suspended_alert as indicated by charger_suspended whereby battery charging is terminated due to suspend_charger or thermistor_voltage out of jeita_t1 - jeita_t6 range. (1 bit, R/W)\n''')
    en_precharge_alert = property(fget=lambda self: self._read_bf('en_precharge_alert'),
                                         fset=lambda self,data: self._write_bf('en_precharge_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon precharge_alert as indicated by precharge denoting the onset of the precharge phase of a battery charging cycle. (1 bit, R/W)\n''')
    en_cc_cv_charge_alert = property(fget=lambda self: self._read_bf('en_cc_cv_charge_alert'),
                                         fset=lambda self,data: self._write_bf('en_cc_cv_charge_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon cc_cv_charge_alert as indicated by cc_cv_charge denoting the onset of the constant current / constant voltage phase of a battery charging cycle. (1 bit, R/W)\n''')
    en_ntc_pause_alert = property(fget=lambda self: self._read_bf('en_ntc_pause_alert'),
                                         fset=lambda self,data: self._write_bf('en_ntc_pause_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon ntc_pause_alert as indicated by ntc_pause whereby a battery charge cycle is interrupted due to thermistor_voltage out of range as set by the jeita_t1 through jeita_t6 values. (1 bit, R/W)\n''')
    en_timer_term_alert = property(fget=lambda self: self._read_bf('en_timer_term_alert'),
                                         fset=lambda self,data: self._write_bf('en_timer_term_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon timer_term_alert as indicated by timer_term whereby a battery charge cycle terminates due to tcvtimer reaching max_cv_time, the maximum time allowed in constant_voltage mode. (1 bit, R/W)\n''')
    en_c_over_x_term_alert = property(fget=lambda self: self._read_bf('en_c_over_x_term_alert'),
                                         fset=lambda self,data: self._write_bf('en_c_over_x_term_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon c_over_x_term_alert as indicated by c_over_x_term whereby a battery charge cycle terminates due to ibat dropping below the c_over_x_threshold. (1 bit, R/W)\n''')
    en_max_charge_time_alert = property(fget=lambda self: self._read_bf('en_max_charge_time_alert'),
                                         fset=lambda self,data: self._write_bf('en_max_charge_time_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon max_charge_time_fault_alert as indicated by max_charge_time_fault whereby charging has terminated due to tchargetimer reaching max_charge_time. (1 bit, R/W)\n''')
    en_bat_missing_fault_alert = property(fget=lambda self: self._read_bf('en_bat_missing_fault_alert'),
                                         fset=lambda self,data: self._write_bf('en_bat_missing_fault_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon bat_missing_fault_alert as indicated by bat_missing_fault whereby charging is prohibited if no battery is detected during the battery presence detection phase at the beginning of a charge cycle. (1 bit, R/W)\n''')
    en_bat_short_fault_alert = property(fget=lambda self: self._read_bf('en_bat_short_fault_alert'),
                                         fset=lambda self,data: self._write_bf('en_bat_short_fault_alert',data),
                                         doc=u'''Interrupt request that causes an SMBALERT upon bat_short_fault_alert as indicated by bat_short_fault whereby charging is prohibited if a shorted battery is detected during the battery presence detection phase at the beginning of a charge cycle. (1 bit, R/W)\n''')
    EN_CHARGER_STATE_ALERTS_REG = property(fget=lambda self: self._read_bf('EN_CHARGER_STATE_ALERTS_REG'),
                                         fset=lambda self,data: self._write_bf('EN_CHARGER_STATE_ALERTS_REG',data),
                                         doc=u'''Enable charger state notification via SMBALERT''')
    en_ilim_reg_active_alert = property(fget=lambda self: self._read_bf('en_ilim_reg_active_alert'),
                                         fset=lambda self,data: self._write_bf('en_ilim_reg_active_alert',data),
                                         doc=u'''Interrupt request that causes an ilim_reg_active_alert SMBALERT upon ilim_reg_active (VCSP-VCSN greater than 45mV). May indicates that the switching regulator is currently controlling power delivery based on a safety current limit. This should not occur under normal conditions and is likely the result of a circuit board fault. Alternately indicates that the switching regulator is in dropout (near 100% duty cycle) and is not regulating on any feedback control loop. (1 bit, R/W)\n''')
    en_thermal_reg_active_alert = property(fget=lambda self: self._read_bf('en_thermal_reg_active_alert'),
                                         fset=lambda self,data: self._write_bf('en_thermal_reg_active_alert',data),
                                         doc=u'''Interrupt request that causes a thermal_reg_active_alert SMBALERT upon thermal_reg_active indicating that the icharge_dac is being dialed back to reduce internal die heating. (1 bit, R/W)\n''')
    en_vin_uvcl_active_alert = property(fget=lambda self: self._read_bf('en_vin_uvcl_active_alert'),
                                         fset=lambda self,data: self._write_bf('en_vin_uvcl_active_alert',data),
                                         doc=u'''Interrupt request that causes a vin_uvcl_active_alert SMBALERT upon vin_uvcl_active indicating that the undervoltage regulation loop has taken control of the switching regulator. (1 bit, R/W)\n''')
    en_iin_limit_active_alert = property(fget=lambda self: self._read_bf('en_iin_limit_active_alert'),
                                         fset=lambda self,data: self._write_bf('en_iin_limit_active_alert',data),
                                         doc=u'''Interrupt request that causes a iin_limit_active_alert SMBALERT upon iin_limit_active indicating that the input current regulation loop has taken control of the switching regulator. (1 bit, R/W)\n''')
    en_constant_current_alert = property(fget=lambda self: self._read_bf('en_constant_current_alert'),
                                         fset=lambda self,data: self._write_bf('en_constant_current_alert',data),
                                         doc=u'''Interrupt request that causes a constant_current_alert SMBALERT upon constant_current indicating that the battery charger constant current regulation loop has taken control of the switching regulator. (1 bit, R/W)\n''')
    en_constant_voltage_alert = property(fget=lambda self: self._read_bf('en_constant_voltage_alert'),
                                         fset=lambda self,data: self._write_bf('en_constant_voltage_alert',data),
                                         doc=u'''Interrupt request that causes a constant_voltage_alert SMBALERT upon constant_voltage indicating that the battery charger constant voltage regulation loop has taken control of the switching regulator. (1 bit, R/W)\n''')
    EN_CHARGE_STATUS_ALERTS_REG = property(fget=lambda self: self._read_bf('EN_CHARGE_STATUS_ALERTS_REG'),
                                         fset=lambda self,data: self._write_bf('EN_CHARGE_STATUS_ALERTS_REG',data),
                                         doc=u'''Enable charge status notification via SMBALERT''')
    thermal_reg_start_temp = property(fget=lambda self: self._read_bf('thermal_reg_start_temp'),
                                         fset=lambda self,data: self._write_bf('thermal_reg_start_temp',data),
                                         doc=u'''Signed number that sets the start of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 17897 corresponds to 120°C. (16 bits, R/W)\n\n'''
                                          u'''Format: die_temp_format	Convert from °C to the die_temp ADC reading.''')
    thermal_reg_end_temp = property(fget=lambda self: self._read_bf('thermal_reg_end_temp'),
                                         fset=lambda self,data: self._write_bf('thermal_reg_end_temp',data),
                                         doc=u'''Signed number that sets the end of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 18130 corresponds to 125°C. (16 bits, R/W)\n\n'''
                                          u'''Format: die_temp_format	Convert from °C to the die_temp ADC reading.''')
    suspend_charger = property(fget=lambda self: self._read_bf('suspend_charger'),
                                         fset=lambda self,data: self._write_bf('suspend_charger',data),
                                         doc=u'''Causes battery charging to be suspended. This setting should be used cautiously. For embedded battery systems where two wire interface communication relies on a minimum battery voltage, setting this bit could result in a deadlock that may require factory service to correct. (1 bit, R/W)\n''')
    run_bsr = property(fget=lambda self: self._read_bf('run_bsr'),
                                         fset=lambda self,data: self._write_bf('run_bsr',data),
                                         doc=u'''Causes the battery equivalent-series-resistance (bsr) measurement to be made as soon as a charge cycle starts or immediately if a charge cycle is already running. (1 bit, R/W)\n''')
    telemetry_speed = property(fget=lambda self: self._read_bf('telemetry_speed'),
                                         fset=lambda self,data: self._write_bf('telemetry_speed',data),
                                         doc=u'''Forces the telemetry system to take measurements at the higher rate of approximately once every 11ms whenever the telemetry system is on. When this bit is disabled, the telemetry system will slow down to about once every 5s to reduce power when not charging. Setting telemetry_speed to tel_high_speed in conjunction with force_telemetry_on with no input power available will increase battery drain. (1 bit, R/W)\n\n'''
                                          u'''Preset 'tel_high_speed': 1\n'''
                                          u'''Preset 'tel_low_speed': 0''')
    force_telemetry_on = property(fget=lambda self: self._read_bf('force_telemetry_on'),
                                         fset=lambda self,data: self._write_bf('force_telemetry_on',data),
                                         doc=u'''Causes the telemetry system to operate at all times, including times when only battery power is available. (1 bit, R/W)\n''')
    mppt_en = property(fget=lambda self: self._read_bf('mppt_en'),
                                         fset=lambda self,data: self._write_bf('mppt_en',data),
                                         doc=u'''Causes the Maximum Power-Point Tracking algorithm to run. The maximum power point algorithm takes control of the input undervoltage regulation control loop via the input_undervoltage_dac to seek the optimum power-point for resistive sources such as a long cable or solar panel. (1 bit, R/W)\n''')
    CONFIG_BITS_REG = property(fget=lambda self: self._read_bf('CONFIG_BITS_REG'),
                                         fset=lambda self,data: self._write_bf('CONFIG_BITS_REG',data),
                                         doc=u'''System configuration settings''')
    iin_limit_target = property(fget=lambda self: self._read_bf('iin_limit_target'),
                                         fset=lambda self,data: self._write_bf('iin_limit_target',data),
                                         doc=u'''Controls the target input current limit setting. The input current is limited by regulating charge current in response to the voltage across an external current sense resistor, RSNSI, between the CLP and CLN pins and is given by (iin_limit_target + 1) × 500µV / RSNSI. Note that the LTC4162 can only limit charge current based on this setting. It does not have the authority to block current from passing directly through to the system load. Connecting the system load to the battery, however, can allow total input current control. (6 bits, R/W)\n\n'''
                                          u'''Format: iinlim	Convert from amperes to the iinlim setting.''')
    IIN_LIMIT_TARGET_REG = property(fget=lambda self: self._read_bf('IIN_LIMIT_TARGET_REG'),
                                         fset=lambda self,data: self._write_bf('IIN_LIMIT_TARGET_REG',data),
                                         doc=u'''''')
    input_undervoltage_setting = property(fget=lambda self: self._read_bf('input_undervoltage_setting'),
                                         fset=lambda self,data: self._write_bf('input_undervoltage_setting',data),
                                         doc=u'''Controls the input undervoltage regulation setting. The regulation voltage, given by (input_undervoltage_setting + 1) × 140.625mV, is the voltage at which the charge current will be reduced to prevent further droop in supply voltage due to a resistive source. If mppt_en is set, the MPPT algorithm will override this setting. The actual input undervoltage value can be read back from the input_undervoltage_dac. (8 bits, R/W)\n\n'''
                                          u'''Format: vin_uvcl	Convert from volts to the vin_uvcl setting.''')
    INPUT_UNDERVOLTAGE_SETTING_REG = property(fget=lambda self: self._read_bf('INPUT_UNDERVOLTAGE_SETTING_REG'),
                                         fset=lambda self,data: self._write_bf('INPUT_UNDERVOLTAGE_SETTING_REG',data),
                                         doc=u'''''')
    arm_ship_mode = property(fget=lambda self: self._read_bf('arm_ship_mode'),
                                         fset=lambda self,data: self._write_bf('arm_ship_mode',data),
                                         doc=u'''Setting this register to arm arms the ultra low-power ship and store mode. Ship mode does not take effect until the VIN pin drops below approximately 1V or immediately if VIN is already below 1V. (16 bits, R/W)\n\n'''
                                          u'''Preset 'arm': 21325''')
    charge_current_setting = property(fget=lambda self: self._read_bf('charge_current_setting'),
                                         fset=lambda self,data: self._write_bf('charge_current_setting',data),
                                         doc=u'''Controls the target charge current regulation servo level. The charge current is regulated by servoing the voltage across an external current sense resistor, RSNSB, between the CSP and CSN pins. The servo voltage is given by (charge_current_setting + 1) × 1mV. The effective charge current, determined by the external resistor, RSNSB, is given by (charge_current_setting + 1) × 1mV / RSNSB. icharge_dac will follow charge_current_setting unless thermal_reg_active is true or the JEITA algorithm, with en_jeita, has altered it. (5 bits, R/W)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    CHARGE_CURRENT_SETTING_REG = property(fget=lambda self: self._read_bf('CHARGE_CURRENT_SETTING_REG'),
                                         fset=lambda self,data: self._write_bf('CHARGE_CURRENT_SETTING_REG',data),
                                         doc=u'''''')
    vcharge_setting = property(fget=lambda self: self._read_bf('vcharge_setting'),
                                         fset=lambda self,data: self._write_bf('vcharge_setting',data),
                                         doc=u'''Controls the final charge voltage regulation servo level. To maintain inherent over-charge protection, only Lithium Ion appropriate charge voltage values can be selected. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max). vcharge_dac will follow vcharge_setting unless the advanced JEITA temperature control system (en_jeita) has altered it. (5 bits, R/W)\n\n'''
                                          u'''Preset 'vcharge_lion_default': 31\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    VCHARGE_SETTING_REG = property(fget=lambda self: self._read_bf('VCHARGE_SETTING_REG'),
                                         fset=lambda self,data: self._write_bf('VCHARGE_SETTING_REG',data),
                                         doc=u'''''')
    c_over_x_threshold = property(fget=lambda self: self._read_bf('c_over_x_threshold'),
                                         fset=lambda self,data: self._write_bf('c_over_x_threshold',data),
                                         doc=u'''Signed number that sets the ibat A/D value used to qualify C/x detection and termination. The C/x level is based on the value for ibat which has a scaling factor of 1.466µV / RSNSB amperes/LSB. For example, to make the C/x level C/10 (a very common choice) then c_over_x_threshold should be set to c_over_10 which is 10% of the maximum possible ibat reading (32mV × 37.5 × 18,191 / 10). 32mV is the full scale charge current signal from CSP to CSN, 37.5 is the internal charge amplifier's gain and 18,191 is the A/D's span term in counts per Volt. (16 bits, R/W)\n\n'''
                                          u'''Preset 'c_over_10': 2184\n'''
                                          u'''Format: ibat_format	Convert from amperes to the ibat ADC reading.''')
    max_cv_time = property(fget=lambda self: self._read_bf('max_cv_time'),
                                         fset=lambda self,data: self._write_bf('max_cv_time',data),
                                         doc=u'''Sets the constant-voltage termination setting against which the tcvtimer is compared. The timer begins at the onset of the constant_voltage phase of charging and increments at one count per second. The default setting is 14,400 (4 hours). (16 bits, R/W)\n\n'''
                                          u'''Preset '30mins': 1800\n'''
                                          u'''Preset '1hour': 3600\n'''
                                          u'''Preset '2hours': 7200\n'''
                                          u'''Preset '4hours_default': 14400''')
    max_charge_time = property(fget=lambda self: self._read_bf('max_charge_time'),
                                         fset=lambda self,data: self._write_bf('max_charge_time',data),
                                         doc=u'''Sets the total charge time termination setting against which the tchargetimer is compared. The default value of 0 disables the total charge time feature and prevents the tchargetimer from running. If enabled with a non zero value, the tchargetimer begins counting at the onset of a charge cycle and increments at one count per minute. (16 bits, R/W)\n\n'''
                                          u'''Preset 'maxchargetime_disable': 0''')
    jeita_t1 = property(fget=lambda self: self._read_bf('jeita_t1'),
                                         fset=lambda self,data: self._write_bf('jeita_t1',data),
                                         doc=u'''Signed number that sets the JEITA temperature region transition temperature T1 between JEITA regions R1 and R2. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 16117 maps to about 0°C for the expected thermistor β value of 3490K. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    jeita_t2 = property(fget=lambda self: self._read_bf('jeita_t2'),
                                         fset=lambda self,data: self._write_bf('jeita_t2',data),
                                         doc=u'''Signed number that sets the JEITA temperature region transition temperature T2 between JEITA regions R2 and R3. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 14113 maps to about 10°C for the expected thermistor β value of 3490K. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    jeita_t3 = property(fget=lambda self: self._read_bf('jeita_t3'),
                                         fset=lambda self,data: self._write_bf('jeita_t3',data),
                                         doc=u'''Signed number that sets the JEITA temperature region transition temperature T3 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7970 maps to about 40°C for the expected thermistor β value of 3490K. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    jeita_t4 = property(fget=lambda self: self._read_bf('jeita_t4'),
                                         fset=lambda self,data: self._write_bf('jeita_t4',data),
                                         doc=u'''Signed number that sets the JEITA temperature region transition temperature T4 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7112 maps to about 45°C for the expected thermistor β value of 3490K. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    jeita_t5 = property(fget=lambda self: self._read_bf('jeita_t5'),
                                         fset=lambda self,data: self._write_bf('jeita_t5',data),
                                         doc=u'''Signed number that sets the JEITA temperature region transition temperature T5 between JEITA regions R5 and R6. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 6325 maps to about 50°C for the expected thermistor β value of 3490K. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    jeita_t6 = property(fget=lambda self: self._read_bf('jeita_t6'),
                                         fset=lambda self,data: self._write_bf('jeita_t6',data),
                                         doc=u'''Signed number that sets the JEITA temperature region transition temperature T6 between JEITA regions R6 and R7. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 4970 maps to about 60°C for the expected thermistor β value of 3490K. (16 bits, R/W)\n\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    vcharge_jeita_6 = property(fget=lambda self: self._read_bf('vcharge_jeita_6'),
                                         fset=lambda self,data: self._write_bf('vcharge_jeita_6',data),
                                         doc=u'''Sets the charge voltage to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_6 × 12.5mV + 3.8125V. The default value of 19 corresponds to 4.05V. (5 bits, R/W)\n\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    vcharge_jeita_5 = property(fget=lambda self: self._read_bf('vcharge_jeita_5'),
                                         fset=lambda self,data: self._write_bf('vcharge_jeita_5',data),
                                         doc=u'''Sets the charge voltage to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_5 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V. (5 bits, R/W)\n\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    VCHARGE_JEITA_6_5_REG = property(fget=lambda self: self._read_bf('VCHARGE_JEITA_6_5_REG'),
                                         fset=lambda self,data: self._write_bf('VCHARGE_JEITA_6_5_REG',data),
                                         doc=u'''vcharge_setting values for JEITA temperature regions jeita_t6 and jeita_t5''')
    vcharge_jeita_4 = property(fget=lambda self: self._read_bf('vcharge_jeita_4'),
                                         fset=lambda self,data: self._write_bf('vcharge_jeita_4',data),
                                         doc=u'''Sets the charge voltage to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_4 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V (5 bits, R/W)\n\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    vcharge_jeita_3 = property(fget=lambda self: self._read_bf('vcharge_jeita_3'),
                                         fset=lambda self,data: self._write_bf('vcharge_jeita_3',data),
                                         doc=u'''Sets the charge voltage to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_3 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V. (5 bits, R/W)\n\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    vcharge_jeita_2 = property(fget=lambda self: self._read_bf('vcharge_jeita_2'),
                                         fset=lambda self,data: self._write_bf('vcharge_jeita_2',data),
                                         doc=u'''Sets the charge voltage to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_2 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V. (5 bits, R/W)\n\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    VCHARGE_JEITA_4_3_2_REG = property(fget=lambda self: self._read_bf('VCHARGE_JEITA_4_3_2_REG'),
                                         fset=lambda self,data: self._write_bf('VCHARGE_JEITA_4_3_2_REG',data),
                                         doc=u'''vcharge_setting values for JEITA temperature regions jeita_t4, jeita_t3, and jeita_t2''')
    icharge_jeita_6 = property(fget=lambda self: self._read_bf('icharge_jeita_6'),
                                         fset=lambda self,data: self._write_bf('icharge_jeita_6',data),
                                         doc=u'''Sets the charge current to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_6 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2. (5 bits, R/W)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    icharge_jeita_5 = property(fget=lambda self: self._read_bf('icharge_jeita_5'),
                                         fset=lambda self,data: self._write_bf('icharge_jeita_5',data),
                                         doc=u'''Sets the charge current to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_5 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2. (5 bits, R/W)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    ICHARGE_JEITA_6_5_REG = property(fget=lambda self: self._read_bf('ICHARGE_JEITA_6_5_REG'),
                                         fset=lambda self,data: self._write_bf('ICHARGE_JEITA_6_5_REG',data),
                                         doc=u'''charge_current_setting values for JEITA temperature regions jeita_t6 and jeita_t5''')
    icharge_jeita_4 = property(fget=lambda self: self._read_bf('icharge_jeita_4'),
                                         fset=lambda self,data: self._write_bf('icharge_jeita_4',data),
                                         doc=u'''Sets the charge current to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_4 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale. (5 bits, R/W)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    icharge_jeita_3 = property(fget=lambda self: self._read_bf('icharge_jeita_3'),
                                         fset=lambda self,data: self._write_bf('icharge_jeita_3',data),
                                         doc=u'''Sets the charge current to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the  charge current can be calculated using (icharge_jeita_3 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale. (5 bits, R/W)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    icharge_jeita_2 = property(fget=lambda self: self._read_bf('icharge_jeita_2'),
                                         fset=lambda self,data: self._write_bf('icharge_jeita_2',data),
                                         doc=u'''Sets the charge current to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_2 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2. (5 bits, R/W)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    ICHARGE_JEITA_4_3_2_REG = property(fget=lambda self: self._read_bf('ICHARGE_JEITA_4_3_2_REG'),
                                         fset=lambda self,data: self._write_bf('ICHARGE_JEITA_4_3_2_REG',data),
                                         doc=u'''charge_current_setting value for JEITA temperature regions jeita_t4, jeita_t3, and jeita_t2''')
    en_c_over_x_term = property(fget=lambda self: self._read_bf('en_c_over_x_term'),
                                         fset=lambda self,data: self._write_bf('en_c_over_x_term',data),
                                         doc=u'''Enables charge current based (C/x) battery charger termination as set by ibat dropping to the c_over_x_threshold in constant_voltage. (1 bit, R/W)\n''')
    en_jeita = property(fget=lambda self: self._read_bf('en_jeita'),
                                         fset=lambda self,data: self._write_bf('en_jeita',data),
                                         doc=u'''Enables the JEITA temperature qualified charging system. (1 bit, R/W)\n''')
    CHARGER_CONFIG_BITS_REG = property(fget=lambda self: self._read_bf('CHARGER_CONFIG_BITS_REG'),
                                         fset=lambda self,data: self._write_bf('CHARGER_CONFIG_BITS_REG',data),
                                         doc=u'''Battery charger configuration settings''')
    tchargetimer = property(fget=lambda self: self._read_bf('tchargetimer'),
                                         fset=lambda self, data: self._error('Write access not allowed to field tchargetimer'),
                                         doc=u'''If max_charge_time is written to a non zero value tchargetimer is the elapsed time in minutes since the beginning of a charge cycle. The LTC4162 will terminate charging when tchargetimer reaches the value in max_charge_time. (16 bits, Read Only)\n''')
    tcvtimer = property(fget=lambda self: self._read_bf('tcvtimer'),
                                         fset=lambda self, data: self._error('Write access not allowed to field tcvtimer'),
                                         doc=u'''This is the elapsed time in seconds since the battery charger has been in the constant_voltage phase of charging. If this value exceeds max_cv_time then charging is considered complete and will terminate. (16 bits, Read Only)\n''')
    charger_state = property(fget=lambda self: self._read_bf('charger_state'),
                                         fset=lambda self, data: self._error('Write access not allowed to field charger_state'),
                                         doc=u'''Real time battery charger state indicator. Individual bits are mutually exclusive. (13 bits, Read Only)\n\n'''
                                          u'''Preset 'bat_detect_failed_fault': 4096	 Indicates that the battery charger is not charging due to an inability to source power during the battery detection test because either vin_uvcl_active or iin_limit_active regulation was true during the battery detection phase of a charge cycle.\n'''
                                          u'''Preset 'battery_detection': 2048	 Indicates that the LTC4162 is in the battery detection phase of a charge cycle.\n'''
                                          u'''Preset 'charger_suspended': 256	 Indicates that the battery charging feature is currently suspended due to suspend_charger or has a thermistor_voltage above jeita_t1 or below jeita_t6.\n'''
                                          u'''Preset 'precharge': 128	 Indicates that the LTC4162 is in the precondition phase of charging.\n'''
                                          u'''Preset 'cc_cv_charge': 64	 Indicates that the LTC4162 is in either the constant_current or constant_voltage phase of charging.\n'''
                                          u'''Preset 'ntc_pause': 32	 Indicates that charging is currently paused due to thermistor_voltage being above jeita_t1 or below jeita_t6 as set by the JEITA temperature qualified charging system. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. jeita_t6 and jeita_t1 are still observed even if en_jeita is set to 0.\n'''
                                          u'''Preset 'timer_term': 16	 Indicates that the battery charger is currently terminated due to tcvtimer reaching max_cv_time during a charge cycle.\n'''
                                          u'''Preset 'c_over_x_term': 8	 Indicates that the battery charger is currently terminated due to ibat falling below the c_over_x_threshold (C/x detection) during the constant_voltage phase of charging as determined by c_over_x_threshold and en_c_over_x_term.\n'''
                                          u'''Preset 'max_charge_time_fault': 4	 Indicates that the battery charger is currently terminated due to tchargetimer reaching max_charge_time.\n'''
                                          u'''Preset 'bat_missing_fault': 2	 Indicates that the battery charger is not charging because no battery was found during the battery detection test at the beginning of a charge cycle or if, at any time, the thermistor_voltage goes above 21,684 indicating an open or missing thermistor.\n'''
                                          u'''Preset 'bat_short_fault': 1	 Indicates that the battery charger is not charging because the battery was found to be shorted during the battery detection test at the beginning of a charge cycle.''')
    CHARGER_STATE_REG = property(fget=lambda self: self._read_bf('CHARGER_STATE_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register CHARGER_STATE_REG'),
                                         doc=u'''''')
    charge_status = property(fget=lambda self: self._read_bf('charge_status'),
                                         fset=lambda self, data: self._error('Write access not allowed to field charge_status'),
                                         doc=u'''Charge status indicator. Individual bits are mutually exclusive and are only active in charging states. (6 bits, Read Only)\n\n'''
                                          u'''Preset 'ilim_reg_active': 32	 May indicate that the switching regulator is currently controlling power delivery based on a safety current limit (~45mV from CSP to CSN). This should not occur under normal conditions and is likely the result of a circuit board fault. Alternately indicates that the switching regulator is in dropout (highest possible duty cycle) and is not regulating on any feedback control loop.\n'''
                                          u'''Preset 'thermal_reg_active': 16	 Indicates that the icharge_dac has been automatically throttled because the die_temp has reached thermal_reg_start_temp.\n'''
                                          u'''Preset 'vin_uvcl_active': 8	 Indicates that the input voltage control loop is currently controlling power delivery to the battery based on the input_undervoltage_dac which normally targets input_undervoltage_setting. This control loop is manipulated internally when mppt_en is set.\n'''
                                          u'''Preset 'iin_limit_active': 4	 Indicates that the input current control loop is currently controlling power delivery to the battery based on iin_limit_dac which normally targets iin_limit_target.\n'''
                                          u'''Preset 'constant_current': 2	 Indicates that the charge current control loop is currently controlling power delivery to the battery based on icharge_dac which normally targets charge_current_setting. This control loop is manipulated internally if en_jeita is true.\n'''
                                          u'''Preset 'constant_voltage': 1	 Indicates that the charge voltage control loop is currently controlling power delivery to the battery based on vcharge_dac which normally targets vcharge_setting. This control loop is manipulated internally if en_jeita is true.\n'''
                                          u'''Preset 'charger_off': 0	 Indicates that the charger is not currently running. Due to a logic error this state may transiently appear during normal operation. Sampling it several times is recommended.''')
    CHARGE_STATUS_REG = property(fget=lambda self: self._read_bf('CHARGE_STATUS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register CHARGE_STATUS_REG'),
                                         doc=u'''''')
    telemetry_valid_alert = property(fget=lambda self: self._read_bf('telemetry_valid_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field telemetry_valid_alert'),
                                         doc=u'''Alert that indicates that the telemetry system warm-up time has expired and valid telemetry data is available from the serial port. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_telemetry_valid_alert. (1 bit, Read Only)\n''')
    bsr_done_alert = property(fget=lambda self: self._read_bf('bsr_done_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bsr_done_alert'),
                                         doc=u'''Alert that indicates that the battery equivalent-series-resistance measurement is finished and a result is available in bsr. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bsr_done_alert. (1 bit, Read Only)\n''')
    vbat_lo_alert = property(fget=lambda self: self._read_bf('vbat_lo_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vbat_lo_alert'),
                                         doc=u'''Alert that indicates that vbat is below the value set by vbat_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vbat_lo_alert. (1 bit, Read Only)\n''')
    vbat_hi_alert = property(fget=lambda self: self._read_bf('vbat_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vbat_hi_alert'),
                                         doc=u'''Alert that indicates that vbat is above the value set by vbat_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vbat_hi_alert. (1 bit, Read Only)\n''')
    vin_lo_alert = property(fget=lambda self: self._read_bf('vin_lo_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin_lo_alert'),
                                         doc=u'''Alert that indicates that vin is below the value set by vin_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_lo_alert. (1 bit, Read Only)\n''')
    vin_hi_alert = property(fget=lambda self: self._read_bf('vin_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin_hi_alert'),
                                         doc=u'''Alert that indicates that vin is above the value set by vin_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_hi_alert. (1 bit, Read Only)\n''')
    vout_lo_alert = property(fget=lambda self: self._read_bf('vout_lo_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vout_lo_alert'),
                                         doc=u'''Alert that indicates that vout is below the value set by vout_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vout_lo_alert. (1 bit, Read Only)\n''')
    vout_hi_alert = property(fget=lambda self: self._read_bf('vout_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vout_hi_alert'),
                                         doc=u'''Alert that indicates that vout is above the value set by vout_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vout_hi_alert. (1 bit, Read Only)\n''')
    iin_hi_alert = property(fget=lambda self: self._read_bf('iin_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field iin_hi_alert'),
                                         doc=u'''Alert that indicates that iin is above the value set by iin_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_iin_hi_alert. (1 bit, Read Only)\n''')
    ibat_lo_alert = property(fget=lambda self: self._read_bf('ibat_lo_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field ibat_lo_alert'),
                                         doc=u'''Alert that indicates that ibat is below the value set by ibat_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ibat_lo_alert. (1 bit, Read Only)\n''')
    die_temp_hi_alert = property(fget=lambda self: self._read_bf('die_temp_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field die_temp_hi_alert'),
                                         doc=u'''Alert that indicates that die_temp is above the value set by die_temp_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_die_temp_hi_alert. (1 bit, Read Only)\n''')
    bsr_hi_alert = property(fget=lambda self: self._read_bf('bsr_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bsr_hi_alert'),
                                         doc=u'''Alert that indicates that bsr is above the value set by bsr_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bsr_hi_alert. (1 bit, Read Only)\n''')
    thermistor_voltage_hi_alert = property(fget=lambda self: self._read_bf('thermistor_voltage_hi_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field thermistor_voltage_hi_alert'),
                                         doc=u'''Alert that indicates that thermistor_voltage is above the value set by thermistor_voltage_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermistor_voltage_hi_alert. (1 bit, Read Only)\n''')
    thermistor_voltage_lo_alert = property(fget=lambda self: self._read_bf('thermistor_voltage_lo_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field thermistor_voltage_lo_alert'),
                                         doc=u'''Alert that indicates that thermistor_voltage is below the value set by thermistor_voltage_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermistor_voltage_lo_alert. (1 bit, Read Only)\n''')
    LIMIT_ALERTS_REG = property(fget=lambda self: self._read_bf('LIMIT_ALERTS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register LIMIT_ALERTS_REG'),
                                         doc=u'''Limit alert register. This input/output register indicates that an enabled alert has occurred. Individual alerts are enabled in EN_LIMIT_ALERTS_REG. Writing 0 to any bit clears that alert. Once set, alert bits remain high until cleared or disabled.''')
    bat_detect_failed_fault_alert = property(fget=lambda self: self._read_bf('bat_detect_failed_fault_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bat_detect_failed_fault_alert'),
                                         doc=u'''Alert that indicates a bat_detect_failed_fault. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_detect_failed_fault_alert. (1 bit, Read Only)\n''')
    battery_detection_alert = property(fget=lambda self: self._read_bf('battery_detection_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field battery_detection_alert'),
                                         doc=u'''Alert that indicates the battery charger is performing battery_detection. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_battery_detecttion_alert. (1 bit, Read Only)\n''')
    charger_suspended_alert = property(fget=lambda self: self._read_bf('charger_suspended_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field charger_suspended_alert'),
                                         doc=u'''Alert that indicates the battery charger is in the charger_suspended state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_charger_suspended_alert. (1 bit, Read Only)\n''')
    precharge_alert = property(fget=lambda self: self._read_bf('precharge_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field precharge_alert'),
                                         doc=u'''Alert that indicates that the battery charger is in the precharge phase. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_precharge_alert. (1 bit, Read Only)\n''')
    cc_cv_charge_alert = property(fget=lambda self: self._read_bf('cc_cv_charge_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field cc_cv_charge_alert'),
                                         doc=u'''Alert that indicates that the battery charge is in the cc_cv_charge phase. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_cc_cv_charge_alert. (1 bit, Read Only)\n''')
    ntc_pause_alert = property(fget=lambda self: self._read_bf('ntc_pause_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field ntc_pause_alert'),
                                         doc=u'''Alert that indicates that the battery charger is in the ntc_pause state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ntc_pause_alert. (1 bit, Read Only)\n''')
    timer_term_alert = property(fget=lambda self: self._read_bf('timer_term_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field timer_term_alert'),
                                         doc=u'''Alert that indicates that the battery charge is in the timer_term state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_timer_term_alert. (1 bit, Read Only)\n''')
    c_over_x_term_alert = property(fget=lambda self: self._read_bf('c_over_x_term_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field c_over_x_term_alert'),
                                         doc=u'''Alert that indicates that the battery charge is in the c_over_x_term state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_c_over_x_term_alert. (1 bit, Read Only)\n''')
    max_charge_time_fault_alert = property(fget=lambda self: self._read_bf('max_charge_time_fault_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field max_charge_time_fault_alert'),
                                         doc=u'''Alert that indicates that the battery charge is in the max_charge_time_fault state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_max_charge_time_alert. (1 bit, Read Only)\n''')
    bat_missing_fault_alert = property(fget=lambda self: self._read_bf('bat_missing_fault_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bat_missing_fault_alert'),
                                         doc=u'''Alert that indicates that a bat_missing_fault has been detected. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_missing_fault_alert. (1 bit, Read Only)\n''')
    bat_short_fault_alert = property(fget=lambda self: self._read_bf('bat_short_fault_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bat_short_fault_alert'),
                                         doc=u'''Alert that indicates that a bat_short_fault has been detected. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_short_fault_alert. (1 bit, Read Only)\n''')
    CHARGER_STATE_ALERTS_REG = property(fget=lambda self: self._read_bf('CHARGER_STATE_ALERTS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register CHARGER_STATE_ALERTS_REG'),
                                         doc=u'''Alert that indicates that charger states have occurred. Individual bits are enabled by EN_CHARGER_STATE_ALERTS_REG. Writing 0 to any bit while writing 1s to the remaining bits clears that alert. Once set, alert bits remain high until cleared or disabled.''')
    ilim_reg_active_alert = property(fget=lambda self: self._read_bf('ilim_reg_active_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field ilim_reg_active_alert'),
                                         doc=u'''Alert that indicates that charge_status is ilim_reg_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ilim_reg_active_alert. (1 bit, Read Only)\n''')
    thermal_reg_active_alert = property(fget=lambda self: self._read_bf('thermal_reg_active_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field thermal_reg_active_alert'),
                                         doc=u'''Alert that indicates that charge_status is thermal_reg_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermal_reg_active_alert. (1 bit, Read Only)\n''')
    vin_uvcl_active_alert = property(fget=lambda self: self._read_bf('vin_uvcl_active_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin_uvcl_active_alert'),
                                         doc=u'''Alert that indicates that charge_status is vin_uvcl_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_uvcl_active_alert. (1 bit, Read Only)\n''')
    iin_limit_active_alert = property(fget=lambda self: self._read_bf('iin_limit_active_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field iin_limit_active_alert'),
                                         doc=u'''Alert that indicates that charge_status is iin_limit_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_iin_limit_active_alert. (1 bit, Read Only)\n''')
    constant_current_alert = property(fget=lambda self: self._read_bf('constant_current_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field constant_current_alert'),
                                         doc=u'''Alert that indicates that charge_status is constant_current. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_constant_current_alert. (1 bit, Read Only)\n''')
    constant_voltage_alert = property(fget=lambda self: self._read_bf('constant_voltage_alert'),
                                         fset=lambda self, data: self._error('Write access not allowed to field constant_voltage_alert'),
                                         doc=u'''Alert that indicates that charge_status is constant_voltage. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_constant_voltage_alert. (1 bit, Read Only)\n''')
    CHARGE_STATUS_ALERTS_REG = property(fget=lambda self: self._read_bf('CHARGE_STATUS_ALERTS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register CHARGE_STATUS_ALERTS_REG'),
                                         doc=u'''Alerts that charge_status indicators have occurred. Individual bits are enabled by EN_CHARGE_STATUS_ALERTS_REG. Writing 0 to any bit clears that alert. Once set, alert bits remain high until cleared or disabled.''')
    en_chg = property(fget=lambda self: self._read_bf('en_chg'),
                                         fset=lambda self, data: self._error('Write access not allowed to field en_chg'),
                                         doc=u'''Indicates that the battery charger is active. (1 bit, Read Only)\n''')
    cell_count_err = property(fget=lambda self: self._read_bf('cell_count_err'),
                                         fset=lambda self, data: self._error('Write access not allowed to field cell_count_err'),
                                         doc=u'''A cell count error will occur and charging will be inhibited if the CELLS0 and CELLS1 pins are programmed for more than 8 cells. cell_count_err always indicates true when telemetry is not enabled such as when the charger is not enabled. (1 bit, Read Only)\n''')
    no_rt = property(fget=lambda self: self._read_bf('no_rt'),
                                         fset=lambda self, data: self._error('Write access not allowed to field no_rt'),
                                         doc=u'''Indicates that no frequency setting resistor is detected on the RT pin. The RT pin impedance detection circuit will typically indicate a missing RT resistor for values above 1.4MΩ. no_rt always indicates true when the battery charger is not enabled such as when there is no input power available. (1 bit, Read Only)\n''')
    thermal_shutdown = property(fget=lambda self: self._read_bf('thermal_shutdown'),
                                         fset=lambda self, data: self._error('Write access not allowed to field thermal_shutdown'),
                                         doc=u'''Indicates that the LTC4162 is in thermal shutdown protection due to an excessively high die temperature (typically 150°C). (1 bit, Read Only)\n''')
    vin_ovlo = property(fget=lambda self: self._read_bf('vin_ovlo'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin_ovlo'),
                                         doc=u'''Indicates that input voltage shutdown protection is active due to an input voltage above its protection shut-down threshold of approximately 38.6V. (1 bit, Read Only)\n''')
    vin_gt_vbat = property(fget=lambda self: self._read_bf('vin_gt_vbat'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin_gt_vbat'),
                                         doc=u'''Indicates that the VIN pin voltage is sufficiently above the battery voltage to begin a charge cycle (typically +150mV). (1 bit, Read Only)\n''')
    vin_gt_4p2v = property(fget=lambda self: self._read_bf('vin_gt_4p2v'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin_gt_4p2v'),
                                         doc=u'''Indicates that the VIN pin voltage is at least greater than the switching regulator under-voltage lockout level (4.2V typical). (1 bit, Read Only)\n''')
    intvcc_gt_2p8v = property(fget=lambda self: self._read_bf('intvcc_gt_2p8v'),
                                         fset=lambda self, data: self._error('Write access not allowed to field intvcc_gt_2p8v'),
                                         doc=u'''Indicates that the INTVCC pin voltage is greater than the telemetry system lockout level (2.8V typical). (1 bit, Read Only)\n''')
    SYSTEM_STATUS_REG = property(fget=lambda self: self._read_bf('SYSTEM_STATUS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register SYSTEM_STATUS_REG'),
                                         doc=u'''Real time system status indicator bits''')
    vbat = property(fget=lambda self: self._read_bf('vbat'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vbat'),
                                         doc=u'''Signed number that indicates the A/D measurement for the per-cell battery voltage. The value is based on the A/D scaling factor for the battery voltage measurement which is cell_count × 192.4µV/LSB at the BATSENS+ pin. (16 bits, Read Only)\n\n'''
                                          u'''Format: vbat_format	Convert from volts to the per-cell vbat ADC reading.''')
    vin = property(fget=lambda self: self._read_bf('vin'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vin'),
                                         doc=u'''Signed number that indicates the A/D measurement for the input voltage. The value is based on the A/D scaling factor for the input voltage measurement which is 1.649mV/LSB. (16 bits, Read Only)\n\n'''
                                          u'''Format: vin_format	Convert from volts to the vin ADC reading.''')
    vout = property(fget=lambda self: self._read_bf('vout'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vout'),
                                         doc=u'''Signed number that indicates the A/D measurement for the vout voltage. The value is based on the A/D scaling factor for the output voltage measurement which is 1.653mV/LSB. (16 bits, Read Only)\n\n'''
                                          u'''Format: vout_format	Convert from volts to the vout ADC reading.''')
    ibat = property(fget=lambda self: self._read_bf('ibat'),
                                         fset=lambda self, data: self._error('Write access not allowed to field ibat'),
                                         doc=u'''Signed number that indicates the A/D measurement for the battery current. The value is based on the A/D scaling factor for the charge current measurement (VCSP - VCSN) which is 1.466µV / RSNSB amperes/LSB. If the charger is not enabled the value represents drain on the battery and will be negative. (16 bits, Read Only)\n\n'''
                                          u'''Format: ibat_format	Convert from amperes to the ibat ADC reading.''')
    iin = property(fget=lambda self: self._read_bf('iin'),
                                         fset=lambda self, data: self._error('Write access not allowed to field iin'),
                                         doc=u'''Signed number that indicates the A/D measurement for the input current (VCLP - VCLN). The value is based on the A/D scaling factor for the input current measurement which is 1.466µV / RSNSI amperes/LSB. (16 bits, Read Only)\n\n'''
                                          u'''Format: iin_format	Convert from amperes to the iin ADC reading.''')
    die_temp = property(fget=lambda self: self._read_bf('die_temp'),
                                         fset=lambda self, data: self._error('Write access not allowed to field die_temp'),
                                         doc=u'''Signed number that indicates the A/D measurement for the die temperature. The value can be calculated from the A/D reading in °C as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C. (16 bits, Read Only)\n\n'''
                                          u'''Format: die_temp_format	Convert from °C to the die_temp ADC reading.''')
    thermistor_voltage = property(fget=lambda self: self._read_bf('thermistor_voltage'),
                                         fset=lambda self, data: self._error('Write access not allowed to field thermistor_voltage'),
                                         doc=u'''Signed number that indicates the A/D measurement for the NTC pin voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × thermistor_voltage / (21829 - thermistor_voltage). Recall that the thermistor has a negative temperature coefficient so higher temperatures make lower thermistor_voltage readings and vice-versa. (16 bits, Read Only)\n\n'''
                                          u'''Preset 'open_thermistor': 21684\n'''
                                          u'''Format: NTCS0402E3103FLT	Convert from °C to the thermistor ADC reading.''')
    bsr = property(fget=lambda self: self._read_bf('bsr'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bsr'),
                                         doc=u'''Indicates the A/D measurement for the per-cell battery resistance. The battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from cell_count × bsr × RSNSB / 500. If the charge current, ibat, is below icharge_over_10, bsr_questionable will be set. (16 bits, Read Only)\n\n'''
                                          u'''Format: bsr_format	Convert from Ω to the per-cell bsr ADC reading.''')
    jeita_region = property(fget=lambda self: self._read_bf('jeita_region'),
                                         fset=lambda self, data: self._error('Write access not allowed to field jeita_region'),
                                         doc=u'''Indicates the LTC4162 JEITA battery temperature region containing the thermistor_voltage. The temperature region consists of the values bounded by the transition temperatures jeita_t(R-1) and jeita_t(R). Recall that the thermistor has a negative temperature coefficient so higher temperatures make lower thermistor_voltage readings and vice-versa. JEITA temperature-controlled charging is active only when en_jeita is at its default value of 1. JEITA regions R7 (jeita_region = 7) and R1 (jeita_region = 1) indicate that the thermistor_voltage (battery temperature) is out of range for charging and therefore charging is paused (ntc_pause). The transition temperatures are set by jeita_t1 through jeita_t6. (3 bits, Read Only)\n\n'''
                                          u'''Preset 'R7': 7\n'''
                                          u'''Preset 'R6': 6\n'''
                                          u'''Preset 'R5': 5\n'''
                                          u'''Preset 'R4': 4\n'''
                                          u'''Preset 'R3': 3\n'''
                                          u'''Preset 'R2': 2\n'''
                                          u'''Preset 'R1': 1''')
    JEITA_REGION_REG = property(fget=lambda self: self._read_bf('JEITA_REGION_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register JEITA_REGION_REG'),
                                         doc=u'''''')
    chem = property(fget=lambda self: self._read_bf('chem'),
                                         fset=lambda self, data: self._error('Write access not allowed to field chem'),
                                         doc=u'''Indicates the chemistry of the battery being charged. For additional safety, application software can test this value to ensure that the correct version of the LTC4162 (LTC4162-L, LTC4162-F or LTC4162-S) is populated on the circuit board. (4 bits, Read Only)\n\n'''
                                          u'''Preset 'LTC4162_LAD': 0	 Li-Ion I²C Adjustable Voltage\n'''
                                          u'''Preset 'LTC4162_L42': 1	 Li-Ion 4.2V Fixed Charge\n'''
                                          u'''Preset 'LTC4162_L41': 2	 Li-Ion 4.1V Fixed Charge\n'''
                                          u'''Preset 'LTC4162_L40': 3	 Li-Ion 4.0V Fixed Charge\n'''
                                          u'''Preset 'LTC4162_FAD': 4	 LiFePO4 I²C Adjustable Voltage\n'''
                                          u'''Preset 'LTC4162_FFS': 5	 LiFePO4 3.8V Rapid Charge\n'''
                                          u'''Preset 'LTC4162_FST': 6	 LiFePO4 3.6V Fixed Charge\n'''
                                          u'''Preset 'LTC4162_SST': 8	 Lead Acid Fixed Voltage\n'''
                                          u'''Preset 'LTC4162_SAD': 9	 Lead Acid I²C Adjustable Voltage''')
    cell_count = property(fget=lambda self: self._read_bf('cell_count'),
                                         fset=lambda self, data: self._error('Write access not allowed to field cell_count'),
                                         doc=u'''Indicates the cell count value detected by the CELLS0 and CELLS1 pin strapping. cell_count always indicates 0 when the battery charger is not enabled such as when there is no input power available. (4 bits, Read Only)\n\n'''
                                          u'''Preset 'Unknown': 0''')
    CHEM_CELLS_REG = property(fget=lambda self: self._read_bf('CHEM_CELLS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register CHEM_CELLS_REG'),
                                         doc=u'''Programmed battery chemistry''')
    icharge_dac = property(fget=lambda self: self._read_bf('icharge_dac'),
                                         fset=lambda self, data: self._error('Write access not allowed to field icharge_dac'),
                                         doc=u'''Indicates the actual charge current setting applied to the charge current digital to analog converter. icharge_dac is ramped up/down to implement digital soft-start/stop. The LTC4162 sets the value of icharge_dac based on charger_state, thermistor_voltage, and charger settings including charge_current_setting, icharge_jeita_2 through icharge_jeita_6, jeita_t1 through jeita_t6 and en_jeita. Recall that the charge current is regulated by controlling the voltage across an external current sense resistor RSNSB. The servo voltage is given by (icharge_dac + 1) × 1mV. The charge current servo level is thus given by (icharge_dac + 1) × 1mV/RSNSB. (5 bits, Read Only)\n\n'''
                                          u'''Format: icharge	Convert from amperes to the charge_current_setting.''')
    ICHARGE_DAC_REG = property(fget=lambda self: self._read_bf('ICHARGE_DAC_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register ICHARGE_DAC_REG'),
                                         doc=u'''''')
    vcharge_dac = property(fget=lambda self: self._read_bf('vcharge_dac'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vcharge_dac'),
                                         doc=u'''This is the actual battery voltage setting applied to the charge voltage digital to analog converter. The LTC4162 sets the value of vcharge_dac based on charger_state, thermistor_voltage, and charger settings including vcharge_setting, vcharge_jeita_2 through vcharge_jeita_6, jeita_t1 through jeita_t6, thermistor_voltage and en_jeita. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max). (5 bits, Read Only)\n\n'''
                                          u'''Format: vcharge_liion	Convert from volts to the vcharge_liion setting.''')
    VCHARGE_DAC_REG = property(fget=lambda self: self._read_bf('VCHARGE_DAC_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register VCHARGE_DAC_REG'),
                                         doc=u'''''')
    iin_limit_dac = property(fget=lambda self: self._read_bf('iin_limit_dac'),
                                         fset=lambda self, data: self._error('Write access not allowed to field iin_limit_dac'),
                                         doc=u'''Indicates the actual input current limit. The iin_limit_dac will follow the value programmed in iin_limit_target. The input current will be regulated to a maximum value given by (iin_limit_dac + 1) × 500µV / RSNSI. (6 bits, Read Only)\n\n'''
                                          u'''Format: iinlim	Convert from amperes to the iinlim setting.''')
    IIN_LIMIT_DAC_REG = property(fget=lambda self: self._read_bf('IIN_LIMIT_DAC_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register IIN_LIMIT_DAC_REG'),
                                         doc=u'''''')
    vbat_filt = property(fget=lambda self: self._read_bf('vbat_filt'),
                                         fset=lambda self, data: self._error('Write access not allowed to field vbat_filt'),
                                         doc=u'''Signed number that is a digitally filtered version of the A/D measurement of vbat. The value is based on the A/D scaling factor for the battery voltage measurement which is cell_count × 192.4µV/LSB at the BATSENS+ pin. (16 bits, Read Only)\n\n'''
                                          u'''Format: vbat_format	Convert from volts to the per-cell vbat ADC reading.''')
    bsr_charge_current = property(fget=lambda self: self._read_bf('bsr_charge_current'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bsr_charge_current'),
                                         doc=u'''Signed number that is the battery charge current that existed during the battery series resistance measurement. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. If the battery series resistance (bsr) test runs with ibat values less than icharge_over_10, the accuracy of the test is questionable due to low signal level and bsr_questionable will set. Rerunning the battery series resistance test earlier in the charge cycle with higher ibat, and therefore higher bsr_charge_current, will give the most accurate result. (16 bits, Read Only)\n\n'''
                                          u'''Preset 'icharge_over_10': 2184\n'''
                                          u'''Format: ibat_format	Convert from amperes to the ibat ADC reading.''')
    bsr_questionable = property(fget=lambda self: self._read_bf('bsr_questionable'),
                                         fset=lambda self, data: self._error('Write access not allowed to field bsr_questionable'),
                                         doc=u'''Indicates that the battery series resistance measurement is questionable due to low signal, specifically that ibat was less than icharge_over_10, when the last battery series resistance (bsr) measurement was taken. bsr_charge_current contains the ibat A/D value present when the battery series resistance measurement was made. (1 bit, Read Only)\n''')
    telemetry_valid = property(fget=lambda self: self._read_bf('telemetry_valid'),
                                         fset=lambda self, data: self._error('Write access not allowed to field telemetry_valid'),
                                         doc=u'''Indicates that the telemetry system autozero amplifiers have had sufficient time, approximately 12ms, to null their offsets. Battery charging is disabled until the telemetry system warm up time has passed. (1 bit, Read Only)\n''')
    TELEMETRY_STATUS_REG = property(fget=lambda self: self._read_bf('TELEMETRY_STATUS_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register TELEMETRY_STATUS_REG'),
                                         doc=u'''Telemetry system status register''')
    input_undervoltage_dac = property(fget=lambda self: self._read_bf('input_undervoltage_dac'),
                                         fset=lambda self, data: self._error('Write access not allowed to field input_undervoltage_dac'),
                                         doc=u'''Input undervoltage regulation digital to analog converter value. The regulation voltage is given by (input_undervoltage_dac + 1) × 140.625mV. If enabled, the MPPT algorithm will directly manipulate this value. Otherwise it will follow input_undervoltage_setting. (8 bits, Read Only)\n\n'''
                                          u'''Format: vin_uvcl	Convert from volts to the vin_uvcl setting.''')
    INPUT_UNDERVOLTAGE_DAC_REG = property(fget=lambda self: self._read_bf('INPUT_UNDERVOLTAGE_DAC_REG'),
                                         fset=lambda self, data: self._error('Write access not allowed to register INPUT_UNDERVOLTAGE_DAC_REG'),
                                         doc=u'''''')

    _constants = {
        'RSNSI': 0.010,
        'RSNSB': 0.010,
        'RNTCBIAS': 10000.0,
        'RNTCSER': 0.0,
        'VINDIV': 30.0,
        'VOUTDIV': (30.0 * 1.00232),
        'BATDIV': 3.5,
        'AVPROG': 37.5,
        'AVCLPROG': 37.5,
        'ADCGAIN': 18191.0,
        'VREF': 1.2,
        'Rm40': 214063.67,
        'Rm34': 152840.30,
        'Rm28': 110480.73,
        'Rm21': 76798.02,
        'Rm14': 54214.99,
        'Rm6': 37075.65,
        'R4': 23649.71,
        'R33': 7400.97,
        'R44': 5001.22,
        'R53': 3693.55,
        'R62': 2768.21,
        'R70': 2167.17,
        'R78': 1714.08,
        'R86': 1368.87,
        'R94': 1103.18,
        'R102': 896.73,
        'R110': 734.86,
        'R118': 606.86,
        'R126': 504.80,
        'R134': 422.81,
        'R142': 356.45,
        'R150': 302.36,
        }

    _xml_formats = {
        'iinlim': {'points': [('0', 'VREF / 64 / AVCLPROG / RSNSI'), ('1', 'VREF / 64 / AVCLPROG / RSNSI * 2')], 'transformed_units': u'A', 'description': u'''Convert from amperes to the iinlim setting.''', 'signed': False},
        'vcharge_liion': {'points': [('0', '3.8125'), ('1', '3.8125 + 0.0125')], 'transformed_units': u'V', 'description': u'''Convert from volts to the vcharge_liion setting.''', 'signed': False},
        'vin_uvcl': {'points': [('0', 'VREF / 256 * VINDIV'), ('1', 'VREF / 256 * VINDIV * 2')], 'transformed_units': u'V', 'description': u'''Convert from volts to the vin_uvcl setting.''', 'signed': False},
        'icharge': {'points': [('0', 'VREF / 32 / AVPROG / RSNSB'), ('1', 'VREF / 32 / AVPROG / RSNSB * 2')], 'transformed_units': u'A', 'description': u'''Convert from amperes to the charge_current_setting.''', 'signed': False},
        'vbat_format': {'points': [('0', '0'), ('1', 'BATDIV / ADCGAIN')], 'transformed_units': u'V', 'description': u'''Convert from volts to the per-cell vbat ADC reading.''', 'signed': True},
        'ibat_format': {'points': [('0', '0'), ('1', '1 / RSNSB / AVPROG / ADCGAIN')], 'transformed_units': u'A', 'description': u'''Convert from amperes to the ibat ADC reading.''', 'signed': True},
        'vout_format': {'points': [('0', '0'), ('1', 'VOUTDIV / ADCGAIN')], 'transformed_units': u'V', 'description': u'''Convert from volts to the vout ADC reading.''', 'signed': True},
        'vin_format': {'points': [('0', '0'), ('1', 'VINDIV / ADCGAIN')], 'transformed_units': u'V', 'description': u'''Convert from volts to the vin ADC reading.''', 'signed': True},
        'iin_format': {'points': [('0', '0'), ('1', '1 / RSNSI / AVCLPROG / ADCGAIN')], 'transformed_units': u'A', 'description': u'''Convert from amperes to the iin ADC reading.''', 'signed': True},
        'bsr_format': {'points': [('0', '0'), ('1', 'RSNSB * AVPROG * BATDIV / 65536')], 'transformed_units': u'Ω', 'description': u'''Convert from Ω to the per-cell bsr ADC reading.''', 'signed': False},
        'die_temp_format': {'points': [('0', '-264.4'), ('1', '-264.4 + 1 / 46.557')], 'transformed_units': u'°C', 'description': u'''Convert from °C to the die_temp ADC reading.''', 'signed': True},
        'NTCS0402E3103FLT': {'points': [('(Rm40 + RNTCSER) / (Rm40 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '-40'), ('(Rm34 + RNTCSER) / (Rm34 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '-34'), ('(Rm28 + RNTCSER) / (Rm28 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '-28'), ('(Rm21 + RNTCSER) / (Rm21 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '-21'), ('(Rm14 + RNTCSER) / (Rm14 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '-14'), ('(Rm6 + RNTCSER) / (Rm6 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '-6'), ('(R4 + RNTCSER) / (R4 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '4'), ('(R33 + RNTCSER) / (R33 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '33'), ('(R44 + RNTCSER) / (R44 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '44'), ('(R53 + RNTCSER) / (R53 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '53'), ('(R62 + RNTCSER) / (R62 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '62'), ('(R70 + RNTCSER) / (R70 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '70'), ('(R78 + RNTCSER) / (R78 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '78'), ('(R86 + RNTCSER) / (R86 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '86'), ('(R94 + RNTCSER) / (R94 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '94'), ('(R102 + RNTCSER) / (R102 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '102'), ('(R110 + RNTCSER) / (R110 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '110'), ('(R118 + RNTCSER) / (R118 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '118'), ('(R126 + RNTCSER) / (R126 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '126'), ('(R134 + RNTCSER) / (R134 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '134'), ('(R142 + RNTCSER) / (R142 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '142'), ('(R150 + RNTCSER) / (R150 + RNTCSER + RNTCBIAS) * ADCGAIN * VREF', '150')], 'transformed_units': u'°C', 'description': u'''Convert from °C to the thermistor ADC reading.''', 'signed': True},
        }

    #Caution! This register map, including active_format settings is shared across all instances of the class.
    _register_map = {
        'vbat_lo_alert_limit': {'command_code':0x01, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vbat_format'], 'active_format':'vbat_format', 'category':'usr_alert_limit'},
        'vbat_hi_alert_limit': {'command_code':0x02, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vbat_format'], 'active_format':'vbat_format', 'category':'usr_alert_limit'},
        'vin_lo_alert_limit': {'command_code':0x03, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vin_format'], 'active_format':'vin_format', 'category':'usr_alert_limit'},
        'vin_hi_alert_limit': {'command_code':0x04, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vin_format'], 'active_format':'vin_format', 'category':'usr_alert_limit'},
        'vout_lo_alert_limit': {'command_code':0x05, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vout_format'], 'active_format':'vout_format', 'category':'usr_alert_limit'},
        'vout_hi_alert_limit': {'command_code':0x06, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vout_format'], 'active_format':'vout_format', 'category':'usr_alert_limit'},
        'iin_hi_alert_limit': {'command_code':0x07, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['iin_format'], 'active_format':'iin_format', 'category':'usr_alert_limit'},
        'ibat_lo_alert_limit': {'command_code':0x08, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['ibat_format'], 'active_format':'ibat_format', 'category':'usr_alert_limit'},
        'die_temp_hi_alert_limit': {'command_code':0x09, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['die_temp_format'], 'active_format':'die_temp_format', 'category':'usr_alert_limit'},
        'bsr_hi_alert_limit': {'command_code':0x0a, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['bsr_format'], 'active_format':'bsr_format', 'category':'usr_alert_limit'},
        'thermistor_voltage_hi_alert_limit': {'command_code':0x0b, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'usr_alert_limit'},
        'thermistor_voltage_lo_alert_limit': {'command_code':0x0c, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'usr_alert_limit'},
        'en_telemetry_valid_alert': {'command_code':0x0d, 'size':1, 'offset':15, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_bsr_done_alert': {'command_code':0x0d, 'size':1, 'offset':14, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_vbat_lo_alert': {'command_code':0x0d, 'size':1, 'offset':11, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_vbat_hi_alert': {'command_code':0x0d, 'size':1, 'offset':10, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_vin_lo_alert': {'command_code':0x0d, 'size':1, 'offset':9, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_vin_hi_alert': {'command_code':0x0d, 'size':1, 'offset':8, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_vout_lo_alert': {'command_code':0x0d, 'size':1, 'offset':7, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_vout_hi_alert': {'command_code':0x0d, 'size':1, 'offset':6, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_iin_hi_alert': {'command_code':0x0d, 'size':1, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_ibat_lo_alert': {'command_code':0x0d, 'size':1, 'offset':4, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_die_temp_hi_alert': {'command_code':0x0d, 'size':1, 'offset':3, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_bsr_hi_alert': {'command_code':0x0d, 'size':1, 'offset':2, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_thermistor_voltage_hi_alert': {'command_code':0x0d, 'size':1, 'offset':1, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'en_thermistor_voltage_lo_alert': {'command_code':0x0d, 'size':1, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_alert_enables'},
        'EN_LIMIT_ALERTS_REG': {'command_code':0x0d, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'en_bat_detect_failed_fault_alert': {'command_code':0x0e, 'size':1, 'offset':12, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_battery_detection_alert': {'command_code':0x0e, 'size':1, 'offset':11, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_charger_suspended_alert': {'command_code':0x0e, 'size':1, 'offset':8, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_precharge_alert': {'command_code':0x0e, 'size':1, 'offset':7, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_cc_cv_charge_alert': {'command_code':0x0e, 'size':1, 'offset':6, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_ntc_pause_alert': {'command_code':0x0e, 'size':1, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_timer_term_alert': {'command_code':0x0e, 'size':1, 'offset':4, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_c_over_x_term_alert': {'command_code':0x0e, 'size':1, 'offset':3, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_max_charge_time_alert': {'command_code':0x0e, 'size':1, 'offset':2, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_bat_missing_fault_alert': {'command_code':0x0e, 'size':1, 'offset':1, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_bat_short_fault_alert': {'command_code':0x0e, 'size':1, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'EN_CHARGER_STATE_ALERTS_REG': {'command_code':0x0e, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'en_ilim_reg_active_alert': {'command_code':0x0f, 'size':1, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_thermal_reg_active_alert': {'command_code':0x0f, 'size':1, 'offset':4, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_vin_uvcl_active_alert': {'command_code':0x0f, 'size':1, 'offset':3, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_iin_limit_active_alert': {'command_code':0x0f, 'size':1, 'offset':2, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_constant_current_alert': {'command_code':0x0f, 'size':1, 'offset':1, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'en_constant_voltage_alert': {'command_code':0x0f, 'size':1, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_alert_enables'},
        'EN_CHARGE_STATUS_ALERTS_REG': {'command_code':0x0f, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'thermal_reg_start_temp': {'command_code':0x10, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['die_temp_format'], 'active_format':'die_temp_format', 'category':'charger_settings'},
        'thermal_reg_end_temp': {'command_code':0x11, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['die_temp_format'], 'active_format':'die_temp_format', 'category':'charger_settings'},
        'suspend_charger': {'command_code':0x14, 'size':1, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'system_settings'},
        'run_bsr': {'command_code':0x14, 'size':1, 'offset':4, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'system_settings'},
        'telemetry_speed': {'command_code':0x14, 'size':1, 'offset':3, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['tel_high_speed',1],['tel_low_speed',0],], 'allowed_formats':[], 'active_format':'None', 'category':'system_settings'},
        'force_telemetry_on': {'command_code':0x14, 'size':1, 'offset':2, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'system_settings'},
        'mppt_en': {'command_code':0x14, 'size':1, 'offset':1, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'system_settings'},
        'CONFIG_BITS_REG': {'command_code':0x14, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'iin_limit_target': {'command_code':0x15, 'size':6, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['iinlim'], 'active_format':'iinlim', 'category':'switcher_settings'},
        'IIN_LIMIT_TARGET_REG': {'command_code':0x15, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'input_undervoltage_setting': {'command_code':0x16, 'size':8, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vin_uvcl'], 'active_format':'vin_uvcl', 'category':'switcher_settings'},
        'INPUT_UNDERVOLTAGE_SETTING_REG': {'command_code':0x16, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'arm_ship_mode': {'command_code':0x19, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['arm',21325],], 'allowed_formats':[], 'active_format':'None', 'category':'system_settings'},
        'charge_current_setting': {'command_code':0x1a, 'size':5, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'charger_settings'},
        'CHARGE_CURRENT_SETTING_REG': {'command_code':0x1a, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'vcharge_setting': {'command_code':0x1b, 'size':5, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['vcharge_lion_default',31],], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'charger_settings'},
        'VCHARGE_SETTING_REG': {'command_code':0x1b, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'c_over_x_threshold': {'command_code':0x1c, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['c_over_10',2184],], 'allowed_formats':['ibat_format'], 'active_format':'ibat_format', 'category':'charger_settings'},
        'max_cv_time': {'command_code':0x1d, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['30mins',1800],['1hour',3600],['2hours',7200],['4hours_default',14400],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_settings'},
        'max_charge_time': {'command_code':0x1e, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['maxchargetime_disable',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_settings'},
        'jeita_t1': {'command_code':0x1f, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'jeita_settings'},
        'jeita_t2': {'command_code':0x20, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'jeita_settings'},
        'jeita_t3': {'command_code':0x21, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'jeita_settings'},
        'jeita_t4': {'command_code':0x22, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'jeita_settings'},
        'jeita_t5': {'command_code':0x23, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'jeita_settings'},
        'jeita_t6': {'command_code':0x24, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'jeita_settings'},
        'vcharge_jeita_6': {'command_code':0x25, 'size':5, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'jeita_settings'},
        'vcharge_jeita_5': {'command_code':0x25, 'size':5, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'jeita_settings'},
        'VCHARGE_JEITA_6_5_REG': {'command_code':0x25, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'vcharge_jeita_4': {'command_code':0x26, 'size':5, 'offset':10, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'jeita_settings'},
        'vcharge_jeita_3': {'command_code':0x26, 'size':5, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'jeita_settings'},
        'vcharge_jeita_2': {'command_code':0x26, 'size':5, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'jeita_settings'},
        'VCHARGE_JEITA_4_3_2_REG': {'command_code':0x26, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'icharge_jeita_6': {'command_code':0x27, 'size':5, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'jeita_settings'},
        'icharge_jeita_5': {'command_code':0x27, 'size':5, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'jeita_settings'},
        'ICHARGE_JEITA_6_5_REG': {'command_code':0x27, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'icharge_jeita_4': {'command_code':0x28, 'size':5, 'offset':10, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'jeita_settings'},
        'icharge_jeita_3': {'command_code':0x28, 'size':5, 'offset':5, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'jeita_settings'},
        'icharge_jeita_2': {'command_code':0x28, 'size':5, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'jeita_settings'},
        'ICHARGE_JEITA_4_3_2_REG': {'command_code':0x28, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'en_c_over_x_term': {'command_code':0x29, 'size':1, 'offset':2, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_settings'},
        'en_jeita': {'command_code':0x29, 'size':1, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_settings'},
        'CHARGER_CONFIG_BITS_REG': {'command_code':0x29, 'size':16, 'offset':0, 'readable':True, 'writable':True, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'tchargetimer': {'command_code':0x30, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'charger_status'},
        'tcvtimer': {'command_code':0x31, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'charger_status'},
        'charger_state': {'command_code':0x34, 'size':13, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['bat_detect_failed_fault',4096],['battery_detection',2048],['charger_suspended',256],['precharge',128],['cc_cv_charge',64],['ntc_pause',32],['timer_term',16],['c_over_x_term',8],['max_charge_time_fault',4],['bat_missing_fault',2],['bat_short_fault',1],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_status'},
        'CHARGER_STATE_REG': {'command_code':0x34, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'charge_status': {'command_code':0x35, 'size':6, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['ilim_reg_active',32],['thermal_reg_active',16],['vin_uvcl_active',8],['iin_limit_active',4],['constant_current',2],['constant_voltage',1],['charger_off',0],], 'allowed_formats':[], 'active_format':'None', 'category':'charger_status'},
        'CHARGE_STATUS_REG': {'command_code':0x35, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'telemetry_valid_alert': {'command_code':0x36, 'size':1, 'offset':15, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'bsr_done_alert': {'command_code':0x36, 'size':1, 'offset':14, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vbat_lo_alert': {'command_code':0x36, 'size':1, 'offset':11, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vbat_hi_alert': {'command_code':0x36, 'size':1, 'offset':10, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vin_lo_alert': {'command_code':0x36, 'size':1, 'offset':9, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vin_hi_alert': {'command_code':0x36, 'size':1, 'offset':8, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vout_lo_alert': {'command_code':0x36, 'size':1, 'offset':7, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vout_hi_alert': {'command_code':0x36, 'size':1, 'offset':6, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'iin_hi_alert': {'command_code':0x36, 'size':1, 'offset':5, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'ibat_lo_alert': {'command_code':0x36, 'size':1, 'offset':4, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'die_temp_hi_alert': {'command_code':0x36, 'size':1, 'offset':3, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'bsr_hi_alert': {'command_code':0x36, 'size':1, 'offset':2, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'thermistor_voltage_hi_alert': {'command_code':0x36, 'size':1, 'offset':1, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'thermistor_voltage_lo_alert': {'command_code':0x36, 'size':1, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'LIMIT_ALERTS_REG': {'command_code':0x36, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'bat_detect_failed_fault_alert': {'command_code':0x37, 'size':1, 'offset':12, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'battery_detection_alert': {'command_code':0x37, 'size':1, 'offset':11, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'charger_suspended_alert': {'command_code':0x37, 'size':1, 'offset':8, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'precharge_alert': {'command_code':0x37, 'size':1, 'offset':7, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'cc_cv_charge_alert': {'command_code':0x37, 'size':1, 'offset':6, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'ntc_pause_alert': {'command_code':0x37, 'size':1, 'offset':5, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'timer_term_alert': {'command_code':0x37, 'size':1, 'offset':4, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'c_over_x_term_alert': {'command_code':0x37, 'size':1, 'offset':3, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'max_charge_time_fault_alert': {'command_code':0x37, 'size':1, 'offset':2, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'bat_missing_fault_alert': {'command_code':0x37, 'size':1, 'offset':1, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'bat_short_fault_alert': {'command_code':0x37, 'size':1, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'CHARGER_STATE_ALERTS_REG': {'command_code':0x37, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'ilim_reg_active_alert': {'command_code':0x38, 'size':1, 'offset':5, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'thermal_reg_active_alert': {'command_code':0x38, 'size':1, 'offset':4, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'vin_uvcl_active_alert': {'command_code':0x38, 'size':1, 'offset':3, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'iin_limit_active_alert': {'command_code':0x38, 'size':1, 'offset':2, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'constant_current_alert': {'command_code':0x38, 'size':1, 'offset':1, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'constant_voltage_alert': {'command_code':0x38, 'size':1, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'alerts'},
        'CHARGE_STATUS_ALERTS_REG': {'command_code':0x38, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'en_chg': {'command_code':0x39, 'size':1, 'offset':8, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'cell_count_err': {'command_code':0x39, 'size':1, 'offset':7, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'no_rt': {'command_code':0x39, 'size':1, 'offset':5, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'thermal_shutdown': {'command_code':0x39, 'size':1, 'offset':4, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'vin_ovlo': {'command_code':0x39, 'size':1, 'offset':3, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'vin_gt_vbat': {'command_code':0x39, 'size':1, 'offset':2, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'vin_gt_4p2v': {'command_code':0x39, 'size':1, 'offset':1, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'intvcc_gt_2p8v': {'command_code':0x39, 'size':1, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'SYSTEM_STATUS_REG': {'command_code':0x39, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'vbat': {'command_code':0x3a, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vbat_format'], 'active_format':'vbat_format', 'category':'usr_status'},
        'vin': {'command_code':0x3b, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vin_format'], 'active_format':'vin_format', 'category':'usr_status'},
        'vout': {'command_code':0x3c, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vout_format'], 'active_format':'vout_format', 'category':'usr_status'},
        'ibat': {'command_code':0x3d, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['ibat_format'], 'active_format':'ibat_format', 'category':'usr_status'},
        'iin': {'command_code':0x3e, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['iin_format'], 'active_format':'iin_format', 'category':'usr_status'},
        'die_temp': {'command_code':0x3f, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['die_temp_format'], 'active_format':'die_temp_format', 'category':'usr_status'},
        'thermistor_voltage': {'command_code':0x40, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['open_thermistor',21684],], 'allowed_formats':['NTCS0402E3103FLT'], 'active_format':'NTCS0402E3103FLT', 'category':'usr_status'},
        'bsr': {'command_code':0x41, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['bsr_format'], 'active_format':'bsr_format', 'category':'usr_status'},
        'jeita_region': {'command_code':0x42, 'size':3, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['R7',7],['R6',6],['R5',5],['R4',4],['R3',3],['R2',2],['R1',1],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'JEITA_REGION_REG': {'command_code':0x42, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'chem': {'command_code':0x43, 'size':4, 'offset':8, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['LTC4162_LAD',0],['LTC4162_L42',1],['LTC4162_L41',2],['LTC4162_L40',3],['LTC4162_FAD',4],['LTC4162_FFS',5],['LTC4162_FST',6],['LTC4162_SST',8],['LTC4162_SAD',9],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'cell_count': {'command_code':0x43, 'size':4, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['Unknown',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'CHEM_CELLS_REG': {'command_code':0x43, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'icharge_dac': {'command_code':0x44, 'size':5, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['icharge'], 'active_format':'icharge', 'category':'usr_status'},
        'ICHARGE_DAC_REG': {'command_code':0x44, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'vcharge_dac': {'command_code':0x45, 'size':5, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vcharge_liion'], 'active_format':'vcharge_liion', 'category':'usr_status'},
        'VCHARGE_DAC_REG': {'command_code':0x45, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'iin_limit_dac': {'command_code':0x46, 'size':6, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['iinlim'], 'active_format':'iinlim', 'category':'usr_status'},
        'IIN_LIMIT_DAC_REG': {'command_code':0x46, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'vbat_filt': {'command_code':0x47, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vbat_format'], 'active_format':'vbat_format', 'category':'usr_status'},
        'bsr_charge_current': {'command_code':0x48, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['icharge_over_10',2184],], 'allowed_formats':['ibat_format'], 'active_format':'ibat_format', 'category':'usr_status'},
        'bsr_questionable': {'command_code':0x4a, 'size':1, 'offset':1, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'telemetry_valid': {'command_code':0x4a, 'size':1, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[['True',1],['False',0],], 'allowed_formats':[], 'active_format':'None', 'category':'usr_status'},
        'TELEMETRY_STATUS_REG': {'command_code':0x4a, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
        'input_undervoltage_dac': {'command_code':0x4b, 'size':8, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':['vin_uvcl'], 'active_format':'vin_uvcl', 'category':'usr_status'},
        'INPUT_UNDERVOLTAGE_DAC_REG': {'command_code':0x4b, 'size':16, 'offset':0, 'readable':True, 'writable':False, 'read_presets_enabled':True, 'presets':[], 'allowed_formats':[], 'active_format':'None', 'category':'whole_register'},
    }

    _formatters = {}

class LTC4162_APIException(Exception):
    '''Bad data passed to instance of LTC4162 will raise LTC4162_APIException'''
    pass

import sqlite3, datetime, time
class logger(object):
    def __init__(self, chip, db_filename="data_log.sqlite"):
        '''Data logger stores memory dump(s) of the LTC4162 to a SQLite database file.
        chip is an instance of the LTC4162 class.
        A new database table will be automatically created with the current timestamp.
        '''
        self.chip = chip
        self.conn = sqlite3.connect(db_filename)
        self.cursor = self.conn.cursor()
        column_names = "rowid INTEGER PRIMARY KEY, datetime DATETIME, "
        for bit_field in sorted(self.chip.keys()):
            column_names += "{},".format(bit_field)
        column_names = column_names[:-1]
        self.q = ("?," * (len(self.chip.keys())+2))[:-1]
        self.table_name = "log_{}".format(datetime.datetime.now().strftime("%Y_%m_%d_%H_%M_%S"))
        self.cursor.execute("CREATE TABLE {} ({});".format(self.table_name, column_names))
    def log(self):
        '''Store single dump of the LTC4162 memory to the database.'''
        mem = [('rowid', None), ('datetime', datetime.datetime.utcnow().strftime('%Y-%m-%dT%H:%M:%S.%fZ'))] + sorted(self.chip.items(),key=lambda (k,v): k)
        keys, values = zip(*mem)
        sql = "INSERT INTO {} {} VALUES ({});".format(self.table_name, str(tuple(keys)), self.q)
        self.cursor.execute(sql,values)
        self.conn.commit()
        return dict(mem)
    def interval_log(self, interval_seconds, max_rows=None):
        '''Repeatedly store dump of the LTC4162 memory to the database.
        Memory will be recorded once per interval_seconds.
        Data will be recorded max_rows times.  If set to None, recording will continue indefinitely.
        '''
        rowcount = 0
        while True:
            begin_time = time.time()
            rowcount += 1
            if max_rows is not None and rowcount > max_rows:
                return
            self.log()
            print("Memory stored to row {} at {}".format(rowcount-1,datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")))
            time.sleep(max(interval_seconds - (time.time()-begin_time),0))

if __name__ == '__main__':
    print('\n\nPlease see the file "example.py"\n\n')

