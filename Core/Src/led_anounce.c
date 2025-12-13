/*
 * led_anounce.c
 *
 *  Created on: Dec 12, 2025
 *      Author: tntam
 */

#include "led_anounce.h"



// Các trạng thái máy trạng thái
#define LED_STATE_IDLE 	0
#define LED_STATE_ON   	1
#define LED_STATE_OFF  	2

// Các mục tiêu nhấp nháy
#define TARGET_NONE  	0
#define TARGET_GREEN 	1 //win / player 1
#define TARGET_RED   	2 //lose / player 2
#define TARGET_BOTH  	3 // draw

static uint8_t current_state = LED_STATE_IDLE;
static int blink_counter = 0;
static uint8_t blink_target = TARGET_NONE; // Biến lưu xem đang nháy đèn nào

// --- PRIVATE FUNCTIONS ---

static void TurnOffAll(void){
    HAL_GPIO_WritePin(LED_WIN_GPIO_Port, LED_WIN_Pin, RESET);
    HAL_GPIO_WritePin(LED_LOSE_GPIO_Port, LED_LOSE_Pin, RESET);
}

// Hàm bật đèn dựa trên target
static void TurnOnTarget(void){
    if(blink_target & TARGET_GREEN){
        HAL_GPIO_WritePin(LED_WIN_GPIO_Port, LED_WIN_Pin, SET);
    }
    if(blink_target & TARGET_RED){
        HAL_GPIO_WritePin(LED_LOSE_GPIO_Port, LED_LOSE_Pin, SET);
    }
}

// Hàm bắt đầu chu trình
static void StartBlinking(uint8_t target){
    TurnOffAll();

    blink_target = target;
    blink_counter = BLINK_TIMES;

    // Bắt đầu ngay
    TurnOnTarget();
    setTimer(LED_TIMER_ID, BLINK_DURATION);
    current_state = LED_STATE_ON;
}

// --- PUBLIC FUNCTIONS ---

void Led_Announce_Init(void){
    TurnOffAll();
    current_state = LED_STATE_IDLE;
    blink_target = TARGET_NONE;
}

void Led_BlinkGreen(void){
    StartBlinking(TARGET_GREEN);
}

void Led_BlinkRed(void){
    StartBlinking(TARGET_RED);
}

void Led_BlinkBoth(void) {
    StartBlinking(TARGET_BOTH);
}

void Led_Announce_Process(void){
    if(current_state == LED_STATE_IDLE) return;

    if(isTimerExpired(LED_TIMER_ID)){
        switch(current_state){
            case LED_STATE_ON:
                TurnOffAll();
                setTimer(LED_TIMER_ID, BLINK_DURATION);
                current_state = LED_STATE_OFF;
                break;

            case LED_STATE_OFF:
                blink_counter--;
                if (blink_counter > 0){
                    TurnOnTarget(); // Bật lại đúng đèn cần bật
                    setTimer(LED_TIMER_ID, BLINK_DURATION);
                    current_state = LED_STATE_ON;
                }
                else{
                    current_state = LED_STATE_IDLE;
                }
                break;

            default: break;
        }
    }
}
