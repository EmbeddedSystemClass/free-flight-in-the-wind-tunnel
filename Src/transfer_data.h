#ifndef __TRANSFER_DATA_H
#define __TRANSFER_DATA_H

#include "stm32f4xx_hal.h"
#include "usart.h"

void Data_Send(uint16_t Angle[],uint16_t Hall[]);
//void Data_Receive_Anl(uint8_t *data_buf,uint8_t num,uint16_t *pwm);
//void Data_Receive_Anl(uint8_t *data_buf,uint8_t num);
void Data_Receive_Prepare(uint8_t data);


#endif
