// STM32L432KC_TIM15.h
// Header for TIM15 functions

#ifndef STM32L4_TIM15_H
#define STM32L4_TIM15_H

#include <stdint.h> //standard integer header file for C programming

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile // Define __IO as volatile

// Base addresses for TIM15 ports
#define TIM15_BASE  (0x40014000UL)

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for TIM15
///////////////////////////////////////////////////////////////////////////////

// TIM15 register structs here
typedef struct {
    __IO uint32_t CR1;       // TIM15 control register 1                   OFFSET: 0x00
    __IO uint32_t CR2;       // TIM15 control register 2                   OFFSET: 0x04
    __IO uint32_t SMCR;      // TIM15 slave mode control register          OFFSET: 0x08
    __IO uint32_t DIER;      // TIM15 DMA/interrupt enable register        OFFSET: 0x0C
    __IO uint32_t SR;        // TIM15 status register                      OFFSET: 0x10
    __IO uint32_t EGR;       // TIM15 event generation register            OFFSET: 0x14
    __IO uint32_t CCMR1;     // TIM15 capture/compare mode register 1      OFFSET: 0x18
         uint32_t RESERVED1; //                                            OFFSET: 0x1C
    __IO uint32_t CCER;      // TIM15 capture/compare enable register      OFFSET: 0x20
    __IO uint32_t CNT;       // TIM15 counter                              OFFSET: 0x24
    __IO uint32_t PSC;       // TIM15 prescaler                            OFFSET: 0x28
    __IO uint32_t ARR;       // TIM15 auto-reload register                 OFFSET: 0x2C
    __IO uint32_t RCR;       // TIM15 repetition counter register          OFFSET: 0x30
    __IO uint32_t CCR1;      // TIM15 capture/compare register 1           OFFSET: 0x34
    __IO uint32_t CCR2;      // TIM15 capture/compare register 2           OFFSET: 0x38
         uint32_t RESERVED2; //                                            OFFSET: 0X3C
         uint32_t RESERVED3; //                                            OFFSET: 0X40
    __IO uint32_t BDTR;      // TIM15 break and dead-time register         OFFSET: 0x44
    __IO uint32_t DCR;       // TIM15 DMA control register                 OFFSET: 0x48
    __IO uint32_t DMAR;      // TIM15 DMA address for full transfer        OFFSET: 0x4C
    __IO uint32_t OR1;       // TIM15 option register 1                    OFFSET: 0x50
         uint32_t RESERVED4; //                                            OFFSET: 0x54
         uint32_t RESERVED5; //                                            OFFSET: 0x58
         uint32_t RESERVED6; //                                            OFFSET: 0x5C
    __IO uint32_t OR2;       // TIM15 option register 2                    OFFSET: 0x60
} TIM15_TypeDef; 

// Pointers to TIM15-sized chunks of memory for each peripheral
#define TIM15 ((TIM15_TypeDef *) TIM15_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////


void configurePWM(TIM15_TypeDef* TIMx);

#endif