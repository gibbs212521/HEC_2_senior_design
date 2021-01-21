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
 *  @brief LTC4162-LADM library file defining data conversion macros and constants for the LTC4162-LADM.
 *
 *
 *  This file contains constants and real to integer/unsigned macros which can be used
 *  to represent real values in the source code, with automatic compile-time
 *  conversion to LTC4162 integer register scaling.
 *  Passing runtime variables to these macros should be avoided in embedded systems, as it
 *  results in runtime floating point calculations.
 *
 *  This file also contains integer/unsigned to real macros which can be used to convert from
 *  internal integer format to real values for display/debug. Invoking these macros results in
 *  runtime floating point calculations with associated high memory and execution penalty in
 *  small embedded systems.
 * @{
 */

#ifndef LTC4162_FORMATS_H_
#define LTC4162_FORMATS_H_

/*! @name Format Definitions
 *  Constants used by the macros below to convert between real and LTC4162 integer scaling.
 */
/*! @name Constants used in real/integer conversion macros below */
#define LTC4162_RSNSI 0.010
#define LTC4162_RSNSB 0.010
#define LTC4162_RNTCBIAS 10000.0
#define LTC4162_RNTCSER 0.0
#define LTC4162_VINDIV 30.0
#define LTC4162_VOUTDIV (30.0 * 1.00232)
#define LTC4162_BATDIV 3.5
#define LTC4162_AVPROG 37.5
#define LTC4162_AVCLPROG 37.5
#define LTC4162_ADCGAIN 18191.0
#define LTC4162_VREF 1.2
#define LTC4162_Rm40 214063.67
#define LTC4162_Rm34 152840.30
#define LTC4162_Rm28 110480.73
#define LTC4162_Rm21 76798.02
#define LTC4162_Rm14 54214.99
#define LTC4162_Rm6 37075.65
#define LTC4162_R4 23649.71
#define LTC4162_R33 7400.97
#define LTC4162_R44 5001.22
#define LTC4162_R53 3693.55
#define LTC4162_R62 2768.21
#define LTC4162_R70 2167.17
#define LTC4162_R78 1714.08
#define LTC4162_R86 1368.87
#define LTC4162_R94 1103.18
#define LTC4162_R102 896.73
#define LTC4162_R110 734.86
#define LTC4162_R118 606.86
#define LTC4162_R126 504.80
#define LTC4162_R134 422.81
#define LTC4162_R142 356.45
#define LTC4162_R150 302.36

/*! @name Use the macros below to convert between real and LTC4162 integer scaling. */
/*! Convert from amperes to the iinlim setting.
 *   - Used with Bit Fields: iin_limit_target, iin_limit_dac, target_ilim.
 */
#define LTC4162_IINLIM_R2U(x) (uint16_t)__LTC4162_ILINE__((LTC4162_VREF / 64 / LTC4162_AVCLPROG / LTC4162_RSNSI), (LTC4162_VREF / 64 / LTC4162_AVCLPROG / LTC4162_RSNSI * 2), (0), (1), x)
#define LTC4162_IINLIM_U2R(y) __LTC4162_RLINE__((0), (1), (LTC4162_VREF / 64 / LTC4162_AVCLPROG / LTC4162_RSNSI), (LTC4162_VREF / 64 / LTC4162_AVCLPROG / LTC4162_RSNSI * 2), (uint16_t)(y))

/*! Convert from volts to the vcharge_liion setting.
 *   - Used with Bit Fields: vcharge_setting, vcharge_jeita_6, vcharge_jeita_5, vcharge_jeita_4, vcharge_jeita_3, vcharge_jeita_2, vcharge_dac.
 */
#define LTC4162_VCHARGE_LIION_R2U(x) (uint16_t)__LTC4162_ILINE__((3.8125), (3.8125 + 0.0125), (0), (1), x)
#define LTC4162_VCHARGE_LIION_U2R(y) __LTC4162_RLINE__((0), (1), (3.8125), (3.8125 + 0.0125), (uint16_t)(y))

/*! Convert from volts to the vin_uvcl setting.
 *   - Used with Bit Fields: input_undervoltage_setting, input_undervoltage_dac, input_undervoltage_mppt, mppt_vuvcl_dac_pmax.
 */
#define LTC4162_VIN_UVCL_R2U(x) (uint16_t)__LTC4162_ILINE__((LTC4162_VREF / 256 * LTC4162_VINDIV), (LTC4162_VREF / 256 * LTC4162_VINDIV * 2), (0), (1), x)
#define LTC4162_VIN_UVCL_U2R(y) __LTC4162_RLINE__((0), (1), (LTC4162_VREF / 256 * LTC4162_VINDIV), (LTC4162_VREF / 256 * LTC4162_VINDIV * 2), (uint16_t)(y))

/*! Convert from amperes to the charge_current_setting.
 *   - Used with Bit Fields: charge_current_setting, icharge_jeita_6, icharge_jeita_5, icharge_jeita_4, icharge_jeita_3, icharge_jeita_2, icharge_dac, target_icharge.
 */
#define LTC4162_ICHARGE_R2U(x) (uint16_t)__LTC4162_ILINE__((LTC4162_VREF / 32 / LTC4162_AVPROG / LTC4162_RSNSB), (LTC4162_VREF / 32 / LTC4162_AVPROG / LTC4162_RSNSB * 2), (0), (1), x)
#define LTC4162_ICHARGE_U2R(y) __LTC4162_RLINE__((0), (1), (LTC4162_VREF / 32 / LTC4162_AVPROG / LTC4162_RSNSB), (LTC4162_VREF / 32 / LTC4162_AVPROG / LTC4162_RSNSB * 2), (uint16_t)(y))

/*! Convert from volts to the per-cell vbat ADC reading.
 *   - Used with Bit Fields: vbat_lo_alert_limit, vbat_hi_alert_limit, vbat, vbat_filt.
 */
#define LTC4162_VBAT_FORMAT_R2I(x) (int16_t)__LTC4162_ILINE__((0), (LTC4162_BATDIV / LTC4162_ADCGAIN), (0), (1), x)
#define LTC4162_VBAT_FORMAT_I2R(y) __LTC4162_RLINE__((0), (1), (0), (LTC4162_BATDIV / LTC4162_ADCGAIN), (int16_t)(y))

/*! Convert from amperes to the ibat ADC reading.
 *   - Used with Bit Fields: ibat_lo_alert_limit, c_over_x_threshold, ibat, bsr_charge_current, mppt_ichrg, mppt_ichrg_max, mppt_ichrg_last.
 */
#define LTC4162_IBAT_FORMAT_R2I(x) (int16_t)__LTC4162_ILINE__((0), (1 / LTC4162_RSNSB / LTC4162_AVPROG / LTC4162_ADCGAIN), (0), (1), x)
#define LTC4162_IBAT_FORMAT_I2R(y) __LTC4162_RLINE__((0), (1), (0), (1 / LTC4162_RSNSB / LTC4162_AVPROG / LTC4162_ADCGAIN), (int16_t)(y))

/*! Convert from volts to the vout ADC reading.
 *   - Used with Bit Fields: vout_lo_alert_limit, vout_hi_alert_limit, vout.
 */
#define LTC4162_VOUT_FORMAT_R2I(x) (int16_t)__LTC4162_ILINE__((0), (LTC4162_VOUTDIV / LTC4162_ADCGAIN), (0), (1), x)
#define LTC4162_VOUT_FORMAT_I2R(y) __LTC4162_RLINE__((0), (1), (0), (LTC4162_VOUTDIV / LTC4162_ADCGAIN), (int16_t)(y))

/*! Convert from volts to the vin ADC reading.
 *   - Used with Bit Fields: vin_lo_alert_limit, vin_hi_alert_limit, vin, mppt_vin_init.
 */
#define LTC4162_VIN_FORMAT_R2I(x) (int16_t)__LTC4162_ILINE__((0), (LTC4162_VINDIV / LTC4162_ADCGAIN), (0), (1), x)
#define LTC4162_VIN_FORMAT_I2R(y) __LTC4162_RLINE__((0), (1), (0), (LTC4162_VINDIV / LTC4162_ADCGAIN), (int16_t)(y))

/*! Convert from amperes to the iin ADC reading.
 *   - Used with Bit Fields: iin_hi_alert_limit, iin.
 */
#define LTC4162_IIN_FORMAT_R2I(x) (int16_t)__LTC4162_ILINE__((0), (1 / LTC4162_RSNSI / LTC4162_AVCLPROG / LTC4162_ADCGAIN), (0), (1), x)
#define LTC4162_IIN_FORMAT_I2R(y) __LTC4162_RLINE__((0), (1), (0), (1 / LTC4162_RSNSI / LTC4162_AVCLPROG / LTC4162_ADCGAIN), (int16_t)(y))

/*! Convert from Ω to the per-cell bsr ADC reading.
 *   - Used with Bit Fields: bsr_hi_alert_limit, bsr.
 */
#define LTC4162_BSR_FORMAT_R2U(x) (uint16_t)__LTC4162_ILINE__((0), (LTC4162_RSNSB * LTC4162_AVPROG * LTC4162_BATDIV / 65536), (0), (1), x)
#define LTC4162_BSR_FORMAT_U2R(y) __LTC4162_RLINE__((0), (1), (0), (LTC4162_RSNSB * LTC4162_AVPROG * LTC4162_BATDIV / 65536), (uint16_t)(y))

/*! Convert from °C to the die_temp ADC reading.
 *   - Used with Bit Fields: die_temp_hi_alert_limit, thermal_reg_start_temp, thermal_reg_end_temp, die_temp.
 */
#define LTC4162_DIE_TEMP_FORMAT_R2I(x) (int16_t)__LTC4162_ILINE__((-264.4), (-264.4 + 1 / 46.557), (0), (1), x)
#define LTC4162_DIE_TEMP_FORMAT_I2R(y) __LTC4162_RLINE__((0), (1), (-264.4), (-264.4 + 1 / 46.557), (int16_t)(y))

/*! Convert from °C to the thermistor ADC reading.
 *   - Used with Bit Fields: thermistor_voltage_hi_alert_limit, thermistor_voltage_lo_alert_limit, jeita_t1, jeita_t2, jeita_t3, jeita_t4, jeita_t5, jeita_t6, thermistor_voltage.
 */
#define LTC4162_NTCS0402E3103FLT_R2I(x) (\
  __LTC4162_BELOW__((-40), x) ? \
    (int16_t)__LTC4162_ILINE__((-40), (-34), ((LTC4162_Rm40 + LTC4162_RNTCSER) / (LTC4162_Rm40 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((-40), (-34), x) ? \
    (int16_t)__LTC4162_ILINE__((-40), (-34), ((LTC4162_Rm40 + LTC4162_RNTCSER) / (LTC4162_Rm40 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((-34), (-28), x) ? \
    (int16_t)__LTC4162_ILINE__((-34), (-28), ((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm28 + LTC4162_RNTCSER) / (LTC4162_Rm28 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((-28), (-21), x) ? \
    (int16_t)__LTC4162_ILINE__((-28), (-21), ((LTC4162_Rm28 + LTC4162_RNTCSER) / (LTC4162_Rm28 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm21 + LTC4162_RNTCSER) / (LTC4162_Rm21 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((-21), (-14), x) ? \
    (int16_t)__LTC4162_ILINE__((-21), (-14), ((LTC4162_Rm21 + LTC4162_RNTCSER) / (LTC4162_Rm21 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm14 + LTC4162_RNTCSER) / (LTC4162_Rm14 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((-14), (-6), x) ? \
    (int16_t)__LTC4162_ILINE__((-14), (-6), ((LTC4162_Rm14 + LTC4162_RNTCSER) / (LTC4162_Rm14 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm6 + LTC4162_RNTCSER) / (LTC4162_Rm6 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((-6), (4), x) ? \
    (int16_t)__LTC4162_ILINE__((-6), (4), ((LTC4162_Rm6 + LTC4162_RNTCSER) / (LTC4162_Rm6 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R4 + LTC4162_RNTCSER) / (LTC4162_R4 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((4), (33), x) ? \
    (int16_t)__LTC4162_ILINE__((4), (33), ((LTC4162_R4 + LTC4162_RNTCSER) / (LTC4162_R4 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R33 + LTC4162_RNTCSER) / (LTC4162_R33 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((33), (44), x) ? \
    (int16_t)__LTC4162_ILINE__((33), (44), ((LTC4162_R33 + LTC4162_RNTCSER) / (LTC4162_R33 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R44 + LTC4162_RNTCSER) / (LTC4162_R44 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((44), (53), x) ? \
    (int16_t)__LTC4162_ILINE__((44), (53), ((LTC4162_R44 + LTC4162_RNTCSER) / (LTC4162_R44 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R53 + LTC4162_RNTCSER) / (LTC4162_R53 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((53), (62), x) ? \
    (int16_t)__LTC4162_ILINE__((53), (62), ((LTC4162_R53 + LTC4162_RNTCSER) / (LTC4162_R53 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R62 + LTC4162_RNTCSER) / (LTC4162_R62 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((62), (70), x) ? \
    (int16_t)__LTC4162_ILINE__((62), (70), ((LTC4162_R62 + LTC4162_RNTCSER) / (LTC4162_R62 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R70 + LTC4162_RNTCSER) / (LTC4162_R70 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((70), (78), x) ? \
    (int16_t)__LTC4162_ILINE__((70), (78), ((LTC4162_R70 + LTC4162_RNTCSER) / (LTC4162_R70 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R78 + LTC4162_RNTCSER) / (LTC4162_R78 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((78), (86), x) ? \
    (int16_t)__LTC4162_ILINE__((78), (86), ((LTC4162_R78 + LTC4162_RNTCSER) / (LTC4162_R78 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R86 + LTC4162_RNTCSER) / (LTC4162_R86 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((86), (94), x) ? \
    (int16_t)__LTC4162_ILINE__((86), (94), ((LTC4162_R86 + LTC4162_RNTCSER) / (LTC4162_R86 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R94 + LTC4162_RNTCSER) / (LTC4162_R94 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((94), (102), x) ? \
    (int16_t)__LTC4162_ILINE__((94), (102), ((LTC4162_R94 + LTC4162_RNTCSER) / (LTC4162_R94 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R102 + LTC4162_RNTCSER) / (LTC4162_R102 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((102), (110), x) ? \
    (int16_t)__LTC4162_ILINE__((102), (110), ((LTC4162_R102 + LTC4162_RNTCSER) / (LTC4162_R102 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R110 + LTC4162_RNTCSER) / (LTC4162_R110 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((110), (118), x) ? \
    (int16_t)__LTC4162_ILINE__((110), (118), ((LTC4162_R110 + LTC4162_RNTCSER) / (LTC4162_R110 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R118 + LTC4162_RNTCSER) / (LTC4162_R118 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((118), (126), x) ? \
    (int16_t)__LTC4162_ILINE__((118), (126), ((LTC4162_R118 + LTC4162_RNTCSER) / (LTC4162_R118 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R126 + LTC4162_RNTCSER) / (LTC4162_R126 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((126), (134), x) ? \
    (int16_t)__LTC4162_ILINE__((126), (134), ((LTC4162_R126 + LTC4162_RNTCSER) / (LTC4162_R126 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R134 + LTC4162_RNTCSER) / (LTC4162_R134 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((134), (142), x) ? \
    (int16_t)__LTC4162_ILINE__((134), (142), ((LTC4162_R134 + LTC4162_RNTCSER) / (LTC4162_R134 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
  __LTC4162_BETWEEN_INCLUSIVE__((142), (150), x) ? \
    (int16_t)__LTC4162_ILINE__((142), (150), ((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R150 + LTC4162_RNTCSER) / (LTC4162_R150 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) : \
    (int16_t)__LTC4162_ILINE__((142), (150), ((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R150 + LTC4162_RNTCSER) / (LTC4162_R150 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), x) \
)
#define LTC4162_NTCS0402E3103FLT_I2R(y) (\
  __LTC4162_BELOW__(((LTC4162_R150 + LTC4162_RNTCSER) / (LTC4162_R150 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R150 + LTC4162_RNTCSER) / (LTC4162_R150 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (150), (142), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R150 + LTC4162_RNTCSER) / (LTC4162_R150 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R150 + LTC4162_RNTCSER) / (LTC4162_R150 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (150), (142), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R134 + LTC4162_RNTCSER) / (LTC4162_R134 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R142 + LTC4162_RNTCSER) / (LTC4162_R142 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R134 + LTC4162_RNTCSER) / (LTC4162_R134 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (142), (134), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R134 + LTC4162_RNTCSER) / (LTC4162_R134 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R126 + LTC4162_RNTCSER) / (LTC4162_R126 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R134 + LTC4162_RNTCSER) / (LTC4162_R134 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R126 + LTC4162_RNTCSER) / (LTC4162_R126 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (134), (126), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R126 + LTC4162_RNTCSER) / (LTC4162_R126 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R118 + LTC4162_RNTCSER) / (LTC4162_R118 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R126 + LTC4162_RNTCSER) / (LTC4162_R126 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R118 + LTC4162_RNTCSER) / (LTC4162_R118 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (126), (118), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R118 + LTC4162_RNTCSER) / (LTC4162_R118 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R110 + LTC4162_RNTCSER) / (LTC4162_R110 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R118 + LTC4162_RNTCSER) / (LTC4162_R118 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R110 + LTC4162_RNTCSER) / (LTC4162_R110 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (118), (110), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R110 + LTC4162_RNTCSER) / (LTC4162_R110 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R102 + LTC4162_RNTCSER) / (LTC4162_R102 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R110 + LTC4162_RNTCSER) / (LTC4162_R110 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R102 + LTC4162_RNTCSER) / (LTC4162_R102 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (110), (102), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R102 + LTC4162_RNTCSER) / (LTC4162_R102 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R94 + LTC4162_RNTCSER) / (LTC4162_R94 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R102 + LTC4162_RNTCSER) / (LTC4162_R102 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R94 + LTC4162_RNTCSER) / (LTC4162_R94 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (102), (94), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R94 + LTC4162_RNTCSER) / (LTC4162_R94 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R86 + LTC4162_RNTCSER) / (LTC4162_R86 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R94 + LTC4162_RNTCSER) / (LTC4162_R94 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R86 + LTC4162_RNTCSER) / (LTC4162_R86 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (94), (86), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R86 + LTC4162_RNTCSER) / (LTC4162_R86 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R78 + LTC4162_RNTCSER) / (LTC4162_R78 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R86 + LTC4162_RNTCSER) / (LTC4162_R86 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R78 + LTC4162_RNTCSER) / (LTC4162_R78 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (86), (78), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R78 + LTC4162_RNTCSER) / (LTC4162_R78 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R70 + LTC4162_RNTCSER) / (LTC4162_R70 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R78 + LTC4162_RNTCSER) / (LTC4162_R78 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R70 + LTC4162_RNTCSER) / (LTC4162_R70 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (78), (70), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R70 + LTC4162_RNTCSER) / (LTC4162_R70 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R62 + LTC4162_RNTCSER) / (LTC4162_R62 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R70 + LTC4162_RNTCSER) / (LTC4162_R70 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R62 + LTC4162_RNTCSER) / (LTC4162_R62 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (70), (62), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R62 + LTC4162_RNTCSER) / (LTC4162_R62 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R53 + LTC4162_RNTCSER) / (LTC4162_R53 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R62 + LTC4162_RNTCSER) / (LTC4162_R62 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R53 + LTC4162_RNTCSER) / (LTC4162_R53 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (62), (53), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R53 + LTC4162_RNTCSER) / (LTC4162_R53 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R44 + LTC4162_RNTCSER) / (LTC4162_R44 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R53 + LTC4162_RNTCSER) / (LTC4162_R53 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R44 + LTC4162_RNTCSER) / (LTC4162_R44 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (53), (44), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R44 + LTC4162_RNTCSER) / (LTC4162_R44 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R33 + LTC4162_RNTCSER) / (LTC4162_R33 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R44 + LTC4162_RNTCSER) / (LTC4162_R44 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R33 + LTC4162_RNTCSER) / (LTC4162_R33 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (44), (33), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R33 + LTC4162_RNTCSER) / (LTC4162_R33 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R4 + LTC4162_RNTCSER) / (LTC4162_R4 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R33 + LTC4162_RNTCSER) / (LTC4162_R33 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_R4 + LTC4162_RNTCSER) / (LTC4162_R4 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (33), (4), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_R4 + LTC4162_RNTCSER) / (LTC4162_R4 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm6 + LTC4162_RNTCSER) / (LTC4162_Rm6 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_R4 + LTC4162_RNTCSER) / (LTC4162_R4 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm6 + LTC4162_RNTCSER) / (LTC4162_Rm6 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (4), (-6), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_Rm6 + LTC4162_RNTCSER) / (LTC4162_Rm6 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm14 + LTC4162_RNTCSER) / (LTC4162_Rm14 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_Rm6 + LTC4162_RNTCSER) / (LTC4162_Rm6 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm14 + LTC4162_RNTCSER) / (LTC4162_Rm14 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (-6), (-14), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_Rm14 + LTC4162_RNTCSER) / (LTC4162_Rm14 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm21 + LTC4162_RNTCSER) / (LTC4162_Rm21 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_Rm14 + LTC4162_RNTCSER) / (LTC4162_Rm14 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm21 + LTC4162_RNTCSER) / (LTC4162_Rm21 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (-14), (-21), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_Rm21 + LTC4162_RNTCSER) / (LTC4162_Rm21 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm28 + LTC4162_RNTCSER) / (LTC4162_Rm28 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_Rm21 + LTC4162_RNTCSER) / (LTC4162_Rm21 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm28 + LTC4162_RNTCSER) / (LTC4162_Rm28 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (-21), (-28), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_Rm28 + LTC4162_RNTCSER) / (LTC4162_Rm28 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_Rm28 + LTC4162_RNTCSER) / (LTC4162_Rm28 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (-28), (-34), (int16_t)(y)) : \
  __LTC4162_BETWEEN_INCLUSIVE__(((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm40 + LTC4162_RNTCSER) / (LTC4162_Rm40 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (int16_t)y) ? \
    __LTC4162_RLINE__(((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm40 + LTC4162_RNTCSER) / (LTC4162_Rm40 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (-34), (-40), (int16_t)(y)) : \
    __LTC4162_RLINE__(((LTC4162_Rm34 + LTC4162_RNTCSER) / (LTC4162_Rm34 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), ((LTC4162_Rm40 + LTC4162_RNTCSER) / (LTC4162_Rm40 + LTC4162_RNTCSER + LTC4162_RNTCBIAS) * LTC4162_ADCGAIN * LTC4162_VREF), (-34), (-40), (int16_t)(y)) \
)

/*! @name Private macros for use by formats above. */
#define __LTC4162_ROUND__(x) ((x) > 0 ? (x) + 0.5 : (x) - 0.5)
#define __LTC4162_ILINE__(x0,x1,y0,y1,x) __LTC4162_ROUND__((y0) + ((double)((y1) - (y0))/(double)((x1) - (x0))) * ((x) - (x0)))
#define __LTC4162_RLINE__(x0,x1,y0,y1,x) ((y0) + (double)((y1) - (y0))/(double)((x1) - (x0)) * ((x) - (x0)))
#define __LTC4162_BETWEEN_INCLUSIVE__(x0,x1,x) (((x) > (x0) && (x) < (x1)) || (x) == (x0) || (x) == (x1) ? 1 : 0)
#define __LTC4162_BELOW__(x0,x) ((x) < (x0) ? 1 : 0)
#define __LTC4162_ABOVE__(xn,x) ((x) > (xn) ? 1 : 0)


/*! @} */

#endif /* LTC4162_FORMATS_H_ */
