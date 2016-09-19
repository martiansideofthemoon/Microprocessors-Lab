/*C**************************************************************************
* NAME:         uart_lib.c
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.20.8.1     
*----------------------------------------------------------------------------
* PURPOSE: 
* This file provides a minimal VT100 terminal access through UART
* and compatibility with Custom I/O support
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#include "config.h"
#include "uart_lib.h"


/*_____ G L O B A L    D E F I N I T I O N _________________________________*/
/*V**************************************************************************
* NAME: uart_hit
*----------------------------------------------------------------------------
* PURPOSE: 
* Latch of RI: something is received
*****************************************************************************/
volatile bit uart_hit;
long int  brg2_init;
#ifdef LOGO_ATMEL
/*V**************************************************************************
* NAME: txt_logo_atmel
*----------------------------------------------------------------------------
* PURPOSE: 
* Add some bytes of code for standard logo string.
* If LOGO_ATMEL is defined: ASCII Art of Atmel Logo + Release name
* Else: Release name
*----------------------------------------------------------------------------
* NOTE: 
* CODE_MEM (memory location identifier) to be defined
*****************************************************************************/
char _ConstType_ txt_logo_atmel[]="\n\
        _____________________________\n\
      /___   ________________________|\n\
     ___  | |  ________    ____   _\n\
    /   | | | |  _   _ \\  |  __| | |\n\
   / /| | | | | | | | | | | |__  | |\n\
  / / | | | | | | | | | | |  __| | |\n\
 / /_ | | | | | | | | | | | |__  | |__\n\
/____||_| |_| |_| |_| |_| |____| |___/\n\
 ___________________________________\n\
|__________________________________/ (R)\n\
c5131-usb-cdc-1_2_1\n\n";
#else
char _ConstType_ txt_logo_atmel[]="Atmel (R)\nc5131-usb-cdc-1_2_1\n\n";
#endif

/*_____ D E F I N I T I O N ________________________________________________*/

/*_____ M A C R O S ________________________________________________________*/
#ifndef UART_MINIMUM
/*F**************************************************************************
* NAME: uart_puts
*----------------------------------------------------------------------------
* PARAMS:   
* sz: string zero terminated to print on UART
* return: none
*----------------------------------------------------------------------------
* PURPOSE:
* print a string on the UART
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
* This function was added only to optimized uart_splash & uart_clrscr in VT100
* mode (reduce code size).
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void uart_puts (char _GenericType_ * sz)
{
register char   ch;

for (;ch=*sz++;)
  {
  if (ch=='\n') uart_putchar('\r');
  uart_putchar(ch);
  }
uart_putchar('\r');
uart_putchar('\n');
}


/*F**************************************************************************
* NAME: uart_clrscr
*----------------------------------------------------------------------------
* PARAMS:   
* return: none
*----------------------------------------------------------------------------
* PURPOSE:
* Clear VT100 terminal
*----------------------------------------------------------------------------
* EXAMPLE:
* uart_clrsscr(); // CLS
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void uart_clrscr (void)
{
#ifndef DISABLE_VT100
char _ConstType_   sz_init[]="\033c\033\133?25l"; // \033c=\033(2j=clear screen, \133?25l=no cursor
uart_puts(sz_init);
#else // 25 new lines
uart_gotoxy(1,25);
#endif
}

#ifdef ENABLE_SPLASH_SCREEN
bit state_uart_splash=0;

/*F**************************************************************************
* NAME: uart_splash
*----------------------------------------------------------------------------
* PARAMS:   
* return: TRUE if terminated
*----------------------------------------------------------------------------
* PURPOSE:
* Splash screen
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
bit uart_splash (void)
{
if (!state_uart_splash)
  {
  uart_clrscr();
  uart_puts(txt_logo_atmel);
  }
return state_uart_splash=TRUE;
}
#endif


/*F**************************************************************************
* NAME: uart_gotoxy
*----------------------------------------------------------------------------
* PARAMS:
* x: horizontal move 1..x, left to right
* y: vertical move 1..y, top to bottom
* return: none
*----------------------------------------------------------------------------
* PURPOSE:
* Absolute move of virtual cursor: the next putchar will place the character
* at position x,y.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
* x=0 => beginning of line
*----------------------------------------------------------------------------
* REQUIREMENTS: 
* VT100 compatibility, except if x=0
*****************************************************************************/
void uart_gotoxy (Byte x, Byte y)
{
if (!x)
  {
  uart_putchar('\r');
  uart_putchar('\n');
  }
else
  {
  #ifndef DISABLE_VT100
  uart_putchar(27);
  uart_putchar(0x5B);
  if (y>9) uart_putchar('0'+(y/10));
  uart_putchar('0'+(y%10));
  uart_putchar(';');
  if (x>9) uart_putchar('0'+(x/10));
  uart_putchar('0'+(x%10));
  uart_putchar('H');
  #else
  uart_putchar('\r');
  for (;y--;) uart_putchar('\n');
  x--; // 0,1 => no space
  for (;x--;) uart_putchar(' ');
  #endif
  }
}
#endif // UART_MINIMUM


