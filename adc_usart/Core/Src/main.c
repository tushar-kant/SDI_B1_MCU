#include "stm32f4xx.h"
void delay(int sec);
void Usart_Init(void);
void USART1_write(char data);
void ADC_Init(void);

int main (void)
{
	int result;
	ADC_Init();
	Usart_Init();

	while (1)
	{
		ADC1->CR2 |= (1<<30); 		/* start a conversion */
		while(!(ADC1->SR & 2)) {} 		/* wait for conv complete */
		result = ADC1->DR; 				/* read conversion result */
		USART1_write(result);
		delay(200);
		if (result & 0x1)
			GPIOA->BSRR |= (1<<5); 		/* turn on LED */
		else
			GPIOA->BSRR |= (1<<21); 		/* turn off LED */
	}
}

void ADC_Init(void)
{
	/* set up pin PA5 for LED */
		RCC->AHB1ENR |= 1; 					/* enable GPIOA clock */
		GPIOA->MODER &= ~0xC00; 		/* clear pin mode */
		GPIOA->MODER |= 0x400; 		/* set pin to output mode */

		/* set up pin PA1 for analog input */
		RCC->AHB1ENR |= 1; 					/* enable GPIOA clock */
		GPIOA->MODER |= 0xC; 				/* PA1 analog */

		/* setup ADC1 */
		RCC->APB2ENR |= 0x100; 		/* enable ADC1 clock */
		ADC1->CR2 |= 3; 					/* enable ADC1 */
}

void Usart_Init(void)
{
	RCC->APB2ENR |= 0x10; 						//Enable APB2ENR
	RCC->AHB1ENR |= 0x1; 							//Enable GPIOA port
	RCC->AHB1ENR |=0X4;
	GPIOA->MODER &=~0x3C0000;							//clear pa9 and pa10
	GPIOA->MODER |= 0x280000; 							//Alernate Function at PA9 AND PA10
	GPIOA->AFR[1] &=~0xFF0;						//clear pa9 and pa10
	GPIOA->AFR[1] |=0x770; 						//Enable USART1 FOR pa9 and pa10
	USART1->BRR |= 0x683; 							//9600 Baud Rate
	//USART1->CR1 |= 0x4; 							//Rx Mode PA10
	USART1->CR1 |=0x8;								//Tx Mode PA9
	USART1->CR1 |= 0x2000; 							//USART1 Enable
}

void USART1_write(char data)
{
	while(!(USART1->SR & 0x80))	{}				//if 0 enters loops if 1 exits											//This loop is for Tx buffer
	USART1->DR = (data & 0xFF);						//Sending data to data register
}
void delay(int sec)
{
	for(;sec>0;sec--)
	{
		for(int count1=0;count1<3000;count1++);
	}
}
