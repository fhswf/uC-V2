/************************************
 *
 * File Name:  main_user.c
 * Path:       /09-02-IRQ-1/Core/Src/main_user.c
 * Created on: 01.06.2026
 * Author:     tobi
 *
 ************************************/


#include "main.h"

extern TIM_HandleTypeDef htim3; // Timer3 Handle

void main_user()
{
    // Start Time Base of Timer 3
    HAL_TIM_Base_Start_IT(&htim3);

    // Toggle LED1 in main loop to show that
    // main loop is still running
    while(1) {
       HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
       HAL_Delay(200);
    }
}
// ... Fortsetzung nächste Folie


// ... Fortsetzung des Codes

// Bei Timer 3 Interrupt LED0 togglen
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)	// "our" timer
    {
       HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    }
}





