/**
 * Copyright (c) 2015, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 */

#include <string.h>
#include "stm32f0xx_hal.h"
#include "log.h"

extern UART_HandleTypeDef UART_DBG_Handle;
static volatile int _loglevel = LOGLEVEL_DEFAULT;

void
log_init(int level)
{

	_loglevel = level;
}

void
log_fini(void)
{

	// TODO: block logging ability
}

void
log_setlevel(int level)
{

	_loglevel = level;
}

int
log_level(void)
{

	return _loglevel;
}

void
_log(int level, const char *message)
{

	/* Drop log if level is grater then value from logger context */
        if (_loglevel < level)
                return;

	HAL_UART_Transmit(&UART_DBG_Handle, (uint8_t*)message, strlen(message), 512);
}
