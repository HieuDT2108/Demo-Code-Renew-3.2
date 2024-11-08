 Include các thư viện cần thiết 
#include main.h

 Khởi tạo các chức năng 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
     Khởi tạo HAL Library 
    HAL_Init();

     Cấu hình hệ thống xung 
    SystemClock_Config();

     Khởi tạo tất cả các GPIO 
    MX_GPIO_Init();

     Vòng lặp vô tận 
    while (1)
    {
         Bật đèn LED 
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
         Chờ 500ms 
        HAL_Delay(500);

         Tắt đèn LED 
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
         Chờ 500ms 
        HAL_Delay(500);
    }
}

 Hàm cấu hình xung hệ thống 
void SystemClock_Config(void)
{
     Cấu hình xung hệ thống (xem thêm tài liệu hoặc sử dụng STM32CubeMX để tự động sinh mã)
}

 Hàm khởi tạo GPIO 
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

     Bật clock cho GPIOA 
    __HAL_RCC_GPIOA_CLK_ENABLE();

     Cấu hình chân PA0 làm Output 
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
