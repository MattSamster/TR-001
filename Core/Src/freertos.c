/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "printf_redir.h"
#include "mpu6050.h"
#include "hip_motors.h"
#include "ankle_motors.h"
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
/* USER CODE BEGIN Variables */
mpu6050_data mpu_data;
/* USER CODE END Variables */
osThreadId mpu_taskHandle;
osThreadId printf_taskHandle;
osThreadId hip_motor_taskHandle;
osThreadId ankle_motor_tasHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void mpu(void const * argument);
void print_to_usb(void const * argument);
void hip_motor(void const * argument);
void ankle_motor(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of mpu_task */
  osThreadDef(mpu_task, mpu, osPriorityNormal, 0, 128);
  mpu_taskHandle = osThreadCreate(osThread(mpu_task), NULL);

  /* definition and creation of printf_task */
  osThreadDef(printf_task, print_to_usb, osPriorityLow, 0, 128);
  printf_taskHandle = osThreadCreate(osThread(printf_task), NULL);

  /* definition and creation of hip_motor_task */
  osThreadDef(hip_motor_task, hip_motor, osPriorityNormal, 0, 128);
  hip_motor_taskHandle = osThreadCreate(osThread(hip_motor_task), NULL);

  /* definition and creation of ankle_motor_tas */
  osThreadDef(ankle_motor_tas, ankle_motor, osPriorityNormal, 0, 128);
  ankle_motor_tasHandle = osThreadCreate(osThread(ankle_motor_tas), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_mpu */
/**
  * @brief  Function implementing the mpu_task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_mpu */
void mpu(void const * argument)
{
  /* USER CODE BEGIN mpu */
  /* Infinite loop */
  for(;;)
  {
    printf("mpu_task \r\n");
    MPU6050_update_data(&mpu_data);
  }
  /* USER CODE END mpu */
}

/* USER CODE BEGIN Header_print_to_usb */
/**
* @brief Function implementing the printf_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_print_to_usb */
void print_to_usb(void const * argument)
{
  /* USER CODE BEGIN print_to_usb */
  /* Infinite loop */
  for(;;)
  {
//    printf("accel data: \r\n");
//    printf("Ax = %4.2f \r\n", mpu_data.Ax);
//    printf("Ay = %4.2f \r\n", mpu_data.Ay);
//    printf("Az = %4.2f \r\n", mpu_data.Az);
//    printf("Gx = %4.2f \r\n", mpu_data.Gx);
//    printf("Gy = %4.2f \r\n", mpu_data.Gy);
//    printf("Gz = %4.2f \r\n", mpu_data.Gz);
  }
  /* USER CODE END print_to_usb */
}

/* USER CODE BEGIN Header_hip_motor */
/**
* @brief Function implementing the hip_motor_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_hip_motor */
void hip_motor(void const * argument)
{
  /* USER CODE BEGIN hip_motor */
  /* Infinite loop */
  for(;;)
  {
    printf("hip motor task \r\n");
  }
  /* USER CODE END hip_motor */
}

/* USER CODE BEGIN Header_ankle_motor */
/**
* @brief Function implementing the ankle_motor_tas thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ankle_motor */
void ankle_motor(void const * argument)
{
  /* USER CODE BEGIN ankle_motor */
  /* Infinite loop */
  for(;;)
  {
    printf("ankle motor task \r\n");
  }
  /* USER CODE END ankle_motor */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
