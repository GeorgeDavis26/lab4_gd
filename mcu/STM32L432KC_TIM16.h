// STM32L432KC_TIM16.h
// Header for TIM16 functions

#ifndef STM32L4_TIM16_H
#define STM32L4_TIM16_H

#include <stdint.h> //standard integer header file for C programming

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile // Define __IO as volatile

// Base addresses for TIM16 ports
#define TIM16_BASE  (0x40014400UL)

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for TIM16
///////////////////////////////////////////////////////////////////////////////

// TIM16 register structs here
typedef struct {
    __IO uint32_t CR1;       // TIM16 control register 1                   OFFSET: 0x00
    __IO uint32_t CR2;       // TIM16 control register 2                   OFFSET: 0x04
         uint32_t RESERVED1; //                                            OFFSET: 0x08
    __IO uint32_t DIER;      // TIM16 DMA/interrupt enable register        OFFSET: 0x0C
    __IO uint32_t SR;        // TIM16 status register                      OFFSET: 0x10
    __IO uint32_t EGR;       // TIM16 event generation register            OFFSET: 0x14
    __IO uint32_t CCMR1;     // TIM16 capture/compare mode register 1      OFFSET: 0x18
         uint32_t RESERVED2; //                                            OFFSET: 0x1C
    __IO uint32_t CCER;      // TIM16 capture/compare enable register      OFFSET: 0x20
    __IO uint32_t CNT;       // TIM16 counter                              OFFSET: 0x24
    __IO uint32_t PSC;       // TIM16 prescaler                            OFFSET: 0x28
    __IO uint32_t ARR;       // TIM16 auto-reload register                 OFFSET: 0x2C
    __IO uint32_t RCR;       // TIM16 repetition counter register          OFFSET: 0x30
    __IO uint32_t CCR1;      // TIM16 capture/compare register 1           OFFSET: 0x34
         uint32_t RESERVED3; //                                            OFFSET: 0x38
         uint32_t RESERVED4; //                                            OFFSET: 0x3C
         uint32_t RESERVED5; //                                            OFFSET: 0x40
    __IO uint32_t BDTR;      // TIM16 break and dead-time register         OFFSET: 0x44
    __IO uint32_t DCR;       // TIM16 DMA control register                 OFFSET: 0x48
    __IO uint32_t DMAR;      // TIM16 DMA address for full transfer        OFFSET: 0x4C
    __IO uint32_t OR1;       // TIM16 option register 1                    OFFSET: 0x50
         uint32_t RESERVED6; //                                            OFFSET: 0x54
         uint32_t RESERVED7; //                                            OFFSET: 0x58
         uint32_t RESERVED8; //                                            OFFSET: 0x5C
    __IO uint32_t OR2;       // TIM16 option register 2                    OFFSET: 0x60
} TIM16_TypeDef;

// Pointers to TIM16-sized chunks of memory for each peripheral
#define TIM16 ((TIM16_TypeDef *) TIM16_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void configureTIM16(void);
#endif