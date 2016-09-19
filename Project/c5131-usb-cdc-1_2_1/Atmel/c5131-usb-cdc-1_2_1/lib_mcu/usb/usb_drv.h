/*H**************************************************************************
* NAME:         usb_drv.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.12.2.1     
*----------------------------------------------------------------------------
* PURPOSE: 
* This file contains the USB low level driver definition                                      
*****************************************************************************/

#ifndef _USB_DRV_H_
#define _USB_DRV_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*F**************************************************************************
* NAME: CONTROL / BULK / INTERRUPT / ISOCHRONOUS
*----------------------------------------------------------------------------
* PURPOSE: 
* These define are the values used to enable and configure an endpoint.
* They are written in the UEPCONX register.
*****************************************************************************/

#define CONTROL              0x80
#define BULK_IN              0x86
#define BULK_OUT             0x82
#define INTERRUPT_IN         0x87
#define INTERRUPT_OUT        0x83
#define ISOCHRONOUS_IN       0x85
#define ISOCHRONOUS_OUT      0x81
#define BULK_MAX_SIZE        ((Uchar)64)

/*M**************************************************************************
* NAME: wSWAP 
*----------------------------------------------------------------------------
* PARAMS:
* x     : (Uint16) the 16 bit word to swap 
* return: (Uint16) the 16 bit word x with the 2 bytes swaped  
*----------------------------------------------------------------------------
* PURPOSE: 
* This macro swaps the Uchar order in words.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define wSWAP(x) ((((x)>>8)&0x00FF)|(((x)<<8)&0xFF00)) ;

/* {for langdoc}*/

/*M**************************************************************************
* NAME: dwSWAP 
*----------------------------------------------------------------------------
* PARAMS:
* x     : (Uint32) the 32 bit double word to swap 
* return: (Uint32) the 32 bit double word x with the 4 bytes swaped  
*----------------------------------------------------------------------------
* PURPOSE: 
* This macro swaps the Uchar order in double words.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define dwSWAP(x) ((((x)>>24)&0x000000FF)|(((x)>>8)&0x0000FF00)|(((x)<<24)&0xFF000000)|(((x)<<8)&0x00FF0000))

/* {for langdoc}*/

/*M**************************************************************************
* NAME: General endpoint management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the common features of the endpoints
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define Usb_select_ep(e)              (UEPNUM = e)
#define Usb_configure_ep_type(x)      (UEPCONX = x)
#define Usb_set_stall_request()       (UEPSTAX |= MSK_STALLRQ)
#define Usb_clear_stall_request()     (UEPSTAX &= ~MSK_STALLRQ)
#define Usb_clear_stalled()           (UEPSTAX &= ~MSK_STALLED)
#define Usb_stall_requested()         (UEPSTAX & MSK_STALLRQ)
#define Usb_stall_sent()              (UEPSTAX & MSK_STALLED)
#define Usb_read_byte()               (UEPDATX)
#define Usb_write_byte(x)             (UEPDATX = x)
#define Usb_endpoint_interrupt()      (UEPINT != 0 )

/* {for langdoc}*/

/*M**************************************************************************
* NAME: Usb_test_it_ep
*----------------------------------------------------------------------------
* PARAMS:   end point number
* return:   0 if no interrupt record in the end point else different of 0
*----------------------------------------------------------------------------
* PURPOSE: 
* This function check if interrupt is pending in the end point
*----------------------------------------------------------------------------
* EXAMPLE:
* if (Usb_test_it_ep(3)) // True if interrupt on endpoint 3
*****************************************************************************/
#define Usb_test_it_ep(ep_num)        (UEPINT & ((Uchar)1<<(ep_num)))

/* {for langdoc}*/

/*M**************************************************************************
* NAME: OUT endpoint management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the OUT endpoints.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define Usb_clear_rx()                (UEPSTAX &= ~MSK_RXOUT)

#define Usb_clear_rx_bank0()          (UEPSTAX &= ~MSK_RXOUTB0)
#define Usb_clear_rx_bank1()          (UEPSTAX &= ~MSK_RXOUTB1)
#define Usb_rx_complete()             (UEPSTAX & MSK_RXOUTB0B1)

#ifdef NO_SUPPORT_USB_PING_PONG
  #define Usb_clear_rx_cdc()                       Usb_clear_rx()
#else
  extern bdata bit   rx_bank;
  #define Usb_clear_rx_cdc()                      {if(rx_bank){Usb_clear_rx_bank1();}else{Usb_clear_rx_bank0();}rx_bank=~rx_bank;}
#endif
/* {for langdoc}*/

/*M**************************************************************************
* NAME: IN endpoint management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the IN endpoints.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define Usb_set_tx_ready()            (UEPSTAX |= MSK_TXRDY)
#define Usb_clear_tx_ready()          (UEPSTAX &= ~MSK_TXRDY)
#define Usb_clear_tx_complete()       (UEPSTAX &= ~MSK_TXCMPL)
#define Usb_tx_complete()             (UEPSTAX & MSK_TXCMPL)
#define Usb_tx_ready()                (UEPSTAX & MSK_TXRDY)

/* {for langdoc}*/

