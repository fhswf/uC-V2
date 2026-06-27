/************************************
 *
 * File Name:  main_user.c
 * Path:       /05-LED-PB0/Core/Src/main_user.c
 * Created on: 03.05.2026
 * Author:     tobi
 *
 * Praktikum uC
 *
 ************************************/

#include "main.h"

void main_user(void)
{
  while (1)
  {
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	HAL_Delay(500);
  }
}

