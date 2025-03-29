#include "stm32f10x.h"  // Device header

void delay(int time);

int main(void)
{
    RCC->APB2ENR |= 4;    // Enable clock for Port A
    RCC->APB2ENR |= 0x10; // Enable clock for Port C

    // Configure PA0 as input (floating)
    GPIOA->CRL &= ~(0xF);  // Reset PA0 mode
    GPIOA->CRL |= 0x4;     // Set PA0 as input floating

    // Configure PC13 as output
    GPIOC->CRH &= 0xFF0FFFFF;
    GPIOC->CRH |= 0x00300000;

    while (1)
    {
        if (GPIOA->IDR & 0x00000001)  // Check if PA0 is high
        {
            delay(10);
            GPIOC->ODR ^= 0x2000;  // Toggle LED
            delay(10);
        }
        else
        {
            GPIOC->ODR |= 0x2000;  // Ensure PC13 stays on
        }
    }

    return 0;
}

void delay(int time)
{
    int t;
    for (; time > 0; time--)
    {
        for (t = 0; t < 8000; t++)  // Adjusted for 8 MHz
        {
            __asm("NOP");  // Prevent compiler optimization
        }
    }
}
