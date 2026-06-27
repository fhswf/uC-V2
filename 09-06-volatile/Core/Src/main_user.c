/************************************
 *
 * File Name:  main_user.c
 * Path:       /09-03-IRQ-2/Core/Src/main_user.c
 * Created on: 01.06.2026
 * Author:     tobi
 *
 ************************************/


#include "main.h"
#include <stdio.h>

#define VOLATILE_DEMO
#define TIMING_ISSUE_DEMO

extern TIM_HandleTypeDef htim3; // Timer3 Handle

#ifdef VOLATILE_DEMO
volatile uint32_t timer3_count = 0; // variable to count Timer3 interrupts
#else
uint32_t timer3_count = 0; // variable to count Timer3 interrupts
#endif

void main_user()
{
	uint32_t old_timer3_count = 0; // variable to store the last read value of timer3_count

	printf("\r\n===================================\r\n");
	printf("  volatile Demo - Nucleo-F103RB  \r\n");
	printf("===================================\r\n");


    HAL_TIM_Base_Start_IT(&htim3);
    while(1)
    {
#ifdef TIMING_ISSUE_DEMO
    	if (timer3_count != old_timer3_count) {
			printf("*** MISSED IRQs!!! old: %lu  now: %lu\r\n", old_timer3_count, timer3_count);
		}
#endif
    	while(timer3_count==old_timer3_count);
    	old_timer3_count = timer3_count;
    	printf("Timer3 Interrupts: %lu\r\n", timer3_count);
#ifdef TIMING_ISSUE_DEMO
    	/* Simulate a long processing time in the main loop,
    	 * which can cause missed interrupts */
    	if (timer3_count == 5)
    	{
    		HAL_Delay(1500); // Delay longer than the timer interrupt period
    	}
#endif

      }
}

// Timer 3 Period Elapsed Callback: Toggle LED0
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// "our" timer
    {
       HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
       timer3_count++;	// Increment the interrupt count

    }
}
