/*
 * global.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "main.h"
#include "random_gen.h"
#include "software_timer.h"
#include "mode_single_spin.h"


#define INIT					0
#define MODE_SINGLE_SPIN		1
#define MODE_HOLD_SPIN			2
#define MODE_ACCEL_DECEL_SPIN	3
#define MODE_TWO_PLAYERS		4

extern int status;
extern int status_temp;


//define timer role
#define TIMER_BLINK				10
#define TIMER_LCD_ANIMATION     11  // [NEW] Timer ID cho hiệu ứng chạy chữ


//define cycle for timer interrupt
#define BLINK_CYCLE				250
#define LCD_UPDATE_CYCLE        200 // [NEW] Cập nhật LCD mỗi 200ms (5 khung hình/giây)

//define announcement
#define START					20
#define BIGWIN					21
#define BETTER_LUCK_NEXT_TIME	22
#define P1_LOSE					23
#define P2_LOSE					24
#define TIE						25


//setTimer(2, 3000);//spin in 3 seconds
//setTimer(3, 100);//default speed

#endif /* INC_GLOBAL_H_ */
