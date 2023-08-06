#include "ap.h"

void apInit(void)
{
    bspInit();
    hwInit();
}

void apMain(void)
{
    uint32_t pre_time = millis();
    for(;;)
    {
        if(millis() - pre_time > 200)
        {
            ledToggle(_DEF_LED1);
            pre_time = millis();
        }
    }
}