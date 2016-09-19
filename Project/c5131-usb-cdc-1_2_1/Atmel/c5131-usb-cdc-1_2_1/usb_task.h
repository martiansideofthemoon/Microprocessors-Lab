/*H**************************************************************************
* NAME: usb_task.h
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* REVISION:       1.1
*----------------------------------------------------------------------------
* PURPOSE:
* 
*****************************************************************************/

#ifndef _USB_TASK_H_
#define _USB_TASK_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/

#define UT_REQUESTED  0
#define UT_BLANK      1

/*_____ D E F I N I T I O N ________________________________________________*/


/*_____ D E C L A R A T I O N ______________________________________________*/
#define HID_1            89
#define HID_2            90
#define HID_3            91
#define HID_4            92
#define HID_5            93
#define HID_6            94
#define HID_7            95
#define HID_8            96
#define HID_9            97
#define HID_0            98
#define HID_ENTER        88
#define HID_BACKSPACE    42
#define HID_LEFT         80
#define HID_RIGHT        79
#define HID_DIVIDE       84
#define HID_MULTIPLY     85
#define HID_MINUS        86
#define HID_PLUS         87

#define HID_A            4
#define HID_B            5
#define HID_C            6
#define HID_D            7
#define HID_E            8
#define HID_F            9
#define HID_G            10
#define HID_H            11
#define HID_I            12
#define HID_J            13
#define HID_K            14
#define HID_L            15
#define HID_M            16
#define HID_N            17
#define HID_O            18
#define HID_P            19
#define HID_Q            20
#define HID_R            21
#define HID_S            22
#define HID_T            23
#define HID_U            24
#define HID_V            25
#define HID_W            26
#define HID_X            27
#define HID_Y            28
#define HID_Z            29

#define HID_SPACEBAR     44

#define HID_UNDERSCORE   45
#define HID_SLASH        56
#define HID_BACKSLASH    49
#define HID_DOT          55
#define HID_AT           85
#define HID_SB           HID_SPACEBAR
#define HID_MN           HID_MINUS
#define HID_SL           HID_SLASH
#define HID_BS           HID_BACKSLASH


void usb_task_init     (void);
void usb_task          (void);

void usb_lcd_task      (void);
void usb_kbd_task      (void);

void kbd_init          (void);
void kbd_test_hit      (void);

#endif /* _USB_TASK_H_ */
