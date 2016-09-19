/*H**************************************************************************
* NAME:         timer_soft.h         
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.16     
*----------------------------------------------------------------------------
* PURPOSE: 
* Macro definition for soft timers.
* Note that the standard unit for time is the millisecond (ms).
*
* Typical use of:
* Type:  Timer setup:     Accuracy:    Advised Timeout:
* bits_t Min/Advised/Max  Logical/Phy  Std   / required               
* __16s  0ms/32s/65s      1ms / tick   33s   /  > sched_rollover_time
* __16l  0s/2h20/4h40     256ms        2h20  / >> sched_rollover_time 
* __8s   0ms/127ms/255ms  1ms / tick   127ms /  > sched_rollover_time
* __8l   0ms/32s/65s      256ms        33s   /  > sched_rollover_time
*****************************************************************************/
#ifndef TIMER_SOFT_H
#define TIMER_SOFT_H

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/

/*M**************************************************************************
* NAME: set_timerxy
*----------------------------------------------------------------------------
* PARAMS:
* delay: delay in ms before timeout
* return:   value to store in the timer variable (x bits)
*----------------------------------------------------------------------------
* PURPOSE: 
* Set a timer variable.
* x=8 or 16 or nothing for default (number of bits of the variable, 
* default=16)
* y=s for short or l for long or nothing for default (default=short)
*----------------------------------------------------------------------------
* EXAMPLE:
* my_timer=set_timer(TIMER_4_S);  
* my_timer=set_timer16s(4000);
*----------------------------------------------------------------------------
* NOTE: 
* Use (x-1) bits value for a correct usage of soft timers.
* Be careful that scheduler roll over must be shortest than (x-1) ms.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
* The gl_soft_timer_tick must be updated correctly, according crystal & x2 
* mode
*****************************************************************************/
#define set_timer(delay)     set_timer16s(delay) 
#define set_timer8(delay)    set_timer8s(delay) 
#define set_timer8s(delay)   ((Uint8) (delay)+(Uint8) gl_soft_timer_tick) 
#define set_timer8l(delay)   ((Uint8) ((delay)>>8)+(Uint8) (gl_soft_timer_tick>>8)+(Uint8)1) 
#define set_timer16(delay)   set_timer16s(delay) 
#define set_timer16s(delay)  ((Uint16)(delay)+(Uint16)gl_soft_timer_tick) 
#define set_timer16l(delay)  ((Uint16)((delay)>>8)+(Uint16)(gl_soft_timer_tick>>8)+1) 


/* {for langdoc}*/


/*M**************************************************************************
* NAME: timeoutxy
*----------------------------------------------------------------------------
* PARAMS:
* timer:    variable used for timer, type xy
* delay:    delay in ms
* return:   TRUE if timeout, FALSE anyelse.
*----------------------------------------------------------------------------
* PURPOSE:
* Test if a timeout occurs on a timer.
* x=8 or 16 or nothing for default (number of bits of the variable, default=16)
* y=s for short or l for long or nothing for default (default=short)
*----------------------------------------------------------------------------
* EXAMPLE:
* if (timeout(my_timer,TIMER_1_S)) // action 
* else // wait
*----------------------------------------------------------------------------
* NOTE: 
* Use (x-1) bits value for a correct usage of soft timers.
* Be careful that scheduler roll over must be shortest than 2^(x-1) ms.
*
* This function is more accurate than std_timeoutxy but the speed is lower.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
* The gl_soft_timer_tick must be updated correctly, according crystal & x2 mode
*****************************************************************************/
#define timeout(timer,delay)    timeout16s(timer,delay)
#define timeout8(timer,delay)   timeout8s(timer,delay) 
#define timeout8s(timer,delay)  ((((Uint8)(timer)-(Uint8)gl_soft_timer_tick)<=(Uint8)(delay))?FALSE:TRUE)
#define timeout8l(timer,delay)  ((((Uint8)(timer)-(Uint8)(gl_soft_timer_tick>>8))<=(Uint8)((delay)>>8))?FALSE:TRUE)
#define timeout16(timer,delay)  timeout16s(timer,delay)
#define timeout16s(timer,delay) ((((Uint16)(timer)-(Uint16)gl_soft_timer_tick)<=(Uint16)(delay))?FALSE:TRUE)
#define timeout16l(timer,delay) ((((Uint16)(timer)-(Uint16)(gl_soft_timer_tick>>8))<=(Uint16)((delay)>>8))?FALSE:TRUE)

/* {for langdoc}*/


