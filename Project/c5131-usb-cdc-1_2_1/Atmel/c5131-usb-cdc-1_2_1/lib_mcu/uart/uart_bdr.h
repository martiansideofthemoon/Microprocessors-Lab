/*H**************************************************************************
* NAME:         uart_bdr.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.5     
*----------------------------------------------------------------------------
* PURPOSE: 
* Provide Baudrate configuration for MCU
*****************************************************************************/

#ifndef _UART_BDR_H_
#define _UART_BDR_H_
// <== Using generator script/bdr.c c5131-usb-cdc-1_2_1 $Id: uart_bdr.h,v 1.5 2003/08/19 12:44:19 njourdan Exp $
// BRG-0 refers to standard Atmel Internal Baudrate Generator peripheral (if available)
// BRG-1 refers to standard C51 Timer 1 peripheral used as Baudrate Generator
// BRG-2 refers to standard C52 Timer 2 peripheral used as Baudrate Generator (if available)

#ifndef FOSC
#error You must define FOSC in config.h
#elif   FOSC     ==             32 // Fosc =     32.768 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          247 //    113 bps (delta=2.72%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //    113 bps (delta=2.72%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //    113 bps (delta=2.72%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          249 //    292 bps (delta=2.66%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65529 //    292 bps (delta=2.66%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 *300 
    #error BRG-1 *110 
    #error BRG-2 110 *300 
  #endif
#elif   FOSC     ==             65 // Fosc =     65.536 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          253 //    113 bps (delta=2.72%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          253 //    113 bps (delta=2.72%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65518 //    113 bps (delta=2.72%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          249 //    292 bps (delta=2.66%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 //    292 bps (delta=2.66%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 
    #error BRG-1 110 
    #error BRG-2 110 300 
  #endif
#elif   FOSC     ==           1000 // Fosc =   1000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          209 //    110 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          209 //    110 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65252 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          204 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //    306 bps (delta=2.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65432 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          243 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   1157 bps (delta=3.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 //   4807 bps (delta=0.14%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 *4800 
    #error BRG-1 110 300 *1200 
    #error BRG-2 110 300 1200 2400 *4800 
  #endif
#elif   FOSC     ==           1834 // Fosc =   1834.200 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          213 //    111 bps (delta=0.90%)
    #define BRG1_INIT          213 //    111 bps (delta=0.90%)
    #define BRG2_INIT        65015 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           65 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          240 //    298 bps (delta=0.66%)
    #define BRG2_INIT        65345 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          252 //   1194 bps (delta=0.50%)
    #define BRG1_INIT          252 //   1194 bps (delta=0.50%)
    #define BRG2_INIT        65488 //   1194 bps (delta=0.50%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          254 //   2388 bps (delta=0.50%)
    #define BRG1_INIT          254 //   2388 bps (delta=0.50%)
    #define BRG2_INIT        65512 //   2388 bps (delta=0.50%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          255 //   4776 bps (delta=0.50%)
    #define BRG1_INIT          255 //   4776 bps (delta=0.50%)
    #define BRG2_INIT        65524 //   4776 bps (delta=0.50%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          255 //   9553 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //   9553 bps (delta=0.48%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //   9553 bps (delta=0.48%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          253 //  19106 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          255 //  19106 bps (delta=0.48%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 //  19106 bps (delta=0.48%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          255 //  28659 bps (delta=0.48%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 //  28659 bps (delta=0.48%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          253 //  38212 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 //  38212 bps (delta=0.48%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          255 //  57318 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 //  57318 bps (delta=0.48%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 114637 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 114637 bps (delta=0.48%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 *38400 57600 *115200 
    #error BRG-1 110 300 1200 2400 4800 9600 *19200 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 *38400 57600 *115200 
  #endif
#elif   FOSC     ==           2000 // Fosc =   2000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          209 //    110 bps (delta=0.00%)
    #define BRG1_INIT          209 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64968 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          152 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          221 //    297 bps (delta=1.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65328 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          230 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   1157 bps (delta=3.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   2314 bps (delta=3.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 //   9615 bps (delta=0.15%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 *9600 
    #error BRG-1 110 300 1200 *2400 
    #error BRG-2 110 300 1200 2400 4800 *9600 
  #endif
#elif   FOSC     ==           2457 // Fosc =   2457.600 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          198 //    110 bps (delta=0.00%)
    #define BRG1_INIT          198 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64838 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          128 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //    297 bps (delta=1.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65280 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          224 //   1200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   1163 bps (delta=3.08%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65472 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          240 //   2400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   2327 bps (delta=3.04%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65504 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          248 //   4800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          252 //   9600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          254 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          255 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 //  38400 bps (delta=0.00%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 38400 
    #error BRG-1 110 300 1200 *2400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 38400 
  #endif
#elif   FOSC     ==           3000 // Fosc =   3000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          185 //    110 bps (delta=0.00%)
    #define BRG1_INIT          185 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64684 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          230 //    300 bps (delta=0.00%)
    #define BRG1_INIT          230 //    300 bps (delta=0.00%)
    #define BRG2_INIT        65224 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          243 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //   1201 bps (delta=0.08%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          217 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65497 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          246 //   4687 bps (delta=2.35%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65516 //   4687 bps (delta=2.35%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          251 //   9375 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65526 //   9375 bps (delta=2.34%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          251 //  18750 bps (delta=2.34%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65531 //  18750 bps (delta=2.34%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          251 //  37500 bps (delta=2.34%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65531 //  37500 bps (delta=2.34%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 *38400 
    #error BRG-1 110 300 1200 *2400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 *38400 
  #endif
#elif   FOSC     ==           3276 // Fosc =   3276.800 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          179 //    110 bps (delta=0.00%)
    #define BRG1_INIT          179 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64606 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          199 //    299 bps (delta=0.33%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          199 //    299 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65195 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          171 //   1204 bps (delta=0.33%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   1219 bps (delta=1.58%)
    #define BRG2_INIT        65451 //   1204 bps (delta=0.33%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          213 //   2381 bps (delta=0.79%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   2438 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65493 //   2381 bps (delta=0.79%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          235 //   4876 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   4876 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65515 //   4876 bps (delta=1.58%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          245 //   9309 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 //   9309 bps (delta=3.03%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          245 //  18618 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 //  18618 bps (delta=3.03%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          249 //  29257 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65529 //  29257 bps (delta=1.58%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 *19200 *28800 
    #error BRG-1 110 300 1200 2400 *4800 
    #error BRG-2 110 300 1200 2400 4800 9600 *19200 *28800 
  #endif
#elif   FOSC     ==           3579 // Fosc =   3579.545 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          172 //    110 bps (delta=0.00%)
    #define BRG1_INIT          172 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64520 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          225 //    300 bps (delta=0.00%)
    #define BRG1_INIT          225 //    300 bps (delta=0.00%)
    #define BRG2_INIT        65164 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          163 //   1202 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          248 //   1165 bps (delta=2.91%)
    #define BRG2_INIT        65443 //   1202 bps (delta=0.16%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          209 //   2380 bps (delta=0.83%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          252 //   2330 bps (delta=2.91%)
    #define BRG2_INIT        65489 //   2380 bps (delta=0.83%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          233 //   4863 bps (delta=1.31%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          254 //   4660 bps (delta=2.91%)
    #define BRG2_INIT        65513 //   4863 bps (delta=1.31%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          255 //   9321 bps (delta=2.90%)
    #define BRG1_INIT          255 //   9321 bps (delta=2.90%)
    #define BRG2_INIT        65524 //   9321 bps (delta=2.90%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          255 //  18643 bps (delta=2.90%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //  18643 bps (delta=2.90%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //  18643 bps (delta=2.90%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          254 //  27965 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  27965 bps (delta=2.89%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          253 //  37286 bps (delta=2.90%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          255 //  37286 bps (delta=2.90%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 //  37286 bps (delta=2.90%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          255 //  55930 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 //  55930 bps (delta=2.89%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 111860 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 111860 bps (delta=2.89%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 223721 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 223721 bps (delta=2.89%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-1 110 300 1200 2400 4800 9600 19200 *38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
  #endif
