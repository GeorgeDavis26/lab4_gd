// STM32L432KC_UPCNT.c
// Source code for UPCOUNT configuration 
// TIM16 handles the duration of the
// the note played, found in main.c


#define DURATION_PSC    700
#include "STM32L432KC_TIM16.h"

void configureTIM16() {
/*
UPCOUNTING MODE 28.5.2
In upcounting mode, the counter counts from 0 to the auto-reload value (content of the
TIM16_ARR register), then restarts from 0 and generates a counter overflow event
*/
    TIM16->PSC = DURATION_PSC; // set prescaler to 700
    TIM16->CR1 |= 1; //enable counter CEN bit
    TIM16->CR1 |= (1 << 7); //set ARPE bit
}
