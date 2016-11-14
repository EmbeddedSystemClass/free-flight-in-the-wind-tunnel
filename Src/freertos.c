/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */   
#include "include.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId defaultTaskHandle;

/* USER CODE BEGIN Variables */
osMessageQId msgQueueAngle = NULL;
osMessageQId msgQueueRpm = NULL;
osMessageQId msgInQueueHandle = NULL;

osSemaphoreId msgOutBinarySemHandle;

EventGroupHandle_t xCreatedEventGroup = NULL;

uint8_t pingpang[256];
uint8_t pingpang_idx;
uint16_t Motor_RPM_1[4];
uint16_t Angle[8];
uint16_t flag_updata;
uint16_t flag_updata_1;
uint16_t flag_updata_2;
uint16_t flag_updata_3;
uint16_t data;
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */
void AS5600Thread(void const * argument);
void StartSampleThread(void const * argument);
void DataReceiveThread(void const * argument);
void StartMsgSendThread(void const * argument);


/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

    uint16_t Hall[4];
	uint8_t data;
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
	
	
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
	osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
	defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	osThreadDef(AS5600_Thread1,AS5600Thread,0,0,512);
	osThreadCreate(osThread(AS5600_Thread1),NULL);

	osThreadDef(StartSampleThread,StartSampleThread,1,0,512);
	osThreadCreate(osThread(StartSampleThread),NULL);

	osThreadDef(Data_Receive_Thread3,DataReceiveThread,3,0,512);
	osThreadCreate(osThread(Data_Receive_Thread3),NULL);

	osThreadDef(StartMsgSendThread, StartMsgSendThread,2, 0, 128);
	osThreadCreate(osThread(StartMsgSendThread), NULL);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */

	osMessageQDef(Queue3,128,uint8_t[4]);
	msgInQueueHandle=osMessageCreate(osMessageQ(Queue3),NULL);
   
   xCreatedEventGroup = xEventGroupCreate();
  /* USER CODE END RTOS_QUEUES */
}

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Application */
     
void AS5600Thread(void const * argument)
{
	
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;	
	//TickType_t count;
	//TickType_t count_1;
	xLastWakeTime = xTaskGetTickCount();
	for(;;)
	{
		//vTaskSuspendAll();
		//taskENTER_CRITICAL();
		//count = xTaskGetTickCount();
		AS5600_DaTa_Angle(Angle);
		//count_1 = xTaskGetTickCount();
		//printf("{%d,%d}",count,count_1);
		//taskEXIT_CRITICAL();
		//xTaskResumeAll();
	    xEventGroupSetBits( xCreatedEventGroup, /* 事件标志组句柄 */
														BIT_0 );           /* 设置bit0 */	
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	} 
}


void StartMsgSendThread(void const * argument)
{
	uint8_t s;
	/* Infinite loop */
	for(;;)
	{
		if(pingpang_idx != 0x00&&pingpang_idx != 0x80)
		{
			osSemaphoreWait(msgOutBinarySemHandle,10);
			if( pingpang_idx > 0x80)
			{
				s = pingpang_idx - 0x80;
				pingpang_idx = 0x00;
				HAL_UART_Transmit_DMA( &huart1, pingpang + 0x80 ,s);
			}
			else
			{
				s = pingpang_idx;
				pingpang_idx = 0x80;
				HAL_UART_Transmit_DMA( &huart1, pingpang, s );
			}
		}
		else
		{
			vTaskDelay(1);
		}
	}
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	UBaseType_t uxSavedInterruptStatus;
	static uint32_t value[4];
	static uint8_t   flag=0,flag_1=0,flag_2=0,flag_3=0;
	static uint16_t temp_cnt1,temp_cnt1_2,temp_cnt2,temp_cnt2_2,temp_cnt3,temp_cnt3_2,temp_cnt4,temp_cnt4_2;
	if(__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC1) != RESET)
	{
		if(flag==0)
		{
			flag_updata =0;
			temp_cnt1 = TIM3->CCR1;
			flag=1;
		}
		else
		{
			temp_cnt1_2 = TIM3->CCR1;
			if( flag_updata == 0 && temp_cnt1_2>=temp_cnt1)
			{
				value[0] = (temp_cnt1_2-temp_cnt1);
			}
			else
			{
				value[0] = (0xffff-temp_cnt1+temp_cnt1_2+1)+ (0xffff + 1) * (flag_updata-1);
				data = flag_updata;
			}
			Motor_RPM_1[0]=60000000/value[0];
			flag_updata = 0;
			flag=0;
		}
		__HAL_TIM_CLEAR_IT(htim, TIM_IT_CC1);
	}
	if(__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC2) != RESET)
	{
		if(flag_1==0)
		{
			flag_updata_1 = 0;
			temp_cnt2 = TIM3->CCR2;
			flag_1=1;
		}
		else
		{
			temp_cnt2_2 = TIM3->CCR2;
			if( flag_updata_1 == 0 )
			{
				value[1] =( temp_cnt2_2-temp_cnt2 );
			}
			else 
			{
				value[1] = (0xffff-temp_cnt2+temp_cnt2_2+1) +(0xffff + 1) * (flag_updata_1-1);
			}	
			Motor_RPM_1[1]=60000000/value[1];
			flag_1=0;
		}
		__HAL_TIM_CLEAR_IT(htim, TIM_IT_CC2);
	}
	if(__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC3) != RESET)
	{
		if(flag_2==0)
		{
			flag_updata_2 = 0;
			temp_cnt3 = TIM3->CCR3;
			flag_2=1;
		}
		else
		{
			temp_cnt3_2 = TIM3->CCR3;
			if( flag_updata_2 == 0)
				value[2] = (temp_cnt3_2-temp_cnt3);
			else 
				value[2] = (0xffff-temp_cnt3+temp_cnt3_2+1) + (0xffff + 1) * (flag_updata_2-1);	
			Motor_RPM_1[2]=60000000/value[2];
			flag_2=0;
		}
		__HAL_TIM_CLEAR_IT(htim, TIM_IT_CC3);
	}
	if(__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC4) != RESET)
	{
		if(flag_3==0)
		{
			flag_updata_3 = 0;
			temp_cnt4 = TIM3->CCR4;
			flag_3=1;
		}
		else
		{
			temp_cnt4_2 = TIM3->CCR4;
			if(flag_updata_3 == 0)
				value[3] = (temp_cnt4_2 - temp_cnt4);
			else 
				value[3] =( 0xffff - temp_cnt4 + temp_cnt4_2 + 1) +(0xffff + 1) * (flag_updata_3-1);		
			Motor_RPM_1[3]=60000000 / value[3];
			
			flag_3=0;
		}
		__HAL_TIM_CLEAR_IT(htim, TIM_IT_CC4);
	}

	xEventGroupSetBitsFromISR(xCreatedEventGroup, /* 事件标志组句柄 */
														BIT_1 ,             /* 设置bit1 */
														&xHigherPriorityTaskWoken );
	
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	
}


void comm_send_ch(int chan, uint8_t ch)
{
	pingpang[pingpang_idx++]=ch;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart2)
	{
		osSemaphoreRelease(msgOutBinarySemHandle);
	}
}



void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart2)
	{
		//TODO precess by error types
		osSemaphoreRelease(msgOutBinarySemHandle);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	flag_updata++;
	flag_updata_1++;
	flag_updata_2++;
	flag_updata_3++;
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
