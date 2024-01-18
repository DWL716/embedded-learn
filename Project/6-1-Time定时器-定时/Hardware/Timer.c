#include "Timer.h"

// 72MHZ = 72000000
void TimerInit(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

    // 开启定时器时钟,即内部时钟CK_INT=72M
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); // 时钟开启

    // 设置时基参数。定时1s中断一次
    TIM_TimeBaseInitStructure.TIM_Period = 7200 - 1; // arr
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 不分频
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0x00;     // 滤波采样次数
    TIM_TimeBaseInitStructure.TIM_Prescaler = 10000 - 1;        // psc
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    // 清除计数器中断标志位，
    // 当初始化时候计数器计数器为0时，中断标志位为1，需要清0，可以参考TIMx_EGR寄存器的UG位
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);

    // 开启计数器中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    TIM_Cmd(TIM2, ENABLE);
}

void NVIC_Init(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {
        // code
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}