/*F**************************************************************************
* NAME: uart_test_hit
*----------------------------------------------------------------------------
* PARAMS:   
* return: none
*----------------------------------------------------------------------------
* PURPOSE:
* Update uart_hit variable: check if something is received on the uart
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
bit uart_test_hit (void)
{
return uart_hit=Uart_rx_ready();
}


/*F**************************************************************************
* NAME: uart_init  
*----------------------------------------------------------------------------
* PARAMS: none
* return: none 
*----------------------------------------------------------------------------
* PURPOSE: 
* init UART & timer 1 in baudrate generator
*****************************************************************************
* NOTE: serial port mode: 8 bits with variable baud rate (9600 with 7.37Mhz)
*****************************************************************************/
bit uart_init (void)
{
Uart_hw_init(UART_CONFIG);
Uart_set_baudrate(BAUDRATE);
Uart_enable();
return TRUE;
}


/*F**************************************************************************
* NAME: uart_putchar
*----------------------------------------------------------------------------
* PARAMS:   
* ch: character to print on UART
* return: character printed
*----------------------------------------------------------------------------
* PURPOSE:
* print a character on the UART
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
char uart_putchar (char ch)
{
while(!Uart_tx_ready());
Uart_set_tx_busy(); // Set Busy flag before sending (always)
Uart_send_byte(ch);
return ch;
}



/*F**************************************************************************
* NAME: uart_getchar
*----------------------------------------------------------------------------
* PARAMS:   
* return: character read on uart.
*----------------------------------------------------------------------------
* PURPOSE:
* Get a character from the UART
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
char uart_getchar (void)
{

register char c;

while(!Uart_rx_ready());
c = Uart_get_byte();
Uart_ack_rx_byte();
return c; 
}
/*F**************************************************************************
* NAME: uart_getchar
*----------------------------------------------------------------------------
* PARAMS:   
* return: character read on uart.
*----------------------------------------------------------------------------
* PURPOSE:
* Get a character from the UART
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void uart_set_baudrate(long int bdr)      
{
 switch (bdr)
 {
	case 1200 :
	 brg2_init = 65120;
	 Set_timer2_x1_mode();
		break;
	case 2400 :
	 brg2_init = 65328;
	 Set_timer2_x1_mode();
		break;
    case 4800 :
	 brg2_init = 65432;
	 Set_timer2_x1_mode();
		break;
 	case 9600 :
	 brg2_init = 65484;
	 Set_timer2_x1_mode();
		break;
	case 19200 :
	 brg2_init = 65510;
	 Set_timer2_x1_mode();
		break;
	case 28800 :
	 brg2_init = 65519;
	 Set_timer2_x1_mode();
		break;
	case 38400 :
	 brg2_init = 65523;
	 Set_timer2_x1_mode();
		break;
	case 57600 :
	 brg2_init = 65527;
	 Set_timer2_x1_mode();

		break;
	case 115200 :
	 brg2_init = 65527;
	 Set_timer2_x2_mode();
	 	 Uart_conf_x2();
		break;
	default :
		break;
	 }

     RCAP2H=(brg2_init>>8); /* Set autoreload value for T2 according to FOSC & BAUDRATE */
     RCAP2L=brg2_init;
     T2CON=0x34; /* Timer2 in Baud rate Generator mode */
     TR2  =1; /* Start timer 2 */
}

