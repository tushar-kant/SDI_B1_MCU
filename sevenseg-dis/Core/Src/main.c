 #include"stm32f4xx.h"
void delay(int T)
{
	int i;
	while(T--)
	{
		for(i=0;i<5000;i++);
	}
}
int main()
{
	int LED;
	RCC->AHB1ENR |= 4;
	GPIOC->MODER |= 0x400;
	while(1)
	{
		//GPIOC->ODR |= 0x01010000;
		//delay(100);
//		GPIOA->ODR &= ~0x20;
//		delay(100);
		//FOR COUNT 0
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
			  HAL_Delay(5000);
			  //FOR COUNT 1
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
			  HAL_Delay(5000);
			  //FOR COUNT 2
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);//A
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);//B
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 1);//C
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);//D
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);//E
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);//F
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G
			  HAL_Delay(5000);
			  //FOR COUNT 3
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G
			  HAL_Delay(5000);
			  //FOR COUNT 4
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G

			  HAL_Delay(5000);
			  //FOR COUNT 5
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 1);
			  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G

	          HAL_Delay(5000);
	          //FOR COUNT 6
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 1);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G

	          HAL_Delay(5000);
	          //FOR COUNT 7
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 1);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G

	          HAL_Delay(5000);
	          //FOR COUNT 8
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G

	          HAL_Delay(5000);
	          //FOR COUNT 9
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
	          HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 0);//G
	          HAL_Delay(5000);
		    /* USER CODE BEGIN 3 */
		  }
		  /* USER CODE END 3 */

}
