#ifndef __STM32F10X_H
#define __STM32F10X_H

#define PERIPH_BASE								((unsigned int)0x40000000)
// AHB总线基地址
#define APB2PERIPH_BASE						(PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE						(PERIPH_BASE + 0x20000)

// GPIOB 外设基地址
#define GPIOB_BASE								(APB2PERIPH_BASE + 0x0C00)

// GPIOB 寄存器地址
#define GPIOB_CRL									*(unsigned int*)(GPIOB_BASE +0x00)
#define GPIOB_CRH									*(unsigned int*)(GPIOB_BASE +0x04)
#define GPIOB_IDR									*(unsigned int*)(GPIOB_BASE +0x08)
#define GPIOB_ODR									*(unsigned int*)(GPIOB_BASE +0x0C)
#define GPIOB_BSRR								*(unsigned int*)(GPIOB_BASE +0x10)
#define GPIOB_BRR									*(unsigned int*)(GPIOB_BASE +0x14)
#define GPIOB_LCKR								*(unsigned int*)(GPIOB_BASE +0x18)
	
// RCC外设基地址
#define RCC_BASE									(AHBPERIPH_BASE + 0x1000)
// RCC的APB2时钟使能寄存器地址
#define RCC_APB2ENR								*(unsigned int*)(RCC_BASE + 0x18)

#endif
