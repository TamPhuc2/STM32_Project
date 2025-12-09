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
#include "mode_accel_decel_spin.h"
#include "mode_hold_spin.h"
#include "mode_two_players.h"


#define INIT					0
#define MODE_SINGLE_SPIN		1
#define MODE_HOLD_SPIN			2
#define MODE_ACCEL_DECEL_SPIN	3
#define MODE_TWO_PLAYERS		4
#define LIST_MODES				5
#define WELCOME_SCREEN			6
#define HOME_SCREEN				7

#define ERROR					99
#define MAX_LED 	3

extern int status;
extern int status_temp;
extern int choose_mode;

extern int led_buffer[MAX_LED];
extern int last_time;
extern int spin_flag;

#define SPIN	2
#define TIMER_WAIT_RESULT 8



//setTimer(2, 3000);//spin in 3 seconds
//setTimer(3, 100);//default speed

#endif /* INC_GLOBAL_H_ */
