#include "as5600.h"

u8 as5600_buffer[16];
/**********************************
修改指定寄存器的一个字节中的一位
dev 设备地址
reg 寄存器地址
data 为0清零，否则置位
返回 成功为1 
***********************************/
u8 IICwriteBit(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte(dev, reg, b));
}
u8 IICwriteBit_1(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_1(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_1(dev, reg, b));
}
u8 IICwriteBit_2(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_2(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_2(dev, reg, b));
}
u8 IICwriteBit_3(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_3(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_3(dev, reg, b));
}
u8 IICwriteBit_4(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_4(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_4(dev, reg, b));
}
u8 IICwriteBit_5(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_5(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_5(dev, reg, b));
}
u8 IICwriteBit_6(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_6(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_6(dev, reg, b));
}
u8 IICwriteBit_7(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//读取指定寄存器的1个字节
	IIC_Read_nByte_7(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_7(dev, reg, b));
}
/*********************************************
修改指定寄存器一个字节的多位
dev 设备地址
reg 寄存器地址
bitstart 目标字节的起始位
length 位长度
data 存放改变目标字节位的值
返回 成功为 1 
**********************************************/
u8 IICwriteBits(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte(dev, reg, b));
}
u8 IICwriteBits_1(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_1(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_1(dev, reg, b));
}
u8 IICwriteBits_2(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_2(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_2(dev, reg, b));
}
u8 IICwriteBits_3(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_3(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_3(dev, reg, b));
}
u8 IICwriteBits_4(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_4(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_4(dev, reg, b));
}
u8 IICwriteBits_5(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_5(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_5(dev, reg, b));
}
u8 IICwriteBits_6(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_6(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_6(dev, reg, b));
}
u8 IICwriteBits_7(u8 dev,u8 reg,u8 bitStart,u8 length,u8 data)
{
	
	u8 b,mask;
	IIC_Read_nByte_7(dev, reg, 1, &b);
	mask = (0xFF << (bitStart + 1)) | 0xFF >> ((8 - bitStart) + length - 1);
	data <<= (8 - length);
	data >>= (7 - bitStart);
	b &= mask;
	b |= data;
	return !(IIC_Write_1Byte_7(dev, reg, b));
}
/**********************************
初始化
返回 0成功
     1失败（1磁铁）
		 2失败（2磁铁）
		 3失败（3磁铁）
     4失败（4磁铁）
     5失败（5磁铁）
     6失败（6磁铁）
***********************************/

//u8 AS5600_Init()
//{
//	u8 MD;
////	I2c_Soft_Init();
//	//AS5600_SET_PWM(pwm_hz);
//	//磁场状态检查
//	IIC_Read_1Byte(AS5600_ADDR,AS5600_STATUS,&MD);
//	if((MD&0x20)==SET)
//	{
//		IIC_Read_1Byte_1(AS5600_ADDR,AS5600_STATUS,&MD);
//		if((MD&0x20)==SET)
//		{
//			IIC_Read_1Byte_2(AS5600_ADDR,AS5600_STATUS,&MD);
//			if((MD&0x20)==SET)
//			{
//				IIC_Read_1Byte_3(AS5600_ADDR,AS5600_STATUS,&MD);
//				if((MD&0x20)==SET)
//				{
//					IIC_Read_1Byte_4(AS5600_ADDR,AS5600_STATUS,&MD);
//					if((MD&0x20)==SET)
//					{
//						IIC_Read_1Byte_5(AS5600_ADDR,AS5600_STATUS,&MD);
//						if((MD&0x20)==SET) return 0;
//						else return 6;
//					}
//					else return 5;
//				}
//				else return 4;
//			}
//			else return 3;
//		}
//		else return 2;
//	}
//	else return 1;

