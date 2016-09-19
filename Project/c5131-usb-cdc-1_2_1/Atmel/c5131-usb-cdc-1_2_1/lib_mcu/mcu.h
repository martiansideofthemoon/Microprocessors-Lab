/*H**************************************************************************
* NAME:         mcu.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.6     
*----------------------------------------------------------------------------
* PURPOSE: 
* SFR Description file for standard Atmel C51 products.
*****************************************************************************/
#ifndef MCU_H
#define MCU_H



/*----------------------------------------*/
/* Include file for 8051 SFR Definitions  */
/*----------------------------------------*/

/* C51 CORE */
Sfr (A       , 0xE0);
Sfr (ACC     , 0xE0);
Sfr (B       , 0xF0);
Sfr (PSW     , 0xD0);
Sfr (SP      , 0x81);
Sfr (DPL     , 0x82);
Sfr (DPH     , 0x83);
Sfr16 (DPTR  , 0x82);

Sbit (CY     , PSW   , 7);
Sbit (AC     , PSW   , 6);
Sbit (F0     , PSW   , 5);
Sbit (RS1    , PSW   , 4);
Sbit (RS0    , PSW   , 3);
Sbit (OV     , PSW   , 2);
Sbit (F1     , PSW   , 1);
Sbit (P      , PSW   , 0);

/*  BYTE Register  */
Sfr (P0 , 0x80);        

Sbit (P0_7 , 0x80, 7);
Sbit (P0_6 , 0x80, 6);
Sbit (P0_5 , 0x80, 5);
Sbit (P0_4 , 0x80, 4);
Sbit (P0_3 , 0x80, 3);
Sbit (P0_2 , 0x80, 2);
Sbit (P0_1 , 0x80, 1);
Sbit (P0_0 , 0x80, 0);

Sfr (P1 , 0x90);        

Sbit (P1_7 , 0x90, 7);
Sbit (P1_6 , 0x90, 6);
Sbit (P1_5 , 0x90, 5);
Sbit (P1_4 , 0x90, 4);
Sbit (P1_3 , 0x90, 3);
Sbit (P1_2 , 0x90, 2);
Sbit (P1_1 , 0x90, 1);
Sbit (P1_0 , 0x90, 0);



Sfr (P2 , 0xA0); 
Sbit (P2_7 , 0xA0, 7);
Sbit (P2_6 , 0xA0, 6);
Sbit (P2_5 , 0xA0, 5);
Sbit (P2_4 , 0xA0, 4);
Sbit (P2_3 , 0xA0, 3);
Sbit (P2_2 , 0xA0, 2);
Sbit (P2_1 , 0xA0, 1);
Sbit (P2_0 , 0xA0, 0);

       
Sfr (P3 , 0xB0);        

Sbit (P3_7 , 0xB0, 7);
Sbit (P3_6 , 0xB0, 6);
Sbit (P3_5 , 0xB0, 5);
Sbit (P3_4 , 0xB0, 4);
Sbit (P3_3 , 0xB0, 3);
Sbit (P3_2 , 0xB0, 2);
Sbit (P3_1 , 0xB0, 1);
Sbit (P3_0 , 0xB0, 0);

Sbit (RD   , 0xB0, 7);
Sbit (WR   , 0xB0, 6);
Sbit (T1   , 0xB0, 5);
Sbit (T0   , 0xB0, 4);
Sbit (INT1 , 0xB0, 3);
Sbit (INT0 , 0xB0, 2);
Sbit (TXD  , 0xB0, 1);
Sbit (RXD  , 0xB0, 0);


Sfr (P4 , 0xC0);  /* => PI2 */      

Sbit (P4_7   , P4    , 7);
Sbit (P4_6   , P4    , 6);
Sbit (P4_5   , P4    , 5);
Sbit (P4_4   , P4    , 4);
Sbit (P4_3   , P4    , 3);
Sbit (P4_2   , P4    , 2);
Sbit (P4_1   , P4    , 1);
Sbit (P4_0   , P4    , 0);


Sfr (P5      , 0xD8);

Sbit (P5_3   , P5    , 3);
Sbit (P5_2   , P5    , 2);
Sbit (P5_1   , P5    , 1);
Sbit (P5_0   , P5    , 0);


/* SYSTEM MANAGEMENT */
Sfr (PCON    , 0x87);
Sfr (AUXR    , 0x8E);
Sfr (AUXR1   , 0xA2);


/* PLL & CLOCK */
Sfr (CKCON   , 0x8F);
Sfr (CKCON0  , 0x8F);     
Sfr (CKCON1  , 0xAF);

/*------------------ TIMERS registers ---------------------*/
Sfr (TCON , 0x88);
Sbit (TF1 , 0x88, 7);
Sbit (TR1 , 0x88, 6);
Sbit (TF0 , 0x88, 5);
Sbit (TR0 , 0x88, 4);
Sbit (IE1 , 0x88, 3);
Sbit (IT1 , 0x88, 2);
Sbit (IE0 , 0x88, 1);
Sbit (IT0 , 0x88, 0);
        