/*M**************************************************************************
* NAME: std_timeoutxy
*----------------------------------------------------------------------------
* PARAMS:
* timer:    variable used for timer, type xy
* return:   TRUE if timeout, FALSE anyelse.
*----------------------------------------------------------------------------
* PURPOSE:
* Test if a timeout occurs on a timer.
* x=8 or 16 or nothing for default (number of bits of the variable, default=16)
* y=s for short or l for long or nothing for default (default=short)
*----------------------------------------------------------------------------
* EXAMPLE:
* if (std_timeout(my_timer)) // action 
* else // wait
*----------------------------------------------------------------------------
* NOTE: 
* Use (x-1) bits value for a correct usage of soft timers.
* Be careful that scheduler roll over must be shortest than 2^(x-1) ms.
*
* This function is less accurate than timeoutxy but the speed is faster.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
* The gl_soft_timer_tick must be updated correctly, according crystal & x2 mode
*****************************************************************************/
#define std_timeout(timer)      std_timeout16s(timer)
#define std_timeout8s(timer)    ((((Uint8)(timer)-(Uint8)gl_soft_timer_tick)<=(Uint8)127)?FALSE:TRUE)
#define std_timeout8(timer)     std_timeout8s(timer) 
#define std_timeout8l(timer)    ((((Uint8)(timer)-(Uint8)(gl_soft_timer_tick>>8))<=(Uint8)127)?FALSE:TRUE)
#define std_timeout16(timer)    std_timeout16s(timer)
#define std_timeout16s(timer)   ((((Uint16)(timer)-(Uint16)gl_soft_timer_tick)<=(Uint16)32767)?FALSE:TRUE)
#define std_timeout16l(timer)   ((((Uint16)(timer)-(Uint16)(gl_soft_timer_tick>>8))<=(Uint16)32767)?FALSE:TRUE)

/* {for langdoc}*/

/*M**************************************************************************
* NAME: reset_timerxy
*----------------------------------------------------------------------------
* PARAMS:
* timer:    timer to reset
* return:   the new value of timer
*----------------------------------------------------------------------------
* PURPOSE:
* Force a timeout on timer.
* x=8 or 16 or nothing for default (number of bits of the variable, default=16)
* y=s for short or l for long or nothing for default (default=short)
*----------------------------------------------------------------------------
* EXAMPLE:
* my_timer=set_timer(TIMER_1_S);
* reset_timer(my_timer);
* if (timeout(my_timer)) ... // Always true due to reset_timer
*----------------------------------------------------------------------------
* NOTE: 
* Use (x-1) bits value for a correct usage of soft timers.
* Be careful that scheduler roll over must be shortest than 2^(x-1) ms.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
* The gl_soft_timer_tick must be updated correctly, according crystal & x2 mode
*****************************************************************************/
#define reset_timer(timer)      reset_timer16s(timer)
#define reset_timer8(timer)     reset_timer8s(timer) 
#define reset_timer8s(timer)    ((timer)=(Uint8)gl_soft_timer_tick-(Uint8)1)
#define reset_timer8l(timer)    ((timer)=(Uint8)(gl_soft_timer_tick>>8)-(Uint8)1)
#define reset_timer16(timer)    reset_timer16s(timer)
#define reset_timer16s(timer)   ((timer)=(Uint16)gl_soft_timer_tick-1)
#define reset_timer16l(timer)   ((timer)=(Uint16)(gl_soft_timer_tick>>8)-1)


/* {for langdoc}*/

/*M**************************************************************************
* NAME: update_timerxy
*----------------------------------------------------------------------------
* PARAMS:
* timer:    variable used for timer, type xy
* delay:    delay in ms
* return:   the new value of timer
*----------------------------------------------------------------------------
* PURPOSE:
* Update a timer,
* when a timeout occurs, to keep accuracy
* when an event occurs, to delay a timeout keeping time past
*
* x=8 or 16 or nothing for default (number of bits of the variable, default=16)
* y=s for short or l for long or nothing for default (default=short)
*----------------------------------------------------------------------------
* EXAMPLE:
* if (timeout(my_timer,TIMER_1_S)) {  // Action
*   update_timer(my_timer,TIMER_1_S); // to keep accuracy on the clock
*   ...
*   }
* else // wait
*----------------------------------------------------------------------------
* NOTE: 
* Use (x-1) bits value for a correct usage of soft timers.
* Be careful that scheduler roll over must be shortest than 2^(x-1) ms.
*
* Do not forget that timer type "s" have a bad accuracy: 256ms/operation on timer.
*----------------------------------------------------------------------------
* REQUIREMENTS: 
* The gl_soft_timer_tick must be updated correctly, according crystal & x2 mode
*****************************************************************************/
#define update_timer(timer,delay)    update_timer16s(timer,delay)
#define update_timer8(timer,delay)   update_timer8s(timer,delay) 
#define update_timer8s(timer,delay)  ((timer)+=(delay))
#define update_timer8l(timer,delay)  ((timer)+=((Uint8)((delay)>>8)+(Uint8)1))
#define update_timer16(timer,delay)  update_timer16s(timer,delay)
#define update_timer16s(timer,delay) ((timer)+=(delay))
#define update_timer16l(timer,delay) ((timer)+=((Uint16)((delay)>>8)+1))

/* {for langdoc}*/

#ifdef I_HAVE_SETUP_SOFT_TIMER_TICK
#define init_soft_timers() (gl_soft_timer_tick=0) 
#endif

