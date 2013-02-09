// Example config file, based on my current setup
// ==============================================

#ifndef LM16A211_CONFIG_H
#define LM16A211_CONFIG_H

#include "xc.h"

// Turn RB0, RB1, RB2, RB3 into output pins.
#define PREPARE_FOR_READ_FROM_LCD \
    TRISB |= 0b00001111

// Turn RBO, RB1, RB2, RB3 into input pins.
#define PREPARE_FOR_WRITE_TO_LCD \
    TRISB &= 0b11110000

#define PRE_LCD_INIT \
    /* Set input/output pins. */ \
    TRISB = 0b00110000; \
    /* Set RC14 into an input pin. */ \
    TRISCbits.TRISC14 = 0; \
    /* Clear the output bits. */ \
    LATB = 0; \
    LATC = 0; \
    /* Change to digital pins. */ \
    ADPCFG = 0b11111111;

// PIC Output pins to the LCD, available after PREPARE_FOR_WRITE_TO_LCD.
#define LCD_E  LATBbits.LATB7
#define LCD_RS LATBbits.LATB6
#define LCD_RW LATCbits.LATC14
#define LCD_D4 LATBbits.LATB0
#define LCD_D5 LATBbits.LATB1
#define LCD_D6 LATBbits.LATB2
#define LCD_D7 LATBbits.LATB3

// PIC Input port to the LCD. Available after PREPARE_FOR_READ_FROM_LCD.
#define LCD_D7_WHEN_READABLE PORTBbits.RB3

#endif // LM16A211_CONFIG_H