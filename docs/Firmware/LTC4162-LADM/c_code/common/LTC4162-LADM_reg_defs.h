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
 *  @brief LTC4162-LADM Register Map Definition Header
 *
 *
 *  This file contains LTC4162 definitions for each command_code as well as
 *  each individual bit field for the case when a register contains multiple
 *  bit-packed fields smaller than the register width.
 *
 *  Each bit field name is prepended with LTC4162_.
 *  Each bit field has individual definitions for its _SIZE, _OFFSET (LSB) and _MASK,
 *  as well as the three fields stored in a single 16-bit word for use with the access
 *  functions provided by LTC4162-LADM.c and LTC4162-LADM.h.
 *
 *  Additionally, each bit field contains a _DECODE macro to unpack multiple individual
 *  bit fields from a single copy of complete register data.
 *
 *  In the case that the bit field contents represent an enumeration, _ENUM
 *  definitions exist to translate from human readable format to the encoded value.
 *
 *  In the case that the bit field contents represent scalar data,
 *  macros exist in LTC4162_formats.h to translate from real units to integer values and back again.
 *  Real to integer conversions of literals should generally be optimized away at compile time
 *  without impact on execution speed or code size.
 *
 *  See @ref LTC4162-LADM_register_map for detailed descriptions of each bit field.
 *  See @ref LTC4162-LADM_formats for detailed descriptions of each data formatting macro.
 */

/*! @defgroup LTC4162-LADM_register_map LTC4162 Register Map Definitions
 *  @ingroup LTC4162-LADM
 */

#ifndef LTC4162_REG_DEFS_H_
#define LTC4162_REG_DEFS_H_

#define LTC4162_ADDR_68 0x68u //!<LTC4162 I2C address in 7-bit format

#define LTC4162_WORD_SIZE 16u

/*! @defgroup LTC4162_VBAT_LO_ALERT_LIMIT_REG VBAT_LO_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_LO_ALERT_LIMIT_REG Register
 *
 * |                15:0 |
 * |:-------------------:|
 * | VBAT_LO_ALERT_LIMIT |
 *
 *   - CommandCode: 0x01
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VBAT_LO_ALERT_LIMIT "VBAT_LO_ALERT_LIMIT" : Signed number that sets a lower limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_lo_alert and can be read back and cleared at vbat_lo_alert.
*/

//!@{
#define LTC4162_VBAT_LO_ALERT_LIMIT_REG_SUBADDR 0x01u
#define LTC4162_VBAT_LO_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VBAT_LO_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VBAT_LO_ALERT_LIMIT VBAT_LO_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_LO_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets a lower limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_lo_alert and can be read back and cleared at vbat_lo_alert.
 *   - Register: @ref LTC4162_VBAT_LO_ALERT_LIMIT_REG "VBAT_LO_ALERT_LIMIT_REG"
 *   - CommandCode: 0x01
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_VBAT_FORMAT
 */
//!@{
#define LTC4162_VBAT_LO_ALERT_LIMIT_SUBADDR LTC4162_VBAT_LO_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_VBAT_LO_ALERT_LIMIT "VBAT_LO_ALERT_LIMIT"
#define LTC4162_VBAT_LO_ALERT_LIMIT_SIZE 16u
#define LTC4162_VBAT_LO_ALERT_LIMIT_OFFSET 0u
#define LTC4162_VBAT_LO_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_VBAT_LO_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_VBAT_LO_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_VBAT_LO_ALERT_LIMIT (LTC4162_VBAT_LO_ALERT_LIMIT_OFFSET << 12 | (LTC4162_VBAT_LO_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_VBAT_LO_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_VBAT_HI_ALERT_LIMIT_REG VBAT_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_HI_ALERT_LIMIT_REG Register
 *
 * |                15:0 |
 * |:-------------------:|
 * | VBAT_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x02
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VBAT_HI_ALERT_LIMIT "VBAT_HI_ALERT_LIMIT" : Signed number that sets an upper limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_hi_alert and can be read back and cleared at vbat_hi_alert.
*/

//!@{
#define LTC4162_VBAT_HI_ALERT_LIMIT_REG_SUBADDR 0x02u
#define LTC4162_VBAT_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VBAT_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VBAT_HI_ALERT_LIMIT VBAT_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_HI_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets an upper limit that can be used to trigger an interrupt based on the per-cell battery voltage out of range. The value is based on the A/D value, vbat, which has a scaling factor of cell_count × 192.4µV/LSB. To compute the per-cell bit count, divide the desired trigger voltage by both cell_count and 192.4µV. The alert is enabled by setting en_vbat_hi_alert and can be read back and cleared at vbat_hi_alert.
 *   - Register: @ref LTC4162_VBAT_HI_ALERT_LIMIT_REG "VBAT_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x02
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_VBAT_FORMAT
 */
//!@{
#define LTC4162_VBAT_HI_ALERT_LIMIT_SUBADDR LTC4162_VBAT_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_VBAT_HI_ALERT_LIMIT "VBAT_HI_ALERT_LIMIT"
#define LTC4162_VBAT_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_VBAT_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_VBAT_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_VBAT_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_VBAT_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_VBAT_HI_ALERT_LIMIT (LTC4162_VBAT_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_VBAT_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_VBAT_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_VIN_LO_ALERT_LIMIT_REG VIN_LO_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_LO_ALERT_LIMIT_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | VIN_LO_ALERT_LIMIT |
 *
 *   - CommandCode: 0x03
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VIN_LO_ALERT_LIMIT "VIN_LO_ALERT_LIMIT" : Signed number that sets a lower limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_lo_alert and can be read back and cleared at vin_lo_alert.
*/

//!@{
#define LTC4162_VIN_LO_ALERT_LIMIT_REG_SUBADDR 0x03u
#define LTC4162_VIN_LO_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VIN_LO_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_LO_ALERT_LIMIT VIN_LO_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_LO_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets a lower limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_lo_alert and can be read back and cleared at vin_lo_alert.
 *   - Register: @ref LTC4162_VIN_LO_ALERT_LIMIT_REG "VIN_LO_ALERT_LIMIT_REG"
 *   - CommandCode: 0x03
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_VIN_FORMAT
 */
//!@{
#define LTC4162_VIN_LO_ALERT_LIMIT_SUBADDR LTC4162_VIN_LO_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_VIN_LO_ALERT_LIMIT "VIN_LO_ALERT_LIMIT"
#define LTC4162_VIN_LO_ALERT_LIMIT_SIZE 16u
#define LTC4162_VIN_LO_ALERT_LIMIT_OFFSET 0u
#define LTC4162_VIN_LO_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_VIN_LO_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_VIN_LO_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_VIN_LO_ALERT_LIMIT (LTC4162_VIN_LO_ALERT_LIMIT_OFFSET << 12 | (LTC4162_VIN_LO_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_VIN_LO_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_VIN_HI_ALERT_LIMIT_REG VIN_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_HI_ALERT_LIMIT_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | VIN_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x04
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VIN_HI_ALERT_LIMIT "VIN_HI_ALERT_LIMIT" : Signed number that sets an upper limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_hi_alert and can be read back and cleared at vin_hi_alert.
*/

//!@{
#define LTC4162_VIN_HI_ALERT_LIMIT_REG_SUBADDR 0x04u
#define LTC4162_VIN_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VIN_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_HI_ALERT_LIMIT VIN_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_HI_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets an upper limit that can be used to trigger an interrupt based on input voltage out of range. The value is based on the A/D value, vin, which has a scaling factor of 1.649mV/LSB. The alert is enabled by setting en_vin_hi_alert and can be read back and cleared at vin_hi_alert.
 *   - Register: @ref LTC4162_VIN_HI_ALERT_LIMIT_REG "VIN_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x04
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_VIN_FORMAT
 */
//!@{
#define LTC4162_VIN_HI_ALERT_LIMIT_SUBADDR LTC4162_VIN_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_VIN_HI_ALERT_LIMIT "VIN_HI_ALERT_LIMIT"
#define LTC4162_VIN_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_VIN_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_VIN_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_VIN_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_VIN_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_VIN_HI_ALERT_LIMIT (LTC4162_VIN_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_VIN_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_VIN_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_VOUT_LO_ALERT_LIMIT_REG VOUT_LO_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_LO_ALERT_LIMIT_REG Register
 *
 * |                15:0 |
 * |:-------------------:|
 * | VOUT_LO_ALERT_LIMIT |
 *
 *   - CommandCode: 0x05
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VOUT_LO_ALERT_LIMIT "VOUT_LO_ALERT_LIMIT" : Signed number that sets a lower limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_lo_alert and can be read back and cleared at vout_lo_alert.
*/

//!@{
#define LTC4162_VOUT_LO_ALERT_LIMIT_REG_SUBADDR 0x05u
#define LTC4162_VOUT_LO_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VOUT_LO_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VOUT_LO_ALERT_LIMIT VOUT_LO_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_LO_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets a lower limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_lo_alert and can be read back and cleared at vout_lo_alert.
 *   - Register: @ref LTC4162_VOUT_LO_ALERT_LIMIT_REG "VOUT_LO_ALERT_LIMIT_REG"
 *   - CommandCode: 0x05
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_VOUT_FORMAT
 */
//!@{
#define LTC4162_VOUT_LO_ALERT_LIMIT_SUBADDR LTC4162_VOUT_LO_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_VOUT_LO_ALERT_LIMIT "VOUT_LO_ALERT_LIMIT"
#define LTC4162_VOUT_LO_ALERT_LIMIT_SIZE 16u
#define LTC4162_VOUT_LO_ALERT_LIMIT_OFFSET 0u
#define LTC4162_VOUT_LO_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_VOUT_LO_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_VOUT_LO_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_VOUT_LO_ALERT_LIMIT (LTC4162_VOUT_LO_ALERT_LIMIT_OFFSET << 12 | (LTC4162_VOUT_LO_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_VOUT_LO_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_VOUT_HI_ALERT_LIMIT_REG VOUT_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_HI_ALERT_LIMIT_REG Register
 *
 * |                15:0 |
 * |:-------------------:|
 * | VOUT_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x06
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VOUT_HI_ALERT_LIMIT "VOUT_HI_ALERT_LIMIT" : Signed number that sets an upper limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_hi_alert and can be read back and cleared at vout_hi_alert.
*/

//!@{
#define LTC4162_VOUT_HI_ALERT_LIMIT_REG_SUBADDR 0x06u
#define LTC4162_VOUT_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VOUT_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VOUT_HI_ALERT_LIMIT VOUT_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_HI_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets an upper limit that can be used to trigger an interrupt based on vout voltage out of range. The value is based on the A/D value, vout, which has a scaling factor of 1.653mV/LSB. The alert is enabled by setting en_vout_hi_alert and can be read back and cleared at vout_hi_alert.
 *   - Register: @ref LTC4162_VOUT_HI_ALERT_LIMIT_REG "VOUT_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x06
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_VOUT_FORMAT
 */
//!@{
#define LTC4162_VOUT_HI_ALERT_LIMIT_SUBADDR LTC4162_VOUT_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_VOUT_HI_ALERT_LIMIT "VOUT_HI_ALERT_LIMIT"
#define LTC4162_VOUT_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_VOUT_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_VOUT_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_VOUT_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_VOUT_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_VOUT_HI_ALERT_LIMIT (LTC4162_VOUT_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_VOUT_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_VOUT_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_IIN_HI_ALERT_LIMIT_REG IIN_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_HI_ALERT_LIMIT_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | IIN_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x07
 *   - Contains Bit Fields:
 *     + @ref LTC4162_IIN_HI_ALERT_LIMIT "IIN_HI_ALERT_LIMIT" : Signed number that sets an upper limit that can be used to trigger an interrupt based on input current out of range. The value is based on the A/D value, iin, which has a scaling factor of 1.466µV / RSNSI amperes/LSB. The alert is enabled by setting en_iin_hi_alert and can be read back and cleared at iin_hi_alert.
*/

//!@{
#define LTC4162_IIN_HI_ALERT_LIMIT_REG_SUBADDR 0x07u
#define LTC4162_IIN_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_IIN_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_IIN_HI_ALERT_LIMIT IIN_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_HI_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets an upper limit that can be used to trigger an interrupt based on input current out of range. The value is based on the A/D value, iin, which has a scaling factor of 1.466µV / RSNSI amperes/LSB. The alert is enabled by setting en_iin_hi_alert and can be read back and cleared at iin_hi_alert.
 *   - Register: @ref LTC4162_IIN_HI_ALERT_LIMIT_REG "IIN_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x07
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_IIN_FORMAT
 */
//!@{
#define LTC4162_IIN_HI_ALERT_LIMIT_SUBADDR LTC4162_IIN_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_IIN_HI_ALERT_LIMIT "IIN_HI_ALERT_LIMIT"
#define LTC4162_IIN_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_IIN_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_IIN_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_IIN_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_IIN_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_IIN_HI_ALERT_LIMIT (LTC4162_IIN_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_IIN_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_IIN_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_IBAT_LO_ALERT_LIMIT_REG IBAT_LO_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IBAT_LO_ALERT_LIMIT_REG Register
 *
 * |                15:0 |
 * |:-------------------:|
 * | IBAT_LO_ALERT_LIMIT |
 *
 *   - CommandCode: 0x08
 *   - Contains Bit Fields:
 *     + @ref LTC4162_IBAT_LO_ALERT_LIMIT "IBAT_LO_ALERT_LIMIT" : Signed number that sets a lower limit that can be used to trigger an interrupt based on charge current dropping below a particular value, such as during the constant-voltage phase of charging, or, load current exceeding a particular limit when not charging. When the charger is not running, and telemetry is enabled with force_telemetry_on, this limit indicates that the battery draw has exceeded a particular value. Telemetry will be enabled automatically if the input voltage exceeds the battery voltage, in which case discharge current will be nearly zero. ibat values are positive for charging and negative for discharging so the polarity of this register should be set according to the mode in which the limit alert is of interest. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. The alert is enabled by setting en_ibat_lo_alert and can be read back and cleared at ibat_lo_alert.
*/

//!@{
#define LTC4162_IBAT_LO_ALERT_LIMIT_REG_SUBADDR 0x08u
#define LTC4162_IBAT_LO_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_IBAT_LO_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_IBAT_LO_ALERT_LIMIT IBAT_LO_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IBAT_LO_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets a lower limit that can be used to trigger an interrupt based on charge current dropping below a particular value, such as during the constant-voltage phase of charging, or, load current exceeding a particular limit when not charging. When the charger is not running, and telemetry is enabled with force_telemetry_on, this limit indicates that the battery draw has exceeded a particular value. Telemetry will be enabled automatically if the input voltage exceeds the battery voltage, in which case discharge current will be nearly zero. ibat values are positive for charging and negative for discharging so the polarity of this register should be set according to the mode in which the limit alert is of interest. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. The alert is enabled by setting en_ibat_lo_alert and can be read back and cleared at ibat_lo_alert.
 *   - Register: @ref LTC4162_IBAT_LO_ALERT_LIMIT_REG "IBAT_LO_ALERT_LIMIT_REG"
 *   - CommandCode: 0x08
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_IBAT_FORMAT
 */
//!@{
#define LTC4162_IBAT_LO_ALERT_LIMIT_SUBADDR LTC4162_IBAT_LO_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_IBAT_LO_ALERT_LIMIT "IBAT_LO_ALERT_LIMIT"
#define LTC4162_IBAT_LO_ALERT_LIMIT_SIZE 16u
#define LTC4162_IBAT_LO_ALERT_LIMIT_OFFSET 0u
#define LTC4162_IBAT_LO_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_IBAT_LO_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_IBAT_LO_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_IBAT_LO_ALERT_LIMIT (LTC4162_IBAT_LO_ALERT_LIMIT_OFFSET << 12 | (LTC4162_IBAT_LO_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_IBAT_LO_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG DIE_TEMP_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief DIE_TEMP_HI_ALERT_LIMIT_REG Register
 *
 * |                    15:0 |
 * |:-----------------------:|
 * | DIE_TEMP_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x09
 *   - Contains Bit Fields:
 *     + @ref LTC4162_DIE_TEMP_HI_ALERT_LIMIT "DIE_TEMP_HI_ALERT_LIMIT" : Signed number that sets an upper limit that can be used to trigger an interrupt based on high die temperature. The value in °C can be calculated from the A/D reading, die_temp, as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C. The alert is enabled by setting en_die_temp_hi_alert and can be read back and cleared at die_temp_hi_alert.
*/

//!@{
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG_SUBADDR 0x09u
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_DIE_TEMP_HI_ALERT_LIMIT DIE_TEMP_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief DIE_TEMP_HI_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets an upper limit that can be used to trigger an interrupt based on high die temperature. The value in °C can be calculated from the A/D reading, die_temp, as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C. The alert is enabled by setting en_die_temp_hi_alert and can be read back and cleared at die_temp_hi_alert.
 *   - Register: @ref LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG "DIE_TEMP_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x09
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_DIE_TEMP_FORMAT
 */
//!@{
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_SUBADDR LTC4162_DIE_TEMP_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_DIE_TEMP_HI_ALERT_LIMIT "DIE_TEMP_HI_ALERT_LIMIT"
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_DIE_TEMP_HI_ALERT_LIMIT (LTC4162_DIE_TEMP_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_DIE_TEMP_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_DIE_TEMP_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_BSR_HI_ALERT_LIMIT_REG BSR_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_HI_ALERT_LIMIT_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | BSR_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x0A
 *   - Contains Bit Fields:
 *     + @ref LTC4162_BSR_HI_ALERT_LIMIT "BSR_HI_ALERT_LIMIT" : Sets an upper limit that can be used to trigger an interrupt based on high battery resistance. The per-cell battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from: BSR = cell_count × bsr × RSNSB / 500. The alert is enabled by setting en_bsr_hi_alert and can be read back and cleared at bsr_hi_alert.
*/

//!@{
#define LTC4162_BSR_HI_ALERT_LIMIT_REG_SUBADDR 0x0Au
#define LTC4162_BSR_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_BSR_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_BSR_HI_ALERT_LIMIT BSR_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_HI_ALERT_LIMIT Bit Field
 *
 *  Sets an upper limit that can be used to trigger an interrupt based on high battery resistance. The per-cell battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from: BSR = cell_count × bsr × RSNSB / 500. The alert is enabled by setting en_bsr_hi_alert and can be read back and cleared at bsr_hi_alert.
 *   - Register: @ref LTC4162_BSR_HI_ALERT_LIMIT_REG "BSR_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x0A
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_BSR_FORMAT
 */
//!@{
#define LTC4162_BSR_HI_ALERT_LIMIT_SUBADDR LTC4162_BSR_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_BSR_HI_ALERT_LIMIT "BSR_HI_ALERT_LIMIT"
#define LTC4162_BSR_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_BSR_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_BSR_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_BSR_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_BSR_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_BSR_HI_ALERT_LIMIT (LTC4162_BSR_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_BSR_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_BSR_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG Register
 *
 * |                              15:0 |
 * |:---------------------------------:|
 * | THERMISTOR_VOLTAGE_HI_ALERT_LIMIT |
 *
 *   - CommandCode: 0x0B
 *   - Contains Bit Fields:
 *     + @ref LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT "THERMISTOR_VOLTAGE_HI_ALERT_LIMIT" : Signed number that sets an upper limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_hi_alert can be read back and cleared at thermistor_voltage_hi_alert.
*/

//!@{
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG_SUBADDR 0x0Bu
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT THERMISTOR_VOLTAGE_HI_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_HI_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets an upper limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_hi_alert can be read back and cleared at thermistor_voltage_hi_alert.
 *   - Register: @ref LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG "THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG"
 *   - CommandCode: 0x0B
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_SUBADDR LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT "THERMISTOR_VOLTAGE_HI_ALERT_LIMIT"
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_SIZE 16u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_OFFSET 0u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT (LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_OFFSET << 12 | (LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG Register
 *
 * |                              15:0 |
 * |:---------------------------------:|
 * | THERMISTOR_VOLTAGE_LO_ALERT_LIMIT |
 *
 *   - CommandCode: 0x0C
 *   - Contains Bit Fields:
 *     + @ref LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT "THERMISTOR_VOLTAGE_LO_ALERT_LIMIT" : Signed number that sets a lower limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_lo_alert and can be read back and cleared at thermistor_voltage_lo_alert.
*/

//!@{
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG_SUBADDR 0x0Cu
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT THERMISTOR_VOLTAGE_LO_ALERT_LIMIT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_LO_ALERT_LIMIT Bit Field
 *
 *  Signed number that sets a lower limit that can be used to trigger an interrupt based on thermistor value out of range. The value is based on the A/D value for thermistor_voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so higher temperatures correspond to lower thermistor_voltage readings and vice-versa. The alert is enabled by setting en_thermistor_voltage_lo_alert and can be read back and cleared at thermistor_voltage_lo_alert.
 *   - Register: @ref LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG "THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG"
 *   - CommandCode: 0x0C
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_SUBADDR LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_REG_SUBADDR //!< @ref LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT "THERMISTOR_VOLTAGE_LO_ALERT_LIMIT"
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_SIZE 16u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_OFFSET 0u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_MASK 0xFFFFu
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_DEFAULT 0u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_DECODE(register_data) (register_data)
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT (LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_OFFSET << 12 | (LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_LIMIT_SUBADDR)
//!@}

/*! @defgroup LTC4162_EN_LIMIT_ALERTS_REG EN_LIMIT_ALERTS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_LIMIT_ALERTS_REG Register
 *
 * |                       15 |                14 | 13:12 |               11 |               10 |               9 |               8 |                7 |                6 |               5 |                4 |                    3 |               2 |                              1 |                              0 |
 * |:------------------------:|:-----------------:|:-----:|:----------------:|:----------------:|:---------------:|:---------------:|:----------------:|:----------------:|:---------------:|:----------------:|:--------------------:|:---------------:|:------------------------------:|:------------------------------:|
 * | EN_TELEMETRY_VALID_ALERT | EN_BSR_DONE_ALERT |   n/a | EN_VBAT_LO_ALERT | EN_VBAT_HI_ALERT | EN_VIN_LO_ALERT | EN_VIN_HI_ALERT | EN_VOUT_LO_ALERT | EN_VOUT_HI_ALERT | EN_IIN_HI_ALERT | EN_IBAT_LO_ALERT | EN_DIE_TEMP_HI_ALERT | EN_BSR_HI_ALERT | EN_THERMISTOR_VOLTAGE_HI_ALERT | EN_THERMISTOR_VOLTAGE_LO_ALERT |
 *
 * Enable limit monitoring and alert notification via SMBALERT
 *   - CommandCode: 0x0D
 *   - Contains Bit Fields:
 *     + @ref LTC4162_EN_TELEMETRY_VALID_ALERT "EN_TELEMETRY_VALID_ALERT" : To ensure high measurement accuracy, the telemetry system in the LTC4162 has a nominal start-up time of approximately 12ms. Setting this interrupt request causes an SMBALERT telemetry_valid_alert when telemetry_valid indicates that the telemetry system's readings are valid. Note that the switching battery charger will not operate until this telemetry system warmup period has passed, regardless of the state of this setting.
 *     + @ref LTC4162_EN_BSR_DONE_ALERT "EN_BSR_DONE_ALERT" : Interrupt request that causes an SMBALERT upon bsr_done_alert when the bsr (battery-series-resistance) measurement is finished.
 *     + @ref LTC4162_EN_VBAT_LO_ALERT "EN_VBAT_LO_ALERT" : Interrupt request that causes an SMBALERT upon vbat_lo_alert when vbat is below vbat_lo_alert_limit.
 *     + @ref LTC4162_EN_VBAT_HI_ALERT "EN_VBAT_HI_ALERT" : Interrupt request that causes an SMBALERT upon vbat_hi_alert when vbat is above vbat_hi_alert_limit.
 *     + @ref LTC4162_EN_VIN_LO_ALERT "EN_VIN_LO_ALERT" : Interrupt request that causes an SMBALERT upon vin_lo_alert when vin is below vin_lo_alert_limit.
 *     + @ref LTC4162_EN_VIN_HI_ALERT "EN_VIN_HI_ALERT" : Interrupt request that causes an SMBALERT upon vin_hi_alert when vin is above vin_hi_alert_limit.
 *     + @ref LTC4162_EN_VOUT_LO_ALERT "EN_VOUT_LO_ALERT" : Interrupt request that causes an SMBALERT upon vout_lo_alert when vout is below vout_lo_alert_limit.
 *     + @ref LTC4162_EN_VOUT_HI_ALERT "EN_VOUT_HI_ALERT" : Interrupt request that causes an SMBALERT upon vout_hi_alert when vout is above vout_hi_alert_limit.
 *     + @ref LTC4162_EN_IIN_HI_ALERT "EN_IIN_HI_ALERT" : Interrupt request that causes an SMBALERT upon iin_hi_alert when iin is above iin_hi_alert_limit.
 *     + @ref LTC4162_EN_IBAT_LO_ALERT "EN_IBAT_LO_ALERT" : Interrupt request that causes an SMBALERT upon ibat_lo_alert when ibat is below ibat_lo_alert_limit.
 *     + @ref LTC4162_EN_DIE_TEMP_HI_ALERT "EN_DIE_TEMP_HI_ALERT" : Interrupt request that causes an SMBALERT upon die_temp_hi_alert when die_temp is above die_temp_hi_alert_limit.
 *     + @ref LTC4162_EN_BSR_HI_ALERT "EN_BSR_HI_ALERT" : Interrupt request that causes an SMBALERT upon bsr_hi_alert when bsr is above bsr_hi_alert_limit.
 *     + @ref LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT "EN_THERMISTOR_VOLTAGE_HI_ALERT" : Interrupt request that causes an SMBALERT upon thermistor_voltage_hi_alert when thermistor_voltage is above thermistor_voltage_hi_alert_limit. Recall that the thermistor has a negative temperature coefficient so higher thermistor_voltage readings correspond to lower temperatures.
 *     + @ref LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT "EN_THERMISTOR_VOLTAGE_LO_ALERT" : Interrupt request that causes an SMBALERT upon thermistor_voltage_lo_alert when thermistor_voltage is below thermistor_voltage_lo_alert_limit. Recall that the thermistor has a negative temperature coefficient so lower thermistor_voltage readings correspond to higher temperatures.
*/

//!@{
#define LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR 0x0Du
#define LTC4162_EN_LIMIT_ALERTS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_TELEMETRY_VALID_ALERT EN_TELEMETRY_VALID_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_TELEMETRY_VALID_ALERT Bit Field
 *
 *  To ensure high measurement accuracy, the telemetry system in the LTC4162 has a nominal start-up time of approximately 12ms. Setting this interrupt request causes an SMBALERT telemetry_valid_alert when telemetry_valid indicates that the telemetry system's readings are valid. Note that the switching battery charger will not operate until this telemetry system warmup period has passed, regardless of the state of this setting.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 15
 *   - MSB: 15
 *   - MASK: 0x8000
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_TELEMETRY_VALID_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_TELEMETRY_VALID_ALERT "EN_TELEMETRY_VALID_ALERT"
#define LTC4162_EN_TELEMETRY_VALID_ALERT_SIZE 1u
#define LTC4162_EN_TELEMETRY_VALID_ALERT_OFFSET 15u
#define LTC4162_EN_TELEMETRY_VALID_ALERT_MASK 0x8000u
#define LTC4162_EN_TELEMETRY_VALID_ALERT_DEFAULT 0u
#define LTC4162_EN_TELEMETRY_VALID_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_TELEMETRY_VALID_ALERT_MASK) >> LTC4162_EN_TELEMETRY_VALID_ALERT_OFFSET)
#define LTC4162_EN_TELEMETRY_VALID_ALERT (LTC4162_EN_TELEMETRY_VALID_ALERT_OFFSET << 12 | (LTC4162_EN_TELEMETRY_VALID_ALERT_SIZE - 1) << 8 | LTC4162_EN_TELEMETRY_VALID_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_BSR_DONE_ALERT EN_BSR_DONE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_BSR_DONE_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon bsr_done_alert when the bsr (battery-series-resistance) measurement is finished.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 14
 *   - MSB: 14
 *   - MASK: 0x4000
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_BSR_DONE_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_BSR_DONE_ALERT "EN_BSR_DONE_ALERT"
#define LTC4162_EN_BSR_DONE_ALERT_SIZE 1u
#define LTC4162_EN_BSR_DONE_ALERT_OFFSET 14u
#define LTC4162_EN_BSR_DONE_ALERT_MASK 0x4000u
#define LTC4162_EN_BSR_DONE_ALERT_DEFAULT 0u
#define LTC4162_EN_BSR_DONE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_BSR_DONE_ALERT_MASK) >> LTC4162_EN_BSR_DONE_ALERT_OFFSET)
#define LTC4162_EN_BSR_DONE_ALERT (LTC4162_EN_BSR_DONE_ALERT_OFFSET << 12 | (LTC4162_EN_BSR_DONE_ALERT_SIZE - 1) << 8 | LTC4162_EN_BSR_DONE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VBAT_LO_ALERT EN_VBAT_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VBAT_LO_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon vbat_lo_alert when vbat is below vbat_lo_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 11
 *   - MSB: 11
 *   - MASK: 0x0800
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VBAT_LO_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VBAT_LO_ALERT "EN_VBAT_LO_ALERT"
#define LTC4162_EN_VBAT_LO_ALERT_SIZE 1u
#define LTC4162_EN_VBAT_LO_ALERT_OFFSET 11u
#define LTC4162_EN_VBAT_LO_ALERT_MASK 0x0800u
#define LTC4162_EN_VBAT_LO_ALERT_DEFAULT 0u
#define LTC4162_EN_VBAT_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VBAT_LO_ALERT_MASK) >> LTC4162_EN_VBAT_LO_ALERT_OFFSET)
#define LTC4162_EN_VBAT_LO_ALERT (LTC4162_EN_VBAT_LO_ALERT_OFFSET << 12 | (LTC4162_EN_VBAT_LO_ALERT_SIZE - 1) << 8 | LTC4162_EN_VBAT_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VBAT_HI_ALERT EN_VBAT_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VBAT_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon vbat_hi_alert when vbat is above vbat_hi_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 10
 *   - MSB: 10
 *   - MASK: 0x0400
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VBAT_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VBAT_HI_ALERT "EN_VBAT_HI_ALERT"
#define LTC4162_EN_VBAT_HI_ALERT_SIZE 1u
#define LTC4162_EN_VBAT_HI_ALERT_OFFSET 10u
#define LTC4162_EN_VBAT_HI_ALERT_MASK 0x0400u
#define LTC4162_EN_VBAT_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_VBAT_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VBAT_HI_ALERT_MASK) >> LTC4162_EN_VBAT_HI_ALERT_OFFSET)
#define LTC4162_EN_VBAT_HI_ALERT (LTC4162_EN_VBAT_HI_ALERT_OFFSET << 12 | (LTC4162_EN_VBAT_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_VBAT_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VIN_LO_ALERT EN_VIN_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VIN_LO_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon vin_lo_alert when vin is below vin_lo_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 9
 *   - MSB: 9
 *   - MASK: 0x0200
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VIN_LO_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VIN_LO_ALERT "EN_VIN_LO_ALERT"
#define LTC4162_EN_VIN_LO_ALERT_SIZE 1u
#define LTC4162_EN_VIN_LO_ALERT_OFFSET 9u
#define LTC4162_EN_VIN_LO_ALERT_MASK 0x0200u
#define LTC4162_EN_VIN_LO_ALERT_DEFAULT 0u
#define LTC4162_EN_VIN_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VIN_LO_ALERT_MASK) >> LTC4162_EN_VIN_LO_ALERT_OFFSET)
#define LTC4162_EN_VIN_LO_ALERT (LTC4162_EN_VIN_LO_ALERT_OFFSET << 12 | (LTC4162_EN_VIN_LO_ALERT_SIZE - 1) << 8 | LTC4162_EN_VIN_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VIN_HI_ALERT EN_VIN_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VIN_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon vin_hi_alert when vin is above vin_hi_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 8
 *   - MSB: 8
 *   - MASK: 0x0100
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VIN_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VIN_HI_ALERT "EN_VIN_HI_ALERT"
#define LTC4162_EN_VIN_HI_ALERT_SIZE 1u
#define LTC4162_EN_VIN_HI_ALERT_OFFSET 8u
#define LTC4162_EN_VIN_HI_ALERT_MASK 0x0100u
#define LTC4162_EN_VIN_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_VIN_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VIN_HI_ALERT_MASK) >> LTC4162_EN_VIN_HI_ALERT_OFFSET)
#define LTC4162_EN_VIN_HI_ALERT (LTC4162_EN_VIN_HI_ALERT_OFFSET << 12 | (LTC4162_EN_VIN_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_VIN_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VOUT_LO_ALERT EN_VOUT_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VOUT_LO_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon vout_lo_alert when vout is below vout_lo_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 7
 *   - MSB: 7
 *   - MASK: 0x0080
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VOUT_LO_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VOUT_LO_ALERT "EN_VOUT_LO_ALERT"
#define LTC4162_EN_VOUT_LO_ALERT_SIZE 1u
#define LTC4162_EN_VOUT_LO_ALERT_OFFSET 7u
#define LTC4162_EN_VOUT_LO_ALERT_MASK 0x0080u
#define LTC4162_EN_VOUT_LO_ALERT_DEFAULT 0u
#define LTC4162_EN_VOUT_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VOUT_LO_ALERT_MASK) >> LTC4162_EN_VOUT_LO_ALERT_OFFSET)
#define LTC4162_EN_VOUT_LO_ALERT (LTC4162_EN_VOUT_LO_ALERT_OFFSET << 12 | (LTC4162_EN_VOUT_LO_ALERT_SIZE - 1) << 8 | LTC4162_EN_VOUT_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VOUT_HI_ALERT EN_VOUT_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VOUT_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon vout_hi_alert when vout is above vout_hi_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 6
 *   - MSB: 6
 *   - MASK: 0x0040
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VOUT_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VOUT_HI_ALERT "EN_VOUT_HI_ALERT"
#define LTC4162_EN_VOUT_HI_ALERT_SIZE 1u
#define LTC4162_EN_VOUT_HI_ALERT_OFFSET 6u
#define LTC4162_EN_VOUT_HI_ALERT_MASK 0x0040u
#define LTC4162_EN_VOUT_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_VOUT_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VOUT_HI_ALERT_MASK) >> LTC4162_EN_VOUT_HI_ALERT_OFFSET)
#define LTC4162_EN_VOUT_HI_ALERT (LTC4162_EN_VOUT_HI_ALERT_OFFSET << 12 | (LTC4162_EN_VOUT_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_VOUT_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_IIN_HI_ALERT EN_IIN_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_IIN_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon iin_hi_alert when iin is above iin_hi_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_IIN_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_IIN_HI_ALERT "EN_IIN_HI_ALERT"
#define LTC4162_EN_IIN_HI_ALERT_SIZE 1u
#define LTC4162_EN_IIN_HI_ALERT_OFFSET 5u
#define LTC4162_EN_IIN_HI_ALERT_MASK 0x0020u
#define LTC4162_EN_IIN_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_IIN_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_IIN_HI_ALERT_MASK) >> LTC4162_EN_IIN_HI_ALERT_OFFSET)
#define LTC4162_EN_IIN_HI_ALERT (LTC4162_EN_IIN_HI_ALERT_OFFSET << 12 | (LTC4162_EN_IIN_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_IIN_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_IBAT_LO_ALERT EN_IBAT_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_IBAT_LO_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon ibat_lo_alert when ibat is below ibat_lo_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_IBAT_LO_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_IBAT_LO_ALERT "EN_IBAT_LO_ALERT"
#define LTC4162_EN_IBAT_LO_ALERT_SIZE 1u
#define LTC4162_EN_IBAT_LO_ALERT_OFFSET 4u
#define LTC4162_EN_IBAT_LO_ALERT_MASK 0x0010u
#define LTC4162_EN_IBAT_LO_ALERT_DEFAULT 0u
#define LTC4162_EN_IBAT_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_IBAT_LO_ALERT_MASK) >> LTC4162_EN_IBAT_LO_ALERT_OFFSET)
#define LTC4162_EN_IBAT_LO_ALERT (LTC4162_EN_IBAT_LO_ALERT_OFFSET << 12 | (LTC4162_EN_IBAT_LO_ALERT_SIZE - 1) << 8 | LTC4162_EN_IBAT_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_DIE_TEMP_HI_ALERT EN_DIE_TEMP_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_DIE_TEMP_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon die_temp_hi_alert when die_temp is above die_temp_hi_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_DIE_TEMP_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_DIE_TEMP_HI_ALERT "EN_DIE_TEMP_HI_ALERT"
#define LTC4162_EN_DIE_TEMP_HI_ALERT_SIZE 1u
#define LTC4162_EN_DIE_TEMP_HI_ALERT_OFFSET 3u
#define LTC4162_EN_DIE_TEMP_HI_ALERT_MASK 0x0008u
#define LTC4162_EN_DIE_TEMP_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_DIE_TEMP_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_DIE_TEMP_HI_ALERT_MASK) >> LTC4162_EN_DIE_TEMP_HI_ALERT_OFFSET)
#define LTC4162_EN_DIE_TEMP_HI_ALERT (LTC4162_EN_DIE_TEMP_HI_ALERT_OFFSET << 12 | (LTC4162_EN_DIE_TEMP_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_DIE_TEMP_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_BSR_HI_ALERT EN_BSR_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_BSR_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon bsr_hi_alert when bsr is above bsr_hi_alert_limit.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_BSR_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_BSR_HI_ALERT "EN_BSR_HI_ALERT"
#define LTC4162_EN_BSR_HI_ALERT_SIZE 1u
#define LTC4162_EN_BSR_HI_ALERT_OFFSET 2u
#define LTC4162_EN_BSR_HI_ALERT_MASK 0x0004u
#define LTC4162_EN_BSR_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_BSR_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_BSR_HI_ALERT_MASK) >> LTC4162_EN_BSR_HI_ALERT_OFFSET)
#define LTC4162_EN_BSR_HI_ALERT (LTC4162_EN_BSR_HI_ALERT_OFFSET << 12 | (LTC4162_EN_BSR_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_BSR_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT EN_THERMISTOR_VOLTAGE_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_THERMISTOR_VOLTAGE_HI_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon thermistor_voltage_hi_alert when thermistor_voltage is above thermistor_voltage_hi_alert_limit. Recall that the thermistor has a negative temperature coefficient so higher thermistor_voltage readings correspond to lower temperatures.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT "EN_THERMISTOR_VOLTAGE_HI_ALERT"
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_SIZE 1u
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET 1u
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_MASK 0x0002u
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_DEFAULT 0u
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_MASK) >> LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET)
#define LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT (LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET << 12 | (LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_SIZE - 1) << 8 | LTC4162_EN_THERMISTOR_VOLTAGE_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT EN_THERMISTOR_VOLTAGE_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_THERMISTOR_VOLTAGE_LO_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon thermistor_voltage_lo_alert when thermistor_voltage is below thermistor_voltage_lo_alert_limit. Recall that the thermistor has a negative temperature coefficient so lower thermistor_voltage readings correspond to higher temperatures.
 *   - Register: @ref LTC4162_EN_LIMIT_ALERTS_REG "EN_LIMIT_ALERTS_REG"
 *   - CommandCode: 0x0D
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_SUBADDR LTC4162_EN_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT "EN_THERMISTOR_VOLTAGE_LO_ALERT"
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_SIZE 1u
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET 0u
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_MASK 0x0001u
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_DEFAULT 0u
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_MASK) >> LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET)
#define LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT (LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET << 12 | (LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_SIZE - 1) << 8 | LTC4162_EN_THERMISTOR_VOLTAGE_LO_ALERT_SUBADDR)
//!@}