//}
//配置为PWM
void AS5600_SET_PWM(u8 pwm_hz)
{
	IICwriteBits(AS5600_ADDR,AS5600_CONF_L,AS5600_CONF_PWMF_BIT,AS5600_CONF_PWMF_LENGTH,pwm_hz);
	IICwriteBits(AS5600_ADDR,AS5600_CONF_L,AS5600_CONF_OUTS_BIT,AS5600_CONF_OUTS_LENGTH,AS5600_OUT_PWM);
}
//读取n个字节	
void AS5600_Angle_Read()
{
	IIC_Read_nByte(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer);
	IIC_Read_nByte_1(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+2);
	IIC_Read_nByte_2(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+4);
	IIC_Read_nByte_3(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+6);
    IIC_Read_nByte_4(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+8);
	IIC_Read_nByte_5(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+10);
	IIC_Read_nByte_5(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+12);
	IIC_Read_nByte_5(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,as5600_buffer+14);
}

/*****************************************
Angle programming ZPOS
起始位置设置
返回 0成功
     1写失败
		 2读失败
******************************************/
//u8 Angle_Pro_ZPOS()
//{
//	u8 Raw_Angle[2];
//	delay_us(10);
//	if((IIC_Read_nByte(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,Raw_Angle))==RESET)
//	{
//		delay_us(10);
//		if((IIC_Write_nByte(AS5600_ADDR,AS5600_ZPOS_H,2,Raw_Angle))==RESET)
//		{
//			delay_ms(2);
//			return 0;
//		}
//		else return 1;
//	}
//	else return 2;
//}
/***************************
Angle_Pro_MPOS
配置停止位置
返回 0成功
     1写失败
     2读失败
****************************/
//u8 Angle_Pro_MPOS()
//{
//	u8 Raw_Angle[2];
//	delay_us(10);
//	if((IIC_Read_nByte(AS5600_ADDR,AS5600_RAW_ANGLE_H,2,Raw_Angle))==RESET)
//	{
//		delay_us(10);
//		if((IIC_Write_nByte(AS5600_ADDR,AS5600_MPOS_H,2,Raw_Angle))==RESET)
//		{
//			delay_ms(2);
//			return 0;
//		}
//		else return 1;
//	}
//	else return 2;
//}
//烧录起始位置、结束位置
//u8 Burn_Angle_Command()
//{
//	IIC_Write_1Byte(AS5600_ADDR,AS5600_BURN,0x80);
//	delay_ms(2);
//}
//烧录核对
//void Burn_Angle_Check(u8 *buffer)
//{
//	delay_us(100);
//	IIC_Read_nByte(AS5600_ADDR,AS5600_ZPOS_H,4,buffer);
//}
//数据  未转换
void AS5600_Data(uint16_t *RawAngle)
{
	
	AS5600_Angle_Read();
	*(RawAngle)=((((uint16_t)as5600_buffer[0])<<8)|as5600_buffer[1]);
	*(RawAngle+1)=((((uint16_t)as5600_buffer[2])<<8)|as5600_buffer[3]);
	*(RawAngle+2)=((((uint16_t)as5600_buffer[4])<<8)|as5600_buffer[5]);
	*(RawAngle+3)=((((uint16_t)as5600_buffer[6])<<8)|as5600_buffer[7]);
	*(RawAngle+4)=((((uint16_t)as5600_buffer[8])<<8)|as5600_buffer[9]);
	*(RawAngle+5)=((((uint16_t)as5600_buffer[10])<<8)|as5600_buffer[11]);
	*(RawAngle+6)=((((uint16_t)as5600_buffer[12])<<8)|as5600_buffer[13]);
	*(RawAngle+7)=((((uint16_t)as5600_buffer[14])<<8)|as5600_buffer[15]);
}
void AS5600_DaTa_Angle(u16 *Angle)
{
	u8 i;
	uint16_t RawAngle[8];
	AS5600_Data(RawAngle);
	for(i=0;i<8;i++)
	{
		*(Angle+i)=RawAngle[i]*0.08789*100;
	}
}
