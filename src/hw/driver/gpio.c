#include "gpio.h"

typedef struct 
{
    uint32_t    pin;
    uint8_t     mode;
    uint8_t     on_state;
    uint8_t     off_state;
    bool        init_value;
} gpio_tbl_t;

static const gpio_tbl_t gpio_tbl[GPIO_MAX_CH] = 
{
    {25, _DEF_OUTPUT, _DEF_HIGH, _DEF_LOW, _DEF_LOW},
};

bool gpioInit(void)
{
    bool ret = true;

    for(uint32_t i = 0; i < GPIO_MAX_CH; i++)
    {
        gpio_init(gpio_tbl[i].pin);

        gpioPinMode(i, gpio_tbl[i].mode);
        gpioPinWrite(i, gpio_tbl[i].init_value);
    }

    return ret;
};

bool gpioPinMode(uint8_t ch, uint8_t mode)
{
    bool ret = true;


  if (ch >= GPIO_MAX_CH)
  {
    return false;
  }

  switch(mode)
  {
    case _DEF_INPUT:
      gpio_set_pulls(gpio_tbl[ch].pin, false, false);
      gpio_set_dir(gpio_tbl[ch].pin, GPIO_IN);
      break;

    case _DEF_INPUT_PULLUP:
      gpio_set_pulls(gpio_tbl[ch].pin, true, false);
      gpio_set_dir(gpio_tbl[ch].pin, GPIO_IN);
      break;

    case _DEF_INPUT_PULLDOWN:
      gpio_set_pulls(gpio_tbl[ch].pin, false, true);
      gpio_set_dir(gpio_tbl[ch].pin, GPIO_IN);
      break;

    case _DEF_OUTPUT:
      gpio_set_dir(gpio_tbl[ch].pin, GPIO_OUT);
      break;

    case _DEF_OUTPUT_PULLUP:
      gpio_set_pulls(gpio_tbl[ch].pin, true, false);
      gpio_set_dir(gpio_tbl[ch].pin, GPIO_OUT);
      break;

    case _DEF_OUTPUT_PULLDOWN:
      gpio_set_pulls(gpio_tbl[ch].pin, false, true);
      gpio_set_dir(gpio_tbl[ch].pin, GPIO_OUT);
      break;
  }

  return ret;
};

void gpioPinWrite(uint8_t ch, uint8_t value)
{
    if (ch >= GPIO_MAX_CH)
    {
        return;
    }

    if (value)
    {
        gpio_put(gpio_tbl[ch].pin, gpio_tbl[ch].on_state);
    }
    else
    {
        gpio_put(gpio_tbl[ch].pin, gpio_tbl[ch].off_state);
    }
};

uint8_t gpioPinRead(uint8_t ch)
{
    uint8_t ret = _DEF_LOW;

    if (ch >= GPIO_MAX_CH)
    {
        return false;
    }

    if (gpio_get(gpio_tbl[ch].pin))
    {
        ret = _DEF_HIGH;
    }

    return ret;
};

void gpioPinToggle(uint8_t ch)
{
    if (ch >= GPIO_MAX_CH)
  {
    return;
  }

    gpio_xor_mask(1<<gpio_tbl[ch].pin);
};