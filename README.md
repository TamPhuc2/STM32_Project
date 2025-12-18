# 🎰 Lucky Spin Game (STM32 Logic Design Project)

Đồ án **Thiết kế luận lý (CO3091)** – Trường Đại học Bách Khoa TP.HCM
Khoa Khoa học và Kỹ thuật Máy tính

---

## 📌 Giới thiệu

**Lucky Spin Game** là một trò chơi quay số may mắn được hiện thực trên nền tảng **vi điều khiển STM32F103C8T6**. Hệ thống mô phỏng quá trình quay số ngẫu nhiên và hiển thị kết quả thông qua **3 LED 7 đoạn** và **màn hình LCD 20x4**, kết hợp với **nút nhấn** và **buzzer** để tạo trải nghiệm tương tác trực quan.

Dự án nhằm mục tiêu áp dụng các kiến thức về:

* Vi điều khiển STM32
* Máy trạng thái hữu hạn (FSM)
* Software Timer, xử lý nút nhấn
* Giao tiếp ngoại vi (GPIO, I2C, PWM)

---

## 🎮 Chức năng chính

Hệ thống hỗ trợ **4 chế độ chơi**:

1. **Single Spin**
   Nhấn nút một lần để quay. Sau 3 giây, hệ thống dừng và hiển thị kết quả.

2. **Hold Spin**
   Nhấn và giữ nút để quay, thả nút thì dừng ngay lập tức.

3. **Accel–Decel Spin**
   Giữ nút để tăng tốc quay, thả nút thì hệ thống giảm tốc dần rồi dừng.

4. **Two Players**
   Hai người chơi lần lượt quay số. Kết quả được so sánh theo thứ tự ưu tiên:

   * 3 số giống nhau
   * 2 số giống nhau
   * Tổng 3 số lớn hơn
   * Trường hợp còn lại: hòa

---

## 🧩 Phần cứng sử dụng

* **MCU**: STM32F103C8T6
* **Hiển thị**:

  * 3 × LED 7 đoạn (điều khiển qua IC 74HC595)
  * LCD 20x4 (HD44780, giao tiếp I2C – PCF8574)
* **Input**: 4 nút nhấn
* **Output**: Buzzer (PWM – TIM1)
* **Nguồn**: 5V / 3.3V qua ST-Link

---

## 🧠 Thiết kế phần mềm

### Kiến trúc tổng thể

Hệ thống được thiết kế theo mô hình phân tầng:

* **System**: nguồn, clock, reset
* **Main Controller**: MCU, GPIO, Timer, I2C
* **Software**:

  * Finite State Machine (FSM)
  * Random Number Generator (ADC + thời gian)
  * Logic so sánh kết quả
* **User Interface**:

  * Buttons
  * LED 7 đoạn
  * LCD
  * Buzzer

### Kỹ thuật sử dụng

* **Software Timer**:

  * Timer Interrupt
  * Bộ định thời - Scheduler

* **Xử lý nút nhấn**:

  * Debouncing bằng phần mềm
  * Phân biệt nhấn ngắn / nhấn giữ / nhả nút

* **FSM (Finite State Machine)**:

  * INIT
  * LIST_MODES
  * MODE_SINGLE_SPIN
  * MODE_HOLD_SPIN
  * MODE_ACCEL_DECEL_SPIN
  * MODE_TWO_PLAYERS
  * HOME_SCREEN

---

## 🔊 Âm thanh (Buzzer)

* Điều khiển bằng **PWM (TIM1)**
* Có các giai điệu:

  * Chào mừng khi khởi động
  * Chiến thắng (Jackpot)
  * Thất bại

---

## 🧪 Kiểm thử

* Sử dụng **bộ số giả lập** để kiểm tra logic thắng/thua
* Kiểm thử đầy đủ 4 chế độ chơi
* Đánh giá khả năng hiển thị, phản hồi nút nhấn và âm thanh

---

## ⚠️ Hạn chế

* Độ ngẫu nhiên chưa tuyệt đối trong môi trường ít nhiễu
* Cấp nguồn trực tiếp từ ST-Link có thể gây nhấp nháy LCD
* Hệ thống dây nối breadboard chưa tối ưu

---

## 🚀 Hướng phát triển

* Sử dụng nguồn ngoài ổn định hơn
* Cải thiện thuật toán sinh số ngẫu nhiên
* Mở rộng tính năng:

  * Kết nối Bluetooth/WiFi
  * Thêm chế độ tính điểm

---

## 👨‍💻 Thành viên thực hiện

| Họ tên                  | MSSV    | Nhiệm vụ                                   |
| ----------------------- | ------- | ------------------------------------------ |
| **Tào Nguyễn Tâm Phúc** | 2312716 | Tích hợp hệ thống, thiết kế mạch, kiểm thử |
| **Hà Trọng Sơn**        | 2312958 | Thuật toán random, logic game, buzzer      |
| **Ngô Hồ Quân**         | 2312832 | Timer, Scheduler, xử lý nút nhấn, LCD      |

---

## 🎥 Demo

Video demo sản phẩm:
👉 [https://www.youtube.com/watch?v=9HbF48BxAqI](https://www.youtube.com/watch?v=9HbF48BxAqI)
