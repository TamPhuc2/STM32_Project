/*
 * mode_accel_decel_spin.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "mode_accel_decel_spin.h"
#include "button.h"
#include "global.h"
#include "software_timer.h"
#include "display_7SEG.h"
#include "display_LCD.h"
#include "random_gen.h"

// include lcd
int temp_accel_decel_spin = 0;
int speed = 10;
int speed_up = 1;
int slow_down = 1;
int check = 0;
void mode_accel_decel_spin(){
	if (isButtonPressed(1) == 1 && temp_accel_decel_spin == 0){
		setTimer(1, speed); // 100ms
		setButtonFlag(1);
		temp_accel_decel_spin++;
	}
	if (isButtonLongPressed(1) == 1){
		speed_up += 1;
		check = 0;
	}
	if (isButtonReleased(1) == 1){
		check = 1;
		slow_down += 1;
	}
	if (isTimerExpired(1) == 1 && check == 0) {
		update_led_buffer(random_digit(), random_digit(), random_digit());
		display_3_digit();
		if (speed - speed_up > 0) {
			speed -= speed_up;
			setTimer(1, speed);
		} else {
			setTimer(1, speed);
		}
	} else {
		update_led_buffer(random_digit(), random_digit(), random_digit());
		display_3_digit();
		if (speed + slow_down < 50) {
			speed += slow_down;
			setTimer(1, speed);
		} else {
			if (check_result_single_player()) {
				display_announcement(BIGWIN);
			} else {
				display_announcement(BETTER_LUCK_NEXT_TIME);
			}
			speed = 10;
			check = 0;
			temp_accel_decel_spin = 0;
			speed_up = 1;
			slow_down = 1;
		}
	}
}
