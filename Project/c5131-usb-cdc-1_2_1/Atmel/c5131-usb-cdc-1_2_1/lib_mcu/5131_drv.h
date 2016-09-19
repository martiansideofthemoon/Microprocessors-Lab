/*H**************************************************************************
* NAME:         5131_drv.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.7     
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the C51 driver definition
*****************************************************************************/

#ifndef _5131_DRV_H_
#define _5131_DRV_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ D E F I N I T I O N ________________________________________________*/
/* SYSTEM MANAGEMENT */
#define MSK_SMOD1   0x80    /* PCON */
#define MSK_SMOD0   0x40
#define MSK_GF1     0x08
#define MSK_GF0     0x04
#define MSK_PD      0x02
#define MSK_IDL     0x01

#define MSK_EXT16   0x40    /* AUXR */
#define MSK_M0      0x20
#define MSK_DPHDIS  0x10
#define MSK_XRS     0x0C
#define MSK_EXTRAM  0x02
#define MSK_AO      0x01
#define ERAM_256    0x00
#define ERAM_512    0x04
#define ERAM_1024   0x08
#define ERAM_2048   0x0C


/* PLL & CLOCK */
#define MSK_X2      0x01    /* CKCON */
#define MSK_T0X2    0x02
#define MSK_T1X2    0x04
#define MSK_WDX2    0x40


/* TIMERS */
#define MSK_GATE1   0x80    /* TMOD */
#define MSK_C_T1    0x40
#define MSK_MO1     0x30
#define MSK_GATE0   0x08
#define MSK_C_T0    0x04
#define MSK_MO0     0x03


/* WATCHDOG */
#define MSK_WTO     0x07    /* WDTPRG*/

/*_____ D E C L A R A T I O N ______________________________________________*/

#define Set_x2_mode()           (CKCON0 |= MSK_X2)
#define Set_x1_mode()           (CKCON0 &= ~MSK_X2)
#define Mode_x2()               ((CKCON0 & MSK_X2) == MSK_X2)

#define Set_timer0_x1_mode()    (CKCON0 |= MSK_T0X2)
#define Set_timer0_x2_mode()    (CKCON0 &=~MSK_T0X2)
#define Set_timer1_x1_mode()    (CKCON0 |= MSK_T1X2)
#define Set_timer1_x2_mode()    (CKCON0 &=~MSK_T1X2)
#define Set_timer2_x1_mode()    (CKCON0 |= MSK_T2X2)
#define Set_timer2_x2_mode()    (CKCON0 &=~MSK_T2X2)
#define Set_uart_x1_mode()      (CKCON0 |= MSK_UARTX2)
#define Set_uart_x2_mode()      (CKCON0 &=~MSK_UARTX2)
#define Set_pca_x1_mode()()     (CKCON0 |= MSK_PCAX2)
#define Set_pca_x2_mode()       (CKCON0 &=~MSK_PCAX2)

#define Set_idle_mode()         (PCON |= MSK_IDLE)
#define Set_power_down_mode()   (PCON |= MSK_PD)

#define Enable_eram()           (AUXR &= ~MSK_EXTRAM)
#define Disable_eram()          (AUXR |= MSK_EXTRAM)
#define Set_eram_size(s)        ((AUXR &= ~MSK_XRS),(AUXR |= s))

#define Enable_interrupt()      (EA = 1)
#define Disable_interrupt()     (EA = 0)

#define Enable_twi_interrupt()  (IEN1 |= 0x02)
#define Disable_twi_interrupt() (IEN1 &= 0xFD)

#define Disable_ale()           (AUXR |= MSK_AO)
#define Enable_ale()            (AUXR &= ~MSK_AO)
#define Switch_ale()            (AUXR ^= MSK_AO)

#define STANDARD_PORT           0
#define LED_PORT_2MA            1
#define LED_PORT_4MA            2
#define LED_PORT_10MA           3

#define Configure_led(num,type) {LEDCON &= (0xFF & ~(0x03 << (num*2))); \
                                 LEDCON |= (type << (num*2));}

