// STM32L432KC_FLASH.c
// Source code for FLASH functions

//SOURCED FROM PROF BRAKES EXAMPLE CODE FOR HMC E155

#include "STM32L432KC_FLASH.h"

void configureFlash() {
    FLASH->ACR |= (0b100); // Set to 4 waitstates
    FLASH->ACR |= (1 << 8); // Turn on the ART
}