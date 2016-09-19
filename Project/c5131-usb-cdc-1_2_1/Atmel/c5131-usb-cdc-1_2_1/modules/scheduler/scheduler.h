/*H**************************************************************************
* NAME:         scheduler.h
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.8     
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the scheduler definition and the task function to be
* executed by the scheduler
*
* NOTE:
* SCHEDULER_TICK & FPER are defined in config.h
*****************************************************************************/

#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

/*_____ I N C L U D E S ____________________________________________________*/
#ifdef KEIL
#include <intrins.h>
#define Wait_semaphore(a) while(!_testbit_(a))
#else
#define Wait_semaphore(a) while(!(a)) (a) = FALSE
#endif

/*_____ M A C R O S ________________________________________________________*/

/*----- Scheduler Types -----*/
#define SCHEDULER_CUSTOM      0
#define SCHEDULER_TIMED       1
#define SCHEDULER_TASK        2
#define SCHEDULER_FREE        3

#if 0
/*----- Scheduler Timer -----*/
#define SCH_TIMER0      0
#define SCH_TIMER1      1
#define SCH_TIMER2      2
/*----- Scheduler Configuration -----*/
#define SCH_TIMER       SCH_TIMER0      /* SCH_TIMER0, SCH_TIMER1, SCH_TIMER2 */
/*----- Scheduler Timer Configuration -----*/
#define TIM_ADJUST      (Byte)4         /* to be modified for timing adjustment */
#define TIM_LOW         LOW(65536 - (SCHEDULER_TICK * (FT0_IN / 6)) + TIM_ADJUST)
#define TIM_HIGH        HIGH(65536 - (SCHEDULER_TICK * (FT0_IN / 6)))
#endif

#ifdef Scheduler_time_init
  extern  void Scheduler_time_init   (void);
#endif



#ifdef Scheduler_task_1_init
  extern  void Scheduler_task_1_init (void);
#else
  // if you do not want init at all, do:
  // #define Scheduler_task_1_init scheduler_empty_fct
  #error Scheduler_task_1_init must be defined in congif.h file
#endif
#ifdef Scheduler_task_2_init
  extern  void Scheduler_task_2_init (void);
#endif
#ifdef Scheduler_task_3_init
  extern  void Scheduler_task_3_init (void);
#endif
#ifdef Scheduler_task_4_init
  extern  void Scheduler_task_4_init (void);
#endif
#ifdef Scheduler_task_5_init
  extern  void Scheduler_task_5_init (void);
#endif
#ifdef Scheduler_task_6_init
  extern  void Scheduler_task_6_init (void);
#endif
#ifdef Scheduler_task_7_init
  extern  void Scheduler_task_7_init (void);
#endif
#ifdef Scheduler_task_8_init
  extern  void Scheduler_task_8_init (void);
#endif
#ifdef Scheduler_task_9_init
  extern  void Scheduler_task_9_init (void);
#endif
#ifdef Scheduler_task_10_init
  extern  void Scheduler_task_10_init (void);
#endif
#ifdef Scheduler_task_11_init
  extern  void Scheduler_task_11_init (void);
#endif




#ifdef Scheduler_task_1
  extern  void Scheduler_task_1 (void);
#else
  // if you do not want task at all, do:
  // #define Scheduler_task_1 scheduler_empty_fct
  #error Scheduler_task_1 must be defined in congif.h file
#endif
#ifdef Scheduler_task_2
  extern  void Scheduler_task_2 (void);
#endif
#ifdef Scheduler_task_3
  extern  void Scheduler_task_3 (void);
#endif
#ifdef Scheduler_task_4
  extern  void Scheduler_task_4 (void);
#endif
#ifdef Scheduler_task_5
  extern  void Scheduler_task_5 (void);
#endif
#ifdef Scheduler_task_6
  extern  void Scheduler_task_6 (void);
#endif
#ifdef Scheduler_task_7
  extern  void Scheduler_task_7 (void);
#endif
#ifdef Scheduler_task_8
  extern  void Scheduler_task_8 (void);
#endif
#ifdef Scheduler_task_9
  extern  void Scheduler_task_9 (void);
#endif
#ifdef Scheduler_task_10
  extern  void Scheduler_task_10 (void);
#endif
#ifdef Scheduler_task_11
  extern  void Scheduler_task_11 (void);
#endif

/*_____ D E F I N I T I O N ________________________________________________*/
#if SCHEDULER_TYPE != SCHEDULER_FREE
extern  bit   scheduler_tick_flag;
#endif

#ifdef TOKEN_MODE
extern Uchar token;
#define TOKEN_FREE      0
#endif

/*_____ D E C L A R A T I O N ______________________________________________*/
void scheduler_init         (void);
void scheduler_tasks        (void);
void scheduler              (void);
void scheduler_empty_fct    (void);

#ifndef SCHEDULER_TYPE
  #error You must define SCHEDULER_TYPE in config.h file
#elif SCHEDULER_TYPE == SCHEDULER_FREE
  #define Scheduler_set_tick_flag()
  #define Scheduler_reset_tick_flag()
#elif SCHEDULER_TYPE == SCHEDULER_TIMED
  #define Scheduler_new_schedule()      Wait_semaphore(scheduler_tick_flag)
  #define Scheduler_set_tick_flag()     (scheduler_tick_flag = TRUE)
  #define Scheduler_reset_tick_flag()   (scheduler_tick_flag = FALSE)
#elif SCHEDULER_TYPE == SCHEDULER_TASK
  #define Scheduler_call_next_task()    Wait_semaphore(scheduler_tick_flag)
  #define Scheduler_set_tick_flag()     (scheduler_tick_flag = TRUE)
  #define Scheduler_reset_tick_flag()   (scheduler_tick_flag = FALSE)
#elif SCHEDULER_TYPE == SCHEDULER_CUSTOM
  #error Make sure you have setup macro/fct Scheduler_new_schedule & Scheduler_call_next_task
  #define Scheduler_set_tick_flag()     (scheduler_tick_flag = TRUE)
  #define Scheduler_reset_tick_flag()   (scheduler_tick_flag = FALSE)
#endif

#ifndef Scheduler_call_next_task
  #define Scheduler_call_next_task()
#endif
#ifndef Scheduler_new_schedule
  #define Scheduler_new_schedule()
#endif
#ifndef Scheduler_call_next_init
  #define Scheduler_call_next_init()
#endif

#endif /* _SCHEDULER_H_ */

