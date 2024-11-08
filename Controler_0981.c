#include "main.h"

/* Khởi tạo các chức năng */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* Khai báo các hàm điều khiển LED */
void LED_On(void);
void LED_Off(void);

/* Khai báo con trỏ hàm */
void (*LED_Control)(void);

int main(void)
{
    /* Khởi tạo HAL Library */
    HAL_Init();

    /* Cấu hình xung hệ thống */
    SystemClock_Config();

    /* Khởi tạo tất cả các GPIO */
    MX_GPIO_Init();

    /* Vòng lặp vô tận */
    while (1)
    {
        /* Gán con trỏ hàm để bật đèn LED */
        LED_Control = LED_On;
        LED_Control(); // Gọi hàm thông qua con trỏ để bật đèn LED
        HAL_Delay(500); // Chờ 500ms

        /* Gán con trỏ hàm để tắt đèn LED */
        LED_Control = LED_Off;
        LED_Control(); // Gọi hàm thông qua con trỏ để tắt đèn LED
        HAL_Delay(500); // Chờ 500ms
    }
}

/* Hàm bật đèn LED */
void LED_On(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}

/* Hàm tắt đèn LED */
void LED_Off(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
}

/* Hàm cấu hình xung hệ thống */
void SystemClock_Config(void)
{
    // Cấu hình xung hệ thống (xem thêm tài liệu hoặc sử dụng STM32CubeMX để tự động sinh mã)
}

/* Hàm khởi tạo GPIO */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Bật clock cho GPIOA */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* Cấu hình chân PA0 làm Output */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