#elif   FOSC     ==           3668 // Fosc =   3668.400 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           83 //    110 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT           83 //    110 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        64494 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           65 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          224 //    298 bps (delta=0.66%)
    #define BRG2_INIT        65154 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          248 //   1194 bps (delta=0.50%)
    #define BRG1_INIT          248 //   1194 bps (delta=0.50%)
    #define BRG2_INIT        65441 //   1206 bps (delta=0.50%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          252 //   2388 bps (delta=0.50%)
    #define BRG1_INIT          252 //   2388 bps (delta=0.50%)
    #define BRG2_INIT        65488 //   2388 bps (delta=0.50%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          254 //   4776 bps (delta=0.50%)
    #define BRG1_INIT          254 //   4776 bps (delta=0.50%)
    #define BRG2_INIT        65512 //   4776 bps (delta=0.50%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          255 //   9553 bps (delta=0.48%)
    #define BRG1_INIT          255 //   9553 bps (delta=0.48%)
    #define BRG2_INIT        65524 //   9553 bps (delta=0.48%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          255 //  19106 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //  19106 bps (delta=0.48%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //  19106 bps (delta=0.48%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          254 //  28659 bps (delta=0.48%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  28659 bps (delta=0.48%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          253 //  38212 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          255 //  38212 bps (delta=0.48%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 //  38212 bps (delta=0.48%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          255 //  57318 bps (delta=0.48%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 //  57318 bps (delta=0.48%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 114637 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 114637 bps (delta=0.48%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 229275 bps (delta=0.48%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 229275 bps (delta=0.48%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-1 110 300 1200 2400 4800 9600 19200 *38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
  #endif
#elif   FOSC     ==           3686 // Fosc =   3686.400 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          169 //    110 bps (delta=0.00%)
    #define BRG1_INIT          169 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64489 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          224 //    300 bps (delta=0.00%)
    #define BRG1_INIT          224 //    300 bps (delta=0.00%)
    #define BRG2_INIT        65152 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          248 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          248 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        65440 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          252 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          252 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65488 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          254 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          254 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65512 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          255 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          255 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65524 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          255 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //  19200 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          254 //  28800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          253 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          255 //  38400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          255 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 230400 bps (delta=0.00%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-1 110 300 1200 2400 4800 9600 19200 *38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
  #endif
#elif   FOSC     ==           4000 // Fosc =   4000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          162 //    110 bps (delta=0.00%)
    #define BRG1_INIT          162 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64400 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           48 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          187 //    301 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65120 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          204 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //   1225 bps (delta=2.08%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65432 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          230 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   2314 bps (delta=3.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   4629 bps (delta=3.56%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 //  19230 bps (delta=0.15%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          247 //  27777 bps (delta=3.55%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  27777 bps (delta=3.55%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 *19200 *28800 
    #error BRG-1 110 300 1200 2400 *4800 
    #error BRG-2 110 300 1200 2400 4800 9600 *19200 *28800 
  #endif
#elif   FOSC     ==           4194 // Fosc =   4194.304 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          157 //    110 bps (delta=0.00%)
    #define BRG1_INIT          157 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64345 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           38 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          183 //    299 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65100 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          147 //   1202 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   1213 bps (delta=1.08%)
    #define BRG2_INIT        65427 //   1202 bps (delta=0.16%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          201 //   2383 bps (delta=0.70%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   2427 bps (delta=1.12%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65481 //   2383 bps (delta=0.70%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          229 //   4854 bps (delta=1.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   4854 bps (delta=1.12%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65509 //   4854 bps (delta=1.12%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          249 //   9362 bps (delta=2.47%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65522 //   9362 bps (delta=2.47%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          249 //  18724 bps (delta=2.47%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 //  18724 bps (delta=2.47%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          247 //  29127 bps (delta=1.13%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  29127 bps (delta=1.13%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          249 //  37449 bps (delta=2.47%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65529 //  37449 bps (delta=2.47%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 *28800 *38400 
    #error BRG-1 110 300 1200 2400 *4800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 *28800 *38400 
  #endif
#elif   FOSC     ==           4433 // Fosc =   4433.619 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           47 //    110 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT           47 //    110 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        64277 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          179 //    299 bps (delta=0.33%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          179 //    299 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65075 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          141 //   1204 bps (delta=0.33%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          237 //   1215 bps (delta=1.25%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65421 //   1204 bps (delta=0.33%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          227 //   2388 bps (delta=0.50%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //   2309 bps (delta=3.79%)
    #define BRG2_INIT        65478 //   2388 bps (delta=0.50%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          227 //   4777 bps (delta=0.47%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //   4618 bps (delta=3.79%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65507 //   4777 bps (delta=0.47%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          249 //   9896 bps (delta=3.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //   9236 bps (delta=3.79%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65522 //   9896 bps (delta=3.08%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          249 //  19792 bps (delta=3.08%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 //  19792 bps (delta=3.08%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          251 //  27710 bps (delta=3.78%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65531 //  27710 bps (delta=3.78%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          249 //  39585 bps (delta=3.08%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65529 //  39585 bps (delta=3.08%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          251 //  55420 bps (delta=3.78%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65531 //  55420 bps (delta=3.78%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 *38400 *57600 
    #error BRG-1 110 300 1200 2400 4800 *9600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 *38400 *57600 
  #endif
#elif   FOSC     ==           4915 // Fosc =   4915.200 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          140 //    110 bps (delta=0.00%)
    #define BRG1_INIT          140 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64140 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT            0 //    300 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          171 //    301 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65024 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          192 //   1200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          235 //   1219 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65408 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          224 //   2400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   2327 bps (delta=3.04%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65472 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          240 //   4800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   4654 bps (delta=3.04%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65504 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          248 //   9600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          252 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          245 //  27927 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 //  27927 bps (delta=3.03%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          254 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  38400 bps (delta=0.00%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 *28800 38400 
    #error BRG-1 110 300 1200 2400 *4800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 *28800 38400 
  #endif
#elif   FOSC     ==           5000 // Fosc =   5000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          138 //    110 bps (delta=0.00%)
    #define BRG1_INIT          138 //    110 bps (delta=0.00%)
    #define BRG2_INIT        64116 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          169 //    299 bps (delta=0.33%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          169 //    299 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65016 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          191 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   1183 bps (delta=1.41%)
    #define BRG2_INIT        65406 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          191 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   2367 bps (delta=1.37%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65471 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          223 //   4734 bps (delta=1.37%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   4734 bps (delta=1.37%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65503 //   4734 bps (delta=1.37%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          248 //   9765 bps (delta=1.71%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //   9765 bps (delta=1.71%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          252 //  19531 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  19531 bps (delta=1.72%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          245 //  28409 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 //  28409 bps (delta=1.35%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          254 //  39062 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  39062 bps (delta=1.72%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 *28800 38400 
    #error BRG-1 110 300 1200 2400 *4800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 *28800 38400 
  #endif
