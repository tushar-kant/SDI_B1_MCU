#ifndef INC_STM32F411X_H_
#define INC_STM32F411X_H_
#include<stddef.h>
#include<stdint.h>
#define __vo volatile


/*Base Address of FLASH and SRAM1 memory locations */


#define FLASH_BASEADDR 0x8000000U
#define SRAM_BASEADDR 0x20000000U
#define ROM_BASEADDR 0x1FFF0000U


/*AHBx and APBx Peripheral Base address*/


#define PERIPH_BASEADDR 0x40000000U
#define APB1PERIPH_BASE PERIPH_BASEADDR
#define APB2PERIPH_BASE 0x40010000U
#define AHB1PERIPH_BASE 0x40020000U
#define AHB2PERIPH_BASE 0x50000000U


/*Base address of peripherals hanging on AHB1 bus*/


#define GPIOA_BASEADDR 0x40020000U
#define GPIOB_BASEADDR 0x40020400U
#define GPIOC_BASEADDR 0x40020800U
#define GPIOD_BASEADDR 0x40020C00U
#define GPIOE_BASEADDR 0x40021000U
#define GPIOH_BASEADDR 0x40021C00U
#define CRC_BASEADDR   0X40023000U
#define RCC_BASEADDR   0X40023800U
#define DMA1_BASEADDR 0X40026000U
#define DMA2_BASEADDR 0X40026400U
#define Flash_interface_Register_BASEADDR 0X40023C00U



//typedef struct
//{
//	__vo uint32_t AHB1ENR;
//	__vo uint32_t AHB1RSTR;
//
//
//}RCC_RegDef_t;

typedef struct
{
  __vo uint32_t CR;            /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t PLLCFGR;       /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t CFGR;          /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t CIR;           /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t AHB1RSTR;      /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t AHB2RSTR;      /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t AHB3RSTR;      /*!< TODO,     										Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                       */
  __vo uint32_t APB1RSTR;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t APB2RSTR;      /*!< TODO,     										Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                  */
  __vo uint32_t AHB1ENR;       /*!< TODO,     										Address offset: 0x30 */
  __vo uint32_t AHB2ENR;       /*!< TODO,     										Address offset: 0x34 */
  __vo uint32_t AHB3ENR;       /*!< TODO,     										Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                       */
  __vo uint32_t APB1ENR;       /*!< TODO,     										Address offset: 0x40 */
  __vo uint32_t APB2ENR;       /*!< TODO,     										Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                  */
  __vo uint32_t AHB1LPENR;     /*!< TODO,     										Address offset: 0x50 */
  __vo uint32_t AHB2LPENR;     /*!< TODO,     										Address offset: 0x54 */
  __vo uint32_t AHB3LPENR;     /*!< TODO,     										Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                       */
  __vo uint32_t APB1LPENR;     /*!< TODO,     										Address offset: 0x60 */
  __vo uint32_t APB2LPENR;     /*!< RTODO,     										Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                  */
  __vo uint32_t BDCR;          /*!< TODO,     										Address offset: 0x70 */
  __vo uint32_t CSR;           /*!< TODO,     										Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                  */
  __vo uint32_t SSCGR;         /*!< TODO,     										Address offset: 0x80 */
  __vo uint32_t PLLI2SCFGR;    /*!< TODO,     										Address offset: 0x84 */
  __vo uint32_t PLLSAICFGR;    /*!< TODO,     										Address offset: 0x88 */
  __vo uint32_t DCKCFGR;       /*!< TODO,     										Address offset: 0x8C */
  __vo uint32_t CKGATENR;      /*!< TODO,     										Address offset: 0x90 */
  __vo uint32_t DCKCFGR2;      /*!< TODO,     										Address offset: 0x94 */

} RCC_RegDef_t;
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

#define GPIOA 					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH 					((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define RCC 					((RCC_RegDef_t*)RCC_BASEADDR)


#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |= (1<<7))



/*Base address of peripherals hanging on APB1 bus*/


#define TIM2_BASEADDR 0X40000000U
#define TIM3_BASEADDR 0X40000400U
#define TIM4_BASEADDR 0X40000800U
#define TIM5_BASEADDR 0X40000C00U
#define RTC_BKP_reg_BASEADDR 0X40002800U
#define WWDG_BASEADDR 0X40002C00U
#define IWDG_BASEADDR 0X40003000U
#define I2S2ext_BASEADDR 0X40003400U
#define SPI_I2S2_BASEADDR 0X40003800U
#define SPI_I2S3_BASEADDR 0X40003C00U
#define I2S3ext_BASEADDR 0X40004000U
#define USART2_BASEADDR 0X40004400U
#define I2C1_BASEADDR 0X40005400U
#define I2C2_BASEADDR 0X40005800U
#define I2C3_BASEADDR 0X40005C00U
#define PWM_BASEADDR 0X40007000U


/*Base address of peripherals hanging on APB2 bus*/
#define TIM1_BASEADDR 0X40010000U
#define USART1_BASEADDR 0X40011000U
#define USART6_BASEADDR 0X40011400U
#define ADC_BASEADDR 0X40012000U
#define SDIO_BASEADDR 0X40012C00U
#define SPI_I2S1_BASEADDR 0X40013000U
#define SPI_I2S4_BASEADDR 0X40013400U
#define SYSCFG_BASEADDR 0X40013800U
#define EXTI_BASEADDR 0X40013C00U
#define TIM9_BASEADDR 0X40014000U
#define TIM10_BASEADDR 0X40014400U
#define TIM11_BASEADDR 0X40014800U
#define SPI_I2S5_BASEADDR 0X40015000U
#endif /* INC_STM32F411X_H_ */

#define GPIOA_REG_RESET()					do{	(RCC->AHB1RSTR |= (1<<0)); RCC->AHB1RSTR &= ~(1<<0); }while(0)
#define GPIOB_REG_RESET()					do{	(RCC->AHB1RSTR |= (1<<0)); RCC->AHB1RSTR &= ~(1<<1); }while(0)
#define GPIOC_REG_RESET()					do{	(RCC->AHB1RSTR |= (1<<0)); RCC->AHB1RSTR &= ~(1<<2); }while(0)

#define GPIO_BASEADDR_TO_CODE(x)		(   (x==GPIOA)?0:\
											(x==GPIOB)?1:\
											(x==GPIOC)?2:\
											(x==GPIOD)?3:\
											(x==GPIOE)?4:0  )
// defining generic macros
#define ENABLE 		 		 1
#define DISABLE 			 0
#define SET 			     ENABLE
#define RESET 				 DISABLE
#define GPIO_PIN_SET 		 SET
#define GPIO_PIN_RESET		 RESET

#include "stm32f411x_driver_gpio.h"
