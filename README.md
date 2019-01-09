![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# GainAMP_2 Click

---

- **CIC Prefix**  : GAINAMP2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Dec 2017.

---

### Software Support

We provide a library for the GainAMP_2 Click on our [LibStock](http://libstock.mikroe.com/projects/view/2272/gainamp-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries single function which allows complete control over GainAMP 2 click.

Key functions :

- ``` gainamp2_writeCommand ``` - writes desired command 

**Examples Description**

Demo application demonstrates simplicicty of usage.

The application is composed of two sections :

- System Initialization - Initializes CS pin as output and SPI module 
- Application Initialization - Setup GainAMP 2 click channel 4 to amplify the signal 4 times


```.c
void applicationInit()
{
    gainamp2_spiDriverInit( (T_GAINAMP2_P)&_MIKROBUS1_GPIO, (T_GAINAMP2_P)&_MIKROBUS1_SPI );

// SETUP GAIN +4 on CHANNEL
    gainamp2_writeCommand( _GAINAMP2_WRITE_INS | _GAINAMP2_CH, _GAINAMP2_CH4 );
    gainamp2_writeCommand( _GAINAMP2_WRITE_INS | _GAINAMP2_GAIN, _GAINAMP2_GAIN_4X );

    mikrobus_logWrite( "Channel 4 - aplified 4x", _LOG_LINE );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](http://libstock.mikroe.com/projects/view/2272/gainamp-2-click) page.

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
