#include "hw.h"


void hwInit(void)
{
    bspInit();
    ledInit();
    cliInit();
    // gpioInit();
    uartInit();
    uartOpen(_DEF_UART1, 115200);
}