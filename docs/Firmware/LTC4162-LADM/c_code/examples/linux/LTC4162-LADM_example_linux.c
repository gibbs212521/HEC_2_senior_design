/******************************************************************************
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
******************************************************************************/



/*! @file
 *  @ingroup LTC4162-LADM
 *  @brief Linux I2C Example
 *
 *  This is an example program to demonstrate use of the API with the Linux
 *  kernel userspace i2c-dev driver.
 *  https://i2c.wiki.kernel.org/index.php/I2C_Tools
 *  https://www.kernel.org/doc/Documentation/i2c/dev-interface
 *  https://www.kernel.org/doc/Documentation/i2c/smbus-protocol
 */

#include "LTC4162-LADM.h"

//Note that there are multiple versions of i2c-dev.h.
//See: https://i2c.wiki.kernel.org/index.php/Plans_for_I2C_Tools_4
//Make sure the userspace libi2c-dev package is installed correctly.
#include <linux/i2c-dev.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/file.h>

  /*! Port file descriptor and PEC setting. Passed to read and write functions. */
struct port_configuration
{
  int file_descriptor;       //!< Linux SMBus file handle
  int packet_error_checking; //!< SMBus Packet Error Check hardware enable
};

/*!  read_register  function  wraps read_word_data and places the returned
data  in  *data. It returns 0 for success and a non-zero error code for failure.
The API functions will return this error code in the event of an error.*/
int read_register(uint8_t address,              //!< Target IC's 7-bit SMBus address
                  uint8_t command_code,         //!< Command Code to be read from
                  uint16_t *data,               //!< Pointer to data destination
                  struct port_configuration *pc //!< Pointer to port_configuration
                 )
{
  //Note that Slave address and PEC setup could be moved to main() and executed
  //only once if this program is only communicating with the LTC4162-LADM.
  if (ioctl(pc->file_descriptor, I2C_SLAVE, address) < 0)
  {
    perror("Error setting slave address");
    return errno;
  }
  if (ioctl(pc->file_descriptor, I2C_PEC, pc->packet_error_checking) < 0)
  {
    perror("Error en/dis-abling Packet Error Checking");
    return errno;
  }
  int32_t ret_val = i2c_smbus_read_word_data(pc->file_descriptor, command_code);
  if (ret_val < 0)
  {
    perror("Read error");
    return errno;
  }
  *data = (uint16_t)ret_val;
  return 0;
}

/*!  write_register  function  wraps  write_word_data.  It  returns  0 for
success  and  a  non-zero  error code for failure. The API functions will return
this error code in the event of an error.*/
int write_register(uint8_t address,              //!< Target IC's 7-bit SMBus address
                   uint8_t command_code,         //!< Command Code to be written to
                   uint16_t data,                //!< Data to be written
                   struct port_configuration *pc //!< Pointer to port_configuration struct
                  )
{
  //Note that Slave address and PEC setup could be moved to main() and done only once if this
  //program is only communicating with the LTC4162-LADM.
  if (ioctl(pc->file_descriptor, I2C_SLAVE, address) < 0)
  {
    perror("Error setting slave address");
    return errno;
  }
  if (ioctl(pc->file_descriptor, I2C_PEC, pc->packet_error_checking) < 0)
  {
    perror("Error en/dis-abling Packet Error Checking");
    return errno;
  }
  int32_t ret_val = i2c_smbus_write_word_data(pc->file_descriptor, command_code, data);
  if (ret_val < 0)
  {
    perror("Write error");
    return errno;
  }
  return 0;
}

// Choose the correct i2c bus.  You can find the memory mapping at:
// /sys/bus/i2c/devices/i2c*
// /sys/class/i2c-dev/ 
// or run "i2cdetect -l"
static const char i2c_dev_filename[] = "/dev/i2c-1";

int main(void)
{
  uint16_t data;
  int fd = open(i2c_dev_filename, O_RDWR);
  if (fd < 0)
  {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  // Linux allows multiple programs to open and read or write the i2c device at the same time.
  // Because this may cause surprising behavior, this example code places an advisory
  // lock on the i2c device.
  printf("Attempting to acquire lock on %s ... ", i2c_dev_filename);
  fflush(stdout);
  if (flock(fd, LOCK_EX) < 0)  // Waits until lock is acquired.
  {
    perror(i2c_dev_filename);
    fprintf(stderr, "Error acquiring exclusive advisory file lock\n");
    exit(EXIT_FAILURE);
  }
  printf("DONE!\n");
  //Leave slave address and PEC ioctl setup for read/write function.
  //Could be placed here instead if configuration doesn't change.
  struct port_configuration pc =
  {
    .file_descriptor = fd,
    .packet_error_checking = 1
  };
  unsigned long smbus_funcs;
  if (ioctl(fd, I2C_FUNCS, &smbus_funcs) < 0)
  {
    perror("Error querying I2C hardware capabilities");
    exit(EXIT_FAILURE);
  }
  if (pc.packet_error_checking && !(smbus_funcs & I2C_FUNC_SMBUS_PEC))
  {
    fprintf(stderr, "SMBus Packet Error Checking requested, but hardware doesn't seem to support it.");
    exit(EXIT_FAILURE);
  }
  if (!(smbus_funcs & I2C_FUNC_I2C))
  {
    fprintf(stderr, "SMBus hardware doesn't seem to support I2C at all.");
    exit(EXIT_FAILURE);
  }
  if (!(smbus_funcs & I2C_FUNC_SMBUS_WRITE_WORD_DATA))
  {
    fprintf(stderr, "SMBus hardware doesn't seem to support SMBus write_word protocol.");
    exit(EXIT_FAILURE);
  }
  if (!(smbus_funcs & I2C_FUNC_SMBUS_READ_WORD_DATA))
  {
    fprintf(stderr, "SMBus hardware doesn't seem to support SMBus read_word protocol.");
    exit(EXIT_FAILURE);
  }

  LTC4162_chip_cfg_t LTC4162 =
  {
    .address = LTC4162_ADDR_68,
    .read_register = read_register,
    .write_register = write_register,
    .port_configuration = &pc
  };

  /* the API functions can be used to read and write individual bit fields
  within a command code */
  printf("Using Read Register for the LTC4162_ICHARGE_JEITA_2 bit field\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, &data);
  printf("Read: %d\n",data);

  printf("\nUsing Read/Modify/Write Register for the LTC4162_ICHARGE_JEITA_2 bit field\n");
  LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, 21u);
  printf("Wrote: %d\n",21);
  printf("\nAlternatively, write in Real units\n");
  printf("Wrote: LTC4162_ICHARGE_R2U(2.2)\n");
  LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, LTC4162_ICHARGE_R2U(2.2));

  printf("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_2 bit field\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, &data);
  printf("Read: %d\n",data);
  printf("Formatted Read: %3.2f\n", LTC4162_ICHARGE_U2R(data));

  /* the API functions can also be used to read and write whole command codes */
  printf("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, &data);
  printf("Read: %d\n",data);

  printf("\nUsing Read/Modify/Write Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code\n");
  LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, 56845);
  printf("Wrote: %d\n",56845);

  printf("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, &data);
  printf("Read: %d\n",data);
  printf("Decoding bit field LTC4162_ICHARGE_JEITA_2 from command code data: %d\n", LTC4162_ICHARGE_JEITA_2_DECODE(data));

  printf("\nRe-writing default values for all bit fields (modify LTC4162_bf_config.c to change defaults).\n");
  configure_LTC4162_bf(&LTC4162);

  return EXIT_SUCCESS;
}
