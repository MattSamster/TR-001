/**
 * @file hip_motors.h
 * @author Matthew Sam (mathcsam@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __HIP_MOTORS_H
#define __HIP_MOTORS_H

#include <stdint.h>
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "tim.h"

#ifdef CAN_EN
// const int32_t START_MOTOR = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc};
// const int32_t STOP_MOTOR = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd};
// const int32_t ZERO_POSITION = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe};
// const int32_t TORQUE_MODE = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9};
// const int32_t SPEED_MODE = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfA};
// const int32_t POSITION_MODE = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfB};
// // const int32_t  = {};

/** function prototypes **/

void hip_start_motors(void);
void hip_stop_motors(void);
void hip_zero_positions(void);
void hip_set_modes(int32_t mode);
void hip_set_position_goals(void);
void hip_set_torque_goals(void);
void hip_set_speed_goals(void);
#endif

#define PWM_EN
#ifdef PWM_EN

// for 200MHz clock, 200-1 psc, 3003-1 ARR

HAL_StatusTypeDef hip_neutral(void){
	TIM1->CCR1 = 1600;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

HAL_StatusTypeDef hip_clockwise(void){
	TIM1->CCR1 = 2000;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

HAL_StatusTypeDef hip_counterclockwise(void){
	TIM1->CCR1 = 1200;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

HAL_StatusTypeDef hip_motor_stop(void){
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}

#endif

#endif