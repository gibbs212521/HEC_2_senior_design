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
 *  @brief Register aligned modifier of power-on defaults
 *
 *  This is an example program to demonstrate use of the API by
 *  writing each writable register in the LTC4162 back to its
 *  power-on default. The file can be changed easily to modify the LTC4162
 *  default behavior. This register aligned configurator is somewhat more economical
 *  of program memory and execution time than the similar bit-field
 *  aligned configurator at the expense of readability.
 */

#include "LTC4162-LADM.h"

void configure_LTC4162_reg(LTC4162_chip_cfg_t *chip)
{
  //VBAT_LO_ALERT_LIMIT_REG
  //  vbat_lo_alert_limit: Signed number that sets a lower limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_lo_alert and can be read back and cleared at vbat_lo_alert.
  //    LTC4162_VBAT_LO_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_VBAT_FORMAT_R2I: Convert from volts to the per-cell vbat ADC reading. MIN:-6.30465614864, MAX:6.30446374581.
  LTC4162_write_register(chip, LTC4162_VBAT_LO_ALERT_LIMIT_REG, (uint16_t)LTC4162_VBAT_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //VBAT_HI_ALERT_LIMIT_REG
  //  vbat_hi_alert_limit: Signed number that sets an upper limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_hi_alert and can be read back and cleared at vbat_hi_alert.
  //    LTC4162_VBAT_HI_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_VBAT_FORMAT_R2I: Convert from volts to the per-cell vbat ADC reading. MIN:-6.30465614864, MAX:6.30446374581.
  LTC4162_write_register(chip, LTC4162_VBAT_HI_ALERT_LIMIT_REG, (uint16_t)LTC4162_VBAT_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //VIN_LO_ALERT_LIMIT_REG
  //  vin_lo_alert_limit: Signed number that sets a lower limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_lo_alert and can be read back and cleared at vin_lo_alert.
  //    LTC4162_VIN_LO_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_VIN_FORMAT_R2I: Convert from volts to the vin ADC reading. MIN:-54.0399098455, MAX:54.0382606784.
  LTC4162_write_register(chip, LTC4162_VIN_LO_ALERT_LIMIT_REG, (uint16_t)LTC4162_VIN_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //VIN_HI_ALERT_LIMIT_REG
  //  vin_hi_alert_limit: Signed number that sets an upper limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_hi_alert and can be read back and cleared at vin_hi_alert.
  //    LTC4162_VIN_HI_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_VIN_FORMAT_R2I: Convert from volts to the vin ADC reading. MIN:-54.0399098455, MAX:54.0382606784.
  LTC4162_write_register(chip, LTC4162_VIN_HI_ALERT_LIMIT_REG, (uint16_t)LTC4162_VIN_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //VOUT_LO_ALERT_LIMIT_REG
  //  vout_lo_alert_limit: Signed number that sets a lower limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_lo_alert and can be read back and cleared at vout_lo_alert.
  //    LTC4162_VOUT_LO_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_VOUT_FORMAT_R2I: Convert from volts to the vout ADC reading. MIN:-54.1652824364, MAX:54.1636294431.
  LTC4162_write_register(chip, LTC4162_VOUT_LO_ALERT_LIMIT_REG, (uint16_t)LTC4162_VOUT_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //VOUT_HI_ALERT_LIMIT_REG
  //  vout_hi_alert_limit: Signed number that sets an upper limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_hi_alert and can be read back and cleared at vout_hi_alert.
  //    LTC4162_VOUT_HI_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_VOUT_FORMAT_R2I: Convert from volts to the vout ADC reading. MIN:-54.1652824364, MAX:54.1636294431.
  LTC4162_write_register(chip, LTC4162_VOUT_HI_ALERT_LIMIT_REG, (uint16_t)LTC4162_VOUT_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //IIN_HI_ALERT_LIMIT_REG
  //  iin_hi_alert_limit: Signed number that sets an upper limit that can be used to trigger an interrupt based on input current out of range. The value is based on the A/D value, iin, which has a scaling factor of 1.466µV / RSNSI amperes/LSB. The alert is enabled by setting en_iin_hi_alert and can be read back and cleared at iin_hi_alert.
  //    LTC4162_IIN_HI_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_IIN_FORMAT_R2I: Convert from amperes to the iin ADC reading. MIN:-4.80354754182, MAX:4.80340094919.
  LTC4162_write_register(chip, LTC4162_IIN_HI_ALERT_LIMIT_REG, (uint16_t)LTC4162_IIN_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //IBAT_LO_ALERT_LIMIT_REG
  //  ibat_lo_alert_limit: Signed number that sets a lower limit that can be used to trigger an interrupt based on charge current dropping below a particular value, such as during the constant-voltage phase of charging, or, load current exceeding a particular limit when not charging. When the charger is not running, and telemetry is enabled with force_telemetry_on, this limit indicates that the battery draw has exceeded a particular value. Telemetry will be enabled automatically if the input voltage exceeds the battery voltage, in which case discharge current will be nearly zero. ibat values are positive for charging and negative for discharging so the polarity of this register should be set according to the mode in which the limit alert is of interest. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. The alert is enabled by setting en_ibat_lo_alert and can be read back and cleared at ibat_lo_alert.
  //    LTC4162_IBAT_LO_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_IBAT_FORMAT_R2I: Convert from amperes to the ibat ADC reading. MIN:-4.80354754182, MAX:4.80340094919.
  LTC4162_write_register(chip, LTC4162_IBAT_LO_ALERT_LIMIT_REG, (uint16_t)LTC4162_IBAT_FORMAT_R2I(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //DIE_TEMP_HI_ALERT_LIMIT_REG
  //  die_temp_hi_alert_limit: Signed number that sets an upper limit that can be used to trigger an interrupt based on high die temperature. The value in °C can be calculated from the A/D reading, die_temp, as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C. The alert is enabled by setting en_die_temp_hi_alert and can be read back and cleared at die_temp_hi_alert.
  //    LTC4162_DIE_TEMP_HI_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I: Convert from °C to the die_temp ADC reading. MIN:-968.225418305, MAX:439.403939257.
  LTC4162_write_register(chip, LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG, (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I(-264.4)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //BSR_HI_ALERT_LIMIT_REG
  //  bsr_hi_alert_limit: Sets an upper limit that can be used to trigger an interrupt based on high battery resistance. The per-cell battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from: BSR = cell_count × bsr × RSNSB / 500. The alert is enabled by setting en_bsr_hi_alert and can be read back and cleared at bsr_hi_alert.
  //    LTC4162_BSR_HI_ALERT_LIMIT_DEFAULT: 0
  //    LTC4162_BSR_FORMAT_R2U: Convert from Ω to the per-cell bsr ADC reading. MIN:0.0, MAX:1.31247997284.
  LTC4162_write_register(chip, LTC4162_BSR_HI_ALERT_LIMIT_REG, LTC4162_BSR_FORMAT_R2U(0.0)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG
  //  thermistor_voltage_hi_alert_limit: Signed number that sets an upper limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_hi_alert can be read back and cleared at thermistor_voltage_hi_alert.
  //    LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(196.313569562)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG
  //  thermistor_voltage_lo_alert_limit: Signed number that sets a lower limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_lo_alert and can be read back and cleared at thermistor_voltage_lo_alert.
  //    LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_DEFAULT: 0
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(196.313569562)); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //EN_LIMIT_ALERTS_REG: Enable limit monitoring and alert notification via SMBALERT
  //  en_telemetry_valid_alert: To ensure high measurement accuracy, the telemetry system in the LTC4162 has a nominal start-up time of approximately 12ms. Setting this interrupt request causes an SMBALERT telemetry_valid_alert when telemetry_valid indicates that the telemetry system's readings are valid. Note that the switching battery charger will not operate until this telemetry system warmup period has passed, regardless of the state of this setting.
  //    LTC4162_EN_TELEMETRY_VALID_ALERT_DEFAULT: 0
  //  en_bsr_done_alert: Interrupt request that causes an SMBALERT upon bsr_done_alert when the bsr (battery-series-resistance) measurement is finished.
  //    LTC4162_EN_BSR_DONE_ALERT_DEFAULT: 0
  //  en_vbat_lo_alert: Interrupt request that causes an SMBALERT upon vbat_lo_alert when vbat is below vbat_lo_alert_limit.
  //    LTC4162_EN_VBAT_LO_ALERT_DEFAULT: 0
  //  en_vbat_hi_alert: Interrupt request that causes an SMBALERT upon vbat_hi_alert when vbat is above vbat_hi_alert_limit.
  //    LTC4162_EN_VBAT_HI_ALERT_DEFAULT: 0
  //  en_vin_lo_alert: Interrupt request that causes an SMBALERT upon vin_lo_alert when vin is below vin_lo_alert_limit.
  //    LTC4162_EN_VIN_LO_ALERT_DEFAULT: 0
  //  en_vin_hi_alert: Interrupt request that causes an SMBALERT upon vin_hi_alert when vin is above vin_hi_alert_limit.
  //    LTC4162_EN_VIN_HI_ALERT_DEFAULT: 0
  //  en_vout_lo_alert: Interrupt request that causes an SMBALERT upon vout_lo_alert when vout is below vout_lo_alert_limit.
  //    LTC4162_EN_VOUT_LO_ALERT_DEFAULT: 0
  //  en_vout_hi_alert: Interrupt request that causes an SMBALERT upon vout_hi_alert when vout is above vout_hi_alert_limit.
  //    LTC4162_EN_VOUT_HI_ALERT_DEFAULT: 0
  //  en_iin_hi_alert: Interrupt request that causes an SMBALERT upon iin_hi_alert when iin is above iin_hi_alert_limit.
  //    LTC4162_EN_IIN_HI_ALERT_DEFAULT: 0
  //  en_ibat_lo_alert: Interrupt request that causes an SMBALERT upon ibat_lo_alert when ibat is below ibat_lo_alert_limit.
  //    LTC4162_EN_IBAT_LO_ALERT_DEFAULT: 0
  //  en_die_temp_hi_alert: Interrupt request that causes an SMBALERT upon die_temp_hi_alert when die_temp is above die_temp_hi_alert_limit.
  //    LTC4162_EN_DIE_TEMP_HI_ALERT_DEFAULT: 0
  //  en_bsr_hi_alert: Interrupt request that causes an SMBALERT upon bsr_hi_alert when bsr is above bsr_hi_alert_limit.
  //    LTC4162_EN_BSR_HI_ALERT_DEFAULT: 0
  //  en_thermistor_voltage_hi_alert: Interrupt request that causes an SMBALERT upon thermistor_voltage_hi_alert when thermistor_voltage is above thermistor_voltage_hi_alert_limit. Recall that the thermistor has a negative temperature coefficient so higher thermistor_voltage readings correspond to lower temperatures.
  //    LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_DEFAULT: 0
  //  en_thermistor_voltage_lo_alert: Interrupt request that causes an SMBALERT upon thermistor_voltage_lo_alert when thermistor_voltage is below thermistor_voltage_lo_alert_limit. Recall that the thermistor has a negative temperature coefficient so lower thermistor_voltage readings correspond to higher temperatures.
  //    LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_DEFAULT: 0
  LTC4162_write_register(chip, LTC4162_EN_LIMIT_ALERTS_REG,
                         (0u << LTC4162_EN_TELEMETRY_VALID_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_BSR_DONE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VBAT_LO_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VBAT_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VIN_LO_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VIN_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VOUT_LO_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VOUT_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_IIN_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_IBAT_LO_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_DIE_TEMP_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_BSR_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET)); //SIZE: 1, MAX: 1, DEFAULT: 0

  //EN_CHARGER_STATE_ALERTS_REG: Enable charger state notification via SMBALERT
  //  en_bat_detect_failed_fault_alert: Interrupt request that causes an SMBALERT upon bat_detect_failed_fault_alert as indicated by bat_detect_failed_fault due to an inability to source power to the battery during battery detection testing (usually due to either iin_limit_active or vin_uvcl_active).
  //    LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_DEFAULT: 0
  //  en_battery_detection_alert: Interrupt request that causes an SMBALERT upon battery_detection_alert as indicated by battery_detection due to the LTC4162 entering battery detection testing.
  //    LTC4162_EN_BATTERY_DETECTION_ALERT_DEFAULT: 0
  //  en_charger_suspended_alert: Interrupt request that causes an SMBALERT upon charger_suspended_alert as indicated by charger_suspended whereby battery charging is terminated due to suspend_charger or thermistor_voltage out of jeita_t1 - jeita_t6 range.
  //    LTC4162_EN_CHARGER_SUSPENDED_ALERT_DEFAULT: 0
  //  en_precharge_alert: Interrupt request that causes an SMBALERT upon precharge_alert as indicated by precharge denoting the onset of the precharge phase of a battery charging cycle.
  //    LTC4162_EN_PRECHARGE_ALERT_DEFAULT: 0
  //  en_cc_cv_charge_alert: Interrupt request that causes an SMBALERT upon cc_cv_charge_alert as indicated by cc_cv_charge denoting the onset of the constant current / constant voltage phase of a battery charging cycle.
  //    LTC4162_EN_CC_CV_CHARGE_ALERT_DEFAULT: 0
  //  en_ntc_pause_alert: Interrupt request that causes an SMBALERT upon ntc_pause_alert as indicated by ntc_pause whereby a battery charge cycle is interrupted due to thermistor_voltage out of range as set by the jeita_t1 through jeita_t6 values.
  //    LTC4162_EN_NTC_PAUSE_ALERT_DEFAULT: 0
  //  en_timer_term_alert: Interrupt request that causes an SMBALERT upon timer_term_alert as indicated by timer_term whereby a battery charge cycle terminates due to tcvtimer reaching max_cv_time, the maximum time allowed in constant_voltage mode.
  //    LTC4162_EN_TIMER_TERM_ALERT_DEFAULT: 0
  //  en_c_over_x_term_alert: Interrupt request that causes an SMBALERT upon c_over_x_term_alert as indicated by c_over_x_term whereby a battery charge cycle terminates due to ibat dropping below the c_over_x_threshold.
  //    LTC4162_EN_C_OVER_X_TERM_ALERT_DEFAULT: 0
  //  en_max_charge_time_alert: Interrupt request that causes an SMBALERT upon max_charge_time_fault_alert as indicated by max_charge_time_fault whereby charging has terminated due to tchargetimer reaching max_charge_time.
  //    LTC4162_EN_MAX_CHARGE_TIME_ALERT_DEFAULT: 0
  //  en_bat_missing_fault_alert: Interrupt request that causes an SMBALERT upon bat_missing_fault_alert as indicated by bat_missing_fault whereby charging is prohibited if no battery is detected during the battery presence detection phase at the beginning of a charge cycle.
  //    LTC4162_EN_BAT_MISSING_FAULT_ALERT_DEFAULT: 0
  //  en_bat_short_fault_alert: Interrupt request that causes an SMBALERT upon bat_short_fault_alert as indicated by bat_short_fault whereby charging is prohibited if a shorted battery is detected during the battery presence detection phase at the beginning of a charge cycle.
  //    LTC4162_EN_BAT_SHORT_FAULT_ALERT_DEFAULT: 0
  LTC4162_write_register(chip, LTC4162_EN_CHARGER_STATE_ALERTS_REG,
                         (0u << LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_BATTERY_DETECTION_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_CHARGER_SUSPENDED_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_PRECHARGE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_CC_CV_CHARGE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_NTC_PAUSE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_TIMER_TERM_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_C_OVER_X_TERM_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_MAX_CHARGE_TIME_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_BAT_MISSING_FAULT_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_BAT_SHORT_FAULT_ALERT_OFFSET)); //SIZE: 1, MAX: 1, DEFAULT: 0

  //EN_CHARGE_STATUS_ALERTS_REG: Enable charge status notification via SMBALERT
  //  en_ilim_reg_active_alert: Interrupt request that causes an ilim_reg_active_alert SMBALERT upon ilim_reg_active (VCSP-VCSN greater than 45mV). May indicates that the switching regulator is currently controlling power delivery based on a safety current limit. This should not occur under normal conditions and is likely the result of a circuit board fault. Alternately indicates that the switching regulator is in dropout (near 100% duty cycle) and is not regulating on any feedback control loop.
  //    LTC4162_EN_ILIM_REG_ACTIVE_ALERT_DEFAULT: 0
  //  en_thermal_reg_active_alert: Interrupt request that causes a thermal_reg_active_alert SMBALERT upon thermal_reg_active indicating that the icharge_dac is being dialed back to reduce internal die heating.
  //    LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_DEFAULT: 0
  //  en_vin_uvcl_active_alert: Interrupt request that causes a vin_uvcl_active_alert SMBALERT upon vin_uvcl_active indicating that the undervoltage regulation loop has taken control of the switching regulator.
  //    LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_DEFAULT: 0
  //  en_iin_limit_active_alert: Interrupt request that causes a iin_limit_active_alert SMBALERT upon iin_limit_active indicating that the input current regulation loop has taken control of the switching regulator.
  //    LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_DEFAULT: 0
  //  en_constant_current_alert: Interrupt request that causes a constant_current_alert SMBALERT upon constant_current indicating that the battery charger constant current regulation loop has taken control of the switching regulator.
  //    LTC4162_EN_CONSTANT_CURRENT_ALERT_DEFAULT: 0
  //  en_constant_voltage_alert: Interrupt request that causes a constant_voltage_alert SMBALERT upon constant_voltage indicating that the battery charger constant voltage regulation loop has taken control of the switching regulator.
  //    LTC4162_EN_CONSTANT_VOLTAGE_ALERT_DEFAULT: 0
  LTC4162_write_register(chip, LTC4162_EN_CHARGE_STATUS_ALERTS_REG,
                         (0u << LTC4162_EN_ILIM_REG_ACTIVE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_CONSTANT_CURRENT_ALERT_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_EN_CONSTANT_VOLTAGE_ALERT_OFFSET)); //SIZE: 1, MAX: 1, DEFAULT: 0

  //THERMAL_REG_START_TEMP_REG
  //  thermal_reg_start_temp: Signed number that sets the start of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 17897 corresponds to 120°C.
  //    LTC4162_THERMAL_REG_START_TEMP_DEFAULT: 17897
  //    (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I: Convert from °C to the die_temp ADC reading. MIN:-968.225418305, MAX:439.403939257.
  LTC4162_write_register(chip, LTC4162_THERMAL_REG_START_TEMP_REG, (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I(120.01050755)); //SIZE: 16, MAX: 65535, DEFAULT: 17897

  //THERMAL_REG_END_TEMP_REG
  //  thermal_reg_end_temp: Signed number that sets the end of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 18130 corresponds to 125°C.
  //    LTC4162_THERMAL_REG_END_TEMP_DEFAULT: 18130
  //    (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I: Convert from °C to the die_temp ADC reading. MIN:-968.225418305, MAX:439.403939257.
  LTC4162_write_register(chip, LTC4162_THERMAL_REG_END_TEMP_REG, (uint16_t)LTC4162_DIE_TEMP_FORMAT_R2I(125.015125545)); //SIZE: 16, MAX: 65535, DEFAULT: 18130

  //CONFIG_BITS_REG: System configuration settings
  //  suspend_charger: Causes battery charging to be suspended. This setting should be used cautiously. For embedded battery systems where two wire interface communication relies on a minimum battery voltage, setting this bit could result in a deadlock that may require factory service to correct.
  //    LTC4162_SUSPEND_CHARGER_DEFAULT: 0
  //  run_bsr: Causes the battery equivalent-series-resistance (bsr) measurement to be made as soon as a charge cycle starts or immediately if a charge cycle is already running.
  //    LTC4162_RUN_BSR_DEFAULT: 0
  //  telemetry_speed: Forces the telemetry system to take measurements at the higher rate of approximately once every 11ms whenever the telemetry system is on. When this bit is disabled, the telemetry system will slow down to about once every 5s to reduce power when not charging. Setting telemetry_speed to tel_high_speed in conjunction with force_telemetry_on with no input power available will increase battery drain.
  //    LTC4162_TELEMETRY_SPEED_ENUM_TEL_LOW_SPEED: 0
  //    LTC4162_TELEMETRY_SPEED_ENUM_TEL_HIGH_SPEED: 1
  //    LTC4162_TELEMETRY_SPEED_DEFAULT: 0
  //  force_telemetry_on: Causes the telemetry system to operate at all times, including times when only battery power is available.
  //    LTC4162_FORCE_TELEMETRY_ON_DEFAULT: 0
  //  mppt_en: Causes the Maximum Power-Point Tracking algorithm to run. The maximum power point algorithm takes control of the input undervoltage regulation control loop via the input_undervoltage_dac to seek the optimum power-point for resistive sources such as a long cable or solar panel.
  //    LTC4162_MPPT_EN_DEFAULT: 1
  LTC4162_write_register(chip, LTC4162_CONFIG_BITS_REG,
                         (0u << LTC4162_SUSPEND_CHARGER_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_RUN_BSR_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (LTC4162_TELEMETRY_SPEED_ENUM_TEL_LOW_SPEED << LTC4162_TELEMETRY_SPEED_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (0u << LTC4162_FORCE_TELEMETRY_ON_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (1u << LTC4162_MPPT_EN_OFFSET)); //SIZE: 1, MAX: 1, DEFAULT: 1

  //IIN_LIMIT_TARGET_REG
  //  iin_limit_target: Controls the target input current limit setting. The input current is limited by regulating charge current in response to the voltage across an external current sense resistor, RSNSI, between the CLP and CLN pins and is given by (iin_limit_target + 1) × 500µV / RSNSI. Note that the LTC4162 can only limit charge current based on this setting. It does not have the authority to block current from passing directly through to the system load. Connecting the system load to the battery, however, can allow total input current control.
  //    LTC4162_IIN_LIMIT_TARGET_DEFAULT: 63
  //    LTC4162_IINLIM_R2U: Convert from amperes to the iinlim setting. MIN:0.05, MAX:3.2.
  LTC4162_write_register(chip, LTC4162_IIN_LIMIT_TARGET_REG, LTC4162_IINLIM_R2U(3.2)); //SIZE: 6, MAX: 63, DEFAULT: 63

  //INPUT_UNDERVOLTAGE_SETTING_REG
  //  input_undervoltage_setting: Controls the input undervoltage regulation setting. The regulation voltage, given by (input_undervoltage_setting + 1) × 140.625mV, is the voltage at which the charge current will be reduced to prevent further droop in supply voltage due to a resistive source. If mppt_en is set, the MPPT algorithm will override this setting. The actual input undervoltage value can be read back from the input_undervoltage_dac.
  //    LTC4162_INPUT_UNDERVOLTAGE_SETTING_DEFAULT: 31
  //    LTC4162_VIN_UVCL_R2U: Convert from volts to the vin_uvcl setting. MIN:0.140625, MAX:36.0.
  LTC4162_write_register(chip, LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG, LTC4162_VIN_UVCL_R2U(4.5)); //SIZE: 8, MAX: 255, DEFAULT: 31

  //ARM_SHIP_MODE_REG
  //  arm_ship_mode: Setting this register to arm arms the ultra low-power ship and store mode. Ship mode does not take effect until the VIN pin drops below approximately 1V or immediately if VIN is already below 1V.
  //    LTC4162_ARM_SHIP_MODE_ENUM_ARM: 21325
  //    LTC4162_ARM_SHIP_MODE_DEFAULT: 0
  LTC4162_write_register(chip, LTC4162_ARM_SHIP_MODE_REG, 0u); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //CHARGE_CURRENT_SETTING_REG
  //  charge_current_setting: Controls the target charge current regulation servo level. The charge current is regulated by servoing the voltage across an external current sense resistor, RSNSB, between the CSP and CSN pins. The servo voltage is given by (charge_current_setting + 1) × 1mV. The effective charge current, determined by the external resistor, RSNSB, is given by (charge_current_setting + 1) × 1mV / RSNSB. icharge_dac will follow charge_current_setting unless thermal_reg_active is true or the JEITA algorithm, with en_jeita, has altered it.
  //    LTC4162_CHARGE_CURRENT_SETTING_DEFAULT: 31
  //    LTC4162_ICHARGE_R2U: Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  LTC4162_write_register(chip, LTC4162_CHARGE_CURRENT_SETTING_REG, LTC4162_ICHARGE_R2U(3.2)); //SIZE: 5, MAX: 31, DEFAULT: 31

  //VCHARGE_SETTING_REG
  //  vcharge_setting: Controls the final charge voltage regulation servo level. To maintain inherent over-charge protection, only Lithium Ion appropriate charge voltage values can be selected. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max). vcharge_dac will follow vcharge_setting unless the advanced JEITA temperature control system (en_jeita) has altered it.
  //    LTC4162_VCHARGE_SETTING_ENUM_VCHARGE_LION_DEFAULT: 31
  //    LTC4162_VCHARGE_SETTING_DEFAULT: 31
  //    LTC4162_VCHARGE_LIION_R2U: Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  LTC4162_write_register(chip, LTC4162_VCHARGE_SETTING_REG, LTC4162_VCHARGE_SETTING_ENUM_VCHARGE_LION_DEFAULT); //SIZE: 5, MAX: 31, DEFAULT: 31

  //C_OVER_X_THRESHOLD_REG
  //  c_over_x_threshold: Signed number that sets the ibat A/D value used to qualify C/x detection and termination. The C/x level is based on the value for ibat which has a scaling factor of 1.466µV / RSNSB amperes/LSB. For example, to make the C/x level C/10 (a very common choice) then c_over_x_threshold should be set to c_over_10 which is 10% of the maximum possible ibat reading (32mV × 37.5 × 18,191 / 10). 32mV is the full scale charge current signal from CSP to CSN, 37.5 is the internal charge amplifier's gain and 18,191 is the A/D's span term in counts per Volt.
  //    LTC4162_C_OVER_X_THRESHOLD_ENUM_C_OVER_10: 2184
  //    LTC4162_C_OVER_X_THRESHOLD_DEFAULT: 2184
  //    (uint16_t)LTC4162_IBAT_FORMAT_R2I: Convert from amperes to the ibat ADC reading. MIN:-4.80354754182, MAX:4.80340094919.
  LTC4162_write_register(chip, LTC4162_C_OVER_X_THRESHOLD_REG, LTC4162_C_OVER_X_THRESHOLD_ENUM_C_OVER_10); //SIZE: 16, MAX: 65535, DEFAULT: 2184

  //MAX_CV_TIME_REG
  //  max_cv_time: Sets the constant-voltage termination setting against which the tcvtimer is compared. The timer begins at the onset of the constant_voltage phase of charging and increments at one count per second. The default setting is 14,400 (4 hours).
  //    LTC4162_MAX_CV_TIME_ENUM_30MINS: 1800
  //    LTC4162_MAX_CV_TIME_ENUM_1HOUR: 3600
  //    LTC4162_MAX_CV_TIME_ENUM_2HOURS: 7200
  //    LTC4162_MAX_CV_TIME_ENUM_4HOURS_DEFAULT: 14400
  //    LTC4162_MAX_CV_TIME_DEFAULT: 14400
  LTC4162_write_register(chip, LTC4162_MAX_CV_TIME_REG, LTC4162_MAX_CV_TIME_ENUM_4HOURS_DEFAULT); //SIZE: 16, MAX: 65535, DEFAULT: 14400

  //MAX_CHARGE_TIME_REG
  //  max_charge_time: Sets the total charge time termination setting against which the tchargetimer is compared. The default value of 0 disables the total charge time feature and prevents the tchargetimer from running. If enabled with a non zero value, the tchargetimer begins counting at the onset of a charge cycle and increments at one count per minute.
  //    LTC4162_MAX_CHARGE_TIME_ENUM_MAXCHARGETIME_DISABLE: 0
  //    LTC4162_MAX_CHARGE_TIME_DEFAULT: 0
  LTC4162_write_register(chip, LTC4162_MAX_CHARGE_TIME_REG, LTC4162_MAX_CHARGE_TIME_ENUM_MAXCHARGETIME_DISABLE); //SIZE: 16, MAX: 65535, DEFAULT: 0

  //JEITA_T1_REG
  //  jeita_t1: Signed number that sets the JEITA temperature region transition temperature T1 between JEITA regions R1 and R2. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 16117 maps to about 0°C for the expected thermistor β value of 3490K.
  //    LTC4162_JEITA_T1_DEFAULT: 16117
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_JEITA_T1_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(-0.188805466836)); //SIZE: 16, MAX: 65535, DEFAULT: 16117

  //JEITA_T2_REG
  //  jeita_t2: Signed number that sets the JEITA temperature region transition temperature T2 between JEITA regions R2 and R3. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 14113 maps to about 10°C for the expected thermistor β value of 3490K.
  //    LTC4162_JEITA_T2_DEFAULT: 14113
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_JEITA_T2_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(9.88371113339)); //SIZE: 16, MAX: 65535, DEFAULT: 14113

  //JEITA_T3_REG
  //  jeita_t3: Signed number that sets the JEITA temperature region transition temperature T3 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7970 maps to about 40°C for the expected thermistor β value of 3490K.
  //    LTC4162_JEITA_T3_DEFAULT: 7970
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_JEITA_T3_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(40.2046110219)); //SIZE: 16, MAX: 65535, DEFAULT: 7970

  //JEITA_T4_REG
  //  jeita_t4: Signed number that sets the JEITA temperature region transition temperature T4 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7112 maps to about 45°C for the expected thermistor β value of 3490K.
  //    LTC4162_JEITA_T4_DEFAULT: 7112
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_JEITA_T4_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(45.0724234503)); //SIZE: 16, MAX: 65535, DEFAULT: 7112

  //JEITA_T5_REG
  //  jeita_t5: Signed number that sets the JEITA temperature region transition temperature T5 between JEITA regions R5 and R6. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 6325 maps to about 50°C for the expected thermistor β value of 3490K.
  //    LTC4162_JEITA_T5_DEFAULT: 6325
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_JEITA_T5_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(50.1695321291)); //SIZE: 16, MAX: 65535, DEFAULT: 6325

  //JEITA_T6_REG
  //  jeita_t6: Signed number that sets the JEITA temperature region transition temperature T6 between JEITA regions R6 and R7. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 4970 maps to about 60°C for the expected thermistor β value of 3490K.
  //    LTC4162_JEITA_T6_DEFAULT: 4970
  //    (uint16_t)LTC4162_NTCS0402E3103FLT_R2I: Convert from °C to the thermistor ADC reading. MIN:2565.13735376, MAX:-235.12625768.
  LTC4162_write_register(chip, LTC4162_JEITA_T6_REG, (uint16_t)LTC4162_NTCS0402E3103FLT_R2I(60.1512004158)); //SIZE: 16, MAX: 65535, DEFAULT: 4970

  //VCHARGE_JEITA_6_5_REG: vcharge_setting values for JEITA temperature regions jeita_t6 and jeita_t5
  //  vcharge_jeita_6: Sets the charge voltage to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_6 × 12.5mV + 3.8125V. The default value of 19 corresponds to 4.05V.
  //    LTC4162_VCHARGE_JEITA_6_DEFAULT: 19
  //    LTC4162_VCHARGE_LIION_R2U: Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //  vcharge_jeita_5: Sets the charge voltage to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_5 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V.
  //    LTC4162_VCHARGE_JEITA_5_DEFAULT: 23
  //    LTC4162_VCHARGE_LIION_R2U: Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_6_5_REG,
                         (LTC4162_VCHARGE_LIION_R2U(4.05) << LTC4162_VCHARGE_JEITA_6_OFFSET) | //SIZE: 5, MAX: 31, DEFAULT: 19
                         (LTC4162_VCHARGE_LIION_R2U(4.1) << LTC4162_VCHARGE_JEITA_5_OFFSET)); //SIZE: 5, MAX: 31, DEFAULT: 23

  //VCHARGE_JEITA_4_3_2_REG: vcharge_setting values for JEITA temperature regions jeita_t4, jeita_t3, and jeita_t2
  //  vcharge_jeita_4: Sets the charge voltage to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_4 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V
  //    LTC4162_VCHARGE_JEITA_4_DEFAULT: 23
  //    LTC4162_VCHARGE_LIION_R2U: Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //  vcharge_jeita_3: Sets the charge voltage to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_3 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V.
  //    LTC4162_VCHARGE_JEITA_3_DEFAULT: 31
  //    LTC4162_VCHARGE_LIION_R2U: Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  //  vcharge_jeita_2: Sets the charge voltage to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_2 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V.
  //    LTC4162_VCHARGE_JEITA_2_DEFAULT: 31
  //    LTC4162_VCHARGE_LIION_R2U: Convert from volts to the vcharge_liion setting. MIN:3.8125, MAX:4.2.
  LTC4162_write_register(chip, LTC4162_VCHARGE_JEITA_4_3_2_REG,
                         (LTC4162_VCHARGE_LIION_R2U(4.1) << LTC4162_VCHARGE_JEITA_4_OFFSET) | //SIZE: 5, MAX: 31, DEFAULT: 23
                         (LTC4162_VCHARGE_LIION_R2U(4.2) << LTC4162_VCHARGE_JEITA_3_OFFSET) | //SIZE: 5, MAX: 31, DEFAULT: 31
                         (LTC4162_VCHARGE_LIION_R2U(4.2) << LTC4162_VCHARGE_JEITA_2_OFFSET)); //SIZE: 5, MAX: 31, DEFAULT: 31

  //ICHARGE_JEITA_6_5_REG: charge_current_setting values for JEITA temperature regions jeita_t6 and jeita_t5
  //  icharge_jeita_6: Sets the charge current to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_6 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
  //    LTC4162_ICHARGE_JEITA_6_DEFAULT: 15
  //    LTC4162_ICHARGE_R2U: Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //  icharge_jeita_5: Sets the charge current to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_5 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
  //    LTC4162_ICHARGE_JEITA_5_DEFAULT: 15
  //    LTC4162_ICHARGE_R2U: Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_6_5_REG,
                         (LTC4162_ICHARGE_R2U(1.6) << LTC4162_ICHARGE_JEITA_6_OFFSET) | //SIZE: 5, MAX: 31, DEFAULT: 15
                         (LTC4162_ICHARGE_R2U(1.6) << LTC4162_ICHARGE_JEITA_5_OFFSET)); //SIZE: 5, MAX: 31, DEFAULT: 15

  //ICHARGE_JEITA_4_3_2_REG: charge_current_setting value for JEITA temperature regions jeita_t4, jeita_t3, and jeita_t2
  //  icharge_jeita_4: Sets the charge current to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_4 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale.
  //    LTC4162_ICHARGE_JEITA_4_DEFAULT: 31
  //    LTC4162_ICHARGE_R2U: Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //  icharge_jeita_3: Sets the charge current to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the  charge current can be calculated using (icharge_jeita_3 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale.
  //    LTC4162_ICHARGE_JEITA_3_DEFAULT: 31
  //    LTC4162_ICHARGE_R2U: Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  //  icharge_jeita_2: Sets the charge current to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_2 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
  //    LTC4162_ICHARGE_JEITA_2_DEFAULT: 15
  //    LTC4162_ICHARGE_R2U: Convert from amperes to the charge_current_setting. MIN:0.1, MAX:3.2.
  LTC4162_write_register(chip, LTC4162_ICHARGE_JEITA_4_3_2_REG,
                         (LTC4162_ICHARGE_R2U(3.2) << LTC4162_ICHARGE_JEITA_4_OFFSET) | //SIZE: 5, MAX: 31, DEFAULT: 31
                         (LTC4162_ICHARGE_R2U(3.2) << LTC4162_ICHARGE_JEITA_3_OFFSET) | //SIZE: 5, MAX: 31, DEFAULT: 31
                         (LTC4162_ICHARGE_R2U(1.6) << LTC4162_ICHARGE_JEITA_2_OFFSET)); //SIZE: 5, MAX: 31, DEFAULT: 15

  //CHARGER_CONFIG_BITS_REG: Battery charger configuration settings
  //  en_c_over_x_term: Enables charge current based (C/x) battery charger termination as set by ibat dropping to the c_over_x_threshold in constant_voltage.
  //    LTC4162_EN_C_OVER_X_TERM_DEFAULT: 0
  //  en_jeita: Enables the JEITA temperature qualified charging system.
  //    LTC4162_EN_JEITA_DEFAULT: 1
  LTC4162_write_register(chip, LTC4162_CHARGER_CONFIG_BITS_REG,
                         (0u << LTC4162_EN_C_OVER_X_TERM_OFFSET) | //SIZE: 1, MAX: 1, DEFAULT: 0
                         (1u << LTC4162_EN_JEITA_OFFSET)); //SIZE: 1, MAX: 1, DEFAULT: 1

}
