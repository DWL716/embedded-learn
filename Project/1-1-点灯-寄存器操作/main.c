
// 配置 GPIOB p0 端口为
int main() {
	// 开启对应的GPIOB时钟
	*((unsigned int *)0x40021018) |= (1<<3);
	// 配置输出模式，先重置 CNFy 和 MODEy 
	*((unsigned int *)0x40011000) &= ~(0x0F << (4*0));
	// 配置 PB0 为通用推挽输出，速度为10M
	*((unsigned int *)0x40011000) |= (1 << (4*0));
	
	// 配置输出为低电平
	*((unsigned int *)0x4001100C) &= ~(1 << 0);
	
	while(1);
}


void SystemInit(void) {
}
