/*
Example for GainAMP_2 Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of two sections :

- System Initialization - Initializes CS pin as output and SPI module 
- Application Initialization - Setup GainAMP 2 click channel 4 to amplify the signal 4 times

*/

#include "Click_GainAMP_2_types.h"
#include "Click_GainAMP_2_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_GAINAMP2_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
    mikrobus_logWrite( "System Initialized", _LOG_LINE );
}

void applicationInit()
{
    gainamp2_spiDriverInit( (T_GAINAMP2_P)&_MIKROBUS1_GPIO, (T_GAINAMP2_P)&_MIKROBUS1_SPI );

// SETUP GAIN +4 on CHANNEL
    gainamp2_writeCommand( _GAINAMP2_WRITE_INS | _GAINAMP2_CH, _GAINAMP2_CH4 );
    gainamp2_writeCommand( _GAINAMP2_WRITE_INS | _GAINAMP2_GAIN, _GAINAMP2_GAIN_4X );

    mikrobus_logWrite( "Channel 4 - aplified 4x", _LOG_LINE );
}

void applicationTask()
{
    // Nothing to do here
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
    	applicationTask();
    }
}