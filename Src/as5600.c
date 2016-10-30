#include "as5600.h"

u8 as5600_buffer[16];
/**********************************
�޸�ָ���Ĵ�����һ���ֽ��е�һλ
dev �豸��ַ
reg �Ĵ�����ַ
data Ϊ0���㣬������λ
���� �ɹ�Ϊ1 
***********************************/
u8 IICwriteBit(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte(dev, reg, b));
}
u8 IICwriteBit_1(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_1(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_1(dev, reg, b));
}
u8 IICwriteBit_2(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_2(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_2(dev, reg, b));
}
u8 IICwriteBit_3(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_3(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_3(dev, reg, b));
}
u8 IICwriteBit_4(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_4(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_4(dev, reg, b));
}
u8 IICwriteBit_5(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_5(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_5(dev, reg, b));
}
u8 IICwriteBit_6(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_6(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_6(dev, reg, b));
}
u8 IICwriteBit_7(u8 dev, u8 reg, u8 bitNum, u8 data){
	u8 b;
	//��ȡָ���Ĵ�����1���ֽ�
	IIC_Read_nByte_7(dev, reg, 1, &b);

	b = (data != 0) ? (b | (1 << bitNum)) : (b & ~(1 << bitNum));
	return !(IIC_Write_1Byte_7(dev, reg, b));
}
/*********************************************
�޸�ָ���Ĵ���һ���ֽڵĶ�λ
dev �豸��ַ
reg �Ĵ�����ַ
bitstart Ŀ���ֽڵ���ʼλ
length λ����
data ��Ÿı�Ŀ���ֽ�λ��ֵ
���� �ɹ�Ϊ 1 
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
��ʼ��
���� 0�ɹ�
     1ʧ�ܣ�1������
		 2ʧ�ܣ�2������
		 3ʧ�ܣ�3������
     4ʧ�ܣ�4������
     5ʧ�ܣ�5������
     6ʧ�ܣ�6������
***********************************/

//u8 AS5600_Init()
//{
//	u8 MD;
////	I2c_Soft_Init();
//	//AS5600_SET_PWM(pwm_hz);
//	//�ų�״̬���
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
//����ΪPWM
void AS5600_SET_PWM(u8 pwm_hz)
{
	IICwriteBits(AS5600_ADDR,AS5600_CONF_L,AS5600_CONF_PWMF_BIT,AS5600_CONF_PWMF_LENGTH,pwm_hz);
	IICwriteBits(AS5600_ADDR,AS5600_CONF_L,AS5600_CONF_OUTS_BIT,AS5600_CONF_OUTS_LENGTH,AS5600_OUT_PWM);
}
//��ȡn���ֽ�	
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
��ʼλ������
���� 0�ɹ�
     1дʧ��
		 2��ʧ��
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
����ֹͣλ��
���� 0�ɹ�
     1дʧ��
     2��ʧ��
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
//��¼��ʼλ�á�����λ��
//u8 Burn_Angle_Command()
//{
//	IIC_Write_1Byte(AS5600_ADDR,AS5600_BURN,0x80);
//	delay_ms(2);
//}
//��¼�˶�
//void Burn_Angle_Check(u8 *buffer)
//{
//	delay_us(100);
//	IIC_Read_nByte(AS5600_ADDR,AS5600_ZPOS_H,4,buffer);
//}
//����  δת��
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
