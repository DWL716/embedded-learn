#include "Timer.h"

// 使用TIM2外部时钟ETR模式2
// 再使用 对射红外线来作为外部时钟计时器
// 对射红外线 Do输出信号引脚连接到 PA0 引脚上
// （注意：有些开发板PA0引脚上还有开关，这时候引脚上可能会连接个电容,这时候实验会无法复现，可以通过将按钮按下来避免这个问题）
void TimerInit(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    // 初始化定时器时钟，初始化GPIOA时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 配置外部时钟模式2
    TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x0F);

    TIM_TimeBaseInitStruct.TIM_Prescaler = 1 - 1;                // psc
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; // 指定计数器模式, 向上计次
    TIM_TimeBaseInitStruct.TIM_Period = 10 - 1;                  // arr
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;     // 时钟分频
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;            // 重复计数(高级定时器才有)
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    TIM_Cmd(TIM2, ENABLE);
}

// 获取计数器值
uint16_t Timer_GetCounter(void)
{
    return TIM_GetCounter(TIM2);
}

void GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
// 初始化NVIC
void My_NVIC_Init(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 中断优先级分组

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;           // 中断号
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // 是否使能中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; // 抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        // 中断子优先级
    NVIC_Init(&NVIC_InitStructure);
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {
        // code
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}