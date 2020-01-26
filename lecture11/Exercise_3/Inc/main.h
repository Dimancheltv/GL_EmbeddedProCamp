/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define DRDY_Pin GPIO_PIN_2
#define DRDY_GPIO_Port GPIOE
#define CS_I2C_SPI_Pin GPIO_PIN_3
#define CS_I2C_SPI_GPIO_Port GPIOE
#define MEMS_INT3_Pin GPIO_PIN_4
#define MEMS_INT3_GPIO_Port GPIOE
#define MEMS_INT4_Pin GPIO_PIN_5
#define MEMS_INT4_GPIO_Port GPIOE
#define OSC32_IN_Pin GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define OSC32_OUT_Pin GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOF
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOF
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOA
#define SPI1_SCK_Pin GPIO_PIN_5
#define SPI1_SCK_GPIO_Port GPIOA
#define SPI1_MISO_Pin GPIO_PIN_6
#define SPI1_MISO_GPIO_Port GPIOA
#define SPI1_MISOA7_Pin GPIO_PIN_7
#define SPI1_MISOA7_GPIO_Port GPIOA
#define LD4_Pin GPIO_PIN_8
#define LD4_GPIO_Port GPIOE
#define LD3_Pin GPIO_PIN_9
#define LD3_GPIO_Port GPIOE
#define LD5_Pin GPIO_PIN_10
#define LD5_GPIO_Port GPIOE
#define LD7_Pin GPIO_PIN_11
#define LD7_GPIO_Port GPIOE
#define LD9_Pin GPIO_PIN_12
#define LD9_GPIO_Port GPIOE
#define LD10_Pin GPIO_PIN_13
#define LD10_GPIO_Port GPIOE
#define LD8_Pin GPIO_PIN_14
#define LD8_GPIO_Port GPIOE
#define LD6_Pin GPIO_PIN_15
#define LD6_GPIO_Port GPIOE
#define DM_Pin GPIO_PIN_11
#define DM_GPIO_Port GPIOA
#define DP_Pin GPIO_PIN_12
#define DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define I2C1_SCL_Pin GPIO_PIN_6
#define I2C1_SCL_GPIO_Port GPIOB
#define I2C1_SDA_Pin GPIO_PIN_7
#define I2C1_SDA_GPIO_Port GPIOB
#define MEMS_INT1_Pin GPIO_PIN_0
#define MEMS_INT1_GPIO_Port GPIOE
#define MEMS_INT2_Pin GPIO_PIN_1
#define MEMS_INT2_GPIO_Port GPIOE


/* ########################## Assert Selection ############################## */
/* USER CODE BEGIN Private defines */
														// LED numbers according to Datasheet
#define LED01 GPIO_PIN_9 		// LED 3
#define LED02 GPIO_PIN_8		// LED 4
#define LED03 GPIO_PIN_10   // LED 5
#define LED04 GPIO_PIN_15 	// LED 6
#define LED05 GPIO_PIN_11		// LED 7
#define LED06 GPIO_PIN_14   // LED 8
#define LED07 GPIO_PIN_12		// LED 9
#define LED08 GPIO_PIN_13   // LED 10

#define LEDPORT GPIOE // all LED's are connected to portE

											// functions set LED's on
#define LED01ON() HAL_GPIO_WritePin(LEDPORT, LED01, GPIO_PIN_SET)
#define LED02ON() HAL_GPIO_WritePin(LEDPORT, LED02, GPIO_PIN_SET)
#define LED03ON() HAL_GPIO_WritePin(LEDPORT, LED03, GPIO_PIN_SET)
#define LED04ON() HAL_GPIO_WritePin(LEDPORT, LED04, GPIO_PIN_SET)
#define LED05ON() HAL_GPIO_WritePin(LEDPORT, LED05, GPIO_PIN_SET)
#define LED06ON() HAL_GPIO_WritePin(LEDPORT, LED06, GPIO_PIN_SET)
#define LED07ON() HAL_GPIO_WritePin(LEDPORT, LED07, GPIO_PIN_SET)
#define LED08ON() HAL_GPIO_WritePin(LEDPORT, LED08, GPIO_PIN_SET)

											// functions set LED's off
#define LED01OFF() HAL_GPIO_WritePin(LEDPORT, LED01, GPIO_PIN_RESET)	
#define LED02OFF() HAL_GPIO_WritePin(LEDPORT, LED02, GPIO_PIN_RESET)
#define LED03OFF() HAL_GPIO_WritePin(LEDPORT, LED03, GPIO_PIN_RESET)
#define LED04OFF() HAL_GPIO_WritePin(LEDPORT, LED04, GPIO_PIN_RESET)
#define LED05OFF() HAL_GPIO_WritePin(LEDPORT, LED05, GPIO_PIN_RESET)
#define LED06OFF() HAL_GPIO_WritePin(LEDPORT, LED06, GPIO_PIN_RESET)
#define LED07OFF() HAL_GPIO_WritePin(LEDPORT, LED07, GPIO_PIN_RESET)
#define LED08OFF() HAL_GPIO_WritePin(LEDPORT, LED08, GPIO_PIN_RESET)

/* USER CODE END Private defines */
#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
