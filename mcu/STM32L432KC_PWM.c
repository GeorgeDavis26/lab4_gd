// STM32L432KC_TIMx.c
// Source code for TIMx functions
// TIMx handles the frequency of the
// the note played, found in main.c

#include "STM32L432KC_TIM15.h"


void configurePWM(TIM15_TypeDef* TIMx){
/*
PWM MODE 28.5.10 REF MANUAL
Pulse Width Modulation mode allows you to generate a signal with a frequency determined
by the value of the TIMx_ARR register and a duty cycle determined by the value of the
TIMx_CCRx register.
*/
    // disable the counter to set new values
    TIMx->CR1 |= 0; //CEN bit

    //set TIMx to PWM mode 1
    TIMx->CCMR1 |= (3 << 6); //OC1M[2:1] set to 3'b11
    TIMx->CCMR1 &= (1 << 4); //OC1M[0] cleared

    //enable preload regiser 1 
    TIMx->CCMR1 |= (1 << 3); //OC1PE set to 1

    //enable the buffer
    TIMx->CR1 |= (1 << 7); //ARPE set to 1

    //set OC1 polarity to active low
    TIMx->CCER &= ~(1); //CC1P cleared

    //enable OC1 output
    TIMx->BDTR |= (1 << 15); //MOE set to 1
    TIMx->CCER |= (1); //CC1E enabled

    //OC1 bit in CR is the output PWM!
}