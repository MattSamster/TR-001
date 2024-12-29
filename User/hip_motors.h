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