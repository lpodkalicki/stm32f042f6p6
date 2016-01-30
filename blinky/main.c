/**
 * Copyright (c) 2015, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include "stm32f0xx_hal.h"
#include "config.h"
#include "led.h"

extern void error_handler(void);
#define DELAY   (100)

int
main(void)
{

	HAL_Init();
        SystemClock_Config();
        RCC_Config();
        GPIO_Config();

        if (SysTick_Config(SystemCoreClock / 1000)) {
                error_handler();
        }

        while (1) {
                led_toggle(LED_BLUE);
                HAL_Delay(DELAY);
	}
}
