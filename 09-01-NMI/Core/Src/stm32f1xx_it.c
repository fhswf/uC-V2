/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

// Busy Wait, HAL_Delay() ist in einem Fault-Handler nicht nutzbar,
// da er auf dem SysTick-Interrupt basier


static void Busy_Delay(uint32_t ms)
{
    uint32_t cycles_per_ms = HAL_RCC_GetSysClockFreq() / 4000UL;
    volatile uint32_t count = ms * cycles_per_ms;
    while (count--) { __NOP(); }
}

static void sos()
{
	  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
	  for (int i=0; i<6;i++) {
		  HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		  Busy_Delay(100);
	  }
	  Busy_Delay(300);
	  for (int i=0; i<3;i++) {
		  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
		  Busy_Delay(300);
		  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		  Busy_Delay(100);
	  }
	  for (int i=0; i<6;i++) {
		  HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		  Busy_Delay(100);
	  }
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
	/* USER CODE BEGIN HardFault_IRQn 0 */

	uint32_t *stacked_regs = (uint32_t*)__get_MSP();

	uint32_t stacked_r0   = stacked_regs[0];
	uint32_t stacked_r1   = stacked_regs[1];
	uint32_t stacked_r2   = stacked_regs[2];
	uint32_t stacked_r3   = stacked_regs[3];
	uint32_t stacked_r12  = stacked_regs[4];
	uint32_t stacked_lr   = stacked_regs[5];
	uint32_t stacked_pc   = stacked_regs[6];
	uint32_t stacked_psr  = stacked_regs[7];

	/* Diagnose-Ausgabe */
	printf("\r\n\r\n!!! HARDFAULT DETECTED !!!\r\n");
	printf("----------------------------\r\n");

	printf("R0   = 0x%08lX\r\n", stacked_r0);
	printf("R1   = 0x%08lX\r\n", stacked_r1);
	printf("R2   = 0x%08lX\r\n", stacked_r2);
	printf("R3   = 0x%08lX\r\n", stacked_r3);
	printf("R12  = 0x%08lX\r\n", stacked_r12);
	printf("LR   = 0x%08lX\r\n", stacked_lr);
	printf("PC   = 0x%08lX  <-- Fehlerort\r\n", stacked_pc);
	printf("xPSR = 0x%08lX\r\n", stacked_psr);

	/* Fault-Status-Register (Cortex-M3 spezifisch) */
	uint32_t hfsr  = SCB->HFSR;   /* HardFault Status Register  */
	uint32_t cfsr  = SCB->CFSR;   /* Configurable Fault SR      */
	uint32_t mmfar = SCB->MMFAR;  /* MemManage Fault Address    */
	uint32_t bfar  = SCB->BFAR;   /* BusFault Address Register  */

	printf("HFSR = 0x%08lX\r\n", hfsr);
	printf("CFSR = 0x%08lX\r\n", cfsr);
	printf("MMFAR= 0x%08lX\r\n", mmfar);
	printf("BFAR = 0x%08lX\r\n", bfar);

	/* CFSR dekodieren (vereinfacht) */
	printf("----------------------------\r\n");
	if (cfsr & 0x0001) printf("[FAULT] IACCVIOL  - Instruction Access Violation\r\n");
	if (cfsr & 0x0002) printf("[FAULT] DACCVIOL  - Data Access Violation\r\n");
	if (cfsr & 0x0008) printf("[FAULT] MUNSTKERR - MemManage Unstacking Error\r\n");
	if (cfsr & 0x0010) printf("[FAULT] MSTKERR   - MemManage Stacking Error\r\n");
	if (cfsr & 0x0100) printf("[FAULT] IBUSERR   - Instruction Bus Error\r\n");
	if (cfsr & 0x0200) printf("[FAULT] PRECISERR - Precise Data Bus Error\r\n");
	if (cfsr & 0x0400) printf("[FAULT] IMPRECISERR - Imprecise Data Bus Error\r\n");
	if (cfsr & 0x1000) printf("[FAULT] UNDEFINSTR - Undefined Instruction\r\n");
	if (cfsr & 0x2000) printf("[FAULT] INVSTATE  - Invalid State\r\n");
	if (hfsr & SCB_HFSR_FORCED_Msk) printf("[FAULT] FORCED    - Fault eskaliert zu HardFault\r\n");
	if (hfsr & SCB_HFSR_VECTTBL_Msk) printf("[FAULT] VECTTBL   - Vector Table Read Fault\r\n");

	printf("----------------------------\r\n");
	printf("System-Reset in 5 Sekunden ...\r\n");

	/* LED SOS-Blinkmuster: ... --- ... (Morse) */
	for (int loop = 0; loop < 3; loop++)  /* 3x SOS */
	{
		sos();
		Busy_Delay(500);
	}

	printf("Resetting  ...\r\n\r\n");
	Busy_Delay(100);
	NVIC_SystemReset();

	/* USER CODE END HardFault_IRQn 0 */
	while (1)
	{
		/* USER CODE BEGIN W1_HardFault_IRQn 0 */
		/* USER CODE END W1_HardFault_IRQn 0 */
	}
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
	 sos();
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(B1_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