#elif   FOSC     ==           6000 // Fosc =   6000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          114 //    110 bps (delta=0.00%)
    #define BRG1_INIT          114 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63832 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          204 //    300 bps (delta=0.00%)
    #define BRG1_INIT          204 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64911 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          243 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          243 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        65380 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          217 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65497 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          246 //   9375 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65516 //   9375 bps (delta=2.34%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          251 //  18750 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65526 //  18750 bps (delta=2.34%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          243 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 //  28846 bps (delta=0.15%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          251 //  37500 bps (delta=2.34%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65531 //  37500 bps (delta=2.34%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 *28800 38400 
    #error BRG-1 110 300 1200 2400 *4800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 *28800 38400 
  #endif
#elif   FOSC     ==           6553 // Fosc =   6553.600 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT          101 //    110 bps (delta=0.00%)
    #define BRG1_INIT          101 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63675 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          199 //    299 bps (delta=0.33%)
    #define BRG1_INIT          199 //    299 bps (delta=0.33%)
    #define BRG2_INIT        64854 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT           85 //   1197 bps (delta=0.25%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          242 //   1219 bps (delta=1.58%)
    #define BRG2_INIT        65365 //   1197 bps (delta=0.25%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          171 //   2409 bps (delta=0.37%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   2438 bps (delta=1.58%)
    #define BRG2_INIT        65451 //   2409 bps (delta=0.37%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          213 //   4762 bps (delta=0.79%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   4876 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65493 //   4762 bps (delta=0.79%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          235 //   9752 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   9752 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65515 //   9752 bps (delta=1.58%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          245 //  18618 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 //  18618 bps (delta=3.03%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          249 //  29257 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 //  29257 bps (delta=1.58%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          245 //  37236 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 //  37236 bps (delta=3.03%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          249 //  58514 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65529 //  58514 bps (delta=1.58%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 *38400 *57600 
    #error BRG-1 110 300 1200 2400 4800 *9600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 *38400 *57600 
  #endif
#elif   FOSC     ==           7159 // Fosc =   7159.090 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           87 //    110 bps (delta=0.00%)
    #define BRG1_INIT           87 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63503 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          194 //    300 bps (delta=0.00%)
    #define BRG1_INIT          194 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64791 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          225 //   1202 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          225 //   1202 bps (delta=0.16%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65350 //   1202 bps (delta=0.16%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          163 //   2405 bps (delta=0.20%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          248 //   2330 bps (delta=2.91%)
    #define BRG2_INIT        65443 //   2405 bps (delta=0.20%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          209 //   4760 bps (delta=0.83%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          252 //   4660 bps (delta=2.91%)
    #define BRG2_INIT        65489 //   4760 bps (delta=0.83%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          233 //   9727 bps (delta=1.32%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          254 //   9321 bps (delta=2.90%)
    #define BRG2_INIT        65513 //   9727 bps (delta=1.32%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          255 //  18643 bps (delta=2.90%)
    #define BRG1_INIT          255 //  18643 bps (delta=2.90%)
    #define BRG2_INIT        65524 //  18643 bps (delta=2.90%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          252 //  27965 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  27965 bps (delta=2.89%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          255 //  37286 bps (delta=2.90%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //  37286 bps (delta=2.90%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //  37286 bps (delta=2.90%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          254 //  55930 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  55930 bps (delta=2.89%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 111860 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 111860 bps (delta=2.89%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 223721 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 223721 bps (delta=2.89%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 447443 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 447443 bps (delta=2.89%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 *460800 
    #error BRG-1 110 300 1200 2400 4800 9600 19200 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 *460800 
  #endif
#elif   FOSC     ==           7372 // Fosc =   7372.800 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           82 //    110 bps (delta=0.00%)
    #define BRG1_INIT           82 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63442 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          192 //    300 bps (delta=0.00%)
    #define BRG1_INIT          192 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64768 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          240 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          240 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        65344 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          248 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          248 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65440 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          252 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          252 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65488 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          254 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          254 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65512 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          255 //  19200 bps (delta=0.00%)
    #define BRG1_INIT          255 //  19200 bps (delta=0.00%)
    #define BRG2_INIT        65524 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          252 //  28800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          255 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //  38400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          254 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 230400 bps (delta=0.00%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 460800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 460800 bps (delta=0.00%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 *460800 
    #error BRG-1 110 300 1200 2400 4800 9600 19200 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 *460800 
  #endif
#elif   FOSC     ==           8000 // Fosc =   8000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           67 //    110 bps (delta=0.00%)
    #define BRG1_INIT           67 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63264 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          187 //    301 bps (delta=0.33%)
    #define BRG1_INIT          187 //    301 bps (delta=0.33%)
    #define BRG2_INIT        64703 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          152 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          221 //   1190 bps (delta=0.83%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65328 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          204 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //   2450 bps (delta=2.08%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65432 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          230 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   4629 bps (delta=3.56%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   9259 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          247 //  27777 bps (delta=3.55%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  27777 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  27777 bps (delta=3.55%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          243 //  38461 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 //  38461 bps (delta=0.15%)
    #define BRG2_REQUIRE_X2_MODE
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          247 //  55555 bps (delta=3.55%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  55555 bps (delta=3.55%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 *38400 *57600 
    #error BRG-1 110 300 1200 2400 4800 *9600 *28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 *38400 *57600 
  #endif
#elif   FOSC     ==           8388 // Fosc =   8388.608 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           58 //    110 bps (delta=0.00%)
    #define BRG1_INIT           58 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63153 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          183 //    299 bps (delta=0.33%)
    #define BRG1_INIT          183 //    299 bps (delta=0.33%)
    #define BRG2_INIT        64663 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          147 //   1202 bps (delta=0.16%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          238 //   1213 bps (delta=1.08%)
    #define BRG2_INIT        65318 //   1202 bps (delta=0.16%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          147 //   2404 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   2427 bps (delta=1.12%)
    #define BRG2_INIT        65427 //   2404 bps (delta=0.16%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          201 //   4766 bps (delta=0.70%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   4854 bps (delta=1.12%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65481 //   4766 bps (delta=0.70%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          229 //   9709 bps (delta=1.13%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   9709 bps (delta=1.13%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65509 //   9709 bps (delta=1.13%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          249 //  18724 bps (delta=2.47%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65522 //  18724 bps (delta=2.47%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          247 //  29127 bps (delta=1.13%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  29127 bps (delta=1.13%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  29127 bps (delta=1.13%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          249 //  37449 bps (delta=2.47%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 //  37449 bps (delta=2.47%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          247 //  58254 bps (delta=1.13%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  58254 bps (delta=1.13%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
    #error BRG-1 110 300 1200 2400 4800 *9600 *28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
  #endif
