/*C**************************************************************************
* NAME:         usb_task.c
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.6     
*----------------------------------------------------------------------------
* PURPOSE: 
* This file controls the USB protocol.
*****************************************************************************/
/*_____ I N C L U D E S ____________________________________________________*/

#include "config.h"
#include "usb_task.h"
#include "lib_mcu\usb\usb_drv.h"
#include "lib_mcu\usb\uart_usb_lib.h"
#include "lib_mcu\uart\uart_lib.h"
#include "modules\usb_cdc_enum\usb_cdc_enum.h"
#include "modules\timer_soft\timer_soft.h"

#ifdef HELLO_WORLD_DEMO
#include <stdio.h>                /* prototype declarations for I/O functions */
#endif

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E F I N I T I O N ________________________________________________*/
sbit LED5 = P1^4; //assigning label to P1^4 as "LED"
int i = 0;
bit   usb_connected;
bit   flush_next_time;
Uchar usb_sof_counter;

extern Uchar tx_counter;
       Uchar last_tx_counter;

Uchar          buff[5];
Uchar          uart_usb_index;

extern         Uchar  usb_configuration_nb;
extern         bit    usb_flush_allowed;
#ifndef NO_SUPPORT_USB_PING_PONG
bdata bit   rx_bank;
#endif


/*_____ D E C L A R A T I O N ______________________________________________*/

/*F**************************************************************************
* NAME: usb_task_init
*----------------------------------------------------------------------------
* PARAMS:
* delay:    none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE: 
* This function initializes the USB controller and the associated variables.
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_task_init(void)
{ 
  configure_usb_clock();
  Usb_enable();
  Usb_detach();
  tempo(TIMER_5_MS);
  Usb_attach();

  usb_configure_endpoint(EP_CONTROL, CONTROL);
  usb_reset_endpoint(EP_CONTROL);

  usb_var_init();

  Configure_led(0,LED_PORT_2MA);
  Configure_led(1,LED_PORT_2MA);
  Configure_led(2,LED_PORT_2MA);
  Configure_led(3,LED_PORT_2MA);

  Led_all_off();

  uart_init();
  uart_usb_init();
  last_tx_counter = 0;
  uart_usb_index = 0;
  usb_connected = TRUE;
#ifndef NO_SUPPORT_USB_PING_PONG
  rx_bank = 0; 
#endif
}


/*F**************************************************************************
* NAME: usb_task
*----------------------------------------------------------------------------
* PARAMS:
* delay:    none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE: 
* This function manages the USB communication
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void usb_task(void)
{
#ifndef HELLO_WORLD_DEMO
Uchar j;
#endif
  if (!usb_connected)
  {
    if (Usb_resume())
    {
      Usb_clear_suspend_clock();
      usb_connected = TRUE;
      Usb_clear_suspend();
      Usb_clear_resume();
      Usb_clear_sof();
      Led_3_off();
    }
  }
  else
  {
    if (Usb_suspend())
    {
      usb_connected = FALSE;
      Led_all_off();
      Led_3_on();
      Usb_clear_suspend();
      Usb_set_suspend_clock();
    }
    if (Usb_reset())
    { 
      usb_var_init();
      Usb_clear_reset();
      Led_0_off(); Led_1_off(); Led_2_off();
      uart_usb_init();
      last_tx_counter = 0;
      uart_usb_index = 0;
#ifndef NO_SUPPORT_USB_PING_PONG
      rx_bank = 0; 
#endif

    }

    if (Usb_sof())
    {
      if (last_tx_counter == tx_counter)
      {
        uart_usb_flush();
      }
      last_tx_counter = tx_counter;
      usb_sof_counter ++;
      if (usb_sof_counter == 0x00)
      {
        Led_0_toggle();
      }
      Usb_clear_sof();
    }

    if (Usb_endpoint_interrupt())
    {
      Usb_select_ep(EP_CONTROL);
      if (Usb_setup_received()) { usb_enumeration_process(); }

      Usb_select_ep(3);
      if (Usb_tx_complete())    { Usb_clear_tx_complete();   }
    }
  }

#ifndef HELLO_WORLD_DEMO                  /* USB <-> RS 232 demo */
  if (uart_test_hit())
  {
    Led_1_on();
    buff[uart_usb_index++]=uart_getchar();
    if (uart_usb_tx_ready())
    {
      for (j=0;j<uart_usb_index;j++) {uart_usb_putchar (buff[j]);}
      uart_usb_index=0;
    }

    Led_1_off();
  }

  if (Uart_tx_ready())
  {
    if (uart_usb_test_hit()) { Led_2_on(); uart_putchar(uart_usb_getchar()); Led_2_off(); }
  }
#else                                     /* HELLO WORLD demo */
	if (P3_2 == 0)
  {
		if (test_hit())
  { 
	LED5 = ~LED5;
	putchar ('a');
		if (test_hit())
			putchar(_getkey());
	}
    Led_1_toggle();     		    /* Toggle LED 0 each time we print */
    //printf ("Hello World\r\n");   /* Print "Hello World" */
  }

  if (test_hit())
  { 
	//LED5 = ~LED5;
	//putchar (_getkey());
	}

#endif

}


