#ifndef SRC_HW_HW_H_
#define SRC_HW_HW_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "hw_def.h"

#include "led.h"
#include "gpio.h"
#include "uart.h"
#include "i2c.h"
#include "cli.h"

void hwInit(void);

#ifdef __cplusplus
    }
#endif

#endif