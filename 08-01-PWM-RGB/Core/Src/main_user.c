/*
 * main_user.c
 *
 *  Created on: 11.05.2026
 *      Author: Tobias Ellermeyer
 *
 *      TimerBlink
 *      Nucleo-STM32F103RB-Board with shield
 *
 *      => Change CCR3
 *      LED2 -> TIM3_CH1
 *      LED3 -> TIM3_CH2
 */

#include "main.h"	// Include HAL and GPIO defines

// Handle for Timer3; defined in main.c
extern TIM_HandleTypeDef htim1;


void main_user()
{

	// Just for Debug: LED 0 permanently on
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);

	/*
	 *  TIMER CONFIGURATION FOM STM32CubeMX:
	 *
	 *  PSC=712 / ARR = 100
	 *
	 *  f_PWM = CK_IN / ((PSC+1)*(ARR+1)) = 72 MHz / (713 * 101) = 999,8 Hz
	 *
	 */

	// start PWM
	HAL_TIM_Base_Start(&htim1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);

    // set a color ...
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 14); 	// blue
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 15); 	// green
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 96); 	// red

	// Infinite loop
	while(1)
	{
	}
}
