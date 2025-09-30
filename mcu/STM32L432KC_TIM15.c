// STM32L432KC_TIM15.c
// Source code for TIM15 functions
// TIM15 handles the frequency of the
// the note played, found in main.c

#include "STM32L432KC_TIM15.h"

#define FREQUENCY_PSC    5

void configureTIM15(){
/*
PWM MODE 28.5.10 REF MANUAL
Pulse Width Modulation mode allows you to generate a signal with a frequency determined
by the value of the TIM15_ARR register and a duty cycle determined by the value of the
TIM15_CCRx register.
*/

    //configure to channel 1 to output mode
    TIM15->CCMR1 &= ~(1 << 1);
    TIM15->CCMR1 &= ~(1 << 0);
    while ((TIM15->CCMR1 & ~(0)) != 1);

    //set TIM15 to PWM mode 1
    TIM15->CCMR1 |= (3 << 6); //OC1M[2:1] set to 3'b11
    TIM15->CCMR1 &= (1 << 4); //OC1M[0] cleared

    //enable preload regiser 1 
    TIM15->CCMR1 |= (1 << 3); //OC1PE set to 1

    //enable the buffer
    TIM15->CR1 |= (1 << 7); //ARPE set to 1
    
    //enable OC1 output
    TIM15->BDTR |= (1 << 15); //MOE set to 1
    TIM15->CCER |= (1); //CC1E enabled

    //OC1 bit in CR is the output PWM!


    TIM15->PSC = FREQUENCY_PSC; //set PSC
    TIM15->EGR |= 1; //UG bit
    TIM15->CR1 |= 1; //CEN bit
}