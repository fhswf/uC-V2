/************************************
 *
 * File Name:  main_user.c
 * Path:       /08-02-PWM-Motor/Core/Src/main_user.c
 * Created on: 28.05.2026
 * Author:     tobi
 *
 * Praktikum uC
 *
 ************************************/

#include "main.h"

extern TIM_HandleTypeDef htim2;

void main_user()
{
  uint8_t dir = GPIO_PIN_RESET;

  // Start PWM on TIM2 Channel 1 and Channel 2
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

  // Set initial duty cycle to 0% for both channels
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);

  while(1)
  {
     // Toggle Motor Direction
     HAL_GPIO_WritePin(MOT_R_DIR_GPIO_Port, MOT_R_DIR_Pin, dir);
     // Toggle LED
     HAL_GPIO_TogglePin(LED0_USR_GPIO_Port, LED0_USR_Pin);

     if (dir == GPIO_PIN_RESET)
        { dir = GPIO_PIN_SET; }
     else
        { dir = GPIO_PIN_RESET; }

     // Speed up Motor 1
     for (int i=0;i<=100;i+=10) {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, i);
        HAL_Delay(200);
     }
     // Slow down Motor 1
     for (int i=0;i<=100;i+=10) {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 100-i);
        HAL_Delay(100);
     }
  }

}
