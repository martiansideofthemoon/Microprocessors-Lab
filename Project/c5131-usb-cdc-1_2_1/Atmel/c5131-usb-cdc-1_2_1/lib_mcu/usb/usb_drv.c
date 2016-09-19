/*C**************************************************************************
* NAME:         usb_drv.c
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.9     
*----------------------------------------------------------------------------
* PURPOSE: 
* This file contains the USB driver routines.
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/

#include "config.h"
#include "usb_drv.h"

/*_____ M A C R O S ________________________________________________________*/


/*_____ D E F I N I T I O N ________________________________________________*/
/* --------------------------------------------------------------------------------------------------
|Xtal frequency  ||  6 MHz |  8 MHz | 12 MHz | 16 MHz | 20 MHz | 24 MHz | 32 MHz | 40 MHz | 48 MHz |
 --------------------------------------------------------------------------------------------------
|Pll % value (n) ||   1    |   1    |   1    |   1    |   5    |   1    |   2    |   10   |disabled|
|Pll x value (r) ||   8    |   6    |   4    |   3    |   12   |   2    |   3    |   12   |disabled|
|PLLDIV value    ||  70h   |  50h   |  30h   |  20  h |  B4h   |  10h   |  21h   |  B9h   |disabled|
|  [r,n]         ||        |        |        |        |        |        |        |        |        |
 --------------------------------------------------------------------------------------------------
|Timer load X1   ||   600  |   800  |  1200  |  1600  |  2000  |  2400  |  3200  |  4000  |  4800  |
|Timer TH0-TH1 X1|| FD-A7h | FC-DFh | FB-4Fh | F9-BFh | F8-2Fh | F6-9Fh | F3-7Fh | F0-5Fh | ED-3Fh |
|Timer load X2   ||  1200  |  1600  |  2400  |  3200  |  4000  |  4800  |   na   |   na   |   na   |
|Timer TH0-TH1 X2|| FB-4Fh | F9-BFh | F6-9Fh | F3-7Fh | F0-5Fh | ED-3Fh |   na   |   na   |   na   |   
 --------------------------------------------------------------------------------------------------
*/
#if FOSC == 0000
  code char pll_value[8] = {0x70,0x50,0x30,0x20,0xB4,0x10,0x21,0xB9};
  code char TH0_value[9] = {0xFD,0xFC,0xFB,0xF9,0xF8,0xF6,0xF3,0xF0,0xED};
  code char TL0_value[9] = {0xA7,0xDF,0x4F,0xBF,0x2F,0x9F,0x7F,0x5F,0x3F};
#endif
/*_____ D E C L A R A T I O N ______________________________________________*/

