/*H**************************************************************************
* NAME:         compiler.h
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* FILE_REV:     1.2.2.1     
*----------------------------------------------------------------------------
* PURPOSE:
* This file redefines dedicated KEIL, RAISONANCE and TASKINKG C51/C251
* keywords in order to ensure that any source file can be processed by
* these compilers.
*****************************************************************************/

#ifndef _COMPILER_H_
#define _COMPILER_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ D E C L A R A T I O N S ____________________________________________*/

typedef unsigned char       Uchar;
typedef float               Float16;

typedef unsigned char       Uint8;
typedef unsigned int        Uint16;
typedef unsigned long int   Uint32;

typedef char                Int8;
typedef int                 Int16;
typedef long int            Int32;

typedef unsigned char       U8 ;
typedef unsigned short      U16;
typedef unsigned long       U32;
typedef char                S8 ;
typedef short               S16;
typedef long                S32;


typedef unsigned char       Bool;
typedef unsigned char       Byte;
typedef unsigned int        Word;
typedef unsigned long int   DWord;

typedef union 
{
  Uint32 l;
  Uint16 w[2];
  Uint8  b[4];
} Union32;

typedef union 
{
  Uint16 w;
  Uint8  b[2];
} Union16;

#  define MSB(u16)        (((U8* )&u16)[0])
#  define LSB(u16)        (((U8* )&u16)[1])
#  define MSW(u32)        (((U16*)&u32)[0])
#  define LSW(u32)        (((U16*)&u32)[1])
#  define MSB0(u32)       (((U8* )&u32)[0]) // MSB of u32
#  define MSB1(u32)       (((U8* )&u32)[1])
#  define MSB2(u32)       (((U8* )&u32)[2])
#  define MSB3(u32)       (((U8* )&u32)[3]) // LSB of u32
#  define LSB0(u32)       MSB3(u32)         // LSB of u32
#  define LSB1(u32)       MSB2(u32)
#  define LSB2(u32)       MSB1(u32)
#  define LSB3(u32)       MSB0(u32)         // MSB of u32



/*_____ M A C R O S ________________________________________________________*/

/* General purpose defines */
#define _ConstType_	code
/* Constants */
#define FALSE   0
#define TRUE    1
#define KO      0
#define OK      1
#define OFF     0
#define ON      1
#define CLR     0
#define SET     1

/* Bit and bytes manipulations */
#define LOW(U16)                ((Uchar)U16)
#define HIGH(U16)               ((Uchar)(U16>>8))	
#define TST_BIT_X(addrx,mask)   (*addrx & mask)
#define SET_BIT_X(addrx,mask)   (*addrx = (*addrx | mask))
#define CLR_BIT_X(addrx,mask)   (*addrx = (*addrx & ~mask))
#define OUT_X(addrx,value)      (*addrx = value)
#define IN_X(addrx)             (*addrx)

/* little endian conversion */
#define LE16(b) (((b & 0xFF) << 8) | ((b & 0xFF00) >> 8))
#define LE32(b) (((b & 0xFF) << 24) | ((b & 0xFF00) << 8) | \
                 ((b & 0xFF0000) >> 8) | ((b & 0xFF000000) >> 24))

/***********************************************************
 SET_SFR_BIT macro 
  parameters 
    sfr_reg : defined value in include file for sfr register 
    bit_pos : defined value B_XX in include file for particular
              bit of sfr register 
    bit_val : CLR / SET 
************************************************************/
#define SET_SFR_BIT(sfr_reg, bit_pos, bit_val) { sfr_reg &= ~(1<<(bit_pos)); sfr_reg |= ((bit_val)<<(bit_pos));}

/***********************************************************
 TST_SFR_BIT macro 
  parameters 
    sfr_reg : defined value in include file for sfr register 
    bit_pos : defined value B_XX in include file for particular
              bit of sfr register 
************************************************************/
#define TST_SFR_BIT(sfr_reg, bit_pos) ((sfr_reg & (1<<(bit_pos)))>>(bit_pos))

#ifdef KEIL             /* KEIL compiler */

#define Reentrant(x)    x reentrant
#define Sfr(x,y)		sfr x = y
#define Sfr16(x,y)	    sfr16 x = y
#define Sbit(x,y,z)	    sbit x = y ^ z
#define Interrupt(x,y)	x interrupt y
#define At(x)			_at_ x

#ifdef __C51__          /* C51 Compiler */
#define far  xdata      /* far is for C251 only */  
#endif

#endif                  /* End of KEIL */


#ifdef RAISONANCE       /* RAISONANCE compiler */

#define Reentrant(x)	x reentrant
#define Sfr(x,y)		sfr x = y
#define Sbit(x,y,z)	    sbit x = y ^ z
#define Interrupt(x,y)	x interrupt y
#define At(x)			_at_ x

#ifdef __C51__          /* C51 Compiler */
#define far  xdata      /* far is for 251 only */
#endif

#endif                  /* End of RAISONANCE */


#ifdef TASKING          /* TASKING compiler */

#include <keil.h>       /* Include Tasking / Keil compatibility header file */ 

#define far 			_far
#define Reentrant(x)	_reentrant x
#define Sfr(x,y)		_sfrbyte x _at(y)
#define Sbit(x,y,z)	    _sfrbit x _atbit(y,z)
#define Interrupt(x,y)	_interrupt(y) x

#endif                  /* End of TASKING */


#endif /* _COMPILER_H_ */

