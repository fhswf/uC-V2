/*
 * main_user.c
 *
 *  Created on: 11.05.2026
 *      Author: Tobias Ellermeyer
 *
 *      HardFault-Demo
 *      Nucleo-STM32F103RB-Board with shield
 *
 */

#include "main.h"	// Include HAL and GPIO defines
#include <stdio.h>

// Handle for Timer3; defined in main.c
extern TIM_HandleTypeDef htim3;


void main_user()
{
	printf("\r\n===================================\r\n");
	printf("  HardFault Demo - Nucleo-F103RB  \r\n");
	printf("===================================\r\n");
	printf("Taste BTN0 auf Shield gedrueckt halten (laenger als 0,5 sec)\r\num HardFault auszuloesen.\r\n\r\n");

	while(1)
	{
		/* Normalbetrieb: LED blinkt mit 1 Hz */
		HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		HAL_Delay(500);

		/* Taste B1 wird active-LOW ausgeloest */
		if (HAL_GPIO_ReadPin(BTN0_GPIO_Port, BTN0_Pin) == GPIO_PIN_RESET)
		{
			printf("[INFO] Taste gedrueckt -> provoziere HardFault in 0,5 sec...\r\n");
			HAL_Delay(500); /* Kurze Entprellung + UART flush */

			/*
			* HardFault-Provokation:
			* Methode A – NULL-Pointer-Dereferenz (Zugriff auf Adresse 0x00000000)
			* Der Cortex-M3 mappt dort den Interrupt-Vektor. Ein Schreibzugriff
			* ist von unprivilegiertem oder privilegiertem Code aus verboten
			* (MPU/Bus-Fault -> HardFault escalation).
			*/
			volatile uint32_t *ptr; // = (uint32_t *)0x00000000;
			(*ptr) = 0xDEADBEEF;   /* -> BusFault -> eskaliert zu HardFault */
		}
	}
}
