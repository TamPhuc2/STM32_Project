/*
 * i2c_lcd.c
 *
 *  Created on: Dec 7, 2025
 *      Author: tntam
 */

// GND
// VCC
// SDA
// SCL
#include "i2c_lcd.h"

extern I2C_HandleTypeDef hi2c1;



//// Gửi lệnh cho LCD
//void lcd_send_cmd (char cmd)
//{
//    char data_u, data_l;
//    uint8_t data_t[4];
//
//    data_u = (cmd & 0xF0);
//    data_l = (cmd << 4) & 0xF0;
//
//    data_t[0] = data_u | 0x0C;  // EN=1, RS=0
//    data_t[1] = data_u | 0x08;  // EN=0, RS=0
//    data_t[2] = data_l | 0x0C;  // EN=1, RS=0
//    data_t[3] = data_l | 0x08;  // EN=0, RS=0
//
//    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t*)data_t, 4, 100);
//}
//
//// Gửi dữ liệu (ký tự) cho LCD
//void lcd_send_data (char data)
//{
//    char data_u, data_l;
//    uint8_t data_t[4];
//
//    data_u = (data & 0xF0);
//    data_l = ((data << 4) & 0xF0);
//
//    data_t[0] = data_u | 0x0D; // EN=1, RS=1
//    data_t[1] = data_u | 0x09; // EN=0, RS=1
//    data_t[2] = data_l | 0x0D; // EN=1, RS=1
//    data_t[3] = data_l | 0x09; // EN=0, RS=1
//
//    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t*)data_t, 4, 100);
//}
//
//// Khởi tạo LCD (chuẩn HD44780)
//void lcd_init (void)
//{
//    HAL_Delay(50);  // đợi LCD sẵn sàng
//
//    lcd_send_cmd(0x30);
//    HAL_Delay(5);
//
//    lcd_send_cmd(0x30);
//    HAL_Delay(5);
//
//    lcd_send_cmd(0x30);
//    HAL_Delay(5);
//
//    lcd_send_cmd(0x20);  // chuyển về 4-bit mode
//    HAL_Delay(5);
//
//    lcd_send_cmd (0x28); // 4-bit, 2 dòng, font 5x7
//    HAL_Delay(1);
//
//    lcd_send_cmd (0x0C); // Display ON, Cursor OFF
//    HAL_Delay(1);
//
//    lcd_send_cmd (0x06); // Auto-increment
//    HAL_Delay(1);
//
//    lcd_send_cmd (0x01); // Clear
//    HAL_Delay(2);
//}
//
//// Gửi chuỗi
//void lcd_send_string (char *str)
//{
//    while (*str) {
//        lcd_send_data (*str++);
//    }
//}
//
//// Xóa màn hình
//void lcd_clear_display (void)
//{
//    lcd_send_cmd(0x01);
//    HAL_Delay(2);
//}
//
//// Di chuyển con trỏ tới vị trí (row, col)
//void lcd_goto_XY (int row, int col)
//{
//    uint8_t pos_Addr;
//
//    switch(row)
//    {
//        case 0: pos_Addr = 0x80 + col;      break; // hàng 0
//        case 1: pos_Addr = 0xC0 + col;      break; // hàng 1
//        case 2: pos_Addr = 0x94 + col;      break; // hàng 2 (0x14 + 0x80)
//        case 3: pos_Addr = 0xD4 + col;      break; // hàng 3 (0x54 + 0x80)
//        default: pos_Addr = 0x80;           break;
//    }
//
//    lcd_send_cmd(pos_Addr);
//}


void lcd_send_cmd(char cmd)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = (cmd & 0xF0);
    data_l = ((cmd << 4) & 0xF0);

    data_t[0] = data_u | 0x0C;
    data_t[1] = data_u | 0x08;
    data_t[2] = data_l | 0x0C;
    data_t[3] = data_l | 0x08;

    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, data_t, 4, 100);
}

void lcd_send_data(char data)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = (data & 0xF0);
    data_l = ((data << 4) & 0xF0);

    data_t[0] = data_u | 0x0D;
    data_t[1] = data_u | 0x09;
    data_t[2] = data_l | 0x0D;
    data_t[3] = data_l | 0x09;

    HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, data_t, 4, 100);
}

void lcd_clear_display(void)
{
    lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void lcd_goto_XY (int row, int col)
{
    uint8_t pos_Addr;

    switch(row)
    {
        case 0: pos_Addr = 0x80 + col;      break; // hàng 0
        case 1: pos_Addr = 0xC0 + col;      break; // hàng 1
        case 2: pos_Addr = 0x94 + col;      break; // hàng 2 (0x14 + 0x80)
        case 3: pos_Addr = 0xD4 + col;      break; // hàng 3 (0x54 + 0x80)
        default: pos_Addr = 0x80;           break;
    }

    lcd_send_cmd(pos_Addr);
}
void lcd_init(void)
{
    HAL_Delay(50);

    lcd_send_cmd(0x30);
    HAL_Delay(5);
    lcd_send_cmd(0x30);
    HAL_Delay(1);
    lcd_send_cmd(0x30);

    lcd_send_cmd(0x20);
    lcd_send_cmd(0x28);
    lcd_send_cmd(0x0C);
    lcd_send_cmd(0x01);
    HAL_Delay(2);
    lcd_send_cmd(0x06);
}

void lcd_send_string(char *str)
{
    while (*str) lcd_send_data(*str++);
}

