#include "stm32f3xx.h"                  // Device header

int main(void){
/*! init clock */
		RCC->AHBENR |= RCC_AHBENR_GPIOEEN; 
		/*! set all LEDs to output */
		GPIOE->MODER |= GPIO_MODER_MODER8_0;
	
	while(1){
		GPIOE->ODR ^= GPIO_ODR_8;
		for(int i=0; i<100000; i++);
	}
	
}
