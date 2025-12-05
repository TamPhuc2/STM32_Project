/*
 * display_LCD.c
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */

#include "display_LCD.h"

static PlayMode currentMode = MODE_1;
static int blinkState = 0;        // 0: off, 1: on
static int blinkTimerID = 0;      // bạn cần set timer số mấy thì dùng số đó

void display_init() {
    lcd_init();
    blinkTimerID = 0;  // ví dụ dùng timer 0 cho blink
}

/* ========== 1. Welcome Screen ========== */
void display_welcome_screen() {
    lcd_clear_display();
    lcd_goto_XY(0, 0);
    lcd_send_string("Welcome To");

    lcd_goto_XY(1, 0);
    lcd_send_string("Lucky Spin Game");
}

/* ========== 2. Announcement ========== */
void display_announcement(const char* msg) {
    lcd_clear_display();
    lcd_goto_XY(0, 0);
    lcd_send_string(msg);
}

/* ========== 3. Playing Mode Display (1 HÀM DUY NHẤT) ========== */
/*
 * Hàm này được gọi bởi FSM mỗi khi cần update LCD.
 * Nhấp nháy “>” được quyết định bởi blinkState.
 * Dòng nào hiện “>” thì do currentMode quyết định.
 */
void display_playing_mode(PlayMode mode) {
    currentMode = mode;

    lcd_clear_display();

    // In 3 dòng mode
    lcd_goto_XY(0, 1);
    lcd_send_string("1P-Mode1");

    lcd_goto_XY(1, 1);
    lcd_send_string("1P-Mode2");

    lcd_goto_XY(2, 1);
    lcd_send_string("1P-Mode3");

    // Hiển thị “>” tùy blinkState
    if (blinkState) {
        switch (currentMode) {
            case MODE_1:
                lcd_goto_XY(0, 0);
                break;
            case MODE_2:
                lcd_goto_XY(1, 0);
                break;
            case MODE_3:
                lcd_goto_XY(2, 0);
                break;
        }
        lcd_send_data('>');
    }
}

/* ========== 4. Hàm toggle nhấp nháy dùng software timer ========== */
void display_update_blink() {
    if (isTimerExpired(blinkTimerID)) {

        resetTimerFlag(blinkTimerID);
        blinkState = !blinkState;

        // restart timer
        setTimer(blinkTimerID, 500);   // 500ms blink

        // FSM sẽ gọi lại display_playing_mode(mode)
        // nên không vẽ ở đây
    }
}

