/*
 * software_timer.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer(int index, int duration);
int isTimerExpired(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