#elif   FOSC     ==           8867 // Fosc =   8867.238 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           47 //    110 bps (delta=0.00%)
    #define BRG1_INIT           47 //    110 bps (delta=0.00%)
    #define BRG2_INIT        63017 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          179 //    299 bps (delta=0.33%)
    #define BRG1_INIT          179 //    299 bps (delta=0.33%)
    #define BRG2_INIT        64613 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT           25 //   1199 bps (delta=0.08%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          237 //   1215 bps (delta=1.25%)
    #define BRG2_INIT        65305 //   1199 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          141 //   2409 bps (delta=0.37%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          237 //   2430 bps (delta=1.25%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65421 //   2409 bps (delta=0.37%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          227 //   4777 bps (delta=0.47%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //   4618 bps (delta=3.79%)
    #define BRG2_INIT        65478 //   4777 bps (delta=0.47%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          227 //   9555 bps (delta=0.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //   9236 bps (delta=3.79%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65507 //   9555 bps (delta=0.46%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          249 //  19792 bps (delta=3.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //  18473 bps (delta=3.78%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65522 //  19792 bps (delta=3.08%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          251 //  27710 bps (delta=3.78%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65526 //  27710 bps (delta=3.78%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          249 //  39585 bps (delta=3.08%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 //  39585 bps (delta=3.08%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          251 //  55420 bps (delta=3.78%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65531 //  55420 bps (delta=3.78%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          251 // 110840 bps (delta=3.78%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65531 // 110840 bps (delta=3.78%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
    #error BRG-1 110 300 1200 2400 4800 9600 *19200 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
  #endif
#elif   FOSC     ==           9830 // Fosc =   9830.400 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           24 //    110 bps (delta=0.00%)
    #define BRG1_INIT           24 //    110 bps (delta=0.00%)
    #define BRG2_INIT        62744 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          171 //    301 bps (delta=0.33%)
    #define BRG1_INIT          171 //    301 bps (delta=0.33%)
    #define BRG2_INIT        64512 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          128 //   1200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //   1190 bps (delta=0.83%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65280 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          192 //   2400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          235 //   2438 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65408 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          224 //   4800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   4654 bps (delta=3.04%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65472 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          240 //   9600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   9309 bps (delta=3.03%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65504 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          248 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          245 //  27927 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 //  27927 bps (delta=3.03%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          252 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          245 //  55854 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 //  55854 bps (delta=3.03%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
    #error BRG-1 110 300 1200 2400 4800 *9600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
  #endif
#elif   FOSC     ==          10000 // Fosc =  10000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG0_INIT           20 //    110 bps (delta=0.00%)
    #define BRG1_INIT           20 //    110 bps (delta=0.00%)
    #define BRG2_INIT        62696 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          169 //    299 bps (delta=0.33%)
    #define BRG1_INIT          169 //    299 bps (delta=0.33%)
    #define BRG2_INIT        64495 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          126 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //   1211 bps (delta=0.91%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65276 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          191 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   2367 bps (delta=1.37%)
    #define BRG2_INIT        65406 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          191 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   4734 bps (delta=1.37%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65471 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          223 //   9469 bps (delta=1.36%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   9469 bps (delta=1.36%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65503 //   9469 bps (delta=1.36%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          248 //  19531 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  19531 bps (delta=1.72%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          245 //  28409 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 //  28409 bps (delta=1.35%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          252 //  39062 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  39062 bps (delta=1.72%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          245 //  56818 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 //  56818 bps (delta=1.35%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
    #error BRG-1 110 300 1200 2400 4800 *9600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
  #endif
#elif   FOSC     ==          11059 // Fosc =  11059.200 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        62395 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          160 //    300 bps (delta=0.00%)
    #define BRG1_INIT          160 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64384 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          232 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          232 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        65248 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          244 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          244 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65392 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          250 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          250 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65464 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          253 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          253 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65500 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          253 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          253 //  19200 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65518 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          255 //  28800 bps (delta=0.00%)
    #define BRG1_INIT          255 //  28800 bps (delta=0.00%)
    #define BRG2_INIT        65524 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          247 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  38400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          255 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 //  57600 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          253 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          253 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 // 230400 bps (delta=0.00%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-1 300 1200 2400 4800 9600 19200 28800 *38400 57600 *115200 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
  #endif
#elif   FOSC     ==          12000 // Fosc =  12000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        62127 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          152 //    300 bps (delta=0.00%)
    #define BRG1_INIT          152 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64286 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          230 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          230 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        65224 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG1_INIT          243 //   2403 bps (delta=0.12%)
    #define BRG2_INIT        65380 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          217 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65497 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          246 //  18750 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65516 //  18750 bps (delta=2.34%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          243 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //  28846 bps (delta=0.15%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          251 //  37500 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65526 //  37500 bps (delta=2.34%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          243 //  57692 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 //  57692 bps (delta=0.15%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 *57600 
    #error BRG-1 300 1200 2400 4800 *9600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 *57600 
  #endif
#elif   FOSC     ==          14318 // Fosc =  14318.100 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        61469 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          132 //    300 bps (delta=0.00%)
    #define BRG1_INIT          132 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64045 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          225 //   1202 bps (delta=0.16%)
    #define BRG1_INIT          225 //   1202 bps (delta=0.16%)
    #define BRG2_INIT        65163 //   1199 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          225 //   2405 bps (delta=0.20%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          225 //   2405 bps (delta=0.20%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65350 //   2405 bps (delta=0.20%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          163 //   4811 bps (delta=0.22%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          248 //   4660 bps (delta=2.91%)
    #define BRG2_INIT        65443 //   4811 bps (delta=0.22%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          209 //   9520 bps (delta=0.83%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          252 //   9321 bps (delta=2.90%)
    #define BRG2_INIT        65489 //   9520 bps (delta=0.83%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          233 //  19453 bps (delta=1.31%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          254 //  18643 bps (delta=2.90%)
    #define BRG2_INIT        65513 //  19453 bps (delta=1.31%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          248 //  27965 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //  29829 bps (delta=3.57%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65520 //  27965 bps (delta=2.89%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          255 //  37286 bps (delta=2.90%)
    #define BRG1_INIT          255 //  37286 bps (delta=2.90%)
    #define BRG2_INIT        65524 //  37286 bps (delta=2.90%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          252 //  55930 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  55930 bps (delta=2.89%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          254 // 111860 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 // 111860 bps (delta=2.89%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 223720 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 223720 bps (delta=2.89%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 447440 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 447440 bps (delta=2.89%)
  #elif BAUDRATE ==         921600 // 921600 bps Serial Speed
    #define BRG0_INIT          255 // 894881 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 894881 bps (delta=2.89%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 *921600 
    #error BRG-1 300 1200 2400 4800 9600 19200 *28800 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 *921600 
  #endif
#elif   FOSC     ==          14745 // Fosc =  14745.600 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        61347 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          128 //    300 bps (delta=0.00%)
    #define BRG1_INIT          128 //    300 bps (delta=0.00%)
    #define BRG2_INIT        64000 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          224 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          224 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        65152 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          240 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          240 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65344 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          248 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          248 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65440 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          252 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          252 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65488 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          254 //  19200 bps (delta=0.00%)
    #define BRG1_INIT          254 //  19200 bps (delta=0.00%)
    #define BRG2_INIT        65512 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          248 //  28800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          255 //  38400 bps (delta=0.00%)
    #define BRG1_INIT          255 //  38400 bps (delta=0.00%)
    #define BRG2_INIT        65524 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          252 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          254 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 230400 bps (delta=0.00%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 460800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 460800 bps (delta=0.00%)
  #elif BAUDRATE ==         921600 // 921600 bps Serial Speed
    #define BRG0_INIT          255 // 921600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65535 // 921600 bps (delta=0.00%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 *921600 
    #error BRG-1 300 1200 2400 4800 9600 19200 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 *921600 
  #endif
