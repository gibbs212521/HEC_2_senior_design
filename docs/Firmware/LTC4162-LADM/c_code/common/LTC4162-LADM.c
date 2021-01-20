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


//! @defgroup LTC4162-LADM LTC4162: Advanced Synchronous Switching Battery Charger and PowerPath Manager

/*! @file
 *  @ingroup LTC4162-LADM
 *  @brief LTC4162-LADM lightweight, hardware agnostic, embeddable C Communication
 *  Library.
 *
 * Communication  is  bit-field based as well as whole-register based. This library
 * automatically masks and right-justifies bit fields.
 *
 * This C library provides a header file with the complete definitions of registers
 * and  bit  fields  within  those  registers, and routines to read and write those
 * registers and individual bit-fields.
 *
 * Outside  of  the  Linduino  environment,  this  library  can  be  built with any
 * standard  C  compiler  and  can  be  used with different I2C/SMBus communication
 * hardware  simply  by  swapping  out  the  pointers  to appropriate user-supplied
 * functions   *@ref   smbus_write_register   and   *@ref  smbus_read_register.  An
 * example  is  provided  using  the  i2c-tools  Linux kernel driver which has been
 * tested  on  the  BeagleBone  Black  Linux  single board computer. It can also be
 * readily  adapted  to  common  microcontrollers  with  minimal  memory  impact on
 * embedded systems.
 *
 * A higher level hardware agnostic Python communication library is also available.
 *
 * Please   visit   http://www.linear.com/product/LTC4162#code  or  contact  the
 * factory at 408-432-1900 or www.linear.com for further information.
 */

#include "LTC4162-LADM.h"

static inline uint8_t get_size(uint16_t registerinfo)
{
  return ((registerinfo >> 8) & 0x0F) + 1;
}
static inline uint8_t get_command_code(uint16_t registerinfo)
{
  return (registerinfo) & 0xFF;
}
static inline uint8_t get_offset(uint16_t registerinfo)
{
  return (registerinfo >> 12) & 0x0F;
}
static inline uint16_t get_mask(uint16_t registerinfo)
{
  uint8_t size = get_size(registerinfo);
  if (size == LTC4162_WORD_SIZE)
  {
    return UINT16_MAX;
  }
  return (uint16_t)(((1u << size) - 1) << get_offset(registerinfo));
}

int LTC4162_write_register(LTC4162_chip_cfg_t *chip, uint16_t registerinfo, uint16_t data)
{
  int ret_val;
  uint8_t command_code = get_command_code(registerinfo);
  /* It may be a good idea to acquire or assert some kind of
     exclusive lock on the i2c hardware here. How to do this
     is VERY dependent on your specific hardware.

     Linux, for example, allows multiple programs
     to open and read or write the i2c device at the same time.
     This may cause surprising behavior like "lost writes"
     when multiple processes concurrently attempt
     read-modify-writes of distinct bitfields
     residing in the same register.

     In Linux, one way to avoid this is to use flock(2), which
     blocks until an exclusive lock is acquired.

     if (flock(pc->file_descriptor, LOCK_EX) < 0)
     {
       perror("Error acquiring exclusive advisory file lock");
       ret_val = errno;
       goto RETURN;
     }
  */
  if (get_size(registerinfo) != LTC4162_WORD_SIZE)
  {
    uint8_t offset = get_offset(registerinfo);
    uint16_t mask = get_mask(registerinfo);
    uint16_t read_data;
    ret_val = chip->read_register(chip->address,command_code,&read_data,chip->port_configuration);
    if (ret_val) goto RETURN;
    assert(data < 1u << get_size(registerinfo)); // Disable runtime overflow checking by defining NDEBUG macro or setting -DNDEBUG CFLAGS option.
    data = (read_data & ~mask) | (data << offset);
  }
  ret_val = chip->write_register(chip->address,command_code,data,chip->port_configuration);
  RETURN:
  /* If you added code to lock the i2c hardware at the beginning
     of this function, this is a good place to release that lock.

     In the case of using flock(2) in Linux, we'd do either:

       flock(pc->file_descriptor, LOCK_UN); // Completely unlock i2c device.

       // or

       flock(pc->file_descriptor, LOCK_SH); // Revert i2c lock to Shared.

  */
  return ret_val;
}

int LTC4162_read_register(LTC4162_chip_cfg_t *chip, uint16_t registerinfo, uint16_t *data)
{
  int failure = chip->read_register(chip->address,get_command_code(registerinfo),data,chip->port_configuration);
  if (get_size(registerinfo) == LTC4162_WORD_SIZE) return failure;
  *data &= get_mask(registerinfo);
  *data = *data >> get_offset(registerinfo);
  return failure;
}
