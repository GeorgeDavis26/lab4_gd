/*
AUTHOER : George Davis
Date    : 9/25/2025
File    : STM32L432KC_TIM16.h
Purpose :  Source code for TIM16 functions
           this file configures the timer to PWM mode
*/

// STM32L432KC_TIM16.c


#include "STM32L432KC_TIM16.h"

#define FREQUENCY_PSC    10

void configureTIM16(){
/*
PWM MODE 28.5.10 REF MANUAL
Pulse Width Modulation mode allows you to generate a signal with a frequency determined
by the value of the TIM16_ARR register and a duty cycle determined by the value of the
TIM16_CCRx register.
*/


    TIM16->CR1 &= ~(1 << 0); //CEN bit

    //clear bits to set channel 1 to output mode
    TIM16->CCMR1 &= ~(1 << 1);
    TIM16->CCMR1 &= ~(1 << 0);

    TIM16->PSC = FREQUENCY_PSC; //set PSC
    TIM16->ARR = 0xFFFF; // set ARR to arbitrary value for init

    //set TIM16 to PWM mode 1
    //clear ocm
    TIM16->CCMR1 &= ~(0b111 << 4);
    TIM16->CCMR1 |= (1 << 6); //OC1M[2:1] set to 3'b11
    TIM16->CCMR1 |= (1 << 5); //OC1M[2:1] set to 3'b11
    TIM16->CCMR1 &= ~(1 << 4); //OC1M[0] cleared

    //enable the buffer
    TIM16->CR1 |= (1 << 7); //ARPE set to 1

    //enable preload regiser 1 
    TIM16->CCMR1 |= (1 << 3); //OC1PE set to 110
    TIM16->CCMR1 &= ~(1 << 1);
    TIM16->CCMR1 &= ~(1 << 0);

    TIM16->BDTR |= (1 << 15); //MOE set to 1

    TIM16->CCR1 = (0xFFFF)/2; //set pwn to 50 percent

    //enable OC1 output
    TIM16->CCER &= ~(1 << 1); //CC1P CLEARED

    TIM16->CCER |= (1 << 0); //CC1E enabled

//    TIM16->CNT = 0; // set counter low v
    TIM16->EGR |= (1 << 0); //UG bit
    TIM16->CR1 |= (1 << 0); //CEN bit
}