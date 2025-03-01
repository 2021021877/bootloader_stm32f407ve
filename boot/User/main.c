
#include "stm32f4xx.h"
#include "bsp_key.h"
#include "bsp_uart.h"
#include "flash.h"
#include "stdio.h"

int fputc(int ch, FILE *f)
{
    Uart_SendByte(USART1, ch);
    return ch;
}
#define APP_FLASH_ADDR             (0x8008000)
/* 定义类型 */
typedef void (*pFunction)(void);

/* APP flash address */


void jump_to_app(void)
{
  uint32_t JumpAddress;
  pFunction Jump_To_Application;

  /* 检查栈顶地址是否合法 */
  if(((*(__IO uint32_t *)APP_FLASH_ADDR) & 0x2FFE0000) == 0x20000000)
  {
    /* 屏蔽所有中断，防止在跳转过程中，中断干扰出现异常 */
    __disable_irq();

    /* 用户代码区第二个 字 为程序开始地址(复位地址) */
    JumpAddress = *(__IO uint32_t *) (APP_FLASH_ADDR + 4);

    /* Initialize user application's Stack Pointer */
    /* 初始化APP堆栈指针(用户代码区的第一个字用于存放栈顶地址) */
    __set_MSP(*(__IO uint32_t *) APP_FLASH_ADDR);

    /* 类型转换 */
    Jump_To_Application = (pFunction) JumpAddress;

    /* 跳转到 APP */
    Jump_To_Application();
  }
}
int main(void)
{
   Key_Init();
	 Uart_Init();
	 printf("hello bootloader\n");
	 printf("hello bootloader\n");
	 printf("hello bootloader\n");
	 printf("hello bootloader\n");
	 jump_to_app();
	 printf("error\n");
    while (1)                                        
    {
 
	
    }
}



