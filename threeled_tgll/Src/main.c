#include "stm32f4xx.h"
#include"stdio.h"
void delay(int T)
{
    int i;
    while(T--){
    for(i=0;i<5000;i++);}
}



int main()
{
	int T;
	RCC->AHB1ENR |= 7;
	GPIOA->MODER |= 0x10000;
	GPIOB->MODER |= 0x10000;
	GPIOC->MODER |= 0x40000;
	while(1)
	{
		GPIOA->BSRR |= 0x100;
		delay(500);
		GPIOA->BSRR |= 0x1000000;
		delay(500);

		GPIOB->BSRR |= 0x100;
		delay(500);
		GPIOB->BSRR |= 0x1000000;
		delay(500);

		GPIOC->BSRR |= 0x200;
		delay(500);
		GPIOC->BSRR |= 0x2000000;
		delay(500);

	}
}
