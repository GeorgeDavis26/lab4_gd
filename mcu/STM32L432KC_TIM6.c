// STM32L432KC_UPCNT.c
// Source code for UPCOUNT configuration 
// TIM6 handles the duration of the
// the note played, found in main.c


#define DURATION_PSC    700
#include "STM32L432KC_TIM6.h"

void configureTIM6() {
/*
UPCOUNTING MODE 28.5.2
In upcounting mode, the counter counts from 0 to the auto-reload value (content of the
TIM6_ARR register), then restarts from 0 and generates a counter overflow event
*/
    TIM6->PSC = DURATION_PSC; // set prescaler to 700
    TIM6->ARR = 0xFFFF; //LOAD an ARR value
    TIM6->CR1 |= (1 << 7); //set ARPE bit
    TIM6->EGR |= (1 << 0); //UG bit
    TIM6->CNT = 0;
    TIM6->CR1 |= (1 << 0); //enable counter CEN bit
}