Sfr (TMOD , 0x89);      

Sfr  (T2CON , 0xC8);
Sbit (TF2   , 0xC8, 7);
Sbit (EXF2  , 0xC8, 6);
Sbit (RCLK  , 0xC8, 5);
Sbit (TCLK  , 0xC8, 4);
Sbit (EXEN2 , 0xC8, 3);
Sbit (TR2   , 0xC8, 2);
Sbit (C_T2  , 0xC8, 1);
Sbit (CP_RL2, 0xC8, 0);
        
Sfr (T2MOD , 0xC9);     
Sfr (TL0 , 0x8A);       
Sfr (TL1 , 0x8B);       
Sfr (TL2 , 0xCC);       
Sfr (TH0 , 0x8C);       
Sfr (TH1 , 0x8D);       
Sfr (TH2 , 0xCD);       
Sfr (RCAP2L , 0xCA);    
Sfr (RCAP2H , 0xCB);    
Sfr (WDTRST , 0xA6);    
Sfr (WDTPRG , 0xA7);    


/*------------------- UART registers ------------------------*/
Sfr (SCON  , 0x98);      
Sbit (SM0  , 0x98, 7);
Sbit (FE   , 0x98, 7);
Sbit (SM1  , 0x98, 6);
Sbit (SM2  , 0x98, 5);
Sbit (REN  , 0x98, 4);
Sbit (TB8  , 0x98, 3);
Sbit (RB8  , 0x98, 2);
Sbit (TI   , 0x98, 1);
Sbit (RI   , 0x98, 0);

Sfr (SBUF  , 0x99);      
Sfr (SADEN , 0xB9);     
Sfr (SADDR , 0xA9);     

/*-------------------- Internal Baud Rate Generator --------*/
Sfr (BRL   , 0x9A);      
Sfr (BDRCON, 0x9B);      



/*-------------------- IT registers -----------------------*/
Sfr (IEN0  , 0xA8);      
Sfr (IEN1  , 0xB1);      
Sfr (IPH0  , 0xB7);      
Sfr (IPH1  , 0xB3);      
Sfr (IPL0  , 0xB8);      
Sfr (IPL1  , 0xB2);      



/*  IEN0  */
Sbit (EA   , 0xA8, 7);
Sbit (EC   , 0xA8, 6);
Sbit (ET2  , 0xA8, 5);
Sbit (ES   , 0xA8, 4);
Sbit (ET1  , 0xA8, 3);
Sbit (EX1  , 0xA8, 2);
Sbit (ET0  , 0xA8, 1);
Sbit (EX0  , 0xA8, 0);


/*--------------------- PCA registers -----------------------------*/
Sfr (CCON , 0xD8);      
Sfr (CMOD , 0xD9);      
Sfr (CH , 0xF9);        
Sfr (CL , 0xE9);        
Sfr (CCAP0H  , 0xFA);   
Sfr (CCAP0L  , 0xEA);   
Sfr (CCAPM0  , 0xDA);   
Sfr (CCAP1H  , 0xFB);   
Sfr (CCAP1L  , 0xEB);   
Sfr (CCAPM1  , 0xDB);   
Sfr (CCAP2H  , 0xFC);   
Sfr (CCAP2L  , 0xEC);   
Sfr (CCAPM2  , 0xDC);   
Sfr (CCAP3H  , 0xFD);   
Sfr (CCAP3L  , 0xED);   
Sfr (CCAPM3  , 0xDD);   
Sfr (CCAP4H  , 0xFE);   
Sfr (CCAP4L  , 0xEE);   
Sfr (CCAPM4  , 0xDE);   
/* CCON */
Sbit (CF   , 0xD8, 7);
Sbit (CR   , 0xD8, 6);

Sbit (CCF4   , 0xD8, 4);
Sbit (CCF3  , 0xD8, 3);
Sbit (CCF2  , 0xD8, 2);
Sbit (CCF1  , 0xD8, 1);
Sbit (CCF0  , 0xD8, 0);


/*-------------------- TWI registers ------------------------------*/
Sfr ( SSCON , 0x93);
Sfr ( SSSTA , 0x94);
Sfr ( SSDAT , 0x95);
Sfr ( SSADR , 0x96);
/* TWI port */
Sfr ( PI2   , 0xC0);    
Sbit (PI2_1 , 0xC0, 1);
Sbit (PI2_0 , 0xC0, 0);

/*-------------------- OSC control registers ----------------------*/
Sfr ( CKSEL , 0x85 );
Sfr ( OSCCON , 0x86 );
Sfr ( CKRL , 0x97 );

/*-------------------- Keyboard control registers -----------------*/
Sfr ( KBLS , 0x9C );
Sfr ( KBE , 0x9D );
Sfr ( KBF , 0x9E );
/*-------------------- SPI ---------------------- -----------------*/
Sfr ( SPCON, 0xC3 );
Sfr ( SPSTA, 0xC4 );
Sfr ( SPDAT, 0xC5 );

/*------ Misc ----------------------------------------------------*/
Sfr ( FCON,  0xD1 );

#endif
