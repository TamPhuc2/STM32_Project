/*
 * global.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT					0
#define MODE_SINGLE_SPIN		1
#define MODE_HOLD_SPIN			2
#define MODE_ACCEL_DECEL_SPIN	3
#define MODE_TWO_PLAYERS		4

//define timer role
#define TIMER_BLINK				10



//define cycle for timer interrupt
#define BLINK_CYCLE				250



//define announcement
#define START					20
#define BIGWIN					21
#define BETTER_LUCK_NEXT_TIME	22
#define P1_LOSE					23
#define P2_LOSE					24
#define TIE						25


extern int status;
extern int status_temp;


#endif /* INC_GLOBAL_H_ */
