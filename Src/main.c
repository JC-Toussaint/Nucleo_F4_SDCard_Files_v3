/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {
	SHIELD_NOT_DETECTED = 0,
	SHIELD_DETECTED
}ShieldStatus;

/* Private define ------------------------------------------------------------*/
#define SD_CARD_NOT_FORMATTED                    0
#define SD_CARD_FILE_NOT_SUPPORTED               1
#define SD_CARD_OPEN_FAIL                        2
#define FATFS_NOT_MOUNTED                        3
#define STRING_SZ                              128
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
uint8_t BlinkSpeed = 0, str[20];
__IO uint8_t JoystickValue = 0;
char* pDirectoryFiles[MAX_BMP_FILES];
DIR dir;
FILINFO fno;
FIL MyFile;     /* File object */
FATFS SD_FatFs;  /* File system object for SD card logical drive */
char SD_Path[4]; /* SD card logical drive path */
DIR  items[256];   /* array of dir struct */
UINT items_sz=0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

FRESULT scan_files (char* path, DIR* items, UINT *items_sz);
FRESULT read_filename(char* path, DIR dir, char* fname);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE
{
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

	return ch;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	char buffer[STRING_SZ];
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
  MX_USART2_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

	snprintf(buffer, sizeof(buffer), "Start\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

	//SD_IO_Init();

	BSP_LED_Off(LED2);

	/*##-1- Link the SD disk I/O driver ########################################*/
	if(FATFS_LinkDriver(&SD_Driver, SD_Path) == 0)
	{
		/*##-2- Register the file system object to the FatFs module ##############*/
		if(f_mount(&SD_FatFs, (TCHAR const*)SD_Path, 0) != FR_OK)
		{
			/* FatFs Initialization Error */
			Error_Handler();
		}
		else
		{
			/*##-3- Create a FAT file system (format) on the logical drive #########*/
			char path[2]="/";
			FRESULT res = scan_files(path, items, &items_sz);
			snprintf(buffer, sizeof(buffer), "==============================================\n");
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

			for (UINT it=0; it<items_sz; it++){
				snprintf(buffer, sizeof(buffer), "dir %x\n", items[it].dir);
				HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);
				FRESULT res = read_filename(path, items[it], buffer);
				if (res != FR_OK) continue;
				HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);
			}

			snprintf(buffer, sizeof(buffer), "==============================================\n");
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

			for (UINT it=0; it<items_sz; it++){
				FRESULT res = read_filename(path, items[it], buffer);
				if (res != FR_OK) continue;
				HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);
			}

			snprintf(buffer, sizeof(buffer), "==============================================\n");
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

			res = read_filename(path, items[10], buffer);
			if (res == FR_OK) HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

			res = read_filename(path, items[0], buffer);
			if (res == FR_OK) HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

			res = read_filename(path, items[5], buffer);
			if (res == FR_OK) HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

			snprintf(buffer, sizeof(buffer), "==============================================\n");
			HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);

		}
	}

	/*##-11- Unlink the SD disk I/O driver ####################################*/
	FATFS_UnLinkDriver(SD_Path);

  /* USER CODE END 2 */

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SD_CS_Pin */
  GPIO_InitStruct.Pin = SD_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
FRESULT scan_files (char* path, DIR* items, UINT *items_sz)        /* Start node to be scanned (***also used as work area***) */
{
	FRESULT res;
	DIR dir;
	UINT i;
	static FILINFO fno;
	char buffer[128];

	res = f_opendir(&dir, path);                       /* Open the directory */
	if (res == FR_OK) {
		items[*items_sz]=dir;
		(*items_sz)++;
		for (;;) {
			res = f_readdir(&dir, &fno);                   /* Read a directory item */

			if (res != FR_OK || fno.fname[0] == 0) break;  /* Break on error or end of dir */
//			if (fno.fattrib & AM_DIR) {                    /* It is a directory */
//				i = strlen(path);
//				sprintf(&path[i], "/%s", fno.fname);
//				res = scan_files(path, items, items_sz);     /* Enter the directory */
//				if (res != FR_OK) break;
//				path[i] = 0;
//			} else
			{                                       /* It is a file. */
				snprintf(buffer, sizeof(buffer), "%s/%s\n", path, fno.fname);
				HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);
				if (*items_sz>255) break;
				items[*items_sz]=dir;
				snprintf(buffer, sizeof(buffer), "DIR.dir pointer %x %x\n", dir.dir, items[*items_sz].dir);
				HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 0xFFFF);
				(*items_sz)++;
			}
		}
		f_closedir(&dir);
	}

	return res;
}

FRESULT read_filename(char* path, DIR target_dir, char* fname)        /* Start node to be scanned (***also used as work area***) */
{
	FRESULT res;
	DIR dir;
	UINT i;
	static FILINFO fno;
	char buffer[STRING_SZ];

	res = f_opendir(&dir, path);                       /* Open the directory */
	if (res == FR_OK) {
		res = f_readdir(&target_dir, &fno);                   /* Read a directory item */

		if (res != FR_OK || fno.fname[0] == 0) {
			fname[0]=0;
			f_closedir(&dir);
			return FR_INT_ERR;  /* Break on error or end of dir */
		}
		if (fno.fattrib & AM_DIR) {
			fname[0]=0;
			f_closedir(&dir);
			return FR_INT_ERR;
		}

		snprintf(fname, STRING_SZ, "%s/%s\n", path, fno.fname);
	}
	f_closedir(&dir);

	return res;
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
