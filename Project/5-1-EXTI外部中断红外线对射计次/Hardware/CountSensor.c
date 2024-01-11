#include "CountSensor.h"

void CountSensor_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    // 定义 EXTI 结构体
    EXTI_InitTypeDef EXTI_InitStructure;
    // 定义 NVIC 结构体
    NVIC_InitTypeDef NVIC_InitStructure;

    // 开启 GPIOB 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    // 开启 AFIO 时钟
    RCC_APB2PeriphClickCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    // 引脚被用作输入模式，内部上拉电阻将引脚维持在高电平。
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    // GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_Source14);

    // 14号引脚的中断模式为EXTI_Line14
    EXTI_InitStructure.EXTI_Line = EXTI_Line14;
    // 设置为中断模式
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    // 触发模式为上升沿触发
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    // 开启中断
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_Structure);

    // NVIC 分组设置
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    // 配置外部中断的 EXTI15_10_IRQn 引脚的中断
    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    // 设置了中断的抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    // 设置了中断的子优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void EXTI15_10_IRQHandler(void)
{
    // 检测中断标志位
    if (EXTI_GetTIStatus(EXTI_Line14) == SET)
    {
        // 如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动
        if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
        {
            // 业务代码
        }
    }
    // 清除中断标志，如果不清除，则会一直触发中断
    EXTI_ClearITPendingBit(EXTI_Line14);
}