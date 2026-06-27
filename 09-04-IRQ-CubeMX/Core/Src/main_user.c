/************************************
 *
 * File Name:  main_user.c
 * Path:       /09-03-IRQ-2/Core/Src/main_user.c
 * Created on: 01.06.2026
 * Author:     tobi
 *
 ************************************/


#include "main.h"

extern TIM_HandleTypeDef htim3; // Timer3 Handle

void main_user()
{
	// Start Time Base of Timer 3 and Output Compare
	// Mode on Channel 1, both generate an interrupt
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_OC_Start_IT(&htim3, TIM_CHANNEL_1);
    while(1) { }	// Empty loop; all work is done in interrupts
}

// Timer 3 Period Elapsed Callback: Toggle LED0
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// "our" timer
    {
       HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    }
}

// Timer 3 Output Compare Callback: Toggle LED1
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// "our" timer
    {
       if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // "our" channel
       {
         HAL_GPIO_TogglePin(LED_USR1_GPIO_Port, LED_USR1_Pin);
       }
}}
