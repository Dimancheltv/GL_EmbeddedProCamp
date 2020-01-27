#include "stm32f3xx.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

static void vTaskBlueBlink(void *argument);

static void vTaskRedBlink(void *argument);

static void vTaskButton(void *argument);
	
TaskHandle_t xHandleLed;

static void vTaskOrangeBlink(void *argument);

uint32_t BlinkCounter = 0;

int main(void){
		/*! init led-port clock */
		RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
		/*! init button-port clock */	
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	
		/*! set  LEDs to output */
		GPIOE->MODER |= GPIO_MODER_MODER8_0;
		GPIOE->MODER |= GPIO_MODER_MODER9_0;
		GPIOE->MODER |= GPIO_MODER_MODER10_0;
		GPIOE->MODER |= GPIO_MODER_MODER14_0;
		GPIOE->MODER |= GPIO_MODER_MODER13_0;	
	  
		/*! set button input mode port */
		GPIOA->MODER &= ~ GPIO_MODER_MODER0;

		/*! Create tasks */
		xTaskCreate(vTaskOrangeBlink, "OrangeBlink", 	configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

		xTaskCreate(vTaskBlueBlink, "BlueBlink", 	configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xHandleLed);

		xTaskCreate(vTaskRedBlink, "RedBlink", 	configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

		xTaskCreate(vTaskButton, "Button", 	configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
	
		/*! Start scheduler */
		vTaskStartScheduler();

  	while(1){}
	
}

static void vTaskOrangeBlink(void *argument)
{
		while(1){
					
			vTaskDelay(1000);
			
			if (BlinkCounter == 5) {			
				GPIOE->ODR ^= GPIO_ODR_10;			
				vTaskPrioritySet(xHandleLed, 2);
				/*! Change priority */					
				BlinkCounter = 0;
				vTaskDelay(1000);
			}
			
			BlinkCounter++;			
		}
}

static void vTaskBlueBlink(void *argument)
{
		while(1){
			GPIOE->ODR ^= GPIO_ODR_8;
			vTaskDelay(1000);
		}
}

static void vTaskRedBlink(void *argument)
{
		while(1){
			GPIOE->ODR ^= GPIO_ODR_13;
			vTaskDelay(500);
		}
}

static void vTaskButton(void *argument)
{
	while(1){
		if(GPIOA->IDR & GPIO_IDR_0 ){
			vTaskDelay(100);
			GPIOE->ODR ^= GPIO_ODR_9;
			/*! Change priority */	
			vTaskPrioritySet(xHandleLed, 0); 
		} 
	
	vTaskDelay(100);
		
	}
}

