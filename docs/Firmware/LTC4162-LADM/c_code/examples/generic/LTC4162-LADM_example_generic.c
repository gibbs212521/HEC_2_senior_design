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
 *  @brief LTC4162-LADM communication library example
 *
 *  This is an example program to demonstrate use of the API. The
 *  my_write_register and my_read_register functions simply display data and
 *  return constant data to allow compiling and demonstration without hardware.
 */

#include "LTC4162-LADM.h"
#include "LTC4162-LADM_pec.h"
#include <stdio.h>

/*! Example of hardware port configuration. Modify structure contents to match hardware requirements. Passed to read and write functions. */
struct port_configuration
{
  FILE *stream; //!< fprintf stream pointer.
};

/*!
This  is  an  example  of an smbus_read_register function. In a real application
this  function  would  do  an SMBus read_word transaction of slave address
address, and command code command_code, and place the returned data in *data. It
should  return  a  0  for success and a non-zero error code for failure. The API
functions  will  return  this error code in the event of an error. If you do not
need error handling, it should simply always return 0.
*/
int my_read_register(uint8_t address,              //!< Target IC's 7-bit SMBus address
                     uint8_t command_code,         //!< Command Code to be read from
                     uint16_t *data,               //!< Pointer to data destination
                     struct port_configuration *pc //!< Pointer to additional implementation-specific port configuration struct, if required.
                    )
{
  fprintf(pc->stream, "Read word Transaction:\n");
  fprintf(pc->stream, "\tAddress: %d (%#04X)\n",address,address);
  fprintf(pc->stream, "\tCommand_code: %d (%#04X)\n",command_code,command_code);
  *data = rand() % (1u << 16);
  fprintf(pc->stream, "\tRaw read fake data: %d (%#06X)\n",*data,*data);
  fprintf(pc->stream, "\tPEC: %d (%#04X)\n",pec_read_word(address,command_code,*data),pec_read_word(address,command_code,*data));
  return 0;
}

/*!
This  is  an  example of an smbus_write_register function. In a real application
this  function  would  do an SMBus write_word transaction of slave address
address, and command  code command_code, writing data.  It should return a 0 for
success  and  a  non-zero  error code for failure. The API functions will return
this  error code in the event of an error. If you do not need error handling, it
should simply always return 0.
*/
int my_write_register(uint8_t address,              //!< Target IC's 7-bit SMBus address
                      uint8_t command_code,         //!< Command Code to be written to
                      uint16_t data,                //!< Data to be written
                      struct port_configuration *pc //!< Pointer to additional implementation-specific port configuration struct, if required.
                     )
{
  fprintf(pc->stream, "Write word Transaction:\n");
  fprintf(pc->stream, "\tAddress: %d (%#04X)\n",address,address);
  fprintf(pc->stream, "\tCommandCode: %d (%#04X)\n",command_code,command_code);
  fprintf(pc->stream, "\tRaw Data: %d (%#06X)\n",data,data);
  fprintf(pc->stream, "\tPEC: %d (%#04X)\n",pec_write_word(address,command_code,data),pec_write_word(address,command_code,data));
  return 0;
}

int main(void)
{
  uint16_t data;

  struct port_configuration pc =
  {
    .stream = stderr
  };

  LTC4162_chip_cfg_t LTC4162 = 
  {
    .address = LTC4162_ADDR_68,
    .read_register = my_read_register,
    .write_register = my_write_register,
    .port_configuration = &pc
  };

  /*! the API functions can be used to read and write individual bit fields
  within a command code */
  printf("Using Read Register for the LTC4162_ICHARGE_JEITA_2 bit field\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, &data);
  printf("\tRead: %d\n",data);
  printf("\tFormatted Read: %3.2f\n", LTC4162_ICHARGE_U2R(data));

  printf("\nUsing Read/Modify/Write Register for the LTC4162_ICHARGE_JEITA_2 bit field\n");
  LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, 21u);
  printf("\nAlternatively, write in Real units\n");
  LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_2, LTC4162_ICHARGE_R2U(2.2));

  /*! the API functions can also be used to read and write whole command codes */
  printf("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, &data);
  printf("\tRead: %d\n",data);
  
  printf("\nUsing Read/Modify/Write Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code\n");
  LTC4162_write_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, 56845);
  
  printf("\nUsing Read Register for the LTC4162_ICHARGE_JEITA_4_3_2_REG command code\n");
  LTC4162_read_register(&LTC4162, LTC4162_ICHARGE_JEITA_4_3_2_REG, &data);
  printf("\tRead: %d\n",data);
  printf("\tDecoding bit field icharge_jeita_2_bf from command code data: %d\n", LTC4162_ICHARGE_JEITA_2_DECODE(data));

  // Example showing how to modify LTC4162 power-on defaults with an inexpensive µC.
  printf("\nRe-writing default values for all registers (modify LTC4162_reg_config.c to change defaults).\n");
  configure_LTC4162_reg(&LTC4162);
  // Alternatively, write each bit-field individually.
  printf("\nRe-writing default values for all bit fields (uses more program memory; modify LTC4162_bf_config.c to change defaults).\n");
  configure_LTC4162_bf(&LTC4162);

  return EXIT_SUCCESS;
}
