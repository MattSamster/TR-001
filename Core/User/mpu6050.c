/**
 * @file mpu6050.c
 * @author Matthew Sam (mathcsam@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdint.h>
#include "mpu6050.h"
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75

extern mpu6050_data mpu_data;
mpu6050_data mpu_data;

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
void MPU6050_Read_Accel (void)
{
	uint8_t Rec_Data[6];

	// Read 6 BYTES of data starting from ACCEL_XOUT_H (0x3B) register
	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, 0x3B, 1, Rec_Data, 6, 1000);

	mpu_data.Accel_X_RAW = (uint16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	mpu_data.Accel_Y_RAW = (uint16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	mpu_data.Accel_Z_RAW = (uint16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	/*** convert the RAW values into acceleration in 'g'
	     we have to divide according to the Full scale value set in FS_SEL
	     I have configured FS_SEL = 0. So I am dividing by 16384.0
	     for more details check ACCEL_CONFIG Register              ****/

	mpu_data.Ax = (float)mpu_data.Accel_X_RAW/16384.0;
	mpu_data.Ay = (float)mpu_data.Accel_Y_RAW/16384.0;
	mpu_data.Az = (float)mpu_data.Accel_Z_RAW/16384.0;
}

/**
 * @brief 
 * 
 */
void MPU6050_Read_Gyro (void)
{
	uint8_t Rec_Data[6];

	// Read 6 BYTES of data starting from GYRO_XOUT_H register
	HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, 0x43, 1, Rec_Data, 6, 1000);

	mpu_data.Gyro_X_RAW = (uint16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	mpu_data.Gyro_Y_RAW = (uint16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	mpu_data.Gyro_Z_RAW = (uint16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	/*** convert the RAW values into dps (ｰ/s)
	     we have to divide according to the Full scale value set in FS_SEL
	     I have configured FS_SEL = 0. So I am dividing by 131.0
	     for more details check GYRO_CONFIG Register              ****/

	mpu_data.Gx = (float)mpu_data.Gyro_X_RAW/131.0;
	mpu_data.Gy = (float)mpu_data.Gyro_Y_RAW/131.0;
	mpu_data.Gz = (float)mpu_data.Gyro_Z_RAW/131.0;
}

/**
 * @brief 
 * 
 */
void MPU6050_update_data(void){

    MPU6050_Read_Accel();
    MPU6050_Read_Gyro();

}
