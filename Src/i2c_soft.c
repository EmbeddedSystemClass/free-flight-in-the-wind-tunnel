/******************** (C) COPYRIGHT 2014 ANO Tech ********************************

**********************************************************************************/
#include "i2c_soft.h"

volatile u8 I2C_FastMode;

void I2c_Soft_delay()
{ 
	__nop();__nop();__nop();
	__nop();__nop();__nop();
	__nop();__nop();__nop();
	
	if(!I2C_FastMode)
	{
		u8 i = 15;
		while(i--);
	}
}

//void I2c_Soft_Init()
//{
//  GPIO_InitTypeDef  GPIO_InitStructure; 
//  RCC_AHB1PeriphClockCmd(ANO_RCC_I2C , ENABLE );
//	RCC_AHB1PeriphClockCmd(ANO_RCC_I2C_1 , ENABLE );
//  GPIO_InitStructure.GPIO_Pin =  I2C_Pin_SCL | I2C_Pin_SDA| I2C_Pin_SCL_1 | I2C_Pin_SDA_1|I2C_Pin_SCL_2 | I2C_Pin_SDA_2;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//输出
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//无上下拉
//  GPIO_Init(ANO_GPIO_I2C, &GPIO_InitStructure);		
//	GPIO_InitStructure.GPIO_Pin = I2C_Pin_SCL_3|I2C_Pin_SCL_4 | I2C_Pin_SDA_4|I2C_Pin_SCL_5 | I2C_Pin_SDA_5|I2C_Pin_SDA_3;
//	GPIO_Init(ANO_GPIO_I2C_1, &GPIO_InitStructure);		
//}

int I2c_Soft_Start()
{
	SDA_H;
	SCL_H;
	I2c_Soft_delay();
	if(!SDA_read)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L;
	I2c_Soft_delay();
	if(SDA_read) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L;
	I2c_Soft_delay();
	return 1;	
}
int I2c_Soft_Start_1()
{
	SDA_H_1;
	SCL_H_1;
	I2c_Soft_delay();
	if(!SDA_read_1)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_1;
	I2c_Soft_delay();
	if(SDA_read_1) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_1;
	I2c_Soft_delay();
	return 1;	
}
int I2c_Soft_Start_2()
{
	SDA_H_2;
	SCL_H_2;
	I2c_Soft_delay();
	if(!SDA_read_2)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_2;
	I2c_Soft_delay();
	if(SDA_read_2) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_2;
	I2c_Soft_delay();
	return 1;	
}
int I2c_Soft_Start_3()
{
	SDA_H_3;
	SCL_H_3;
	I2c_Soft_delay();
	if(!SDA_read_3)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_3;
	I2c_Soft_delay();
	if(SDA_read_3) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_3;
	I2c_Soft_delay();
	return 1;	
}
int I2c_Soft_Start_4()
{
	SDA_H_4;
	SCL_H_4;
	I2c_Soft_delay();
	if(!SDA_read_4)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_4;
	I2c_Soft_delay();
	if(SDA_read_4) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_4;
	I2c_Soft_delay();
	return 1;	
}
int I2c_Soft_Start_5()
{
	SDA_H_5;
	SCL_H_5;
	I2c_Soft_delay();
	if(!SDA_read_5)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_5;
	I2c_Soft_delay();
	if(SDA_read_5) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_5;
	I2c_Soft_delay();
	return 1;	
}

int I2c_Soft_Start_6()
{
	SDA_H_6;
	SCL_H_6;
	I2c_Soft_delay();
	if(!SDA_read_6)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_6;
	I2c_Soft_delay();
	if(SDA_read_6) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_6;
	I2c_Soft_delay();
	return 1;	
}

int I2c_Soft_Start_7()
{
	SDA_H_7;
	SCL_H_7;
	I2c_Soft_delay();
	if(!SDA_read_7)return 0;	//SDA线为低电平则总线忙,退出
	SDA_L_7;
	I2c_Soft_delay();
	if(SDA_read_7) return 0;	//SDA线为高电平则总线出错,退出
	SDA_L_7;
	I2c_Soft_delay();
	return 1;	
}

