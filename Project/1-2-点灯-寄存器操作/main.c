#include "stm32f10x.h"

// 配置 GPIOB p0 端口为
int main() {
	// 开启对应的GPIOB时钟
	RCC_APB2ENR |= (1<<3);
	// 配置输出模式，先重置 CNFy 和 MODEy 
	GPIOB_CRL= ~(0x0F << (4*0));
	// 配置 PB0 为通用推挽输出，速度为10M
	GPIOB_CRL |= (1 << (4*0));
	
	// 配置输出为低电平
	GPIOB_ODR &= ~(1 << 0);
	
	while(1);
}


void SystemInit(void) {
}