#define Led_0_on()              (P3_3 = 0)
#define Led_0_off()             (P3_3 = 1)
#define Led_0_toggle()          (P3_3 = ~P3_3)
#define Led_0_status()          (P3_3)
#define Led_0_write(x)          (P3_3 = x) 
#define Led_1_on()              (P3_5 = 0)
#define Led_1_off()             (P3_5 = 1)
#define Led_1_toggle()          (P3_5 = ~P3_5)
#define Led_1_status()          (P3_5)
#define Led_1_write(x)          (P3_5 = x) 
#define Led_2_on()              (P3_6 = 0)
#define Led_2_off()             (P3_6 = 1)
#define Led_2_toggle()          (P3_6 = ~P3_6)
#define Led_2_status()          (P3_6)
#define Led_2_write(x)          (P3_6 = x) 
#define Led_3_on()              (P3_7 = 0)
#define Led_3_off()             (P3_7 = 1)
#define Led_3_toggle()          (P3_7 = ~P3_7)
#define Led_3_status()          (P3_7)
#define Led_3_write(x)          (P3_7 = x) 


#define Led_all_on()            (P3 &= 0x17)
#define Led_all_off()           (P3 |= ~0x17)

/*C**************************************************************************
* NAME: PLL_3MHz
*----------------------------------------------------------------------------
* PURPOSE:
* PLLDIV value for an oscillator frequency of 3MHz 
*****************************************************************************/
#define PLL_3MHz             0xF0

/*C**************************************************************************
* NAME: PLL_4MHz
*----------------------------------------------------------------------------
* PURPOSE:
* PLLDIV value for an oscillator frequency of 4MHz 
*****************************************************************************/
#define PLL_4MHz             0xC0

/*C**************************************************************************
* NAME: PLL_6MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 6MHz 
*****************************************************************************/
#define PLL_6MHz             0x70

/*C**************************************************************************
* NAME: PLL_8MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 8MHz 
*****************************************************************************/
#define PLL_8MHz             0x50

/*C**************************************************************************
* NAME: PLL_12MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 12MHz 
*****************************************************************************/
#define PLL_12MHz            0x30

/*C**************************************************************************
* NAME: PLL_16MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 16MHz 
*****************************************************************************/
#define PLL_16MHz            0x20

/*C**************************************************************************
* NAME: PLL_18MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 18MHz 
*****************************************************************************/
#define PLL_18MHz            0x72

/*C**************************************************************************
* NAME: PLL_20MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 20MHz 
*****************************************************************************/
#define PLL_20MHz            0xB4

/*C**************************************************************************
* NAME: PLL_24MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 24MHz 
*****************************************************************************/
#define PLL_24MHz            0x10

/*C**************************************************************************
* NAME: PLL_32MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 32MHz 
*****************************************************************************/
#define PLL_32MHz            0x21

/*C**************************************************************************
* NAME: PLL_40MHz
*----------------------------------------------------------------------------
* PURPOSE: 
* PLLDIV value for an oscillator frequency of 40MHz 
*****************************************************************************/
#define PLL_40MHz            0xB9

/* UART */
#define MSK_UART_MODE0          0x00 /* SCON */
#define MSK_UART_8BIT           0x40
#define MSK_UART_MODE1          0x40
#define MSK_UART_MODE2          0x80
#define MSK_UART_MODE3          0xC0
#define MSK_UART_9BIT           0xC0
#define MSK_UART_MULTIPROC      0x20
#define MSK_UART_ENABLE_RX      0x10
#define MSK_UART_TX_BIT9        0x08
#define MSK_UART_RX_BIT9        0x04
#define MSK_UART_TX_READY       0x02
#define MSK_UART_RX_DONE        0x01

#define Uart_hw_init(config)    (SCON=(config))   
//#define Uart_set_baudrate(bdr) defined in /lib_mcu/uart/uart_bdr.h
#define Uart_enable()           (SCON|=MSK_UART_ENABLE_RX|MSK_UART_TX_READY)
#define Uart_tx_ready()         ((const bit)TI)
#define Uart_set_tx_busy()      (TI=0)
#define Uart_send_byte(ch)      (SBUF=ch)
#define Uart_rx_ready()         ((const bit)RI)
#define Uart_get_byte()         ((const char)SBUF)
#define Uart_ack_rx_byte()      (RI=0)

#endif  /* _5131_DRV_H_ */

