/**
 * @file mpu6050.h
 * @author Matthew Sam (mathcsam@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __MPU6050_H
#define __MPU6050_H

typedef struct mpu6050_data
{
    uint16_t Accel_X_RAW;
    uint16_t Accel_Y_RAW;
    uint16_t Accel_Z_RAW;

    uint16_t Gyro_X_RAW;
    uint16_t Gyro_Y_RAW;
    uint16_t Gyro_Z_RAW;

    float Ax;
    float Ay;
    float Az;
    float Gx;
    float Gy;
    float Gz;

}mpu6050_data;

void MPU6050_Init (void);
void MPU6050_Read_Accel (mpu6050_data *mpu_data);
void MPU6050_Read_Gyro (mpu6050_data *mpu_data);
void MPU6050_update_data (mpu6050_data *mpu_data);


#endif
