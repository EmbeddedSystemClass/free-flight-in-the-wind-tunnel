#ifndef __INCLUDE_H
#define __INCLUDE_H

/*-------------------------------------*/
/*--------------标准库-----------------*/
/*-------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

/*------------------------------------*/
/*----------------OS------------------*/
/*------------------------------------*/

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "croutine.h"
#include "event_groups.h"
/*------------------------------------*/
/*--------------宏定义----------------*/
/*------------------------------------*/

#define BIT_0	(1 << 0)
#define BIT_1	(1 << 1)
#define BIT_ALL (BIT_0 | BIT_1)


/*------------------------------------*/
/*--------------APP/BSP---------------*/
/*------------------------------------*/
#include "stm32f4xx_hal.h"
#include "usart.h" 
#include "as5600.h"
#include "transfer_data.h"



#endif