#elif   FOSC     ==          16000 // Fosc =  16000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        60991 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT          118 //    301 bps (delta=0.33%)
    #define BRG1_INIT          118 //    301 bps (delta=0.33%)
    #define BRG2_INIT        63870 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT           48 //   1201 bps (delta=0.08%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          187 //   1207 bps (delta=0.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65120 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          152 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          221 //   2380 bps (delta=0.83%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65328 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          204 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //   4901 bps (delta=2.10%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65432 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          230 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //   9259 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  18518 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          239 //  29411 bps (delta=2.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  27777 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65519 //  29411 bps (delta=2.12%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          243 //  38461 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //  38461 bps (delta=0.15%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          247 //  55555 bps (delta=3.55%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  55555 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 //  55555 bps (delta=3.55%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          247 // 111111 bps (delta=3.54%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65527 // 111111 bps (delta=3.54%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
    #error BRG-1 300 1200 2400 4800 9600 *19200 28800 *57600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
  #endif
#elif   FOSC     ==          18432 // Fosc =  18432.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        60300 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           96 //    300 bps (delta=0.00%)
    #define BRG1_INIT           96 //    300 bps (delta=0.00%)
    #define BRG2_INIT        63616 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          216 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          216 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        65056 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          236 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          236 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65296 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          246 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          246 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65416 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          251 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          251 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65476 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          251 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          251 //  19200 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65506 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          246 //  28800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  27428 bps (delta=4.76%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65516 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          241 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //  38400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65521 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          251 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65526 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          251 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65531 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          251 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65531 // 230400 bps (delta=0.00%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-1 300 1200 2400 4800 9600 19200 *28800 *38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
  #endif
#elif   FOSC     ==          19660 // Fosc =  19660.800 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        59951 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           86 //    301 bps (delta=0.33%)
    #define BRG1_INIT           86 //    301 bps (delta=0.33%)
    #define BRG2_INIT        63488 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT            0 //   1200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          171 //   1204 bps (delta=0.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65024 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          128 //   2400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //   2381 bps (delta=0.79%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65280 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          192 //   4800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          235 //   4876 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65408 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          224 //   9600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   9309 bps (delta=3.03%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65472 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          240 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //  18618 bps (delta=3.03%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65504 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          235 //  29257 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  29257 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65515 //  29257 bps (delta=1.58%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          248 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          245 //  55854 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 //  55854 bps (delta=3.03%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          245 // 111709 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 // 111709 bps (delta=3.03%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
    #error BRG-1 300 1200 2400 4800 9600 *19200 *28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
  #endif
#elif   FOSC     ==          20000 // Fosc =  20000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        59855 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           83 //    301 bps (delta=0.33%)
    #define BRG1_INIT           83 //    301 bps (delta=0.33%)
    #define BRG2_INIT        63453 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          169 //   1197 bps (delta=0.25%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          169 //   1197 bps (delta=0.25%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65016 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          126 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //   2422 bps (delta=0.91%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65276 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          191 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   4734 bps (delta=1.37%)
    #define BRG2_INIT        65406 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          191 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   9469 bps (delta=1.36%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65471 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          223 //  18939 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //  18939 bps (delta=1.35%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65503 //  18939 bps (delta=1.35%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          245 //  28409 bps (delta=1.35%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  29761 bps (delta=3.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65514 //  28409 bps (delta=1.35%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          248 //  39062 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  39062 bps (delta=1.72%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          245 //  56818 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 //  56818 bps (delta=1.35%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          245 // 113636 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65525 // 113636 bps (delta=1.35%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
    #error BRG-1 300 1200 2400 4800 9600 *19200 *28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
  #endif
#elif   FOSC     ==          22118 // Fosc =  22118.400 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        59253 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           64 //    300 bps (delta=0.00%)
    #define BRG1_INIT           64 //    300 bps (delta=0.00%)
    #define BRG2_INIT        63232 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          208 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          208 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        64960 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          232 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          232 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65248 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          244 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          244 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65392 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          250 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          250 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65464 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          253 //  19200 bps (delta=0.00%)
    #define BRG1_INIT          253 //  19200 bps (delta=0.00%)
    #define BRG2_INIT        65500 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          254 //  28800 bps (delta=0.00%)
    #define BRG1_INIT          254 //  28800 bps (delta=0.00%)
    #define BRG2_INIT        65512 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          253 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          253 //  38400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65518 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          255 //  57600 bps (delta=0.00%)
    #define BRG1_INIT          255 //  57600 bps (delta=0.00%)
    #define BRG2_INIT        65524 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          253 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          255 // 230400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 // 230400 bps (delta=0.00%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          253 // 460800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65533 // 460800 bps (delta=0.00%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 *460800 
    #error BRG-1 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 *460800 
  #endif
#elif   FOSC     ==          24000 // Fosc =  24000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        58718 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           48 //    300 bps (delta=0.00%)
    #define BRG1_INIT           48 //    300 bps (delta=0.00%)
    #define BRG2_INIT        63036 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          204 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          204 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        64911 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          230 //   2403 bps (delta=0.12%)
    #define BRG1_INIT          230 //   2403 bps (delta=0.12%)
    #define BRG2_INIT        65224 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG1_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG2_INIT        65380 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          217 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65497 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          243 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  27777 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //  28846 bps (delta=0.15%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          246 //  37500 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65516 //  37500 bps (delta=2.34%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          243 //  57692 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //  57692 bps (delta=0.15%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          243 // 115384 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 // 115384 bps (delta=0.15%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
    #error BRG-1 300 1200 2400 4800 9600 *19200 *28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
  #endif
#elif   FOSC     ==          24000 // Fosc =  24000.140 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        58718 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           48 //    300 bps (delta=0.00%)
    #define BRG1_INIT           48 //    300 bps (delta=0.00%)
    #define BRG2_INIT        63036 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          204 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          204 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        64911 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          230 //   2403 bps (delta=0.12%)
    #define BRG1_INIT          230 //   2403 bps (delta=0.12%)
    #define BRG2_INIT        65224 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG1_INIT          243 //   4807 bps (delta=0.14%)
    #define BRG2_INIT        65380 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          217 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65497 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          243 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  27777 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65510 //  28846 bps (delta=0.15%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          246 //  37500 bps (delta=2.34%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65516 //  37500 bps (delta=2.34%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          243 //  57692 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 //  57692 bps (delta=0.15%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          243 // 115385 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65523 // 115385 bps (delta=0.16%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
    #error BRG-1 300 1200 2400 4800 9600 *19200 *28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 *115200 
  #endif
