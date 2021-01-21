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
 */

#include "LTC4162-LADM_pec.h"

#ifndef LTC4162_CRC_TABLE

uint8_t crc8(uint8_t data, uint8_t crc)
{
  uint8_t i;
  crc = crc ^ data;
  for (i = 0; i < 8; i++)
  {
    if (crc & 0x80) crc = (crc << 1) ^  0x07;
    else crc = crc << 1;
  }
  return crc;
}

#else

static const uint8_t crc8_table[256] =
{
  0000, 0X07, 0X0E, 0X09, 0X1C, 0X1B, 0X12, 0X15,
  0X38, 0X3F, 0X36, 0X31, 0X24, 0X23, 0X2A, 0X2D,
  0X70, 0X77, 0X7E, 0X79, 0X6C, 0X6B, 0X62, 0X65,
  0X48, 0X4F, 0X46, 0X41, 0X54, 0X53, 0X5A, 0X5D,
  0XE0, 0XE7, 0XEE, 0XE9, 0XFC, 0XFB, 0XF2, 0XF5,
  0XD8, 0XDF, 0XD6, 0XD1, 0XC4, 0XC3, 0XCA, 0XCD,
  0X90, 0X97, 0X9E, 0X99, 0X8C, 0X8B, 0X82, 0X85,
  0XA8, 0XAF, 0XA6, 0XA1, 0XB4, 0XB3, 0XBA, 0XBD,
  0XC7, 0XC0, 0XC9, 0XCE, 0XDB, 0XDC, 0XD5, 0XD2,
  0XFF, 0XF8, 0XF1, 0XF6, 0XE3, 0XE4, 0XED, 0XEA,
  0XB7, 0XB0, 0XB9, 0XBE, 0XAB, 0XAC, 0XA5, 0XA2,
  0X8F, 0X88, 0X81, 0X86, 0X93, 0X94, 0X9D, 0X9A,
  0X27, 0X20, 0X29, 0X2E, 0X3B, 0X3C, 0X35, 0X32,
  0X1F, 0X18, 0X11, 0X16, 0X03, 0X04, 0X0D, 0X0A,
  0X57, 0X50, 0X59, 0X5E, 0X4B, 0X4C, 0X45, 0X42,
  0X6F, 0X68, 0X61, 0X66, 0X73, 0X74, 0X7D, 0X7A,
  0X89, 0X8E, 0X87, 0X80, 0X95, 0X92, 0X9B, 0X9C,
  0XB1, 0XB6, 0XBF, 0XB8, 0XAD, 0XAA, 0XA3, 0XA4,
  0XF9, 0XFE, 0XF7, 0XF0, 0XE5, 0XE2, 0XEB, 0XEC,
  0XC1, 0XC6, 0XCF, 0XC8, 0XDD, 0XDA, 0XD3, 0XD4,
  0X69, 0X6E, 0X67, 0X60, 0X75, 0X72, 0X7B, 0X7C,
  0X51, 0X56, 0X5F, 0X58, 0X4D, 0X4A, 0X43, 0X44,
  0X19, 0X1E, 0X17, 0X10, 0X05, 0X02, 0X0B, 0X0C,
  0X21, 0X26, 0X2F, 0X28, 0X3D, 0X3A, 0X33, 0X34,
  0X4E, 0X49, 0X40, 0X47, 0X52, 0X55, 0X5C, 0X5B,
  0X76, 0X71, 0X78, 0X7F, 0X6A, 0X6D, 0X64, 0X63,
  0X3E, 0X39, 0X30, 0X37, 0X22, 0X25, 0X2C, 0X2B,
  0X06, 0X01, 0X08, 0X0F, 0X1A, 0X1D, 0X14, 0X13,
  0XAE, 0XA9, 0XA0, 0XA7, 0XB2, 0XB5, 0XBC, 0XBB,
  0X96, 0X91, 0X98, 0X9F, 0X8A, 0X8D, 0X84, 0X83,
  0XDE, 0XD9, 0XD0, 0XD7, 0XC2, 0XC5, 0XCC, 0XCB,
  0XE6, 0XE1, 0XE8, 0XEF, 0XFA, 0XFD, 0XF4, 0XF3
};

#define crc8(data,crc) (crc8_table[(data) ^ (crc)])
/*
uint8_t crc8(uint8_t data, uint8_t crc)
{
  return crc8_table[data ^ crc];
}
*/

#endif //LTC4162_CRC_TABLE

uint8_t pec_write_word(uint8_t address, uint8_t command_code, uint16_t data)
{
  uint8_t remainder;
  remainder = crc8(address << 1, 0);
  remainder = crc8(command_code, remainder);
  remainder = crc8(data & 0xFF, remainder);
  remainder = crc8((data >> 8) & 0xFF, remainder);
  return remainder; //Returns final byte to be sent to slave device before Stop condition.
}

uint8_t pec_read_word(uint8_t address, uint8_t command_code, uint16_t data)
{
  uint8_t remainder;
  remainder = crc8(address << 1, 0);
  remainder = crc8(command_code, remainder);
  remainder = crc8((address << 1) | 1, 0);
  remainder = crc8(data & 0xFF, remainder);
  remainder = crc8((data >> 8) & 0xFF, remainder);
  return remainder; //Returns expected PEC byte to be received from slave device before Stop condition.
}

uint8_t pec_read_word_test(uint8_t address, uint8_t command_code, uint16_t data, uint8_t pec)
{
  uint8_t remainder;
  remainder = pec_read_word(address, command_code, data);
  //return (remainder == pec); //Alternative implementation
  remainder = crc8(pec, remainder);
  return remainder; //Returns 0 for no errors.
}

uint8_t pec_write_byte(uint8_t address, uint8_t command_code, uint8_t data)
{
  uint8_t remainder;
  remainder = crc8(address << 1, 0);
  remainder = crc8(command_code, remainder);
  remainder = crc8(data, remainder);
  return remainder; //Returns final byte to be sent to slave device before Stop condition.
}

uint8_t pec_read_byte(uint8_t address, uint8_t command_code, uint8_t data)
{
  uint8_t remainder;
  remainder = crc8(address << 1, 0);
  remainder = crc8(command_code, remainder);
  remainder = crc8((address << 1) | 1, 0);
  remainder = crc8(data, remainder);
  return remainder; //Returns expected PEC byte to be received from slave device before Stop condition.
}

uint8_t pec_read_byte_test(uint8_t address, uint8_t command_code, uint8_t data, uint8_t pec)
{
  uint8_t remainder;
  remainder = pec_read_byte(address, command_code, data);
  //return (remainder == pec); //Alternative implementation
  remainder = crc8(pec, remainder);
  return remainder; //Returns 0 for no errors.
}
