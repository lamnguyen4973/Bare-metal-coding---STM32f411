/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stdint.h"
// base addreessed
#define GPIOD_BASE 0x40020C00
#define RCC_BASE 0x40023800

//addresses RCC
#define RCC_AHB1 (uint32_t*)(RCC_BASE + 0x30 )

// addresses GPIOD register
#define GPIOD_MODER  (uint32_t*)(GPIOD_BASE + 0x00)
#define GPIOD_ODR  (uint32_t*)(GPIOD_BASE + 0x14)

static void delay_ms(volatile uint32_t ms)
{
	for (volatile uint32_t i = 0; i< ms * 4000; i++);
}
int main (void){
	// enable clk for GPIOD
	*RCC_AHB1 |= (0x1 << 3);
	// set MODE for GPIOD
	*GPIOD_MODER &= ~(0xff << 24);
	*GPIOD_MODER |= (0x01 << 24);
	*GPIOD_MODER |= (0x01 <<26);
	*GPIOD_MODER |= (0x01 <<28);
	*GPIOD_MODER |= (0x01 <<30);

	while (1){
	//set GPIOD is output
	*GPIOD_ODR ^= (1 << 12);
	*GPIOD_ODR ^= (1 << 13);
	*GPIOD_ODR ^= (1 << 14);
	*GPIOD_ODR ^= (1 << 15);
	delay_ms(500);

	}
}
