/*
AUTHOER : George Davis
Date    : 9/25/2025
File    : main.c
Purpose : main C file for E155 lab 4
          Plays Fur Elise on a speaker using the STM32L4KC timer peripherals

*/

#include "STM32L432KC_RCC.h"

#include "STM32L432KC_FLASH.h"

#include "STM32L432KC_TIM15.h"

#include "STM32L432KC_TIM16.h"

#include "STM32L432KC_GPIO.h"

// The PLL is configured as the sysclk and input to TIM15/16
//lab4_starter constaints a const int of pitches and durations

//Create a PWM at GPIO pin 3
// Need two timers -- TIM15 in PWM mode driving the frequency
//                 -- TIM16 in up counting mode driving the duration of the note

// Define macros for constants
#define AUDIO_PIN           8 //PIN A2
#define DURATION_PSC    700
#define FREQUENCY_PSC    5



void duration(uint16_t dur_DUR){

    // timer_f = clk_f / ((PSC + 1)(ARR + 1))
    //timer_f range 2 Hz - 32 Hz
    uint16_t freq_DUR= 1/(dur_DUR  * 10^-3);
    uint16_t arr_DUR = (80000000 / ((DURATION_PSC+1)*(freq_DUR))) -1;

    TIM16->ARR = arr_DUR; // Set auto reload register to duration of the note
    TIM15->EGR |= 1; //UG bit
    TIM16->SR |= 1; //clear UIF
    TIM16->CNT = 0; // Set counter to 0 to begin the timer
}

void frequency(uint16_t freq_FREQ) {
    // timer_f = clk_f / ((PSC + 1)(ARR + 1))
    //timer_f range 220 Hz - 1000 Hz
    int16_t arr_FREQ = (80000000 / ((FREQUENCY_PSC+1)*(freq_FREQ))) -1;

    TIM15->ARR = arr_FREQ;
    TIM15->EGR |= 1; //UG bit
    TIM15->CNT = 0;  // Set counter to 0 to begin the timer
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

    configureFlash(); // config flash
    configureClock(); // configure clock, timers and GPIO
    RCC->APB2ENR |= (1 << 16); // SET TIM15 clk to sysclk PLL = 80MhZ
    RCC->APB2ENR |= (1 << 17); // SET TIM16 clk to sysclk PLL = 80MhZ
    RCC->AHB2ENR |= (1 << 1);  // Turn on clock to GPIOB
    GPIOA->AFRL |= (14 << 11); //GPIOA PA2 AFRL set to AF14

    configureTIM15(); // SET TO PWM MODE
    configureTIM16();

    pinMode(AUDIO_PIN, GPIO_ALT);

    uint16_t i = 0;
    
    while(notes[i][1] != 0){
        uint16_t dur = notes[i][1];
        uint16_t freq = notes[i][0];
        frequency(freq);
        duration(dur);
        while((TIM16->SR >> 0 & 1) != 1){
            __asm("nop");
        i = i + 1;
        }
    }
}

/*************************** End of file ****************************/