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

#include "i2c.h"
#include <stdint.h>

/** define register values **/
#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x751

/**
 * @brief struct for holding MPU data
 * 
 */
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

/**
 * @brief 
 * 
 */
void MPU6050_Init (void)
{
	uint8_t check;
	uint8_t Data;

	// check device ID WHO_AM_I
	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, 0x75, 1, &check, 1, 1000);
	if (check == 0x68)  // 0x68 will be returned by the sensor if everything goes well
	{
		// power management register 0X6B we should write all 0's to wake the sensor up
		Data = 0;
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, 0x6B, 1,&Data, 1, 1000);

		// Set DATA RATE of 1KHz by writing SMPLRT_DIV register
		Data = 0x07;
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, 0x19, 1, &Data, 1, 1000);

		// Set Gyroscopic configuration in GYRO_CONFIG Register
		Data = 0x00;  // XG_ST=0,YG_ST=0,ZG_ST=0, FS_SEL=0 -> ± 250 ̐/s
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, 0x1B, 1, &Data, 1, 1000);

		// Set accelerometer configuration in ACCEL_CONFIG Register
		Data = 0x00;  // XA_ST=0,YA_ST=0,ZA_ST=0, FS_SEL=0 -> ± 2g
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, 0x1C, 1, &Data, 1, 1000);
	}

}

/**
 * @brief 
 * 
 */
void MPU6050_Read_Accel (mpu6050_data *mpu_data)
{
	uint8_t Rec_Data[6];

	// Read 6 BYTES of data starting from ACCEL_XOUT_H (0x3B) register
	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, 0x3B, 1, Rec_Data, 6, 1000);

	mpu_data->Accel_X_RAW = (uint16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	mpu_data->Accel_Y_RAW = (uint16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	mpu_data->Accel_Z_RAW = (uint16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	mpu_data->Ax = (float)mpu_data->Accel_X_RAW/16384.0;
	mpu_data->Ay = (float)mpu_data->Accel_Y_RAW/16384.0;
	mpu_data->Az = (float)mpu_data->Accel_Z_RAW/16384.0;
}

/**
 * @brief 
 * 
 */
void MPU6050_Read_Gyro (mpu6050_data *mpu_data)
{
	uint8_t Rec_Data[6];

	// Read 6 BYTES of data starting from GYRO_XOUT_H register
	HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, 0x43, 1, Rec_Data, 6, 1000);

	mpu_data->Gyro_X_RAW = (uint16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	mpu_data->Gyro_Y_RAW = (uint16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	mpu_data->Gyro_Z_RAW = (uint16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	mpu_data->Gx = (float)mpu_data->Gyro_X_RAW/131.0;
	mpu_data->Gy = (float)mpu_data->Gyro_Y_RAW/131.0;
	mpu_data->Gz = (float)mpu_data->Gyro_Z_RAW/131.0;
}

void MPU6050_update_data(mpu6050_data *mpu_data){
      MPU6050_Read_Accel(mpu_data);
      MPU6050_Read_Gyro(mpu_data);
}

#endif
