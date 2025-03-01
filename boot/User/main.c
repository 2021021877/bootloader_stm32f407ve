
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
/* �������� */
typedef void (*pFunction)(void);

/* APP flash address */


void jump_to_app(void)
{
  uint32_t JumpAddress;
  pFunction Jump_To_Application;

  /* ���ջ����ַ�Ƿ�Ϸ� */
  if(((*(__IO uint32_t *)APP_FLASH_ADDR) & 0x2FFE0000) == 0x20000000)
  {
    /* ���������жϣ���ֹ����ת�����У��жϸ��ų����쳣 */
    __disable_irq();

    /* �û��������ڶ��� �� Ϊ����ʼ��ַ(��λ��ַ) */
    JumpAddress = *(__IO uint32_t *) (APP_FLASH_ADDR + 4);

    /* Initialize user application's Stack Pointer */
    /* ��ʼ��APP��ջָ��(�û��������ĵ�һ�������ڴ��ջ����ַ) */
    __set_MSP(*(__IO uint32_t *) APP_FLASH_ADDR);

    /* ����ת�� */
    Jump_To_Application = (pFunction) JumpAddress;

    /* ��ת�� APP */
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



