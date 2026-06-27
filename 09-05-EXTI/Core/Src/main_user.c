/************************************
 *
 * File Name:  main_user.c
 * Path:       /09-05-EXTI/Core/Src/main_user.c
 * Created on: 01.06.2026
 * Author:     tobi
 *
 ************************************/


#include "main.h"

//#define ENTPRELLEN

void main_user()
{
	// Start Time Base of Timer 3 and Output Compare
	// Mode on Channel 1, both generate an interrupt
    while(1) { }	// Empty loop; all work is done in interrupts
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	 /* Ignoriere Interrupt, wenn er innerhalb von 20 ms zum letzten Interrupt auftritt */

	#ifdef ENTPRELLEN
		static uint32_t last_interrupt_time = 0;
		if ((HAL_GetTick() - last_interrupt_time) < 20) {
			return;
		}
		last_interrupt_time = HAL_GetTick();
	#endif

  if(GPIO_Pin == GPIO_PIN_15)
  {
    /* Toggle LED0 */
    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
  }
}
