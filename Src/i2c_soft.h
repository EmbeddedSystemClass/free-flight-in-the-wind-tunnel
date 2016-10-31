#ifndef _I2C_SOFT_H
#define	_I2C_SOFT_H

#include "stm32f4xx_hal.h"


typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;



#define SCL_H         ANO_GPIO_I2C->BSRRL = I2C_Pin_SCL
#define SCL_L         ANO_GPIO_I2C->BSRRH = I2C_Pin_SCL
#define SDA_H         ANO_GPIO_I2C->BSRRL = I2C_Pin_SDA
#define SDA_L         ANO_GPIO_I2C->BSRRH = I2C_Pin_SDA
#define SCL_read      ANO_GPIO_I2C->IDR  & I2C_Pin_SCL
#define SDA_read      ANO_GPIO_I2C->IDR  & I2C_Pin_SDA

#define SCL_H_1       ANO_GPIO_I2C->BSRRL = I2C_Pin_SCL_1
#define SCL_L_1       ANO_GPIO_I2C->BSRRH = I2C_Pin_SCL_1
#define SDA_H_1       ANO_GPIO_I2C->BSRRL = I2C_Pin_SDA_1
#define SDA_L_1       ANO_GPIO_I2C->BSRRH = I2C_Pin_SDA_1
#define SCL_read_1    ANO_GPIO_I2C->IDR  & I2C_Pin_SCL_1
#define SDA_read_1    ANO_GPIO_I2C->IDR  & I2C_Pin_SDA_1

#define SCL_H_2       ANO_GPIO_I2C_1->BSRRL = I2C_Pin_SCL_2
#define SCL_L_2       ANO_GPIO_I2C_1->BSRRH = I2C_Pin_SCL_2
#define SDA_H_2       ANO_GPIO_I2C_1->BSRRL = I2C_Pin_SDA_2
#define SDA_L_2       ANO_GPIO_I2C_1->BSRRH = I2C_Pin_SDA_2
#define SCL_read_2    ANO_GPIO_I2C_1->IDR  & I2C_Pin_SCL_2
#define SDA_read_2    ANO_GPIO_I2C_1->IDR  & I2C_Pin_SDA_2

#define SCL_H_3       ANO_GPIO_I2C_2->BSRRL = I2C_Pin_SCL_3
#define SCL_L_3       ANO_GPIO_I2C_2->BSRRH = I2C_Pin_SCL_3
#define SDA_H_3       ANO_GPIO_I2C_2->BSRRL = I2C_Pin_SDA_3
#define SDA_L_3       ANO_GPIO_I2C_2->BSRRH = I2C_Pin_SDA_3
#define SCL_read_3    ANO_GPIO_I2C_2->IDR  & I2C_Pin_SCL_3
#define SDA_read_3    ANO_GPIO_I2C_2->IDR  & I2C_Pin_SDA_3

#define SCL_H_4       ANO_GPIO_I2C->BSRRL = I2C_Pin_SCL_4
#define SCL_L_4       ANO_GPIO_I2C->BSRRH = I2C_Pin_SCL_4
#define SDA_H_4       ANO_GPIO_I2C->BSRRL = I2C_Pin_SDA_4
#define SDA_L_4       ANO_GPIO_I2C->BSRRH = I2C_Pin_SDA_4
#define SCL_read_4    ANO_GPIO_I2C->IDR  & I2C_Pin_SCL_4
#define SDA_read_4    ANO_GPIO_I2C->IDR  & I2C_Pin_SDA_4

#define SCL_H_5       ANO_GPIO_I2C->BSRRL = I2C_Pin_SCL_5
#define SCL_L_5       ANO_GPIO_I2C->BSRRH = I2C_Pin_SCL_5
#define SDA_H_5       ANO_GPIO_I2C->BSRRL = I2C_Pin_SDA_5
#define SDA_L_5       ANO_GPIO_I2C->BSRRH = I2C_Pin_SDA_5
#define SCL_read_5    ANO_GPIO_I2C->IDR  & I2C_Pin_SCL_5
#define SDA_read_5    ANO_GPIO_I2C->IDR  & I2C_Pin_SDA_5

#define SCL_H_6       ANO_GPIO_I2C->BSRRL = I2C_Pin_SCL_6
#define SCL_L_6       ANO_GPIO_I2C->BSRRH = I2C_Pin_SCL_6
#define SDA_H_6       ANO_GPIO_I2C->BSRRL = I2C_Pin_SDA_6
#define SDA_L_6       ANO_GPIO_I2C->BSRRH = I2C_Pin_SDA_6
#define SCL_read_6    ANO_GPIO_I2C->IDR  & I2C_Pin_SCL_6
#define SDA_read_6    ANO_GPIO_I2C->IDR  & I2C_Pin_SDA_6

