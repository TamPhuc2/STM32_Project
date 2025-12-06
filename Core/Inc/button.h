/*
 * button.h
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_


#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define NUM_BUTTONS 4

// STRUCT

typedef struct {
    int KeyReg0;
    int KeyReg1;
    int KeyReg2;
    int KeyReg3;

    int TimeOutForKeyPress;

    int flag_pressed;
    int flag_long_pressed;
} Button_t;

// API

void Button_Init();
void getKeyInput();

void subKeyProcess(int index);
void setButtonFlag(int index);
int isButtonPressed(int index);
int isButtonLongPressed(int index);



#endif /* INC_BUTTON_H_ */
