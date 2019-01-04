/*
    __gainamp2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__gainamp2_driver.h"
#include "__gainamp2_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __GAINAMP2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _GAINAMP2_NOP_INS      = 0x00;
const uint8_t _GAINAMP2_SHUTDOWN_INS = 0x20;
const uint8_t _GAINAMP2_WRITE_INS    = 0x40;

const uint8_t _GAINAMP2_CH           = 0x01;
const uint8_t _GAINAMP2_GAIN         = 0x00;

const uint8_t _GAINAMP2_GAIN_1X      = 0x00;
const uint8_t _GAINAMP2_GAIN_2X      = 0x01;
const uint8_t _GAINAMP2_GAIN_4X      = 0x02;
const uint8_t _GAINAMP2_GAIN_5X      = 0x03;
const uint8_t _GAINAMP2_GAIN_8X      = 0x04;
const uint8_t _GAINAMP2_GAIN_10X     = 0x05;
const uint8_t _GAINAMP2_GAIN_16X     = 0x06;
const uint8_t _GAINAMP2_GAIN_32X     = 0x07;

const uint8_t _GAINAMP2_CH0          = 0x00;
const uint8_t _GAINAMP2_CH1          = 0x01;
const uint8_t _GAINAMP2_CH2          = 0x02;
const uint8_t _GAINAMP2_CH3          = 0x03;
const uint8_t _GAINAMP2_CH4          = 0x04;
const uint8_t _GAINAMP2_CH5          = 0x05;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __GAINAMP2_DRV_SPI__

void gainamp2_spiDriverInit(T_GAINAMP2_P gpioObj, T_GAINAMP2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet( 1 );
    Delay_100ms();
}

#endif
#ifdef   __GAINAMP2_DRV_I2C__

void gainamp2_i2cDriverInit(T_GAINAMP2_P gpioObj, T_GAINAMP2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __GAINAMP2_DRV_UART__

void gainamp2_uartDriverInit(T_GAINAMP2_P gpioObj, T_GAINAMP2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void gainamp2_writeCommand( uint8_t instruction, uint8_t input )
{
    uint8_t tmp[2];

    tmp[0] = instruction;
    tmp[1] = input;

    hal_gpio_csSet( 0 );
    hal_spiWrite( tmp, 2 );
    hal_gpio_csSet( 1 );
    Delay_1us();
}

/* -------------------------------------------------------------------------- */
/*
  __gainamp2_driver.c

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
