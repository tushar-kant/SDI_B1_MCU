#include <stdint.h>
#include "stdio.h"
#include"stm32f411x.h"
void delay(int T)
{
	while(T--)
	{
		for(uint32_t i=0;i<500000;i++);
	}
}

int main(void)
{
//	GPIO_Handle_t GpioLed;
//	GpioLed.pGPIOx = GPIOA;
//	GpioLed.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_5;
//	GpioLed.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_OUT;
//	GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_LOW;
//	GpioLed.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
//	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;
//	GPIO_PeriClockControl(GPIOA,ENABLE);
//	GPIO_Init(&GpioLed);
	gpio_config();
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
		delay(5);
	}
}
