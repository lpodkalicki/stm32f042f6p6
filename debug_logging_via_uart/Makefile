# -
# Copyright (c) 2015, Lukasz Marcin Podkalicki <lpodkalicki@gmail.com>
# -

TARGET=main
STMDIR=lib

###################################################

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump
SE=arm-none-eabi-size
SF=st-flash

###################################################

STMSRCDIR = $(STMDIR)/Drivers/STM32F0xx_HAL_Driver/Src
vpath %.c $(STMSRCDIR)

INC_DIRS = $(STMDIR)/Drivers/STM32F0xx_HAL_Driver/Inc
INC_DIRS += $(STMDIR)/Drivers/CMSIS/Device/ST/STM32F0xx/Include
INC_DIRS += $(STMDIR)/Drivers/CMSIS/Include
INC_DIRS += .

INCLUDE = $(addprefix -I,$(INC_DIRS))

###################################################

CFLAGS  = -std=gnu99 -g -O2 -Wall -TSTM32F042x6_FLASH.ld
CFLAGS += -mlittle-endian -mthumb -mthumb-interwork -mcpu=cortex-m0
CFLAGS += -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -DUSE_STDPERIPH_DRIVER -DSTM32F042x6
CFLAGS += -DDEBUG

###################################################

SRCS =  main.c \
	stm32f0xx_it.c \
	system_stm32f0xx.c \
	syscalls.c \
	config.c \
	led.c \
	log.c 
	
SRCS += stm32f0xx_hal.c \
	stm32f0xx_hal_rcc.c \
	stm32f0xx_hal_gpio.c \
	stm32f0xx_hal_cortex.c \
	stm32f0xx_hal_dma.c \
	stm32f0xx_hal_uart.c \
	startup_stm32f042x6.s

###################################################

.PHONY: $(TARGET)

$(TARGET): $(TARGET).elf

$(TARGET).elf: $(SRCS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ 
	$(CP) -O ihex $(TARGET).elf $(TARGET).hex
	$(CP) -O binary $(TARGET).elf $(TARGET).bin

clean:
	rm -f *.o $(TARGET).elf $(TARGET).hex $(TARGET).bin

flash: 
	$(SF) write $(TARGET).bin 0x8000000