/*! @defgroup LTC4162_EN_CHARGER_STATE_ALERTS_REG EN_CHARGER_STATE_ALERTS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CHARGER_STATE_ALERTS_REG Register
 *
 * | 15:13 |                               12 |                         11 | 10:9 |                          8 |                  7 |                     6 |                  5 |                   4 |                      3 |                        2 |                          1 |                        0 |
 * |:-----:|:--------------------------------:|:--------------------------:|:----:|:--------------------------:|:------------------:|:---------------------:|:------------------:|:-------------------:|:----------------------:|:------------------------:|:--------------------------:|:------------------------:|
 * |   n/a | EN_BAT_DETECT_FAILED_FAULT_ALERT | EN_BATTERY_DETECTION_ALERT |  n/a | EN_CHARGER_SUSPENDED_ALERT | EN_PRECHARGE_ALERT | EN_CC_CV_CHARGE_ALERT | EN_NTC_PAUSE_ALERT | EN_TIMER_TERM_ALERT | EN_C_OVER_X_TERM_ALERT | EN_MAX_CHARGE_TIME_ALERT | EN_BAT_MISSING_FAULT_ALERT | EN_BAT_SHORT_FAULT_ALERT |
 *
 * Enable charger state notification via SMBALERT
 *   - CommandCode: 0x0E
 *   - Contains Bit Fields:
 *     + @ref LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT "EN_BAT_DETECT_FAILED_FAULT_ALERT" : Interrupt request that causes an SMBALERT upon bat_detect_failed_fault_alert as indicated by bat_detect_failed_fault due to an inability to source power to the battery during battery detection testing (usually due to either iin_limit_active or vin_uvcl_active).
 *     + @ref LTC4162_EN_BATTERY_DETECTION_ALERT "EN_BATTERY_DETECTION_ALERT" : Interrupt request that causes an SMBALERT upon battery_detection_alert as indicated by battery_detection due to the LTC4162 entering battery detection testing.
 *     + @ref LTC4162_EN_CHARGER_SUSPENDED_ALERT "EN_CHARGER_SUSPENDED_ALERT" : Interrupt request that causes an SMBALERT upon charger_suspended_alert as indicated by charger_suspended whereby battery charging is terminated due to suspend_charger or thermistor_voltage out of jeita_t1 - jeita_t6 range.
 *     + @ref LTC4162_EN_PRECHARGE_ALERT "EN_PRECHARGE_ALERT" : Interrupt request that causes an SMBALERT upon precharge_alert as indicated by precharge denoting the onset of the precharge phase of a battery charging cycle.
 *     + @ref LTC4162_EN_CC_CV_CHARGE_ALERT "EN_CC_CV_CHARGE_ALERT" : Interrupt request that causes an SMBALERT upon cc_cv_charge_alert as indicated by cc_cv_charge denoting the onset of the constant current / constant voltage phase of a battery charging cycle.
 *     + @ref LTC4162_EN_NTC_PAUSE_ALERT "EN_NTC_PAUSE_ALERT" : Interrupt request that causes an SMBALERT upon ntc_pause_alert as indicated by ntc_pause whereby a battery charge cycle is interrupted due to thermistor_voltage out of range as set by the jeita_t1 through jeita_t6 values.
 *     + @ref LTC4162_EN_TIMER_TERM_ALERT "EN_TIMER_TERM_ALERT" : Interrupt request that causes an SMBALERT upon timer_term_alert as indicated by timer_term whereby a battery charge cycle terminates due to tcvtimer reaching max_cv_time, the maximum time allowed in constant_voltage mode.
 *     + @ref LTC4162_EN_C_OVER_X_TERM_ALERT "EN_C_OVER_X_TERM_ALERT" : Interrupt request that causes an SMBALERT upon c_over_x_term_alert as indicated by c_over_x_term whereby a battery charge cycle terminates due to ibat dropping below the c_over_x_threshold.
 *     + @ref LTC4162_EN_MAX_CHARGE_TIME_ALERT "EN_MAX_CHARGE_TIME_ALERT" : Interrupt request that causes an SMBALERT upon max_charge_time_fault_alert as indicated by max_charge_time_fault whereby charging has terminated due to tchargetimer reaching max_charge_time.
 *     + @ref LTC4162_EN_BAT_MISSING_FAULT_ALERT "EN_BAT_MISSING_FAULT_ALERT" : Interrupt request that causes an SMBALERT upon bat_missing_fault_alert as indicated by bat_missing_fault whereby charging is prohibited if no battery is detected during the battery presence detection phase at the beginning of a charge cycle.
 *     + @ref LTC4162_EN_BAT_SHORT_FAULT_ALERT "EN_BAT_SHORT_FAULT_ALERT" : Interrupt request that causes an SMBALERT upon bat_short_fault_alert as indicated by bat_short_fault whereby charging is prohibited if a shorted battery is detected during the battery presence detection phase at the beginning of a charge cycle.
*/

//!@{
#define LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR 0x0Eu
#define LTC4162_EN_CHARGER_STATE_ALERTS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT EN_BAT_DETECT_FAILED_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_BAT_DETECT_FAILED_FAULT_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon bat_detect_failed_fault_alert as indicated by bat_detect_failed_fault due to an inability to source power to the battery during battery detection testing (usually due to either iin_limit_active or vin_uvcl_active).
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 12
 *   - MSB: 12
 *   - MASK: 0x1000
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT "EN_BAT_DETECT_FAILED_FAULT_ALERT"
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_SIZE 1u
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET 12u
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_MASK 0x1000u
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_DEFAULT 0u
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_MASK) >> LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET)
#define LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT (LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET << 12 | (LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_EN_BAT_DETECT_FAILED_FAULT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_BATTERY_DETECTION_ALERT EN_BATTERY_DETECTION_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_BATTERY_DETECTION_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon battery_detection_alert as indicated by battery_detection due to the LTC4162 entering battery detection testing.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 11
 *   - MSB: 11
 *   - MASK: 0x0800
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_BATTERY_DETECTION_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_BATTERY_DETECTION_ALERT "EN_BATTERY_DETECTION_ALERT"
#define LTC4162_EN_BATTERY_DETECTION_ALERT_SIZE 1u
#define LTC4162_EN_BATTERY_DETECTION_ALERT_OFFSET 11u
#define LTC4162_EN_BATTERY_DETECTION_ALERT_MASK 0x0800u
#define LTC4162_EN_BATTERY_DETECTION_ALERT_DEFAULT 0u
#define LTC4162_EN_BATTERY_DETECTION_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_BATTERY_DETECTION_ALERT_MASK) >> LTC4162_EN_BATTERY_DETECTION_ALERT_OFFSET)
#define LTC4162_EN_BATTERY_DETECTION_ALERT (LTC4162_EN_BATTERY_DETECTION_ALERT_OFFSET << 12 | (LTC4162_EN_BATTERY_DETECTION_ALERT_SIZE - 1) << 8 | LTC4162_EN_BATTERY_DETECTION_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_CHARGER_SUSPENDED_ALERT EN_CHARGER_SUSPENDED_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CHARGER_SUSPENDED_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon charger_suspended_alert as indicated by charger_suspended whereby battery charging is terminated due to suspend_charger or thermistor_voltage out of jeita_t1 - jeita_t6 range.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 8
 *   - MSB: 8
 *   - MASK: 0x0100
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_CHARGER_SUSPENDED_ALERT "EN_CHARGER_SUSPENDED_ALERT"
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT_SIZE 1u
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT_OFFSET 8u
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT_MASK 0x0100u
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT_DEFAULT 0u
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_CHARGER_SUSPENDED_ALERT_MASK) >> LTC4162_EN_CHARGER_SUSPENDED_ALERT_OFFSET)
#define LTC4162_EN_CHARGER_SUSPENDED_ALERT (LTC4162_EN_CHARGER_SUSPENDED_ALERT_OFFSET << 12 | (LTC4162_EN_CHARGER_SUSPENDED_ALERT_SIZE - 1) << 8 | LTC4162_EN_CHARGER_SUSPENDED_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_PRECHARGE_ALERT EN_PRECHARGE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_PRECHARGE_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon precharge_alert as indicated by precharge denoting the onset of the precharge phase of a battery charging cycle.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 7
 *   - MSB: 7
 *   - MASK: 0x0080
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_PRECHARGE_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_PRECHARGE_ALERT "EN_PRECHARGE_ALERT"
#define LTC4162_EN_PRECHARGE_ALERT_SIZE 1u
#define LTC4162_EN_PRECHARGE_ALERT_OFFSET 7u
#define LTC4162_EN_PRECHARGE_ALERT_MASK 0x0080u
#define LTC4162_EN_PRECHARGE_ALERT_DEFAULT 0u
#define LTC4162_EN_PRECHARGE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_PRECHARGE_ALERT_MASK) >> LTC4162_EN_PRECHARGE_ALERT_OFFSET)
#define LTC4162_EN_PRECHARGE_ALERT (LTC4162_EN_PRECHARGE_ALERT_OFFSET << 12 | (LTC4162_EN_PRECHARGE_ALERT_SIZE - 1) << 8 | LTC4162_EN_PRECHARGE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_CC_CV_CHARGE_ALERT EN_CC_CV_CHARGE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CC_CV_CHARGE_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon cc_cv_charge_alert as indicated by cc_cv_charge denoting the onset of the constant current / constant voltage phase of a battery charging cycle.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 6
 *   - MSB: 6
 *   - MASK: 0x0040
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_CC_CV_CHARGE_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_CC_CV_CHARGE_ALERT "EN_CC_CV_CHARGE_ALERT"
#define LTC4162_EN_CC_CV_CHARGE_ALERT_SIZE 1u
#define LTC4162_EN_CC_CV_CHARGE_ALERT_OFFSET 6u
#define LTC4162_EN_CC_CV_CHARGE_ALERT_MASK 0x0040u
#define LTC4162_EN_CC_CV_CHARGE_ALERT_DEFAULT 0u
#define LTC4162_EN_CC_CV_CHARGE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_CC_CV_CHARGE_ALERT_MASK) >> LTC4162_EN_CC_CV_CHARGE_ALERT_OFFSET)
#define LTC4162_EN_CC_CV_CHARGE_ALERT (LTC4162_EN_CC_CV_CHARGE_ALERT_OFFSET << 12 | (LTC4162_EN_CC_CV_CHARGE_ALERT_SIZE - 1) << 8 | LTC4162_EN_CC_CV_CHARGE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_NTC_PAUSE_ALERT EN_NTC_PAUSE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_NTC_PAUSE_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon ntc_pause_alert as indicated by ntc_pause whereby a battery charge cycle is interrupted due to thermistor_voltage out of range as set by the jeita_t1 through jeita_t6 values.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_NTC_PAUSE_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_NTC_PAUSE_ALERT "EN_NTC_PAUSE_ALERT"
#define LTC4162_EN_NTC_PAUSE_ALERT_SIZE 1u
#define LTC4162_EN_NTC_PAUSE_ALERT_OFFSET 5u
#define LTC4162_EN_NTC_PAUSE_ALERT_MASK 0x0020u
#define LTC4162_EN_NTC_PAUSE_ALERT_DEFAULT 0u
#define LTC4162_EN_NTC_PAUSE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_NTC_PAUSE_ALERT_MASK) >> LTC4162_EN_NTC_PAUSE_ALERT_OFFSET)
#define LTC4162_EN_NTC_PAUSE_ALERT (LTC4162_EN_NTC_PAUSE_ALERT_OFFSET << 12 | (LTC4162_EN_NTC_PAUSE_ALERT_SIZE - 1) << 8 | LTC4162_EN_NTC_PAUSE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_TIMER_TERM_ALERT EN_TIMER_TERM_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_TIMER_TERM_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon timer_term_alert as indicated by timer_term whereby a battery charge cycle terminates due to tcvtimer reaching max_cv_time, the maximum time allowed in constant_voltage mode.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_TIMER_TERM_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_TIMER_TERM_ALERT "EN_TIMER_TERM_ALERT"
#define LTC4162_EN_TIMER_TERM_ALERT_SIZE 1u
#define LTC4162_EN_TIMER_TERM_ALERT_OFFSET 4u
#define LTC4162_EN_TIMER_TERM_ALERT_MASK 0x0010u
#define LTC4162_EN_TIMER_TERM_ALERT_DEFAULT 0u
#define LTC4162_EN_TIMER_TERM_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_TIMER_TERM_ALERT_MASK) >> LTC4162_EN_TIMER_TERM_ALERT_OFFSET)
#define LTC4162_EN_TIMER_TERM_ALERT (LTC4162_EN_TIMER_TERM_ALERT_OFFSET << 12 | (LTC4162_EN_TIMER_TERM_ALERT_SIZE - 1) << 8 | LTC4162_EN_TIMER_TERM_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_C_OVER_X_TERM_ALERT EN_C_OVER_X_TERM_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_C_OVER_X_TERM_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon c_over_x_term_alert as indicated by c_over_x_term whereby a battery charge cycle terminates due to ibat dropping below the c_over_x_threshold.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_C_OVER_X_TERM_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_C_OVER_X_TERM_ALERT "EN_C_OVER_X_TERM_ALERT"
#define LTC4162_EN_C_OVER_X_TERM_ALERT_SIZE 1u
#define LTC4162_EN_C_OVER_X_TERM_ALERT_OFFSET 3u
#define LTC4162_EN_C_OVER_X_TERM_ALERT_MASK 0x0008u
#define LTC4162_EN_C_OVER_X_TERM_ALERT_DEFAULT 0u
#define LTC4162_EN_C_OVER_X_TERM_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_C_OVER_X_TERM_ALERT_MASK) >> LTC4162_EN_C_OVER_X_TERM_ALERT_OFFSET)
#define LTC4162_EN_C_OVER_X_TERM_ALERT (LTC4162_EN_C_OVER_X_TERM_ALERT_OFFSET << 12 | (LTC4162_EN_C_OVER_X_TERM_ALERT_SIZE - 1) << 8 | LTC4162_EN_C_OVER_X_TERM_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_MAX_CHARGE_TIME_ALERT EN_MAX_CHARGE_TIME_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_MAX_CHARGE_TIME_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon max_charge_time_fault_alert as indicated by max_charge_time_fault whereby charging has terminated due to tchargetimer reaching max_charge_time.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_MAX_CHARGE_TIME_ALERT "EN_MAX_CHARGE_TIME_ALERT"
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT_SIZE 1u
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT_OFFSET 2u
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT_MASK 0x0004u
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT_DEFAULT 0u
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_MAX_CHARGE_TIME_ALERT_MASK) >> LTC4162_EN_MAX_CHARGE_TIME_ALERT_OFFSET)
#define LTC4162_EN_MAX_CHARGE_TIME_ALERT (LTC4162_EN_MAX_CHARGE_TIME_ALERT_OFFSET << 12 | (LTC4162_EN_MAX_CHARGE_TIME_ALERT_SIZE - 1) << 8 | LTC4162_EN_MAX_CHARGE_TIME_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_BAT_MISSING_FAULT_ALERT EN_BAT_MISSING_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_BAT_MISSING_FAULT_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon bat_missing_fault_alert as indicated by bat_missing_fault whereby charging is prohibited if no battery is detected during the battery presence detection phase at the beginning of a charge cycle.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_BAT_MISSING_FAULT_ALERT "EN_BAT_MISSING_FAULT_ALERT"
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT_SIZE 1u
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT_OFFSET 1u
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT_MASK 0x0002u
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT_DEFAULT 0u
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_BAT_MISSING_FAULT_ALERT_MASK) >> LTC4162_EN_BAT_MISSING_FAULT_ALERT_OFFSET)
#define LTC4162_EN_BAT_MISSING_FAULT_ALERT (LTC4162_EN_BAT_MISSING_FAULT_ALERT_OFFSET << 12 | (LTC4162_EN_BAT_MISSING_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_EN_BAT_MISSING_FAULT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_BAT_SHORT_FAULT_ALERT EN_BAT_SHORT_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_BAT_SHORT_FAULT_ALERT Bit Field
 *
 *  Interrupt request that causes an SMBALERT upon bat_short_fault_alert as indicated by bat_short_fault whereby charging is prohibited if a shorted battery is detected during the battery presence detection phase at the beginning of a charge cycle.
 *   - Register: @ref LTC4162_EN_CHARGER_STATE_ALERTS_REG "EN_CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x0E
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT_SUBADDR LTC4162_EN_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_BAT_SHORT_FAULT_ALERT "EN_BAT_SHORT_FAULT_ALERT"
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT_SIZE 1u
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT_OFFSET 0u
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT_MASK 0x0001u
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT_DEFAULT 0u
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_BAT_SHORT_FAULT_ALERT_MASK) >> LTC4162_EN_BAT_SHORT_FAULT_ALERT_OFFSET)
#define LTC4162_EN_BAT_SHORT_FAULT_ALERT (LTC4162_EN_BAT_SHORT_FAULT_ALERT_OFFSET << 12 | (LTC4162_EN_BAT_SHORT_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_EN_BAT_SHORT_FAULT_ALERT_SUBADDR)
//!@}

/*! @defgroup LTC4162_EN_CHARGE_STATUS_ALERTS_REG EN_CHARGE_STATUS_ALERTS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CHARGE_STATUS_ALERTS_REG Register
 *
 * | 15:6 |                        5 |                           4 |                        3 |                         2 |                         1 |                         0 |
 * |:----:|:------------------------:|:---------------------------:|:------------------------:|:-------------------------:|:-------------------------:|:-------------------------:|
 * |  n/a | EN_ILIM_REG_ACTIVE_ALERT | EN_THERMAL_REG_ACTIVE_ALERT | EN_VIN_UVCL_ACTIVE_ALERT | EN_IIN_LIMIT_ACTIVE_ALERT | EN_CONSTANT_CURRENT_ALERT | EN_CONSTANT_VOLTAGE_ALERT |
 *
 * Enable charge status notification via SMBALERT
 *   - CommandCode: 0x0F
 *   - Contains Bit Fields:
 *     + @ref LTC4162_EN_ILIM_REG_ACTIVE_ALERT "EN_ILIM_REG_ACTIVE_ALERT" : Interrupt request that causes an ilim_reg_active_alert SMBALERT upon ilim_reg_active (VCSP-VCSN greater than 45mV). May indicates that the switching regulator is currently controlling power delivery based on a safety current limit. This should not occur under normal conditions and is likely the result of a circuit board fault. Alternately indicates that the switching regulator is in dropout (near 100% duty cycle) and is not regulating on any feedback control loop.
 *     + @ref LTC4162_EN_THERMAL_REG_ACTIVE_ALERT "EN_THERMAL_REG_ACTIVE_ALERT" : Interrupt request that causes a thermal_reg_active_alert SMBALERT upon thermal_reg_active indicating that the icharge_dac is being dialed back to reduce internal die heating.
 *     + @ref LTC4162_EN_VIN_UVCL_ACTIVE_ALERT "EN_VIN_UVCL_ACTIVE_ALERT" : Interrupt request that causes a vin_uvcl_active_alert SMBALERT upon vin_uvcl_active indicating that the undervoltage regulation loop has taken control of the switching regulator.
 *     + @ref LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT "EN_IIN_LIMIT_ACTIVE_ALERT" : Interrupt request that causes a iin_limit_active_alert SMBALERT upon iin_limit_active indicating that the input current regulation loop has taken control of the switching regulator.
 *     + @ref LTC4162_EN_CONSTANT_CURRENT_ALERT "EN_CONSTANT_CURRENT_ALERT" : Interrupt request that causes a constant_current_alert SMBALERT upon constant_current indicating that the battery charger constant current regulation loop has taken control of the switching regulator.
 *     + @ref LTC4162_EN_CONSTANT_VOLTAGE_ALERT "EN_CONSTANT_VOLTAGE_ALERT" : Interrupt request that causes a constant_voltage_alert SMBALERT upon constant_voltage indicating that the battery charger constant voltage regulation loop has taken control of the switching regulator.
*/

