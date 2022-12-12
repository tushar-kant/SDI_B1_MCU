#include "stm32f4xx.h"
#include <stdio.h>


void delay(int T)
{
    int i;
    while(T--){
    for(i=0;i<5000;i++);}
}



int main()
{    int T;
    RCC ->AHB1ENR |= 7;
    GPIOA->MODER = 0X10000;
    GPIOB->MODER = 0X10000;
    GPIOC->MODER = 0X40000;
    while(1)
    {
        GPIOA->ODR |= 0x100; // 0000 0001 0000 0000

        GPIOB->ODR |= 0x100; // 0000 0001 0000 0000

        GPIOC->ODR |= 0x200; // 0000 0010 0000 0000

        GPIOA->ODR &= ~0x100; // 0000 0001 0000 0000

        GPIOB->ODR &= ~0x100; // 0000 0001 0000 0000

        GPIOC->ODR &= ~0x200; // 0000 0010 0000 0000




   }
}
