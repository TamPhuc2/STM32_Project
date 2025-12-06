/*
 * mode_single_spin.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "mode_single_spin.h"
#include "button.h"
#include "global.h"

void mode_single_spin(){
	if (isButtonPressed(0) == 1){
		status_temp = MODE_HOLD_SPIN;
		setButtonFlag(0);
	}
	if (isButtonPressed(4) == 1){
		status = status_temp;
		setButtonFlag(4);
	}
}
