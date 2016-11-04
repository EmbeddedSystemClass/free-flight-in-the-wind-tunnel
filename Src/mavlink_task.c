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
extern uint16_t Motor_RPM_1[4];
extern uint16_t Angle[8];

void vToggleRedLED(void);
void vToggleGreenLED(void);
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
	uint8_t data=0;
	EventBits_t uxBits;
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;	
	const TickType_t xMaxBlockTime = pdMS_TO_TICKS(5); /* 设置最大等待时间为10ms */
	xLastWakeTime = xTaskGetTickCount();
	for(;;) 
	{
		uxBits=xEventGroupWaitBits(xCreatedEventGroup, /* 事件标志组句柄 */
							         BIT_ALL,            /* 等待bit0和bit1被设置 */
							         pdTRUE,             /* 退出前bit0和bit1被清除 */
							         pdTRUE,             /* 设置为pdTRUE表示等待bit1和bit0都被设置*/
							         (TickType_t)0); 	 /* 等待延迟时间 */
		if((uxBits & BIT_ALL) == BIT_ALL)
		{	
			mavlink_msg_sensors_send(MAVLINK_COMM_0, Angle,Motor_RPM_1);	
		//	printf("Angle={[%d,%d,%d,%d,%d,%d,%d,%d]}\r\n",Angle[0],Angle[1],Angle[2],Angle[3],Angle[4],Angle[5],Angle[6],Angle[7]);
		//	printf("Hall={%d,%d,%d,%d}\r\n",Motor_RPM_1[0],Motor_RPM_1[1],Motor_RPM_1[2],Motor_RPM_1[3]);
		}
		
		else 
		{
		//	printf("Angle={[%d,%d,%d,%d,%d,%d,%d,%d]}\r\n",Angle[0],Angle[1],Angle[2],Angle[3],Angle[4],Angle[5],Angle[6],Angle[7]);
			mavlink_msg_sensors_send(MAVLINK_COMM_0, Angle,Motor_RPM_1);
			vTaskDelay(1);
		}
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void DataReceiveThread(void const * argument)
{
	uint8_t data[4];
	mavlink_message_t msg;
	mavlink_status_t status;
	mavlink_pwms_t pwms;
	for(;;)
	{ 
		if(xQueueReceive( msgInQueueHandle,                   /* 消息队列句柄 */
		               (void *)data,  		   /* 这里获取的是结构体的地址 */
		               (TickType_t)-1))/* 设置阻塞时间 */
		{
			for (int i=0;i<4;++i)
			{
				vToggleRedLED();
				if (mavlink_parse_char(MAVLINK_COMM_0,data[i], &msg, &status))
				{
				vToggleGreenLED();
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
}

void vToggleRedLED(void)
{
  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2);
}

void vToggleGreenLED(void)
{
  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);
}
