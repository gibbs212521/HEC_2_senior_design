/*!*****************************************************************************
*
* LTC4162: Advanced Synchronous Switching Battery Charger and PowerPath Manager
*
* @verbatim
* The LTC®4162-L is an advanced synchronous switching battery charger and
* PowerPath manager that seamlessly manages power distribution from input
* sources such as wall adapters, backplanes, solar panels, etc. and a
* rechargeable battery. A high resolution telemetry system provides extensive
* information on circuit voltages, currents, battery resistance and temperatures
* which can all be read back over the serial interface. The serial interface can
* also be used to configure many of the charging parameters including
* termination algorithms as well as numerous system status alerts. The LTC4162-L
* can charge Lithium-Ion cell stacks as high as eight cells with up to 3.2A of
* charge current. The power path topology decouples the output voltage from the
* battery allowing a portable product to start up under very low battery voltage
* conditions. The LTC4162-L is available in an I²C adjustable version as well as
* 4.0V, 4.1V and 4.2V fixed voltage versions all with and without MPPT enabled
* by default. The LTC4162-L is available in the 28-pin 4mm × 5mm × 0.75mm QFN
* surface mount package.
* @endverbatim
*
* http://www.linear.com/product/LTC4162
*
* http://www.linear.com/product/LTC4162#demoboards
*
* REVISION HISTORY
* $Revision$
* $Date: 2019-03-06 17:20:19 -0500 (Wed, 06 Mar 2019) $
*
* Copyright (c) 2019 Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification,
* are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL,SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS
* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
* The Linear Technology Linduino is not affiliated with the official Arduino
* team. However, the Linduino is only possible because of the Arduino team's
* commitment to the open-source community. Please, visit http://www.arduino.cc
* and http://store.arduino.cc, and consider a purchase that will help fund
* their ongoing work.
*
* Generated on: 2019-03-06
*
******************************************************************************/


/*! @file
 *  @ingroup LTC4162-LADM
 *  @brief Packet Error Checking CRC-8 Computation
 *
 *  This is an implementation of the 8-bit CRC which can optionally
 *  be used for SMBus Packet Error Checking.
 *
 *  Both bit-wise and byte-wise implementations are included to trade
 *  program storage space against execution speed optimization.
 *
 *  Note that there may be more efficient libraries or hardware available
 *  in many cases that can be used in lieu of this library. For example,
 *  the Linux example uses the kernel driver directly and the Linduino
 *  example makes use of PEC functionality within the LT_SMBus library.
 *  avr-libc provides an optimized _crc8_ccitt_update() from <util/crc16.h>.
 */

#ifndef LTC4162_PEC_H_
#define LTC4162_PEC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

//Uncomment following line to switch from bitwise runtime computation to table lookup.
//#define LTC4162_CRC_TABLE

  /*! Computes CRC-8 using x^8 + X^2 + X + 1 polynomial with most-significant-bit first endianness.
   *  SMBUs computes the PEC over all bytes of the transaction with initialization value 0 and no
   *  pre or post XOR operations.
   *
   *  More efficient execution can be achieved by calling the crc8 function repeatedly from within
   *  the user-supplied, hardware-specific read and write functions rather than using the functions below
   *  with additional stack operations.
   */
  uint8_t crc8(uint8_t data, //!< Byte over which to compute updated CRC.
               uint8_t crc   //!< Previous remainder, or initialization value for first byte. PEC initializes to 0.
              );

  /*! Computes Packet Error Check byte to be sent at end of SMBus write_word transaction. */
  uint8_t pec_write_word(uint8_t address,      //!< 7-bit SMBus slave address
                         uint8_t command_code, //!< SMBus command code (slave memory address)
                         uint16_t data         //!< Data to be written to slave
                        );

  /*! Computes expected Packet Error Check byte from read_word transaction*/
  uint8_t pec_read_word(uint8_t address,      //!< 7-bit SMBus slave address
                        uint8_t command_code, //!< SMBus command code (slave memory address)
                        uint16_t data         //!< Data read from slave
                       );

  /*! Computes Packet Error Check result over completed SMBus read_word transaction.
   *  Returns 0 for no errors.
   */
  uint8_t pec_read_word_test(uint8_t address,      //!< 7-bit SMBus slave address
                             uint8_t command_code, //!< SMBus command code (slave memory address)
                             uint16_t data,        //!< Data read from slave
                             uint8_t pec           //!< Packet error check byte read from slave
                            );

  /*! Computes Packet Error Checking byte to be sent at end of SMBus write_byte transaction. */
  uint8_t pec_write_byte(uint8_t address,      //!< 7-bit SMBus slave address
                         uint8_t command_code, //!< SMBus command code (slave memory address)
                         uint8_t data          //!< Data to be written to slave
                        );

  /*! Computes expected Packet Error Check byte from read_byte transaction*/
  uint8_t pec_read_byte(uint8_t address,      //!< 7-bit SMBus slave address
                        uint8_t command_code, //!< SMBus command code (slave memory address)
                        uint8_t data          //!< Data read from slave
                       );

  /*! Computes Packet Error Checking result over completed SMBus read_byte transaction.
   *  Returns 0 for no errors.
   */
  uint8_t pec_read_byte_test(uint8_t address,      //!< 7-bit SMBus slave address
                             uint8_t command_code, //!< SMBus command code (slave memory address)
                             uint8_t data,         //!< Data read from slave
                             uint8_t pec           //!< Packet error check byte read from slave
                            );

#ifdef __cplusplus
}
#endif
#endif /* LTCLTC4162_PEC_H_ */