//!@{
#define LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR 0x0Fu
#define LTC4162_EN_CHARGE_STATUS_ALERTS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_ILIM_REG_ACTIVE_ALERT EN_ILIM_REG_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_ILIM_REG_ACTIVE_ALERT Bit Field
 *
 *  Interrupt request that causes an ilim_reg_active_alert SMBALERT upon ilim_reg_active (VCSP-VCSN greater than 45mV). May indicates that the switching regulator is currently controlling power delivery based on a safety current limit. This should not occur under normal conditions and is likely the result of a circuit board fault. Alternately indicates that the switching regulator is in dropout (near 100% duty cycle) and is not regulating on any feedback control loop.
 *   - Register: @ref LTC4162_EN_CHARGE_STATUS_ALERTS_REG "EN_CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x0F
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT_SUBADDR LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_ILIM_REG_ACTIVE_ALERT "EN_ILIM_REG_ACTIVE_ALERT"
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT_SIZE 1u
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT_OFFSET 5u
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT_MASK 0x0020u
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_ILIM_REG_ACTIVE_ALERT_MASK) >> LTC4162_EN_ILIM_REG_ACTIVE_ALERT_OFFSET)
#define LTC4162_EN_ILIM_REG_ACTIVE_ALERT (LTC4162_EN_ILIM_REG_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_EN_ILIM_REG_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_EN_ILIM_REG_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_THERMAL_REG_ACTIVE_ALERT EN_THERMAL_REG_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_THERMAL_REG_ACTIVE_ALERT Bit Field
 *
 *  Interrupt request that causes a thermal_reg_active_alert SMBALERT upon thermal_reg_active indicating that the icharge_dac is being dialed back to reduce internal die heating.
 *   - Register: @ref LTC4162_EN_CHARGE_STATUS_ALERTS_REG "EN_CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x0F
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_SUBADDR LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_THERMAL_REG_ACTIVE_ALERT "EN_THERMAL_REG_ACTIVE_ALERT"
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_SIZE 1u
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_OFFSET 4u
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_MASK 0x0010u
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_MASK) >> LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_OFFSET)
#define LTC4162_EN_THERMAL_REG_ACTIVE_ALERT (LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_EN_THERMAL_REG_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_VIN_UVCL_ACTIVE_ALERT EN_VIN_UVCL_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_VIN_UVCL_ACTIVE_ALERT Bit Field
 *
 *  Interrupt request that causes a vin_uvcl_active_alert SMBALERT upon vin_uvcl_active indicating that the undervoltage regulation loop has taken control of the switching regulator.
 *   - Register: @ref LTC4162_EN_CHARGE_STATUS_ALERTS_REG "EN_CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x0F
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_SUBADDR LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_VIN_UVCL_ACTIVE_ALERT "EN_VIN_UVCL_ACTIVE_ALERT"
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_SIZE 1u
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_OFFSET 3u
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_MASK 0x0008u
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_MASK) >> LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_OFFSET)
#define LTC4162_EN_VIN_UVCL_ACTIVE_ALERT (LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_EN_VIN_UVCL_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT EN_IIN_LIMIT_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_IIN_LIMIT_ACTIVE_ALERT Bit Field
 *
 *  Interrupt request that causes a iin_limit_active_alert SMBALERT upon iin_limit_active indicating that the input current regulation loop has taken control of the switching regulator.
 *   - Register: @ref LTC4162_EN_CHARGE_STATUS_ALERTS_REG "EN_CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x0F
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_SUBADDR LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT "EN_IIN_LIMIT_ACTIVE_ALERT"
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_SIZE 1u
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_OFFSET 2u
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_MASK 0x0004u
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_MASK) >> LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_OFFSET)
#define LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT (LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_EN_IIN_LIMIT_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_CONSTANT_CURRENT_ALERT EN_CONSTANT_CURRENT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CONSTANT_CURRENT_ALERT Bit Field
 *
 *  Interrupt request that causes a constant_current_alert SMBALERT upon constant_current indicating that the battery charger constant current regulation loop has taken control of the switching regulator.
 *   - Register: @ref LTC4162_EN_CHARGE_STATUS_ALERTS_REG "EN_CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x0F
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_CONSTANT_CURRENT_ALERT_SUBADDR LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_CONSTANT_CURRENT_ALERT "EN_CONSTANT_CURRENT_ALERT"
#define LTC4162_EN_CONSTANT_CURRENT_ALERT_SIZE 1u
#define LTC4162_EN_CONSTANT_CURRENT_ALERT_OFFSET 1u
#define LTC4162_EN_CONSTANT_CURRENT_ALERT_MASK 0x0002u
#define LTC4162_EN_CONSTANT_CURRENT_ALERT_DEFAULT 0u
#define LTC4162_EN_CONSTANT_CURRENT_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_CONSTANT_CURRENT_ALERT_MASK) >> LTC4162_EN_CONSTANT_CURRENT_ALERT_OFFSET)
#define LTC4162_EN_CONSTANT_CURRENT_ALERT (LTC4162_EN_CONSTANT_CURRENT_ALERT_OFFSET << 12 | (LTC4162_EN_CONSTANT_CURRENT_ALERT_SIZE - 1) << 8 | LTC4162_EN_CONSTANT_CURRENT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_CONSTANT_VOLTAGE_ALERT EN_CONSTANT_VOLTAGE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CONSTANT_VOLTAGE_ALERT Bit Field
 *
 *  Interrupt request that causes a constant_voltage_alert SMBALERT upon constant_voltage indicating that the battery charger constant voltage regulation loop has taken control of the switching regulator.
 *   - Register: @ref LTC4162_EN_CHARGE_STATUS_ALERTS_REG "EN_CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x0F
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT_SUBADDR LTC4162_EN_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_EN_CONSTANT_VOLTAGE_ALERT "EN_CONSTANT_VOLTAGE_ALERT"
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT_SIZE 1u
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT_OFFSET 0u
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT_MASK 0x0001u
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT_DEFAULT 0u
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT_DECODE(register_data) (((register_data) & LTC4162_EN_CONSTANT_VOLTAGE_ALERT_MASK) >> LTC4162_EN_CONSTANT_VOLTAGE_ALERT_OFFSET)
#define LTC4162_EN_CONSTANT_VOLTAGE_ALERT (LTC4162_EN_CONSTANT_VOLTAGE_ALERT_OFFSET << 12 | (LTC4162_EN_CONSTANT_VOLTAGE_ALERT_SIZE - 1) << 8 | LTC4162_EN_CONSTANT_VOLTAGE_ALERT_SUBADDR)
//!@}

/*! @defgroup LTC4162_THERMAL_REG_START_TEMP_REG THERMAL_REG_START_TEMP_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMAL_REG_START_TEMP_REG Register
 *
 * |                   15:0 |
 * |:----------------------:|
 * | THERMAL_REG_START_TEMP |
 *
 *   - CommandCode: 0x10
 *   - Contains Bit Fields:
 *     + @ref LTC4162_THERMAL_REG_START_TEMP "THERMAL_REG_START_TEMP" : Signed number that sets the start of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 17897 corresponds to 120°C.
*/

//!@{
#define LTC4162_THERMAL_REG_START_TEMP_REG_SUBADDR 0x10u
#define LTC4162_THERMAL_REG_START_TEMP_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_THERMAL_REG_START_TEMP_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMAL_REG_START_TEMP THERMAL_REG_START_TEMP
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMAL_REG_START_TEMP Bit Field
 *
 *  Signed number that sets the start of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 17897 corresponds to 120°C.
 *   - Register: @ref LTC4162_THERMAL_REG_START_TEMP_REG "THERMAL_REG_START_TEMP_REG"
 *   - CommandCode: 0x10
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 17897
 *   - Format: LTC4162_DIE_TEMP_FORMAT
 */
//!@{
#define LTC4162_THERMAL_REG_START_TEMP_SUBADDR LTC4162_THERMAL_REG_START_TEMP_REG_SUBADDR //!< @ref LTC4162_THERMAL_REG_START_TEMP "THERMAL_REG_START_TEMP"
#define LTC4162_THERMAL_REG_START_TEMP_SIZE 16u
#define LTC4162_THERMAL_REG_START_TEMP_OFFSET 0u
#define LTC4162_THERMAL_REG_START_TEMP_MASK 0xFFFFu
#define LTC4162_THERMAL_REG_START_TEMP_DEFAULT 17897u
#define LTC4162_THERMAL_REG_START_TEMP_DECODE(register_data) (register_data)
#define LTC4162_THERMAL_REG_START_TEMP (LTC4162_THERMAL_REG_START_TEMP_OFFSET << 12 | (LTC4162_THERMAL_REG_START_TEMP_SIZE - 1) << 8 | LTC4162_THERMAL_REG_START_TEMP_SUBADDR)
//!@}

/*! @defgroup LTC4162_THERMAL_REG_END_TEMP_REG THERMAL_REG_END_TEMP_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMAL_REG_END_TEMP_REG Register
 *
 * |                 15:0 |
 * |:--------------------:|
 * | THERMAL_REG_END_TEMP |
 *
 *   - CommandCode: 0x11
 *   - Contains Bit Fields:
 *     + @ref LTC4162_THERMAL_REG_END_TEMP "THERMAL_REG_END_TEMP" : Signed number that sets the end of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 18130 corresponds to 125°C.
*/

//!@{
#define LTC4162_THERMAL_REG_END_TEMP_REG_SUBADDR 0x11u
#define LTC4162_THERMAL_REG_END_TEMP_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_THERMAL_REG_END_TEMP_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMAL_REG_END_TEMP THERMAL_REG_END_TEMP
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMAL_REG_END_TEMP Bit Field
 *
 *  Signed number that sets the end of the temperature region for thermal regulation. To prevent overheating, a thermal regulation feedback loop utilizing die_temp sets an upper limit on icharge_dac following a linear gradient from full scale (31) to minimum scale (0) between thermal_reg_start_temp and thermal_reg_end_temp. The default value of 18130 corresponds to 125°C.
 *   - Register: @ref LTC4162_THERMAL_REG_END_TEMP_REG "THERMAL_REG_END_TEMP_REG"
 *   - CommandCode: 0x11
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 18130
 *   - Format: LTC4162_DIE_TEMP_FORMAT
 */
//!@{
#define LTC4162_THERMAL_REG_END_TEMP_SUBADDR LTC4162_THERMAL_REG_END_TEMP_REG_SUBADDR //!< @ref LTC4162_THERMAL_REG_END_TEMP "THERMAL_REG_END_TEMP"
#define LTC4162_THERMAL_REG_END_TEMP_SIZE 16u
#define LTC4162_THERMAL_REG_END_TEMP_OFFSET 0u
#define LTC4162_THERMAL_REG_END_TEMP_MASK 0xFFFFu
#define LTC4162_THERMAL_REG_END_TEMP_DEFAULT 18130u
#define LTC4162_THERMAL_REG_END_TEMP_DECODE(register_data) (register_data)
#define LTC4162_THERMAL_REG_END_TEMP (LTC4162_THERMAL_REG_END_TEMP_OFFSET << 12 | (LTC4162_THERMAL_REG_END_TEMP_SIZE - 1) << 8 | LTC4162_THERMAL_REG_END_TEMP_SUBADDR)
//!@}

/*! @defgroup LTC4162_CONFIG_BITS_REG CONFIG_BITS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CONFIG_BITS_REG Register
 *
 * | 15:6 |               5 |       4 |               3 |                  2 |       1 |
 * |:----:|:---------------:|:-------:|:---------------:|:------------------:|:-------:|
 * |  n/a | SUSPEND_CHARGER | RUN_BSR | TELEMETRY_SPEED | FORCE_TELEMETRY_ON | MPPT_EN |
 *
 * System configuration settings
 *   - CommandCode: 0x14
 *   - Contains Bit Fields:
 *     + @ref LTC4162_SUSPEND_CHARGER "SUSPEND_CHARGER" : Causes battery charging to be suspended. This setting should be used cautiously. For embedded battery systems where two wire interface communication relies on a minimum battery voltage, setting this bit could result in a deadlock that may require factory service to correct.
 *     + @ref LTC4162_RUN_BSR "RUN_BSR" : Causes the battery equivalent-series-resistance (bsr) measurement to be made as soon as a charge cycle starts or immediately if a charge cycle is already running.
 *     + @ref LTC4162_TELEMETRY_SPEED "TELEMETRY_SPEED" : Forces the telemetry system to take measurements at the higher rate of approximately once every 11ms whenever the telemetry system is on. When this bit is disabled, the telemetry system will slow down to about once every 5s to reduce power when not charging. Setting telemetry_speed to tel_high_speed in conjunction with force_telemetry_on with no input power available will increase battery drain.
 *     + @ref LTC4162_FORCE_TELEMETRY_ON "FORCE_TELEMETRY_ON" : Causes the telemetry system to operate at all times, including times when only battery power is available.
 *     + @ref LTC4162_MPPT_EN "MPPT_EN" : Causes the Maximum Power-Point Tracking algorithm to run. The maximum power point algorithm takes control of the input undervoltage regulation control loop via the input_undervoltage_dac to seek the optimum power-point for resistive sources such as a long cable or solar panel.
*/

//!@{
#define LTC4162_CONFIG_BITS_REG_SUBADDR 0x14u
#define LTC4162_CONFIG_BITS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CONFIG_BITS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_SUSPEND_CHARGER SUSPEND_CHARGER
 *  @ingroup LTC4162-LADM_register_map
 *  @brief SUSPEND_CHARGER Bit Field
 *
 *  Causes battery charging to be suspended. This setting should be used cautiously. For embedded battery systems where two wire interface communication relies on a minimum battery voltage, setting this bit could result in a deadlock that may require factory service to correct.
 *   - Register: @ref LTC4162_CONFIG_BITS_REG "CONFIG_BITS_REG"
 *   - CommandCode: 0x14
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_SUSPEND_CHARGER_SUBADDR LTC4162_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_SUSPEND_CHARGER "SUSPEND_CHARGER"
#define LTC4162_SUSPEND_CHARGER_SIZE 1u
#define LTC4162_SUSPEND_CHARGER_OFFSET 5u
#define LTC4162_SUSPEND_CHARGER_MASK 0x0020u
#define LTC4162_SUSPEND_CHARGER_DEFAULT 0u
#define LTC4162_SUSPEND_CHARGER_DECODE(register_data) (((register_data) & LTC4162_SUSPEND_CHARGER_MASK) >> LTC4162_SUSPEND_CHARGER_OFFSET)
#define LTC4162_SUSPEND_CHARGER (LTC4162_SUSPEND_CHARGER_OFFSET << 12 | (LTC4162_SUSPEND_CHARGER_SIZE - 1) << 8 | LTC4162_SUSPEND_CHARGER_SUBADDR)
//!@}
/*! @defgroup LTC4162_RUN_BSR RUN_BSR
 *  @ingroup LTC4162-LADM_register_map
 *  @brief RUN_BSR Bit Field
 *
 *  Causes the battery equivalent-series-resistance (bsr) measurement to be made as soon as a charge cycle starts or immediately if a charge cycle is already running.
 *   - Register: @ref LTC4162_CONFIG_BITS_REG "CONFIG_BITS_REG"
 *   - CommandCode: 0x14
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_RUN_BSR_SUBADDR LTC4162_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_RUN_BSR "RUN_BSR"
#define LTC4162_RUN_BSR_SIZE 1u
#define LTC4162_RUN_BSR_OFFSET 4u
#define LTC4162_RUN_BSR_MASK 0x0010u
#define LTC4162_RUN_BSR_DEFAULT 0u
#define LTC4162_RUN_BSR_DECODE(register_data) (((register_data) & LTC4162_RUN_BSR_MASK) >> LTC4162_RUN_BSR_OFFSET)
#define LTC4162_RUN_BSR (LTC4162_RUN_BSR_OFFSET << 12 | (LTC4162_RUN_BSR_SIZE - 1) << 8 | LTC4162_RUN_BSR_SUBADDR)
//!@}
/*! @defgroup LTC4162_TELEMETRY_SPEED TELEMETRY_SPEED
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TELEMETRY_SPEED Bit Field
 *
 *  Forces the telemetry system to take measurements at the higher rate of approximately once every 11ms whenever the telemetry system is on. When this bit is disabled, the telemetry system will slow down to about once every 5s to reduce power when not charging. Setting telemetry_speed to tel_high_speed in conjunction with force_telemetry_on with no input power available will increase battery drain.
 *   - Register: @ref LTC4162_CONFIG_BITS_REG "CONFIG_BITS_REG"
 *   - CommandCode: 0x14
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_TELEMETRY_SPEED_SUBADDR LTC4162_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_TELEMETRY_SPEED "TELEMETRY_SPEED"
#define LTC4162_TELEMETRY_SPEED_SIZE 1u
#define LTC4162_TELEMETRY_SPEED_OFFSET 3u
#define LTC4162_TELEMETRY_SPEED_MASK 0x0008u
#define LTC4162_TELEMETRY_SPEED_DEFAULT 0u
#define LTC4162_TELEMETRY_SPEED_DECODE(register_data) (((register_data) & LTC4162_TELEMETRY_SPEED_MASK) >> LTC4162_TELEMETRY_SPEED_OFFSET)
#define LTC4162_TELEMETRY_SPEED (LTC4162_TELEMETRY_SPEED_OFFSET << 12 | (LTC4162_TELEMETRY_SPEED_SIZE - 1) << 8 | LTC4162_TELEMETRY_SPEED_SUBADDR)
#define LTC4162_TELEMETRY_SPEED_ENUM_TEL_HIGH_SPEED 1u
#define LTC4162_TELEMETRY_SPEED_ENUM_TEL_LOW_SPEED 0u
//!@}
/*! @defgroup LTC4162_FORCE_TELEMETRY_ON FORCE_TELEMETRY_ON
 *  @ingroup LTC4162-LADM_register_map
 *  @brief FORCE_TELEMETRY_ON Bit Field
 *
 *  Causes the telemetry system to operate at all times, including times when only battery power is available.
 *   - Register: @ref LTC4162_CONFIG_BITS_REG "CONFIG_BITS_REG"
 *   - CommandCode: 0x14
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_FORCE_TELEMETRY_ON_SUBADDR LTC4162_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_FORCE_TELEMETRY_ON "FORCE_TELEMETRY_ON"
#define LTC4162_FORCE_TELEMETRY_ON_SIZE 1u
#define LTC4162_FORCE_TELEMETRY_ON_OFFSET 2u
#define LTC4162_FORCE_TELEMETRY_ON_MASK 0x0004u
#define LTC4162_FORCE_TELEMETRY_ON_DEFAULT 0u
#define LTC4162_FORCE_TELEMETRY_ON_DECODE(register_data) (((register_data) & LTC4162_FORCE_TELEMETRY_ON_MASK) >> LTC4162_FORCE_TELEMETRY_ON_OFFSET)
#define LTC4162_FORCE_TELEMETRY_ON (LTC4162_FORCE_TELEMETRY_ON_OFFSET << 12 | (LTC4162_FORCE_TELEMETRY_ON_SIZE - 1) << 8 | LTC4162_FORCE_TELEMETRY_ON_SUBADDR)
//!@}
/*! @defgroup LTC4162_MPPT_EN MPPT_EN
 *  @ingroup LTC4162-LADM_register_map
 *  @brief MPPT_EN Bit Field
 *
 *  Causes the Maximum Power-Point Tracking algorithm to run. The maximum power point algorithm takes control of the input undervoltage regulation control loop via the input_undervoltage_dac to seek the optimum power-point for resistive sources such as a long cable or solar panel.
 *   - Register: @ref LTC4162_CONFIG_BITS_REG "CONFIG_BITS_REG"
 *   - CommandCode: 0x14
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R/W
 *   - Default: 1
 */
//!@{
#define LTC4162_MPPT_EN_SUBADDR LTC4162_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_MPPT_EN "MPPT_EN"
#define LTC4162_MPPT_EN_SIZE 1u
#define LTC4162_MPPT_EN_OFFSET 1u
#define LTC4162_MPPT_EN_MASK 0x0002u
#define LTC4162_MPPT_EN_DEFAULT 1u
#define LTC4162_MPPT_EN_DECODE(register_data) (((register_data) & LTC4162_MPPT_EN_MASK) >> LTC4162_MPPT_EN_OFFSET)
#define LTC4162_MPPT_EN (LTC4162_MPPT_EN_OFFSET << 12 | (LTC4162_MPPT_EN_SIZE - 1) << 8 | LTC4162_MPPT_EN_SUBADDR)
//!@}

/*! @defgroup LTC4162_IIN_LIMIT_TARGET_REG IIN_LIMIT_TARGET_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_LIMIT_TARGET_REG Register
 *
 * | 15:6 |              5:0 |
 * |:----:|:----------------:|
 * |  n/a | IIN_LIMIT_TARGET |
 *
 *   - CommandCode: 0x15
 *   - Contains Bit Fields:
 *     + @ref LTC4162_IIN_LIMIT_TARGET "IIN_LIMIT_TARGET" : Controls the target input current limit setting. The input current is limited by regulating charge current in response to the voltage across an external current sense resistor, RSNSI, between the CLP and CLN pins and is given by (iin_limit_target + 1) × 500µV / RSNSI. Note that the LTC4162 can only limit charge current based on this setting. It does not have the authority to block current from passing directly through to the system load. Connecting the system load to the battery, however, can allow total input current control.
*/

//!@{
#define LTC4162_IIN_LIMIT_TARGET_REG_SUBADDR 0x15u
#define LTC4162_IIN_LIMIT_TARGET_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_IIN_LIMIT_TARGET_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_IIN_LIMIT_TARGET IIN_LIMIT_TARGET
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_LIMIT_TARGET Bit Field
 *
 *  Controls the target input current limit setting. The input current is limited by regulating charge current in response to the voltage across an external current sense resistor, RSNSI, between the CLP and CLN pins and is given by (iin_limit_target + 1) × 500µV / RSNSI. Note that the LTC4162 can only limit charge current based on this setting. It does not have the authority to block current from passing directly through to the system load. Connecting the system load to the battery, however, can allow total input current control.
 *   - Register: @ref LTC4162_IIN_LIMIT_TARGET_REG "IIN_LIMIT_TARGET_REG"
 *   - CommandCode: 0x15
 *   - Size: 6
 *   - Offset: 0
 *   - MSB: 5
 *   - MASK: 0x003F
 *   - Access: R/W
 *   - Default: 63
 *   - Format: LTC4162_IINLIM
 */
//!@{
#define LTC4162_IIN_LIMIT_TARGET_SUBADDR LTC4162_IIN_LIMIT_TARGET_REG_SUBADDR //!< @ref LTC4162_IIN_LIMIT_TARGET "IIN_LIMIT_TARGET"
#define LTC4162_IIN_LIMIT_TARGET_SIZE 6u
#define LTC4162_IIN_LIMIT_TARGET_OFFSET 0u
#define LTC4162_IIN_LIMIT_TARGET_MASK 0x003Fu
#define LTC4162_IIN_LIMIT_TARGET_DEFAULT 63u
#define LTC4162_IIN_LIMIT_TARGET_DECODE(register_data) (((register_data) & LTC4162_IIN_LIMIT_TARGET_MASK) >> LTC4162_IIN_LIMIT_TARGET_OFFSET)
#define LTC4162_IIN_LIMIT_TARGET (LTC4162_IIN_LIMIT_TARGET_OFFSET << 12 | (LTC4162_IIN_LIMIT_TARGET_SIZE - 1) << 8 | LTC4162_IIN_LIMIT_TARGET_SUBADDR)
//!@}

/*! @defgroup LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG INPUT_UNDERVOLTAGE_SETTING_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief INPUT_UNDERVOLTAGE_SETTING_REG Register
 *
 * | 15:8 |                        7:0 |
 * |:----:|:--------------------------:|
 * |  n/a | INPUT_UNDERVOLTAGE_SETTING |
 *
 *   - CommandCode: 0x16
 *   - Contains Bit Fields:
 *     + @ref LTC4162_INPUT_UNDERVOLTAGE_SETTING "INPUT_UNDERVOLTAGE_SETTING" : Controls the input undervoltage regulation setting. The regulation voltage, given by (input_undervoltage_setting + 1) × 140.625mV, is the voltage at which the charge current will be reduced to prevent further droop in supply voltage due to a resistive source. If mppt_en is set, the MPPT algorithm will override this setting. The actual input undervoltage value can be read back from the input_undervoltage_dac.
*/

//!@{
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG_SUBADDR 0x16u
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_INPUT_UNDERVOLTAGE_SETTING INPUT_UNDERVOLTAGE_SETTING
 *  @ingroup LTC4162-LADM_register_map
 *  @brief INPUT_UNDERVOLTAGE_SETTING Bit Field
 *
 *  Controls the input undervoltage regulation setting. The regulation voltage, given by (input_undervoltage_setting + 1) × 140.625mV, is the voltage at which the charge current will be reduced to prevent further droop in supply voltage due to a resistive source. If mppt_en is set, the MPPT algorithm will override this setting. The actual input undervoltage value can be read back from the input_undervoltage_dac.
 *   - Register: @ref LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG "INPUT_UNDERVOLTAGE_SETTING_REG"
 *   - CommandCode: 0x16
 *   - Size: 8
 *   - Offset: 0
 *   - MSB: 7
 *   - MASK: 0x00FF
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_VIN_UVCL
 */
//!@{
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_SUBADDR LTC4162_INPUT_UNDERVOLTAGE_SETTING_REG_SUBADDR //!< @ref LTC4162_INPUT_UNDERVOLTAGE_SETTING "INPUT_UNDERVOLTAGE_SETTING"
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_SIZE 8u
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_OFFSET 0u
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_MASK 0x00FFu
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_DEFAULT 31u
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING_DECODE(register_data) (((register_data) & LTC4162_INPUT_UNDERVOLTAGE_SETTING_MASK) >> LTC4162_INPUT_UNDERVOLTAGE_SETTING_OFFSET)
#define LTC4162_INPUT_UNDERVOLTAGE_SETTING (LTC4162_INPUT_UNDERVOLTAGE_SETTING_OFFSET << 12 | (LTC4162_INPUT_UNDERVOLTAGE_SETTING_SIZE - 1) << 8 | LTC4162_INPUT_UNDERVOLTAGE_SETTING_SUBADDR)
//!@}

/*! @defgroup LTC4162_ARM_SHIP_MODE_REG ARM_SHIP_MODE_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ARM_SHIP_MODE_REG Register
 *
 * |          15:0 |
 * |:-------------:|
 * | ARM_SHIP_MODE |
 *
 *   - CommandCode: 0x19
 *   - Contains Bit Fields:
 *     + @ref LTC4162_ARM_SHIP_MODE "ARM_SHIP_MODE" : Setting this register to arm arms the ultra low-power ship and store mode. Ship mode does not take effect until the VIN pin drops below approximately 1V or immediately if VIN is already below 1V.
*/

//!@{
#define LTC4162_ARM_SHIP_MODE_REG_SUBADDR 0x19u
#define LTC4162_ARM_SHIP_MODE_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_ARM_SHIP_MODE_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_ARM_SHIP_MODE ARM_SHIP_MODE
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ARM_SHIP_MODE Bit Field
 *
 *  Setting this register to arm arms the ultra low-power ship and store mode. Ship mode does not take effect until the VIN pin drops below approximately 1V or immediately if VIN is already below 1V.
 *   - Register: @ref LTC4162_ARM_SHIP_MODE_REG "ARM_SHIP_MODE_REG"
 *   - CommandCode: 0x19
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_ARM_SHIP_MODE_SUBADDR LTC4162_ARM_SHIP_MODE_REG_SUBADDR //!< @ref LTC4162_ARM_SHIP_MODE "ARM_SHIP_MODE"
#define LTC4162_ARM_SHIP_MODE_SIZE 16u
#define LTC4162_ARM_SHIP_MODE_OFFSET 0u
#define LTC4162_ARM_SHIP_MODE_MASK 0xFFFFu
#define LTC4162_ARM_SHIP_MODE_DEFAULT 0u
#define LTC4162_ARM_SHIP_MODE_DECODE(register_data) (register_data)
#define LTC4162_ARM_SHIP_MODE (LTC4162_ARM_SHIP_MODE_OFFSET << 12 | (LTC4162_ARM_SHIP_MODE_SIZE - 1) << 8 | LTC4162_ARM_SHIP_MODE_SUBADDR)
#define LTC4162_ARM_SHIP_MODE_ENUM_ARM 21325u
//!@}

/*! @defgroup LTC4162_CHARGE_CURRENT_SETTING_REG CHARGE_CURRENT_SETTING_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGE_CURRENT_SETTING_REG Register
 *
 * | 15:5 |                    4:0 |
 * |:----:|:----------------------:|
 * |  n/a | CHARGE_CURRENT_SETTING |
 *
 *   - CommandCode: 0x1A
 *   - Contains Bit Fields:
 *     + @ref LTC4162_CHARGE_CURRENT_SETTING "CHARGE_CURRENT_SETTING" : Controls the target charge current regulation servo level. The charge current is regulated by servoing the voltage across an external current sense resistor, RSNSB, between the CSP and CSN pins. The servo voltage is given by (charge_current_setting + 1) × 1mV. The effective charge current, determined by the external resistor, RSNSB, is given by (charge_current_setting + 1) × 1mV / RSNSB. icharge_dac will follow charge_current_setting unless thermal_reg_active is true or the JEITA algorithm, with en_jeita, has altered it.
*/

//!@{
#define LTC4162_CHARGE_CURRENT_SETTING_REG_SUBADDR 0x1Au
#define LTC4162_CHARGE_CURRENT_SETTING_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHARGE_CURRENT_SETTING_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_CHARGE_CURRENT_SETTING CHARGE_CURRENT_SETTING
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGE_CURRENT_SETTING Bit Field
 *
 *  Controls the target charge current regulation servo level. The charge current is regulated by servoing the voltage across an external current sense resistor, RSNSB, between the CSP and CSN pins. The servo voltage is given by (charge_current_setting + 1) × 1mV. The effective charge current, determined by the external resistor, RSNSB, is given by (charge_current_setting + 1) × 1mV / RSNSB. icharge_dac will follow charge_current_setting unless thermal_reg_active is true or the JEITA algorithm, with en_jeita, has altered it.
 *   - Register: @ref LTC4162_CHARGE_CURRENT_SETTING_REG "CHARGE_CURRENT_SETTING_REG"
 *   - CommandCode: 0x1A
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_CHARGE_CURRENT_SETTING_SUBADDR LTC4162_CHARGE_CURRENT_SETTING_REG_SUBADDR //!< @ref LTC4162_CHARGE_CURRENT_SETTING "CHARGE_CURRENT_SETTING"
#define LTC4162_CHARGE_CURRENT_SETTING_SIZE 5u
#define LTC4162_CHARGE_CURRENT_SETTING_OFFSET 0u
#define LTC4162_CHARGE_CURRENT_SETTING_MASK 0x001Fu
#define LTC4162_CHARGE_CURRENT_SETTING_DEFAULT 31u
#define LTC4162_CHARGE_CURRENT_SETTING_DECODE(register_data) (((register_data) & LTC4162_CHARGE_CURRENT_SETTING_MASK) >> LTC4162_CHARGE_CURRENT_SETTING_OFFSET)
#define LTC4162_CHARGE_CURRENT_SETTING (LTC4162_CHARGE_CURRENT_SETTING_OFFSET << 12 | (LTC4162_CHARGE_CURRENT_SETTING_SIZE - 1) << 8 | LTC4162_CHARGE_CURRENT_SETTING_SUBADDR)
//!@}

/*! @defgroup LTC4162_VCHARGE_SETTING_REG VCHARGE_SETTING_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_SETTING_REG Register
 *
 * | 15:5 |             4:0 |
 * |:----:|:---------------:|
 * |  n/a | VCHARGE_SETTING |
 *
 *   - CommandCode: 0x1B
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VCHARGE_SETTING "VCHARGE_SETTING" : Controls the final charge voltage regulation servo level. To maintain inherent over-charge protection, only Lithium Ion appropriate charge voltage values can be selected. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max). vcharge_dac will follow vcharge_setting unless the advanced JEITA temperature control system (en_jeita) has altered it.
*/

