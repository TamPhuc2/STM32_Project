/*
 * mode_single_spin.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "mode_single_spin.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "random_gen.h"


void mode_single_spin(){
	if (isButtonPressed(1) == 1){
		setTimer(1, 1);
		last_time = HAL_GetTick();
	}
	if (isTimerExpired(1) == 1){
		if (HAL_GetTick() - last_time < 3000) {
			update_led_buffer(random_digit(), random_digit(), random_digit());
			display_3_digit();
			setTimer(1, 10);
		} else {
			if (check_result_single_player()){
				display_announcement(BIGWIN);
			} else {
				display_announcement(BETTER_LUCK_NEXT_TIME);
			}
		}
	}
}
