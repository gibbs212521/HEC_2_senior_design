/*****************************************************************************/
/*  INTRINSICS_LEGACY_UNDEFS.H                                               */
/*                                                                           */
/* Copyright (c) 2005 Texas Instruments Incorporated                         */
/* http://www.ti.com/                                                        */
/*                                                                           */
/*  Redistribution and  use in source  and binary forms, with  or without    */
/*  modification,  are permitted provided  that the  following conditions    */
/*  are met:                                                                 */
/*                                                                           */
/*     Redistributions  of source  code must  retain the  above copyright    */
/*     notice, this list of conditions and the following disclaimer.         */
/*                                                                           */
/*     Redistributions in binary form  must reproduce the above copyright    */
/*     notice, this  list of conditions  and the following  disclaimer in    */
/*     the  documentation  and/or   other  materials  provided  with  the    */
/*     distribution.                                                         */
/*                                                                           */
/*     Neither the  name of Texas Instruments Incorporated  nor the names    */
/*     of its  contributors may  be used to  endorse or  promote products    */
/*     derived  from   this  software  without   specific  prior  written    */
/*     permission.                                                           */
/*                                                                           */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS    */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT    */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT    */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT    */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     */
/*                                                                           */
/*****************************************************************************/
#ifndef _INTRINSICS_LEGACY_UNDEFS_H_
#define _INTRINSICS_LEGACY_UNDEFS_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*---------------------------------------------------------------------------*/
/* Handle in430.h conflicts with legacy intrinsic names                      */
/*---------------------------------------------------------------------------*/
#ifdef __IN430_H
#undef __no_operation
#undef __enable_interrupt
#undef __disable_interrupt
#undef __set_interrupt_state
#undef __bic_SR_register
#undef __bic_SR_register_on_exit
#undef __bis_SR_register
#undef __bis_SR_register_on_exit
#undef __get_SR_register
#undef __get_SR_register_on_exit
#undef __even_in_range
#undef __op_code
#undef __bcd_add_short
#undef __bcd_add_long
#undef __swap_bytes
#undef __data16_rewrite_addr
#undef __data16_rewrite_addr
#undef __data16_write_addr
#undef __data16_read_addr
#undef __data20_write_char
#undef __data20_write_short
#undef __data20_write_long
#undef __data20_read_char
#undef __data20_read_short
#undef __data20_read_long
#undef __get_SP_register
#undef __set_SP_register
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _INTRINSICS_LEGACY_UNDEFS_H_ */