//!@{
#define LTC4162_VCHARGE_SETTING_REG_SUBADDR 0x1Bu
#define LTC4162_VCHARGE_SETTING_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VCHARGE_SETTING_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_SETTING VCHARGE_SETTING
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_SETTING Bit Field
 *
 *  Controls the final charge voltage regulation servo level. To maintain inherent over-charge protection, only Lithium Ion appropriate charge voltage values can be selected. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max). vcharge_dac will follow vcharge_setting unless the advanced JEITA temperature control system (en_jeita) has altered it.
 *   - Register: @ref LTC4162_VCHARGE_SETTING_REG "VCHARGE_SETTING_REG"
 *   - CommandCode: 0x1B
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_SETTING_SUBADDR LTC4162_VCHARGE_SETTING_REG_SUBADDR //!< @ref LTC4162_VCHARGE_SETTING "VCHARGE_SETTING"
#define LTC4162_VCHARGE_SETTING_SIZE 5u
#define LTC4162_VCHARGE_SETTING_OFFSET 0u
#define LTC4162_VCHARGE_SETTING_MASK 0x001Fu
#define LTC4162_VCHARGE_SETTING_DEFAULT 31u
#define LTC4162_VCHARGE_SETTING_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_SETTING_MASK) >> LTC4162_VCHARGE_SETTING_OFFSET)
#define LTC4162_VCHARGE_SETTING (LTC4162_VCHARGE_SETTING_OFFSET << 12 | (LTC4162_VCHARGE_SETTING_SIZE - 1) << 8 | LTC4162_VCHARGE_SETTING_SUBADDR)
#define LTC4162_VCHARGE_SETTING_ENUM_VCHARGE_LION_DEFAULT 31u
//!@}

/*! @defgroup LTC4162_C_OVER_X_THRESHOLD_REG C_OVER_X_THRESHOLD_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief C_OVER_X_THRESHOLD_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | C_OVER_X_THRESHOLD |
 *
 *   - CommandCode: 0x1C
 *   - Contains Bit Fields:
 *     + @ref LTC4162_C_OVER_X_THRESHOLD "C_OVER_X_THRESHOLD" : Signed number that sets the ibat A/D value used to qualify C/x detection and termination. The C/x level is based on the value for ibat which has a scaling factor of 1.466µV / RSNSB amperes/LSB. For example, to make the C/x level C/10 (a very common choice) then c_over_x_threshold should be set to c_over_10 which is 10% of the maximum possible ibat reading (32mV × 37.5 × 18,191 / 10). 32mV is the full scale charge current signal from CSP to CSN, 37.5 is the internal charge amplifier's gain and 18,191 is the A/D's span term in counts per Volt.
*/

//!@{
#define LTC4162_C_OVER_X_THRESHOLD_REG_SUBADDR 0x1Cu
#define LTC4162_C_OVER_X_THRESHOLD_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_C_OVER_X_THRESHOLD_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_C_OVER_X_THRESHOLD C_OVER_X_THRESHOLD
 *  @ingroup LTC4162-LADM_register_map
 *  @brief C_OVER_X_THRESHOLD Bit Field
 *
 *  Signed number that sets the ibat A/D value used to qualify C/x detection and termination. The C/x level is based on the value for ibat which has a scaling factor of 1.466µV / RSNSB amperes/LSB. For example, to make the C/x level C/10 (a very common choice) then c_over_x_threshold should be set to c_over_10 which is 10% of the maximum possible ibat reading (32mV × 37.5 × 18,191 / 10). 32mV is the full scale charge current signal from CSP to CSN, 37.5 is the internal charge amplifier's gain and 18,191 is the A/D's span term in counts per Volt.
 *   - Register: @ref LTC4162_C_OVER_X_THRESHOLD_REG "C_OVER_X_THRESHOLD_REG"
 *   - CommandCode: 0x1C
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 2184
 *   - Format: LTC4162_IBAT_FORMAT
 */
//!@{
#define LTC4162_C_OVER_X_THRESHOLD_SUBADDR LTC4162_C_OVER_X_THRESHOLD_REG_SUBADDR //!< @ref LTC4162_C_OVER_X_THRESHOLD "C_OVER_X_THRESHOLD"
#define LTC4162_C_OVER_X_THRESHOLD_SIZE 16u
#define LTC4162_C_OVER_X_THRESHOLD_OFFSET 0u
#define LTC4162_C_OVER_X_THRESHOLD_MASK 0xFFFFu
#define LTC4162_C_OVER_X_THRESHOLD_DEFAULT 2184u
#define LTC4162_C_OVER_X_THRESHOLD_DECODE(register_data) (register_data)
#define LTC4162_C_OVER_X_THRESHOLD (LTC4162_C_OVER_X_THRESHOLD_OFFSET << 12 | (LTC4162_C_OVER_X_THRESHOLD_SIZE - 1) << 8 | LTC4162_C_OVER_X_THRESHOLD_SUBADDR)
#define LTC4162_C_OVER_X_THRESHOLD_ENUM_C_OVER_10 2184u
//!@}

/*! @defgroup LTC4162_MAX_CV_TIME_REG MAX_CV_TIME_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief MAX_CV_TIME_REG Register
 *
 * |        15:0 |
 * |:-----------:|
 * | MAX_CV_TIME |
 *
 *   - CommandCode: 0x1D
 *   - Contains Bit Fields:
 *     + @ref LTC4162_MAX_CV_TIME "MAX_CV_TIME" : Sets the constant-voltage termination setting against which the tcvtimer is compared. The timer begins at the onset of the constant_voltage phase of charging and increments at one count per second. The default setting is 14,400 (4 hours).
*/

//!@{
#define LTC4162_MAX_CV_TIME_REG_SUBADDR 0x1Du
#define LTC4162_MAX_CV_TIME_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_MAX_CV_TIME_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_MAX_CV_TIME MAX_CV_TIME
 *  @ingroup LTC4162-LADM_register_map
 *  @brief MAX_CV_TIME Bit Field
 *
 *  Sets the constant-voltage termination setting against which the tcvtimer is compared. The timer begins at the onset of the constant_voltage phase of charging and increments at one count per second. The default setting is 14,400 (4 hours).
 *   - Register: @ref LTC4162_MAX_CV_TIME_REG "MAX_CV_TIME_REG"
 *   - CommandCode: 0x1D
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 14400
 */
//!@{
#define LTC4162_MAX_CV_TIME_SUBADDR LTC4162_MAX_CV_TIME_REG_SUBADDR //!< @ref LTC4162_MAX_CV_TIME "MAX_CV_TIME"
#define LTC4162_MAX_CV_TIME_SIZE 16u
#define LTC4162_MAX_CV_TIME_OFFSET 0u
#define LTC4162_MAX_CV_TIME_MASK 0xFFFFu
#define LTC4162_MAX_CV_TIME_DEFAULT 14400u
#define LTC4162_MAX_CV_TIME_DECODE(register_data) (register_data)
#define LTC4162_MAX_CV_TIME (LTC4162_MAX_CV_TIME_OFFSET << 12 | (LTC4162_MAX_CV_TIME_SIZE - 1) << 8 | LTC4162_MAX_CV_TIME_SUBADDR)
#define LTC4162_MAX_CV_TIME_ENUM_30MINS 1800u
#define LTC4162_MAX_CV_TIME_ENUM_1HOUR 3600u
#define LTC4162_MAX_CV_TIME_ENUM_2HOURS 7200u
#define LTC4162_MAX_CV_TIME_ENUM_4HOURS_DEFAULT 14400u
//!@}

/*! @defgroup LTC4162_MAX_CHARGE_TIME_REG MAX_CHARGE_TIME_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief MAX_CHARGE_TIME_REG Register
 *
 * |            15:0 |
 * |:---------------:|
 * | MAX_CHARGE_TIME |
 *
 *   - CommandCode: 0x1E
 *   - Contains Bit Fields:
 *     + @ref LTC4162_MAX_CHARGE_TIME "MAX_CHARGE_TIME" : Sets the total charge time termination setting against which the tchargetimer is compared. The default value of 0 disables the total charge time feature and prevents the tchargetimer from running. If enabled with a non zero value, the tchargetimer begins counting at the onset of a charge cycle and increments at one count per minute.
*/

//!@{
#define LTC4162_MAX_CHARGE_TIME_REG_SUBADDR 0x1Eu
#define LTC4162_MAX_CHARGE_TIME_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_MAX_CHARGE_TIME_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_MAX_CHARGE_TIME MAX_CHARGE_TIME
 *  @ingroup LTC4162-LADM_register_map
 *  @brief MAX_CHARGE_TIME Bit Field
 *
 *  Sets the total charge time termination setting against which the tchargetimer is compared. The default value of 0 disables the total charge time feature and prevents the tchargetimer from running. If enabled with a non zero value, the tchargetimer begins counting at the onset of a charge cycle and increments at one count per minute.
 *   - Register: @ref LTC4162_MAX_CHARGE_TIME_REG "MAX_CHARGE_TIME_REG"
 *   - CommandCode: 0x1E
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_MAX_CHARGE_TIME_SUBADDR LTC4162_MAX_CHARGE_TIME_REG_SUBADDR //!< @ref LTC4162_MAX_CHARGE_TIME "MAX_CHARGE_TIME"
#define LTC4162_MAX_CHARGE_TIME_SIZE 16u
#define LTC4162_MAX_CHARGE_TIME_OFFSET 0u
#define LTC4162_MAX_CHARGE_TIME_MASK 0xFFFFu
#define LTC4162_MAX_CHARGE_TIME_DEFAULT 0u
#define LTC4162_MAX_CHARGE_TIME_DECODE(register_data) (register_data)
#define LTC4162_MAX_CHARGE_TIME (LTC4162_MAX_CHARGE_TIME_OFFSET << 12 | (LTC4162_MAX_CHARGE_TIME_SIZE - 1) << 8 | LTC4162_MAX_CHARGE_TIME_SUBADDR)
#define LTC4162_MAX_CHARGE_TIME_ENUM_MAXCHARGETIME_DISABLE 0u
//!@}

/*! @defgroup LTC4162_JEITA_T1_REG JEITA_T1_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T1_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | JEITA_T1 |
 *
 *   - CommandCode: 0x1F
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_T1 "JEITA_T1" : Signed number that sets the JEITA temperature region transition temperature T1 between JEITA regions R1 and R2. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 16117 maps to about 0°C for the expected thermistor β value of 3490K.
*/

//!@{
#define LTC4162_JEITA_T1_REG_SUBADDR 0x1Fu
#define LTC4162_JEITA_T1_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_T1_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_T1 JEITA_T1
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T1 Bit Field
 *
 *  Signed number that sets the JEITA temperature region transition temperature T1 between JEITA regions R1 and R2. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 16117 maps to about 0°C for the expected thermistor β value of 3490K.
 *   - Register: @ref LTC4162_JEITA_T1_REG "JEITA_T1_REG"
 *   - CommandCode: 0x1F
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 16117
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_JEITA_T1_SUBADDR LTC4162_JEITA_T1_REG_SUBADDR //!< @ref LTC4162_JEITA_T1 "JEITA_T1"
#define LTC4162_JEITA_T1_SIZE 16u
#define LTC4162_JEITA_T1_OFFSET 0u
#define LTC4162_JEITA_T1_MASK 0xFFFFu
#define LTC4162_JEITA_T1_DEFAULT 16117u
#define LTC4162_JEITA_T1_DECODE(register_data) (register_data)
#define LTC4162_JEITA_T1 (LTC4162_JEITA_T1_OFFSET << 12 | (LTC4162_JEITA_T1_SIZE - 1) << 8 | LTC4162_JEITA_T1_SUBADDR)
//!@}

/*! @defgroup LTC4162_JEITA_T2_REG JEITA_T2_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T2_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | JEITA_T2 |
 *
 *   - CommandCode: 0x20
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_T2 "JEITA_T2" : Signed number that sets the JEITA temperature region transition temperature T2 between JEITA regions R2 and R3. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 14113 maps to about 10°C for the expected thermistor β value of 3490K.
*/

//!@{
#define LTC4162_JEITA_T2_REG_SUBADDR 0x20u
#define LTC4162_JEITA_T2_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_T2_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_T2 JEITA_T2
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T2 Bit Field
 *
 *  Signed number that sets the JEITA temperature region transition temperature T2 between JEITA regions R2 and R3. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 14113 maps to about 10°C for the expected thermistor β value of 3490K.
 *   - Register: @ref LTC4162_JEITA_T2_REG "JEITA_T2_REG"
 *   - CommandCode: 0x20
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 14113
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_JEITA_T2_SUBADDR LTC4162_JEITA_T2_REG_SUBADDR //!< @ref LTC4162_JEITA_T2 "JEITA_T2"
#define LTC4162_JEITA_T2_SIZE 16u
#define LTC4162_JEITA_T2_OFFSET 0u
#define LTC4162_JEITA_T2_MASK 0xFFFFu
#define LTC4162_JEITA_T2_DEFAULT 14113u
#define LTC4162_JEITA_T2_DECODE(register_data) (register_data)
#define LTC4162_JEITA_T2 (LTC4162_JEITA_T2_OFFSET << 12 | (LTC4162_JEITA_T2_SIZE - 1) << 8 | LTC4162_JEITA_T2_SUBADDR)
//!@}

/*! @defgroup LTC4162_JEITA_T3_REG JEITA_T3_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T3_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | JEITA_T3 |
 *
 *   - CommandCode: 0x21
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_T3 "JEITA_T3" : Signed number that sets the JEITA temperature region transition temperature T3 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7970 maps to about 40°C for the expected thermistor β value of 3490K.
*/

//!@{
#define LTC4162_JEITA_T3_REG_SUBADDR 0x21u
#define LTC4162_JEITA_T3_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_T3_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_T3 JEITA_T3
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T3 Bit Field
 *
 *  Signed number that sets the JEITA temperature region transition temperature T3 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7970 maps to about 40°C for the expected thermistor β value of 3490K.
 *   - Register: @ref LTC4162_JEITA_T3_REG "JEITA_T3_REG"
 *   - CommandCode: 0x21
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 7970
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_JEITA_T3_SUBADDR LTC4162_JEITA_T3_REG_SUBADDR //!< @ref LTC4162_JEITA_T3 "JEITA_T3"
#define LTC4162_JEITA_T3_SIZE 16u
#define LTC4162_JEITA_T3_OFFSET 0u
#define LTC4162_JEITA_T3_MASK 0xFFFFu
#define LTC4162_JEITA_T3_DEFAULT 7970u
#define LTC4162_JEITA_T3_DECODE(register_data) (register_data)
#define LTC4162_JEITA_T3 (LTC4162_JEITA_T3_OFFSET << 12 | (LTC4162_JEITA_T3_SIZE - 1) << 8 | LTC4162_JEITA_T3_SUBADDR)
//!@}

/*! @defgroup LTC4162_JEITA_T4_REG JEITA_T4_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T4_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | JEITA_T4 |
 *
 *   - CommandCode: 0x22
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_T4 "JEITA_T4" : Signed number that sets the JEITA temperature region transition temperature T4 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7112 maps to about 45°C for the expected thermistor β value of 3490K.
*/

//!@{
#define LTC4162_JEITA_T4_REG_SUBADDR 0x22u
#define LTC4162_JEITA_T4_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_T4_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_T4 JEITA_T4
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T4 Bit Field
 *
 *  Signed number that sets the JEITA temperature region transition temperature T4 between JEITA regions R3 and R4. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 7112 maps to about 45°C for the expected thermistor β value of 3490K.
 *   - Register: @ref LTC4162_JEITA_T4_REG "JEITA_T4_REG"
 *   - CommandCode: 0x22
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 7112
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_JEITA_T4_SUBADDR LTC4162_JEITA_T4_REG_SUBADDR //!< @ref LTC4162_JEITA_T4 "JEITA_T4"
#define LTC4162_JEITA_T4_SIZE 16u
#define LTC4162_JEITA_T4_OFFSET 0u
#define LTC4162_JEITA_T4_MASK 0xFFFFu
#define LTC4162_JEITA_T4_DEFAULT 7112u
#define LTC4162_JEITA_T4_DECODE(register_data) (register_data)
#define LTC4162_JEITA_T4 (LTC4162_JEITA_T4_OFFSET << 12 | (LTC4162_JEITA_T4_SIZE - 1) << 8 | LTC4162_JEITA_T4_SUBADDR)
//!@}

/*! @defgroup LTC4162_JEITA_T5_REG JEITA_T5_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T5_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | JEITA_T5 |
 *
 *   - CommandCode: 0x23
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_T5 "JEITA_T5" : Signed number that sets the JEITA temperature region transition temperature T5 between JEITA regions R5 and R6. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 6325 maps to about 50°C for the expected thermistor β value of 3490K.
*/

//!@{
#define LTC4162_JEITA_T5_REG_SUBADDR 0x23u
#define LTC4162_JEITA_T5_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_T5_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_T5 JEITA_T5
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T5 Bit Field
 *
 *  Signed number that sets the JEITA temperature region transition temperature T5 between JEITA regions R5 and R6. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 6325 maps to about 50°C for the expected thermistor β value of 3490K.
 *   - Register: @ref LTC4162_JEITA_T5_REG "JEITA_T5_REG"
 *   - CommandCode: 0x23
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 6325
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_JEITA_T5_SUBADDR LTC4162_JEITA_T5_REG_SUBADDR //!< @ref LTC4162_JEITA_T5 "JEITA_T5"
#define LTC4162_JEITA_T5_SIZE 16u
#define LTC4162_JEITA_T5_OFFSET 0u
#define LTC4162_JEITA_T5_MASK 0xFFFFu
#define LTC4162_JEITA_T5_DEFAULT 6325u
#define LTC4162_JEITA_T5_DECODE(register_data) (register_data)
#define LTC4162_JEITA_T5 (LTC4162_JEITA_T5_OFFSET << 12 | (LTC4162_JEITA_T5_SIZE - 1) << 8 | LTC4162_JEITA_T5_SUBADDR)
//!@}

/*! @defgroup LTC4162_JEITA_T6_REG JEITA_T6_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T6_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | JEITA_T6 |
 *
 *   - CommandCode: 0x24
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_T6 "JEITA_T6" : Signed number that sets the JEITA temperature region transition temperature T6 between JEITA regions R6 and R7. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 4970 maps to about 60°C for the expected thermistor β value of 3490K.
*/

//!@{
#define LTC4162_JEITA_T6_REG_SUBADDR 0x24u
#define LTC4162_JEITA_T6_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_T6_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_T6 JEITA_T6
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_T6 Bit Field
 *
 *  Signed number that sets the JEITA temperature region transition temperature T6 between JEITA regions R6 and R7. The temperature is based on the thermistor reading from the telemetry system; RNTC = RNTCBIAS × (21829 - thermistor_voltage) / thermistor_voltage. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. The default value of 4970 maps to about 60°C for the expected thermistor β value of 3490K.
 *   - Register: @ref LTC4162_JEITA_T6_REG "JEITA_T6_REG"
 *   - CommandCode: 0x24
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R/W
 *   - Default: 4970
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_JEITA_T6_SUBADDR LTC4162_JEITA_T6_REG_SUBADDR //!< @ref LTC4162_JEITA_T6 "JEITA_T6"
#define LTC4162_JEITA_T6_SIZE 16u
#define LTC4162_JEITA_T6_OFFSET 0u
#define LTC4162_JEITA_T6_MASK 0xFFFFu
#define LTC4162_JEITA_T6_DEFAULT 4970u
#define LTC4162_JEITA_T6_DECODE(register_data) (register_data)
#define LTC4162_JEITA_T6 (LTC4162_JEITA_T6_OFFSET << 12 | (LTC4162_JEITA_T6_SIZE - 1) << 8 | LTC4162_JEITA_T6_SUBADDR)
//!@}

/*! @defgroup LTC4162_VCHARGE_JEITA_6_5_REG VCHARGE_JEITA_6_5_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_6_5_REG Register
 *
 * | 15:10 |             9:5 |             4:0 |
 * |:-----:|:---------------:|:---------------:|
 * |   n/a | VCHARGE_JEITA_6 | VCHARGE_JEITA_5 |
 *
 * vcharge_setting values for JEITA temperature regions jeita_t6 and jeita_t5
 *   - CommandCode: 0x25
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VCHARGE_JEITA_6 "VCHARGE_JEITA_6" : Sets the charge voltage to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_6 × 12.5mV + 3.8125V. The default value of 19 corresponds to 4.05V.
 *     + @ref LTC4162_VCHARGE_JEITA_5 "VCHARGE_JEITA_5" : Sets the charge voltage to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_5 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V.
*/

//!@{
#define LTC4162_VCHARGE_JEITA_6_5_REG_SUBADDR 0x25u
#define LTC4162_VCHARGE_JEITA_6_5_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_6_5_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_JEITA_6 VCHARGE_JEITA_6
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_6 Bit Field
 *
 *  Sets the charge voltage to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_6 × 12.5mV + 3.8125V. The default value of 19 corresponds to 4.05V.
 *   - Register: @ref LTC4162_VCHARGE_JEITA_6_5_REG "VCHARGE_JEITA_6_5_REG"
 *   - CommandCode: 0x25
 *   - Size: 5
 *   - Offset: 5
 *   - MSB: 9
 *   - MASK: 0x03E0
 *   - Access: R/W
 *   - Default: 19
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_JEITA_6_SUBADDR LTC4162_VCHARGE_JEITA_6_5_REG_SUBADDR //!< @ref LTC4162_VCHARGE_JEITA_6 "VCHARGE_JEITA_6"
#define LTC4162_VCHARGE_JEITA_6_SIZE 5u
#define LTC4162_VCHARGE_JEITA_6_OFFSET 5u
#define LTC4162_VCHARGE_JEITA_6_MASK 0x03E0u
#define LTC4162_VCHARGE_JEITA_6_DEFAULT 19u
#define LTC4162_VCHARGE_JEITA_6_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_JEITA_6_MASK) >> LTC4162_VCHARGE_JEITA_6_OFFSET)
#define LTC4162_VCHARGE_JEITA_6 (LTC4162_VCHARGE_JEITA_6_OFFSET << 12 | (LTC4162_VCHARGE_JEITA_6_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_6_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_JEITA_5 VCHARGE_JEITA_5
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_5 Bit Field
 *
 *  Sets the charge voltage to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_5 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V.
 *   - Register: @ref LTC4162_VCHARGE_JEITA_6_5_REG "VCHARGE_JEITA_6_5_REG"
 *   - CommandCode: 0x25
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R/W
 *   - Default: 23
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_JEITA_5_SUBADDR LTC4162_VCHARGE_JEITA_6_5_REG_SUBADDR //!< @ref LTC4162_VCHARGE_JEITA_5 "VCHARGE_JEITA_5"
#define LTC4162_VCHARGE_JEITA_5_SIZE 5u
#define LTC4162_VCHARGE_JEITA_5_OFFSET 0u
#define LTC4162_VCHARGE_JEITA_5_MASK 0x001Fu
#define LTC4162_VCHARGE_JEITA_5_DEFAULT 23u
#define LTC4162_VCHARGE_JEITA_5_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_JEITA_5_MASK) >> LTC4162_VCHARGE_JEITA_5_OFFSET)
#define LTC4162_VCHARGE_JEITA_5 (LTC4162_VCHARGE_JEITA_5_OFFSET << 12 | (LTC4162_VCHARGE_JEITA_5_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_5_SUBADDR)
//!@}

/*! @defgroup LTC4162_VCHARGE_JEITA_4_3_2_REG VCHARGE_JEITA_4_3_2_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_4_3_2_REG Register
 *
 * |  15 |           14:10 |             9:5 |             4:0 |
 * |:---:|:---------------:|:---------------:|:---------------:|
 * | n/a | VCHARGE_JEITA_4 | VCHARGE_JEITA_3 | VCHARGE_JEITA_2 |
 *
 * vcharge_setting values for JEITA temperature regions jeita_t4, jeita_t3, and jeita_t2
 *   - CommandCode: 0x26
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VCHARGE_JEITA_4 "VCHARGE_JEITA_4" : Sets the charge voltage to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_4 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V
 *     + @ref LTC4162_VCHARGE_JEITA_3 "VCHARGE_JEITA_3" : Sets the charge voltage to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_3 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V.
 *     + @ref LTC4162_VCHARGE_JEITA_2 "VCHARGE_JEITA_2" : Sets the charge voltage to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_2 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V.
*/

//!@{
#define LTC4162_VCHARGE_JEITA_4_3_2_REG_SUBADDR 0x26u
#define LTC4162_VCHARGE_JEITA_4_3_2_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_4_3_2_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_JEITA_4 VCHARGE_JEITA_4
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_4 Bit Field
 *
 *  Sets the charge voltage to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_4 × 12.5mV + 3.8125V. The default value of 23 corresponds to 4.1V
 *   - Register: @ref LTC4162_VCHARGE_JEITA_4_3_2_REG "VCHARGE_JEITA_4_3_2_REG"
 *   - CommandCode: 0x26
 *   - Size: 5
 *   - Offset: 10
 *   - MSB: 14
 *   - MASK: 0x7C00
 *   - Access: R/W
 *   - Default: 23
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_JEITA_4_SUBADDR LTC4162_VCHARGE_JEITA_4_3_2_REG_SUBADDR //!< @ref LTC4162_VCHARGE_JEITA_4 "VCHARGE_JEITA_4"
#define LTC4162_VCHARGE_JEITA_4_SIZE 5u
#define LTC4162_VCHARGE_JEITA_4_OFFSET 10u
#define LTC4162_VCHARGE_JEITA_4_MASK 0x7C00u
#define LTC4162_VCHARGE_JEITA_4_DEFAULT 23u
#define LTC4162_VCHARGE_JEITA_4_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_JEITA_4_MASK) >> LTC4162_VCHARGE_JEITA_4_OFFSET)
#define LTC4162_VCHARGE_JEITA_4 (LTC4162_VCHARGE_JEITA_4_OFFSET << 12 | (LTC4162_VCHARGE_JEITA_4_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_4_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_JEITA_3 VCHARGE_JEITA_3
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_3 Bit Field
 *
 *  Sets the charge voltage to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_3 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V.
 *   - Register: @ref LTC4162_VCHARGE_JEITA_4_3_2_REG "VCHARGE_JEITA_4_3_2_REG"
 *   - CommandCode: 0x26
 *   - Size: 5
 *   - Offset: 5
 *   - MSB: 9
 *   - MASK: 0x03E0
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_JEITA_3_SUBADDR LTC4162_VCHARGE_JEITA_4_3_2_REG_SUBADDR //!< @ref LTC4162_VCHARGE_JEITA_3 "VCHARGE_JEITA_3"
#define LTC4162_VCHARGE_JEITA_3_SIZE 5u
#define LTC4162_VCHARGE_JEITA_3_OFFSET 5u
#define LTC4162_VCHARGE_JEITA_3_MASK 0x03E0u
#define LTC4162_VCHARGE_JEITA_3_DEFAULT 31u
#define LTC4162_VCHARGE_JEITA_3_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_JEITA_3_MASK) >> LTC4162_VCHARGE_JEITA_3_OFFSET)
#define LTC4162_VCHARGE_JEITA_3 (LTC4162_VCHARGE_JEITA_3_OFFSET << 12 | (LTC4162_VCHARGE_JEITA_3_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_3_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_JEITA_2 VCHARGE_JEITA_2
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_JEITA_2 Bit Field
 *
 *  Sets the charge voltage to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to vcharge_setting and can be calculated using vcharge_jeita_2 × 12.5mV + 3.8125V. The default value of 31 corresponds to 4.2V.
 *   - Register: @ref LTC4162_VCHARGE_JEITA_4_3_2_REG "VCHARGE_JEITA_4_3_2_REG"
 *   - CommandCode: 0x26
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_JEITA_2_SUBADDR LTC4162_VCHARGE_JEITA_4_3_2_REG_SUBADDR //!< @ref LTC4162_VCHARGE_JEITA_2 "VCHARGE_JEITA_2"
#define LTC4162_VCHARGE_JEITA_2_SIZE 5u
#define LTC4162_VCHARGE_JEITA_2_OFFSET 0u
#define LTC4162_VCHARGE_JEITA_2_MASK 0x001Fu
#define LTC4162_VCHARGE_JEITA_2_DEFAULT 31u
#define LTC4162_VCHARGE_JEITA_2_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_JEITA_2_MASK) >> LTC4162_VCHARGE_JEITA_2_OFFSET)
#define LTC4162_VCHARGE_JEITA_2 (LTC4162_VCHARGE_JEITA_2_OFFSET << 12 | (LTC4162_VCHARGE_JEITA_2_SIZE - 1) << 8 | LTC4162_VCHARGE_JEITA_2_SUBADDR)
//!@}

/*! @defgroup LTC4162_ICHARGE_JEITA_6_5_REG ICHARGE_JEITA_6_5_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_6_5_REG Register
 *
 * | 15:10 |             9:5 |             4:0 |
 * |:-----:|:---------------:|:---------------:|
 * |   n/a | ICHARGE_JEITA_6 | ICHARGE_JEITA_5 |
 *
 * charge_current_setting values for JEITA temperature regions jeita_t6 and jeita_t5
 *   - CommandCode: 0x27
 *   - Contains Bit Fields:
 *     + @ref LTC4162_ICHARGE_JEITA_6 "ICHARGE_JEITA_6" : Sets the charge current to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_6 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
 *     + @ref LTC4162_ICHARGE_JEITA_5 "ICHARGE_JEITA_5" : Sets the charge current to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_5 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
*/

//!@{
#define LTC4162_ICHARGE_JEITA_6_5_REG_SUBADDR 0x27u
#define LTC4162_ICHARGE_JEITA_6_5_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_6_5_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_ICHARGE_JEITA_6 ICHARGE_JEITA_6
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_6 Bit Field
 *
 *  Sets the charge current to be used in JEITA region 6 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_6 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
 *   - Register: @ref LTC4162_ICHARGE_JEITA_6_5_REG "ICHARGE_JEITA_6_5_REG"
 *   - CommandCode: 0x27
 *   - Size: 5
 *   - Offset: 5
 *   - MSB: 9
 *   - MASK: 0x03E0
 *   - Access: R/W
 *   - Default: 15
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_ICHARGE_JEITA_6_SUBADDR LTC4162_ICHARGE_JEITA_6_5_REG_SUBADDR //!< @ref LTC4162_ICHARGE_JEITA_6 "ICHARGE_JEITA_6"
#define LTC4162_ICHARGE_JEITA_6_SIZE 5u
#define LTC4162_ICHARGE_JEITA_6_OFFSET 5u
#define LTC4162_ICHARGE_JEITA_6_MASK 0x03E0u
#define LTC4162_ICHARGE_JEITA_6_DEFAULT 15u
#define LTC4162_ICHARGE_JEITA_6_DECODE(register_data) (((register_data) & LTC4162_ICHARGE_JEITA_6_MASK) >> LTC4162_ICHARGE_JEITA_6_OFFSET)
#define LTC4162_ICHARGE_JEITA_6 (LTC4162_ICHARGE_JEITA_6_OFFSET << 12 | (LTC4162_ICHARGE_JEITA_6_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_6_SUBADDR)
//!@}
/*! @defgroup LTC4162_ICHARGE_JEITA_5 ICHARGE_JEITA_5
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_5 Bit Field
 *
 *  Sets the charge current to be used in JEITA region 5 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_5 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
 *   - Register: @ref LTC4162_ICHARGE_JEITA_6_5_REG "ICHARGE_JEITA_6_5_REG"
 *   - CommandCode: 0x27
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R/W
 *   - Default: 15
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_ICHARGE_JEITA_5_SUBADDR LTC4162_ICHARGE_JEITA_6_5_REG_SUBADDR //!< @ref LTC4162_ICHARGE_JEITA_5 "ICHARGE_JEITA_5"
#define LTC4162_ICHARGE_JEITA_5_SIZE 5u
#define LTC4162_ICHARGE_JEITA_5_OFFSET 0u
#define LTC4162_ICHARGE_JEITA_5_MASK 0x001Fu
#define LTC4162_ICHARGE_JEITA_5_DEFAULT 15u
#define LTC4162_ICHARGE_JEITA_5_DECODE(register_data) (((register_data) & LTC4162_ICHARGE_JEITA_5_MASK) >> LTC4162_ICHARGE_JEITA_5_OFFSET)
#define LTC4162_ICHARGE_JEITA_5 (LTC4162_ICHARGE_JEITA_5_OFFSET << 12 | (LTC4162_ICHARGE_JEITA_5_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_5_SUBADDR)
//!@}

/*! @defgroup LTC4162_ICHARGE_JEITA_4_3_2_REG ICHARGE_JEITA_4_3_2_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_4_3_2_REG Register
 *
 * |  15 |           14:10 |             9:5 |             4:0 |
 * |:---:|:---------------:|:---------------:|:---------------:|
 * | n/a | ICHARGE_JEITA_4 | ICHARGE_JEITA_3 | ICHARGE_JEITA_2 |
 *
 * charge_current_setting value for JEITA temperature regions jeita_t4, jeita_t3, and jeita_t2
 *   - CommandCode: 0x28
 *   - Contains Bit Fields:
 *     + @ref LTC4162_ICHARGE_JEITA_4 "ICHARGE_JEITA_4" : Sets the charge current to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_4 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale.
 *     + @ref LTC4162_ICHARGE_JEITA_3 "ICHARGE_JEITA_3" : Sets the charge current to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the  charge current can be calculated using (icharge_jeita_3 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale.
 *     + @ref LTC4162_ICHARGE_JEITA_2 "ICHARGE_JEITA_2" : Sets the charge current to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_2 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
*/

