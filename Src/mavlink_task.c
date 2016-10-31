/**
  ******************************************************************************
  * File Name          : mavlink_task.c
  * Description        : Code for mavlink communications
  ******************************************************************************
  *
  * Copyright (c) 2016 Matthew GONG(matt@matthewgong.com) 
  * All rights reserved.
  *
  ******************************************************************************
  */
  /* Includes ------------------------------------------------------------------*/
#include "include.h"

#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
#pragma anon_unions
void comm_send_ch(int chan, uint8_t ch);
#include "mavlink.h"

/* Variables -----------------------------------------------------------------*/
mavlink_system_t mavlink_system;
extern QueueHandle_t msgInQueueHandle;
extern QueueHandle_t msgQueueAngle ;
extern QueueHandle_t msgQueueRpm ;

extern EventGroupHandle_t xCreatedEventGroup ;
/* Variables -----------------------------------------------------------------*/

/* Function implements -------------------------------------------------------*/

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

void StartSampleThread(void const * argument)
{
	uint16_t Hall[4]={0,0,0,0};
	uint16_t Angle[8]={0,0,0,0,0,0,0,0};
	uint8_t data=0;
	EventBits_t uxBits;
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 100;	
	const TickType_t xTicksToWait = 20 / portTICK_PERIOD_MS;
	const TickType_t xMaxBlockTime = pdMS_TO_TICKS(10); /* 设置最大等待时间为100ms */
	xLastWakeTime = xTaskGetTickCount();
	for(;;)
	{
		uxBits=xEventGroupWaitBits(xCreatedEventGroup, /* 事件标志组句柄 */
							         BIT_ALL,            /* 等待bit0和bit1被设置 */
							         pdTRUE,             /* 退出前bit0和bit1被清除 */
							         pdTRUE,             /* 设置为pdTRUE表示等待bit1和bit0都被设置*/
							         xTicksToWait); 	 /* 等待延迟时间 */
		if((uxBits & BIT_ALL) == BIT_ALL)
		{
			//printf("接收到数据\r\n");
		
			xQueueReceive( msgQueueAngle,                   /* 消息队列句柄 */
		               (void *)Angle,  		   /* 这里获取的是结构体的地址 */
		               (TickType_t)xMaxBlockTime);/* 设置阻塞时间 */
		
			xQueueReceive( msgQueueRpm,                   /* 消息队列句柄 */
		               (void *)Hall,  		   /* 这里获取的是结构体的地址 */
		               (TickType_t)xMaxBlockTime);/* 设置阻塞时间 */
		
				
			mavlink_msg_sensors_send(MAVLINK_COMM_0, Angle,Hall);
			//printf("Angle={[%d,%d,%d,%d,%d,%d,%d,%d]}\r\n",Angle[0],Angle[1],Angle[2],Angle[3],Angle[4],Angle[5],Angle[6],Angle[7]);
			//printf("Hall={%d,%d,%d,%d}\r\n",Hall[0],Hall[1],Hall[2],Hall[3]);
		}
		else if (uxBits == BIT_1)
		{
			mavlink_msg_sensors_send(MAVLINK_COMM_0, Angle,Hall);
		}
		else 
		{
			xQueueReceive( msgQueueAngle,                   /* 消息队列句柄 */
		               (void *)Angle,  		   /* 这里获取的是结构体的地址 */
		               (TickType_t)xMaxBlockTime);/* 设置阻塞时间 */
			//printf("Angle={[%d,%d,%d,%d,%d,%d,%d,%d]}\r\n",Angle[0],Angle[1],Angle[2],Angle[3],Angle[4],Angle[5],Angle[6],Angle[7]);
			mavlink_msg_sensors_send(MAVLINK_COMM_0, Angle,Hall);
		}
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void DataReceiveThread(void const * argument)
{
	uint8_t data=0;
	mavlink_message_t msg;
	mavlink_status_t status;
	mavlink_pwms_t pwms;
	for(;;)
	{
		if(xQueueReceive( msgInQueueHandle,                   /* 消息队列句柄 */
		               (void *)&data,  		   /* 这里获取的是结构体的地址 */
		               (TickType_t)-1))/* 设置阻塞时间 */
		{
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
					}
						break;
					default:
						break;
				}
		    }
	     }			   
	 }		
}

