/*!*****************************************************************************
*
* LTC4162: Advanced Synchronous Switching Battery Charger and PowerPath Manager
*
* @verbatim
The LTC®4162-L is an advanced synchronous switching battery charger and
PowerPath manager that seamlessly manages power distribution from input sources
such as wall adapters, backplanes, solar panels, etc. and a rechargeable
battery. A high resolution telemetry system provides extensive information on
circuit voltages, currents, battery resistance and temperatures which can all be
read back over the serial interface. The serial interface can also be used to
configure many of the charging parameters including termination algorithms as
well as numerous system status alerts. The LTC4162-L can charge Lithium-Ion cell
stacks as high as eight cells with up to 3.2A of charge current. The power path
topology decouples the output voltage from the battery allowing a portable
product to start up under very low battery voltage conditions. The LTC4162-L is
available in an I²C adjustable version as well as 4.0V, 4.1V and 4.2V fixed
voltage versions all with and without MPPT enabled by default. The LTC4162-L is
available in the 28-pin 4mm × 5mm × 0.75mm QFN surface mount package.
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
 *  @brief Bit-field aligned modifier of power-on defaults
 *
 *  This is an example program to demonstrate use of the API by
 *  writing each writable bit-field in the LTC4162 back to its
 *  power-on default. The file can be changed easily to modify the LTC4162
 *  default behavior. This bit-field aligned configurator is somewhat simpler than
 *  the similar register based configurator, at the expense of program memory and 
 *  execution time.
 */

#include "LTC4162-LADM.h"

