#include "main.h"
#include "cmsis_os.h"


#define NUM_OF_PHILOSOPHERS (5)
#define MAX_NUMBER_ALLOWED (NUM_OF_PHILOSOPHERS - 1)


osThreadId defaultTaskHandle;

SemaphoreHandle_t forks[NUM_OF_PHILOSOPHERS];
SemaphoreHandle_t entry_sem;
TaskHandle_t philosophers[NUM_OF_PHILOSOPHERS];


#define left(i) (i)
#define right(i) ((i + 1) % NUM_OF_PHILOSOPHERS)

int i =0;//MY

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartDefaultTask(void const * argument);



void take_fork(int i) {
	xSemaphoreTake(forks[left(i)], portMAX_DELAY);
	xSemaphoreTake(forks[right(i)], portMAX_DELAY);
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);//green
}

void put_fork(int i) {
	xSemaphoreGive(forks[left(i)]);
	xSemaphoreGive(forks[right(i)]);
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_10);//orange
}
void philosophers_task(void *param)//MY
{
	  int i = *(int *)param;

		for(;;) {

			xSemaphoreTake(entry_sem, portMAX_DELAY);

			take_fork(i);

			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);//red

			put_fork(i);

			xSemaphoreGive(entry_sem);



		}

	}

int main(void)
{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();

  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

    int i;
  	int param[NUM_OF_PHILOSOPHERS];

  	// Create Five Semaphores for the five shared resources.
  	// Which is the fork in this case.

  	for (i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
  		forks[i] = xSemaphoreCreateMutex();
  	}

  	// This is the critical piece to avoid deadlock.
  	// If one less philosopher is allowed to act then there will no deadlock.
  	// As one philosopher will always get two forks and so it will go on.

  	entry_sem = xSemaphoreCreateCounting(MAX_NUMBER_ALLOWED, MAX_NUMBER_ALLOWED);

  	for (i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
  		param[i] = i;
  		xTaskCreate(philosophers_task, "task", 30, &(param[i]), 2, NULL);
  	}


 /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
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
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE9 PE10 PE11 */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
