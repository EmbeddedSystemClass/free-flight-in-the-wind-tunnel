#include "transfer_data.h"


#include "mavlink.h"
#include "mavlink_msg_sensors.h"

extern UART_HandleTypeDef huart1;

mavlink_system_t mavlink_system;

void SetPwm(mavlink_pwms_t pwms);

//void comm_send_ch2(mavlink_channel_t chan, const uint8_t *buf, uint16_t len)
//{
//	if (chan == MAVLINK_COMM_0)
//	{
//     // HAL_UART_Transmit(&huart1,(uint8_t *)buf,len,0xffff);
//	  HAL_UART_Transmit_DMA(&huart1,(uint8_t *)buf, len);

//	}
//}


/////////////////////////////////////////////////////////////////////////////////////
//数据拆分宏定义，在发送大于1字节的数据类型时，比如int16、float等，需要把数据拆分成单独字节进行发送
#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)		) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )
	
uint8_t data_to_send[50];	//发送数据缓存
uint16_t a1=0;
/*------------------数据发送-------------------*/

//void Data_Send(uint16_t Angle[],uint16_t Hall[])
//{
//	uint8_t cnt=0,sum=0,i;
//	uint16_t temp;
//	//帧头
//	data_to_send[cnt++]=0xAA;
//	data_to_send[cnt++]=0xAA;
//	//功能字
//	data_to_send[cnt++]=0x01;
//	//数据长度
//	data_to_send[cnt++]=0;
//	
//	temp=Angle[0];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[1];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[2];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[3];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[4];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[5];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[6];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Angle[7];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Hall[0];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Hall[1];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Hall[2];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	temp=Hall[3];
//	data_to_send[cnt++]=BYTE1(temp);
//	data_to_send[cnt++]=BYTE0(temp);
//	//确定数据长度
//	data_to_send[3]=cnt-4;
//	for(i=0;i<cnt;i++)
//		sum+=data_to_send[i];
//	data_to_send[cnt++]=sum;
//	
//	HAL_UART_Transmit(&huart1,data_to_send,cnt,0xffff);
//}

uint16_t tmp1=0;
uint16_t tmp2=0;

void Data_Send(uint16_t Angle[],uint16_t Hall[])
{
	++tmp2;
	Angle[1] = tmp1;
	Angle[2] = tmp2;
	mavlink_msg_sensors_send(MAVLINK_COMM_0, Angle,Hall);

}
/*--------------------数据接收--------------------*/

mavlink_message_t msg;
mavlink_status_t status;

void Data_Receive_Prepare(uint8_t data)
{
	mavlink_pwms_t pwms;
	if (mavlink_parse_char(MAVLINK_COMM_0,data, &msg, &status))
	{
		switch (msg.msgid)
		{
			case 1:
			{
			}
				break;
			case 2:
			{
			    mavlink_msg_pwms_decode(&msg, &pwms);
				SetPwm(pwms);
				++tmp1;
			}
				break;
			default:
				break;
		}
	
	}
}

void SetPwm(mavlink_pwms_t pwms)
{
 	TIM8->CCR3 = pwms.pwms[0];				//pwmout1
 	TIM8->CCR4 = pwms.pwms[1];				//pwmout2
	TIM5->CCR3 = pwms.pwms[2];              //pwmout3
	TIM5->CCR4 = pwms.pwms[3];              //pwmout4
	TIM1->CCR1 = pwms.pwms[4];              //pwmout5
	TIM1->CCR2 = pwms.pwms[5];              //pwmout6
	TIM1->CCR3 = pwms.pwms[6];              //pwmout7
	TIM1->CCR4 = pwms.pwms[7];              //pwmout8

}
//void Data_Receive_Prepare(uint8_t data)
//{
//	static uint8_t RxBuffer[50];
//	static uint8_t _data_len = 0,_data_cnt = 0;
//	static uint8_t state = 0;
//	if(state==0&&data==0xAA)
//	{
//		state=1;
//		RxBuffer[0]=data;
//	}
//	else if(state==1&&data==0xAA)
//	{
//		state=2;
//		RxBuffer[1]=data;
//	}
//	else if(state==2&&data<0XF1)
//	{
//		state=3;
//		RxBuffer[2]=data;
//	}
//	else if(state==3&&data<50)
//	{
//		state = 4; 
//		RxBuffer[3]=data;
//		_data_len = data;
//		_data_cnt = 0;
//	}
//	else if(state==4&&_data_len>0)
//	{
//		_data_len--;
//		RxBuffer[4+_data_cnt++]=data;
//		if(_data_len==0)
//			state = 5;
//	}
//	else if(state==5)
//	{
//		state = 0;
//		RxBuffer[4+_data_cnt]=data;
//		Data_Receive_Anl(RxBuffer,_data_cnt+5);
//		
//	}
//	else
//		state = 0;
//}


//void Data_Receive_Anl(uint8_t *data_buf,uint8_t num)
//{
//	
//	uint8_t sum = 0;
//	uint8_t i;
//	uint16_t pwm[8];
//	uint16_t hall[4];
//	for(i=0;i<(num-1);i++)
//		sum += *(data_buf+i);
//	if(!(sum==*(data_buf+num-1)))		return;		//判断sum
//	if(!(*(data_buf)==0xAA && *(data_buf+1)==0xAA))		return;		//判断帧头
//	if(*(data_buf+2)==0X01)
//	{
//		*(pwm+0) = (uint16_t)(*(data_buf+4)<<8)|*(data_buf+5);
//		*(pwm+1) = (uint16_t)(*(data_buf+6)<<8)|*(data_buf+7);
//		*(pwm+2) = (uint16_t)(*(data_buf+8)<<8)|*(data_buf+9);
//		*(pwm+3) = (uint16_t)(*(data_buf+4)<<10)|*(data_buf+11);
//		*(pwm+4) = (uint16_t)(*(data_buf+4)<<12)|*(data_buf+13);
//		*(pwm+5) = (uint16_t)(*(data_buf+4)<<14)|*(data_buf+15);
//		*(pwm+6)=(uint16_t)(*(data_buf+4)<<16)|*(data_buf+17);
//	    *(pwm+7)=(uint16_t)(*(data_buf+4)<<18)|*(data_buf+19);
//		*(hall+0)=(uint16_t)(*(data_buf+4)<<20)|*(data_buf+21);
//		*(hall+1)=(uint16_t)(*(data_buf+4)<<22)|*(data_buf+23);
//		*(hall+2)=(uint16_t)(*(data_buf+4)<<24)|*(data_buf+25);
//		*(hall+3)=(uint16_t)(*(data_buf+4)<<26)|*(data_buf+27);
//		Data_Send(pwm,hall);
//	    a1++;	
//	}
//	else return;
//}