void I2c_Soft_Stop()
{
	SCL_L;
	I2c_Soft_delay();
	SDA_L;
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	SDA_H;
	I2c_Soft_delay();
}
void I2c_Soft_Stop_1()
{
	SCL_L_1;
	I2c_Soft_delay();
	SDA_L_1;
	I2c_Soft_delay();
	SCL_H_1;
	I2c_Soft_delay();
	SDA_H_1;
	I2c_Soft_delay();
}
void I2c_Soft_Stop_2()
{
	SCL_L_2;
	I2c_Soft_delay();
	SDA_L_2;
	I2c_Soft_delay();
	SCL_H_2;
	I2c_Soft_delay();
	SDA_H_2;
	I2c_Soft_delay();
}
void I2c_Soft_Stop_3()
{
	SCL_L_3;
	I2c_Soft_delay();
	SDA_L_3;
	I2c_Soft_delay();
	SCL_H_3;
	I2c_Soft_delay();
	SDA_H_3;
	I2c_Soft_delay();
}
void I2c_Soft_Stop_4()
{
	SCL_L_4;
	I2c_Soft_delay();
	SDA_L_4;
	I2c_Soft_delay();
	SCL_H_4;
	I2c_Soft_delay();
	SDA_H_4;
	I2c_Soft_delay();
}
void I2c_Soft_Stop_5()
{
	SCL_L_5;
	I2c_Soft_delay();
	SDA_L_5;
	I2c_Soft_delay();
	SCL_H_5;
	I2c_Soft_delay();
	SDA_H_5;
	I2c_Soft_delay();
}

void I2c_Soft_Stop_6()
{
	SCL_L_6;
	I2c_Soft_delay();
	SDA_L_6;
	I2c_Soft_delay();
	SCL_H_6;
	I2c_Soft_delay();
	SDA_H_6;
	I2c_Soft_delay();
}
void I2c_Soft_Stop_7()
{
	SCL_L_7;
	I2c_Soft_delay();
	SDA_L_7;
	I2c_Soft_delay();
	SCL_H_7;
	I2c_Soft_delay();
	SDA_H_7;
	I2c_Soft_delay();
}

void I2c_Soft_Ask()
{
	SCL_L;
	I2c_Soft_delay();
	SDA_L;
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	SCL_L;
	I2c_Soft_delay();
}
void I2c_Soft_Ask_1()
{
	SCL_L_1;
	I2c_Soft_delay();
	SDA_L_1;
	I2c_Soft_delay();
	SCL_H_1;
	I2c_Soft_delay();
	SCL_L_1;
	I2c_Soft_delay();
}
void I2c_Soft_Ask_2()
{
	SCL_L_2;
	I2c_Soft_delay();
	SDA_L_2;
	I2c_Soft_delay();
	SCL_H_2;
	I2c_Soft_delay();
	SCL_L_2;
	I2c_Soft_delay();
}
void I2c_Soft_Ask_3()
{
	SCL_L_3;
	I2c_Soft_delay();
	SDA_L_3;
	I2c_Soft_delay();
	SCL_H_3;
	I2c_Soft_delay();
	SCL_L_3;
	I2c_Soft_delay();
}
void I2c_Soft_Ask_4()
{
	SCL_L_4;
	I2c_Soft_delay();
	SDA_L_4;
	I2c_Soft_delay();
	SCL_H_4;
	I2c_Soft_delay();
	SCL_L_4;
	I2c_Soft_delay();
}
void I2c_Soft_Ask_5()
{
	SCL_L_5;
	I2c_Soft_delay();
	SDA_L_5;
	I2c_Soft_delay();
	SCL_H_5;
	I2c_Soft_delay();
	SCL_L_5;
	I2c_Soft_delay();
}

void I2c_Soft_Ask_6()
{
	SCL_L_6;
	I2c_Soft_delay();
	SDA_L_6;
	I2c_Soft_delay();
	SCL_H_6;
	I2c_Soft_delay();
	SCL_L_6;
	I2c_Soft_delay();
}
void I2c_Soft_Ask_7()
{
	SCL_L_7;
	I2c_Soft_delay();
	SDA_L_7;
	I2c_Soft_delay();
	SCL_H_7;
	I2c_Soft_delay();
	SCL_L_7;
	I2c_Soft_delay();
}


