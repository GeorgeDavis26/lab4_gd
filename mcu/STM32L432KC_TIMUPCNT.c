// STM32L432KC_UPCNT.c
// Source code for UPCOUNT configuration 
// TIMx handles the duration of the
// the note played, found in main.c



#include "STM32L432KC_TIM16.h"


void configureUPCNT(TIM16_TypeDef* TIMx) {
/*
UPCOUNTING MODE 28.5.2
In upcounting mode, the counter counts from 0 to the auto-reload value (content of the
TIM16_ARR register), then restarts from 0 and generates a counter overflow event
*/

    // disable the counter to set new values
    TIMx->CR1 |= 0; //CEN bit

    // Wait till TIM16 is unlocked (e.g., off)
    while ((TIMx->CR1 & 1) != 0);

}
