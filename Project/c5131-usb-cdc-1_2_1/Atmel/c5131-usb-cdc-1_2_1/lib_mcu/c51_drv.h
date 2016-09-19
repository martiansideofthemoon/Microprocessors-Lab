/*H**************************************************************************
* NAME:         c51_drv.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.1     
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the C51 driver definition
*****************************************************************************/

#ifndef _C51_DRV_H_
#define _C51_DRV_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ D E F I N I T I O N ________________________________________________*/


/*_____ D E C L A R A T I O N ______________________________________________*/

#define Set_x2_mode()           (CKCON |= MSK_X2)
#define Set_x1_mode()           (CKCON &= ~MSK_X2)
#define Mode_x2()               ((CKCON & MSK_X2) == MSK_X2)

#define Set_idle_mode()         (PCON |= MSK_IDLE)
#define Set_power_down_mode()   (PCON |= MSK_PD)

#define Enable_eram()           (AUXR &= ~MSK_EXTRAM)
#define Disable_eram()          (AUXR |= MSK_EXTRAM)
#define Set_eram_size(s)        (AUXR &= ~MSK_XRS); (AUXR |= s)

#define Enable_interrupt()      (EA = 1)
#define Disable_interrupt()     (EA = 0)


#endif  /* _C51_DRV_H_ */

