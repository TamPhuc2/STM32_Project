/*
 * button.c
 *
 *  Created on: Dec 4, 2025
 *      Author: Ha Trong Son
 */

#include "button.h"

Button_t buttons[NUM_BUTTONS];

GPIO_TypeDef* BUTTON_PORTS[NUM_BUTTONS] = {
//    BUTTON1_GPIO_Port,
//    BUTTON2_GPIO_Port,
//    BUTTON3_GPIO_Port,
};

uint16_t BUTTON_PINS[NUM_BUTTONS] = {
//    BUTTON1_Pin,
//    BUTTON2_Pin,
//    BUTTON3_Pin,
};

// IMPLEMENTATION

void Button_Init(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		buttons[i].KeyReg0 = NORMAL_STATE;
		buttons[i].KeyReg1 = NORMAL_STATE;
		buttons[i].KeyReg2 = NORMAL_STATE;
		buttons[i].KeyReg3 = NORMAL_STATE;
		buttons[i].TimeOutForKeyPress = 50;
		buttons[i].flag_pressed = 0;
		buttons[i].flag_long_pressed = 0;
		buttons[i].flag_released = 0;
	}
}

int isButtonPressed(int index) {
    if (buttons[index].flag_pressed == 1) {
        buttons[index].flag_pressed = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int index){
	if (buttons[index].flag_long_pressed == 1) {
		buttons[index].flag_long_pressed = 0;
	    return 1;
	}
	return 0;
}

int isButtonReleased(int index) {
    if (buttons[index].flag_released == 1) {
        buttons[index].flag_released = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int index){
	buttons[index].flag_pressed = 1;
}

void setButtonFlag(int index){
	buttons[index].flag_pressed = 0;
}


void getKeyInput(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		buttons[i].KeyReg2 = buttons[i].KeyReg1;
		buttons[i].KeyReg1 = buttons[i].KeyReg0;

		buttons[i].KeyReg0 = HAL_GPIO_ReadPin(BUTTON_PORTS[i], BUTTON_PINS[i]);

		if ((buttons[i].KeyReg1 == buttons[i].KeyReg0) && (buttons[i].KeyReg1 == buttons[i].KeyReg2)){
			if (buttons[i].KeyReg2 != buttons[i].KeyReg3){
				buttons[i].KeyReg3 = buttons[i].KeyReg2;

				if (buttons[i].KeyReg3 == PRESSED_STATE){
					buttons[i].TimeOutForKeyPress = 50;
					buttons[i].flag_pressed = 1;
				} else if (buttons[i].KeyReg3 == NORMAL_STATE) {
					buttons[i].flag_released = 1;
				}
			}
			else {
				if (buttons[i].KeyReg3 == PRESSED_STATE) {
					buttons[i].TimeOutForKeyPress--;

				    if (buttons[i].TimeOutForKeyPress == 0) {
				    	buttons[i].TimeOutForKeyPress = 50;

				        buttons[i].flag_long_pressed = 1;
				    }
				}
			}
		}
	}
}
