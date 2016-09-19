/*H**************************************************************************
* NAME:         mcu_drv.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.7     
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the C51 driver definition
*****************************************************************************/

#ifndef _C51_DRV_H_
#define _C51_DRV_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/


/*_____ D E F I N I T I O N ________________________________________________*/
/* INTERRUPT NUMBER */
#define IRQ_INT0                0
#define IRQ_T0                  1
#define IRQ_TIMER0              1 // Obsolete, use IRQ_T0
#define IRQ_INT1                2
#define IRQ_T1                  3
#define IRQ_TIMER1              3 // Obsolete, use IRQ_T1
#define IRQ_UART                4
#define IRQ_T2                  5
#define IRQ_TIMER2              5 // Obsolete, use IRQ_T2

/* SYSTEM MANAGEMENT */
#define MSK_SMOD1               0x80 /* PCON */
#define MSK_SMOD0               0x40
#define MSK_GF1                 0x08
#define MSK_GF0                 0x04
#define MSK_PD                  0x02
#define MSK_IDL                 0x01

#define MSK_EXT16               0x40 /* AUXR */
#define MSK_M0                  0x20
#define MSK_DPHDIS              0x10
#define MSK_XRS                 0x0C
#define MSK_EXTRAM              0x02
#define MSK_AO                  0x01
#define ERAM_256                0x00
#define ERAM_512                0x04
#define ERAM_1024               0x08
#define ERAM_2048               0x0C


/* PLL & CLOCK */
#define MSK_X2                  0x01 /* CKCON */
#define MSK_T0X2                0x02
#define MSK_T1X2                0x04
#define MSK_T2X2                0x08
#define MSK_UARTX2              0x10
#define MSK_PCAX2               0x20
#define MSK_WDX2                0x40


/* TIMERS */
#define MSK_GATE1               0x80 /* TMOD */
#define MSK_C_T1                0x40
#define MSK_MO1                 0x30
#define MSK_GATE0               0x08
#define MSK_C_T0                0x04
#define MSK_MO0                 0x03


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


/* WATCHDOG */
#define MSK_WTO                 0x07 /* WDTPRG*/

/* PCA */
#define MSK_CF                  0x80 /*CCON*/
#define MSK_CR                  0x40

#define MSK_CCF4                0x10
#define MSK_CCF3                0x08
#define MSK_CCF2                0x04
#define MSK_CCF1                0x02
#define MSK_CCF0                0x01

#define MSK_CDIL                0x80 
#define MSK_WDTE                0x40
#define MSK_CPS1                0x04
#define MSK_CPS0                0x02
#define MSK_ECF                 0x01

#define MSK_ECM0                0x40 /*CCAPM0*/
#define MSK_CAPP0               0x20
#define MSK_CAPN0               0x10
#define MSK_MAT0                0x08
#define MSK_TOG0                0x04
#define MSK_PWM0                0x02
#define MSK_ECCF0               0x01

#define MSK_ECM1                0x40 /*CCAPM1*/
#define MSK_CAPP1               0x20
#define MSK_CAPN1               0x10
#define MSK_MAT1                0x08
#define MSK_TOG1                0x04
#define MSK_PWM1                0x02
#define MSK_ECCF1               0x01

#define MSK_ECM2                0x40 /*CCAPM2*/
#define MSK_CAPP2               0x20
#define MSK_CAPN2               0x10
#define MSK_MAT2                0x08
#define MSK_TOG2                0x04
#define MSK_PWM2                0x02
#define MSK_ECCF2               0x01

#define MSK_ECM3                0x40 /*CCAPM3*/
#define MSK_CAPP3               0x20
#define MSK_CAPN3               0x10
#define MSK_MAT3                0x08
#define MSK_TOG3                0x04
#define MSK_PWM3                0x02
#define MSK_ECCF3               0x01

#define MSK_ECM4                0x40 /*CCAPM4*/
#define MSK_CAPP4               0x20
#define MSK_CAPN4               0x10
#define MSK_MAT4                0x08
#define MSK_TOG4                0x04
#define MSK_PWM4                0x02
#define MSK_ECCF4               0x01

#define MSK_CCAP0H7             0x80 /*CCAP0H*/
#define MSK_CCAP0H6             0x40
#define MSK_CCAP0H5             0x20
#define MSK_CCAP0H4             0x10
#define MSK_CCAP0H3             0x08
#define MSK_CCAP0H2             0x04
#define MSK_CCAP0H1             0x02
#define MSK_CCAP0H0             0x01

#define MSK_CCAP1H7             0x80 /*CCAP1H*/
#define MSK_CCAP1H6             0x40
#define MSK_CCAP1H5             0x20
#define MSK_CCAP1H4             0x10
#define MSK_CCAP1H3             0x08
#define MSK_CCAP1H2             0x04
#define MSK_CCAP1H1             0x02
#define MSK_CCAP1H0             0x01

#define MSK_CCAP2H7             0x80 /*CCAP2H*/
#define MSK_CCAP2H6             0x40
#define MSK_CCAP2H5             0x20
#define MSK_CCAP2H4             0x10
#define MSK_CCAP2H3             0x08
#define MSK_CCAP2H2             0x04
#define MSK_CCAP2H1             0x02
#define MSK_CCAP2H0             0x01

