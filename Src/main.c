/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define STATUS_NULL 0
#define STATUS_OPEN 1
#define STATUS_OPENING 2
#define STATUS_OPENED 3
#define STATUS_CLOSE 4
#define STATUS_CLOSING 5
#define STATUS_CLOSED 6
#define STATUS_COUNTING 7
#define STATUS_COUNTED 8

#define OPEN_CNT 50
#define CLOSE_CNT 50
#define WAIT_CNT 5000

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int green_status = STATUS_NULL;
int gray_status = STATUS_NULL;
int red_status = STATUS_NULL;
int blue_status = STATUS_NULL;

int green_open_cnt = 0;
int gray_open_cnt = 0;
int red_open_cnt = 0;
int blue_open_cnt = 0;


int green_wait_cnt = 0;
int gray_wait_cnt = 0;
int red_wait_cnt = 0;
int blue_wait_cnt = 0;


int green_close_cnt = 0;
int gray_close_cnt = 0;
int red_close_cnt = 0;
int blue_close_cnt = 0;
int can_control = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//	int led_cnt = 0;

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
  /* USER CODE BEGIN 2 */
	HAL_Delay(1000);
		can_control = 1;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
//		if (led_cnt++ >= 500)
//		{
//			led_cnt = 0;
//			//HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		}
		//green
		HAL_Delay(1);
		if (green_status != STATUS_NULL)
		{
			if (green_status == STATUS_OPEN)
			{
				HAL_GPIO_WritePin(Green_out_1_GPIO_Port,Green_out_1_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Green_out_2_GPIO_Port,Green_out_2_Pin,GPIO_PIN_RESET);
				green_status = STATUS_OPENING;
				green_open_cnt = 0;
			}else if (green_status == STATUS_OPENING)
			{
				if (green_open_cnt ++ >= OPEN_CNT)
				{
					green_status = STATUS_OPENED;
				}
			}else if (green_status == STATUS_OPENED)
			{
				HAL_GPIO_WritePin(Green_out_1_GPIO_Port,Green_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Green_out_2_GPIO_Port,Green_out_2_Pin,GPIO_PIN_RESET);
				green_status = STATUS_COUNTING;
				green_wait_cnt = 0;
			}else if (green_status == STATUS_COUNTING)
			{
				if (green_wait_cnt++ >= WAIT_CNT)
				{
					green_status = STATUS_COUNTED;
				}
			}else if (green_status == STATUS_COUNTED)
			{
				green_status = STATUS_CLOSE;
			}else if (green_status == STATUS_CLOSE)
			{
				HAL_GPIO_WritePin(Green_out_1_GPIO_Port,Green_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Green_out_2_GPIO_Port,Green_out_2_Pin,GPIO_PIN_SET);
				green_status = STATUS_CLOSING;
				green_close_cnt = 0;
			}else if (green_status == STATUS_CLOSING)
			{
				if (green_close_cnt++ > CLOSE_CNT)
				{
					green_status = STATUS_CLOSED;
				}
			}else if (green_status == STATUS_CLOSED)
			{
				HAL_GPIO_WritePin(Green_out_1_GPIO_Port,Green_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Green_out_2_GPIO_Port,Green_out_2_Pin,GPIO_PIN_RESET);
				green_status = STATUS_NULL;
			}
		}
		
		//gray
		
		if (gray_status != STATUS_NULL)
		{
			if (gray_status == STATUS_OPEN)
			{
				HAL_GPIO_WritePin(Gray_out_1_GPIO_Port,Gray_out_1_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Gray_out_2_GPIO_Port,Gray_out_2_Pin,GPIO_PIN_RESET);
				gray_status = STATUS_OPENING;
				gray_open_cnt = 0;
			}else if (gray_status == STATUS_OPENING)
			{
				if (gray_open_cnt ++ >= OPEN_CNT)
				{
					gray_status = STATUS_OPENED;
				}
			}else if (gray_status == STATUS_OPENED)
			{
				HAL_GPIO_WritePin(Gray_out_1_GPIO_Port,Gray_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Gray_out_2_GPIO_Port,Gray_out_2_Pin,GPIO_PIN_RESET);
				gray_status = STATUS_COUNTING;
				gray_wait_cnt = 0;
			}else if (gray_status == STATUS_COUNTING)
			{
				if (gray_wait_cnt++ >= WAIT_CNT)
				{
					gray_status = STATUS_COUNTED;
				}
			}else if (gray_status == STATUS_COUNTED)
			{
				gray_status = STATUS_CLOSE;
			}else if (gray_status == STATUS_CLOSE)
			{
				HAL_GPIO_WritePin(Gray_out_1_GPIO_Port,Gray_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Gray_out_2_GPIO_Port,Gray_out_2_Pin,GPIO_PIN_SET);
				gray_status = STATUS_CLOSING;
				gray_close_cnt = 0;
			}else if (gray_status == STATUS_CLOSING)
			{
				if (gray_close_cnt++ > CLOSE_CNT)
				{
					gray_status = STATUS_CLOSED;
				}
			}else if (gray_status == STATUS_CLOSED)
			{
				HAL_GPIO_WritePin(Gray_out_1_GPIO_Port,Gray_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Gray_out_2_GPIO_Port,Gray_out_2_Pin,GPIO_PIN_RESET);
				gray_status = STATUS_NULL;
			}
		}
		// red
		if (red_status != STATUS_NULL)
		{
			if (red_status == STATUS_OPEN)
			{
				HAL_GPIO_WritePin(Red_out_1_GPIO_Port,Red_out_1_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Red_out_2_GPIO_Port,Red_out_2_Pin,GPIO_PIN_RESET);
				red_status = STATUS_OPENING;
				red_open_cnt = 0;
			}else if (red_status == STATUS_OPENING)
			{
				if (red_open_cnt ++ >= OPEN_CNT)
				{
					red_status = STATUS_OPENED;
				}
			}else if (red_status == STATUS_OPENED)
			{
				HAL_GPIO_WritePin(Red_out_1_GPIO_Port,Red_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Red_out_2_GPIO_Port,Red_out_2_Pin,GPIO_PIN_RESET);
				red_status = STATUS_COUNTING;
				red_wait_cnt = 0;
			}else if (red_status == STATUS_COUNTING)
			{
				if (red_wait_cnt++ >= WAIT_CNT)
				{
					red_status = STATUS_COUNTED;
				}
			}else if (red_status == STATUS_COUNTED)
			{
				red_status = STATUS_CLOSE;
			}else if (red_status == STATUS_CLOSE)
			{
				HAL_GPIO_WritePin(Red_out_1_GPIO_Port,Red_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Red_out_2_GPIO_Port,Red_out_2_Pin,GPIO_PIN_SET);
				red_status = STATUS_CLOSING;
				red_close_cnt = 0;
			}else if (red_status == STATUS_CLOSING)
			{
				if (red_close_cnt++ > CLOSE_CNT)
				{
					red_status = STATUS_CLOSED;
				}
			}else if (red_status == STATUS_CLOSED)
			{
				HAL_GPIO_WritePin(Red_out_1_GPIO_Port,Red_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Red_out_2_GPIO_Port,Red_out_2_Pin,GPIO_PIN_RESET);
				red_status = STATUS_NULL;
			}
		}
		
		// blue
		if (blue_status != STATUS_NULL)
		{
			if (blue_status == STATUS_OPEN)
			{
				HAL_GPIO_WritePin(Blue_out_1_GPIO_Port,Blue_out_1_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Blue_out_2_GPIO_Port,Blue_out_2_Pin,GPIO_PIN_RESET);
				blue_status = STATUS_OPENING;
				blue_open_cnt = 0;
			}else if (blue_status == STATUS_OPENING)
			{
				if (blue_open_cnt ++ >= OPEN_CNT)
				{
					blue_status = STATUS_OPENED;
				}
			}else if (blue_status == STATUS_OPENED)
			{
				HAL_GPIO_WritePin(Blue_out_1_GPIO_Port,Blue_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Blue_out_2_GPIO_Port,Blue_out_2_Pin,GPIO_PIN_RESET);
				blue_status = STATUS_COUNTING;
				blue_wait_cnt = 0;
			}else if (blue_status == STATUS_COUNTING)
			{
				if (blue_wait_cnt++ >= WAIT_CNT)
				{
					blue_status = STATUS_COUNTED;
				}
			}else if (blue_status == STATUS_COUNTED)
			{
				blue_status = STATUS_CLOSE;
			}else if (blue_status == STATUS_CLOSE)
			{
				HAL_GPIO_WritePin(Blue_out_1_GPIO_Port,Blue_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Blue_out_2_GPIO_Port,Blue_out_2_Pin,GPIO_PIN_SET);
				blue_status = STATUS_CLOSING;
				blue_close_cnt = 0;
			}else if (blue_status == STATUS_CLOSING)
			{
				if (blue_close_cnt++ > CLOSE_CNT)
				{
					blue_status = STATUS_CLOSED;
				}
			}else if (blue_status == STATUS_CLOSED)
			{
				HAL_GPIO_WritePin(Blue_out_1_GPIO_Port,Blue_out_1_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Blue_out_2_GPIO_Port,Blue_out_2_Pin,GPIO_PIN_RESET);
				blue_status = STATUS_NULL;
			}
		}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Blue_out_2_Pin|Blue_out_1_Pin|Red_out_2_Pin|Red_out_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Gray_out_2_Pin|Gray_out_1_Pin|Green_out_2_Pin|Green_out_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Blue_out_2_Pin Blue_out_1_Pin Red_out_2_Pin Red_out_1_Pin */
  GPIO_InitStruct.Pin = Blue_out_2_Pin|Blue_out_1_Pin|Red_out_2_Pin|Red_out_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Gray_out_2_Pin Gray_out_1_Pin Green_out_2_Pin Green_out_1_Pin */
  GPIO_InitStruct.Pin = Gray_out_2_Pin|Gray_out_1_Pin|Green_out_2_Pin|Green_out_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Green_in_Pin Gray_in_Pin Red_in_Pin Blue_in_Pin */
  GPIO_InitStruct.Pin = Green_in_Pin|Gray_in_Pin|Red_in_Pin|Blue_in_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */
