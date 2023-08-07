#include "ap.h"

void cliInfo(cli_args_t *args);

void apInit(void)
{ 

    hwInit();

    cliOpen(_DEF_UART1, 115200);
    cliAdd("info", cliInfo); 

}

void apMain(void)
{
    
    uint32_t pre_time = millis();
    for(;;)
    {
        if (millis()-pre_time >= 500)
        {
            ledToggle(_DEF_LED1);
            delay(200);
        }
        cliMain();
    }

}

void cliInfo(cli_args_t *args)
{
  bool ret = false;

  if (args->argc == 1 && args->isStr(0, "flash"))
  {
    extern const uint32_t __flash_binary_start;
    extern const uint32_t __flash_binary_end;

    cliPrintf("Flash FW Start : 0x%X\r\n", &__flash_binary_start);
    cliPrintf("Flash FW End   : 0x%X\r\n", &__flash_binary_end);
    cliPrintf("Flash FW Size  : %d Bytes\r\n", ((uint32_t)&__flash_binary_end - (uint32_t)&__flash_binary_start));

    ret = true;
  }

  if (ret != true)
  {
    cliPrintf("info flash\n");
  }
}