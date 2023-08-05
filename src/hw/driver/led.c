#include "led.h"

typedef struct
{
    uint32_t pin;
    uint8_t on_state;
    uint8_t off_state;
}  led_tbl_t;

static const led_tbl_t led_tbl[LED_MAX_CH] = 
{
    {25, 1, 0},
}

void ledInit(void)
{
    for( uint32_t i = 0; i < LED_MAX_CH; i++)
    {
        gpio_init(led_tbl[i].pin);
        gpio_set_dir(led_tbl[i].pin, GPIO_OUT);
        ledOff(i);
    }
};

void ledOn(uint8_t ch)
{
    if(ch > LED_MAX_CH) return;
    
    gpio_put(led_tbl[ch], led_tbl[ch].on_state);
};

void ledOff(uint8_t ch)
{
    if(ch > LED_MAX_CH) return;

    gpio_put(led_tbl[ch], led_tbl[ch].off_state);
};

void ledToggle(uint8_t ch)
{
    if (ch >= LED_MAX_CH) return;

    gpio_xor_mask(1<<led_tbl[ch].pin);
};
