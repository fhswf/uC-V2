/*
 * main_user.c
 *
 *  Created on: 11.05.2026
 *      Author: Tobias Ellermeyer
 *
 *      TimerBlink
 *      Nucleo-STM32F103RB-Board with shield
 *
 *      LED2 -> TIM3_CH1
 *      LED3 -> TIM3_CH2
 */

#include "main.h"	// Include HAL and GPIO defines

// Handle for Timer3; defined in main.c
extern TIM_HandleTypeDef htim3;


void main_user()
{

	// Just for Debug: LED 0 permanently on
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);

	/*
	 *  TIMER CONFIGURATION FOM STM32CubeMX:
	 *
	 *  PSC=7199 / ARR = 4999
	 *
	 *  f= CK_IN / ((PSC+1)*(ARR+1)) = 72 MHz / (7200 * 5000) = 2 Hz
	 *
	 *  Mode = Toggle --> Led blinks at 1 Hz
	 *
	 */

	// Start OC-Mode in Timer 3 / Channel 1 & 2
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_OC_Start(&htim3, TIM_CHANNEL_2);
	// -> Now LEDs should blink @ 1Hz


	// Infinite loop
	while(1)
	{
		// Do nothing ...
	}
}