#define SCL_H_7       ANO_GPIO_I2C->BSRRL = I2C_Pin_SCL_7
#define SCL_L_7       ANO_GPIO_I2C->BSRRH = I2C_Pin_SCL_7
#define SDA_H_7       ANO_GPIO_I2C->BSRRL = I2C_Pin_SDA_7
#define SDA_L_7       ANO_GPIO_I2C->BSRRH = I2C_Pin_SDA_7
#define SCL_read_7    ANO_GPIO_I2C->IDR  & I2C_Pin_SCL_7
#define SDA_read_7    ANO_GPIO_I2C->IDR  & I2C_Pin_SDA_7
/***************I2C GPIO∂®“Â******************/
#define ANO_GPIO_I2C	GPIOD
#define ANO_GPIO_I2C_1  GPIOC
#define ANO_GPIO_I2C_2  GPIOB
//#define ANO_GPIO_I2C_1 GPIOB
//#define ANO_GPIO_I2C_2 GPIOB
//#define ANO_GPIO_I2C_3 GPIOG
//#define ANO_GPIO_I2C_4 GPIOG
//#define ANO_GPIO_I2C_5 GPIOG
#define I2C_Pin_SCL	  GPIO_PIN_0
#define I2C_Pin_SCL_1 GPIO_PIN_3
#define I2C_Pin_SCL_2 GPIO_PIN_10
#define I2C_Pin_SCL_3 GPIO_PIN_8
#define I2C_Pin_SCL_4 GPIO_PIN_8
#define I2C_Pin_SCL_5 GPIO_PIN_10
#define I2C_Pin_SCL_6 GPIO_PIN_12
#define I2C_Pin_SCL_7 GPIO_PIN_14
#define I2C_Pin_SDA		GPIO_PIN_1
#define I2C_Pin_SDA_1	GPIO_PIN_4
#define I2C_Pin_SDA_2	GPIO_PIN_11
#define I2C_Pin_SDA_3	GPIO_PIN_9
#define I2C_Pin_SDA_4	GPIO_PIN_9
#define I2C_Pin_SDA_5	GPIO_PIN_11
#define I2C_Pin_SDA_6   GPIO_PIN_13
#define I2C_Pin_SDA_7   GPIO_PIN_15

//#define ANO_RCC_I2C		RCC_AHB1Periph_GPIOB
////#define ANO_RCC_I2C_1	RCC_AHB1Periph_GPIOB
////#define ANO_RCC_I2C_2	RCC_AHB1Periph_GPIOB
////#define ANO_RCC_I2C_3	RCC_AHB1Periph_GPIOG
////#define ANO_RCC_I2C_4	RCC_AHB1Periph_GPIOG
////#define ANO_RCC_I2C_5	RCC_AHB1Periph_GPIOG
//#define ANO_RCC_I2C_1		RCC_AHB1Periph_GPIOG
/*********************************************/
extern volatile u8 I2C_FastMode;

//void I2c_Soft_Init(void);
void I2c_Soft_SendByte(u8 SendByte);
void I2c_Soft_SendByte_1(u8 SendByte);
void I2c_Soft_SendByte_2(u8 SendByte);
void I2c_Soft_SendByte_3(u8 SendByte);
void I2c_Soft_SendByte_4(u8 SendByte);
void I2c_Soft_SendByte_5(u8 SendByte);
void I2c_Soft_SendByte_6(u8 SendByte);
void I2c_Soft_SendByte_7(u8 SendByte);

u8 I2c_Soft_ReadByte(u8);
u8 I2c_Soft_ReadByte_1(u8);
u8 I2c_Soft_ReadByte_2(u8);
u8 I2c_Soft_ReadByte_3(u8);
u8 I2c_Soft_ReadByte_4(u8);
u8 I2c_Soft_ReadByte_5(u8);
u8 I2c_Soft_ReadByte_6(u8);
u8 I2c_Soft_ReadByte_7(u8);
//int I2c_Soft_Single_Write(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
//int I2c_Soft_Single_Read(u8 SlaveAddress,u8 REG_Address);
//int I2c_Soft_Mult_Read(u8 SlaveAddress,u8 REG_Address,u8 * ptChar,u8 size);

u8 IIC_Write_1Byte(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_1(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_2(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_3(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_4(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_5(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_6(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
u8 IIC_Write_1Byte_7(u8 SlaveAddress,u8 REG_Address,u8 REG_data);

u8 IIC_Read_1Byte(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_1(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_2(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_3(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_4(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_5(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_6(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);
u8 IIC_Read_1Byte_7(u8 SlaveAddress,u8 REG_Address,u8 *REG_data);

u8 IIC_Write_nByte(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_1(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_2(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_3(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_4(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_5(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_6(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Write_nByte_7(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);


u8 IIC_Read_nByte(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_1(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_2(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_3(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_4(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_5(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_6(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
u8 IIC_Read_nByte_7(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
#endif
