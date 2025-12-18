LUCKY SPIN GAME - TRÒ CHƠI QUAY SỐ MAY MẮN

Dự án thiết kế hệ thống nhúng sử dụng vi điều khiển STM32F103C8T6. Đây là một hệ thống giải trí mô phỏng mô hình quay số ngẫu nhiên với trải nghiệm tương tác đa dạng qua màn hình LCD, LED 7 đoạn và âm thanh

--- 🎥 VIDEO MINH HỌA ---

Demo hoạt động của hệ thống trò chơi: [(https://www.youtube.com/watch?v=9HbF48BxAqI)]

--- TÍNH NĂNG NỔI BẬT ---

Hệ thống hỗ trợ 4 chế độ chơi:

Single Spin: Nhấn nút một lần để kích hoạt vòng quay. Kết quả sẽ hiển thị sau 3 giây chờ.

Hold Spin: Nhấn và giữ nút để vòng quay chạy liên tục. Ngay khi thả tay, hệ thống sẽ dừng và chốt kết quả lập tức.

Accel-Decel Spin: Mô phỏng vật lý thực tế. Tốc độ tăng dần khi nhấn giữ và giảm tốc từ từ (có quán tính) sau khi thả tay cho đến khi dừng hẳn.

Two Players: Chế độ đối kháng dành cho 2 người. Hệ thống tự động phân định thắng thua dựa trên quy tắc: Jackpot (3 số giống nhau) > Đôi > Tổng điểm.

--- LINH KIỆN PHẦN CỨNG ---

Vi điều khiển: STM32F103C8T6 (Blue Pill)

LED 7 đoạn: 3 LED đơn, điều khiển qua 3 IC dịch 74HC595 (Daisy-chain)

Màn hình LCD: LCD 2004 giao tiếp qua module I2C

Âm thanh: Buzzer (Điều khiển bằng PWM tạo giai điệu)

Điều khiển: 4 nút nhấn vật lý: Mode, Spin, Select, List Mode

Nguồn điện: 5V/3.3V qua mạch nạp ST-Link

--- KIẾN TRÚC HỆ THỐNG ---

Finite State Machine (FSM): Quản lý logic chuyển trạng thái giữa các màn hình và chế độ chơi chặt chẽ.

Non-blocking Software Timer: Xử lý đa nhiệm (multitasking), quét LED, đọc nút nhấn và cập nhật LCD đồng thời mà không gây trễ hệ thống.

Software Debouncing: Thuật toán chống dội phím hiệu quả cho các nút nhấn vật lý.

Random Number Generator (RNG): Kết hợp tín hiệu nhiễu từ chân ADC thả nổi và HAL_GetTick() để tạo ra bộ số ngẫu nhiên thực thụ (000-999).

--- CẤU TRÚC THƯ MỤC ---
.
├── Core/
│   ├── Inc/               # File header (.h) định nghĩa trạng thái & cấu trúc
│   └── Src/               # Mã nguồn (.c) - Logic FSM, Timer & Xử lý Button
├── Drivers/               # Thư viện HAL của nhà sản xuất STM32
├── Middlewares/           # Driver tùy chỉnh cho LCD I2C và 74HC595
├── Screenshots/           # Hình ảnh minh họa và kết quả kiểm thử
└── README.md              # Tài liệu hướng dẫn dự án

--- HƯỚNG DẪN NẠP CODE ---

Tải mã nguồn: git clone hoặc tải file ZIP của repository này.

Mở dự án: Sử dụng phần mềm STM32CubeIDE.

Kết nối phần cứng: Kết nối STM32 với máy tính qua mạch nạp ST-Link.

Cấu hình: Kiểm tra sơ đồ chân (Pinout) trong file .ioc.

Thực thi: Build project và nhấn Flash để nạp chương trình xuống vi điều khiển.

--- THÀNH VIÊN THỰC HIỆN ---

Tào Nguyễn Tâm Phúc - 2312716

Hà Trọng Sơn - 2312958

Ngô Hồ Quân - 2312832
