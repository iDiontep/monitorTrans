/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    octospi.c
  * @brief   This file provides code for the configuration
  *          of the OCTOSPI instances.
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
/* Includes ------------------------------------------------------------------*/
#include "octospi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

OSPI_HandleTypeDef hospi1;
OSPI_HandleTypeDef hospi2;

/* OCTOSPI1 init function */
void MX_OCTOSPI1_Init(void)
{

  /* USER CODE BEGIN OCTOSPI1_Init 0 */

  /* USER CODE END OCTOSPI1_Init 0 */

  OSPIM_CfgTypeDef OSPIM_Cfg_Struct = {0};

  /* USER CODE BEGIN OCTOSPI1_Init 1 */

  /* USER CODE END OCTOSPI1_Init 1 */
  hospi1.Instance = OCTOSPI1;
  hospi1.Init.FifoThreshold = 1;
  hospi1.Init.DualQuad = HAL_OSPI_DUALQUAD_ENABLE;
  hospi1.Init.MemoryType = HAL_OSPI_MEMTYPE_MICRON;
  hospi1.Init.DeviceSize = 32;
  hospi1.Init.ChipSelectHighTime = 1;
  hospi1.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
  hospi1.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
  hospi1.Init.ClockPrescaler = 1;
  hospi1.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
  hospi1.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_DISABLE;
  hospi1.Init.ChipSelectBoundary = 0;
  hospi1.Init.DelayBlockBypass = HAL_OSPI_DELAY_BLOCK_BYPASSED;
  if (HAL_OSPI_Init(&hospi1) != HAL_OK)
  {
    Error_Handler();
  }
  OSPIM_Cfg_Struct.ClkPort = 1;
  OSPIM_Cfg_Struct.NCSPort = 1;
  OSPIM_Cfg_Struct.IOLowPort = HAL_OSPIM_IOPORT_1_LOW;
  OSPIM_Cfg_Struct.IOHighPort = HAL_OSPIM_IOPORT_1_HIGH;
  if (HAL_OSPIM_Config(&hospi1, &OSPIM_Cfg_Struct, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI1_Init 2 */

  /* USER CODE END OCTOSPI1_Init 2 */

}
/* OCTOSPI2 init function */
void MX_OCTOSPI2_Init(void)
{

  /* USER CODE BEGIN OCTOSPI2_Init 0 */

  /* USER CODE END OCTOSPI2_Init 0 */

  OSPIM_CfgTypeDef OSPIM_Cfg_Struct = {0};

  /* USER CODE BEGIN OCTOSPI2_Init 1 */

  /* USER CODE END OCTOSPI2_Init 1 */
  hospi2.Instance = OCTOSPI2;
  hospi2.Init.FifoThreshold = 1;
  hospi2.Init.DualQuad = HAL_OSPI_DUALQUAD_ENABLE;
  hospi2.Init.MemoryType = HAL_OSPI_MEMTYPE_MICRON;
  hospi2.Init.DeviceSize = 32;
  hospi2.Init.ChipSelectHighTime = 1;
  hospi2.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
  hospi2.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
  hospi2.Init.ClockPrescaler = 1;
  hospi2.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
  hospi2.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_DISABLE;
  hospi2.Init.ChipSelectBoundary = 0;
  hospi2.Init.DelayBlockBypass = HAL_OSPI_DELAY_BLOCK_BYPASSED;
  if (HAL_OSPI_Init(&hospi2) != HAL_OK)
  {
    Error_Handler();
  }
  OSPIM_Cfg_Struct.ClkPort = 2;
  OSPIM_Cfg_Struct.NCSPort = 2;
  OSPIM_Cfg_Struct.IOLowPort = HAL_OSPIM_IOPORT_2_LOW;
  OSPIM_Cfg_Struct.IOHighPort = HAL_OSPIM_IOPORT_2_HIGH;
  if (HAL_OSPIM_Config(&hospi2, &OSPIM_Cfg_Struct, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI2_Init 2 */

  /* USER CODE END OCTOSPI2_Init 2 */

}

static uint32_t HAL_RCC_OSPIM_CLK_ENABLED=0;

void HAL_OSPI_MspInit(OSPI_HandleTypeDef* ospiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(ospiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspInit 0 */

  /* USER CODE END OCTOSPI1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_OSPI;
    PeriphClkInit.OspiClockSelection = RCC_OSPICLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* OCTOSPI1 clock enable */
    HAL_RCC_OSPIM_CLK_ENABLED++;
    if(HAL_RCC_OSPIM_CLK_ENABLED==1){
      __HAL_RCC_OSPIM_CLK_ENABLE();
    }
    __HAL_RCC_OSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**OCTOSPI1 GPIO Configuration
    PF6     ------> OCTOSPIM_P1_IO3
    PF7     ------> OCTOSPIM_P1_IO2
    PF8     ------> OCTOSPIM_P1_IO0
    PF9     ------> OCTOSPIM_P1_IO1
    PF10     ------> OCTOSPIM_P1_CLK
    PC1     ------> OCTOSPIM_P1_IO4
    PC2     ------> OCTOSPIM_P1_IO5
    PC3     ------> OCTOSPIM_P1_IO6
    PA2     ------> OCTOSPIM_P1_NCS
    PC4     ------> OCTOSPIM_P1_IO7
    */
    GPIO_InitStruct.Pin = DATA_1_3_Pin|DATA_1_2_Pin|DATA_1_0_Pin|DATA_1_1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = DATA_1_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF3_OCTOSPIM_P1;
    HAL_GPIO_Init(DATA_1_CLK_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = DATA_1_4_Pin|DATA_1_5_Pin|DATA_1_6_Pin|DATA_1_7_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = DATA_1_CS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(DATA_1_CS_GPIO_Port, &GPIO_InitStruct);

    /* OCTOSPI1 interrupt Init */
    HAL_NVIC_SetPriority(OCTOSPI1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(OCTOSPI1_IRQn);
  /* USER CODE BEGIN OCTOSPI1_MspInit 1 */

  /* USER CODE END OCTOSPI1_MspInit 1 */
  }
  else if(ospiHandle->Instance==OCTOSPI2)
  {
  /* USER CODE BEGIN OCTOSPI2_MspInit 0 */

  /* USER CODE END OCTOSPI2_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_OSPI;
    PeriphClkInit.OspiClockSelection = RCC_OSPICLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* OCTOSPI2 clock enable */
    HAL_RCC_OSPIM_CLK_ENABLED++;
    if(HAL_RCC_OSPIM_CLK_ENABLED==1){
      __HAL_RCC_OSPIM_CLK_ENABLE();
    }
    __HAL_RCC_OSPI2_CLK_ENABLE();

    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    HAL_PWREx_EnableVddIO2();
    /**OCTOSPI2 GPIO Configuration
    PF0     ------> OCTOSPIM_P2_IO0
    PF1     ------> OCTOSPIM_P2_IO1
    PF2     ------> OCTOSPIM_P2_IO2
    PF3     ------> OCTOSPIM_P2_IO3
    PF4     ------> OCTOSPIM_P2_CLK
    PG0     ------> OCTOSPIM_P2_IO4
    PG1     ------> OCTOSPIM_P2_IO5
    PG9     ------> OCTOSPIM_P2_IO6
    PG10     ------> OCTOSPIM_P2_IO7
    PG12     ------> OCTOSPIM_P2_NCS
    */
    GPIO_InitStruct.Pin = DATA_2_0_Pin|DATA_2_1_Pin|DATA_2_2_Pin|DATA_2_3_Pin
                          |DATA_2_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_OCTOSPIM_P2;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = DATA_2_4_Pin|DATA_2_5_Pin|DATA_2_6_Pin|DATA_2_7_Pin
                          |DATA_2_CS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_OCTOSPIM_P2;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    /* OCTOSPI2 interrupt Init */
    HAL_NVIC_SetPriority(OCTOSPI2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(OCTOSPI2_IRQn);
  /* USER CODE BEGIN OCTOSPI2_MspInit 1 */

  /* USER CODE END OCTOSPI2_MspInit 1 */
  }
}

void HAL_OSPI_MspDeInit(OSPI_HandleTypeDef* ospiHandle)
{

  if(ospiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspDeInit 0 */

  /* USER CODE END OCTOSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_OSPIM_CLK_ENABLED--;
    if(HAL_RCC_OSPIM_CLK_ENABLED==0){
      __HAL_RCC_OSPIM_CLK_DISABLE();
    }
    __HAL_RCC_OSPI1_CLK_DISABLE();

    /**OCTOSPI1 GPIO Configuration
    PF6     ------> OCTOSPIM_P1_IO3
    PF7     ------> OCTOSPIM_P1_IO2
    PF8     ------> OCTOSPIM_P1_IO0
    PF9     ------> OCTOSPIM_P1_IO1
    PF10     ------> OCTOSPIM_P1_CLK
    PC1     ------> OCTOSPIM_P1_IO4
    PC2     ------> OCTOSPIM_P1_IO5
    PC3     ------> OCTOSPIM_P1_IO6
    PA2     ------> OCTOSPIM_P1_NCS
    PC4     ------> OCTOSPIM_P1_IO7
    */
    HAL_GPIO_DeInit(GPIOF, DATA_1_3_Pin|DATA_1_2_Pin|DATA_1_0_Pin|DATA_1_1_Pin
                          |DATA_1_CLK_Pin);

    HAL_GPIO_DeInit(GPIOC, DATA_1_4_Pin|DATA_1_5_Pin|DATA_1_6_Pin|DATA_1_7_Pin);

    HAL_GPIO_DeInit(DATA_1_CS_GPIO_Port, DATA_1_CS_Pin);

    /* OCTOSPI1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(OCTOSPI1_IRQn);
  /* USER CODE BEGIN OCTOSPI1_MspDeInit 1 */

  /* USER CODE END OCTOSPI1_MspDeInit 1 */
  }
  else if(ospiHandle->Instance==OCTOSPI2)
  {
  /* USER CODE BEGIN OCTOSPI2_MspDeInit 0 */

  /* USER CODE END OCTOSPI2_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_OSPIM_CLK_ENABLED--;
    if(HAL_RCC_OSPIM_CLK_ENABLED==0){
      __HAL_RCC_OSPIM_CLK_DISABLE();
    }
    __HAL_RCC_OSPI2_CLK_DISABLE();

    /**OCTOSPI2 GPIO Configuration
    PF0     ------> OCTOSPIM_P2_IO0
    PF1     ------> OCTOSPIM_P2_IO1
    PF2     ------> OCTOSPIM_P2_IO2
    PF3     ------> OCTOSPIM_P2_IO3
    PF4     ------> OCTOSPIM_P2_CLK
    PG0     ------> OCTOSPIM_P2_IO4
    PG1     ------> OCTOSPIM_P2_IO5
    PG9     ------> OCTOSPIM_P2_IO6
    PG10     ------> OCTOSPIM_P2_IO7
    PG12     ------> OCTOSPIM_P2_NCS
    */
    HAL_GPIO_DeInit(GPIOF, DATA_2_0_Pin|DATA_2_1_Pin|DATA_2_2_Pin|DATA_2_3_Pin
                          |DATA_2_CLK_Pin);

    HAL_GPIO_DeInit(GPIOG, DATA_2_4_Pin|DATA_2_5_Pin|DATA_2_6_Pin|DATA_2_7_Pin
                          |DATA_2_CS_Pin);

    /* OCTOSPI2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(OCTOSPI2_IRQn);
  /* USER CODE BEGIN OCTOSPI2_MspDeInit 1 */

  /* USER CODE END OCTOSPI2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
