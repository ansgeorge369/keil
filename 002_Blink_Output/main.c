#include "stm32f10x.h"                  // Device header

void delay(int rep);

int main(void)
{
    // Enable clock for GPIOC (bit 4 in RCC->APB2ENR)
    RCC->APB2ENR |= 0x10; // APB2 enable for GPIOC

    // Configure PC13 as output (50 MHz)
    GPIOC->CRH &= 0xFF0FFFFF;  // Clear bits 20–23  -- mode bits
    GPIOC->CRH |= 0x00300000;  // Set PC13 as 50 MHz output  -- configuration bits.

    while(1)
    {
        // Set PC13 high (turn LED off if active-low)
        GPIOC->ODR |= (1 << 13);  
        delay(10);  // Wait

        // Set PC13 low (turn LED on if active-low)
        GPIOC->ODR &= ~(1 << 13); 
        delay(10);  // Wait
    }
}

// Delay function: Delay for 'rep' repetitions of a fixed inner loop
void delay(int rep)
{
    int i, j;
    for(; rep > 0; rep--)
    {
        for(i = 0; i < 100000; i++)
        {
            for(j = 0; j < 10; j++) // Nested loop for more delay
            {
                // Do nothing (empty loop for delay)
            }
        }
    }
}
