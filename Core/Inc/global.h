/*
 * global.h
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define INIT					0
#define MODE_SINGLE_SPIN		1
#define MODE_HOLD_SPIN			2
#define MODE_ACCEL_DECEL_SPIN	3
#define MODE_TWO_PLAYERS		4
#define LIST_MODES				5

#define ERROR					99

#define MAX_LED 	3

extern int status;
extern int status_temp;
extern int led_buffer[MAX_LED];
extern int last_time;
#endif /* INC_GLOBAL_H_ */