/*F**************************************************************************
* NAME: usb_configure_endpoint 
*----------------------------------------------------------------------------
* PARAMS:
* ep_num:   Number of the endpoint to configure
* ep_type:  Type to configure
*           The possible types are:
*                CONTROL
*                BULK_IN
*                BULK_OUT
*                INTERRUPT_IN
*                INTERRUPT_OUT
*                ISOCHRONOUS_IN
*                ISOCHRONOUS_OUT
* return:   none
*----------------------------------------------------------------------------
* PURPOSE: 
* This function configures an endpoint with the selected type.
*----------------------------------------------------------------------------
* EXAMPLE:
* usb_configure_endpoint(0,CONTROL);
*----------------------------------------------------------------------------
* NOTE:
* The endpoint 0 shall always be configured in CONTROL type.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_configure_endpoint (Uchar ep_num, Uchar ep_type)
{
  Usb_select_ep(ep_num);
  Usb_configure_ep_type(ep_type); 
}

/*F**************************************************************************
* NAME: usb_select_endpoint_interrupt
*----------------------------------------------------------------------------
* PARAMS:
* return:   endpoint number
*----------------------------------------------------------------------------
* PURPOSE: 
* This function select the endpoint where an event occurs and returns the
* number of this endpoint. If no event occurs on the endpoints, this
* function returns 0.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
Uchar usb_select_enpoint_interrupt(void)
{
  if (EP0INT)       { Usb_select_ep(0); }
  else if (EP1INT)  { Usb_select_ep(1); }
  else if (EP2INT)  { Usb_select_ep(2); }
  else if (EP3INT)  { Usb_select_ep(3); }
  else if (EP4INT)  { Usb_select_ep(4); }
  else if (EP5INT)  { Usb_select_ep(5); }
  else if (EP6INT)  { Usb_select_ep(6); }

  return (UEPNUM);
}


/*F**************************************************************************
* NAME: usb_get_nb_byte 
*----------------------------------------------------------------------------
* PARAMS:
* return:   number of byte stored in the currently selected endpoint
*----------------------------------------------------------------------------
* PURPOSE: 
* This function returns the number of byte stored in the currently selected
* endpoint.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
* This function shall be launched only for OUT endpoints after each receipt
* and before any other operation.
* This function shall not be used if the declared FIFO size is more than
* 255 bytes. In this case, use the usb_get_nb_byte_epw function.  
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
Uchar usb_get_nb_byte (void)
{
  return (UBYCTLX);
}

/*F**************************************************************************
* NAME: usb_get_nb_byte_epw 
*----------------------------------------------------------------------------
* PARAMS:
* return:   number of byte stored in the endpoint .
*----------------------------------------------------------------------------
* PURPOSE: 
* This function returns the number of byte stored in the endpoint 6.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
* This function shall be launched only for OUT endpoints after each receipt
* and before any other operation.
* This function shall be used if the declared FIFO size is more than
* 255 bytes.
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
Uint16 usb_get_nb_byte_epw (void)
{
  return ((((Uint16)UBYCTHX)<<8)|(UBYCTLX)); 
}

/*F**************************************************************************
* NAME: usb_send_ep0_packet
*----------------------------------------------------------------------------
* PARAMS:
* *tbuf:        address of the first data to send
* data_length:  number of bytes to send
* return:       address of the next Ucharto send
*----------------------------------------------------------------------------
* PURPOSE: 
* This function moves the data pointed by tbuf to the default Control
* endpoint fifo and sends it through the USB.
*----------------------------------------------------------------------------
* EXAMPLE:
* usb_send_ep0_packet(&first_data,0x20);  // send packet
* while(!(Usb_tx_complete));              // wait packet ACK'ed by the Host
* Usb_clear_tx_complete();                     // acknowledge the transmit
*----------------------------------------------------------------------------
* NOTE: 
* tbuf is incremented of 'data_length'.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
Uchar* usb_send_ep0_packet (Uchar* tbuf, Uchar data_length)
{
  Usb_select_ep(0);

  for (; data_length-- ;  tbuf++)  { Usb_write_byte(*tbuf); }
  Usb_set_tx_ready();

  return tbuf;
}


/*F**************************************************************************
* NAME: usb_send_right_packet
*----------------------------------------------------------------------------
* PARAMS:
* ep_num:       number of the addressed endpoint
* *tbuf:        address of the first data to send
* data_length:  number of bytes to send
* return:       address of the next Uchar to send
*----------------------------------------------------------------------------
* PURPOSE: 
* This function moves the data pointed by tbuf to the selected endpoint fifo 
* and sends it through the USB.
*----------------------------------------------------------------------------
* EXAMPLE:
* usb_send_packet(3,&first_data,0x20);    // send packet on the endpoint #3
* while(!(Usb_tx_complete));              // wait packet ACK'ed by the Host
* Usb_clear_tx_complete();                     // acknowledge the transmit
*----------------------------------------------------------------------------
* NOTE:
* tbuf is incremented of 'data_length'.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
Uchar* usb_send_right_packet ( Uchar * tbuf, Uchar data_length)
{
  for ( ; data_length-- ; tbuf++)  { Usb_write_byte(*tbuf); }
  Usb_set_tx_ready();

  return tbuf;
}


 

/*F**************************************************************************
* NAME: usb_read_packet
*----------------------------------------------------------------------------
* PARAMS:
* ep_num:       number of the addressed endpoint
* *rbuf:        address of the first data to write with the USB data
* data_length:  number of bytes to read
* return:       address of the next Ucharto send
*----------------------------------------------------------------------------
* PURPOSE: 
* This function moves the data stored in the selected endpoint fifo to 
* the address specified by *rbuf.
*----------------------------------------------------------------------------
* EXAMPLE:
* while(!(Usb_rx_complete));                      // wait new packet received
* usb_read_packet(4,&first_data,usb_get_nb_byte); // read packet from ep 4
* Usb_clear_rx();                                 // acknowledge the transmit
*----------------------------------------------------------------------------
* NOTE:
* rbuf is incremented of 'data_length'.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
Uchar* usb_read_right_packet (Uchar* rbuf, Uchar data_length)
{
  for (; data_length-- ; rbuf++) { *rbuf = Usb_read_byte(); }

  return rbuf;
}

/*F**************************************************************************
* NAME: usb_halt_endpoint
*----------------------------------------------------------------------------
* PARAMS:
* ep_num:       number of the addressed endpoint
* return:       none
*----------------------------------------------------------------------------
* PURPOSE: 
* This function sends a STALL handshake for the next Host request. A STALL
* handshake will be send for each next request untill a SETUP or a Clear Halt
* Feature occurs for this endpoint.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_halt_endpoint (Uchar ep_num)
{
  Usb_select_ep(ep_num);
  UEPSTAX = 0x00;
  Usb_set_stall_request();
}

/*F**************************************************************************
* NAME: usb_reset_endpoint
*----------------------------------------------------------------------------
* PARAMS:
* return:       none
*----------------------------------------------------------------------------
* PURPOSE: 
* This function resets the endpoint fifo. This should be performed before
* the first use of an endpoint and after a Clear Halt Feature for the 
* endpoint
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_reset_endpoint (Uchar ep_num)
{
  UEPRST = 0x01 << ep_num ;
  UEPRST = 0x00;
}

/*F**************************************************************************
* NAME: configure_usb_clock
*----------------------------------------------------------------------------
* PARAMS:
* return:       none
* The possible value for FOSC are :
*              3000   ( 3MHz)
*              6000   ( 6MHz)
*              8000   ( 8MHz)
*             12000   (12MHz)
*             16000   (16MHz)
*             18000   (18MHz)
*             20000   (20MHz)
*             24000   (24MHz)
*             32000   (32MHz)
*             40000   (40MHz)
*             48000   (48MHz)
*              0000   (frequency auto-dectection)
*----------------------------------------------------------------------------
* PURPOSE: 
* This function configure the PLL to generate the 48MHz clock required by
* the USB controller, considering the FOSC defined in the "config.h" file.
*----------------------------------------------------------------------------
* EXAMPLE:
* #define FOSC   8000 // 8MHz
* configure_usb_clock();
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void configure_usb_clock(void)
{
#ifndef PLL_USB_OK
#if FOSC == 3000
  Pll_set_div(PLL_3MHz);
  Pll_enable();
#endif

#if FOSC == 4000
  Pll_set_div(PLL_4MHz);
  Pll_enable();
#endif

#if FOSC == 6000
  Pll_set_div(PLL_6MHz);
  Pll_enable();
#endif

#if FOSC == 8000
  Pll_set_div(PLL_8MHz);
  Pll_enable();
#endif

#if FOSC == 12000
  Pll_set_div(PLL_12MHz);
  Pll_enable();
#endif

#if FOSC == 16000
  Pll_set_div(PLL_16MHz);
  Pll_enable();
#endif

#if FOSC == 18000
  Pll_set_div(PLL_18MHz);
  Pll_enable();
#endif

#if FOSC == 20000
  Pll_set_div(PLL_20MHz);
  Pll_enable();
#endif

#if FOSC == 24000
  Pll_set_div(PLL_24MHz);
  Pll_enable();
#endif

#if FOSC == 32000
  Pll_set_div(PLL_32MHz);
  Pll_enable();
#endif

#if FOSC == 40000
  Pll_set_div(PLL_40MHz);
  Pll_enable();
#endif

#if FOSC == 48000
  Usb_set_EXT48();
#endif

#if FOSC == 0000            /* frequency Auto-detection */

