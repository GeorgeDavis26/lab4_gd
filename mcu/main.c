/*
AUTHOER : George Davis
Date    : 9/25/2025
File    : main.c
Purpose : main C file for E155 lab 4
          Plays Fur Elise on a speaker using the STM32L4KC timer peripherals

*/

#include "STM32L432KC_RCC.h"

#include "STM32L432KC_TIM15.h"

#include "STM32L432KC_TIM16.h"

#include "STM32L432KC_GPIO.h"

// The PLL is configured as the sysclk and input to TIM15/16
//lab4_starter constaints a const int of pitches and durations

//Create a PWM at GPIO pin 3
// Need two timers -- TIM15 in PWM mode driving the frequency
//                 -- TIM16 in up counting mode driving the duration of the note


void duration(int dur, TIM16_TypeDef* TIMx){
    // disable the counter to set new values
    TIMx->CR1 &= ~(1 << 0); //CEN bit

    // timer_f = clk_f / ((PSC + 1)(ARR + 1))
    //timer_f range 2 Hz - 8 Hz
    int psc = 700;
    int freq = 1/(dur  * 10^-3);
    int arr = (80000000 / ((psc+1)*(freq))) -1;

    // Set auto reload register to duration of the note
    TIMx->ARR &= ~(65536);
    TIMx->ARR = arr;

    // Set time prescaler (PSC) to 0
    TIMx->PSC = psc;

    // Set counter to 0 to begin the timer
    TIMx->CNT &= ~(65536);
    TIMx->CNT = 0;

    //clear repition counter register
    TIMx->RCR &= ~(256);

    // enable the counter to get going
    TIMx->CR1 |= 1; //CEN bit

    // UIF in TIMx SR goes high at CNT == ARR
    //TIMx->SR bit 0
}

void frequency(int freq, TIM15_TypeDef* TIMx) {
    // disable the counter to set new values
    TIMx->CR1 |= 0; //CEN bit

    // Wait till TIM15 is unlocked (e.g., off)
    while ((TIMx->CR1 & 1) != 0);

    // reinitialize the counter and generate an update of registers
    TIMx->EGR |= 1;

    // timer_f = clk_f / ((PSC + 1)(ARR + 1))
    //timer_f range 100 Hz - 1500 Hz
    int psc = 12;
    int arr = (80000000 / ((psc+1)*(freq))) -1;

    // Set time prescaler (PSC) to 0
    TIMx->PSC = psc;

    // Period of the counter set to be # of clk cycles per Hz for 50 percent Duty cycle
    TIMx->ARR &= ~(65536);
    TIMx->ARR = arr;
    // Set auto reload register to 50 DS
//    TIMx->CCR1 = arr/2;

    // Set counter to 0 to begin the timer
    TIMx->CNT &= ~(65536);
    TIMx->CNT = 0;

    // enable the counter to begin timing
    TIMx->CR1 |= 1; //CEN bit

    //Reinitialize the counter and generate an update of registers
    TIMx->EGR |= 1;//UG set high
}

const int superstition[][2] = {
{415, 31}, //A flat 16th note
{466, 62}, //B flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

//MEASURE #1

{311, 62}, //E flat 8th note
{622, 62}, //E flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

{741, 93}, //G flat dotted 8th note
{554, 32}, //D flat 16th note

{0, 31}, //rest 16th note

{466, 31}, //B flat 16th note
{741, 31}, //G flat 16th note
{741, 31}, //G flat 16th note

//MEASURE 2

{415, 62}, //A flat 8th note
{466, 62}, //B flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

{741, 93}, //G flat dotted 8th note

{466, 31}, //B flat 16th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

//MEASURE 3

{311, 62}, //E flat 8th note
{622, 62}, //E flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

{741, 93}, //G flat dotted 8th note
{554, 32}, //D flat 16th note

{0, 125}, //rest quarter note

//MEASURE 4

{415, 62}, //A flat 8th note
{466, 62}, //B flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note
{741, 93}, //G flat dotted 8th note

{466, 31}, //B flat 16th note

{0, 62}, //rest 8th note

{554, 62}, //D flat 8th note

//REPEAT

//MEASURE #1

{311, 62}, //E flat 8th note
{622, 62}, //E flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

{741, 93}, //G flat dotted 8th note
{554, 32}, //D flat 16th note

{0, 31}, //rest 16th note

{466, 31}, //B flat 16th note
{741, 31}, //G flat 16th note
{741, 31}, //G flat 16th note

//MEASURE 2

{415, 62}, //A flat 8th note
{466, 62}, //B flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

{741, 93}, //G flat dotted 8th note

{466, 31}, //B flat 16th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

//MEASURE 3

{311, 62}, //E flat 8th note
{622, 62}, //E flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note

{741, 93}, //G flat dotted 8th note
{554, 32}, //D flat 16th note

{0, 125}, //rest quarter note

//MEASURE 4

{415, 62}, //A flat 8th note
{466, 62}, //B flat 8th note
{554, 62}, //D flat 8th note
{622, 62}, //E flat 8th note
{741, 93}, //G flat dotted 8th note

{466, 31}, //B flat 16th note

{0, 62}, //rest 8th note

{554, 62}, //D flat 8th note

{0,0} //END OF SONG
};

const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};

int main(void) {

    int pin = 3;

    // configure clock, timers and GPIO
    configureClock();

    // SET TIM15 clk to sysclk PLL = 80MhZ
    RCC->APB2ENR |= (1 << 16);

    // SET TIM16 clk to sysclk PLL = 80MhZ
    RCC->APB2ENR |= (1 << 17);


    configurePWM(TIM15);

    configureUPCNT(TIM16);

    pinMode(pin, GPIO_OUTPUT);

    int i = 0;
    
    while(notes[i][1] != 0){
        int dur = notes[i][1];
        int freq = notes[i][0];
        
        duration(dur, TIM16);
        frequency(freq, TIM15);
        
        while((TIM16->SR >> 0 & 1) != 1){
            int val = TIM15->CR1;
            digitalWrite(pin, val);
            }
        i = i + 1;
    }
}

/*************************** End of file ****************************/