#elif   FOSC     ==          25000 // Fosc =  25000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        58434 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT           39 //    300 bps (delta=0.00%)
    #define BRG1_INIT           39 //    300 bps (delta=0.00%)
    #define BRG2_INIT        62932 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          202 //   1205 bps (delta=0.41%)
    #define BRG1_INIT          202 //   1205 bps (delta=0.41%)
    #define BRG2_INIT        64885 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT           93 //   2396 bps (delta=0.16%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          229 //   2411 bps (delta=0.45%)
    #define BRG2_INIT        65211 //   2403 bps (delta=0.12%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT           93 //   4792 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          229 //   4822 bps (delta=0.45%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65373 //   4792 bps (delta=0.16%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          175 //   9645 bps (delta=0.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //   9300 bps (delta=3.12%)
    #define BRG2_INIT        65455 //   9645 bps (delta=0.46%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          215 //  19054 bps (delta=0.76%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  18601 bps (delta=3.11%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65495 //  19054 bps (delta=0.76%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          229 //  28935 bps (delta=0.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  28935 bps (delta=0.46%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65509 //  28935 bps (delta=0.46%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          246 //  39062 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  37202 bps (delta=3.11%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG1_REQUIRE_X2_MODE
    #define BRG2_INIT        65516 //  39062 bps (delta=1.72%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          249 //  55803 bps (delta=3.11%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65522 //  55803 bps (delta=3.11%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          249 // 111607 bps (delta=3.11%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 // 111607 bps (delta=3.11%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          249 // 223214 bps (delta=3.11%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG0_REQUIRE_X2_MODE
    #define BRG2_INIT        65529 // 223214 bps (delta=3.11%)
    #define BRG2_REQUIRE_X2_MODE
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
    #error BRG-1 300 1200 2400 4800 9600 19200 *28800 *38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 *230400 
  #endif
#elif   FOSC     ==          28636 // Fosc =  28636.200 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        57401 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT            8 //    300 bps (delta=0.00%)
    #define BRG1_INIT            8 //    300 bps (delta=0.00%)
    #define BRG2_INIT        62554 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          194 //   1202 bps (delta=0.16%)
    #define BRG1_INIT          194 //   1202 bps (delta=0.16%)
    #define BRG2_INIT        64791 //   1201 bps (delta=0.08%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          225 //   2405 bps (delta=0.20%)
    #define BRG1_INIT          225 //   2405 bps (delta=0.20%)
    #define BRG2_INIT        65163 //   2399 bps (delta=0.04%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          225 //   4811 bps (delta=0.22%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          225 //   4811 bps (delta=0.22%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65350 //   4811 bps (delta=0.22%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          163 //   9622 bps (delta=0.22%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          248 //   9321 bps (delta=2.90%)
    #define BRG2_INIT        65443 //   9622 bps (delta=0.22%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          209 //  19040 bps (delta=0.83%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          252 //  18643 bps (delta=2.90%)
    #define BRG2_INIT        65489 //  19040 bps (delta=0.83%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          225 //  28867 bps (delta=0.23%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          251 //  29829 bps (delta=3.57%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65505 //  28867 bps (delta=0.23%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          233 //  38907 bps (delta=1.32%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          254 //  37286 bps (delta=2.90%)
    #define BRG2_INIT        65513 //  38907 bps (delta=1.32%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          248 //  55930 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  55930 bps (delta=2.89%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          252 // 111860 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 // 111860 bps (delta=2.89%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          254 // 223720 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 // 223720 bps (delta=2.89%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 447440 bps (delta=2.89%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 447440 bps (delta=2.89%)
  #elif BAUDRATE ==         921600 // 921600 bps Serial Speed
    #define BRG0_INIT          255 // 894881 bps (delta=2.89%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 894881 bps (delta=2.89%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 
    #error BRG-1 300 1200 2400 4800 9600 19200 28800 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 
  #endif
#elif   FOSC     ==          29491 // Fosc =  29491.200 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        57158 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG0_INIT            0 //    300 bps (delta=0.00%)
    #define BRG1_INIT            0 //    300 bps (delta=0.00%)
    #define BRG2_INIT        62464 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          192 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          192 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        64768 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          224 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          224 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65152 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          240 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          240 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65344 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          248 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          248 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65440 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          252 //  19200 bps (delta=0.00%)
    #define BRG1_INIT          252 //  19200 bps (delta=0.00%)
    #define BRG2_INIT        65488 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          240 //  28800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65504 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          254 //  38400 bps (delta=0.00%)
    #define BRG1_INIT          254 //  38400 bps (delta=0.00%)
    #define BRG2_INIT        65512 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          248 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          252 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          254 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 // 230400 bps (delta=0.00%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 460800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 460800 bps (delta=0.00%)
  #elif BAUDRATE ==         921600 // 921600 bps Serial Speed
    #define BRG0_INIT          255 // 921600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 921600 bps (delta=0.00%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 
    #error BRG-1 300 1200 2400 4800 9600 19200 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 
  #endif
#elif   FOSC     ==          30875 // Fosc =  30875.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        56765 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        62320 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          189 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          189 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        64732 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          189 //   2400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          189 //   2400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65134 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT           55 //   4800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //   4729 bps (delta=1.47%)
    #define BRG2_INIT        65335 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          206 //   9648 bps (delta=0.50%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //   9459 bps (delta=1.46%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65436 //   9648 bps (delta=0.50%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          231 //  19296 bps (delta=0.50%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          252 //  20100 bps (delta=4.68%)
    #define BRG2_INIT        65486 //  19296 bps (delta=0.50%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          239 //  28377 bps (delta=1.46%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65502 //  28377 bps (delta=1.46%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          231 //  38593 bps (delta=0.50%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          254 //  40201 bps (delta=4.69%)
    #define BRG2_INIT        65511 //  38593 bps (delta=0.50%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          239 //  56755 bps (delta=1.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65519 //  56755 bps (delta=1.46%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          252 // 120605 bps (delta=4.69%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 // 120605 bps (delta=4.69%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          254 // 241210 bps (delta=4.69%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 // 241210 bps (delta=4.69%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          255 // 482421 bps (delta=4.69%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 482421 bps (delta=4.69%)
  #elif BAUDRATE ==         921600 // 921600 bps Serial Speed
    #define BRG0_INIT          255 // 964843 bps (delta=4.69%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 964843 bps (delta=4.69%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 
    #error BRG-1 1200 2400 4800 9600 19200 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 
  #endif
#elif   FOSC     ==          32000 // Fosc =  32000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        56446 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        62203 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          117 //   1199 bps (delta=0.08%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          117 //   1199 bps (delta=0.08%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        64703 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT           48 //   2403 bps (delta=0.12%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          187 //   2415 bps (delta=0.62%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65119 //   2398 bps (delta=0.08%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          152 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          221 //   4761 bps (delta=0.81%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65328 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          204 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          239 //   9803 bps (delta=2.11%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65432 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          230 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  18518 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          221 //  28571 bps (delta=0.79%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  27777 bps (delta=3.55%)
    #define BRG2_INIT        65501 //  28571 bps (delta=0.79%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          243 //  38461 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65510 //  38461 bps (delta=0.15%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          239 //  58823 bps (delta=2.12%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          253 //  55555 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65519 //  58823 bps (delta=2.12%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          247 // 111111 bps (delta=3.54%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65527 // 111111 bps (delta=3.54%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 
    #error BRG-1 1200 2400 4800 9600 19200 28800 57600 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 
  #endif
#elif   FOSC     ==          36864 // Fosc =  36864.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        55064 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        61696 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          176 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          176 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        64576 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          216 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          216 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        65056 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          236 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          236 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65296 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          246 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          246 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65416 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          251 //  19200 bps (delta=0.00%)
    #define BRG1_INIT          251 //  19200 bps (delta=0.00%)
    #define BRG2_INIT        65476 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          236 //  28800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  27428 bps (delta=4.76%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65496 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          251 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          251 //  38400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65506 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          246 //  57600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65516 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          251 // 115200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65526 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          251 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65531 // 230400 bps (delta=0.00%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 
    #error BRG-1 1200 2400 4800 9600 19200 28800 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 
  #endif
