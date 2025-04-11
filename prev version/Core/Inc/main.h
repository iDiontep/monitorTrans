/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32l4xx_hal.h"

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
#define DATA_2_0_Pin GPIO_PIN_0
#define DATA_2_0_GPIO_Port GPIOF
#define DATA_2_1_Pin GPIO_PIN_1
#define DATA_2_1_GPIO_Port GPIOF
#define DATA_2_2_Pin GPIO_PIN_2
#define DATA_2_2_GPIO_Port GPIOF
#define DATA_2_3_Pin GPIO_PIN_3
#define DATA_2_3_GPIO_Port GPIOF
#define DATA_2_CLK_Pin GPIO_PIN_4
#define DATA_2_CLK_GPIO_Port GPIOF
#define DATA_1_3_Pin GPIO_PIN_6
#define DATA_1_3_GPIO_Port GPIOF
#define DATA_1_2_Pin GPIO_PIN_7
#define DATA_1_2_GPIO_Port GPIOF
#define DATA_1_0_Pin GPIO_PIN_8
#define DATA_1_0_GPIO_Port GPIOF
#define DATA_1_1_Pin GPIO_PIN_9
#define DATA_1_1_GPIO_Port GPIOF
#define DATA_1_CLK_Pin GPIO_PIN_10
#define DATA_1_CLK_GPIO_Port GPIOF
#define DATA_1_4_Pin GPIO_PIN_1
#define DATA_1_4_GPIO_Port GPIOC
#define DATA_1_5_Pin GPIO_PIN_2
#define DATA_1_5_GPIO_Port GPIOC
#define DATA_1_6_Pin GPIO_PIN_3
#define DATA_1_6_GPIO_Port GPIOC
#define DATA_1_CS_Pin GPIO_PIN_2
#define DATA_1_CS_GPIO_Port GPIOA
#define DATA_1_7_Pin GPIO_PIN_4
#define DATA_1_7_GPIO_Port GPIOC
#define DATA_2_4_Pin GPIO_PIN_0
#define DATA_2_4_GPIO_Port GPIOG
#define DATA_2_5_Pin GPIO_PIN_1
#define DATA_2_5_GPIO_Port GPIOG
#define touch_RESET_Pin GPIO_PIN_13
#define touch_RESET_GPIO_Port GPIOD
#define touch_INT_Pin GPIO_PIN_6
#define touch_INT_GPIO_Port GPIOG
#define touch_SCL_Pin GPIO_PIN_7
#define touch_SCL_GPIO_Port GPIOG
#define touch_SDA_Pin GPIO_PIN_8
#define touch_SDA_GPIO_Port GPIOG
#define USART1_REDE_Pin GPIO_PIN_8
#define USART1_REDE_GPIO_Port GPIOA
#define USART1_PV_Pin GPIO_PIN_11
#define USART1_PV_GPIO_Port GPIOA
#define DATA_2_6_Pin GPIO_PIN_9
#define DATA_2_6_GPIO_Port GPIOG
#define DATA_2_7_Pin GPIO_PIN_10
#define DATA_2_7_GPIO_Port GPIOG
#define DATA_2_CS_Pin GPIO_PIN_12
#define DATA_2_CS_GPIO_Port GPIOG

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
