#ifndef __TIMER_H
#define __TIMER_H

#include "stm32f10x.h"

void TimerInit(void);
void NVIC_Init(void);
void TIM2_IRQHandler(void);

#endif
