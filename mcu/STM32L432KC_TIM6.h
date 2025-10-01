
/*
AUTHOER : George Davis
Date    : 9/25/2025
File    : STM32L432KC_TIM16.h
*/

//Purpose
// Header for TIM6 functions

#ifndef STM32L4_TIM6_H
#define STM32L4_TIM6_H

#include <stdint.h> //standard integer header file for C programming

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile // Define __IO as volatile

// Base addresses for TIM6 ports
#define TIM6_BASE  (0x40001000UL)

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for TIM6
///////////////////////////////////////////////////////////////////////////////

// TIM6 register structs here
typedef struct {
    __IO uint32_t CR1;       // TIM6 control register 1                   OFFSET: 0x00
    __IO uint32_t CR2;       // TIM6 control register 2                   OFFSET: 0x04
         uint32_t RESERVED1; //                                           OFFSET: 0x08
    __IO uint32_t DIER;      // TIM6 DMA/interrupt enable register        OFFSET: 0x0C
    __IO uint32_t SR;        // TIM6 status register                      OFFSET: 0x10
    __IO uint32_t EGR;       // TIM6 event generation register            OFFSET: 0x14
         uint32_t RESERVED2; //                                           OFFSET: 0x18
         uint32_t RESERVED3; //                                           OFFSET: 0x1C
         uint32_t RESERVED4; //                                           OFFSET: 0x20
    __IO uint32_t CNT;       // TIM6 counter                              OFFSET: 0x24
    __IO uint32_t PSC;       // TIM6 prescaler                            OFFSET: 0x28
    __IO uint32_t ARR;       // TIM6 auto-reload register                 OFFSET: 0x2C
} TIM6_TypeDef; 

// Pointers to TIM6-sized chunks of memory for each peripheral
#define TIM6 ((TIM6_TypeDef *) TIM6_BASE)

////////////X///////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////


void configureTIM6(void);

#endif