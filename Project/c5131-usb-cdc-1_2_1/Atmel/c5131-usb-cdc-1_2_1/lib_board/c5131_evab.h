/*H**************************************************************************
* NAME:         c5131_evab.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.8     
*----------------------------------------------------------------------------
* PURPOSE: 
* Configuration file. Selection of the device.
*****************************************************************************/
#ifndef _C5131_EVAB_H
#define _C5131_EVAB_H

/*_____ D E F I N I T I O N S ______________________________________________*/
#define GENEB_BUZZER            P1_5 // CPU I/O Port connected to GENEB Buzzer Pin or mute
#define GENEB_BP1               P3_2 // CPU I/O Port connected to GENEB BP1

#define GENEB_TWI_IT            P3_2 // Port I/O IT pin of CPU connected to GENEB TWI_IT Pin
#define GENEB_SDA               P1_1
#define GENEB_SCL               P1_0

#define GENEB_A16               P3_4 // CPU I/O Port connected to GENEB A16
#define GENEB_CS_RAM            P1_2
#define GENEB_CS_FLASH          P1_3
#define GENEB_ISP_FLASH         P1_4

#define RST_ETH                 P1_5
#define CS_ETH                  P3_5

#define CPUb_enable_all_leds()  (AUXR&=~1,P3_0=0,P3_1=0,P4_0=0,P4_1=0,P1_5=0)
#define CPUb_disable_all_leds() (AUXR|=1,P3_0=1,P3_1=1,P4_0=1,P4_1=1,P1_5=1)
#define Geneb_enable_ram()      (GENEB_ISP_FLASH=1,CS_ETH=1,GENEB_CS_RAM=0)
#define Geneb_disable_ram()     (GENEB_CS_RAM=1)
#define Geneb_enable_isp()      (GENEB_ISP_FLASH=0,GENEB_CS_FLASH=1)
#define Geneb_disable_isp()     (GENEB_ISP_FLASH=1)

/*_____ I N C L U D E S ____________________________________________________*/
#ifdef GENEB_VERSION
#include "lib_board/geneb.h"
#endif


/*_____ M A C R O S ________________________________________________________*/

/*_____ D E C L A R A T I O N S ____________________________________________*/

#endif  /* _C5131_EVAB_H */



