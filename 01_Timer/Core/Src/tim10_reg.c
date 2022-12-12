/*
 * timer_reg.c
 * BLINK LED WITH 1SEC DELAY GENERATION
 * step1:ENABLE GPIOA
 * step2:ENABLE Alternative pin for TIM10
 * step3:
 *
 *  Created on: Nov 30, 2022
 *      Author: PHY202209EF08
 */



#include "main.h"

void timer_delay()
{
	RCC->APB2ENR |= 0x20000;
	GPIOB->MODER |= 0x20000;
	GPIOB->AFR[1] |=0x3;
	TIM10->PSC |=15999-1;
	TIM10->ARR |= 1000-1;
	TIM10->CNT |=  0x0;
	TIM10->CR1 |= 0x1;
}
int main(){
	/*	ENABLE GPIO   */
	RCC->AHB1ENR |= 0x3;
	GPIOA->MODER |= 0x400;
//    timer_delay();
    	while(!(TIM10->SR & 1));
    	GPIOA->ODR ^=0x20;d
    		TIM10->DIER |=0x0;

}
