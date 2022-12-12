/*
 * USART_Reg.c
 *1.protocol selected : USART2
 *2.ENABLE APB1 Clock with RCC
 *3.ENABLE AHB1 Clock with RCC
 *4.Alternative function of PA2 As USART2_Tx
 *5.Alternative  function of PA3 As USART2_Rx
 *
 *  Created on: Nov 23, 2022
 *      Author: PHY202209EF08
 */
#include  "main.h"
void Sconfig_Init()
{
	RCC->APB1ENR |= 0x20000;
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x20;
	GPIOA->AFR[0] |=0x700;
	USART2->BRR  |= 0x683;  // 9600 baudrate
	USART2->CR1 |= 0x8;
	USART2->CR1 |= 0x2000;

}
void USART2_Tx(unsigned char data)
{
	while( !(USART2->SR & 0x80)){}
	USART2->DR |=(data & 0xff);

}
void USART2_Send(unsigned char *str)
{
	while(*str){
		USART2_Tx(*str);
		str++;
	}

}


void delay(int T)
{
	while(T--)
	{
		for(int i=0;i<10000;i++);
	}
}

int main()
{
	Sconfig_Init();
//	while(1){
//		USART2_Tx('H');
//		delay(500);
//		USART2_Tx('E');
//		delay(500);
//		USART2_Tx('L');
//		delay(500);
//		USART2_Tx('L');
//		delay(500);
//		USART2_Tx('O');
//		delay(500);
//
//
//
//	}
	while(1){
		USART2_Send("hello tushar\r\n");
		delay(500);
	}


}

