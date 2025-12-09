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

void logic_game(){
	switch (status){
	case INIT:
		update_led_buffer(9, 9, 9);
		display_3_digit();
		display_welcome_screen();
		if(isButtonPressed(3) == 1){
			lcd_clear_display();
			status = LIST_MODES;
			setButtonFlag(3);
		}
		break;
	case MODE_SINGLE_SPIN:
		//open list mode
		if(isButtonPressed(3) == 1)
		{
			lcd_clear_display();
			status = LIST_MODES;
			setButtonFlag(3);
			break;
		}
		//play
		mode_single_spin();

		break;
	case MODE_HOLD_SPIN:
		//open list mode
		if(isButtonPressed(3) == 1)
		{
			lcd_clear_display();
			status = LIST_MODES;
			setButtonFlag(3);
			break;
		}
		//play
		mode_hold_spin();
		break;
	case MODE_ACCEL_DECEL_SPIN:
		//open list mode
		if(isButtonPressed(3) == 1)
		{
			lcd_clear_display();
			status = LIST_MODES;
			setButtonFlag(3);
			break;
		}
		//play
		mode_accel_decel_spin();
		break;
	case MODE_TWO_PLAYERS:
		//open list mode
		if(isButtonPressed(3) == 1)
		{
			lcd_clear_display();
			status = LIST_MODES;
			setButtonFlag(3);
			break;
		}
		//play
		if(isTimerExpired(6)) mode_two_players();
		break;
	case HOME_SCREEN:
		//open list mode
		display_welcome_screen();
		if(isButtonPressed(3) == 1)
		{
			lcd_clear_display();
			status = LIST_MODES;
			choose_mode = INIT;
			setButtonFlag(3);
			break;
		}
	case LIST_MODES:
		display_list_modes();
		break;
	}
}