void I2c_Soft_NoAsk()
{
	SCL_L;
	I2c_Soft_delay();
	SDA_H;
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	SCL_L;
	I2c_Soft_delay();
}
void I2c_Soft_NoAsk_1()
{
	SCL_L_1;
	I2c_Soft_delay();
	SDA_H_1;
	I2c_Soft_delay();
	SCL_H_1;
	I2c_Soft_delay();
	SCL_L_1;
	I2c_Soft_delay();
}
void I2c_Soft_NoAsk_2()
{
	SCL_L_2;
	I2c_Soft_delay();
	SDA_H_2;
	I2c_Soft_delay();
	SCL_H_2;
	I2c_Soft_delay();
	SCL_L_2;
	I2c_Soft_delay();
}
void I2c_Soft_NoAsk_3()
{
	SCL_L_3;
	I2c_Soft_delay();
	SDA_H_3;
	I2c_Soft_delay();
	SCL_H_3;
	I2c_Soft_delay();
	SCL_L_3;
	I2c_Soft_delay();
}
void I2c_Soft_NoAsk_4()
{
	SCL_L_4;
	I2c_Soft_delay();
	SDA_H_4;
	I2c_Soft_delay();
	SCL_H_4;
	I2c_Soft_delay();
	SCL_L_4;
	I2c_Soft_delay();
}
void I2c_Soft_NoAsk_5()
{
	SCL_L_5;
	I2c_Soft_delay();
	SDA_H_5;
	I2c_Soft_delay();
	SCL_H_5;
	I2c_Soft_delay();
	SCL_L_5;
	I2c_Soft_delay();
}

void I2c_Soft_NoAsk_6()
{
	SCL_L_6;
	I2c_Soft_delay();
	SDA_H_6;
	I2c_Soft_delay();
	SCL_H_6;
	I2c_Soft_delay();
	SCL_L_6;
	I2c_Soft_delay();
}


void I2c_Soft_NoAsk_7()
{
	SCL_L_7;
	I2c_Soft_delay();
	SDA_H_7;
	I2c_Soft_delay();
	SCL_H_7;
	I2c_Soft_delay();
	SCL_L_7;
	I2c_Soft_delay();
}

int I2c_Soft_WaitAsk(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L;
	I2c_Soft_delay();
	SDA_H;			
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	while(SDA_read)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop();
			return 1;
		}
	}
	SCL_L;
	I2c_Soft_delay();
	return 0;
}

int I2c_Soft_WaitAsk_1(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_1;
	I2c_Soft_delay();
	SDA_H_1;			
	I2c_Soft_delay();
	SCL_H_1;
	I2c_Soft_delay();
	while(SDA_read_1)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_1();
			return 1;
		}
	}
	SCL_L_1;
	I2c_Soft_delay();
	return 0;
}
int I2c_Soft_WaitAsk_2(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_2;
	I2c_Soft_delay();
	SDA_H_2;			
	I2c_Soft_delay();
	SCL_H_2;
	I2c_Soft_delay();
	while(SDA_read_2)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_2();
			return 1;
		}
	}
	SCL_L_2;
	I2c_Soft_delay();
	return 0;
}
int I2c_Soft_WaitAsk_3(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_3;
	I2c_Soft_delay();
	SDA_H_3;			
	I2c_Soft_delay();
	SCL_H_3;
	I2c_Soft_delay();
	while(SDA_read_3)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_3();
			return 1;
		}
	}
	SCL_L_3;
	I2c_Soft_delay();
	return 0;
}
int I2c_Soft_WaitAsk_4(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_4;
	I2c_Soft_delay();
	SDA_H_4;			
	I2c_Soft_delay();
	SCL_H_4;
	I2c_Soft_delay();
	while(SDA_read_4)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_4();
			return 1;
		}
	}
	SCL_L_4;
	I2c_Soft_delay();
	return 0;
}
int I2c_Soft_WaitAsk_5(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_5;
	I2c_Soft_delay();
	SDA_H_5;			
	I2c_Soft_delay();
	SCL_H_5;
	I2c_Soft_delay();
	while(SDA_read_5)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_5();
			return 1;
		}
	}
	SCL_L_5;
	I2c_Soft_delay();
	return 0;
}