#define MSK_CCAP3H7             0x80 /*CCAP3H*/
#define MSK_CCAP3H6             0x40
#define MSK_CCAP3H5             0x20
#define MSK_CCAP3H4             0x10
#define MSK_CCAP3H3             0x08
#define MSK_CCAP3H2             0x04
#define MSK_CCAP3H1             0x02
#define MSK_CCAP3H0             0x01

#define MSK_CCAP4H7             0x80 /*CCAP4H*/
#define MSK_CCAP4H6             0x40
#define MSK_CCAP4H5             0x20
#define MSK_CCAP4H4             0x10
#define MSK_CCAP4H3             0x08
#define MSK_CCAP4H2             0x04
#define MSK_CCAP4H1             0x02
#define MSK_CCAP4H0             0x01

#define MSK_CCAP0L7             0x80 /*CCAP0L*/
#define MSK_CCAP0L6             0x40
#define MSK_CCAP0L5             0x20
#define MSK_CCAP0L4             0x10
#define MSK_CCAP0L3             0x08
#define MSK_CCAP0L2             0x04
#define MSK_CCAP0L1             0x02
#define MSK_CCAP0L0             0x01

#define MSK_CCAP1L7             0x80 /*CCAP1L*/
#define MSK_CCAP1L6             0x40
#define MSK_CCAP1L5             0x20
#define MSK_CCAP1L4             0x10
#define MSK_CCAP1L3             0x08
#define MSK_CCAP1L2             0x04
#define MSK_CCAP1L1             0x02
#define MSK_CCAP1L0             0x01

#define MSK_CCAP2L7             0x80 /*CCAP2L*/
#define MSK_CCAP2L6             0x40
#define MSK_CCAP2L5             0x20
#define MSK_CCAP2L4             0x10
#define MSK_CCAP2L3             0x08
#define MSK_CCAP2L2             0x04
#define MSK_CCAP2L1             0x02
#define MSK_CCAP2L0             0x01

#define MSK_CCAP3L7             0x80 /*CCAP3L*/
#define MSK_CCAP3L6             0x40
#define MSK_CCAP3L5             0x20
#define MSK_CCAP3L4             0x10
#define MSK_CCAP3L3             0x08
#define MSK_CCAP3L2             0x04
#define MSK_CCAP3L1             0x02
#define MSK_CCAP3L0             0x01

#define MSK_CCAP4L7             0x80 /*CCAP4L*/
#define MSK_CCAP4L6             0x40
#define MSK_CCAP4L5             0x20
#define MSK_CCAP4L4             0x10
#define MSK_CCAP4L3             0x08
#define MSK_CCAP4L2             0x04
#define MSK_CCAP4L1             0x02
#define MSK_CCAP4L0             0x01

/*_____ D E C L A R A T I O N ______________________________________________*/

#define Set_x2_mode()           (CKCON |= MSK_X2)
#define Set_x1_mode()           (CKCON &= ~MSK_X2)
#define Mode_x2()               ((CKCON & MSK_X2) == MSK_X2)

#define Set_timer0_x1_mode()    (CKCON |= MSK_T0X2)
#define Set_timer0_x2_mode()    (CKCON &=~MSK_T0X2)
#define Set_timer1_x1_mode()    (CKCON |= MSK_T1X2)
#define Set_timer1_x2_mode()    (CKCON &=~MSK_T1X2)
#define Set_timer2_x1_mode()    (CKCON |= MSK_T2X2)
#define Set_timer2_x2_mode()    (CKCON &=~MSK_T2X2)
#define Set_uart_x1_mode()      (CKCON |= MSK_UARTX2)
#define Set_uart_x2_mode()      (CKCON &=~MSK_UARTX2)
#define Set_pca_x1_mode()()     (CKCON |= MSK_PCAX2)
#define Set_pca_x2_mode()       (CKCON &=~MSK_PCAX2)

#define Set_idle_mode()         (PCON |= MSK_IDLE)
#define Set_power_down_mode()   (PCON |= MSK_PD)

#define Enable_eram()           (AUXR &= ~MSK_EXTRAM)
#define Disable_eram()          (AUXR |= MSK_EXTRAM)
#define Set_eram_size(s)        ((AUXR &= ~MSK_XRS),(AUXR |= s))

#define Disable_ale()           (AUXR |= MSK_AO)
#define Enable_ale()            (AUXR &= ~MSK_AO)
#define Switch_ale()            (AUXR ^= MSK_AO)

#define Enable_interrupt()      (EA = 1)
#define Disable_interrupt()     (EA = 0)

#define Uart_hw_init(config)    (SCON=(config))   
//#define Uart_set_baudrate(bdr) defined in /lib_mcu/uart/uart_bdr.h
#define Uart_enable()           (SCON|=MSK_UART_ENABLE_RX|MSK_UART_TX_READY)
#define Uart_tx_ready()         ((const bit)TI)
#define Uart_set_tx_busy()      (TI=0)
#define Uart_send_byte(ch)      (SBUF=ch)
#define Uart_rx_ready()         ((const bit)RI)
#define Uart_get_byte()         ((const char)SBUF)
#define Uart_ack_rx_byte()      (RI=0)

#endif  /* _C51_DRV_H_ */

