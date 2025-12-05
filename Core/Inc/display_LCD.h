/*
 * display_LCD.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_DISPLAY_LCD_H_
#define INC_DISPLAY_LCD_H_


#include "i2c_lcd.h"
#include "software_timer.h"

typedef enum {
    MODE_1 = 1,
    MODE_2,
    MODE_3
} PlayMode;

void display_init();
void display_welcome_screen();
void display_announcement(const char* msg);
void display_playing_mode(PlayMode mode);
void display_update_blink();   // được gọi mỗi tick trong FSM


#endif /* INC_DISPLAY_LCD_H_ */
