#include "stm32f10x.h"                  // Device header

void delay(int time);

int main(void)
{
	RCC->APB2ENR |= (1 << 2);   //Enable PORT A
	RCC->APB2ENR |= (1 << 4);   // Enable PORT C
	
	GPIOA->CRL &= 0xFFFFFFF0;   //Reset PORTA Pin 0
	GPIOA->CRL |= (1<<3);       //Set PORTA Pin 0 as Input push pull
	
	GPIOC->CRH &= 0xFF0FFFFF;
	GPIOC->CRH |= 0x00300000;
	
	while(1)
	{
		if(GPIOA->IDR &= 0x00000001)
		{
		  delay(10);
			GPIOC->ODR ^= 0x2000;
			delay(10);
		}
		else
		{
			GPIOC->ODR = 0x2000;
		}
	}
}

void delay(int time)
{
	int t;
	for(;time>0; time--)
	{
		for(t=0; t<100000; t++)
		{}
	}
}
