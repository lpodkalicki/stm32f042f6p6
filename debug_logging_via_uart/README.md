# Debug logging via UART
## Board
CUSTOM board based on STM32F042F6P6 (TSSOP20)

## MCU
[STM32F042F6P6](http://www.st.com/web/en/resource/technical/document/datasheet/DM00105814.pdf)

## Library
[STM32Cube_FW_F0_V1.4.0](http://www.st.com/web/catalog/tools/FM147/CL1794/SC961/SS1743/LN1897/PF260612?s_searchtype=partnumber)

## Configuration

### DEBUG
 * USART2 with GPIOs:
  * USART2_TX -> PA2
  * USART2_RX -> PA3 (unused)

## Compiling and Burning (arm-none-eabi toolchain)
```
$ make && make flash
```