//!@{
#define LTC4162_ICHARGE_JEITA_4_3_2_REG_SUBADDR 0x28u
#define LTC4162_ICHARGE_JEITA_4_3_2_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_4_3_2_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_ICHARGE_JEITA_4 ICHARGE_JEITA_4
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_4 Bit Field
 *
 *  Sets the charge current to be used in JEITA region 4 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_4 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale.
 *   - Register: @ref LTC4162_ICHARGE_JEITA_4_3_2_REG "ICHARGE_JEITA_4_3_2_REG"
 *   - CommandCode: 0x28
 *   - Size: 5
 *   - Offset: 10
 *   - MSB: 14
 *   - MASK: 0x7C00
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_ICHARGE_JEITA_4_SUBADDR LTC4162_ICHARGE_JEITA_4_3_2_REG_SUBADDR //!< @ref LTC4162_ICHARGE_JEITA_4 "ICHARGE_JEITA_4"
#define LTC4162_ICHARGE_JEITA_4_SIZE 5u
#define LTC4162_ICHARGE_JEITA_4_OFFSET 10u
#define LTC4162_ICHARGE_JEITA_4_MASK 0x7C00u
#define LTC4162_ICHARGE_JEITA_4_DEFAULT 31u
#define LTC4162_ICHARGE_JEITA_4_DECODE(register_data) (((register_data) & LTC4162_ICHARGE_JEITA_4_MASK) >> LTC4162_ICHARGE_JEITA_4_OFFSET)
#define LTC4162_ICHARGE_JEITA_4 (LTC4162_ICHARGE_JEITA_4_OFFSET << 12 | (LTC4162_ICHARGE_JEITA_4_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_4_SUBADDR)
//!@}
/*! @defgroup LTC4162_ICHARGE_JEITA_3 ICHARGE_JEITA_3
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_3 Bit Field
 *
 *  Sets the charge current to be used in JEITA region 3 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the  charge current can be calculated using (icharge_jeita_3 + 1) × 1mV / RSNSB. The default value of 31 corresponds to a VCSP-VCSN servo voltage of 32mV which is full scale.
 *   - Register: @ref LTC4162_ICHARGE_JEITA_4_3_2_REG "ICHARGE_JEITA_4_3_2_REG"
 *   - CommandCode: 0x28
 *   - Size: 5
 *   - Offset: 5
 *   - MSB: 9
 *   - MASK: 0x03E0
 *   - Access: R/W
 *   - Default: 31
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_ICHARGE_JEITA_3_SUBADDR LTC4162_ICHARGE_JEITA_4_3_2_REG_SUBADDR //!< @ref LTC4162_ICHARGE_JEITA_3 "ICHARGE_JEITA_3"
#define LTC4162_ICHARGE_JEITA_3_SIZE 5u
#define LTC4162_ICHARGE_JEITA_3_OFFSET 5u
#define LTC4162_ICHARGE_JEITA_3_MASK 0x03E0u
#define LTC4162_ICHARGE_JEITA_3_DEFAULT 31u
#define LTC4162_ICHARGE_JEITA_3_DECODE(register_data) (((register_data) & LTC4162_ICHARGE_JEITA_3_MASK) >> LTC4162_ICHARGE_JEITA_3_OFFSET)
#define LTC4162_ICHARGE_JEITA_3 (LTC4162_ICHARGE_JEITA_3_OFFSET << 12 | (LTC4162_ICHARGE_JEITA_3_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_3_SUBADDR)
//!@}
/*! @defgroup LTC4162_ICHARGE_JEITA_2 ICHARGE_JEITA_2
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_JEITA_2 Bit Field
 *
 *  Sets the charge current to be used in JEITA region 2 as illustrated in the JEITA Temperature Qualified Charging section. The value corresponds to charge_current_setting where the charge current can be calculated using (icharge_jeita_2 + 1) × 1mV / RSNSB. The default value of 15 corresponds to a VCSP-VCSN servo voltage of 16mV which is half scale or C/2.
 *   - Register: @ref LTC4162_ICHARGE_JEITA_4_3_2_REG "ICHARGE_JEITA_4_3_2_REG"
 *   - CommandCode: 0x28
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R/W
 *   - Default: 15
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_ICHARGE_JEITA_2_SUBADDR LTC4162_ICHARGE_JEITA_4_3_2_REG_SUBADDR //!< @ref LTC4162_ICHARGE_JEITA_2 "ICHARGE_JEITA_2"
#define LTC4162_ICHARGE_JEITA_2_SIZE 5u
#define LTC4162_ICHARGE_JEITA_2_OFFSET 0u
#define LTC4162_ICHARGE_JEITA_2_MASK 0x001Fu
#define LTC4162_ICHARGE_JEITA_2_DEFAULT 15u
#define LTC4162_ICHARGE_JEITA_2_DECODE(register_data) (((register_data) & LTC4162_ICHARGE_JEITA_2_MASK) >> LTC4162_ICHARGE_JEITA_2_OFFSET)
#define LTC4162_ICHARGE_JEITA_2 (LTC4162_ICHARGE_JEITA_2_OFFSET << 12 | (LTC4162_ICHARGE_JEITA_2_SIZE - 1) << 8 | LTC4162_ICHARGE_JEITA_2_SUBADDR)
//!@}

/*! @defgroup LTC4162_CHARGER_CONFIG_BITS_REG CHARGER_CONFIG_BITS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGER_CONFIG_BITS_REG Register
 *
 * | 15:3 |                2 |   1 |        0 |
 * |:----:|:----------------:|:---:|:--------:|
 * |  n/a | EN_C_OVER_X_TERM | n/a | EN_JEITA |
 *
 * Battery charger configuration settings
 *   - CommandCode: 0x29
 *   - Contains Bit Fields:
 *     + @ref LTC4162_EN_C_OVER_X_TERM "EN_C_OVER_X_TERM" : Enables charge current based (C/x) battery charger termination as set by ibat dropping to the c_over_x_threshold in constant_voltage.
 *     + @ref LTC4162_EN_JEITA "EN_JEITA" : Enables the JEITA temperature qualified charging system.
*/

//!@{
#define LTC4162_CHARGER_CONFIG_BITS_REG_SUBADDR 0x29u
#define LTC4162_CHARGER_CONFIG_BITS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHARGER_CONFIG_BITS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_C_OVER_X_TERM EN_C_OVER_X_TERM
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_C_OVER_X_TERM Bit Field
 *
 *  Enables charge current based (C/x) battery charger termination as set by ibat dropping to the c_over_x_threshold in constant_voltage.
 *   - Register: @ref LTC4162_CHARGER_CONFIG_BITS_REG "CHARGER_CONFIG_BITS_REG"
 *   - CommandCode: 0x29
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R/W
 *   - Default: 0
 */
//!@{
#define LTC4162_EN_C_OVER_X_TERM_SUBADDR LTC4162_CHARGER_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_EN_C_OVER_X_TERM "EN_C_OVER_X_TERM"
#define LTC4162_EN_C_OVER_X_TERM_SIZE 1u
#define LTC4162_EN_C_OVER_X_TERM_OFFSET 2u
#define LTC4162_EN_C_OVER_X_TERM_MASK 0x0004u
#define LTC4162_EN_C_OVER_X_TERM_DEFAULT 0u
#define LTC4162_EN_C_OVER_X_TERM_DECODE(register_data) (((register_data) & LTC4162_EN_C_OVER_X_TERM_MASK) >> LTC4162_EN_C_OVER_X_TERM_OFFSET)
#define LTC4162_EN_C_OVER_X_TERM (LTC4162_EN_C_OVER_X_TERM_OFFSET << 12 | (LTC4162_EN_C_OVER_X_TERM_SIZE - 1) << 8 | LTC4162_EN_C_OVER_X_TERM_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_JEITA EN_JEITA
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_JEITA Bit Field
 *
 *  Enables the JEITA temperature qualified charging system.
 *   - Register: @ref LTC4162_CHARGER_CONFIG_BITS_REG "CHARGER_CONFIG_BITS_REG"
 *   - CommandCode: 0x29
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R/W
 *   - Default: 1
 */
//!@{
#define LTC4162_EN_JEITA_SUBADDR LTC4162_CHARGER_CONFIG_BITS_REG_SUBADDR //!< @ref LTC4162_EN_JEITA "EN_JEITA"
#define LTC4162_EN_JEITA_SIZE 1u
#define LTC4162_EN_JEITA_OFFSET 0u
#define LTC4162_EN_JEITA_MASK 0x0001u
#define LTC4162_EN_JEITA_DEFAULT 1u
#define LTC4162_EN_JEITA_DECODE(register_data) (((register_data) & LTC4162_EN_JEITA_MASK) >> LTC4162_EN_JEITA_OFFSET)
#define LTC4162_EN_JEITA (LTC4162_EN_JEITA_OFFSET << 12 | (LTC4162_EN_JEITA_SIZE - 1) << 8 | LTC4162_EN_JEITA_SUBADDR)
//!@}

/*! @defgroup LTC4162_TCHARGETIMER_REG TCHARGETIMER_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TCHARGETIMER_REG Register
 *
 * |         15:0 |
 * |:------------:|
 * | TCHARGETIMER |
 *
 *   - CommandCode: 0x30
 *   - Contains Bit Fields:
 *     + @ref LTC4162_TCHARGETIMER "TCHARGETIMER" : If max_charge_time is written to a non zero value tchargetimer is the elapsed time in minutes since the beginning of a charge cycle. The LTC4162 will terminate charging when tchargetimer reaches the value in max_charge_time.
*/

//!@{
#define LTC4162_TCHARGETIMER_REG_SUBADDR 0x30u
#define LTC4162_TCHARGETIMER_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_TCHARGETIMER_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_TCHARGETIMER TCHARGETIMER
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TCHARGETIMER Bit Field
 *
 *  If max_charge_time is written to a non zero value tchargetimer is the elapsed time in minutes since the beginning of a charge cycle. The LTC4162 will terminate charging when tchargetimer reaches the value in max_charge_time.
 *   - Register: @ref LTC4162_TCHARGETIMER_REG "TCHARGETIMER_REG"
 *   - CommandCode: 0x30
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_TCHARGETIMER_SUBADDR LTC4162_TCHARGETIMER_REG_SUBADDR //!< @ref LTC4162_TCHARGETIMER "TCHARGETIMER"
#define LTC4162_TCHARGETIMER_SIZE 16u
#define LTC4162_TCHARGETIMER_OFFSET 0u
#define LTC4162_TCHARGETIMER_MASK 0xFFFFu
#define LTC4162_TCHARGETIMER_DEFAULT 0u
#define LTC4162_TCHARGETIMER_DECODE(register_data) (register_data)
#define LTC4162_TCHARGETIMER (LTC4162_TCHARGETIMER_OFFSET << 12 | (LTC4162_TCHARGETIMER_SIZE - 1) << 8 | LTC4162_TCHARGETIMER_SUBADDR)
//!@}

/*! @defgroup LTC4162_TCVTIMER_REG TCVTIMER_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TCVTIMER_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | TCVTIMER |
 *
 *   - CommandCode: 0x31
 *   - Contains Bit Fields:
 *     + @ref LTC4162_TCVTIMER "TCVTIMER" : This is the elapsed time in seconds since the battery charger has been in the constant_voltage phase of charging. If this value exceeds max_cv_time then charging is considered complete and will terminate.
*/

//!@{
#define LTC4162_TCVTIMER_REG_SUBADDR 0x31u
#define LTC4162_TCVTIMER_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_TCVTIMER_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_TCVTIMER TCVTIMER
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TCVTIMER Bit Field
 *
 *  This is the elapsed time in seconds since the battery charger has been in the constant_voltage phase of charging. If this value exceeds max_cv_time then charging is considered complete and will terminate.
 *   - Register: @ref LTC4162_TCVTIMER_REG "TCVTIMER_REG"
 *   - CommandCode: 0x31
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_TCVTIMER_SUBADDR LTC4162_TCVTIMER_REG_SUBADDR //!< @ref LTC4162_TCVTIMER "TCVTIMER"
#define LTC4162_TCVTIMER_SIZE 16u
#define LTC4162_TCVTIMER_OFFSET 0u
#define LTC4162_TCVTIMER_MASK 0xFFFFu
#define LTC4162_TCVTIMER_DEFAULT 0u
#define LTC4162_TCVTIMER_DECODE(register_data) (register_data)
#define LTC4162_TCVTIMER (LTC4162_TCVTIMER_OFFSET << 12 | (LTC4162_TCVTIMER_SIZE - 1) << 8 | LTC4162_TCVTIMER_SUBADDR)
//!@}

/*! @defgroup LTC4162_CHARGER_STATE_REG CHARGER_STATE_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGER_STATE_REG Register
 *
 * | 15:13 |          12:0 |
 * |:-----:|:-------------:|
 * |   n/a | CHARGER_STATE |
 *
 *   - CommandCode: 0x34
 *   - Contains Bit Fields:
 *     + @ref LTC4162_CHARGER_STATE "CHARGER_STATE" : Real time battery charger state indicator. Individual bits are mutually exclusive.
*/

//!@{
#define LTC4162_CHARGER_STATE_REG_SUBADDR 0x34u
#define LTC4162_CHARGER_STATE_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHARGER_STATE_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_CHARGER_STATE CHARGER_STATE
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGER_STATE Bit Field
 *
 *  Real time battery charger state indicator. Individual bits are mutually exclusive.
 *   - Register: @ref LTC4162_CHARGER_STATE_REG "CHARGER_STATE_REG"
 *   - CommandCode: 0x34
 *   - Size: 13
 *   - Offset: 0
 *   - MSB: 12
 *   - MASK: 0x1FFF
 *   - Access: R
 *   - Default: 256
 */
//!@{
#define LTC4162_CHARGER_STATE_SUBADDR LTC4162_CHARGER_STATE_REG_SUBADDR //!< @ref LTC4162_CHARGER_STATE "CHARGER_STATE"
#define LTC4162_CHARGER_STATE_SIZE 13u
#define LTC4162_CHARGER_STATE_OFFSET 0u
#define LTC4162_CHARGER_STATE_MASK 0x1FFFu
#define LTC4162_CHARGER_STATE_DEFAULT 256u
#define LTC4162_CHARGER_STATE_DECODE(register_data) (((register_data) & LTC4162_CHARGER_STATE_MASK) >> LTC4162_CHARGER_STATE_OFFSET)
#define LTC4162_CHARGER_STATE (LTC4162_CHARGER_STATE_OFFSET << 12 | (LTC4162_CHARGER_STATE_SIZE - 1) << 8 | LTC4162_CHARGER_STATE_SUBADDR)
#define LTC4162_CHARGER_STATE_ENUM_BAT_DETECT_FAILED_FAULT 4096u //!<Indicates that the battery charger is not charging due to an inability to source power during the battery detection test because either vin_uvcl_active or iin_limit_active regulation was true during the battery detection phase of a charge cycle.
#define LTC4162_CHARGER_STATE_ENUM_BATTERY_DETECTION 2048u //!<Indicates that the LTC4162 is in the battery detection phase of a charge cycle.
#define LTC4162_CHARGER_STATE_ENUM_CHARGER_SUSPENDED 256u //!<Indicates that the battery charging feature is currently suspended due to suspend_charger or has a thermistor_voltage above jeita_t1 or below jeita_t6.
#define LTC4162_CHARGER_STATE_ENUM_PRECHARGE 128u //!<Indicates that the LTC4162 is in the precondition phase of charging.
#define LTC4162_CHARGER_STATE_ENUM_CC_CV_CHARGE 64u //!<Indicates that the LTC4162 is in either the constant_current or constant_voltage phase of charging.
#define LTC4162_CHARGER_STATE_ENUM_NTC_PAUSE 32u //!<Indicates that charging is currently paused due to thermistor_voltage being above jeita_t1 or below jeita_t6 as set by the JEITA temperature qualified charging system. Recall that the thermistor has a negative temperature coefficient so jeita_t1, representing colder temperatures, will have the highest value and jeita_t6, representing warmer temperatures, will have the lowest value. jeita_t6 and jeita_t1 are still observed even if en_jeita is set to 0.
#define LTC4162_CHARGER_STATE_ENUM_TIMER_TERM 16u //!<Indicates that the battery charger is currently terminated due to tcvtimer reaching max_cv_time during a charge cycle.
#define LTC4162_CHARGER_STATE_ENUM_C_OVER_X_TERM 8u //!<Indicates that the battery charger is currently terminated due to ibat falling below the c_over_x_threshold (C/x detection) during the constant_voltage phase of charging as determined by c_over_x_threshold and en_c_over_x_term.
#define LTC4162_CHARGER_STATE_ENUM_MAX_CHARGE_TIME_FAULT 4u //!<Indicates that the battery charger is currently terminated due to tchargetimer reaching max_charge_time.
#define LTC4162_CHARGER_STATE_ENUM_BAT_MISSING_FAULT 2u //!<Indicates that the battery charger is not charging because no battery was found during the battery detection test at the beginning of a charge cycle or if, at any time, the thermistor_voltage goes above 21,684 indicating an open or missing thermistor.
#define LTC4162_CHARGER_STATE_ENUM_BAT_SHORT_FAULT 1u //!<Indicates that the battery charger is not charging because the battery was found to be shorted during the battery detection test at the beginning of a charge cycle.
//!@}

/*! @defgroup LTC4162_CHARGE_STATUS_REG CHARGE_STATUS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGE_STATUS_REG Register
 *
 * | 15:6 |           5:0 |
 * |:----:|:-------------:|
 * |  n/a | CHARGE_STATUS |
 *
 *   - CommandCode: 0x35
 *   - Contains Bit Fields:
 *     + @ref LTC4162_CHARGE_STATUS "CHARGE_STATUS" : Charge status indicator. Individual bits are mutually exclusive and are only active in charging states.
*/

//!@{
#define LTC4162_CHARGE_STATUS_REG_SUBADDR 0x35u
#define LTC4162_CHARGE_STATUS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHARGE_STATUS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_CHARGE_STATUS CHARGE_STATUS
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGE_STATUS Bit Field
 *
 *  Charge status indicator. Individual bits are mutually exclusive and are only active in charging states.
 *   - Register: @ref LTC4162_CHARGE_STATUS_REG "CHARGE_STATUS_REG"
 *   - CommandCode: 0x35
 *   - Size: 6
 *   - Offset: 0
 *   - MSB: 5
 *   - MASK: 0x003F
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CHARGE_STATUS_SUBADDR LTC4162_CHARGE_STATUS_REG_SUBADDR //!< @ref LTC4162_CHARGE_STATUS "CHARGE_STATUS"
#define LTC4162_CHARGE_STATUS_SIZE 6u
#define LTC4162_CHARGE_STATUS_OFFSET 0u
#define LTC4162_CHARGE_STATUS_MASK 0x003Fu
#define LTC4162_CHARGE_STATUS_DEFAULT 0u
#define LTC4162_CHARGE_STATUS_DECODE(register_data) (((register_data) & LTC4162_CHARGE_STATUS_MASK) >> LTC4162_CHARGE_STATUS_OFFSET)
#define LTC4162_CHARGE_STATUS (LTC4162_CHARGE_STATUS_OFFSET << 12 | (LTC4162_CHARGE_STATUS_SIZE - 1) << 8 | LTC4162_CHARGE_STATUS_SUBADDR)
#define LTC4162_CHARGE_STATUS_ENUM_ILIM_REG_ACTIVE 32u //!<May indicate that the switching regulator is currently controlling power delivery based on a safety current limit (~45mV from CSP to CSN). This should not occur under normal conditions and is likely the result of a circuit board fault. Alternately indicates that the switching regulator is in dropout (highest possible duty cycle) and is not regulating on any feedback control loop.
#define LTC4162_CHARGE_STATUS_ENUM_THERMAL_REG_ACTIVE 16u //!<Indicates that the icharge_dac has been automatically throttled because the die_temp has reached thermal_reg_start_temp.
#define LTC4162_CHARGE_STATUS_ENUM_VIN_UVCL_ACTIVE 8u //!<Indicates that the input voltage control loop is currently controlling power delivery to the battery based on the input_undervoltage_dac which normally targets input_undervoltage_setting. This control loop is manipulated internally when mppt_en is set.
#define LTC4162_CHARGE_STATUS_ENUM_IIN_LIMIT_ACTIVE 4u //!<Indicates that the input current control loop is currently controlling power delivery to the battery based on iin_limit_dac which normally targets iin_limit_target.
#define LTC4162_CHARGE_STATUS_ENUM_CONSTANT_CURRENT 2u //!<Indicates that the charge current control loop is currently controlling power delivery to the battery based on icharge_dac which normally targets charge_current_setting. This control loop is manipulated internally if en_jeita is true.
#define LTC4162_CHARGE_STATUS_ENUM_CONSTANT_VOLTAGE 1u //!<Indicates that the charge voltage control loop is currently controlling power delivery to the battery based on vcharge_dac which normally targets vcharge_setting. This control loop is manipulated internally if en_jeita is true.
#define LTC4162_CHARGE_STATUS_ENUM_CHARGER_OFF 0u //!<Indicates that the charger is not currently running. Due to a logic error this state may transiently appear during normal operation. Sampling it several times is recommended.
//!@}

/*! @defgroup LTC4162_LIMIT_ALERTS_REG LIMIT_ALERTS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief LIMIT_ALERTS_REG Register
 *
 * |                    15 |             14 | 13:12 |            11 |            10 |            9 |            8 |             7 |             6 |            5 |             4 |                 3 |            2 |                           1 |                           0 |
 * |:---------------------:|:--------------:|:-----:|:-------------:|:-------------:|:------------:|:------------:|:-------------:|:-------------:|:------------:|:-------------:|:-----------------:|:------------:|:---------------------------:|:---------------------------:|
 * | TELEMETRY_VALID_ALERT | BSR_DONE_ALERT |   n/a | VBAT_LO_ALERT | VBAT_HI_ALERT | VIN_LO_ALERT | VIN_HI_ALERT | VOUT_LO_ALERT | VOUT_HI_ALERT | IIN_HI_ALERT | IBAT_LO_ALERT | DIE_TEMP_HI_ALERT | BSR_HI_ALERT | THERMISTOR_VOLTAGE_HI_ALERT | THERMISTOR_VOLTAGE_LO_ALERT |
 *
 * Limit alert register. This input/output register indicates that an enabled alert has occurred. Individual alerts are enabled in EN_LIMIT_ALERTS_REG. Writing 0 to any bit clears that alert. Once set, alert bits remain high until cleared or disabled.
 *   - CommandCode: 0x36
 *   - Contains Bit Fields:
 *     + @ref LTC4162_TELEMETRY_VALID_ALERT "TELEMETRY_VALID_ALERT" : Alert that indicates that the telemetry system warm-up time has expired and valid telemetry data is available from the serial port. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_telemetry_valid_alert.
 *     + @ref LTC4162_BSR_DONE_ALERT "BSR_DONE_ALERT" : Alert that indicates that the battery equivalent-series-resistance measurement is finished and a result is available in bsr. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bsr_done_alert.
 *     + @ref LTC4162_VBAT_LO_ALERT "VBAT_LO_ALERT" : Alert that indicates that vbat is below the value set by vbat_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vbat_lo_alert.
 *     + @ref LTC4162_VBAT_HI_ALERT "VBAT_HI_ALERT" : Alert that indicates that vbat is above the value set by vbat_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vbat_hi_alert.
 *     + @ref LTC4162_VIN_LO_ALERT "VIN_LO_ALERT" : Alert that indicates that vin is below the value set by vin_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_lo_alert.
 *     + @ref LTC4162_VIN_HI_ALERT "VIN_HI_ALERT" : Alert that indicates that vin is above the value set by vin_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_hi_alert.
 *     + @ref LTC4162_VOUT_LO_ALERT "VOUT_LO_ALERT" : Alert that indicates that vout is below the value set by vout_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vout_lo_alert.
 *     + @ref LTC4162_VOUT_HI_ALERT "VOUT_HI_ALERT" : Alert that indicates that vout is above the value set by vout_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vout_hi_alert.
 *     + @ref LTC4162_IIN_HI_ALERT "IIN_HI_ALERT" : Alert that indicates that iin is above the value set by iin_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_iin_hi_alert.
 *     + @ref LTC4162_IBAT_LO_ALERT "IBAT_LO_ALERT" : Alert that indicates that ibat is below the value set by ibat_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ibat_lo_alert.
 *     + @ref LTC4162_DIE_TEMP_HI_ALERT "DIE_TEMP_HI_ALERT" : Alert that indicates that die_temp is above the value set by die_temp_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_die_temp_hi_alert.
 *     + @ref LTC4162_BSR_HI_ALERT "BSR_HI_ALERT" : Alert that indicates that bsr is above the value set by bsr_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bsr_hi_alert.
 *     + @ref LTC4162_THERMISTOR_VOLTAGE_HI_ALERT "THERMISTOR_VOLTAGE_HI_ALERT" : Alert that indicates that thermistor_voltage is above the value set by thermistor_voltage_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermistor_voltage_hi_alert.
 *     + @ref LTC4162_THERMISTOR_VOLTAGE_LO_ALERT "THERMISTOR_VOLTAGE_LO_ALERT" : Alert that indicates that thermistor_voltage is below the value set by thermistor_voltage_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermistor_voltage_lo_alert.
*/