void configure_LTC4162_bf(LTC4162_chip_cfg_t *chip)
{
  LTC4162_write_register(chip, LTC4162_VBAT_LO_ALERT_LIMIT, (uint16_t)LTC4162_VBAT_FORMAT_R2I(0.0)); //Convert from volts to the per-cell vbat ADC reading. MIN:-6.30465614864, MAX:6.30446374581.
  //LTC4162_write_register(chip, LTC4162_VBAT_LO_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_VBAT_HI_ALERT_LIMIT, (uint16_t)LTC4162_VBAT_FORMAT_R2I(0.0)); //Convert from volts to the per-cell vbat ADC reading. MIN:-6.30465614864, MAX:6.30446374581.
  //LTC4162_write_register(chip, LTC4162_VBAT_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_VIN_LO_ALERT_LIMIT, (uint16_t)LTC4162_VIN_FORMAT_R2I(0.0)); //Convert from volts to the vin ADC reading. MIN:-54.0399098455, MAX:54.0382606784.
  //LTC4162_write_register(chip, LTC4162_VIN_LO_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_VIN_HI_ALERT_LIMIT, (uint16_t)LTC4162_VIN_FORMAT_R2I(0.0)); //Convert from volts to the vin ADC reading. MIN:-54.0399098455, MAX:54.0382606784.
  //LTC4162_write_register(chip, LTC4162_VIN_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_VOUT_LO_ALERT_LIMIT, (uint16_t)LTC4162_VOUT_FORMAT_R2I(0.0)); //Convert from volts to the vout ADC reading. MIN:-54.1652824364, MAX:54.1636294431.
  //LTC4162_write_register(chip, LTC4162_VOUT_LO_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_VOUT_HI_ALERT_LIMIT, (uint16_t)LTC4162_VOUT_FORMAT_R2I(0.0)); //Convert from volts to the vout ADC reading. MIN:-54.1652824364, MAX:54.1636294431.
  //LTC4162_write_register(chip, LTC4162_VOUT_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_IIN_HI_ALERT_LIMIT, (uint16_t)LTC4162_IIN_FORMAT_R2I(0.0)); //Convert from amperes to the iin ADC reading. MIN:-4.80354754182, MAX:4.80340094919.
  //LTC4162_write_register(chip, LTC4162_IIN_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_IBAT_LO_ALERT_LIMIT, (uint16_t)LTC4162_IBAT_FORMAT_R2I(0.0)); //Convert from amperes to the ibat ADC reading. MIN:-4.80354754182, MAX:4.80340094919.
  //LTC4162_write_register(chip, LTC4162_IBAT_LO_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_DIE_TEMP_HI_ALERT_LIMIT, (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I(-264.4)); //Convert from °C to the die_temp ADC reading. MIN:-968.225418305, MAX:439.403939257.
  //LTC4162_write_register(chip, LTC4162_DIE_TEMP_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_BSR_HI_ALERT_LIMIT, LTC4162_BSR_FORMAT_R2U(0.0)); //Convert from Ω to the per-cell bsr ADC reading. MIN:0.0, MAX:1.31247997284.
  //LTC4162_write_register(chip, LTC4162_BSR_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(196.313569562)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(196.313569562)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_EN_TELEMETRY_VALID_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_BSR_DONE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VBAT_LO_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VBAT_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VIN_LO_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VIN_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VOUT_LO_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VOUT_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_IIN_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_IBAT_LO_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_DIE_TEMP_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_BSR_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_BATTERY_DETECTION_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_CHARGER_SUSPENDED_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_PRECHARGE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_CC_CV_CHARGE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_NTC_PAUSE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_TIMER_TERM_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_C_OVER_X_TERM_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_MAX_CHARGE_TIME_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_BAT_MISSING_FAULT_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_BAT_SHORT_FAULT_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_ILIM_REG_ACTIVE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_THERMAL_REG_ACTIVE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_VIN_UVCL_ACTIVE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_CONSTANT_CURRENT_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_CONSTANT_VOLTAGE_ALERT, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_THERMAL_REG_START_TEMP, (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I(120.01050755)); //Convert from °C to the die_temp ADC reading. MIN:-968.225418305, MAX:439.403939257.
  //LTC4162_write_register(chip, LTC4162_THERMAL_REG_START_TEMP, 17897u); //Max 65535

  LTC4162_write_register(chip, LTC4162_THERMAL_REG_END_TEMP, (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I(125.015125545)); //Convert from °C to the die_temp ADC reading. MIN:-968.225418305, MAX:439.403939257.
  //LTC4162_write_register(chip, LTC4162_THERMAL_REG_END_TEMP, 18130u); //Max 65535

  LTC4162_write_register(chip, LTC4162_SUSPEND_CHARGER, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_RUN_BSR, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_TELEMETRY_SPEED, LTC4162_TELEMETRY_SPEED_ENUM_TEL_LOW_SPEED);
  //LTC4162_write_register(chip, LTC4162_TELEMETRY_SPEED, LTC4162_TELEMETRY_SPEED_ENUM_TEL_HIGH_SPEED);
  //LTC4162_write_register(chip, LTC4162_TELEMETRY_SPEED, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_FORCE_TELEMETRY_ON, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_MPPT_EN, 1u); //Max 1

  LTC4162_write_register(chip, LTC4162_IIN_LIMIT_TARGET, LTC4162_IINLIM_R2U(3.2)); //Convert from amperes to the iinlim setting. MIN:0.05, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_IIN_LIMIT_TARGET, 63u); //Max 63

  LTC4162_write_register(chip, LTC4162_INPUT_UNDERVOLTAGE_SETTING, LTC4162_VIN_UVCL_R2U(4.5)); //Convert from volts to the vin_uvcl setting. MIN:0.140625, MAX:36.0.
  //LTC4162_write_register(chip, LTC4162_INPUT_UNDERVOLTAGE_SETTING, 31u); //Max 255

  //LTC4162_write_register(chip, LTC4162_ARM_SHIP_MODE, LTC4162_ARM_SHIP_MODE_ENUM_ARM);
  LTC4162_write_register(chip, LTC4162_ARM_SHIP_MODE, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_CHARGE_CURRENT_SETTING, LTC4162_ICHARGE_R2U(3.2)); //Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_CHARGE_CURRENT_SETTING, 31u); //Max 31

  LTC4162_write_register(chip, LTC4162_VCHARGE_SETTING, LTC4162_VCHARGE_SETTING_ENUM_VCHARGE_LION_DEFAULT);
  //LTC4162_write_register(chip, LTC4162_VCHARGE_SETTING, LTC4162_VCHARGE_LIION_R2U(4.2)); //Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //LTC4162_write_register(chip, LTC4162_VCHARGE_SETTING, 31u); //Max 31

  LTC4162_write_register(chip, LTC4162_C_OVER_X_THRESHOLD, LTC4162_C_OVER_X_THRESHOLD_ENUM_C_OVER_10);
  //LTC4162_write_register(chip, LTC4162_C_OVER_X_THRESHOLD, (uint16_t)LTC4162_IBAT_FORMAT_R2I(0.320158320048)); //Convert from amperes to the ibat ADC reading. MIN:-4.80354754182, MAX:4.80340094919.
  //LTC4162_write_register(chip, LTC4162_C_OVER_X_THRESHOLD, 2184u); //Max 65535

  //LTC4162_write_register(chip, LTC4162_MAX_CV_TIME, LTC4162_MAX_CV_TIME_ENUM_30MINS);
  //LTC4162_write_register(chip, LTC4162_MAX_CV_TIME, LTC4162_MAX_CV_TIME_ENUM_1HOUR);
  //LTC4162_write_register(chip, LTC4162_MAX_CV_TIME, LTC4162_MAX_CV_TIME_ENUM_2HOURS);
  LTC4162_write_register(chip, LTC4162_MAX_CV_TIME, LTC4162_MAX_CV_TIME_ENUM_4HOURS_DEFAULT);
  //LTC4162_write_register(chip, LTC4162_MAX_CV_TIME, 14400u); //Max 65535

  LTC4162_write_register(chip, LTC4162_MAX_CHARGE_TIME, LTC4162_MAX_CHARGE_TIME_ENUM_MAXCHARGETIME_DISABLE);
  //LTC4162_write_register(chip, LTC4162_MAX_CHARGE_TIME, 0u); //Max 65535

  LTC4162_write_register(chip, LTC4162_JEITA_T1, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(-0.188805466836)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_JEITA_T1, 16117u); //Max 65535

  LTC4162_write_register(chip, LTC4162_JEITA_T2, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(9.88371113339)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_JEITA_T2, 14113u); //Max 65535

  LTC4162_write_register(chip, LTC4162_JEITA_T3, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(40.2046110219)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_JEITA_T3, 7970u); //Max 65535

  LTC4162_write_register(chip, LTC4162_JEITA_T4, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(45.0724234503)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_JEITA_T4, 7112u); //Max 65535

  LTC4162_write_register(chip, LTC4162_JEITA_T5, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(50.1695321291)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_JEITA_T5, 6325u); //Max 65535

  LTC4162_write_register(chip, LTC4162_JEITA_T6, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(60.1512004158)); //Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  //LTC4162_write_register(chip, LTC4162_JEITA_T6, 4970u); //Max 65535

  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_6, LTC4162_VCHARGE_LIION_R2U(4.05)); //Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_6, 19u); //Max 31

  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_5, LTC4162_VCHARGE_LIION_R2U(4.1)); //Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_5, 23u); //Max 31

  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_4, LTC4162_VCHARGE_LIION_R2U(4.1)); //Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_4, 23u); //Max 31

  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_3, LTC4162_VCHARGE_LIION_R2U(4.2)); //Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_3, 31u); //Max 31

  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_2, LTC4162_VCHARGE_LIION_R2U(4.2)); //Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_2, 31u); //Max 31

  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_6, LTC4162_ICHARGE_R2U(1.6)); //Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_6, 15u); //Max 31

  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_5, LTC4162_ICHARGE_R2U(1.6)); //Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_5, 15u); //Max 31

  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_4, LTC4162_ICHARGE_R2U(3.2)); //Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_4, 31u); //Max 31

  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_3, LTC4162_ICHARGE_R2U(3.2)); //Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_3, 31u); //Max 31

  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_2, LTC4162_ICHARGE_R2U(1.6)); //Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_2, 15u); //Max 31

  LTC4162_write_register(chip, LTC4162_EN_C_OVER_X_TERM, 0u); //Max 1

  LTC4162_write_register(chip, LTC4162_EN_JEITA, 1u); //Max 1

}
