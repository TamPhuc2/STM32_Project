/*
 * mode_hold_spin.c
 *
 *  Created on: Dec 9, 2025
 *      Author: tntam
 */


#include "mode_hold_spin.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "random_gen.h"


void mode_hold_spin(){
	if(isButtonPressed(1) == 1){
		spin_flag = 1;
		//setup lcd
		reset_animation_pos();
		lcd_clear_display();
		display_while_playing();

		//speed
		setTimer(SPIN, 10);

		update_led_buffer(random_digit(), random_digit(), random_digit());
		display_3_digit();

		setButtonFlag(1);
	}

	//spinning
	if(spin_flag == 1) {
		display_while_playing();

		if(isTimerExpired(SPIN)){
			update_led_buffer(random_digit(), random_digit(), random_digit());
			display_3_digit();
			setTimer(SPIN, 100);
		}
	}
	//stop spin
	if(isButtonReleased(1) == 1  && spin_flag == 1){
		spin_flag = 0;

		if(check_result_single_player()){
			display_announcement(BIGWIN);
			display_list_button();
		}

		else{
			display_announcement(BETTER_LUCK_NEXT_TIME);
			display_list_button();
		}

	}
}

void display7SEG_mode_hold_spin(){
	led_buffer[0] = 0;
	led_buffer[1] = 0;
	led_buffer[2] = 2;
	display_3_digit();
}
