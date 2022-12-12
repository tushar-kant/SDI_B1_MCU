/*
 * gpio_config.c
 *
 *  Created on: 17-Nov-2022
 *      Author: PHY202209EF08
 */

#include <stdint.h>
#include "stdio.h"
#include"stm32f411x.h"

void gpio_config(){
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&GpioLed);
}
