/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Create program "The Dining Philosophers"
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include "Init.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define  ARISTOTLE 0
#define  PLATON 1
#define  NIETZSCHE 2
#define  KANT 3
#define  SOCRAT 4
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */
/* Private variables ---------------------------------------------------------*/

TaskHandle_t myTaskHandle[5]; 
/*for each of philosofer*/
SemaphoreHandle_t xSemaphorePhilosofer[5] = {NULL}; 
/* fork taking */
SemaphoreHandle_t xSemaphoreTakingFork = NULL; 

volatile uint32_t TIM1_Count = 0;			
volatile uint32_t TIM1_Count_Sec = 0;	
volatile uint8_t philosopherStatus[5] = {0}; 

	
/* Private function prototypes -----------------------------------------------*/
void Philosopher_1(void* pvParameters);
void Philosopher_2(void* pvParameters);
void Philosopher_3(void* pvParameters);
void Philosopher_4(void* pvParameters);
void Philosopher_5(void* pvParameters);

void t_Fork (uint8_t);
void t_Eat(uint8_t);
void p_Fork (uint8_t);
/* ---------------------------------------------------------------------------*/
int main(void)
{
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */


/* MCU Configuration--------------------------------------------------------*/

/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

/* USER CODE BEGIN Init */

/* USER CODE END Init */

/* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_USB_PCD_Init();
	/* creating semaphors for each forks */
	for(int i = 0; i < 5; i++)
	{
		xSemaphorePhilosofer[i] = xSemaphoreCreateBinary();  
		if( xSemaphorePhilosofer[i]  == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to be created successfully. */
				 for (;;);    
		}
		else
		{
				if( xSemaphoreGive( xSemaphorePhilosofer[i]  ) != pdTRUE )
				{
					for (;;); 
				}
		}	
	}
	/* semaphor for taking fork */
	xSemaphoreTakingFork = xSemaphoreCreateBinary();
	if( xSemaphoreTakingFork  == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to be created successfully. */
				 for (;;);  
		}
		else
		{
				if( xSemaphoreGive(xSemaphoreTakingFork) != pdTRUE )
				{
					for (;;); 
				}
		}	
		
		xTaskCreate(Philosopher_1,       /* Function that implements the task. */
								"philosopher1",          /* Text name for the task. */
								64,      /* Stack size in words, not bytes. */
								NULL,    /* Parameter passed into the task. */
								0,/* Priority at which the task is created. */
								&myTaskHandle[0] );
	
		xTaskCreate(Philosopher_2,       /* Function that implements the task. */
								"philosopher2",          /* Text name for the task. */
								64,      /* Stack size in words, not bytes. */
								NULL,    /* Parameter passed into the task. */
								0,/* Priority at which the task is created. */
								&myTaskHandle[1] );
								
		xTaskCreate(Philosopher_3,       /* Function that implements the task. */
								"philosopher3",          /* Text name for the task. */
								64,      /* Stack size in words, not bytes. */
								NULL,    /* Parameter passed into the task. */
								0,/* Priority at which the task is created. */
								&myTaskHandle[2] );
		xTaskCreate(Philosopher_4,       /* Function that implements the task. */
								"philosopher4",          /* Text name for the task. */
								64,      /* Stack size in words, not bytes. */
								NULL,    /* Parameter passed into the task. */
								0,/* Priority at which the task is created. */
								&myTaskHandle[3] );	
		xTaskCreate(Philosopher_5,       /* Function that implements the task. */
								"philosopher5",          /* Text name for the task. */
								64,      /* Stack size in words, not bytes. */
								NULL,    /* Parameter passed into the task. */
								0,/* Priority at which the task is created. */
								&myTaskHandle[4] );								
	/* Start scheduler */
  osKernelStart();

  while (1)
  {
  }
}
/**
  * @brief  executed when one of the philosophers try to take a fork.
  * @param  Number of philosopher who want to take a fork.
  */
void t_Fork (uint8_t philosopher)
{
	if (xSemaphoreTakingFork != NULL)
  {
    if(osSemaphoreWait(xSemaphoreTakingFork , 100) == osOK)
    {
			philosopherStatus[philosopher] = 1;
			/* taking forks */
			t_Eat(philosopher);
			/* taking semaphor for philosofer how waithing for forks */
			osSemaphoreRelease(xSemaphoreTakingFork);
		}
		else
		{
			/* taking semaphor for philosopher how whants to eat */
			xSemaphoreTake( xSemaphorePhilosofer[philosopher],  portMAX_DELAY );
		}
	}
}
/**
  * @brief  executed when one of the philosophers test forks.
  * @param  Number of philosopher who want release the forks.
  */
void t_Eat(uint8_t philosopher)
{
		if (philosopherStatus[philosopher] == 1 
				  && philosopherStatus[(philosopher + 5 - 1) % 5] != 2 
					&& philosopherStatus[(philosopher + 1) % 5] != 2) 
			{
				philosopherStatus[philosopher] = 2;				
				xSemaphoreGive( xSemaphorePhilosofer[philosopher] );
			}
}
/**
  * @brief  executed when one of the philosophers releasin the forks.
  * @param  Number of philosopher who want release the forks.
  */