int I2c_Soft_WaitAsk_6(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_6;
	I2c_Soft_delay();
	SDA_H_6;			
	I2c_Soft_delay();
	SCL_H_6;
	I2c_Soft_delay();
	while(SDA_read_6)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_6();
			return 1;
		}
	}
	SCL_L_6;
	I2c_Soft_delay();
	return 0;
}
int I2c_Soft_WaitAsk_7(void) 	 //返回为:=1无ASK,=0有ASK
{
  u8 ErrTime = 0;
	SCL_L_7;
	I2c_Soft_delay();
	SDA_H_7;			
	I2c_Soft_delay();
	SCL_H_7;
	I2c_Soft_delay();
	while(SDA_read_7)
	{
		ErrTime++;
		if(ErrTime>50)
		{
			I2c_Soft_Stop_7();
			return 1;
		}
	}
	SCL_L_7;
	I2c_Soft_delay();
	return 0;
}


void I2c_Soft_SendByte(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H;  
      else 
        SDA_L;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H;
				I2c_Soft_delay();
    }
    SCL_L;
}  
void I2c_Soft_SendByte_1(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_1;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_1;  
      else 
        SDA_L_1;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_1;
				I2c_Soft_delay();
    }
    SCL_L_1;
}  
void I2c_Soft_SendByte_2(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_2;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_2;  
      else 
        SDA_L_2;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_2;
				I2c_Soft_delay();
    }
    SCL_L_2;
}  
void I2c_Soft_SendByte_3(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_3;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_3;  
      else 
        SDA_L_3;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_3;
				I2c_Soft_delay();
    }
    SCL_L_3;
}  
void I2c_Soft_SendByte_4(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_4;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_4;  
      else 
        SDA_L_4;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_4;
				I2c_Soft_delay();
    }
    SCL_L_4;
}  

void I2c_Soft_SendByte_5(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_5;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_5;  
      else 
        SDA_L_5;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_5;
				I2c_Soft_delay();
    }
    SCL_L_5;
}  


void I2c_Soft_SendByte_6(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_6;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_6;  
      else 
        SDA_L_6;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_6;
				I2c_Soft_delay();
    }
    SCL_L_6;
}  


void I2c_Soft_SendByte_7(u8 SendByte) //数据从高位到低位//
{
    u8 i=8;
    while(i--)
    {
        SCL_L_7;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H_7;  
      else 
        SDA_L_7;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H_7;
				I2c_Soft_delay();
    }
    SCL_L_7;
}  

//读1个字节，ack=1时，发送ACK，ack=0，发送NACK
u8 I2c_Soft_ReadByte(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L;
      I2c_Soft_delay();
			SCL_H;
      I2c_Soft_delay();	
      if(SDA_read)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L;

	if (ask)
		I2c_Soft_Ask();
	else
		I2c_Soft_NoAsk();  
    return ReceiveByte;
} 

u8 I2c_Soft_ReadByte_1(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_1;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_1;
      I2c_Soft_delay();
			SCL_H_1;
      I2c_Soft_delay();	
      if(SDA_read_1)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_1;

	if (ask)
		I2c_Soft_Ask_1();
	else
		I2c_Soft_NoAsk_1();  
    return ReceiveByte;
} 

u8 I2c_Soft_ReadByte_2(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_2;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_2;
      I2c_Soft_delay();
			SCL_H_2;
      I2c_Soft_delay();	
      if(SDA_read_2)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_2;

	if (ask)
		I2c_Soft_Ask_2();
	else
		I2c_Soft_NoAsk_2();  
    return ReceiveByte;
} 

