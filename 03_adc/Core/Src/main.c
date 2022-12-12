/* A to D conversion of channel 1
* This program converts the analog input from channel 1.
* Channel 1 is connected to input from PA1.
* Clock prescaler is left at 0 (divided by 2) and Sampling
* time is also left at default of 3 cycles.
* Software trigger is used. The bit 8 of the conversion
* result is used to turn on/off the LED0.
*/


#include "stm32f4xx.h"
void ADC_Init(void);
void delay(int sec);

int main (void)
{
	int result;
	ADC_Init();

	while (1)
	{
		ADC1->CR2 |= (1<<30); 		/* start a conversion */
		while(!(ADC1->SR & 2)) {} 		/* wait for conv complete */
		result = ADC1->DR; 				/* read conversion result */
		if (result & 0x1)
		{
			GPIOA->BSRR |= (1<<5); 		/* turn on LED */
			delay(100);
		}
		else
		{
			GPIOA->BSRR |= (1<<21); 		/* turn off LED */
			delay(100);
		}
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

void delay(int sec)
{
	for(;sec>0;sec--)
	{
		for(int count1=0;count1<3195;count1++);
	}
}
