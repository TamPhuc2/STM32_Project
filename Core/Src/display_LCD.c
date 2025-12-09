/*
 * display_LCD.c
 *
 *  Created on: Nov 28, 2025
 *      Author: tntam
 */


#include "display_LCD.h"


// Điều khiển vị trí hiện tại
int pos_left  = RUN_COL_END; // Hàng 1 chạy từ phải → trái
int pos_right = RUN_COL_START; // Hàng 2 chạy từ trái → phải

int currmark = 0;

void display_mark(int);
void clear_mark(int);

void display_init() {
    lcd_init();

}

/* ========== 1. Welcome Screen ========== */
void display_welcome_screen() {
    lcd_clear_display();
    lcd_goto_XY(0, 5);
    lcd_send_string("Welcome To");

    lcd_goto_XY(2, 3);
    lcd_send_string("Lucky Spin Game");
}

/* ========== 2. Announcement ========== */
void display_announcement(int announce_num) {
	lcd_clear_display();
    switch (announce_num){
    case START:
    	lcd_goto_XY(1, 8);
    	lcd_send_string("START");
    	break;
    case BIGWIN:
    	lcd_goto_XY(1, 7);
    	lcd_send_string("BIG WIN!");
    	break;
    case BETTER_LUCK_NEXT_TIME:
    	lcd_goto_XY(1, 0);
    	lcd_send_string("GOOD LUCK NEXT TIME!");
    	break;
    case P1_LOSE:
    	lcd_goto_XY(1, 5);
    	lcd_send_string("P1");
    	lcd_goto_XY(1, 13);
    	lcd_send_string("P2");
    	lcd_goto_XY(2, 3);
    	lcd_send_string("LOSER");
    	lcd_goto_XY(2, 12);
    	lcd_send_string("WINER");
    	break;
    case P2_LOSE:
    	lcd_goto_XY(1, 5);
    	lcd_send_string("P1");
    	lcd_goto_XY(1, 13);
    	lcd_send_string("P2");
    	lcd_goto_XY(2, 3);
    	lcd_send_string("WINER");
    	lcd_goto_XY(2, 12);
    	lcd_send_string("LOSER");
    	break;
    case TIE:
    	lcd_goto_XY(1, 5);
    	lcd_send_string("P1");
    	lcd_goto_XY(1, 13);
    	lcd_send_string("P2");
    	lcd_goto_XY(2, 1);
    	lcd_send_string("THE SCORE IS EVEN!");
    	break;
    default:
    	break;
    }
}

/* ========== 3. Playing Mode Display (1 HÀM DUY NHẤT) ========== */
/*
 * Hàm này được gọi bởi FSM mỗi khi cần update LCD.
 * Nhấp nháy “>” được quyết định bởi blinkState.
 * Dòng nào hiện “>” thì do mode mình đang trỏ vào quyết định.
 */
void display_mark(int mode){
	if (currmark == 1){
		lcd_goto_XY(mode, 0);
		lcd_send_string(">");
	} else {
		lcd_goto_XY(mode, 0);
		lcd_send_string(" ");
	}
}

void clear_mark(int mode){
	lcd_goto_XY(mode, 0);
	lcd_send_string(" ");
}

// mode value from 0 to 3
void display_playing_mode(int mode) {

	clear_mark(mode);

	switch (mode){
	case 0:
		lcd_goto_XY(mode, 1);
		lcd_send_string("1P-Accel decel spin");
		break;
	case 1:
		lcd_goto_XY(mode, 1);
		lcd_send_string("1P-Hold spin");
		break;
	case 2:
		lcd_goto_XY(mode, 1);
		lcd_send_string("1P-Single spin");
		break;
	case 3:
		lcd_goto_XY(mode, 1);
		lcd_send_string("2P-Two players");
		break;
	default: break;
	}


	display_mark(mode);

	if(isTimerExpired(TIMER_BLINK)){
		currmark = !currmark;
		setTimer(TIMER_BLINK, BLINK_CYCLE);
	}

}



/* ========== 4. Hàm hiển thị màn hình khi trò chơi đang chạy ========== */
void display_while_playing() {
	if (!isTimerExpired(TIMER_LCD_ANIMATION)) {
	    return;
	}

	    // --- Reset Timer cho lần sau ---
	setTimer(TIMER_LCD_ANIMATION, LCD_UPDATE_CYCLE);

    char line1[21];
    char line2[21];

    // clear buffer
    for (int i = 0; i < 20; i++) {
        line1[i] = ' ';
        line2[i] = ' ';
    }
    line1[20] = '\0';
    line2[20] = '\0';

    // --- VẼ MŨI TÊN TRÊN HÀNG 1 (<<<) ---
    for (int i = 0; i < ARROW_LEN; i++) {
        int col = pos_left - i;
        if (col >= RUN_COL_START && col <= RUN_COL_END)
            line1[col] = '<';
    }

    // --- VẼ MŨI TÊN TRÊN HÀNG 2 (>>>) ---
    for (int i = 0; i < ARROW_LEN; i++) {
        int col = pos_right + i;
        if (col >= RUN_COL_START && col <= RUN_COL_END)
            line2[col] = '>';
    }

    // In ra LCD
    lcd_goto_XY(1, 0);
    lcd_send_string(line1);

    lcd_goto_XY(2, 0);
    lcd_send_string(line2);

    // --- CẬP NHẬT VỊ TRÍ ---
    pos_left--;          // <<< di chuyển trái
    pos_right++;         // >>> di chuyển phải

    // Reset vòng lặp
    if (pos_left < (RUN_COL_START - ARROW_LEN))
        pos_left = RUN_COL_END;

    if (pos_right > (RUN_COL_END + 1))
        pos_right = RUN_COL_START - ARROW_LEN + 1;
}