u8 I2c_Soft_ReadByte_3(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_3;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_3;
      I2c_Soft_delay();
			SCL_H_3;
      I2c_Soft_delay();	
      if(SDA_read_3)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_3;

	if (ask)
		I2c_Soft_Ask_3();
	else
		I2c_Soft_NoAsk_3();  
    return ReceiveByte;
} 
u8 I2c_Soft_ReadByte_4(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_4;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_4;
      I2c_Soft_delay();
			SCL_H_4;
      I2c_Soft_delay();	
      if(SDA_read_4)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_4;

	if (ask)
		I2c_Soft_Ask_4();
	else
		I2c_Soft_NoAsk_4();  
    return ReceiveByte;
} 

u8 I2c_Soft_ReadByte_5(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_5;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_5;
      I2c_Soft_delay();
			SCL_H_5;
      I2c_Soft_delay();	
      if(SDA_read_5)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_5;

	if (ask)
		I2c_Soft_Ask_5();
	else
		I2c_Soft_NoAsk_5();  
    return ReceiveByte;
} 


u8 I2c_Soft_ReadByte_6(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_6;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_6;
      I2c_Soft_delay();
			SCL_H_6;
      I2c_Soft_delay();	
      if(SDA_read_6)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_6;

	if (ask)
		I2c_Soft_Ask_6();
	else
		I2c_Soft_NoAsk_6();  
    return ReceiveByte;
} 

u8 I2c_Soft_ReadByte_7(u8 ask)  //数据从高位到低位//
{ 
    u8 i=8;
    u8 ReceiveByte=0;

    SDA_H_7;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L_7;
      I2c_Soft_delay();
			SCL_H_7;
      I2c_Soft_delay();	
      if(SDA_read_7)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L_7;

	if (ask)
		I2c_Soft_Ask_7();
	else
		I2c_Soft_NoAsk_7();  
    return ReceiveByte;
} 
// IIC写一个字节数据
u8 IIC_Write_1Byte(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address);       
	I2c_Soft_WaitAsk();	
	I2c_Soft_SendByte(REG_data);
	I2c_Soft_WaitAsk();   
	I2c_Soft_Stop(); 
	return 0;
}
u8 IIC_Write_1Byte_1(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_1();
	I2c_Soft_SendByte_1(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_1())
	{
		I2c_Soft_Stop_1();
		return 1;
	}
	I2c_Soft_SendByte_1(REG_Address);       
	I2c_Soft_WaitAsk_1();	
	I2c_Soft_SendByte_1(REG_data);
	I2c_Soft_WaitAsk_1();   
	I2c_Soft_Stop_1(); 
	return 0;
}
u8 IIC_Write_1Byte_2(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_2();
	I2c_Soft_SendByte_2(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_2())
	{
		I2c_Soft_Stop_2();
		return 1;
	}
	I2c_Soft_SendByte_2(REG_Address);       
	I2c_Soft_WaitAsk_2();	
	I2c_Soft_SendByte_2(REG_data);
	I2c_Soft_WaitAsk_2();   
	I2c_Soft_Stop_2(); 
	return 0;
}
u8 IIC_Write_1Byte_3(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_3();
	I2c_Soft_SendByte_3(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_3())
	{
		I2c_Soft_Stop_3();
		return 1;
	}
	I2c_Soft_SendByte_3(REG_Address);       
	I2c_Soft_WaitAsk_3();	
	I2c_Soft_SendByte_3(REG_data);
	I2c_Soft_WaitAsk_3();   
	I2c_Soft_Stop_3(); 
	return 0;
}
u8 IIC_Write_1Byte_4(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_4();
	I2c_Soft_SendByte_4(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_4())
	{
		I2c_Soft_Stop_4();
		return 1;
	}
	I2c_Soft_SendByte_4(REG_Address);       
	I2c_Soft_WaitAsk_4();	
	I2c_Soft_SendByte_4(REG_data);
	I2c_Soft_WaitAsk_4();   
	I2c_Soft_Stop_4(); 
	return 0;
}
u8 IIC_Write_1Byte_5(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_5();
	I2c_Soft_SendByte_5(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_5())
	{
		I2c_Soft_Stop_5();
		return 1;
	}
	I2c_Soft_SendByte_5(REG_Address);       
	I2c_Soft_WaitAsk_5();	
	I2c_Soft_SendByte_5(REG_data);
	I2c_Soft_WaitAsk_5();   
	I2c_Soft_Stop_5(); 
	return 0;
}

