/*H**************************************************************************
* NAME:         config.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* FILE_REV:     1.6     
*----------------------------------------------------------------------------
* PURPOSE: 
* Describes the system dependant software configuration.
* This file is included by all source files in order to access to system wide
* configuration.
*****************************************************************************/

#ifndef _CONFIG_H_
#define _CONFIG_H_

/*_____ I N C L U D E S ____________________________________________________*/


#include "lib_mcu/compiler.h"
#include "lib_mcu/reg_5131.h"
#include "lib_mcu/ext_5131.h"
#include "lib_mcu/5131_drv.h"

/*_____ M A C R O S ________________________________________________________*/

#define NO_SUPPORT_USB_PING_PONG       // CDC in ping-pong mode

/*_____ D E F I N I T I O N ________________________________________________*/

// Board config
#define FOSC                    24000
#define FILE_BOARD_H            "lib_board/c5131_evab.h"
#define CPUB_VERSION            0x0102
#define X2_MODE                              // Allow use of c51 x2 mode feature 

#define TWI_SCAL                120 //120, 160, 60 //dont work with 256, 224, 192, 960
#define SDA_SOFT                GENEB_SDA
#define SCL_SOFT                GENEB_SCL

//#define USE_STATIC_OUTPUT       // static output are faster but cannot be desactivated
//#define ENABLE_SPLASH_SCREEN      // Splash screen is first screen show after reset
//#define LOGO_ATMEL                // ASCII art of Logo ATMEL

#define BAUDRATE                115200       // in bps
#define BDR_GENERATOR           BRG_TIMER2   // Available value: BRG_INTERNAL, BRG_TIMER1, BRG_TIMER2 
#define UART_MINIMUM

#define HELLO_WORLD_DEMO

#ifdef HELLO_WORLD_DEMO
#define UART_USB_DEFAULT_INPUT             // HELLO WORLD demo
#define UART_USB_DEFAULT_OUTPUT            // HELLO WORLD demo
#endif

/*_____ D E F I N I T I O N ________________________________________________*/
/* Scheduler Definitions */
#define Scheduler_time_init     init_soft_timers

#define Scheduler_task_1_init   usb_task_init


#define Scheduler_task_1        usb_task


#define SCHEDULER_TYPE          SCHEDULER_FREE  // SCHEDULER_(TIMED|TASK|FREE|CUSTOM)

/* USB Configuration */
                                    /* DEVICE DESCRIPTOR */
#define USB_SPECIFICATION     0x0002
#define DEVICE_CLASS          0x02
#define DEVICE_SUB_CLASS      0
#define DEVICE_PROTOCOL       0
#define EP_CONTROL_LENGTH     32
#define VENDOR_ID             0xEB03        /* Atmel vendor ID = 03EBh */
#define PRODUCT_ID            0xFD2F        /* Product ID: 2FFDh = CDC C5131 */
#define RELEASE_NUMBER        0x2001
#define MAN_INDEX             0x00
#define PROD_INDEX            0x00
#define SN_INDEX              0x00
#define NB_CONFIGURATION      1

                                    /* CONFIGURATION DESCRIPTOR */
#define CONF_LENGTH           0x4300  // 3E00
#define NB_INTERFACE          2
#define CONF_NB               1
#define CONF_INDEX            0
#define CONF_ATTRIBUTES       USB_CONFIG_BUSPOWERED
#define MAX_POWER             50          /* 100 mA */
                                    /* INTERFACE 0 DESCRIPTOR */
#define INTERFACE0_NB          0
#define ALTERNATE0             0
#define NB_ENDPOINT0           1
#define INTERFACE0_CLASS       0x02 /* CDC ACM Comm */
#define INTERFACE0_SUB_CLASS   0x02
#define INTERFACE0_PROTOCOL    0x01
#define INTERFACE0_INDEX       0

                                    /* INTERFACE 1 DESCRIPTOR */
#define INTERFACE1_NB          1
#define ALTERNATE1             0
#define NB_ENDPOINT1           2
#define INTERFACE1_CLASS       0x0A /* CDC ACM Data */
#define INTERFACE1_SUB_CLASS   0
#define INTERFACE1_PROTOCOL    0
#define INTERFACE1_INDEX       0

                                    /* ENDPOINT 3 DESCRIPTOR */
#define ENDPOINT_NB_3         0x83
#define EP_ATTRIBUTES_3       0x03  // interrupt
#define EP_SIZE_3             ((Uint16)32) << 8 
#define EP_INTERVAL_3         0x02

#ifdef NO_SUPPORT_USB_PING_PONG
                                       /* ENDPOINT 1 DESCRIPTOR */
   #define ENDPOINT_NB_1         0x81
   #define EP_ATTRIBUTES_1       0x02  // bulk
   #define TX_EP_SIZE            32        
   #define EP_SIZE_1             ((Uint16)TX_EP_SIZE) << 8 
   #define EP_INTERVAL_1         0x00
   
                                       /* ENDPOINT 2 DESCRIPTOR */
   #define ENDPOINT_NB_2         0x02
   #define EP_ATTRIBUTES_2       0x02  // bulk
   #define RX_EP_SIZE            32        
   #define EP_SIZE_2             ((Uint16)RX_EP_SIZE) << 8 
   #define EP_INTERVAL_2         0x00
#else
                                       /* ENDPOINT 1 DESCRIPTOR */
   #define ENDPOINT_NB_1         0x84
   #define EP_ATTRIBUTES_1       0x02  // bulk
   #define TX_EP_SIZE            64        
   #define EP_SIZE_1             ((Uint16)TX_EP_SIZE) << 8 
   #define EP_INTERVAL_1         0x00
   
                                       /* ENDPOINT 2 DESCRIPTOR */
   #define ENDPOINT_NB_2         0x05
   #define EP_ATTRIBUTES_2       0x02  // bulk
   #define RX_EP_SIZE            64        
   #define EP_SIZE_2             ((Uint16)RX_EP_SIZE) << 8 
   #define EP_INTERVAL_2         0x00
#endif


#define USB_MANUFACTURER_NAME {'A'<<8, 'T'<<8, 'M'<<8, 'E'<<8, 'L'<<8}
#define USB_MN_LENGTH         5
#define USB_PRODUCT_NAME      {'A'<<8, 'T'<<8, '8'<<8, '9'<<8, 'C'<<8, '5'<<8, '1'<<8, \
                               '3'<<8, '1'<<8, ' '<<8, \
                               'E'<<8, 'v'<<8, 'a'<<8, 'B'<<8, ' '<<8, \
                               'C'<<8, 'D'<<8, 'C'<<8, ' '<<8, \
                               'E'<<8, 'x'<<8, 'a'<<8, 'm'<<8, 'p'<<8, 'l'<<8, 'e'<<8}
#define USB_PN_LENGTH         26
#define USB_SERIAL_NUMBER     {'1'<<8, '.'<<8, '0'<<8, '.'<<8, '0'<<8}
#define USB_SN_LENGTH         5

#define LANG_ID               0x00
#define LANGUAGE_ID           0x0904

#define EP_CONTROL            0x00
#define EP_CDC_IN             (ENDPOINT_NB_1 & 0x7F)
#define EP_CDC_OUT            ENDPOINT_NB_2
#define ENDPOINT_0            0x00
#define ENDPOINT_CDC_IN       ENDPOINT_NB_1
#define ENDPOINT_CDC_OUT      ENDPOINT_NB_2

#define RX_EP                 EP_CDC_OUT
#define TX_EP                 EP_CDC_IN


/*_____ D E C L A R A T I O N ______________________________________________*/


#endif /* _CONFIG_H_ */
