/*C**************************************************************************
* NAME:         scheduler.c
*----------------------------------------------------------------------------
* Copyright (c) 2004 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      c5131-usb-cdc-1_2_1      
* REVISION:     1.9     
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the scheduler routines
*
* NOTES:
* Configuration:
*   - SCHEDULER_TYPE in scheduler.h header file
*   - Task & init for at least task number 1 must be defined
*****************************************************************************/

/*_____ I N C L U D E S ____________________________________________________*/
#define _SCHEDULER_C_
#include "config.h"                         /* system definition */
#include "scheduler.h"                      /* scheduler definition */


/*_____ M A C R O S ________________________________________________________*/


/*_____ D E F I N I T I O N ________________________________________________*/
#if SCHEDULER_TYPE != SCHEDULER_FREE
/*V**************************************************************************
* NAME: scheduler_tick_flag
*----------------------------------------------------------------------------
* PURPOSE: 
* When SCHEDULER_TYPE != SCHEDULER_FREE, this flag control task calls.
*****************************************************************************/
  bit   scheduler_tick_flag;
#endif

#ifdef TOKEN_MODE
/*V**************************************************************************
* NAME: token
*----------------------------------------------------------------------------
* PURPOSE: 
* Can be used to avoid that some tasks executes at same time. 
* The tasks check if the token is free before executing. 
* If the token is free, the tasks reserve it at the begin of the execution 
* and release it at the end of the execution to enable next waiting tasks to 
* run.	
*****************************************************************************/
Uchar token;
#endif

/*_____ D E C L A R A T I O N ______________________________________________*/
/*F**************************************************************************
* NAME:     scheduler_init
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE: 
*   Scheduler initialization
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   Task_x_init() and Task_x_fct() are defined in config.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void scheduler_init (void)
{
#ifdef Scheduler_time_init
  Scheduler_time_init(); // start time base
#endif
#ifdef TOKEN_MODE
token=TOKEN_FREE;
#endif
#ifdef Scheduler_task_1_init
  Scheduler_task_1_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_2_init
  Scheduler_task_2_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_3_init
  Scheduler_task_3_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_4_init
  Scheduler_task_4_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_5_init
  Scheduler_task_5_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_6_init
  Scheduler_task_6_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_7_init
  Scheduler_task_7_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_8_init
  Scheduler_task_8_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_9_init
  Scheduler_task_9_init();  
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_10_init
  Scheduler_task_10_init();
  Scheduler_call_next_init();
#endif
#ifdef Scheduler_task_11_init
  Scheduler_task_11_init();
  Scheduler_call_next_init();
#endif
  Scheduler_reset_tick_flag();
}


/*F**************************************************************************
* NAME:     scheduler_tasks
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Task execution scheduler 
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void scheduler_tasks (void)
{
scheduler_empty_fct(); // only to avoid uncalled segment warning if the empty function is not used
#ifdef SCHEDULER_ENABLE_IT
Enable_interrupt(); // 80C51 All IT on
#endif
for(;;)
  {
    Scheduler_new_schedule();
  #ifdef Scheduler_task_1
    Scheduler_task_1();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_2
    Scheduler_task_2();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_3
    Scheduler_task_3();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_4
    Scheduler_task_4();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_5
    Scheduler_task_5();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_6
    Scheduler_task_6();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_7
    Scheduler_task_7();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_8
    Scheduler_task_8();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_9
    Scheduler_task_9();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_10
    Scheduler_task_10();
    Scheduler_call_next_task();
  #endif
  #ifdef Scheduler_task_11
    Scheduler_task_11();
    Scheduler_call_next_task();
  #endif
  }
}


/*F**************************************************************************
* NAME:     scheduler
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
* Simply call this task to init & run the scheduler
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void scheduler (void)
{
scheduler_init();
scheduler_tasks();
}


/*F**************************************************************************
* NAME:    scheduler_empty_fct
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
* This function does nothing 
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void scheduler_empty_fct (void)
{
}


#if 0 // End of file used only by Chejudo to simplify change from old scheduler
#include "lib_mcu\timer\timer_drv.h"        /* timer definition */

extern  data    Byte    gl_cpt_tick;        /* general tick counter */
extern  data    Byte    gl_kbd_tick;        /* keypad tick counter */
extern  data    Byte    gl_mem_tick;        /* memory tick counter */


