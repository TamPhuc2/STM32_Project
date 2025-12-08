/*
 * global.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "global.h"

int status = INIT;
int last_time = 0;
int led_buffer[MAX_LED] = {1, 2, 3};
int check_result_single_player(){
	if (led_buffer[0] == led_buffer[1] && led_buffer[1] == led_buffer[2]){
		return 1;
	}
	return 0;
}