/*M**************************************************************************
* NAME: CONTROL endpoint management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the Control endpoints.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define Usb_clear_rx_setup()          (UEPSTAX &= ~MSK_RXSETUP)
#define Usb_setup_received()          (UEPSTAX & MSK_RXSETUP)
#define Usb_clear_DIR()               (UEPSTAX &= ~MSK_DIR)
#define Usb_set_DIR()                 (UEPSTAX |= MSK_DIR)

/* {for langdoc}*/

/*M**************************************************************************
* NAME: General USB management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the USB controller.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define Usb_enable()                  (USBCON |= MSK_USBE)
#define Usb_disable()                 (USBCON &= ~MSK_USBE)
#define Usb_detach()                  (USBCON |= MSK_DETACH)
#define Usb_attach()                  (USBCON &= ~MSK_DETACH)
#define Usb_clear_reset()             (USBINT &= ~MSK_EORINT)
#define Usb_clear_resume()            (USBINT &= ~MSK_WUPCPU)
#define Usb_clear_sof()               (USBINT &= ~MSK_SOFINT)
#define Usb_clear_suspend()           (USBINT &= ~MSK_SPINT)
#define Usb_suspend()                 (USBINT & MSK_SPINT)
#define Usb_resume()                  (USBINT & MSK_WUPCPU)
#define Usb_reset()                   (USBINT & MSK_EORINT)
#define Usb_sof()                     (USBINT & MSK_SOFINT)
#define Usb_configure_address(x)      (USBADDR = (0x80 | x))
#define Usb_address()                 (USBADDR & 0x7F)
#define Usb_set_CONFG()               (USBCON |= MSK_CONFG)
#define Usb_clear_CONFG()             (USBCON &= ~MSK_CONFG)
#define Usb_set_FADDEN()              (USBCON |= MSK_FADDEN)
#define Usb_clear_FADDEN()            (USBCON &= ~MSK_FADDEN)
#define Usb_set_suspend_clock()       (USBCON |= MSK_SUSPCLK)
#define Usb_clear_suspend_clock()     (USBCON &= ~MSK_SUSPCLK)

#define usb_send_packet(ep_num,tbuf,data_length)     (Usb_select_ep(ep_num), usb_send_right_packet(tbuf,data_length)) 
#define usb_read_packet(ep_num, rbuf,data_length)   (Usb_select_ep(ep_num), usb_read_right_packet(rbuf,data_length))

/* {for langdoc}*/

/*M**************************************************************************
* NAME: USB interrupt management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the USB controller.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/

#define Usb_enable_int()              (IEN1 |= MSK_EUSB)
#define Usb_disable_int()             (IEN1 &= ~MSK_EUSB)

#define Usb_enable_reset_int()        (USBIEN |= MSK_EEORINT)
#define Usb_enable_resume_int()       (USBIEN |= MSK_EWUPCPU)
#define Usb_enable_sof_int()          (USBIEN |= MSK_ESOFINT)
#define Usb_enable_suspend_int()      (USBIEN |= MSK_ESPINT)
#define Usb_disable_reset_int()       (USBIEN &= ~MSK_EEORINT)
#define Usb_disable_resume_int()      (USBIEN &= ~MSK_EWUPCPU)
#define Usb_disable_sof_int()         (USBIEN &= ~MSK_ESOFINT)
#define Usb_disable_suspend_int()     (USBIEN &= ~MSK_ESPINT)

#define Usb_enable_ep_int(e)          (UEPIEN |= (0x01 << e))
#define Usb_disable_ep_int(e)         (UEPIEN &= ~(0x01 << e))


/* {for langdoc}*/

/*M**************************************************************************
* NAME: USB clock management 
*----------------------------------------------------------------------------
* PARAMS:
*----------------------------------------------------------------------------
* PURPOSE: 
* These macros manage the USB clock.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
#define Usb_set_EXT48()               (PLLCON |= MSK_EXT48)
#define Usb_clear_EXT48()             (PLLCON &= ~MSK_EXT48)

#define Pll_stop()                    (PLLCON &= ~MSK_PLLEN)
#define Pll_set_div(n)                (PLLDIV = n)
#define Pll_enable()                  (PLLCON |= MSK_PLLEN) 

/* {for langdoc}*/

/*_____ D E C L A R A T I O N ______________________________________________*/

void    usb_configure_endpoint       (Uchar , Uchar);
Uchar   usb_get_nb_byte              (void);
Uint16  usb_get_nb_byte_epw          (void);
Uchar*  usb_send_ep0_packet          (Uchar*, Uchar);
Uchar*  usb_send_right_packet        (Uchar*, Uchar);
Uchar*  usb_read_right_packet        ( Uchar*, Uchar);
void    usb_reset_endpoint           (Uchar);
Uchar   usb_select_enpoint_interrupt (void);
void    usb_halt_endpoint            (Uchar);
void    configure_usb_clock          (void);


#endif  /* _USB_DRV_H_ */

