/************************************
 *
 * File Name:  main_user.c
 * Path:       /08-03-Encoder/Core/Src/main_user.c
 * Created on: 28.05.2026
 * Author:     tobi
 *
 * Praktikum uC
 *
 ************************************/

#include <stdio.h>
#include "main.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void main_user()
{
	uint16_t enc_left, enc_right;
	printf("\n\nStarting Encoder Test\r\n");
	printf("*********************\r\n\n");
	/* Encoder Setup */
	__HAL_TIM_SET_COUNTER(&htim3,0);
	__HAL_TIM_SET_COUNTER(&htim4,0);
	HAL_TIM_Encoder_Start_IT(&htim3,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start_IT(&htim4,TIM_CHANNEL_1);

	while(1)
	{
		enc_left = __HAL_TIM_GET_COUNTER(&htim3);
		enc_right = __HAL_TIM_GET_COUNTER(&htim4);
		printf("Encoders: Left %6d   Right %6d\r\n", enc_left, enc_right);
		HAL_Delay(500);
	}
}
