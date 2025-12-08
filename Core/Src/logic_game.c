/*
 * logic_game.c
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#include "main.h"
#include "global.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "button.h"
#include "buzzer.h"
#include "mode_accel_decel_spin.h"
#include "mode_hold_spin.h"
#include "mode_single_spin.h"
#include "mode_two_players.h"
#include "random_gen.h"


void logic_game(){
	switch (status){
	case INIT:
		update_led_buffer(ERROR, ERROR, ERROR);
		display_3_digit();
		display_welcome_screen();
		if (isButtonPressed(1) == 1){
			status = LIST_MODES;
			setButtonFlag(0);
			setButtonFlag(1);
		}
		break;
	case LIST_MODES:
		display_list_modes(status);
		break;
	case MODE_SINGLE_SPIN:
		mode_single_spin();
		if (isButtonPressed(0) == 1){
			status = LIST_MODES;
			setButtonFlag(0);
			break;
		}
		break;
	case MODE_HOLD_SPIN:
		mode_hold_spin();
		if (isButtonPressed(0) == 1){
			status = LIST_MODES;
			setButtonFlag(0);
			break;
		}
		break;
	case MODE_ACCEL_DECEL_SPIN:
		mode_accel_decel_spin();
		if (isButtonPressed(0) == 1){
			status = LIST_MODES;
			setButtonFlag(0);
			break;
		}
		break;
	case MODE_TWO_PLAYERS:
		mode_two_players();
		if (isButtonPressed(0) == 1){
			status = LIST_MODES;
			setButtonFlag(0);
			break;
		}
		break;
	}
}
