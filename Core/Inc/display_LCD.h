/*
 * display_LCD.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_DISPLAY_LCD_H_
#define INC_DISPLAY_LCD_H_

// Vùng chạy trên LCD 20x4
#define RUN_COL_START   2
#define RUN_COL_END     17
#define RUN_LEN         (RUN_COL_END - RUN_COL_START + 1)
#define ARROW_LEN 3   // "<<<" hoặc ">>>"

#include "i2c_lcd.h"
#include "global.h"


void display_init();
void display_welcome_screen();
void display_announcement(int);
void display_playing_mode(int);
void display_while_playing();

#endif /* INC_DISPLAY_LCD_H_ */