//!@{
#define LTC4162_LIMIT_ALERTS_REG_SUBADDR 0x36u
#define LTC4162_LIMIT_ALERTS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_LIMIT_ALERTS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_TELEMETRY_VALID_ALERT TELEMETRY_VALID_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TELEMETRY_VALID_ALERT Bit Field
 *
 *  Alert that indicates that the telemetry system warm-up time has expired and valid telemetry data is available from the serial port. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_telemetry_valid_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 15
 *   - MSB: 15
 *   - MASK: 0x8000
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_TELEMETRY_VALID_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_TELEMETRY_VALID_ALERT "TELEMETRY_VALID_ALERT"
#define LTC4162_TELEMETRY_VALID_ALERT_SIZE 1u
#define LTC4162_TELEMETRY_VALID_ALERT_OFFSET 15u
#define LTC4162_TELEMETRY_VALID_ALERT_MASK 0x8000u
#define LTC4162_TELEMETRY_VALID_ALERT_DEFAULT 0u
#define LTC4162_TELEMETRY_VALID_ALERT_DECODE(register_data) (((register_data) & LTC4162_TELEMETRY_VALID_ALERT_MASK) >> LTC4162_TELEMETRY_VALID_ALERT_OFFSET)
#define LTC4162_TELEMETRY_VALID_ALERT (LTC4162_TELEMETRY_VALID_ALERT_OFFSET << 12 | (LTC4162_TELEMETRY_VALID_ALERT_SIZE - 1) << 8 | LTC4162_TELEMETRY_VALID_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_BSR_DONE_ALERT BSR_DONE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_DONE_ALERT Bit Field
 *
 *  Alert that indicates that the battery equivalent-series-resistance measurement is finished and a result is available in bsr. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bsr_done_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 14
 *   - MSB: 14
 *   - MASK: 0x4000
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BSR_DONE_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_BSR_DONE_ALERT "BSR_DONE_ALERT"
#define LTC4162_BSR_DONE_ALERT_SIZE 1u
#define LTC4162_BSR_DONE_ALERT_OFFSET 14u
#define LTC4162_BSR_DONE_ALERT_MASK 0x4000u
#define LTC4162_BSR_DONE_ALERT_DEFAULT 0u
#define LTC4162_BSR_DONE_ALERT_DECODE(register_data) (((register_data) & LTC4162_BSR_DONE_ALERT_MASK) >> LTC4162_BSR_DONE_ALERT_OFFSET)
#define LTC4162_BSR_DONE_ALERT (LTC4162_BSR_DONE_ALERT_OFFSET << 12 | (LTC4162_BSR_DONE_ALERT_SIZE - 1) << 8 | LTC4162_BSR_DONE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VBAT_LO_ALERT VBAT_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_LO_ALERT Bit Field
 *
 *  Alert that indicates that vbat is below the value set by vbat_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vbat_lo_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 11
 *   - MSB: 11
 *   - MASK: 0x0800
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VBAT_LO_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_VBAT_LO_ALERT "VBAT_LO_ALERT"
#define LTC4162_VBAT_LO_ALERT_SIZE 1u
#define LTC4162_VBAT_LO_ALERT_OFFSET 11u
#define LTC4162_VBAT_LO_ALERT_MASK 0x0800u
#define LTC4162_VBAT_LO_ALERT_DEFAULT 0u
#define LTC4162_VBAT_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_VBAT_LO_ALERT_MASK) >> LTC4162_VBAT_LO_ALERT_OFFSET)
#define LTC4162_VBAT_LO_ALERT (LTC4162_VBAT_LO_ALERT_OFFSET << 12 | (LTC4162_VBAT_LO_ALERT_SIZE - 1) << 8 | LTC4162_VBAT_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VBAT_HI_ALERT VBAT_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_HI_ALERT Bit Field
 *
 *  Alert that indicates that vbat is above the value set by vbat_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vbat_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 10
 *   - MSB: 10
 *   - MASK: 0x0400
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VBAT_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_VBAT_HI_ALERT "VBAT_HI_ALERT"
#define LTC4162_VBAT_HI_ALERT_SIZE 1u
#define LTC4162_VBAT_HI_ALERT_OFFSET 10u
#define LTC4162_VBAT_HI_ALERT_MASK 0x0400u
#define LTC4162_VBAT_HI_ALERT_DEFAULT 0u
#define LTC4162_VBAT_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_VBAT_HI_ALERT_MASK) >> LTC4162_VBAT_HI_ALERT_OFFSET)
#define LTC4162_VBAT_HI_ALERT (LTC4162_VBAT_HI_ALERT_OFFSET << 12 | (LTC4162_VBAT_HI_ALERT_SIZE - 1) << 8 | LTC4162_VBAT_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_LO_ALERT VIN_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_LO_ALERT Bit Field
 *
 *  Alert that indicates that vin is below the value set by vin_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_lo_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 9
 *   - MSB: 9
 *   - MASK: 0x0200
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VIN_LO_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_VIN_LO_ALERT "VIN_LO_ALERT"
#define LTC4162_VIN_LO_ALERT_SIZE 1u
#define LTC4162_VIN_LO_ALERT_OFFSET 9u
#define LTC4162_VIN_LO_ALERT_MASK 0x0200u
#define LTC4162_VIN_LO_ALERT_DEFAULT 0u
#define LTC4162_VIN_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_VIN_LO_ALERT_MASK) >> LTC4162_VIN_LO_ALERT_OFFSET)
#define LTC4162_VIN_LO_ALERT (LTC4162_VIN_LO_ALERT_OFFSET << 12 | (LTC4162_VIN_LO_ALERT_SIZE - 1) << 8 | LTC4162_VIN_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_HI_ALERT VIN_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_HI_ALERT Bit Field
 *
 *  Alert that indicates that vin is above the value set by vin_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 8
 *   - MSB: 8
 *   - MASK: 0x0100
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VIN_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_VIN_HI_ALERT "VIN_HI_ALERT"
#define LTC4162_VIN_HI_ALERT_SIZE 1u
#define LTC4162_VIN_HI_ALERT_OFFSET 8u
#define LTC4162_VIN_HI_ALERT_MASK 0x0100u
#define LTC4162_VIN_HI_ALERT_DEFAULT 0u
#define LTC4162_VIN_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_VIN_HI_ALERT_MASK) >> LTC4162_VIN_HI_ALERT_OFFSET)
#define LTC4162_VIN_HI_ALERT (LTC4162_VIN_HI_ALERT_OFFSET << 12 | (LTC4162_VIN_HI_ALERT_SIZE - 1) << 8 | LTC4162_VIN_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VOUT_LO_ALERT VOUT_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_LO_ALERT Bit Field
 *
 *  Alert that indicates that vout is below the value set by vout_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vout_lo_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 7
 *   - MSB: 7
 *   - MASK: 0x0080
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VOUT_LO_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_VOUT_LO_ALERT "VOUT_LO_ALERT"
#define LTC4162_VOUT_LO_ALERT_SIZE 1u
#define LTC4162_VOUT_LO_ALERT_OFFSET 7u
#define LTC4162_VOUT_LO_ALERT_MASK 0x0080u
#define LTC4162_VOUT_LO_ALERT_DEFAULT 0u
#define LTC4162_VOUT_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_VOUT_LO_ALERT_MASK) >> LTC4162_VOUT_LO_ALERT_OFFSET)
#define LTC4162_VOUT_LO_ALERT (LTC4162_VOUT_LO_ALERT_OFFSET << 12 | (LTC4162_VOUT_LO_ALERT_SIZE - 1) << 8 | LTC4162_VOUT_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VOUT_HI_ALERT VOUT_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_HI_ALERT Bit Field
 *
 *  Alert that indicates that vout is above the value set by vout_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vout_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 6
 *   - MSB: 6
 *   - MASK: 0x0040
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VOUT_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_VOUT_HI_ALERT "VOUT_HI_ALERT"
#define LTC4162_VOUT_HI_ALERT_SIZE 1u
#define LTC4162_VOUT_HI_ALERT_OFFSET 6u
#define LTC4162_VOUT_HI_ALERT_MASK 0x0040u
#define LTC4162_VOUT_HI_ALERT_DEFAULT 0u
#define LTC4162_VOUT_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_VOUT_HI_ALERT_MASK) >> LTC4162_VOUT_HI_ALERT_OFFSET)
#define LTC4162_VOUT_HI_ALERT (LTC4162_VOUT_HI_ALERT_OFFSET << 12 | (LTC4162_VOUT_HI_ALERT_SIZE - 1) << 8 | LTC4162_VOUT_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_IIN_HI_ALERT IIN_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_HI_ALERT Bit Field
 *
 *  Alert that indicates that iin is above the value set by iin_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_iin_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_IIN_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_IIN_HI_ALERT "IIN_HI_ALERT"
#define LTC4162_IIN_HI_ALERT_SIZE 1u
#define LTC4162_IIN_HI_ALERT_OFFSET 5u
#define LTC4162_IIN_HI_ALERT_MASK 0x0020u
#define LTC4162_IIN_HI_ALERT_DEFAULT 0u
#define LTC4162_IIN_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_IIN_HI_ALERT_MASK) >> LTC4162_IIN_HI_ALERT_OFFSET)
#define LTC4162_IIN_HI_ALERT (LTC4162_IIN_HI_ALERT_OFFSET << 12 | (LTC4162_IIN_HI_ALERT_SIZE - 1) << 8 | LTC4162_IIN_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_IBAT_LO_ALERT IBAT_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IBAT_LO_ALERT Bit Field
 *
 *  Alert that indicates that ibat is below the value set by ibat_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ibat_lo_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_IBAT_LO_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_IBAT_LO_ALERT "IBAT_LO_ALERT"
#define LTC4162_IBAT_LO_ALERT_SIZE 1u
#define LTC4162_IBAT_LO_ALERT_OFFSET 4u
#define LTC4162_IBAT_LO_ALERT_MASK 0x0010u
#define LTC4162_IBAT_LO_ALERT_DEFAULT 0u
#define LTC4162_IBAT_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_IBAT_LO_ALERT_MASK) >> LTC4162_IBAT_LO_ALERT_OFFSET)
#define LTC4162_IBAT_LO_ALERT (LTC4162_IBAT_LO_ALERT_OFFSET << 12 | (LTC4162_IBAT_LO_ALERT_SIZE - 1) << 8 | LTC4162_IBAT_LO_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_DIE_TEMP_HI_ALERT DIE_TEMP_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief DIE_TEMP_HI_ALERT Bit Field
 *
 *  Alert that indicates that die_temp is above the value set by die_temp_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_die_temp_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_DIE_TEMP_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_DIE_TEMP_HI_ALERT "DIE_TEMP_HI_ALERT"
#define LTC4162_DIE_TEMP_HI_ALERT_SIZE 1u
#define LTC4162_DIE_TEMP_HI_ALERT_OFFSET 3u
#define LTC4162_DIE_TEMP_HI_ALERT_MASK 0x0008u
#define LTC4162_DIE_TEMP_HI_ALERT_DEFAULT 0u
#define LTC4162_DIE_TEMP_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_DIE_TEMP_HI_ALERT_MASK) >> LTC4162_DIE_TEMP_HI_ALERT_OFFSET)
#define LTC4162_DIE_TEMP_HI_ALERT (LTC4162_DIE_TEMP_HI_ALERT_OFFSET << 12 | (LTC4162_DIE_TEMP_HI_ALERT_SIZE - 1) << 8 | LTC4162_DIE_TEMP_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_BSR_HI_ALERT BSR_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_HI_ALERT Bit Field
 *
 *  Alert that indicates that bsr is above the value set by bsr_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bsr_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BSR_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_BSR_HI_ALERT "BSR_HI_ALERT"
#define LTC4162_BSR_HI_ALERT_SIZE 1u
#define LTC4162_BSR_HI_ALERT_OFFSET 2u
#define LTC4162_BSR_HI_ALERT_MASK 0x0004u
#define LTC4162_BSR_HI_ALERT_DEFAULT 0u
#define LTC4162_BSR_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_BSR_HI_ALERT_MASK) >> LTC4162_BSR_HI_ALERT_OFFSET)
#define LTC4162_BSR_HI_ALERT (LTC4162_BSR_HI_ALERT_OFFSET << 12 | (LTC4162_BSR_HI_ALERT_SIZE - 1) << 8 | LTC4162_BSR_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_HI_ALERT THERMISTOR_VOLTAGE_HI_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_HI_ALERT Bit Field
 *
 *  Alert that indicates that thermistor_voltage is above the value set by thermistor_voltage_hi_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermistor_voltage_hi_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_THERMISTOR_VOLTAGE_HI_ALERT "THERMISTOR_VOLTAGE_HI_ALERT"
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_SIZE 1u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET 1u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_MASK 0x0002u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_DEFAULT 0u
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_DECODE(register_data) (((register_data) & LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_MASK) >> LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET)
#define LTC4162_THERMISTOR_VOLTAGE_HI_ALERT (LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_OFFSET << 12 | (LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_HI_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_LO_ALERT THERMISTOR_VOLTAGE_LO_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_LO_ALERT Bit Field
 *
 *  Alert that indicates that thermistor_voltage is below the value set by thermistor_voltage_lo_alert_limit. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermistor_voltage_lo_alert.
 *   - Register: @ref LTC4162_LIMIT_ALERTS_REG "LIMIT_ALERTS_REG"
 *   - CommandCode: 0x36
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_SUBADDR LTC4162_LIMIT_ALERTS_REG_SUBADDR //!< @ref LTC4162_THERMISTOR_VOLTAGE_LO_ALERT "THERMISTOR_VOLTAGE_LO_ALERT"
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_SIZE 1u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET 0u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_MASK 0x0001u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_DEFAULT 0u
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_DECODE(register_data) (((register_data) & LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_MASK) >> LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET)
#define LTC4162_THERMISTOR_VOLTAGE_LO_ALERT (LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_OFFSET << 12 | (LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_LO_ALERT_SUBADDR)
//!@}

/*! @defgroup LTC4162_CHARGER_STATE_ALERTS_REG CHARGER_STATE_ALERTS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGER_STATE_ALERTS_REG Register
 *
 * | 15:13 |                            12 |                      11 | 10:9 |                       8 |               7 |                  6 |               5 |                4 |                   3 |                           2 |                       1 |                     0 |
 * |:-----:|:-----------------------------:|:-----------------------:|:----:|:-----------------------:|:---------------:|:------------------:|:---------------:|:----------------:|:-------------------:|:---------------------------:|:-----------------------:|:---------------------:|
 * |   n/a | BAT_DETECT_FAILED_FAULT_ALERT | BATTERY_DETECTION_ALERT |  n/a | CHARGER_SUSPENDED_ALERT | PRECHARGE_ALERT | CC_CV_CHARGE_ALERT | NTC_PAUSE_ALERT | TIMER_TERM_ALERT | C_OVER_X_TERM_ALERT | MAX_CHARGE_TIME_FAULT_ALERT | BAT_MISSING_FAULT_ALERT | BAT_SHORT_FAULT_ALERT |
 *
 * Alert that indicates that charger states have occurred. Individual bits are enabled by EN_CHARGER_STATE_ALERTS_REG. Writing 0 to any bit while writing 1s to the remaining bits clears that alert. Once set, alert bits remain high until cleared or disabled.
 *   - CommandCode: 0x37
 *   - Contains Bit Fields:
 *     + @ref LTC4162_BAT_DETECT_FAILED_FAULT_ALERT "BAT_DETECT_FAILED_FAULT_ALERT" : Alert that indicates a bat_detect_failed_fault. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_detect_failed_fault_alert.
 *     + @ref LTC4162_BATTERY_DETECTION_ALERT "BATTERY_DETECTION_ALERT" : Alert that indicates the battery charger is performing battery_detection. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_battery_detecttion_alert.
 *     + @ref LTC4162_CHARGER_SUSPENDED_ALERT "CHARGER_SUSPENDED_ALERT" : Alert that indicates the battery charger is in the charger_suspended state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_charger_suspended_alert.
 *     + @ref LTC4162_PRECHARGE_ALERT "PRECHARGE_ALERT" : Alert that indicates that the battery charger is in the precharge phase. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_precharge_alert.
 *     + @ref LTC4162_CC_CV_CHARGE_ALERT "CC_CV_CHARGE_ALERT" : Alert that indicates that the battery charge is in the cc_cv_charge phase. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_cc_cv_charge_alert.
 *     + @ref LTC4162_NTC_PAUSE_ALERT "NTC_PAUSE_ALERT" : Alert that indicates that the battery charger is in the ntc_pause state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ntc_pause_alert.
 *     + @ref LTC4162_TIMER_TERM_ALERT "TIMER_TERM_ALERT" : Alert that indicates that the battery charge is in the timer_term state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_timer_term_alert.
 *     + @ref LTC4162_C_OVER_X_TERM_ALERT "C_OVER_X_TERM_ALERT" : Alert that indicates that the battery charge is in the c_over_x_term state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_c_over_x_term_alert.
 *     + @ref LTC4162_MAX_CHARGE_TIME_FAULT_ALERT "MAX_CHARGE_TIME_FAULT_ALERT" : Alert that indicates that the battery charge is in the max_charge_time_fault state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_max_charge_time_alert.
 *     + @ref LTC4162_BAT_MISSING_FAULT_ALERT "BAT_MISSING_FAULT_ALERT" : Alert that indicates that a bat_missing_fault has been detected. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_missing_fault_alert.
 *     + @ref LTC4162_BAT_SHORT_FAULT_ALERT "BAT_SHORT_FAULT_ALERT" : Alert that indicates that a bat_short_fault has been detected. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_short_fault_alert.
*/

//!@{
#define LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR 0x37u
#define LTC4162_CHARGER_STATE_ALERTS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_BAT_DETECT_FAILED_FAULT_ALERT BAT_DETECT_FAILED_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BAT_DETECT_FAILED_FAULT_ALERT Bit Field
 *
 *  Alert that indicates a bat_detect_failed_fault. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_detect_failed_fault_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 12
 *   - MSB: 12
 *   - MASK: 0x1000
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_BAT_DETECT_FAILED_FAULT_ALERT "BAT_DETECT_FAILED_FAULT_ALERT"
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_SIZE 1u
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET 12u
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_MASK 0x1000u
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_DEFAULT 0u
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_MASK) >> LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET)
#define LTC4162_BAT_DETECT_FAILED_FAULT_ALERT (LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_OFFSET << 12 | (LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_BAT_DETECT_FAILED_FAULT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_BATTERY_DETECTION_ALERT BATTERY_DETECTION_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BATTERY_DETECTION_ALERT Bit Field
 *
 *  Alert that indicates the battery charger is performing battery_detection. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_battery_detecttion_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 11
 *   - MSB: 11
 *   - MASK: 0x0800
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BATTERY_DETECTION_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_BATTERY_DETECTION_ALERT "BATTERY_DETECTION_ALERT"
#define LTC4162_BATTERY_DETECTION_ALERT_SIZE 1u
#define LTC4162_BATTERY_DETECTION_ALERT_OFFSET 11u
#define LTC4162_BATTERY_DETECTION_ALERT_MASK 0x0800u
#define LTC4162_BATTERY_DETECTION_ALERT_DEFAULT 0u
#define LTC4162_BATTERY_DETECTION_ALERT_DECODE(register_data) (((register_data) & LTC4162_BATTERY_DETECTION_ALERT_MASK) >> LTC4162_BATTERY_DETECTION_ALERT_OFFSET)
#define LTC4162_BATTERY_DETECTION_ALERT (LTC4162_BATTERY_DETECTION_ALERT_OFFSET << 12 | (LTC4162_BATTERY_DETECTION_ALERT_SIZE - 1) << 8 | LTC4162_BATTERY_DETECTION_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_CHARGER_SUSPENDED_ALERT CHARGER_SUSPENDED_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGER_SUSPENDED_ALERT Bit Field
 *
 *  Alert that indicates the battery charger is in the charger_suspended state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_charger_suspended_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 8
 *   - MSB: 8
 *   - MASK: 0x0100
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CHARGER_SUSPENDED_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_CHARGER_SUSPENDED_ALERT "CHARGER_SUSPENDED_ALERT"
#define LTC4162_CHARGER_SUSPENDED_ALERT_SIZE 1u
#define LTC4162_CHARGER_SUSPENDED_ALERT_OFFSET 8u
#define LTC4162_CHARGER_SUSPENDED_ALERT_MASK 0x0100u
#define LTC4162_CHARGER_SUSPENDED_ALERT_DEFAULT 0u
#define LTC4162_CHARGER_SUSPENDED_ALERT_DECODE(register_data) (((register_data) & LTC4162_CHARGER_SUSPENDED_ALERT_MASK) >> LTC4162_CHARGER_SUSPENDED_ALERT_OFFSET)
#define LTC4162_CHARGER_SUSPENDED_ALERT (LTC4162_CHARGER_SUSPENDED_ALERT_OFFSET << 12 | (LTC4162_CHARGER_SUSPENDED_ALERT_SIZE - 1) << 8 | LTC4162_CHARGER_SUSPENDED_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_PRECHARGE_ALERT PRECHARGE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief PRECHARGE_ALERT Bit Field
 *
 *  Alert that indicates that the battery charger is in the precharge phase. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_precharge_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 7
 *   - MSB: 7
 *   - MASK: 0x0080
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_PRECHARGE_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_PRECHARGE_ALERT "PRECHARGE_ALERT"
#define LTC4162_PRECHARGE_ALERT_SIZE 1u
#define LTC4162_PRECHARGE_ALERT_OFFSET 7u
#define LTC4162_PRECHARGE_ALERT_MASK 0x0080u
#define LTC4162_PRECHARGE_ALERT_DEFAULT 0u
#define LTC4162_PRECHARGE_ALERT_DECODE(register_data) (((register_data) & LTC4162_PRECHARGE_ALERT_MASK) >> LTC4162_PRECHARGE_ALERT_OFFSET)
#define LTC4162_PRECHARGE_ALERT (LTC4162_PRECHARGE_ALERT_OFFSET << 12 | (LTC4162_PRECHARGE_ALERT_SIZE - 1) << 8 | LTC4162_PRECHARGE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_CC_CV_CHARGE_ALERT CC_CV_CHARGE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CC_CV_CHARGE_ALERT Bit Field
 *
 *  Alert that indicates that the battery charge is in the cc_cv_charge phase. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_cc_cv_charge_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 6
 *   - MSB: 6
 *   - MASK: 0x0040
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CC_CV_CHARGE_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_CC_CV_CHARGE_ALERT "CC_CV_CHARGE_ALERT"
#define LTC4162_CC_CV_CHARGE_ALERT_SIZE 1u
#define LTC4162_CC_CV_CHARGE_ALERT_OFFSET 6u
#define LTC4162_CC_CV_CHARGE_ALERT_MASK 0x0040u
#define LTC4162_CC_CV_CHARGE_ALERT_DEFAULT 0u
#define LTC4162_CC_CV_CHARGE_ALERT_DECODE(register_data) (((register_data) & LTC4162_CC_CV_CHARGE_ALERT_MASK) >> LTC4162_CC_CV_CHARGE_ALERT_OFFSET)
#define LTC4162_CC_CV_CHARGE_ALERT (LTC4162_CC_CV_CHARGE_ALERT_OFFSET << 12 | (LTC4162_CC_CV_CHARGE_ALERT_SIZE - 1) << 8 | LTC4162_CC_CV_CHARGE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_NTC_PAUSE_ALERT NTC_PAUSE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief NTC_PAUSE_ALERT Bit Field
 *
 *  Alert that indicates that the battery charger is in the ntc_pause state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ntc_pause_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_NTC_PAUSE_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_NTC_PAUSE_ALERT "NTC_PAUSE_ALERT"
#define LTC4162_NTC_PAUSE_ALERT_SIZE 1u
#define LTC4162_NTC_PAUSE_ALERT_OFFSET 5u
#define LTC4162_NTC_PAUSE_ALERT_MASK 0x0020u
#define LTC4162_NTC_PAUSE_ALERT_DEFAULT 0u
#define LTC4162_NTC_PAUSE_ALERT_DECODE(register_data) (((register_data) & LTC4162_NTC_PAUSE_ALERT_MASK) >> LTC4162_NTC_PAUSE_ALERT_OFFSET)
#define LTC4162_NTC_PAUSE_ALERT (LTC4162_NTC_PAUSE_ALERT_OFFSET << 12 | (LTC4162_NTC_PAUSE_ALERT_SIZE - 1) << 8 | LTC4162_NTC_PAUSE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_TIMER_TERM_ALERT TIMER_TERM_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TIMER_TERM_ALERT Bit Field
 *
 *  Alert that indicates that the battery charge is in the timer_term state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_timer_term_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_TIMER_TERM_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_TIMER_TERM_ALERT "TIMER_TERM_ALERT"
#define LTC4162_TIMER_TERM_ALERT_SIZE 1u
#define LTC4162_TIMER_TERM_ALERT_OFFSET 4u
#define LTC4162_TIMER_TERM_ALERT_MASK 0x0010u
#define LTC4162_TIMER_TERM_ALERT_DEFAULT 0u
#define LTC4162_TIMER_TERM_ALERT_DECODE(register_data) (((register_data) & LTC4162_TIMER_TERM_ALERT_MASK) >> LTC4162_TIMER_TERM_ALERT_OFFSET)
#define LTC4162_TIMER_TERM_ALERT (LTC4162_TIMER_TERM_ALERT_OFFSET << 12 | (LTC4162_TIMER_TERM_ALERT_SIZE - 1) << 8 | LTC4162_TIMER_TERM_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_C_OVER_X_TERM_ALERT C_OVER_X_TERM_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief C_OVER_X_TERM_ALERT Bit Field
 *
 *  Alert that indicates that the battery charge is in the c_over_x_term state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_c_over_x_term_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_C_OVER_X_TERM_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_C_OVER_X_TERM_ALERT "C_OVER_X_TERM_ALERT"
#define LTC4162_C_OVER_X_TERM_ALERT_SIZE 1u
#define LTC4162_C_OVER_X_TERM_ALERT_OFFSET 3u
#define LTC4162_C_OVER_X_TERM_ALERT_MASK 0x0008u
#define LTC4162_C_OVER_X_TERM_ALERT_DEFAULT 0u
#define LTC4162_C_OVER_X_TERM_ALERT_DECODE(register_data) (((register_data) & LTC4162_C_OVER_X_TERM_ALERT_MASK) >> LTC4162_C_OVER_X_TERM_ALERT_OFFSET)
#define LTC4162_C_OVER_X_TERM_ALERT (LTC4162_C_OVER_X_TERM_ALERT_OFFSET << 12 | (LTC4162_C_OVER_X_TERM_ALERT_SIZE - 1) << 8 | LTC4162_C_OVER_X_TERM_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_MAX_CHARGE_TIME_FAULT_ALERT MAX_CHARGE_TIME_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief MAX_CHARGE_TIME_FAULT_ALERT Bit Field
 *
 *  Alert that indicates that the battery charge is in the max_charge_time_fault state. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_max_charge_time_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_MAX_CHARGE_TIME_FAULT_ALERT "MAX_CHARGE_TIME_FAULT_ALERT"
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_SIZE 1u
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_OFFSET 2u
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_MASK 0x0004u
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_DEFAULT 0u
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_MASK) >> LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_OFFSET)
#define LTC4162_MAX_CHARGE_TIME_FAULT_ALERT (LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_OFFSET << 12 | (LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_MAX_CHARGE_TIME_FAULT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_BAT_MISSING_FAULT_ALERT BAT_MISSING_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BAT_MISSING_FAULT_ALERT Bit Field
 *
 *  Alert that indicates that a bat_missing_fault has been detected. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_missing_fault_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BAT_MISSING_FAULT_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_BAT_MISSING_FAULT_ALERT "BAT_MISSING_FAULT_ALERT"
#define LTC4162_BAT_MISSING_FAULT_ALERT_SIZE 1u
#define LTC4162_BAT_MISSING_FAULT_ALERT_OFFSET 1u
#define LTC4162_BAT_MISSING_FAULT_ALERT_MASK 0x0002u
#define LTC4162_BAT_MISSING_FAULT_ALERT_DEFAULT 0u
#define LTC4162_BAT_MISSING_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_BAT_MISSING_FAULT_ALERT_MASK) >> LTC4162_BAT_MISSING_FAULT_ALERT_OFFSET)
#define LTC4162_BAT_MISSING_FAULT_ALERT (LTC4162_BAT_MISSING_FAULT_ALERT_OFFSET << 12 | (LTC4162_BAT_MISSING_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_BAT_MISSING_FAULT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_BAT_SHORT_FAULT_ALERT BAT_SHORT_FAULT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BAT_SHORT_FAULT_ALERT Bit Field
 *
 *  Alert that indicates that a bat_short_fault has been detected. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_bat_short_fault_alert.
 *   - Register: @ref LTC4162_CHARGER_STATE_ALERTS_REG "CHARGER_STATE_ALERTS_REG"
 *   - CommandCode: 0x37
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BAT_SHORT_FAULT_ALERT_SUBADDR LTC4162_CHARGER_STATE_ALERTS_REG_SUBADDR //!< @ref LTC4162_BAT_SHORT_FAULT_ALERT "BAT_SHORT_FAULT_ALERT"
#define LTC4162_BAT_SHORT_FAULT_ALERT_SIZE 1u
#define LTC4162_BAT_SHORT_FAULT_ALERT_OFFSET 0u
#define LTC4162_BAT_SHORT_FAULT_ALERT_MASK 0x0001u
#define LTC4162_BAT_SHORT_FAULT_ALERT_DEFAULT 0u
#define LTC4162_BAT_SHORT_FAULT_ALERT_DECODE(register_data) (((register_data) & LTC4162_BAT_SHORT_FAULT_ALERT_MASK) >> LTC4162_BAT_SHORT_FAULT_ALERT_OFFSET)
#define LTC4162_BAT_SHORT_FAULT_ALERT (LTC4162_BAT_SHORT_FAULT_ALERT_OFFSET << 12 | (LTC4162_BAT_SHORT_FAULT_ALERT_SIZE - 1) << 8 | LTC4162_BAT_SHORT_FAULT_ALERT_SUBADDR)
//!@}

/*! @defgroup LTC4162_CHARGE_STATUS_ALERTS_REG CHARGE_STATUS_ALERTS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHARGE_STATUS_ALERTS_REG Register
 *
 * | 15:6 |                     5 |                        4 |                     3 |                      2 |                      1 |                      0 |
 * |:----:|:---------------------:|:------------------------:|:---------------------:|:----------------------:|:----------------------:|:----------------------:|
 * |  n/a | ILIM_REG_ACTIVE_ALERT | THERMAL_REG_ACTIVE_ALERT | VIN_UVCL_ACTIVE_ALERT | IIN_LIMIT_ACTIVE_ALERT | CONSTANT_CURRENT_ALERT | CONSTANT_VOLTAGE_ALERT |
 *
 * Alerts that charge_status indicators have occurred. Individual bits are enabled by EN_CHARGE_STATUS_ALERTS_REG. Writing 0 to any bit clears that alert. Once set, alert bits remain high until cleared or disabled.
 *   - CommandCode: 0x38
 *   - Contains Bit Fields:
 *     + @ref LTC4162_ILIM_REG_ACTIVE_ALERT "ILIM_REG_ACTIVE_ALERT" : Alert that indicates that charge_status is ilim_reg_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ilim_reg_active_alert.
 *     + @ref LTC4162_THERMAL_REG_ACTIVE_ALERT "THERMAL_REG_ACTIVE_ALERT" : Alert that indicates that charge_status is thermal_reg_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermal_reg_active_alert.
 *     + @ref LTC4162_VIN_UVCL_ACTIVE_ALERT "VIN_UVCL_ACTIVE_ALERT" : Alert that indicates that charge_status is vin_uvcl_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_uvcl_active_alert.
 *     + @ref LTC4162_IIN_LIMIT_ACTIVE_ALERT "IIN_LIMIT_ACTIVE_ALERT" : Alert that indicates that charge_status is iin_limit_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_iin_limit_active_alert.
 *     + @ref LTC4162_CONSTANT_CURRENT_ALERT "CONSTANT_CURRENT_ALERT" : Alert that indicates that charge_status is constant_current. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_constant_current_alert.
 *     + @ref LTC4162_CONSTANT_VOLTAGE_ALERT "CONSTANT_VOLTAGE_ALERT" : Alert that indicates that charge_status is constant_voltage. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_constant_voltage_alert.
*/