void p_Fork (uint8_t philosopher)
{
	if(osSemaphoreWait(xSemaphoreTakingFork , 100) == osOK)
	{
		philosopherStatus[philosopher] = 0;
		t_Eat((philosopher + 5 - 1) % 5);
		t_Eat((philosopher + 1) % 5);
		osSemaphoreRelease(xSemaphoreTakingFork);
	}
}


void Philosopher_1( void* pvParameters)
{
	for(;;)
  {
		/*  thinking */
		osDelay(100);
		/*  take forks */
		t_Fork (ARISTOTLE);
		
		if(xSemaphoreTake( xSemaphorePhilosofer[ARISTOTLE],  portMAX_DELAY ) == pdTRUE && philosopherStatus[ARISTOTLE] == 2) 
		{ 
				/* eating */
				HAL_GPIO_WritePin(LEDPORT, LED02, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED01, GPIO_PIN_SET);
				osDelay(100);
				HAL_GPIO_WritePin(LEDPORT, LED01, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED02, GPIO_PIN_SET);
				osDelay(100);
				/* eating */
				xSemaphoreGive( xSemaphorePhilosofer[ARISTOTLE]);
				p_Fork(ARISTOTLE);
		}
		else
		{
			osDelay(10);
		}
	}
}

void Philosopher_2( void* pvParameters)
{
	for(;;)
  {
		/*  thinking */
		osDelay(100);
		/*  take forks */
		t_Fork (PLATON);
		
		if(xSemaphoreTake( xSemaphorePhilosofer[PLATON],  portMAX_DELAY ) == pdTRUE && philosopherStatus[PLATON] == 2) 
		{ 
				/* eating */
				HAL_GPIO_WritePin(LEDPORT, LED04, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED03, GPIO_PIN_SET);
				osDelay(100);
				HAL_GPIO_WritePin(LEDPORT, LED03, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED04, GPIO_PIN_SET);
				osDelay(100);
				/* eating */
				xSemaphoreGive(xSemaphorePhilosofer[PLATON]);
				p_Fork(PLATON);
			}
		else
		{
			osDelay(10);
		}
					
	}
}

void Philosopher_3( void* pvParameters)
{
	for(;;)
  {
		/*  thinking */
		osDelay(70);
		/*  take forks */
		t_Fork (NIETZSCHE);
		
		if(xSemaphoreTake( xSemaphorePhilosofer[NIETZSCHE],  portMAX_DELAY ) == pdTRUE && philosopherStatus[NIETZSCHE] == 2) 
		{ 
				/* eating */
				HAL_GPIO_WritePin(LEDPORT, LED06, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED05, GPIO_PIN_SET);
				osDelay(100);
				HAL_GPIO_WritePin(LEDPORT, LED05, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED06, GPIO_PIN_SET);
				osDelay(100);
				/* eating */
				xSemaphoreGive(xSemaphorePhilosofer[NIETZSCHE]);
				p_Fork(NIETZSCHE);
			}
		else
		{
			osDelay(10);
		}
			
	}
}

void Philosopher_4( void* pvParameters)
{
	for(;;)
  {
		/*  thinking */
		osDelay(100);
		/*  take forks */
		t_Fork (KANT);
		
		if(xSemaphoreTake( xSemaphorePhilosofer[KANT],  portMAX_DELAY ) == pdTRUE && philosopherStatus[KANT] == 2) 
		{ 
				/* eating */
				HAL_GPIO_WritePin(LEDPORT, LED08, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED07, GPIO_PIN_SET);
				osDelay(100);
				HAL_GPIO_WritePin(LEDPORT, LED07, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LEDPORT, LED08, GPIO_PIN_SET);
				osDelay(100);
				/* eating */
				xSemaphoreGive(xSemaphorePhilosofer[KANT]);
				p_Fork(KANT);
			}
		else
		{
			osDelay(10);
		}
	}
}

void Philosopher_5( void* pvParameters)
{
	for(;;)
  {
		/*  thinking */
		osDelay(100);
		/*  take forks */
		t_Fork (SOCRAT);
		
		if(xSemaphoreTake( xSemaphorePhilosofer[SOCRAT],  portMAX_DELAY ) == pdTRUE && philosopherStatus[SOCRAT] == 2) 
		{ 
		  	osDelay(100);

				xSemaphoreGive(xSemaphorePhilosofer[SOCRAT]);
				p_Fork(SOCRAT);
			}
		else
		{
			osDelay(10);
		}
	}
}


/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
	TIM1_Count++;
  if(TIM1_Count%1000==0)
  {
    TIM1_Count_Sec++; 
  }
  if(TIM1_Count>=10000000) 
	{
		TIM1_Count=0;
	}
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  while(1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 

}
#endif /* USE_FULL_ASSERT */
