#include "stm32f10x.h"  // Device header

void delay_ms(uint32_t ms);  

int main(void)
{
    RCC->APB2ENR |= 0x10;   // Enable clock for GPIOC
    GPIOC->CRH &= 0xFF0FFFFF;
    GPIOC->CRH |= 0x00300000;  // Configure PC13 as output

    while (1)
    {
        GPIOC->ODR |= 0x2000;  // Set PC13
        delay_ms(5000);         // 500ms delay
        GPIOC->ODR &= ~0x2000; // Clear PC13
        delay_ms(5000);         // 500ms delay
    }

    return 0;
}

void delay_ms(uint32_t ms)
{
    uint32_t i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 2000; j++)  // Adjusted for 8 MHz
        {
            __asm("NOP");  // Prevent compiler optimization
        }
    }
}
