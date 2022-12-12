//
//toggle led on button pressed with falling edge
//output device->LED(PA5)
//input device ->switch(pc13)



#include "main.h"

void delay(int T){
	while(T--){
		for(int i=0;i<3000;i++);}
}
void LED_Init()
{
	RCC->AHB1ENR  |=0x1;
	GPIOA->MODER   |= 0x400;
}
void Button_Init(){
		RCC->AHB1ENR  |=0x4;
		GPIOC->MODER   |= 0x0;
}
void Toggle_pin(){
	GPIOA->ODR ^=0x20;
	delay(100);
}
void EXTI_myirq(void){
		GPIOA->ODR ^=0x20;
		delay(100);
		EXTI->PR |=0x2000;
	}
int main(){
	__disable_irq();
		LED_Init();
		Button_Init();
	RCC->APB2ENR |=0x4000;
	SYSCFG->EXTICR[3] |= 0x20;
	EXTI->IMR |=0x2000;
	EXTI->FTSR |=0x2000;

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq();


	while(1)
	{
//		Toggle_pin();
	}


}
