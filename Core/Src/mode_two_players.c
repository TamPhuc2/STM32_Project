/*
 * mode_two_players.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "mode_two_players.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "display_7SEG.h"
#include "random_gen.h"
// include lcd

int first_player_buffer[5] = {0, 0, 0, 0, 0};
int second_player_buffer[5] = {0, 0, 0, 0, 0};
int index_player = 1;
int check_result_two_players(){
	first_player_buffer[3] = first_player_buffer[0] + first_player_buffer[1] + first_player_buffer[2];
	second_player_buffer[3] = second_player_buffer[0] + second_player_buffer[1] + second_player_buffer[2];

	first_player_buffer[4] = SUM_MASTER;
	second_player_buffer[4] = SUM_MASTER;

	if (first_player_buffer[0] == first_player_buffer[1]
		|| first_player_buffer[0] == first_player_buffer[2]
		|| first_player_buffer[1] == first_player_buffer[2]) {
		first_player_buffer[4] = DOUBLE_EDGE;
	}
	if (second_player_buffer[0] == second_player_buffer[1]
		|| second_player_buffer[0] == second_player_buffer[2]
		|| second_player_buffer[1] == second_player_buffer[2]) {
		second_player_buffer[4] = DOUBLE_EDGE;
	}

	if (first_player_buffer[0] == first_player_buffer[1]
		&& first_player_buffer[0] == first_player_buffer[2]){
		first_player_buffer[4] = TRIPLE_WIN;
	}
	if (second_player_buffer[0] == second_player_buffer[1]
		&& second_player_buffer[0] == second_player_buffer[2]){
		second_player_buffer[4] = TRIPLE_WIN;
	}

	if (first_player_buffer[4] > second_player_buffer[4]){
		return FIRST_PLAYER;
	} else if (first_player_buffer[4] < second_player_buffer[4]){
		return SECOND_PLAYER;
	} else if (first_player_buffer[4] == second_player_buffer[4]){
		if (first_player_buffer[3] > second_player_buffer[3]){
			return FIRST_PLAYER;
		} else if (first_player_buffer[3] < second_player_buffer[3]){
			return SECOND_PLAYER;
		} else if (first_player_buffer[3] == second_player_buffer[3]){
			return DRAW;
		}
	}
	return 0;
}
void mode_two_players(){
	if (index_player % 2 == 1){
		display_mode_two_players(index_player);
	} else {
		display_mode_two_players(index_player);
	}
	if (isButtonPressed(1) == 1){
		last_time = HAL_GetTick();
		index_player++;
	}
	if (isTimerExpired(1) == 1){
		if (HAL_GetTick() - last_time < 3000){
			update_led_buffer(random_digit(), random_digit(), random_digit());
			display_3_digit();
			setTimer(1, 10);
		} else if (index_player % 2 == 1){
			first_player_buffer[0] = led_buffer[0];
			first_player_buffer[1] = led_buffer[1];
			first_player_buffer[2] = led_buffer[2];
		} else if (index_player % 2 == 0){
			second_player_buffer[0] = led_buffer[0];
			second_player_buffer[1] = led_buffer[1];
			second_player_buffer[2] = led_buffer[2];
			switch (check_result_two_players()){
			case FIRST_PLAYER:
				display_announcement(P2_LOSE);
				break;
			case SECOND_PLAYER:
				display_announcement(P1_LOSE);
				break;
			case DRAW:
				display_announcement(TIE);
				break;
			default:
				break;
			}
		}
	}

}
