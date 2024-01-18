#include "stm32f10x.h"
#include "Timer.h"

int main(void)
{
    NVIC_Init();
    GPIO_Init();
    TimerInit();

    while (1)
    {
        /* Place your application code here. */
        if (Timer_GetCounter() == 9)
        {
            // code
        }
    }
}