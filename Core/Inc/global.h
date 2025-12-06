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

//setTimer(2, 3000);//spin in 3 seconds
//setTimer(3, 100);//default speed

#endif /* INC_GLOBAL_H_ */
