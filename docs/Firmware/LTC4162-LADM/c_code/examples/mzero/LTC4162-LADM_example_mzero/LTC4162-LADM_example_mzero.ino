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
 *  @brief Arduino Example
 *
 *  This is an example sketch to demonstrate use of the API with the Linduino.
 *  In addition to the sketch, the following files are required:
 *    LTC4162-LADM.c
 *    LTC4162-LADM.h
 *    LTC4162-LADM_formats.h
 *    LTC4162-LADM_reg_defs.h
 */

#include "LTC4162-LADM.h"
#include <Arduino.h>

#include "Comm_SMBus.h"

LTC4162_chip_cfg_t LTC4162 =
{
  LTC4162_ADDR_68, //.address (7-bit)
  Comm_Smbus_Reg16_Read_PEC,   //.read_register
  Comm_Smbus_Reg16_Write_PEC,  //.write_register
  NULL                         //.port_configuration not used
};

uint16_t data;

void setup()
{
  SerialUSB.begin(115200);  //! Initialize the serial port to the PC
  while (!SerialUSB);       //! Wait for serial port to be opened in the case of Leonardo USB Serial
  SerialUSB.println("Press any key to demo reading and writing to the LTC4162-LADM.");
}

void loop()
{
  if (SerialUSB.available() < 1) {
    return;           // Don't do anything unless we've gotten bytes over the serial port.
  } else {
    while (SerialUSB.available() > 0) {
      SerialUSB.read();  // Throw away any bytes we received over the (USB) serial port.
    }
    /* the API functions can be used to read and write individual bit fields
    within a command code */
    SerialUSB.println(F("Using Read Register for the LTC4162_ICHARGE_JEITA_2 bit field"));
    int errcode = LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, &data);
    const char errmsg[] = ">>> Got I2C ERROR. Is the chip powered?";
    if (errcode) { SerialUSB.println(errmsg); return; }
    SerialUSB.print(F("Read: "));
    SerialUSB.println(data);

    SerialUSB.println(F("\nUsing Read/Modify/Write Register for the LTC4162_ICHARGE_JEITA_2 bit field"));
    errcode = LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, 21u);
    if (errcode) { SerialUSB.println(errmsg); return; }
    SerialUSB.print(F("Wrote: "));
    SerialUSB.println(21);
    SerialUSB.println(F("Alternatively, write in Real units:"));
    SerialUSB.println(F("Wrote: LTC4162_ICHARGE_R2U(2.2)"));
    LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, LTC4162_ICHARGE_R2U(2.2));

    SerialUSB.println(F("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_2 bit field"));
    errcode = LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, &data);
    if (errcode) { SerialUSB.println(errmsg); return; }
    SerialUSB.print(F("Read: "));
    SerialUSB.println(data);
    SerialUSB.print(F("Formatted Read: "));
    SerialUSB.println(LTC4162_ICHARGE_U2R(data));

    /* the API functions can also be used to read and write whole command codes */
    SerialUSB.println(F("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code"));
    errcode = LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, &data);
    if (errcode) { SerialUSB.println(errmsg); return; }
    SerialUSB.print(F("Read: "));
    SerialUSB.println(data);

    SerialUSB.println(F("\nUsing Read/Modify/Write Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code"));
    errcode = LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, 56845);
    if (errcode) { SerialUSB.println(errmsg); return; }
    SerialUSB.print(F("Wrote: "));
    SerialUSB.println(56845);

    SerialUSB.println(F("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code"));
    errcode = LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, &data);
    if (errcode) { SerialUSB.println(errmsg); return; }
    SerialUSB.print(F("Read: "));
    SerialUSB.println(data);
    SerialUSB.print(F("Decoding bit field LTC4162_ICHARGE_JEITA_2 from command code data:"));
    SerialUSB.println(LTC4162_ICHARGE_JEITA_2_DECODE(data));
  }
}