//!@{
#define LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR 0x38u
#define LTC4162_CHARGE_STATUS_ALERTS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_ILIM_REG_ACTIVE_ALERT ILIM_REG_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ILIM_REG_ACTIVE_ALERT Bit Field
 *
 *  Alert that indicates that charge_status is ilim_reg_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_ilim_reg_active_alert.
 *   - Register: @ref LTC4162_CHARGE_STATUS_ALERTS_REG "CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x38
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_ILIM_REG_ACTIVE_ALERT_SUBADDR LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_ILIM_REG_ACTIVE_ALERT "ILIM_REG_ACTIVE_ALERT"
#define LTC4162_ILIM_REG_ACTIVE_ALERT_SIZE 1u
#define LTC4162_ILIM_REG_ACTIVE_ALERT_OFFSET 5u
#define LTC4162_ILIM_REG_ACTIVE_ALERT_MASK 0x0020u
#define LTC4162_ILIM_REG_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_ILIM_REG_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_ILIM_REG_ACTIVE_ALERT_MASK) >> LTC4162_ILIM_REG_ACTIVE_ALERT_OFFSET)
#define LTC4162_ILIM_REG_ACTIVE_ALERT (LTC4162_ILIM_REG_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_ILIM_REG_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_ILIM_REG_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMAL_REG_ACTIVE_ALERT THERMAL_REG_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMAL_REG_ACTIVE_ALERT Bit Field
 *
 *  Alert that indicates that charge_status is thermal_reg_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_thermal_reg_active_alert.
 *   - Register: @ref LTC4162_CHARGE_STATUS_ALERTS_REG "CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x38
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_THERMAL_REG_ACTIVE_ALERT_SUBADDR LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_THERMAL_REG_ACTIVE_ALERT "THERMAL_REG_ACTIVE_ALERT"
#define LTC4162_THERMAL_REG_ACTIVE_ALERT_SIZE 1u
#define LTC4162_THERMAL_REG_ACTIVE_ALERT_OFFSET 4u
#define LTC4162_THERMAL_REG_ACTIVE_ALERT_MASK 0x0010u
#define LTC4162_THERMAL_REG_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_THERMAL_REG_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_THERMAL_REG_ACTIVE_ALERT_MASK) >> LTC4162_THERMAL_REG_ACTIVE_ALERT_OFFSET)
#define LTC4162_THERMAL_REG_ACTIVE_ALERT (LTC4162_THERMAL_REG_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_THERMAL_REG_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_THERMAL_REG_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_UVCL_ACTIVE_ALERT VIN_UVCL_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_UVCL_ACTIVE_ALERT Bit Field
 *
 *  Alert that indicates that charge_status is vin_uvcl_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_vin_uvcl_active_alert.
 *   - Register: @ref LTC4162_CHARGE_STATUS_ALERTS_REG "CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x38
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_VIN_UVCL_ACTIVE_ALERT_SUBADDR LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_VIN_UVCL_ACTIVE_ALERT "VIN_UVCL_ACTIVE_ALERT"
#define LTC4162_VIN_UVCL_ACTIVE_ALERT_SIZE 1u
#define LTC4162_VIN_UVCL_ACTIVE_ALERT_OFFSET 3u
#define LTC4162_VIN_UVCL_ACTIVE_ALERT_MASK 0x0008u
#define LTC4162_VIN_UVCL_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_VIN_UVCL_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_VIN_UVCL_ACTIVE_ALERT_MASK) >> LTC4162_VIN_UVCL_ACTIVE_ALERT_OFFSET)
#define LTC4162_VIN_UVCL_ACTIVE_ALERT (LTC4162_VIN_UVCL_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_VIN_UVCL_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_VIN_UVCL_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_IIN_LIMIT_ACTIVE_ALERT IIN_LIMIT_ACTIVE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_LIMIT_ACTIVE_ALERT Bit Field
 *
 *  Alert that indicates that charge_status is iin_limit_active. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_iin_limit_active_alert.
 *   - Register: @ref LTC4162_CHARGE_STATUS_ALERTS_REG "CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x38
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT_SUBADDR LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_IIN_LIMIT_ACTIVE_ALERT "IIN_LIMIT_ACTIVE_ALERT"
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT_SIZE 1u
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT_OFFSET 2u
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT_MASK 0x0004u
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT_DEFAULT 0u
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT_DECODE(register_data) (((register_data) & LTC4162_IIN_LIMIT_ACTIVE_ALERT_MASK) >> LTC4162_IIN_LIMIT_ACTIVE_ALERT_OFFSET)
#define LTC4162_IIN_LIMIT_ACTIVE_ALERT (LTC4162_IIN_LIMIT_ACTIVE_ALERT_OFFSET << 12 | (LTC4162_IIN_LIMIT_ACTIVE_ALERT_SIZE - 1) << 8 | LTC4162_IIN_LIMIT_ACTIVE_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_CONSTANT_CURRENT_ALERT CONSTANT_CURRENT_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CONSTANT_CURRENT_ALERT Bit Field
 *
 *  Alert that indicates that charge_status is constant_current. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_constant_current_alert.
 *   - Register: @ref LTC4162_CHARGE_STATUS_ALERTS_REG "CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x38
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CONSTANT_CURRENT_ALERT_SUBADDR LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_CONSTANT_CURRENT_ALERT "CONSTANT_CURRENT_ALERT"
#define LTC4162_CONSTANT_CURRENT_ALERT_SIZE 1u
#define LTC4162_CONSTANT_CURRENT_ALERT_OFFSET 1u
#define LTC4162_CONSTANT_CURRENT_ALERT_MASK 0x0002u
#define LTC4162_CONSTANT_CURRENT_ALERT_DEFAULT 0u
#define LTC4162_CONSTANT_CURRENT_ALERT_DECODE(register_data) (((register_data) & LTC4162_CONSTANT_CURRENT_ALERT_MASK) >> LTC4162_CONSTANT_CURRENT_ALERT_OFFSET)
#define LTC4162_CONSTANT_CURRENT_ALERT (LTC4162_CONSTANT_CURRENT_ALERT_OFFSET << 12 | (LTC4162_CONSTANT_CURRENT_ALERT_SIZE - 1) << 8 | LTC4162_CONSTANT_CURRENT_ALERT_SUBADDR)
//!@}
/*! @defgroup LTC4162_CONSTANT_VOLTAGE_ALERT CONSTANT_VOLTAGE_ALERT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CONSTANT_VOLTAGE_ALERT Bit Field
 *
 *  Alert that indicates that charge_status is constant_voltage. This alert bit is cleared by writing it back to 0 with the remaining bits in this register set to 1s. It can also be cleared by clearing en_constant_voltage_alert.
 *   - Register: @ref LTC4162_CHARGE_STATUS_ALERTS_REG "CHARGE_STATUS_ALERTS_REG"
 *   - CommandCode: 0x38
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CONSTANT_VOLTAGE_ALERT_SUBADDR LTC4162_CHARGE_STATUS_ALERTS_REG_SUBADDR //!< @ref LTC4162_CONSTANT_VOLTAGE_ALERT "CONSTANT_VOLTAGE_ALERT"
#define LTC4162_CONSTANT_VOLTAGE_ALERT_SIZE 1u
#define LTC4162_CONSTANT_VOLTAGE_ALERT_OFFSET 0u
#define LTC4162_CONSTANT_VOLTAGE_ALERT_MASK 0x0001u
#define LTC4162_CONSTANT_VOLTAGE_ALERT_DEFAULT 0u
#define LTC4162_CONSTANT_VOLTAGE_ALERT_DECODE(register_data) (((register_data) & LTC4162_CONSTANT_VOLTAGE_ALERT_MASK) >> LTC4162_CONSTANT_VOLTAGE_ALERT_OFFSET)
#define LTC4162_CONSTANT_VOLTAGE_ALERT (LTC4162_CONSTANT_VOLTAGE_ALERT_OFFSET << 12 | (LTC4162_CONSTANT_VOLTAGE_ALERT_SIZE - 1) << 8 | LTC4162_CONSTANT_VOLTAGE_ALERT_SUBADDR)
//!@}

/*! @defgroup LTC4162_SYSTEM_STATUS_REG SYSTEM_STATUS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief SYSTEM_STATUS_REG Register
 *
 * | 15:9 |      8 |              7 |   6 |     5 |                4 |        3 |           2 |           1 |              0 |
 * |:----:|:------:|:--------------:|:---:|:-----:|:----------------:|:--------:|:-----------:|:-----------:|:--------------:|
 * |  n/a | EN_CHG | CELL_COUNT_ERR | n/a | NO_RT | THERMAL_SHUTDOWN | VIN_OVLO | VIN_GT_VBAT | VIN_GT_4P2V | INTVCC_GT_2P8V |
 *
 * Real time system status indicator bits
 *   - CommandCode: 0x39
 *   - Contains Bit Fields:
 *     + @ref LTC4162_EN_CHG "EN_CHG" : Indicates that the battery charger is active.
 *     + @ref LTC4162_CELL_COUNT_ERR "CELL_COUNT_ERR" : A cell count error will occur and charging will be inhibited if the CELLS0 and CELLS1 pins are programmed for more than 8 cells. cell_count_err always indicates true when telemetry is not enabled such as when the charger is not enabled.
 *     + @ref LTC4162_NO_RT "NO_RT" : Indicates that no frequency setting resistor is detected on the RT pin. The RT pin impedance detection circuit will typically indicate a missing RT resistor for values above 1.4MΩ. no_rt always indicates true when the battery charger is not enabled such as when there is no input power available.
 *     + @ref LTC4162_THERMAL_SHUTDOWN "THERMAL_SHUTDOWN" : Indicates that the LTC4162 is in thermal shutdown protection due to an excessively high die temperature (typically 150°C).
 *     + @ref LTC4162_VIN_OVLO "VIN_OVLO" : Indicates that input voltage shutdown protection is active due to an input voltage above its protection shut-down threshold of approximately 38.6V.
 *     + @ref LTC4162_VIN_GT_VBAT "VIN_GT_VBAT" : Indicates that the VIN pin voltage is sufficiently above the battery voltage to begin a charge cycle (typically +150mV).
 *     + @ref LTC4162_VIN_GT_4P2V "VIN_GT_4P2V" : Indicates that the VIN pin voltage is at least greater than the switching regulator under-voltage lockout level (4.2V typical).
 *     + @ref LTC4162_INTVCC_GT_2P8V "INTVCC_GT_2P8V" : Indicates that the INTVCC pin voltage is greater than the telemetry system lockout level (2.8V typical).
*/

//!@{
#define LTC4162_SYSTEM_STATUS_REG_SUBADDR 0x39u
#define LTC4162_SYSTEM_STATUS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_SYSTEM_STATUS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_EN_CHG EN_CHG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief EN_CHG Bit Field
 *
 *  Indicates that the battery charger is active.
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 8
 *   - MSB: 8
 *   - MASK: 0x0100
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_EN_CHG_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_EN_CHG "EN_CHG"
#define LTC4162_EN_CHG_SIZE 1u
#define LTC4162_EN_CHG_OFFSET 8u
#define LTC4162_EN_CHG_MASK 0x0100u
#define LTC4162_EN_CHG_DEFAULT n/au
#define LTC4162_EN_CHG_DECODE(register_data) (((register_data) & LTC4162_EN_CHG_MASK) >> LTC4162_EN_CHG_OFFSET)
#define LTC4162_EN_CHG (LTC4162_EN_CHG_OFFSET << 12 | (LTC4162_EN_CHG_SIZE - 1) << 8 | LTC4162_EN_CHG_SUBADDR)
//!@}
/*! @defgroup LTC4162_CELL_COUNT_ERR CELL_COUNT_ERR
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CELL_COUNT_ERR Bit Field
 *
 *  A cell count error will occur and charging will be inhibited if the CELLS0 and CELLS1 pins are programmed for more than 8 cells. cell_count_err always indicates true when telemetry is not enabled such as when the charger is not enabled.
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 7
 *   - MSB: 7
 *   - MASK: 0x0080
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_CELL_COUNT_ERR_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_CELL_COUNT_ERR "CELL_COUNT_ERR"
#define LTC4162_CELL_COUNT_ERR_SIZE 1u
#define LTC4162_CELL_COUNT_ERR_OFFSET 7u
#define LTC4162_CELL_COUNT_ERR_MASK 0x0080u
#define LTC4162_CELL_COUNT_ERR_DEFAULT n/au
#define LTC4162_CELL_COUNT_ERR_DECODE(register_data) (((register_data) & LTC4162_CELL_COUNT_ERR_MASK) >> LTC4162_CELL_COUNT_ERR_OFFSET)
#define LTC4162_CELL_COUNT_ERR (LTC4162_CELL_COUNT_ERR_OFFSET << 12 | (LTC4162_CELL_COUNT_ERR_SIZE - 1) << 8 | LTC4162_CELL_COUNT_ERR_SUBADDR)
//!@}
/*! @defgroup LTC4162_NO_RT NO_RT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief NO_RT Bit Field
 *
 *  Indicates that no frequency setting resistor is detected on the RT pin. The RT pin impedance detection circuit will typically indicate a missing RT resistor for values above 1.4MΩ. no_rt always indicates true when the battery charger is not enabled such as when there is no input power available.
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 5
 *   - MSB: 5
 *   - MASK: 0x0020
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_NO_RT_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_NO_RT "NO_RT"
#define LTC4162_NO_RT_SIZE 1u
#define LTC4162_NO_RT_OFFSET 5u
#define LTC4162_NO_RT_MASK 0x0020u
#define LTC4162_NO_RT_DEFAULT n/au
#define LTC4162_NO_RT_DECODE(register_data) (((register_data) & LTC4162_NO_RT_MASK) >> LTC4162_NO_RT_OFFSET)
#define LTC4162_NO_RT (LTC4162_NO_RT_OFFSET << 12 | (LTC4162_NO_RT_SIZE - 1) << 8 | LTC4162_NO_RT_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMAL_SHUTDOWN THERMAL_SHUTDOWN
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMAL_SHUTDOWN Bit Field
 *
 *  Indicates that the LTC4162 is in thermal shutdown protection due to an excessively high die temperature (typically 150°C).
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 4
 *   - MSB: 4
 *   - MASK: 0x0010
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_THERMAL_SHUTDOWN_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_THERMAL_SHUTDOWN "THERMAL_SHUTDOWN"
#define LTC4162_THERMAL_SHUTDOWN_SIZE 1u
#define LTC4162_THERMAL_SHUTDOWN_OFFSET 4u
#define LTC4162_THERMAL_SHUTDOWN_MASK 0x0010u
#define LTC4162_THERMAL_SHUTDOWN_DEFAULT n/au
#define LTC4162_THERMAL_SHUTDOWN_DECODE(register_data) (((register_data) & LTC4162_THERMAL_SHUTDOWN_MASK) >> LTC4162_THERMAL_SHUTDOWN_OFFSET)
#define LTC4162_THERMAL_SHUTDOWN (LTC4162_THERMAL_SHUTDOWN_OFFSET << 12 | (LTC4162_THERMAL_SHUTDOWN_SIZE - 1) << 8 | LTC4162_THERMAL_SHUTDOWN_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_OVLO VIN_OVLO
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_OVLO Bit Field
 *
 *  Indicates that input voltage shutdown protection is active due to an input voltage above its protection shut-down threshold of approximately 38.6V.
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 3
 *   - MSB: 3
 *   - MASK: 0x0008
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_VIN_OVLO_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_VIN_OVLO "VIN_OVLO"
#define LTC4162_VIN_OVLO_SIZE 1u
#define LTC4162_VIN_OVLO_OFFSET 3u
#define LTC4162_VIN_OVLO_MASK 0x0008u
#define LTC4162_VIN_OVLO_DEFAULT n/au
#define LTC4162_VIN_OVLO_DECODE(register_data) (((register_data) & LTC4162_VIN_OVLO_MASK) >> LTC4162_VIN_OVLO_OFFSET)
#define LTC4162_VIN_OVLO (LTC4162_VIN_OVLO_OFFSET << 12 | (LTC4162_VIN_OVLO_SIZE - 1) << 8 | LTC4162_VIN_OVLO_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_GT_VBAT VIN_GT_VBAT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_GT_VBAT Bit Field
 *
 *  Indicates that the VIN pin voltage is sufficiently above the battery voltage to begin a charge cycle (typically +150mV).
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 2
 *   - MSB: 2
 *   - MASK: 0x0004
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_VIN_GT_VBAT_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_VIN_GT_VBAT "VIN_GT_VBAT"
#define LTC4162_VIN_GT_VBAT_SIZE 1u
#define LTC4162_VIN_GT_VBAT_OFFSET 2u
#define LTC4162_VIN_GT_VBAT_MASK 0x0004u
#define LTC4162_VIN_GT_VBAT_DEFAULT n/au
#define LTC4162_VIN_GT_VBAT_DECODE(register_data) (((register_data) & LTC4162_VIN_GT_VBAT_MASK) >> LTC4162_VIN_GT_VBAT_OFFSET)
#define LTC4162_VIN_GT_VBAT (LTC4162_VIN_GT_VBAT_OFFSET << 12 | (LTC4162_VIN_GT_VBAT_SIZE - 1) << 8 | LTC4162_VIN_GT_VBAT_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN_GT_4P2V VIN_GT_4P2V
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_GT_4P2V Bit Field
 *
 *  Indicates that the VIN pin voltage is at least greater than the switching regulator under-voltage lockout level (4.2V typical).
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_VIN_GT_4P2V_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_VIN_GT_4P2V "VIN_GT_4P2V"
#define LTC4162_VIN_GT_4P2V_SIZE 1u
#define LTC4162_VIN_GT_4P2V_OFFSET 1u
#define LTC4162_VIN_GT_4P2V_MASK 0x0002u
#define LTC4162_VIN_GT_4P2V_DEFAULT n/au
#define LTC4162_VIN_GT_4P2V_DECODE(register_data) (((register_data) & LTC4162_VIN_GT_4P2V_MASK) >> LTC4162_VIN_GT_4P2V_OFFSET)
#define LTC4162_VIN_GT_4P2V (LTC4162_VIN_GT_4P2V_OFFSET << 12 | (LTC4162_VIN_GT_4P2V_SIZE - 1) << 8 | LTC4162_VIN_GT_4P2V_SUBADDR)
//!@}
/*! @defgroup LTC4162_INTVCC_GT_2P8V INTVCC_GT_2P8V
 *  @ingroup LTC4162-LADM_register_map
 *  @brief INTVCC_GT_2P8V Bit Field
 *
 *  Indicates that the INTVCC pin voltage is greater than the telemetry system lockout level (2.8V typical).
 *   - Register: @ref LTC4162_SYSTEM_STATUS_REG "SYSTEM_STATUS_REG"
 *   - CommandCode: 0x39
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R
 *   - Default: n/a
 */
//!@{
#define LTC4162_INTVCC_GT_2P8V_SUBADDR LTC4162_SYSTEM_STATUS_REG_SUBADDR //!< @ref LTC4162_INTVCC_GT_2P8V "INTVCC_GT_2P8V"
#define LTC4162_INTVCC_GT_2P8V_SIZE 1u
#define LTC4162_INTVCC_GT_2P8V_OFFSET 0u
#define LTC4162_INTVCC_GT_2P8V_MASK 0x0001u
#define LTC4162_INTVCC_GT_2P8V_DEFAULT n/au
#define LTC4162_INTVCC_GT_2P8V_DECODE(register_data) (((register_data) & LTC4162_INTVCC_GT_2P8V_MASK) >> LTC4162_INTVCC_GT_2P8V_OFFSET)
#define LTC4162_INTVCC_GT_2P8V (LTC4162_INTVCC_GT_2P8V_OFFSET << 12 | (LTC4162_INTVCC_GT_2P8V_SIZE - 1) << 8 | LTC4162_INTVCC_GT_2P8V_SUBADDR)
//!@}

/*! @defgroup LTC4162_VBAT_REG VBAT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_REG Register
 *
 * | 15:0 |
 * |:----:|
 * | VBAT |
 *
 *   - CommandCode: 0x3A
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VBAT "VBAT" : Signed number that indicates the A/D measurement for the per-cell battery voltage. The value is based on the A/D scaling factor for the battery voltage measurement which is cell_count × 192.4µV/LSB at the BATSENS+ pin.
*/

//!@{
#define LTC4162_VBAT_REG_SUBADDR 0x3Au
#define LTC4162_VBAT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VBAT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VBAT VBAT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT Bit Field
 *
 *  Signed number that indicates the A/D measurement for the per-cell battery voltage. The value is based on the A/D scaling factor for the battery voltage measurement which is cell_count × 192.4µV/LSB at the BATSENS+ pin.
 *   - Register: @ref LTC4162_VBAT_REG "VBAT_REG"
 *   - CommandCode: 0x3A
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_VBAT_FORMAT
 */
//!@{
#define LTC4162_VBAT_SUBADDR LTC4162_VBAT_REG_SUBADDR //!< @ref LTC4162_VBAT "VBAT"
#define LTC4162_VBAT_SIZE 16u
#define LTC4162_VBAT_OFFSET 0u
#define LTC4162_VBAT_MASK 0xFFFFu
#define LTC4162_VBAT_DEFAULT 0u
#define LTC4162_VBAT_DECODE(register_data) (register_data)
#define LTC4162_VBAT (LTC4162_VBAT_OFFSET << 12 | (LTC4162_VBAT_SIZE - 1) << 8 | LTC4162_VBAT_SUBADDR)
//!@}

/*! @defgroup LTC4162_VIN_REG VIN_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN_REG Register
 *
 * | 15:0 |
 * |:----:|
 * |  VIN |
 *
 *   - CommandCode: 0x3B
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VIN "VIN" : Signed number that indicates the A/D measurement for the input voltage. The value is based on the A/D scaling factor for the input voltage measurement which is 1.649mV/LSB.
*/

//!@{
#define LTC4162_VIN_REG_SUBADDR 0x3Bu
#define LTC4162_VIN_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VIN_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VIN VIN
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VIN Bit Field
 *
 *  Signed number that indicates the A/D measurement for the input voltage. The value is based on the A/D scaling factor for the input voltage measurement which is 1.649mV/LSB.
 *   - Register: @ref LTC4162_VIN_REG "VIN_REG"
 *   - CommandCode: 0x3B
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_VIN_FORMAT
 */
//!@{
#define LTC4162_VIN_SUBADDR LTC4162_VIN_REG_SUBADDR //!< @ref LTC4162_VIN "VIN"
#define LTC4162_VIN_SIZE 16u
#define LTC4162_VIN_OFFSET 0u
#define LTC4162_VIN_MASK 0xFFFFu
#define LTC4162_VIN_DEFAULT 0u
#define LTC4162_VIN_DECODE(register_data) (register_data)
#define LTC4162_VIN (LTC4162_VIN_OFFSET << 12 | (LTC4162_VIN_SIZE - 1) << 8 | LTC4162_VIN_SUBADDR)
//!@}

/*! @defgroup LTC4162_VOUT_REG VOUT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT_REG Register
 *
 * | 15:0 |
 * |:----:|
 * | VOUT |
 *
 *   - CommandCode: 0x3C
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VOUT "VOUT" : Signed number that indicates the A/D measurement for the vout voltage. The value is based on the A/D scaling factor for the output voltage measurement which is 1.653mV/LSB.
*/

//!@{
#define LTC4162_VOUT_REG_SUBADDR 0x3Cu
#define LTC4162_VOUT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VOUT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VOUT VOUT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VOUT Bit Field
 *
 *  Signed number that indicates the A/D measurement for the vout voltage. The value is based on the A/D scaling factor for the output voltage measurement which is 1.653mV/LSB.
 *   - Register: @ref LTC4162_VOUT_REG "VOUT_REG"
 *   - CommandCode: 0x3C
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_VOUT_FORMAT
 */
//!@{
#define LTC4162_VOUT_SUBADDR LTC4162_VOUT_REG_SUBADDR //!< @ref LTC4162_VOUT "VOUT"
#define LTC4162_VOUT_SIZE 16u
#define LTC4162_VOUT_OFFSET 0u
#define LTC4162_VOUT_MASK 0xFFFFu
#define LTC4162_VOUT_DEFAULT 0u
#define LTC4162_VOUT_DECODE(register_data) (register_data)
#define LTC4162_VOUT (LTC4162_VOUT_OFFSET << 12 | (LTC4162_VOUT_SIZE - 1) << 8 | LTC4162_VOUT_SUBADDR)
//!@}

/*! @defgroup LTC4162_IBAT_REG IBAT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IBAT_REG Register
 *
 * | 15:0 |
 * |:----:|
 * | IBAT |
 *
 *   - CommandCode: 0x3D
 *   - Contains Bit Fields:
 *     + @ref LTC4162_IBAT "IBAT" : Signed number that indicates the A/D measurement for the battery current. The value is based on the A/D scaling factor for the charge current measurement (VCSP - VCSN) which is 1.466µV / RSNSB amperes/LSB. If the charger is not enabled the value represents drain on the battery and will be negative.
*/

//!@{
#define LTC4162_IBAT_REG_SUBADDR 0x3Du
#define LTC4162_IBAT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_IBAT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_IBAT IBAT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IBAT Bit Field
 *
 *  Signed number that indicates the A/D measurement for the battery current. The value is based on the A/D scaling factor for the charge current measurement (VCSP - VCSN) which is 1.466µV / RSNSB amperes/LSB. If the charger is not enabled the value represents drain on the battery and will be negative.
 *   - Register: @ref LTC4162_IBAT_REG "IBAT_REG"
 *   - CommandCode: 0x3D
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_IBAT_FORMAT
 */
//!@{
#define LTC4162_IBAT_SUBADDR LTC4162_IBAT_REG_SUBADDR //!< @ref LTC4162_IBAT "IBAT"
#define LTC4162_IBAT_SIZE 16u
#define LTC4162_IBAT_OFFSET 0u
#define LTC4162_IBAT_MASK 0xFFFFu
#define LTC4162_IBAT_DEFAULT 0u
#define LTC4162_IBAT_DECODE(register_data) (register_data)
#define LTC4162_IBAT (LTC4162_IBAT_OFFSET << 12 | (LTC4162_IBAT_SIZE - 1) << 8 | LTC4162_IBAT_SUBADDR)
//!@}

/*! @defgroup LTC4162_IIN_REG IIN_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_REG Register
 *
 * | 15:0 |
 * |:----:|
 * |  IIN |
 *
 *   - CommandCode: 0x3E
 *   - Contains Bit Fields:
 *     + @ref LTC4162_IIN "IIN" : Signed number that indicates the A/D measurement for the input current (VCLP - VCLN). The value is based on the A/D scaling factor for the input current measurement which is 1.466µV / RSNSI amperes/LSB.
*/

//!@{
#define LTC4162_IIN_REG_SUBADDR 0x3Eu
#define LTC4162_IIN_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_IIN_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_IIN IIN
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN Bit Field
 *
 *  Signed number that indicates the A/D measurement for the input current (VCLP - VCLN). The value is based on the A/D scaling factor for the input current measurement which is 1.466µV / RSNSI amperes/LSB.
 *   - Register: @ref LTC4162_IIN_REG "IIN_REG"
 *   - CommandCode: 0x3E
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_IIN_FORMAT
 */
//!@{
#define LTC4162_IIN_SUBADDR LTC4162_IIN_REG_SUBADDR //!< @ref LTC4162_IIN "IIN"
#define LTC4162_IIN_SIZE 16u
#define LTC4162_IIN_OFFSET 0u
#define LTC4162_IIN_MASK 0xFFFFu
#define LTC4162_IIN_DEFAULT 0u
#define LTC4162_IIN_DECODE(register_data) (register_data)
#define LTC4162_IIN (LTC4162_IIN_OFFSET << 12 | (LTC4162_IIN_SIZE - 1) << 8 | LTC4162_IIN_SUBADDR)
//!@}

/*! @defgroup LTC4162_DIE_TEMP_REG DIE_TEMP_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief DIE_TEMP_REG Register
 *
 * |     15:0 |
 * |:--------:|
 * | DIE_TEMP |
 *
 *   - CommandCode: 0x3F
 *   - Contains Bit Fields:
 *     + @ref LTC4162_DIE_TEMP "DIE_TEMP" : Signed number that indicates the A/D measurement for the die temperature. The value can be calculated from the A/D reading in °C as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C.
*/

//!@{
#define LTC4162_DIE_TEMP_REG_SUBADDR 0x3Fu
#define LTC4162_DIE_TEMP_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_DIE_TEMP_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_DIE_TEMP DIE_TEMP
 *  @ingroup LTC4162-LADM_register_map
 *  @brief DIE_TEMP Bit Field
 *
 *  Signed number that indicates the A/D measurement for the die temperature. The value can be calculated from the A/D reading in °C as TDIE(°C) = die_temp × 0.0215°C/LSB - 264.4°C.
 *   - Register: @ref LTC4162_DIE_TEMP_REG "DIE_TEMP_REG"
 *   - CommandCode: 0x3F
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_DIE_TEMP_FORMAT
 */
//!@{
#define LTC4162_DIE_TEMP_SUBADDR LTC4162_DIE_TEMP_REG_SUBADDR //!< @ref LTC4162_DIE_TEMP "DIE_TEMP"
#define LTC4162_DIE_TEMP_SIZE 16u
#define LTC4162_DIE_TEMP_OFFSET 0u
#define LTC4162_DIE_TEMP_MASK 0xFFFFu
#define LTC4162_DIE_TEMP_DEFAULT 0u
#define LTC4162_DIE_TEMP_DECODE(register_data) (register_data)
#define LTC4162_DIE_TEMP (LTC4162_DIE_TEMP_OFFSET << 12 | (LTC4162_DIE_TEMP_SIZE - 1) << 8 | LTC4162_DIE_TEMP_SUBADDR)
//!@}

/*! @defgroup LTC4162_THERMISTOR_VOLTAGE_REG THERMISTOR_VOLTAGE_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | THERMISTOR_VOLTAGE |
 *
 *   - CommandCode: 0x40
 *   - Contains Bit Fields:
 *     + @ref LTC4162_THERMISTOR_VOLTAGE "THERMISTOR_VOLTAGE" : Signed number that indicates the A/D measurement for the NTC pin voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × thermistor_voltage / (21829 - thermistor_voltage). Recall that the thermistor has a negative temperature coefficient so higher temperatures make lower thermistor_voltage readings and vice-versa.
*/

//!@{
#define LTC4162_THERMISTOR_VOLTAGE_REG_SUBADDR 0x40u
#define LTC4162_THERMISTOR_VOLTAGE_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_THERMISTOR_VOLTAGE THERMISTOR_VOLTAGE
 *  @ingroup LTC4162-LADM_register_map
 *  @brief THERMISTOR_VOLTAGE Bit Field
 *
 *  Signed number that indicates the A/D measurement for the NTC pin voltage. The thermistor value can be determined by the expression RNTC = RNTCBIAS × thermistor_voltage / (21829 - thermistor_voltage). Recall that the thermistor has a negative temperature coefficient so higher temperatures make lower thermistor_voltage readings and vice-versa.
 *   - Register: @ref LTC4162_THERMISTOR_VOLTAGE_REG "THERMISTOR_VOLTAGE_REG"
 *   - CommandCode: 0x40
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_NTCS0402E3103FLT
 */
//!@{
#define LTC4162_THERMISTOR_VOLTAGE_SUBADDR LTC4162_THERMISTOR_VOLTAGE_REG_SUBADDR //!< @ref LTC4162_THERMISTOR_VOLTAGE "THERMISTOR_VOLTAGE"
#define LTC4162_THERMISTOR_VOLTAGE_SIZE 16u
#define LTC4162_THERMISTOR_VOLTAGE_OFFSET 0u
#define LTC4162_THERMISTOR_VOLTAGE_MASK 0xFFFFu
#define LTC4162_THERMISTOR_VOLTAGE_DEFAULT 0u
#define LTC4162_THERMISTOR_VOLTAGE_DECODE(register_data) (register_data)
#define LTC4162_THERMISTOR_VOLTAGE (LTC4162_THERMISTOR_VOLTAGE_OFFSET << 12 | (LTC4162_THERMISTOR_VOLTAGE_SIZE - 1) << 8 | LTC4162_THERMISTOR_VOLTAGE_SUBADDR)
#define LTC4162_THERMISTOR_VOLTAGE_ENUM_OPEN_THERMISTOR 21684u
//!@}

/*! @defgroup LTC4162_BSR_REG BSR_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_REG Register
 *
 * | 15:0 |
 * |:----:|
 * |  BSR |
 *
 *   - CommandCode: 0x41
 *   - Contains Bit Fields:
 *     + @ref LTC4162_BSR "BSR" : Indicates the A/D measurement for the per-cell battery resistance. The battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from cell_count × bsr × RSNSB / 500. If the charge current, ibat, is below icharge_over_10, bsr_questionable will be set.
*/

