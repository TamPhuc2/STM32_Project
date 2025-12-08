/*
 * logic_game.c
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#include "global.h"
#include "logic_game.h"
#include "display_7SEG.h"
#include "button.h"
#include "random_gen.h"
#include "software_timer.h"

int spin_flag = 0;
void FSM_game_control(){
	switch(status){
	case INIT:
		//display mode
		lcd_clear_display();
		display_welcome_screen();
		led_buffer[0] = 9;
		led_buffer[1] = 9;
		led_buffer[2] = 9;
		display_3_digit();

		//next state
		if(isButtonPressed(0) == 1){
			display7SEG_mode_single_spin();
			status = MODE_SINGLE_SPIN;
		}
		break;
	case MODE_SINGLE_SPIN:
		//set spin flag, speed
		if(isButtonPressed(1) == 1 && spin_flag != 1 && status == MODE_SINGLE_SPIN){
			spin_flag = 1;
			setTimer(2, 3000);//spin in 3 seconds
			setTimer(3, 100);//default speed
		}
		//spinning
		if(spin_flag == 1){
			spinning_mode_single();
		}
		//time out -> display 7SEG
		if(isTimerExpired(2)== 1){
			spin_flag = 0;
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 2;
			display_3_digit();
			spin_flag = 0;
			status = MODE_HOLD_SPIN;
		}
		break;
	case MODE_HOLD_SPIN:
		//spin
		if(isButtonPressed(1) == 1){
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 3;
			display_3_digit();
			status = MODE_ACCEL_DECEL_SPIN;
		}
		break;
	case MODE_ACCEL_DECEL_SPIN:

		//spin
		if(isButtonPressed(1) == 1){
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 4;
			display_3_digit();
			status = MODE_TWO_PLAYERS;

		}
		break;
	case MODE_TWO_PLAYERS:
		//display current mode

		//spin
		if(isButtonPressed(1) == 1){
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 0;
			status = INIT;
		}
		break;
	default:
		status = INIT;
		break;

	}

}
