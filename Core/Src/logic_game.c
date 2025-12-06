/*
 * logic_game.c
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

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
		led_buffer[0] = 0;
		led_buffer[1] = 0;
		led_buffer[2] = 0;
		display_3_digit();

		//next state
		if(isButtonPressed(0) == 1){
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 1;
			display_3_digit();
			status = MODE_SINGLE_SPIN;
			//setButtonFlag(0);
		}
		break;
	case MODE_SINGLE_SPIN:
		//spin
		if(isButtonPressed(1) == 1){
			//display_3_digit();
			spin_flag = 1;
			setTimer(2, 3000);
		}
		if(spin_flag == 1)
		{
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		if(isTimerExpired(2)== 1){
			spin_flag = 0;
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			status = MODE_HOLD_SPIN;
			setButtonFlag(0);
		}
		break;
	case MODE_HOLD_SPIN:
		//display current mode
		led_buffer[0] = 0;
		led_buffer[1] = 0;
		led_buffer[2] = 2;

		//spin
		if(isButtonPressed(1) == 1){
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			status = MODE_ACCEL_DECEL_SPIN;
			setButtonFlag(0);
		}
		break;
	case MODE_ACCEL_DECEL_SPIN:
		//display current mode
		led_buffer[0] = 0;
		led_buffer[1] = 0;
		led_buffer[2] = 3;

		//spin
		if(isButtonPressed(1) == 1){
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			status = MODE_TWO_PLAYERS;
			setButtonFlag(0);
		}
		break;
	case MODE_TWO_PLAYERS:
		//display current mode
		led_buffer[0] = 0;
		led_buffer[1] = 0;
		led_buffer[2] = 4;

		//spin
		if(isButtonPressed(1) == 1){
			led_buffer[0] = random_digit();
			led_buffer[1] = random_digit();
			led_buffer[2] = random_digit();
			display_3_digit();
		}
		//next state
		if(isButtonPressed(0) == 1){
			status = INIT;
			setButtonFlag(0);
		}
		break;
	default:
		status = INIT;
		break;

	}

}
