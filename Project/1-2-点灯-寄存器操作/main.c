#include "stm32f10x.h"

// ���� GPIOB p0 �˿�Ϊ
int main() {
	// ������Ӧ��GPIOBʱ��
	RCC_APB2ENR |= (1<<3);
	// �������ģʽ�������� CNFy �� MODEy 
	GPIOB_CRL= ~(0x0F << (4*0));
	// ���� PB0 Ϊͨ������������ٶ�Ϊ10M
	GPIOB_CRL |= (1 << (4*0));
	
	// �������Ϊ�͵�ƽ
	GPIOB_ODR &= ~(1 << 0);
	
	while(1);
}


void SystemInit(void) {
}