#if (SCH_TIMER == SCH_TIMER0)
/****************************************************************************
* NAME:     sch_time_init
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Scheduler time base (timer 0) initialization
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   mode 16-bit Timer, Time counter
*   T0_PRIO to be defined in config.h
*   TIM_LOW & TIM_HIGH defined in scheduler.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void sch_time_init (void)
{
  T0_init(T0_NOT_GATED, T0_TIMER, T0_MODE_1);
  T0_set_low(TIM_LOW);
  T0_set_high(TIM_HIGH);
  t0_set_prio(T0_PRIO);                     /* set-up priority */
  T0_enable_int();                          /* enable interrupt */
  T0_start();                               /* start time base */
}

/****************************************************************************
* NAME:     sch_timer_int
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Timer 0 interrupt function
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   IRQ_T0 defined in extsnd1.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
******************************************************************************/
Interrupt (sch_timer_int(void), IRQ_T0) 
{
//  T0_stop();                                /* stop timer */
  T0_set_low(TIM_LOW);                      /* reload timer */ 
  T0_set_high(TIM_HIGH);
//  T0_start();                               /* restart timer */

#if (SCH_TYPE != SCH_FREE)
  sch_tick_flag = TRUE;
#endif
  /* increment task tick counters */
  gl_cpt_tick++;                            /* general timer */
  gl_kbd_tick++;                            /* keyboard timer */
  gl_mem_tick++;                            /* memory timer */
}


#elif (SCH_TIMER == SCH_TIMER1)
/****************************************************************************
* NAME:     sch_time_init
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Scheduler time base (timer 1) initialization
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   mode 16-bit Timer, Time counter
*   T1_PRIO to be defined in config.h
*   TIM_LOW & TIM_HIGH defined in scheduler.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void sch_time_init (void)
{
  T1_init(T1_NOT_GATED, T1_TIMER, T1_MODE_1);
  T1_set_low(TIM_LOW);
  T1_set_high(TIM_HIGH);
  t1_set_prio(T1_PRIO);                     /* set-up priority */
  T1_enable_int();                          /* enable interrupt */
  T1_start();                               /* start time base */
}

/****************************************************************************
* NAME:     sch_timer_int
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Timer 1 interrupt function
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   IRQ_T1 defined in extsnd1.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
Interrupt (sch_timer_int(void), IRQ_T1) 
{
//  T1_stop();                                /* stop timer */
  T1_set_low(TIM_LOW);                      /* reload timer */
  T1_set_high(TIM_HIGH);
//  T1_start();                               /* restart timer */

#if (SCH_TYPE != SCH_FREE)
  sch_tick_flag = TRUE;
#endif

  gl_cpt_tick++;
}


#elif (SCH_TIMER == SCH_TIMER2)
/****************************************************************************
* NAME:     sch_time_init
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Scheduler time base (timer 2) initialization
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   mode 16-bit auto-reload
*   T2_PRIO to be defined in config.h
*   TIM_LOW & TIM_HIGH defined in scheduler.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
*****************************************************************************/
void sch_time_init (void)
{
  T2_init(T2_AUTO_RELOAD, T2_TIMER, T2_NOT_GATED);
  T2_set_low(TIM_LOW);
  T2_set_high(TIM_HIGH);
  t2_set_prio(T2_PRIO);                     /* set-up priority */
  T2_enable_int();                          /* enable interrupt */
  T2_start();                               /* start time base */
}

/****************************************************************************
* NAME:     sch_timer_int
*----------------------------------------------------------------------------
* PARAMS:
*
* return:
*----------------------------------------------------------------------------
* PURPOSE:
*   Timer 2 interrupt function
*----------------------------------------------------------------------------
* EXAMPLE:
*----------------------------------------------------------------------------
* NOTE:
*   IRQ_T2 defined in extsnd1.h
*----------------------------------------------------------------------------
* REQUIREMENTS:
******************************************************************************/
Interrupt (sch_timer_int(void), IRQ_T2) 
{
  T2_clr_ovf;                               /* ack interrupt */

#if (SCH_TYPE != SCH_FREE)
  sch_tick_flag = TRUE;
#endif
  gl_cpt_tick++;
}
#endif

#endif