/**
  * ????: ??????????
  * ????: GPIO_Pin:????
  * ? ? ?: ?
  * ?    ?: ?
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin==Green_in_Pin)
  {
		if (can_control)
		{
			if(green_status == STATUS_NULL){
				green_status = STATUS_OPEN;
				green_open_cnt =0;
			}else if (green_status == STATUS_COUNTING){
				green_wait_cnt = 0;
			}
		}
		
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    __HAL_GPIO_EXTI_CLEAR_IT(Green_in_Pin);
  }else if(GPIO_Pin==Gray_in_Pin)
  {
		if (can_control)
		{
			if(gray_status == STATUS_NULL){
				gray_status = STATUS_OPEN;
				gray_open_cnt =0;
			}else if (gray_status == STATUS_COUNTING){
				gray_wait_cnt = 0;
			}
		}
		
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    __HAL_GPIO_EXTI_CLEAR_IT(Gray_in_Pin);
  }else if(GPIO_Pin==Red_in_Pin)
  {
		if (can_control)
		{
			if(red_status == STATUS_NULL){
				red_status = STATUS_OPEN;
				red_open_cnt =0;
			}else if (red_status == STATUS_COUNTING){
				red_wait_cnt = 0;
			}
		}
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    __HAL_GPIO_EXTI_CLEAR_IT(Red_in_Pin);
  }else if(GPIO_Pin==Blue_in_Pin)
  {
		if (can_control)
		{
			if(blue_status == STATUS_NULL){
				blue_status = STATUS_OPEN;
				blue_open_cnt =0;
			}else if (blue_status == STATUS_COUNTING){
				blue_wait_cnt = 0;
			}
		}
		
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    __HAL_GPIO_EXTI_CLEAR_IT(Blue_in_Pin);
  }

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
