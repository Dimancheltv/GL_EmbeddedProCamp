#include "stm32f3xx.h"                  

void led_init(void)
{
		/*! init clock */
		RCC->AHBENR |= RCC_AHBENR_GPIOEEN; 
		/*! set all LEDs to output */
		GPIOE->MODER |= GPIO_MODER_MODER8_0;
		GPIOE->MODER |= GPIO_MODER_MODER9_0;
		GPIOE->MODER |= GPIO_MODER_MODER10_0;
		GPIOE->MODER |= GPIO_MODER_MODER11_0;
		GPIOE->MODER |= GPIO_MODER_MODER12_0;
		GPIOE->MODER |= GPIO_MODER_MODER13_0;
		GPIOE->MODER |= GPIO_MODER_MODER14_0;
		GPIOE->MODER |= GPIO_MODER_MODER15_0;	  
}

void led_shutdown(void)
{
		/*! shutdown LEDs */
		GPIOE->ODR &= ~GPIO_ODR_8;
		GPIOE->ODR &= ~GPIO_ODR_9;
		GPIOE->ODR &= ~GPIO_ODR_10;
		GPIOE->ODR &= ~GPIO_ODR_11;
		GPIOE->ODR &= ~GPIO_ODR_12;
		GPIOE->ODR &= ~GPIO_ODR_13;
		GPIOE->ODR &= ~GPIO_ODR_14;
		GPIOE->ODR &= ~GPIO_ODR_15;

		/*! clock disable */
		RCC->AHBENR &= ~RCC_AHBENR_GPIOEEN;
		return;
}


void toggleBlue(void)
{
		GPIOE->ODR ^= GPIO_ODR_8;
		GPIOE->ODR ^= GPIO_ODR_12;
}

void toggleRed(void)
{
		GPIOE->ODR ^= GPIO_ODR_9;
		GPIOE->ODR ^= GPIO_ODR_13;
}

void toggleOrange(void)
{
		GPIOE->ODR ^= GPIO_ODR_10;
		GPIOE->ODR ^= GPIO_ODR_14;
}

void toggleGreen(void)
{
		GPIOE->ODR ^= GPIO_ODR_11;
		GPIOE->ODR ^= GPIO_ODR_15;
}

