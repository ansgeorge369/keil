#include "stm32f10x.h" // Device header

void delay(int n);

int main(void)
{
    // Enable GPIOC clock
    RCC->APB2ENR |= (1 << 4);
    
    // Configure PC13 as output at 50 MHz
    GPIOC->CRH &= ~((uint32_t)0xF << 20); // Clear bits 20-23
    GPIOC->CRH |= (0x3 << 20);  // Set mode 50 MHz output
    
    while(1)
    {
        GPIOC->ODR ^= 0x2000; // Toggle PC13
        delay(500);           // Delay
    }
}

void delay(int n)
{
    int i;
    for(; n > 0; n--)
    {
        for(i = 0; i < 3340; i++);
    }
}