#elif   FOSC     ==          39321 // Fosc =  39321.600 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        54366 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        61440 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT           85 //   1197 bps (delta=0.25%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT           85 //   1197 bps (delta=0.25%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        64512 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT            0 //   2400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          171 //   2409 bps (delta=0.37%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65024 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          128 //   4800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //   4762 bps (delta=0.79%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65280 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          192 //   9600 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          235 //   9752 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65408 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          224 //  19200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //  18618 bps (delta=3.03%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65472 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          213 //  28576 bps (delta=0.77%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  29257 bps (delta=1.58%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65493 //  28576 bps (delta=0.77%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          240 //  38400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65504 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          235 //  58514 bps (delta=1.58%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65515 //  58514 bps (delta=1.58%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          245 // 111709 bps (delta=3.03%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 // 111709 bps (delta=3.03%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 
    #error BRG-1 1200 2400 4800 9600 19200 28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 
  #endif
#elif   FOSC     ==          40000 // Fosc =  40000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        54173 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        61370 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          169 //   1197 bps (delta=0.25%)
    #define BRG1_INIT          169 //   1197 bps (delta=0.25%)
    #define BRG2_INIT        64495 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          169 //   2394 bps (delta=0.25%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          169 //   2394 bps (delta=0.25%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65015 //   2399 bps (delta=0.04%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          126 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          213 //   4844 bps (delta=0.91%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65276 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          191 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //   9469 bps (delta=1.36%)
    #define BRG2_INIT        65406 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          191 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //  18939 bps (delta=1.35%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65471 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          213 //  29069 bps (delta=0.93%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  29761 bps (delta=3.33%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65493 //  29069 bps (delta=0.93%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          223 //  37878 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65503 //  37878 bps (delta=1.35%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          245 //  56818 bps (delta=1.35%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65514 //  56818 bps (delta=1.35%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          245 // 113636 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65525 // 113636 bps (delta=1.35%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 
    #error BRG-1 1200 2400 4800 9600 19200 28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 
  #endif
#elif   FOSC     ==          44236 // Fosc =  44236.800 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        52969 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        60928 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          160 //   1200 bps (delta=0.00%)
    #define BRG1_INIT          160 //   1200 bps (delta=0.00%)
    #define BRG2_INIT        64384 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          208 //   2400 bps (delta=0.00%)
    #define BRG1_INIT          208 //   2400 bps (delta=0.00%)
    #define BRG2_INIT        64960 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          232 //   4800 bps (delta=0.00%)
    #define BRG1_INIT          232 //   4800 bps (delta=0.00%)
    #define BRG2_INIT        65248 //   4800 bps (delta=0.00%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          244 //   9600 bps (delta=0.00%)
    #define BRG1_INIT          244 //   9600 bps (delta=0.00%)
    #define BRG2_INIT        65392 //   9600 bps (delta=0.00%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          250 //  19200 bps (delta=0.00%)
    #define BRG1_INIT          250 //  19200 bps (delta=0.00%)
    #define BRG2_INIT        65464 //  19200 bps (delta=0.00%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          252 //  28800 bps (delta=0.00%)
    #define BRG1_INIT          252 //  28800 bps (delta=0.00%)
    #define BRG2_INIT        65488 //  28800 bps (delta=0.00%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          253 //  38400 bps (delta=0.00%)
    #define BRG1_INIT          253 //  38400 bps (delta=0.00%)
    #define BRG2_INIT        65500 //  38400 bps (delta=0.00%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          254 //  57600 bps (delta=0.00%)
    #define BRG1_INIT          254 //  57600 bps (delta=0.00%)
    #define BRG2_INIT        65512 //  57600 bps (delta=0.00%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG1_INIT          255 // 115200 bps (delta=0.00%)
    #define BRG2_INIT        65524 // 115200 bps (delta=0.00%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          255 // 230400 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          255 // 230400 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65530 // 230400 bps (delta=0.00%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          253 // 460800 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65533 // 460800 bps (delta=0.00%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 
    #error BRG-1 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 
  #endif
#elif   FOSC     ==          48000 // Fosc =  48000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        51900 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        60536 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          152 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          152 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        64286 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          204 //   2403 bps (delta=0.12%)
    #define BRG1_INIT          204 //   2403 bps (delta=0.12%)
    #define BRG2_INIT        64911 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          230 //   4807 bps (delta=0.14%)
    #define BRG1_INIT          230 //   4807 bps (delta=0.14%)
    #define BRG2_INIT        65224 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG1_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG2_INIT        65380 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          230 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  27777 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //  28846 bps (delta=0.15%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          217 //  38461 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65497 //  38461 bps (delta=0.15%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          243 //  57692 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65510 //  57692 bps (delta=0.15%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          243 // 115384 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 // 115384 bps (delta=0.15%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 
    #error BRG-1 1200 2400 4800 9600 19200 28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 
  #endif
#elif   FOSC     ==          48000 // Fosc =  48000.280 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        51900 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        60536 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          152 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          152 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        64286 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          204 //   2403 bps (delta=0.12%)
    #define BRG1_INIT          204 //   2403 bps (delta=0.12%)
    #define BRG2_INIT        64911 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          230 //   4807 bps (delta=0.14%)
    #define BRG1_INIT          230 //   4807 bps (delta=0.14%)
    #define BRG2_INIT        65224 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG1_INIT          243 //   9615 bps (delta=0.15%)
    #define BRG2_INIT        65380 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          243 //  19230 bps (delta=0.15%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65458 //  19230 bps (delta=0.15%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          230 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          247 //  27777 bps (delta=3.55%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65484 //  28846 bps (delta=0.15%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          217 //  38461 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65497 //  38461 bps (delta=0.15%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          243 //  57692 bps (delta=0.15%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65510 //  57692 bps (delta=0.15%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          243 // 115385 bps (delta=0.16%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65523 // 115385 bps (delta=0.16%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 
    #error BRG-1 1200 2400 4800 9600 19200 28800 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 
  #endif
#elif   FOSC     ==          50000 // Fosc =  50000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        51332 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        60328 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT           39 //   1200 bps (delta=0.00%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT           39 //   1200 bps (delta=0.00%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        64234 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          202 //   2411 bps (delta=0.45%)
    #define BRG1_INIT          202 //   2411 bps (delta=0.45%)
    #define BRG2_INIT        64885 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT           93 //   4792 bps (delta=0.16%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          229 //   4822 bps (delta=0.45%)
    #define BRG2_INIT        65211 //   4807 bps (delta=0.14%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT           93 //   9585 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          229 //   9645 bps (delta=0.46%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65373 //   9585 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          175 //  19290 bps (delta=0.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  18601 bps (delta=3.11%)
    #define BRG2_INIT        65455 //  19290 bps (delta=0.46%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          247 //  28935 bps (delta=0.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          247 //  28935 bps (delta=0.46%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65482 //  28935 bps (delta=0.46%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          215 //  38109 bps (delta=0.75%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          249 //  37202 bps (delta=3.11%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65495 //  38109 bps (delta=0.75%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          229 //  57870 bps (delta=0.46%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65509 //  57870 bps (delta=0.46%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          249 // 111607 bps (delta=3.11%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65522 // 111607 bps (delta=3.11%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          249 // 223214 bps (delta=3.11%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65529 // 223214 bps (delta=3.11%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 
    #error BRG-1 1200 2400 4800 9600 19200 28800 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 
  #endif