Uchar i;
Uchar reload;
  
  PLLCON = 0x00;
  
  if (CKCON0 & MSK_X2)
  {
    CKCON0 |= MSK_T0X2;
    reload = 6; 
  }
  else
  {
    CKCON0 &= ~MSK_T0X2;
    reload = 9;
  }
  
  TMOD = 0x01;                            /* put Timer 0 in mode 1 */
  USBINT = 0x00;
  i=reload;
  
  while (!(USBINT & MSK_SOFINT))          /* Do until Start Of Frame detection */
  {
    if (i==9)
    {
      Pll_stop();                         /* external 48 MHz supposed */
      Usb_set_EXT48();
    }
    else
    {
      Usb_clear_EXT48();                  /* PLL output supposed */
      Pll_set_div(pll_value[i]);          /* configure PLL */
      Pll_enable();
    }
    TH0 = TH0_value[i];                   /* Run Timer 0 */
    TL0 = TL0_value[i];
    TCON |= 0x10;
    while(((TCON & 0x20) != 0x20));       /* Wait Timer 0 Overflow */
    TCON &= ~(0x30);
    if (i==0)
    {
      i=reload;
    }
    else
    {
      i--;
    }
  }

  TH0  = 0;                               /* Reset Timer 0 Registers */
  TL0  = 0;
  TCON = 0;
  TMOD = 0;
#endif
#endif
}



/*F**************************************************************************
* NAME: usb_init 
*----------------------------------------------------------------------------
* PARAMS:
* return:   none
*----------------------------------------------------------------------------
* PURPOSE: 
* This function initializes the USB controller (low-level)
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_init (void)
{
#ifdef USB_FORCE_DETACH
register Byte   i,j;
#endif
configure_usb_clock();  // The PLL is already configured by the main task
Usb_enable();
#ifdef USB_FORCE_DETACH
Usb_detach();           // detach from USB interface if active connection set
for (i=0;--i;) for (j=(FOSC>>8);--j;); // Chap. 7 USB: wait 2.5us
#endif
}