//!@{
#define LTC4162_BSR_REG_SUBADDR 0x41u
#define LTC4162_BSR_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_BSR_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_BSR BSR
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR Bit Field
 *
 *  Indicates the A/D measurement for the per-cell battery resistance. The battery resistance is relative to the battery charge current setting resistor, RSNSB, and can be computed in Ω from cell_count × bsr × RSNSB / 500. If the charge current, ibat, is below icharge_over_10, bsr_questionable will be set.
 *   - Register: @ref LTC4162_BSR_REG "BSR_REG"
 *   - CommandCode: 0x41
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_BSR_FORMAT
 */
//!@{
#define LTC4162_BSR_SUBADDR LTC4162_BSR_REG_SUBADDR //!< @ref LTC4162_BSR "BSR"
#define LTC4162_BSR_SIZE 16u
#define LTC4162_BSR_OFFSET 0u
#define LTC4162_BSR_MASK 0xFFFFu
#define LTC4162_BSR_DEFAULT 0u
#define LTC4162_BSR_DECODE(register_data) (register_data)
#define LTC4162_BSR (LTC4162_BSR_OFFSET << 12 | (LTC4162_BSR_SIZE - 1) << 8 | LTC4162_BSR_SUBADDR)
//!@}

/*! @defgroup LTC4162_JEITA_REGION_REG JEITA_REGION_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_REGION_REG Register
 *
 * | 15:3 |          2:0 |
 * |:----:|:------------:|
 * |  n/a | JEITA_REGION |
 *
 *   - CommandCode: 0x42
 *   - Contains Bit Fields:
 *     + @ref LTC4162_JEITA_REGION "JEITA_REGION" : Indicates the LTC4162 JEITA battery temperature region containing the thermistor_voltage. The temperature region consists of the values bounded by the transition temperatures jeita_t(R-1) and jeita_t(R). Recall that the thermistor has a negative temperature coefficient so higher temperatures make lower thermistor_voltage readings and vice-versa. JEITA temperature-controlled charging is active only when en_jeita is at its default value of 1. JEITA regions R7 (jeita_region = 7) and R1 (jeita_region = 1) indicate that the thermistor_voltage (battery temperature) is out of range for charging and therefore charging is paused (ntc_pause). The transition temperatures are set by jeita_t1 through jeita_t6.
*/

//!@{
#define LTC4162_JEITA_REGION_REG_SUBADDR 0x42u
#define LTC4162_JEITA_REGION_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_JEITA_REGION_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_JEITA_REGION JEITA_REGION
 *  @ingroup LTC4162-LADM_register_map
 *  @brief JEITA_REGION Bit Field
 *
 *  Indicates the LTC4162 JEITA battery temperature region containing the thermistor_voltage. The temperature region consists of the values bounded by the transition temperatures jeita_t(R-1) and jeita_t(R). Recall that the thermistor has a negative temperature coefficient so higher temperatures make lower thermistor_voltage readings and vice-versa. JEITA temperature-controlled charging is active only when en_jeita is at its default value of 1. JEITA regions R7 (jeita_region = 7) and R1 (jeita_region = 1) indicate that the thermistor_voltage (battery temperature) is out of range for charging and therefore charging is paused (ntc_pause). The transition temperatures are set by jeita_t1 through jeita_t6.
 *   - Register: @ref LTC4162_JEITA_REGION_REG "JEITA_REGION_REG"
 *   - CommandCode: 0x42
 *   - Size: 3
 *   - Offset: 0
 *   - MSB: 2
 *   - MASK: 0x0007
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_JEITA_REGION_SUBADDR LTC4162_JEITA_REGION_REG_SUBADDR //!< @ref LTC4162_JEITA_REGION "JEITA_REGION"
#define LTC4162_JEITA_REGION_SIZE 3u
#define LTC4162_JEITA_REGION_OFFSET 0u
#define LTC4162_JEITA_REGION_MASK 0x0007u
#define LTC4162_JEITA_REGION_DEFAULT 0u
#define LTC4162_JEITA_REGION_DECODE(register_data) (((register_data) & LTC4162_JEITA_REGION_MASK) >> LTC4162_JEITA_REGION_OFFSET)
#define LTC4162_JEITA_REGION (LTC4162_JEITA_REGION_OFFSET << 12 | (LTC4162_JEITA_REGION_SIZE - 1) << 8 | LTC4162_JEITA_REGION_SUBADDR)
#define LTC4162_JEITA_REGION_ENUM_R7 7u
#define LTC4162_JEITA_REGION_ENUM_R6 6u
#define LTC4162_JEITA_REGION_ENUM_R5 5u
#define LTC4162_JEITA_REGION_ENUM_R4 4u
#define LTC4162_JEITA_REGION_ENUM_R3 3u
#define LTC4162_JEITA_REGION_ENUM_R2 2u
#define LTC4162_JEITA_REGION_ENUM_R1 1u
//!@}

/*! @defgroup LTC4162_CHEM_CELLS_REG CHEM_CELLS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHEM_CELLS_REG Register
 *
 * | 15:12 | 11:8 | 7:4 |        3:0 |
 * |:-----:|:----:|:---:|:----------:|
 * |   n/a | CHEM | n/a | CELL_COUNT |
 *
 * Programmed battery chemistry
 *   - CommandCode: 0x43
 *   - Contains Bit Fields:
 *     + @ref LTC4162_CHEM "CHEM" : Indicates the chemistry of the battery being charged. For additional safety, application software can test this value to ensure that the correct version of the LTC4162 (LTC4162-L, LTC4162-F or LTC4162-S) is populated on the circuit board.
 *     + @ref LTC4162_CELL_COUNT "CELL_COUNT" : Indicates the cell count value detected by the CELLS0 and CELLS1 pin strapping. cell_count always indicates 0 when the battery charger is not enabled such as when there is no input power available.
*/

//!@{
#define LTC4162_CHEM_CELLS_REG_SUBADDR 0x43u
#define LTC4162_CHEM_CELLS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_CHEM_CELLS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_CHEM CHEM
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CHEM Bit Field
 *
 *  Indicates the chemistry of the battery being charged. For additional safety, application software can test this value to ensure that the correct version of the LTC4162 (LTC4162-L, LTC4162-F or LTC4162-S) is populated on the circuit board.
 *   - Register: @ref LTC4162_CHEM_CELLS_REG "CHEM_CELLS_REG"
 *   - CommandCode: 0x43
 *   - Size: 4
 *   - Offset: 8
 *   - MSB: 11
 *   - MASK: 0x0F00
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CHEM_SUBADDR LTC4162_CHEM_CELLS_REG_SUBADDR //!< @ref LTC4162_CHEM "CHEM"
#define LTC4162_CHEM_SIZE 4u
#define LTC4162_CHEM_OFFSET 8u
#define LTC4162_CHEM_MASK 0x0F00u
#define LTC4162_CHEM_DEFAULT 0u
#define LTC4162_CHEM_DECODE(register_data) (((register_data) & LTC4162_CHEM_MASK) >> LTC4162_CHEM_OFFSET)
#define LTC4162_CHEM (LTC4162_CHEM_OFFSET << 12 | (LTC4162_CHEM_SIZE - 1) << 8 | LTC4162_CHEM_SUBADDR)
#define LTC4162_CHEM_ENUM_LTC4162_LAD 0u //!<Li-Ion I²C Adjustable Voltage
#define LTC4162_CHEM_ENUM_LTC4162_L42 1u //!<Li-Ion 4.2V Fixed Charge
#define LTC4162_CHEM_ENUM_LTC4162_L41 2u //!<Li-Ion 4.1V Fixed Charge
#define LTC4162_CHEM_ENUM_LTC4162_L40 3u //!<Li-Ion 4.0V Fixed Charge
#define LTC4162_CHEM_ENUM_LTC4162_FAD 4u //!<LiFePO4 I²C Adjustable Voltage
#define LTC4162_CHEM_ENUM_LTC4162_FFS 5u //!<LiFePO4 3.8V Rapid Charge
#define LTC4162_CHEM_ENUM_LTC4162_FST 6u //!<LiFePO4 3.6V Fixed Charge
#define LTC4162_CHEM_ENUM_LTC4162_SST 8u //!<Lead Acid Fixed Voltage
#define LTC4162_CHEM_ENUM_LTC4162_SAD 9u //!<Lead Acid I²C Adjustable Voltage
//!@}
/*! @defgroup LTC4162_CELL_COUNT CELL_COUNT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief CELL_COUNT Bit Field
 *
 *  Indicates the cell count value detected by the CELLS0 and CELLS1 pin strapping. cell_count always indicates 0 when the battery charger is not enabled such as when there is no input power available.
 *   - Register: @ref LTC4162_CHEM_CELLS_REG "CHEM_CELLS_REG"
 *   - CommandCode: 0x43
 *   - Size: 4
 *   - Offset: 0
 *   - MSB: 3
 *   - MASK: 0x000F
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_CELL_COUNT_SUBADDR LTC4162_CHEM_CELLS_REG_SUBADDR //!< @ref LTC4162_CELL_COUNT "CELL_COUNT"
#define LTC4162_CELL_COUNT_SIZE 4u
#define LTC4162_CELL_COUNT_OFFSET 0u
#define LTC4162_CELL_COUNT_MASK 0x000Fu
#define LTC4162_CELL_COUNT_DEFAULT 0u
#define LTC4162_CELL_COUNT_DECODE(register_data) (((register_data) & LTC4162_CELL_COUNT_MASK) >> LTC4162_CELL_COUNT_OFFSET)
#define LTC4162_CELL_COUNT (LTC4162_CELL_COUNT_OFFSET << 12 | (LTC4162_CELL_COUNT_SIZE - 1) << 8 | LTC4162_CELL_COUNT_SUBADDR)
#define LTC4162_CELL_COUNT_ENUM_UNKNOWN 0u
//!@}

/*! @defgroup LTC4162_ICHARGE_DAC_REG ICHARGE_DAC_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_DAC_REG Register
 *
 * | 15:5 |         4:0 |
 * |:----:|:-----------:|
 * |  n/a | ICHARGE_DAC |
 *
 *   - CommandCode: 0x44
 *   - Contains Bit Fields:
 *     + @ref LTC4162_ICHARGE_DAC "ICHARGE_DAC" : Indicates the actual charge current setting applied to the charge current digital to analog converter. icharge_dac is ramped up/down to implement digital soft-start/stop. The LTC4162 sets the value of icharge_dac based on charger_state, thermistor_voltage, and charger settings including charge_current_setting, icharge_jeita_2 through icharge_jeita_6, jeita_t1 through jeita_t6 and en_jeita. Recall that the charge current is regulated by controlling the voltage across an external current sense resistor RSNSB. The servo voltage is given by (icharge_dac + 1) × 1mV. The charge current servo level is thus given by (icharge_dac + 1) × 1mV/RSNSB.
*/

//!@{
#define LTC4162_ICHARGE_DAC_REG_SUBADDR 0x44u
#define LTC4162_ICHARGE_DAC_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_ICHARGE_DAC_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_ICHARGE_DAC ICHARGE_DAC
 *  @ingroup LTC4162-LADM_register_map
 *  @brief ICHARGE_DAC Bit Field
 *
 *  Indicates the actual charge current setting applied to the charge current digital to analog converter. icharge_dac is ramped up/down to implement digital soft-start/stop. The LTC4162 sets the value of icharge_dac based on charger_state, thermistor_voltage, and charger settings including charge_current_setting, icharge_jeita_2 through icharge_jeita_6, jeita_t1 through jeita_t6 and en_jeita. Recall that the charge current is regulated by controlling the voltage across an external current sense resistor RSNSB. The servo voltage is given by (icharge_dac + 1) × 1mV. The charge current servo level is thus given by (icharge_dac + 1) × 1mV/RSNSB.
 *   - Register: @ref LTC4162_ICHARGE_DAC_REG "ICHARGE_DAC_REG"
 *   - CommandCode: 0x44
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_ICHARGE
 */
//!@{
#define LTC4162_ICHARGE_DAC_SUBADDR LTC4162_ICHARGE_DAC_REG_SUBADDR //!< @ref LTC4162_ICHARGE_DAC "ICHARGE_DAC"
#define LTC4162_ICHARGE_DAC_SIZE 5u
#define LTC4162_ICHARGE_DAC_OFFSET 0u
#define LTC4162_ICHARGE_DAC_MASK 0x001Fu
#define LTC4162_ICHARGE_DAC_DEFAULT 0u
#define LTC4162_ICHARGE_DAC_DECODE(register_data) (((register_data) & LTC4162_ICHARGE_DAC_MASK) >> LTC4162_ICHARGE_DAC_OFFSET)
#define LTC4162_ICHARGE_DAC (LTC4162_ICHARGE_DAC_OFFSET << 12 | (LTC4162_ICHARGE_DAC_SIZE - 1) << 8 | LTC4162_ICHARGE_DAC_SUBADDR)
//!@}

/*! @defgroup LTC4162_VCHARGE_DAC_REG VCHARGE_DAC_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_DAC_REG Register
 *
 * | 15:5 |         4:0 |
 * |:----:|:-----------:|
 * |  n/a | VCHARGE_DAC |
 *
 *   - CommandCode: 0x45
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VCHARGE_DAC "VCHARGE_DAC" : This is the actual battery voltage setting applied to the charge voltage digital to analog converter. The LTC4162 sets the value of vcharge_dac based on charger_state, thermistor_voltage, and charger settings including vcharge_setting, vcharge_jeita_2 through vcharge_jeita_6, jeita_t1 through jeita_t6, thermistor_voltage and en_jeita. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max).
*/

//!@{
#define LTC4162_VCHARGE_DAC_REG_SUBADDR 0x45u
#define LTC4162_VCHARGE_DAC_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VCHARGE_DAC_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VCHARGE_DAC VCHARGE_DAC
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VCHARGE_DAC Bit Field
 *
 *  This is the actual battery voltage setting applied to the charge voltage digital to analog converter. The LTC4162 sets the value of vcharge_dac based on charger_state, thermistor_voltage, and charger settings including vcharge_setting, vcharge_jeita_2 through vcharge_jeita_6, jeita_t1 through jeita_t6, thermistor_voltage and en_jeita. The charge voltage setting can be computed from cell_count × (vcharge_setting × 12.5mV + 3.8125V) where vcharge_setting ranges from 0 to 31 (4.2V max).
 *   - Register: @ref LTC4162_VCHARGE_DAC_REG "VCHARGE_DAC_REG"
 *   - CommandCode: 0x45
 *   - Size: 5
 *   - Offset: 0
 *   - MSB: 4
 *   - MASK: 0x001F
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_VCHARGE_LIION
 */
//!@{
#define LTC4162_VCHARGE_DAC_SUBADDR LTC4162_VCHARGE_DAC_REG_SUBADDR //!< @ref LTC4162_VCHARGE_DAC "VCHARGE_DAC"
#define LTC4162_VCHARGE_DAC_SIZE 5u
#define LTC4162_VCHARGE_DAC_OFFSET 0u
#define LTC4162_VCHARGE_DAC_MASK 0x001Fu
#define LTC4162_VCHARGE_DAC_DEFAULT 0u
#define LTC4162_VCHARGE_DAC_DECODE(register_data) (((register_data) & LTC4162_VCHARGE_DAC_MASK) >> LTC4162_VCHARGE_DAC_OFFSET)
#define LTC4162_VCHARGE_DAC (LTC4162_VCHARGE_DAC_OFFSET << 12 | (LTC4162_VCHARGE_DAC_SIZE - 1) << 8 | LTC4162_VCHARGE_DAC_SUBADDR)
//!@}

/*! @defgroup LTC4162_IIN_LIMIT_DAC_REG IIN_LIMIT_DAC_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_LIMIT_DAC_REG Register
 *
 * | 15:6 |           5:0 |
 * |:----:|:-------------:|
 * |  n/a | IIN_LIMIT_DAC |
 *
 *   - CommandCode: 0x46
 *   - Contains Bit Fields:
 *     + @ref LTC4162_IIN_LIMIT_DAC "IIN_LIMIT_DAC" : Indicates the actual input current limit. The iin_limit_dac will follow the value programmed in iin_limit_target. The input current will be regulated to a maximum value given by (iin_limit_dac + 1) × 500µV / RSNSI.
*/

//!@{
#define LTC4162_IIN_LIMIT_DAC_REG_SUBADDR 0x46u
#define LTC4162_IIN_LIMIT_DAC_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_IIN_LIMIT_DAC_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_IIN_LIMIT_DAC IIN_LIMIT_DAC
 *  @ingroup LTC4162-LADM_register_map
 *  @brief IIN_LIMIT_DAC Bit Field
 *
 *  Indicates the actual input current limit. The iin_limit_dac will follow the value programmed in iin_limit_target. The input current will be regulated to a maximum value given by (iin_limit_dac + 1) × 500µV / RSNSI.
 *   - Register: @ref LTC4162_IIN_LIMIT_DAC_REG "IIN_LIMIT_DAC_REG"
 *   - CommandCode: 0x46
 *   - Size: 6
 *   - Offset: 0
 *   - MSB: 5
 *   - MASK: 0x003F
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_IINLIM
 */
//!@{
#define LTC4162_IIN_LIMIT_DAC_SUBADDR LTC4162_IIN_LIMIT_DAC_REG_SUBADDR //!< @ref LTC4162_IIN_LIMIT_DAC "IIN_LIMIT_DAC"
#define LTC4162_IIN_LIMIT_DAC_SIZE 6u
#define LTC4162_IIN_LIMIT_DAC_OFFSET 0u
#define LTC4162_IIN_LIMIT_DAC_MASK 0x003Fu
#define LTC4162_IIN_LIMIT_DAC_DEFAULT 0u
#define LTC4162_IIN_LIMIT_DAC_DECODE(register_data) (((register_data) & LTC4162_IIN_LIMIT_DAC_MASK) >> LTC4162_IIN_LIMIT_DAC_OFFSET)
#define LTC4162_IIN_LIMIT_DAC (LTC4162_IIN_LIMIT_DAC_OFFSET << 12 | (LTC4162_IIN_LIMIT_DAC_SIZE - 1) << 8 | LTC4162_IIN_LIMIT_DAC_SUBADDR)
//!@}

/*! @defgroup LTC4162_VBAT_FILT_REG VBAT_FILT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_FILT_REG Register
 *
 * |      15:0 |
 * |:---------:|
 * | VBAT_FILT |
 *
 *   - CommandCode: 0x47
 *   - Contains Bit Fields:
 *     + @ref LTC4162_VBAT_FILT "VBAT_FILT" : Signed number that is a digitally filtered version of the A/D measurement of vbat. The value is based on the A/D scaling factor for the battery voltage measurement which is cell_count × 192.4µV/LSB at the BATSENS+ pin.
*/

//!@{
#define LTC4162_VBAT_FILT_REG_SUBADDR 0x47u
#define LTC4162_VBAT_FILT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_VBAT_FILT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_VBAT_FILT VBAT_FILT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief VBAT_FILT Bit Field
 *
 *  Signed number that is a digitally filtered version of the A/D measurement of vbat. The value is based on the A/D scaling factor for the battery voltage measurement which is cell_count × 192.4µV/LSB at the BATSENS+ pin.
 *   - Register: @ref LTC4162_VBAT_FILT_REG "VBAT_FILT_REG"
 *   - CommandCode: 0x47
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_VBAT_FORMAT
 */
//!@{
#define LTC4162_VBAT_FILT_SUBADDR LTC4162_VBAT_FILT_REG_SUBADDR //!< @ref LTC4162_VBAT_FILT "VBAT_FILT"
#define LTC4162_VBAT_FILT_SIZE 16u
#define LTC4162_VBAT_FILT_OFFSET 0u
#define LTC4162_VBAT_FILT_MASK 0xFFFFu
#define LTC4162_VBAT_FILT_DEFAULT 0u
#define LTC4162_VBAT_FILT_DECODE(register_data) (register_data)
#define LTC4162_VBAT_FILT (LTC4162_VBAT_FILT_OFFSET << 12 | (LTC4162_VBAT_FILT_SIZE - 1) << 8 | LTC4162_VBAT_FILT_SUBADDR)
//!@}

/*! @defgroup LTC4162_BSR_CHARGE_CURRENT_REG BSR_CHARGE_CURRENT_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_CHARGE_CURRENT_REG Register
 *
 * |               15:0 |
 * |:------------------:|
 * | BSR_CHARGE_CURRENT |
 *
 *   - CommandCode: 0x48
 *   - Contains Bit Fields:
 *     + @ref LTC4162_BSR_CHARGE_CURRENT "BSR_CHARGE_CURRENT" : Signed number that is the battery charge current that existed during the battery series resistance measurement. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. If the battery series resistance (bsr) test runs with ibat values less than icharge_over_10, the accuracy of the test is questionable due to low signal level and bsr_questionable will set. Rerunning the battery series resistance test earlier in the charge cycle with higher ibat, and therefore higher bsr_charge_current, will give the most accurate result.
*/

//!@{
#define LTC4162_BSR_CHARGE_CURRENT_REG_SUBADDR 0x48u
#define LTC4162_BSR_CHARGE_CURRENT_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_BSR_CHARGE_CURRENT_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_BSR_CHARGE_CURRENT BSR_CHARGE_CURRENT
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_CHARGE_CURRENT Bit Field
 *
 *  Signed number that is the battery charge current that existed during the battery series resistance measurement. The value is based on the A/D value, ibat, which has a scaling factor of 1.466µV / RSNSB amperes/LSB. If the battery series resistance (bsr) test runs with ibat values less than icharge_over_10, the accuracy of the test is questionable due to low signal level and bsr_questionable will set. Rerunning the battery series resistance test earlier in the charge cycle with higher ibat, and therefore higher bsr_charge_current, will give the most accurate result.
 *   - Register: @ref LTC4162_BSR_CHARGE_CURRENT_REG "BSR_CHARGE_CURRENT_REG"
 *   - CommandCode: 0x48
 *   - Size: 16
 *   - Offset: 0
 *   - MSB: 15
 *   - MASK: 0xFFFF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_IBAT_FORMAT
 */
//!@{
#define LTC4162_BSR_CHARGE_CURRENT_SUBADDR LTC4162_BSR_CHARGE_CURRENT_REG_SUBADDR //!< @ref LTC4162_BSR_CHARGE_CURRENT "BSR_CHARGE_CURRENT"
#define LTC4162_BSR_CHARGE_CURRENT_SIZE 16u
#define LTC4162_BSR_CHARGE_CURRENT_OFFSET 0u
#define LTC4162_BSR_CHARGE_CURRENT_MASK 0xFFFFu
#define LTC4162_BSR_CHARGE_CURRENT_DEFAULT 0u
#define LTC4162_BSR_CHARGE_CURRENT_DECODE(register_data) (register_data)
#define LTC4162_BSR_CHARGE_CURRENT (LTC4162_BSR_CHARGE_CURRENT_OFFSET << 12 | (LTC4162_BSR_CHARGE_CURRENT_SIZE - 1) << 8 | LTC4162_BSR_CHARGE_CURRENT_SUBADDR)
#define LTC4162_BSR_CHARGE_CURRENT_ENUM_ICHARGE_OVER_10 2184u
//!@}

/*! @defgroup LTC4162_TELEMETRY_STATUS_REG TELEMETRY_STATUS_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TELEMETRY_STATUS_REG Register
 *
 * | 15:2 |                1 |               0 |
 * |:----:|:----------------:|:---------------:|
 * |  n/a | BSR_QUESTIONABLE | TELEMETRY_VALID |
 *
 * Telemetry system status register
 *   - CommandCode: 0x4A
 *   - Contains Bit Fields:
 *     + @ref LTC4162_BSR_QUESTIONABLE "BSR_QUESTIONABLE" : Indicates that the battery series resistance measurement is questionable due to low signal, specifically that ibat was less than icharge_over_10, when the last battery series resistance (bsr) measurement was taken. bsr_charge_current contains the ibat A/D value present when the battery series resistance measurement was made.
 *     + @ref LTC4162_TELEMETRY_VALID "TELEMETRY_VALID" : Indicates that the telemetry system autozero amplifiers have had sufficient time, approximately 12ms, to null their offsets. Battery charging is disabled until the telemetry system warm up time has passed.
*/

//!@{
#define LTC4162_TELEMETRY_STATUS_REG_SUBADDR 0x4Au
#define LTC4162_TELEMETRY_STATUS_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_TELEMETRY_STATUS_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_BSR_QUESTIONABLE BSR_QUESTIONABLE
 *  @ingroup LTC4162-LADM_register_map
 *  @brief BSR_QUESTIONABLE Bit Field
 *
 *  Indicates that the battery series resistance measurement is questionable due to low signal, specifically that ibat was less than icharge_over_10, when the last battery series resistance (bsr) measurement was taken. bsr_charge_current contains the ibat A/D value present when the battery series resistance measurement was made.
 *   - Register: @ref LTC4162_TELEMETRY_STATUS_REG "TELEMETRY_STATUS_REG"
 *   - CommandCode: 0x4A
 *   - Size: 1
 *   - Offset: 1
 *   - MSB: 1
 *   - MASK: 0x0002
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_BSR_QUESTIONABLE_SUBADDR LTC4162_TELEMETRY_STATUS_REG_SUBADDR //!< @ref LTC4162_BSR_QUESTIONABLE "BSR_QUESTIONABLE"
#define LTC4162_BSR_QUESTIONABLE_SIZE 1u
#define LTC4162_BSR_QUESTIONABLE_OFFSET 1u
#define LTC4162_BSR_QUESTIONABLE_MASK 0x0002u
#define LTC4162_BSR_QUESTIONABLE_DEFAULT 0u
#define LTC4162_BSR_QUESTIONABLE_DECODE(register_data) (((register_data) & LTC4162_BSR_QUESTIONABLE_MASK) >> LTC4162_BSR_QUESTIONABLE_OFFSET)
#define LTC4162_BSR_QUESTIONABLE (LTC4162_BSR_QUESTIONABLE_OFFSET << 12 | (LTC4162_BSR_QUESTIONABLE_SIZE - 1) << 8 | LTC4162_BSR_QUESTIONABLE_SUBADDR)
//!@}
/*! @defgroup LTC4162_TELEMETRY_VALID TELEMETRY_VALID
 *  @ingroup LTC4162-LADM_register_map
 *  @brief TELEMETRY_VALID Bit Field
 *
 *  Indicates that the telemetry system autozero amplifiers have had sufficient time, approximately 12ms, to null their offsets. Battery charging is disabled until the telemetry system warm up time has passed.
 *   - Register: @ref LTC4162_TELEMETRY_STATUS_REG "TELEMETRY_STATUS_REG"
 *   - CommandCode: 0x4A
 *   - Size: 1
 *   - Offset: 0
 *   - MSB: 0
 *   - MASK: 0x0001
 *   - Access: R
 *   - Default: 0
 */
//!@{
#define LTC4162_TELEMETRY_VALID_SUBADDR LTC4162_TELEMETRY_STATUS_REG_SUBADDR //!< @ref LTC4162_TELEMETRY_VALID "TELEMETRY_VALID"
#define LTC4162_TELEMETRY_VALID_SIZE 1u
#define LTC4162_TELEMETRY_VALID_OFFSET 0u
#define LTC4162_TELEMETRY_VALID_MASK 0x0001u
#define LTC4162_TELEMETRY_VALID_DEFAULT 0u
#define LTC4162_TELEMETRY_VALID_DECODE(register_data) (((register_data) & LTC4162_TELEMETRY_VALID_MASK) >> LTC4162_TELEMETRY_VALID_OFFSET)
#define LTC4162_TELEMETRY_VALID (LTC4162_TELEMETRY_VALID_OFFSET << 12 | (LTC4162_TELEMETRY_VALID_SIZE - 1) << 8 | LTC4162_TELEMETRY_VALID_SUBADDR)
//!@}

/*! @defgroup LTC4162_INPUT_UNDERVOLTAGE_DAC_REG INPUT_UNDERVOLTAGE_DAC_REG
 *  @ingroup LTC4162-LADM_register_map
 *  @brief INPUT_UNDERVOLTAGE_DAC_REG Register
 *
 * | 15:8 |                    7:0 |
 * |:----:|:----------------------:|
 * |  n/a | INPUT_UNDERVOLTAGE_DAC |
 *
 *   - CommandCode: 0x4B
 *   - Contains Bit Fields:
 *     + @ref LTC4162_INPUT_UNDERVOLTAGE_DAC "INPUT_UNDERVOLTAGE_DAC" : Input undervoltage regulation digital to analog converter value. The regulation voltage is given by (input_undervoltage_dac + 1) × 140.625mV. If enabled, the MPPT algorithm will directly manipulate this value. Otherwise it will follow input_undervoltage_setting.
*/

//!@{
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_REG_SUBADDR 0x4Bu
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_REG (0u << 12 | (LTC4162_WORD_SIZE - 1) << 8 | LTC4162_INPUT_UNDERVOLTAGE_DAC_REG_SUBADDR)
//!@}
/*! @defgroup LTC4162_INPUT_UNDERVOLTAGE_DAC INPUT_UNDERVOLTAGE_DAC
 *  @ingroup LTC4162-LADM_register_map
 *  @brief INPUT_UNDERVOLTAGE_DAC Bit Field
 *
 *  Input undervoltage regulation digital to analog converter value. The regulation voltage is given by (input_undervoltage_dac + 1) × 140.625mV. If enabled, the MPPT algorithm will directly manipulate this value. Otherwise it will follow input_undervoltage_setting.
 *   - Register: @ref LTC4162_INPUT_UNDERVOLTAGE_DAC_REG "INPUT_UNDERVOLTAGE_DAC_REG"
 *   - CommandCode: 0x4B
 *   - Size: 8
 *   - Offset: 0
 *   - MSB: 7
 *   - MASK: 0x00FF
 *   - Access: R
 *   - Default: 0
 *   - Format: LTC4162_VIN_UVCL
 */
//!@{
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_SUBADDR LTC4162_INPUT_UNDERVOLTAGE_DAC_REG_SUBADDR //!< @ref LTC4162_INPUT_UNDERVOLTAGE_DAC "INPUT_UNDERVOLTAGE_DAC"
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_SIZE 8u
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_OFFSET 0u
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_MASK 0x00FFu
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_DEFAULT 0u
#define LTC4162_INPUT_UNDERVOLTAGE_DAC_DECODE(register_data) (((register_data) & LTC4162_INPUT_UNDERVOLTAGE_DAC_MASK) >> LTC4162_INPUT_UNDERVOLTAGE_DAC_OFFSET)
#define LTC4162_INPUT_UNDERVOLTAGE_DAC (LTC4162_INPUT_UNDERVOLTAGE_DAC_OFFSET << 12 | (LTC4162_INPUT_UNDERVOLTAGE_DAC_SIZE - 1) << 8 | LTC4162_INPUT_UNDERVOLTAGE_DAC_SUBADDR)
//!@}

#endif /* LTC4162_H_ */
