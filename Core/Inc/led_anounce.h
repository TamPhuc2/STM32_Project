/*
 * led_anounce.h
 *
 *  Created on: Dec 12, 2025
 *      Author: tntam
 */

#ifndef INC_LED_ANOUNCE_H_
#define INC_LED_ANOUNCE_H_


#include "main.h"
#include "software_timer.h"
#include "global.h"

// Hàm khởi tạo
void Led_Announce_Init(void);

// Các hàm kích hoạt hiệu ứng
void Led_BlinkGreen(void); // Dùng cho P1 thắng hoặc Win game 1 người
void Led_BlinkRed(void);   // Dùng cho P2 thắng hoặc Thua game 1 người
void Led_BlinkBoth(void);  // Dùng cho Hoà (Draw)

// Hàm xử lý chính
void Led_Announce_Process(void);


#endif /* INC_LED_ANOUNCE_H_ */
