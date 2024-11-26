/**
 * @file ankle_motors.h
 * @author Matthew Sam (mathcsam@gmail.com)
 * @brief driver for dynamixel
 * @version 0.1
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __ANKLE_MOTORS_H
#define __ANKLE_MOTORS_H

#include "main.h"
#include "string.h"
#include "stdio.h"

void hip_start_motors(void)
{

}

void hip_stop_motors(void)
{

}

void hip_zero_positions(void)
{

}

void hip_set_modes(int32_t mode)
{

}

void hip_set_position_goals(void)
{
    // ex. 0x95 00 10 49 40 B8 0B 00 --> 180degree 3s, 00 10 49 40 (LSB IEEE 754) = 180, B8 0B 00 (LSB) = 3000 = (000BB8 MSB)
    
}

void hip_set_torque_goals(void)
{
    // ex. 0x93 CC CC 7C 41 B8 0B 00 --> 15.8Nm 3s, CC CC 7C 41 (LSB IEEE 754) = 15.8, B8 0B 00 (LSB) = 3000 = (000BB8 MSB)

}

void hip_set_speed_goals(void)
{
    // ex. 0x94 00 00 4A 42 B8 0B 00 --> 50.5RPM 3s 00 00 4A 42 (LSB IEEE 754) = 50.5, B8 0B 00 (LSB) = 3000 = (000BB8 MSB)

}

#endif