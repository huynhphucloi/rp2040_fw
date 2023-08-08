#include "hw.h"


void hwInit(void)
{
    bspInit();
    ledInit();
    cliInit();
    // gpioInit();
    uartInit();
    i2cInit();
    uartOpen(_DEF_UART1, 115200);
}