
// ���� GPIOB p0 �˿�Ϊ
int main() {
	// ������Ӧ��GPIOBʱ��
	*((unsigned int *)0x40021018) |= (1<<3);
	// �������ģʽ�������� CNFy �� MODEy 
	*((unsigned int *)0x40011000) &= ~(0x0F << (4*0));
	// ���� PB0 Ϊͨ������������ٶ�Ϊ10M
	*((unsigned int *)0x40011000) |= (1 << (4*0));
	
	// �������Ϊ�͵�ƽ
	*((unsigned int *)0x4001100C) &= ~(1 << 0);
	
	while(1);
}


void SystemInit(void) {
}
