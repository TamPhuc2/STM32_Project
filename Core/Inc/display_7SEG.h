/*
 * display_7SEG.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_DISPLAY_7SEG_H_
#define INC_DISPLAY_7SEG_H_

#include "main.h"
#include "global.h"

#define MAX_LED 	3

extern const uint8_t SEG_CC[10];
extern int led_buffer[MAX_LED];

uint8_t invert_byte(uint8_t x);

static inline void clk_pulse(void);
static inline void latch_pulse(void);
void shift_byte(uint8_t data);
void HC595_Send3_GPIO(uint8_t b3, uint8_t b2, uint8_t b1);

#endif /* INC_DISPLAY_7SEG_H_ */
