/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD_LIB.h"
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

/* USER CODE BEGIN PV */
uint8_t menu1=0,menu2=0,aux1=0,aux2=0,aux3=0,aux4=0,aux5=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void Pulsadores(void);
void Menu1(void);
void Menu2(void);
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
  LCD_Init();

  LCD_CreateCaracter(1,0x10,0x08,0x04,0x07,0x04,0x08,0x10,0x00);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(menu1==0){
		  Menu1();
		  Pulsadores();

		if(aux2==0 && aux3==1){
			comando(0x00);
			comando(0x01);
			menu1=1;
			aux1=0;aux2=0;aux3=0;aux4=0;
		}

	  }
	  if(menu1==1){
		  Menu2();
		  Pulsadores();
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D6_Pin|D5_Pin|D4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, D7_Pin|RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RIGTH_Pin LEFT_Pin UP_Pin DOWN_Pin */
  GPIO_InitStruct.Pin = RIGTH_Pin|LEFT_Pin|UP_Pin|DOWN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D6_Pin D5_Pin D4_Pin */
  GPIO_InitStruct.Pin = D6_Pin|D5_Pin|D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : EN_Pin */
  GPIO_InitStruct.Pin = EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : D7_Pin RS_Pin */
  GPIO_InitStruct.Pin = D7_Pin|RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void Pulsadores(void){
	if(HAL_GPIO_ReadPin(GPIOA, DOWN_Pin)==0){
		  while(HAL_GPIO_ReadPin(GPIOA, DOWN_Pin)==0);
		  HAL_Delay(20);
		  aux2++;
		  if(menu1==0){
			  if(aux2>2) {aux2=0;}
		  }else if(menu1==1){
			  if(aux2>3) {aux2=0;}
		  }
	  }
	  if(HAL_GPIO_ReadPin(GPIOA, UP_Pin)==0){
		  while(HAL_GPIO_ReadPin(GPIOA, UP_Pin)==0);
		  HAL_Delay(20);
		  aux2--;
		  if(menu1==0){
			  if(aux2<0) {aux2=2;}
		  }
		  }else if(menu1==1){
					  if(aux2<0) {aux2=1;}

		  }
	  if(HAL_GPIO_ReadPin(GPIOA, RIGTH_Pin)==0){
		  while(HAL_GPIO_ReadPin(GPIOA, RIGTH_Pin)==0);
		  HAL_Delay(20);
		  aux3++;
		  if(menu1==0){
			  if(aux3>1)aux3=1;
		  }
		  if(menu1==1){
			  if(aux3>2)aux3=2;
		  }
	  if(HAL_GPIO_ReadPin(GPIOA, LEFT_Pin)==0){
		  while(HAL_GPIO_ReadPin(GPIOA, LEFT_Pin)==0);
		  HAL_Delay(20);
		  aux3--;
		  if(menu1==1){

		  }

	  }
}
}

void Menu1(void){
	LCD_SetCursor(1,1);
	LCD_PrintString("Menu");
	LCD_SetCursor(2,2);
	LCD_PrintString("Glucosa");
	LCD_SetCursor(2,3);
	LCD_PrintString("Dosis");
	LCD_SetCursor(2,4);
	LCD_PrintString("Historial");
	if(aux2==0){
		LCD_SetCursor(1,3);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,4);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,2);
		LCD_WriteCaracter(1);
	}else if(aux2==1){
		LCD_SetCursor(1,2);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,4);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,3);
		LCD_WriteCaracter(1);
	}else if(aux2==2){
		LCD_SetCursor(1,2);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,3);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,4);
		LCD_WriteCaracter(1);
	 }
}

void Menu2 (void){
	LCD_CreateCaracter(2,   0B00011111,0B00010001,0B00010001,0B00010001, 0B00010001,0B00010001,0B00011111,0B00000000);
	LCD_CreateCaracter(3,   0B11111111,0B11111111,0B11111111,0B11111111,0B11111111,0B11111111,0B11111111, 0B11111111);

	if(aux2==0 && aux3==0){
	LCD_SetCursor(1,1);
	LCD_PrintString("Glucosa");
	LCD_SetCursor(2,2);
	LCD_PrintString("Actual : ");
	LCD_SetCursor(2,3);
	LCD_PrintString("Confirmar?");
	LCD_SetCursor(9,4);
	LCD_PrintString("NO   SI");
	LCD_SetCursor(8,4);
	LCD_WriteCaracter(3);
	LCD_SetCursor(13,4);
	LCD_WriteCaracter(3);

	LCD_SetCursor(1,3);
	LCD_PrintCaracter(' ');
	LCD_SetCursor(1,2);
	LCD_WriteCaracter(1);
	LCD_SetCursor(8,4);
	LCD_WriteCaracter(2);
	LCD_SetCursor(13,4);
	LCD_WriteCaracter(2);

	}else if(aux2==1 && aux3==0){
		LCD_SetCursor(1,2);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,3);
		LCD_WriteCaracter(1);
		LCD_SetCursor(8,4);
		LCD_WriteCaracter(2);
		LCD_SetCursor(13,4);
		LCD_WriteCaracter(2);
	}else if(aux2==1 && aux3==1){
		LCD_SetCursor(1,2);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,3);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(8,4);
		LCD_WriteCaracter(1);
		LCD_SetCursor(13,4);
		LCD_WriteCaracter(2);
	 }
	else if(aux2==1 && aux3==2){
		LCD_SetCursor(1,2);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(1,3);
		LCD_PrintCaracter(' ');
		LCD_SetCursor(8,4);
		LCD_WriteCaracter(2);
		LCD_SetCursor(13,4);
		LCD_WriteCaracter(1);
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

