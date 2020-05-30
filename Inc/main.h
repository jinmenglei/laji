/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define Blue_out_2_Pin GPIO_PIN_12
#define Blue_out_2_GPIO_Port GPIOB
#define Blue_out_1_Pin GPIO_PIN_13
#define Blue_out_1_GPIO_Port GPIOB
#define Red_out_2_Pin GPIO_PIN_14
#define Red_out_2_GPIO_Port GPIOB
#define Red_out_1_Pin GPIO_PIN_15
#define Red_out_1_GPIO_Port GPIOB
#define Gray_out_2_Pin GPIO_PIN_8
#define Gray_out_2_GPIO_Port GPIOA
#define Gray_out_1_Pin GPIO_PIN_9
#define Gray_out_1_GPIO_Port GPIOA
#define Green_out_2_Pin GPIO_PIN_10
#define Green_out_2_GPIO_Port GPIOA
#define Green_out_1_Pin GPIO_PIN_11
#define Green_out_1_GPIO_Port GPIOA
#define Green_in_Pin GPIO_PIN_6
#define Green_in_GPIO_Port GPIOB
#define Green_in_EXTI_IRQn EXTI9_5_IRQn
#define Gray_in_Pin GPIO_PIN_7
#define Gray_in_GPIO_Port GPIOB
#define Gray_in_EXTI_IRQn EXTI9_5_IRQn
#define Red_in_Pin GPIO_PIN_8
#define Red_in_GPIO_Port GPIOB
#define Red_in_EXTI_IRQn EXTI9_5_IRQn
#define Blue_in_Pin GPIO_PIN_9
#define Blue_in_GPIO_Port GPIOB
#define Blue_in_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
