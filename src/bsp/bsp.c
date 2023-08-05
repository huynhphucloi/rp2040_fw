#include "bsp.h"


bool bspInit(void) {
    stdio_init_all();
    __enable_irq();
    return true;
}

void delay(uint32_t ms) {
    sleep_ms(ms);
}

uint32_t millis(void) {
    return to_ms_since_boot(get_absolute_time());
}