/*_____ D E F I N I T I O N S ______________________________________________*/
typedef Uint16          Timer16s;
typedef Uint16          Timer16l;
typedef Uint16          Timer16;
typedef Uint16          Timer;
typedef Uint8           Timer8s;
typedef Uint8           Timer8l;
typedef Uint8           Timer8;


#define TIMER_1_MS      1
#define TIMER_2_MS      2
#define TIMER_3_MS      3
#define TIMER_4_MS      4
#define TIMER_5_MS      5
#define TIMER_10_MS     10
#define TIMER_20_MS     20
#define TIMER_30_MS     30
#define TIMER_40_MS     40
#define TIMER_50_MS     50
#define TIMER_100_MS    100
#define TIMER_200_MS    200
#define TIMER_500_MS    500
#define TIMER_1_S       1000
#define TIMER_2_S       2000
#define TIMER_3_S       3000
#define TIMER_4_S       4000
#define TIMER_5_S       5000
#define TIMER_10_S      10000
#define TIMER_20_S      20000
#define TIMER_30_S      30000
#define TIMER_60_S      60000
#define TIMER_120_S     120000L
#define TIMER_180_S     180000L
#define TIMER_300_S     300000L
#define TIMER_1_MIN     60000
#define TIMER_2_MIN     120000L
#define TIMER_3_MIN     180000L
#define TIMER_5_MIN     300000L


#ifndef I_HAVE_SETUP_SOFT_TIMER_TICK
#ifndef FOSC
#error You must define FOSC in config.h
// FOSC = 22118 => 1843.2 timer inc/ms
// To update software timer each 2 ms: 3,684.3 timer inc for 2ms
// we need a power of 2 for TH0 so 4096 inc => 2^8*2^4 so TH0=1111 0000b=240
// To keep accuracy: 4096 / 1843.2 = 2,222.. ms = 2 + 14564 / 65536
// FOSC = 12000 => 1,000 timer inc/ms ( 2,000 in X2 mode)
// To update software timer each 2 ms: 2,000 timer inc for 2ms
// we need a power of 2 for TH0 so 2000 <=> 2048 inc => 2^8*2^3 so TH0=1111 1000b=248
// To keep accuracy: 2,048 / 1,000 = 2,048 ms = 2/65536*65536 + 3146 / 65536
// INC_MS = 2 ; REMINDER_INC_MS = 3146
// FOSC = 11059 => 921.6 timer inc/ms
// To update software timer each 2 ms: 1,843.2 timer inc for 2ms
// we need a power of 2 for TH0 so 1843 <=> 2048 inc => 2^8*2^3 so TH0=1111 1000b=248
// To keep accuracy: 2,048 / 921.6 = 2,222.. ms = 2 + 14564 / 65536
#elif FOSC == 48000
#define RELOAD_TH0      224    // to optimize CPU load
#define INC_MS          2      // to have something near 2 ms
#define REMINDER_INC_MS 3146   // to keep accuracy, reminder in tick/65536
#elif FOSC == 32000
#define RELOAD_TH0      224    // to optimize CPU load
#define INC_MS          3      // to have something near 2 ms
#define REMINDER_INC_MS 4719  // to keep accuracy, reminder in tick/65536
#elif FOSC == 24000
#define RELOAD_TH0      240    // to optimize CPU load
#define INC_MS          2      // to have something near 2 ms
#define REMINDER_INC_MS 3146   // to keep accuracy, reminder in tick/65536
#elif FOSC == 22118
#define RELOAD_TH0      240    // to optimize CPU load
#define INC_MS          2      // to have something near 2 ms
#define REMINDER_INC_MS 14564  // to keep accuracy, reminder in tick/65536
#elif FOSC == 16000
#define RELOAD_TH0      240    // to optimize CPU load
#define INC_MS          3      // to have something near 2 ms
#define REMINDER_INC_MS 4719  // to keep accuracy, reminder in tick/65536
#elif FOSC == 12000
#define RELOAD_TH0      248    // to optimize CPU load
#define INC_MS          2      // to have something near 2 ms
#define REMINDER_INC_MS 3146   // to keep accuracy, reminder in tick/65536
#elif FOSC == 11059
#define RELOAD_TH0      248    // to optimize CPU load
#define INC_MS          2      // to have something near 2 ms
#define REMINDER_INC_MS 14564  // to keep accuracy, reminder in tick/65536
#elif FOSC == 8000
#define RELOAD_TH0      248    // to optimize CPU load
#define INC_MS          3      // to have something near 2 ms
#define REMINDER_INC_MS 4719  // to keep accuracy, reminder in tick/65536
#else
#define INC_MS          2
#define RELOAD_TH0      reload_TH0()
//#define REMINDER_INC_MS => computed in reload_TH0, #define => variable
#define SOFT_TIMER_CUSTOM_FOSC
#endif
#endif


/*_____ D E C L A R A T I O N S ____________________________________________*/
extern volatile Uint32 data gl_soft_timer_tick;  // number of ms since Reset

void tempo                  (Uint16 delay);
void init_soft_timers       (void);
void timer_soft_update_task (void); 


#endif  /* TIMER_SOFT_H */



