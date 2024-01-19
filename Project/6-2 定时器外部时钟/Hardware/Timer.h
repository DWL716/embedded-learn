#ifndef __TIMER_H_
#define __TIMER_H_

#include "stm32f10x.h"

void TimerInit(void);
uint16_t Timer_GetCounter(void);
void GPIO_Init(void);
void My_NVIC_Init(void);

#endif