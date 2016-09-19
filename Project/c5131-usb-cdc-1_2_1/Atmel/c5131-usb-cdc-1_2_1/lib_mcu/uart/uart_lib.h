/*H**************************************************************************
* NAME:         uart_lib.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.14.8.1     
*----------------------------------------------------------------------------
* PURPOSE: 
* UART lib header file                                       
*****************************************************************************/

#ifndef _UART_LIB_H_
#define _UART_LIB_H_

/*_____ C O N F I G U R A T I O N _________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/
#define XON  0x11
#define XOFF 0x13

// BDR_GENERATOR type:
#ifndef BDR_GENERATOR
#error You must define BDR_GENERATOR in config.h
#define BDR_GENERATOR   999
#endif

#define BRG_INTERNAL    0
#define BRG_TIMER1      1
#define BRG_TIMER2      2

#ifndef UART_CONFIG
#define UART_CONFIG     MSK_UART_8BIT
#endif

#ifndef BAUDRATE
#error You must define BAUDRATE in config.h
#define BAUDRATE        999
#endif

#define AUTOBAUD        0

#if BAUDRATE == AUTOBAUD
#define Uart_set_baudrate(bdr)  autobaud()
#include "modules/autobaud/autobaud.h"
#else
#include "uart_bdr.h"
#endif

/*_____ D E C L A R A T I O N ______________________________________________*/
#ifdef UART_DEFAULT_INPUT
#define uart_getchar            _getkey
#define uart_test_hit           test_hit
#endif

#ifdef UART_DEFAULT_OUTPUT
#define uart_putchar            putchar
#endif

/*_____ M A C R O S ________________________________________________________*/

/*_____ P R O T O T Y P E S ____________________________________________________________*/
// Std functions for CUSTOM_IO support
// Output
bit     uart_init           (void);
char    uart_putchar        (char uc_wr_byte);
#ifndef UART_MINIMUM
void    uart_gotoxy         (Byte x, Byte y);
void    uart_clrscr         (void);
bit     uart_splash         (void);
// Misc.
void    uart_puts           (char _GenericType_ * p);
extern char _ConstType_ txt_logo_atmel[];
#endif
// Input
bit     uart_test_hit       (void);
char    uart_getchar        (void);
extern volatile bit         uart_hit;
void uart_set_baudrate		(long int);

#endif /* _UART_LIB_H_ */
