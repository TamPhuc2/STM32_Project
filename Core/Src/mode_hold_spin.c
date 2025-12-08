/*
 * mode_hold_spin.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "mode_hold_spin.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "random_gen.h"



void mode_hold_spin(){
	if (isButtonPressed(1) == 1){
		update_led_buffer(random_digit(), random_digit(), random_digit());
		display_3_digit();
		setButtonFlag(1);
	}
	if (isButtonReleased(1) == 1){
		if (check_result_single_player()){
			display_announcement(BIGWIN);
		} else {
			display_announcement(BETTER_LUCK_NEXT_TIME);
		}
	}
}