u8 IIC_Write_1Byte_6(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_6();
	I2c_Soft_SendByte_6(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_6())
	{
		I2c_Soft_Stop_6();
		return 1;
	}
	I2c_Soft_SendByte_6(REG_Address);       
	I2c_Soft_WaitAsk_6();	
	I2c_Soft_SendByte_6(REG_data);
	I2c_Soft_WaitAsk_6();   
	I2c_Soft_Stop_6(); 
	return 0;
}

u8 IIC_Write_1Byte_7(u8 SlaveAddress,u8 REG_Address,u8 REG_data)
{
	I2c_Soft_Start_7();
	I2c_Soft_SendByte_7(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk_7())
	{
		I2c_Soft_Stop_7();
		return 1;
	}
	I2c_Soft_SendByte_7(REG_Address);       
	I2c_Soft_WaitAsk_7();	
	I2c_Soft_SendByte_7(REG_data);
	I2c_Soft_WaitAsk_7();   
	I2c_Soft_Stop_7(); 
	return 0;
}
// IIC读1字节数据
u8 IIC_Read_1Byte(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address);     
	I2c_Soft_WaitAsk();
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk();
	*REG_data= I2c_Soft_ReadByte(0);
	I2c_Soft_Stop();
	return 0;
}	
// IIC读1字节数据
u8 IIC_Read_1Byte_1(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_1();
	I2c_Soft_SendByte_1(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_1())
	{
		I2c_Soft_Stop_1();
		return 1;
	}
	I2c_Soft_SendByte_1(REG_Address);     
	I2c_Soft_WaitAsk_1();
	I2c_Soft_Start_1();
	I2c_Soft_SendByte_1(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_1();
	*REG_data= I2c_Soft_ReadByte_1(0);
	I2c_Soft_Stop_1();
	return 0;
}	
u8 IIC_Read_1Byte_2(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_2();
	I2c_Soft_SendByte_2(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_2())
	{
		I2c_Soft_Stop_2();
		return 1;
	}
	I2c_Soft_SendByte_2(REG_Address);     
	I2c_Soft_WaitAsk_2();
	I2c_Soft_Start_2();
	I2c_Soft_SendByte_2(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_2();
	*REG_data= I2c_Soft_ReadByte_2(0);
	I2c_Soft_Stop_2();
	return 0;
}	

u8 IIC_Read_1Byte_3(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_3();
	I2c_Soft_SendByte_3(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_3())
	{
		I2c_Soft_Stop_3();
		return 1;
	}
	I2c_Soft_SendByte_3(REG_Address);     
	I2c_Soft_WaitAsk_3();
	I2c_Soft_Start_3();
	I2c_Soft_SendByte_3(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_3();
	*REG_data= I2c_Soft_ReadByte_3(0);
	I2c_Soft_Stop_3();
	return 0;
}	
u8 IIC_Read_1Byte_4(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_4();
	I2c_Soft_SendByte_4(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_4())
	{
		I2c_Soft_Stop_4();
		return 1;
	}
	I2c_Soft_SendByte_4(REG_Address);     
	I2c_Soft_WaitAsk_4();
	I2c_Soft_Start_4();
	I2c_Soft_SendByte_4(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_4();
	*REG_data= I2c_Soft_ReadByte_4(0);
	I2c_Soft_Stop_4();
	return 0;
}	
u8 IIC_Read_1Byte_5(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_5();
	I2c_Soft_SendByte_5(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_5())
	{
		I2c_Soft_Stop_5();
		return 1;
	}
	I2c_Soft_SendByte_5(REG_Address);     
	I2c_Soft_WaitAsk_5();
	I2c_Soft_Start_5();
	I2c_Soft_SendByte_5(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_5();
	*REG_data= I2c_Soft_ReadByte_5(0);
	I2c_Soft_Stop_5();
	return 0;
}	

u8 IIC_Read_1Byte_6(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_6();
	I2c_Soft_SendByte_6(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_6())
	{
		I2c_Soft_Stop_6();
		return 1;
	}
	I2c_Soft_SendByte_6(REG_Address);     
	I2c_Soft_WaitAsk_6();
	I2c_Soft_Start_6();
	I2c_Soft_SendByte_6(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_6();
	*REG_data= I2c_Soft_ReadByte_6(0);
	I2c_Soft_Stop_6();
	return 0;
}	


u8 IIC_Read_1Byte_7(u8 SlaveAddress,u8 REG_Address,u8 *REG_data)
{      		
	I2c_Soft_Start_7();
	I2c_Soft_SendByte_7(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_7())
	{
		I2c_Soft_Stop_7();
		return 1;
	}
	I2c_Soft_SendByte_7(REG_Address);     
	I2c_Soft_WaitAsk_7();
	I2c_Soft_Start_7();
	I2c_Soft_SendByte_7(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk_7();
	*REG_data= I2c_Soft_ReadByte_7(0);
	I2c_Soft_Stop_7();
	return 0;
}	
// IIC写n字节数据
u8 IIC_Write_nByte(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address); 
	I2c_Soft_WaitAsk();
	while(len--) 
	{
		I2c_Soft_SendByte(*buf++); 
		I2c_Soft_WaitAsk();
	}
	I2c_Soft_Stop();
	return 0;
}
// IIC写n字节数据
u8 IIC_Write_nByte_1(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_1();
	I2c_Soft_SendByte_1(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_1())
	{
		I2c_Soft_Stop_1();
		return 1;
	}
	I2c_Soft_SendByte_1(REG_Address); 
	I2c_Soft_WaitAsk_1();
	while(len--) 
	{
		I2c_Soft_SendByte_1(*buf++); 
		I2c_Soft_WaitAsk_1();
	}
	I2c_Soft_Stop_1();
	return 0;
}
// IIC写n字节数据
u8 IIC_Write_nByte_2(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_2();
	I2c_Soft_SendByte_2(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_2())
	{
		I2c_Soft_Stop_2();
		return 1;
	}
	I2c_Soft_SendByte_2(REG_Address); 
	I2c_Soft_WaitAsk_2();
	while(len--) 
	{
		I2c_Soft_SendByte_2(*buf++); 
		I2c_Soft_WaitAsk_2();
	}
	I2c_Soft_Stop_2();
	return 0;
}

// IIC写n字节数据
u8 IIC_Write_nByte_3(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_3();
	I2c_Soft_SendByte_3(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_3())
	{
		I2c_Soft_Stop_3();
		return 1;
	}
	I2c_Soft_SendByte_3(REG_Address); 
	I2c_Soft_WaitAsk_3();
	while(len--) 
	{
		I2c_Soft_SendByte_3(*buf++); 
		I2c_Soft_WaitAsk_3();
	}
	I2c_Soft_Stop_3();
	return 0;
}
// IIC写n字节数据
u8 IIC_Write_nByte_4(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_4();
	I2c_Soft_SendByte_4(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_4())
	{
		I2c_Soft_Stop_4();
		return 1;
	}
	I2c_Soft_SendByte_4(REG_Address); 
	I2c_Soft_WaitAsk_4();
	while(len--) 
	{
		I2c_Soft_SendByte_4(*buf++); 
		I2c_Soft_WaitAsk_4();
	}
	I2c_Soft_Stop_4();
	return 0;
}
// IIC写n字节数据
u8 IIC_Write_nByte_5(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_5();
	I2c_Soft_SendByte_5(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_5())
	{
		I2c_Soft_Stop_5();
		return 1;
	}
	I2c_Soft_SendByte_5(REG_Address); 
	I2c_Soft_WaitAsk_5();
	while(len--) 
	{
		I2c_Soft_SendByte_5(*buf++); 
		I2c_Soft_WaitAsk_5();
	}
	I2c_Soft_Stop_5();
	return 0;
}

// IIC写n字节数据
u8 IIC_Write_nByte_6(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_6();
	I2c_Soft_SendByte_6(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_6())
	{
		I2c_Soft_Stop_6();
		return 1;
	}
	I2c_Soft_SendByte_6(REG_Address); 
	I2c_Soft_WaitAsk_6();
	while(len--) 
	{
		I2c_Soft_SendByte_6(*buf++); 
		I2c_Soft_WaitAsk_6();
	}
	I2c_Soft_Stop_6();
	return 0;
}
// IIC写n字节数据
u8 IIC_Write_nByte_7(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_7();
	I2c_Soft_SendByte_7(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_7())
	{
		I2c_Soft_Stop_7();
		return 1;
	}
	I2c_Soft_SendByte_7(REG_Address); 
	I2c_Soft_WaitAsk_7();
	while(len--) 
	{
		I2c_Soft_SendByte_7(*buf++); 
		I2c_Soft_WaitAsk_7();
	}
	I2c_Soft_Stop_7();
	return 0;
}
// IIC读n字节数据
u8 IIC_Read_nByte(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address); 
	I2c_Soft_WaitAsk();
	
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop();
	return 0;
}
// IIC读n字节数据
u8 IIC_Read_nByte_1(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_1();
	I2c_Soft_SendByte_1(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_1())
	{
		I2c_Soft_Stop_1();
		return 1;
	}
	I2c_Soft_SendByte_1(REG_Address); 
	I2c_Soft_WaitAsk_1();
	
	I2c_Soft_Start_1();
	I2c_Soft_SendByte_1(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_1();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_1(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_1(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_1();
	return 0;
}

u8 IIC_Read_nByte_2(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_2();
	I2c_Soft_SendByte_2(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_2())
	{
		I2c_Soft_Stop_2();
		return 1;
	}
	I2c_Soft_SendByte_2(REG_Address); 
	I2c_Soft_WaitAsk_2();
	
	I2c_Soft_Start_2();
	I2c_Soft_SendByte_2(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_2();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_2(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_2(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_2();
	return 0;
}
u8 IIC_Read_nByte_3(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_3();
	I2c_Soft_SendByte_3(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_3())
	{
		I2c_Soft_Stop_3();
		return 1;
	}
	I2c_Soft_SendByte_3(REG_Address); 
	I2c_Soft_WaitAsk_3();
	
	I2c_Soft_Start_3();
	I2c_Soft_SendByte_3(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_3();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_3(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_3(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_3();
	return 0;
}
u8 IIC_Read_nByte_4(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_4();
	I2c_Soft_SendByte_4(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_4())
	{
		I2c_Soft_Stop_4();
		return 1;
	}
	I2c_Soft_SendByte_4(REG_Address); 
	I2c_Soft_WaitAsk_4();
	
	I2c_Soft_Start_4();
	I2c_Soft_SendByte_4(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_4();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_4(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_4(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_4();
	return 0;
}
u8 IIC_Read_nByte_5(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_5();
	I2c_Soft_SendByte_5(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_5())
	{
		I2c_Soft_Stop_5();
		return 1;
	}
	I2c_Soft_SendByte_5(REG_Address); 
	I2c_Soft_WaitAsk_5();
	
	I2c_Soft_Start_5();
	I2c_Soft_SendByte_5(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_5();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_5(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_5(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_5();
	return 0;
}
u8 IIC_Read_nByte_6(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_6();
	I2c_Soft_SendByte_6(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_6())
	{
		I2c_Soft_Stop_6();
		return 1;
	}
	I2c_Soft_SendByte_6(REG_Address); 
	I2c_Soft_WaitAsk_6();
	
	I2c_Soft_Start_6();
	I2c_Soft_SendByte_6(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_6();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_6(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_6(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_6();
	return 0;
}
u8 IIC_Read_nByte_7(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf)
{	
	I2c_Soft_Start_7();
	I2c_Soft_SendByte_7(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk_7())
	{
		I2c_Soft_Stop_7();
		return 1;
	}
	I2c_Soft_SendByte_7(REG_Address); 
	I2c_Soft_WaitAsk_7();
	
	I2c_Soft_Start_7();
	I2c_Soft_SendByte_7(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk_7();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte_7(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte_7(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop_7();
	return 0;
}
/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/