#elif   FOSC     ==          60000 // Fosc =  60000.000 kHz
  #if   BAUDRATE ==            110 //    110 bps Serial Speed
    #define BRG2_INIT        48491 //    110 bps (delta=0.00%)
  #elif BAUDRATE ==            300 //    300 bps Serial Speed
    #define BRG2_INIT        59286 //    300 bps (delta=0.00%)
  #elif BAUDRATE ==           1200 //   1200 bps Serial Speed
    #define BRG0_INIT          126 //   1201 bps (delta=0.08%)
    #define BRG1_INIT          126 //   1201 bps (delta=0.08%)
    #define BRG2_INIT        63974 //   1200 bps (delta=0.00%)
  #elif BAUDRATE ==           2400 //   2400 bps Serial Speed
    #define BRG0_INIT          191 //   2403 bps (delta=0.12%)
    #define BRG1_INIT          191 //   2403 bps (delta=0.12%)
    #define BRG2_INIT        64755 //   2400 bps (delta=0.00%)
  #elif BAUDRATE ==           4800 //   4800 bps Serial Speed
    #define BRG0_INIT          191 //   4807 bps (delta=0.14%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG1_INIT          191 //   4807 bps (delta=0.14%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65145 //   4795 bps (delta=0.10%)
  #elif BAUDRATE ==           9600 //   9600 bps Serial Speed
    #define BRG0_INIT           61 //   9615 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          223 //   9469 bps (delta=1.36%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65341 //   9615 bps (delta=0.15%)
  #elif BAUDRATE ==          19200 //  19200 bps Serial Speed
    #define BRG0_INIT          207 //  19132 bps (delta=0.35%)
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          248 //  19531 bps (delta=1.72%)
    #define BRG2_INIT        65438 //  19132 bps (delta=0.35%)
  #elif BAUDRATE ==          28800 //  28800 bps Serial Speed
    #define BRG0_INIT          191 //  28846 bps (delta=0.15%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          245 //  28409 bps (delta=1.35%)
    #define BRG1_REQUIRE_SMOD1
    #define BRG2_INIT        65471 //  28846 bps (delta=0.15%)
  #elif BAUDRATE ==          38400 //  38400 bps Serial Speed
    #define BRG0_INIT          207 //  38265 bps (delta=0.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG1_INIT          252 //  39062 bps (delta=1.72%)
    #define BRG2_INIT        65487 //  38265 bps (delta=0.35%)
  #elif BAUDRATE ==          57600 //  57600 bps Serial Speed
    #define BRG0_INIT          223 //  56818 bps (delta=1.35%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65503 //  56818 bps (delta=1.35%)
  #elif BAUDRATE ==         115200 // 115200 bps Serial Speed
    #define BRG0_INIT          248 // 117187 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65520 // 117187 bps (delta=1.72%)
  #elif BAUDRATE ==         230400 // 230400 bps Serial Speed
    #define BRG0_INIT          252 // 234375 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65528 // 234375 bps (delta=1.72%)
  #elif BAUDRATE ==         460800 // 460800 bps Serial Speed
    #define BRG0_INIT          254 // 468750 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65532 // 468750 bps (delta=1.72%)
  #elif BAUDRATE ==         921600 // 921600 bps Serial Speed
    #define BRG0_INIT          255 // 937500 bps (delta=1.72%)
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65534 // 937500 bps (delta=1.72%)
  #elif BAUDRATE ==         1843200 // 1843200 bps Serial Speed
    #define BRG0_INIT          255 // 1875000 bps (delta=1.72%)
    #define BRG0_REQUIRE_SMOD1
    #define BRG0_REQUIRE_SPD
    #define BRG2_INIT        65535 // 1875000 bps (delta=1.72%)
  #else
    #error Only these baudrates are available (*=x2 mode only):
    #error BRG-0 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 1843200 
    #error BRG-1 1200 2400 4800 9600 19200 28800 38400 
    #error BRG-2 110 300 1200 2400 4800 9600 19200 28800 38400 57600 115200 230400 460800 921600 1843200 
  #endif
#endif
// ==> End of generator $Id: uart_bdr.h,v 1.5 2003/08/19 12:44:19 njourdan Exp $


#if BDR_GENERATOR == BRG_INTERNAL
  #ifdef BRG0_REQUIRE_X2_MODE
    #ifndef X2_MODE
    #error You must define X2_MODE in config.h for this baudrate config.
    #endif
  #define Uart_conf_x2()            (Set_x2_mode())
  #else
  #define Uart_conf_x2()            (ACC=0) // do nothing
  #endif

  #ifdef BRG0_REQUIRE_SMOD1 // SMOD bit in pwr ctrl reg => x2 baud rate
  #define Uart_conf_smod()          (PCON|=MSK_SMOD1)
  #else
  #define Uart_conf_smod()          (PCON&=~MSK_SMOD1)
  #endif

  #ifdef BRG0_REQUIRE_SPD
  #define Uart_conf_spd()           (BDRCON|=2)
  #else
  #define Uart_conf_spd()           (BDRCON&=~2)
  #endif

#define Uart_set_baudrate(bdr)      (Uart_conf_x2(),\
                                     Uart_conf_smod(),\
                                     Uart_conf_spd(),\
                                     BDRCON|=0x1C,\
                                     BDRCON&=~1, /*not UART mode 0*/\
                                     BRL    =BRG0_INIT) /*Set autoreload value for Internal BRG according to FOSC & BAUDRATE*/


#elif BDR_GENERATOR == BRG_TIMER1
  #ifdef BRG1_REQUIRE_X2_MODE
    #ifndef X2_MODE
    #error You must define X2_MODE in config.h for this baudrate config.
    #endif
  #define Uart_conf_x2()            (Set_timer1_x2_mode(),Set_x2_mode())
  #else
  #define Uart_conf_x2()            (Set_timer1_x1_mode())
  #endif

  #ifdef BRG1_REQUIRE_SMOD1
  #define Uart_conf_smod()          (PCON|=MSK_SMOD1)
  #else
  #define Uart_conf_smod()          (PCON&=~MSK_SMOD1)
  #endif

#define Uart_set_baudrate(bdr)      (Uart_conf_x2(),\
                                     Uart_conf_smod(),\
                                     TMOD&=0xCF, /* Setup timer/counter mode reg, clear M1 & M0 for T1*/\
                                     TMOD|=0x20, /* Set M1 for 8bit autoreload mode */\
                                     TH1  =BRG1_INIT, /* Set autoreload value for T1 according to FOSC & BAUDRATE */\
                                     TR1  =1) /* Start timer 1 */

#elif BDR_GENERATOR == BRG_TIMER2
  #ifdef BRG2_REQUIRE_X2_MODE
    #ifndef X2_MODE
    #error You must define X2_MODE in config.h for this baudrate config.
    #endif
  #define Uart_conf_x2()            (Set_timer2_x2_mode(),Set_x2_mode())
  #else
  #define Uart_conf_x2()            (Set_timer2_x1_mode())
  #endif

#define Uart_set_baudrate(bdr)      (Uart_conf_x2(),\
                                     RCAP2H=(BRG2_INIT>>8), /* Set autoreload value for T2 according to FOSC & BAUDRATE */\
                                     RCAP2L=BRG2_INIT,\
                                     T2CON=0x34, /* Timer2 in Baud rate Generator mode */\
                                     TR2  =1) /* Start timer 2 */

#else
  #error You must define BDR_GENERATOR in config.h
#endif


#endif
