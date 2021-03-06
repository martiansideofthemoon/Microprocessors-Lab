/*C**************************************************************************
* NAME:         main.c
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.3     
*----------------------------------------------------------------------------
* PURPOSE: 
* This file contains an example of use of the USB controller.
*
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/


#include "config.h"
#include "modules/scheduler/scheduler.h"
#include "lib_mcu/usb/uart_usb_lib.h"
#ifndef HELLO_WORLD_DEMO
#include "lib_mcu/uart/uart_lib.h"
#endif
/*_____ G L O B A L S ________________________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*F**************************************************************************
* NAME: main 
*----------------------------------------------------------------------------
* PARAMS:   none
* return:   none
*----------------------------------------------------------------------------
* PURPOSE: example of use of the USB controller
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE: 
*----------------------------------------------------------------------------
* REQUIREMENTS: 
*****************************************************************************/
void main (void)
{
  Set_x2_mode();

#ifndef HELLO_WORLD_DEMO
  uart_init();
  uart_set_baudrate(115200);
#endif

  Enable_interrupt();

  scheduler();
}


