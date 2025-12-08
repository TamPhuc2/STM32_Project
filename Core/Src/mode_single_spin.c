/*
 * mode_single_spin.c
 *
 *  Created on: Dec 6, 2025
 *      Author: tntam
 */

#include "mode_single_spin.h"



void display7SEG_mode_single_spin(){
	led_buffer[0] = 0;
	led_buffer[1] = 0;
	led_buffer[2] = 1;
	display_3_digit();
	status = MODE_SINGLE_SPIN;
}

void spinning_mode_single(){
	led_buffer[0] = random_digit();
	led_buffer[1] = random_digit();
	led_buffer[2] = random_digit();
	if(isTimerExpired(3) == 1){
		display_3_digit();
		setTimer(3, 120);
	}
}
