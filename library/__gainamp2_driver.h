/*
    __gainamp2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __gainamp2_driver.h
@brief    GainAMP_2 Driver
@mainpage GainAMP_2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   GAINAMP2
@brief      GainAMP_2 Click Driver
@{

| Global Library Prefix | **GAINAMP2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _GAINAMP2_H_
#define _GAINAMP2_H_

/** 
 * @macro T_GAINAMP2_P
 * @brief Driver Abstract type 
 */
#define T_GAINAMP2_P    const uint8_t*

/** @defgroup GAINAMP2_COMPILE Compilation Config */              /** @{ */

   #define   __GAINAMP2_DRV_SPI__                            /**<     @macro __GAINAMP2_DRV_SPI__  @brief SPI driver selector */
//  #define   __GAINAMP2_DRV_I2C__                            /**<     @macro __GAINAMP2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __GAINAMP2_DRV_UART__                           /**<     @macro __GAINAMP2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup GAINAMP2_VAR Variables */                                /** @{ */

extern const uint8_t _GAINAMP2_NOP_INS      ; /**< NOP Instruction */
extern const uint8_t _GAINAMP2_SHUTDOWN_INS ; /**< Shutdown Instruction */
extern const uint8_t _GAINAMP2_WRITE_INS    ; /**< Write Instruction */
extern const uint8_t _GAINAMP2_GAIN         ; /**< Gain setup - used with write instuction */
extern const uint8_t _GAINAMP2_CH           ; /**< Channel setup - used with write instruction */
extern const uint8_t _GAINAMP2_GAIN_1X      ; /**< Gain of +1 */
extern const uint8_t _GAINAMP2_GAIN_2X      ; /**< Gain of +2 */
extern const uint8_t _GAINAMP2_GAIN_4X      ; /**< Gain of +4 */
extern const uint8_t _GAINAMP2_GAIN_5X      ; /**< Gain of +5 */
extern const uint8_t _GAINAMP2_GAIN_8X      ; /**< Gain of +8 */
extern const uint8_t _GAINAMP2_GAIN_10X     ; /**< Gain of +10 */
extern const uint8_t _GAINAMP2_GAIN_16X     ; /**< Gain of +16 */
extern const uint8_t _GAINAMP2_GAIN_32X     ; /**< Gain of +32 */
extern const uint8_t _GAINAMP2_CH0          ; /**< CH0 */
extern const uint8_t _GAINAMP2_CH1          ; /**< CH1 */
extern const uint8_t _GAINAMP2_CH2          ; /**< CH2 */
extern const uint8_t _GAINAMP2_CH3          ; /**< CH3 */
extern const uint8_t _GAINAMP2_CH4          ; /**< CH4 */
extern const uint8_t _GAINAMP2_CH5          ; /**< CH5 */
                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup GAINAMP2_INIT Driver Initialization */              /** @{ */

#ifdef   __GAINAMP2_DRV_SPI__
void gainamp2_spiDriverInit(T_GAINAMP2_P gpioObj, T_GAINAMP2_P spiObj);
#endif
#ifdef   __GAINAMP2_DRV_I2C__
void gainamp2_i2cDriverInit(T_GAINAMP2_P gpioObj, T_GAINAMP2_P i2cObj, uint8_t slave);
#endif
#ifdef   __GAINAMP2_DRV_UART__
void gainamp2_uartDriverInit(T_GAINAMP2_P gpioObj, T_GAINAMP2_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup GAINAMP2_FUNC Driver Functions */                        /** @{ */

/**
 * @brief Send Command
 *
 * @param[in] instruction 
 * @param[in] input 
 *
 * Function setup amplifier according to provided command.
 */
void gainamp2_writeCommand( uint8_t instruction, uint8_t input );
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_GainAMP_2_STM.c
    @example Click_GainAMP_2_TIVA.c
    @example Click_GainAMP_2_CEC.c
    @example Click_GainAMP_2_KINETIS.c
    @example Click_GainAMP_2_MSP.c
    @example Click_GainAMP_2_PIC.c
    @example Click_GainAMP_2_PIC32.c
    @example Click_GainAMP_2_DSPIC.c
    @example Click_GainAMP_2_AVR.c
    @example Click_GainAMP_2_FT90x.c
    @example Click_GainAMP_2_STM.mbas
    @example Click_GainAMP_2_TIVA.mbas
    @example Click_GainAMP_2_CEC.mbas
    @example Click_GainAMP_2_KINETIS.mbas
    @example Click_GainAMP_2_MSP.mbas
    @example Click_GainAMP_2_PIC.mbas
    @example Click_GainAMP_2_PIC32.mbas
    @example Click_GainAMP_2_DSPIC.mbas
    @example Click_GainAMP_2_AVR.mbas
    @example Click_GainAMP_2_FT90x.mbas
    @example Click_GainAMP_2_STM.mpas
    @example Click_GainAMP_2_TIVA.mpas
    @example Click_GainAMP_2_CEC.mpas
    @example Click_GainAMP_2_KINETIS.mpas
    @example Click_GainAMP_2_MSP.mpas
    @example Click_GainAMP_2_PIC.mpas
    @example Click_GainAMP_2_PIC32.mpas
    @example Click_GainAMP_2_DSPIC.mpas
    @example Click_GainAMP_2_AVR.mpas
    @example Click_GainAMP_2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __gainamp2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */

