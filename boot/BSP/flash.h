#ifndef FLASH_H
#define FLASH_H

// 包含必要的头文件
#include <stdint.h>
#include "stm32f4xx.h"
void Flash_Unlock(void);
void Flash_Lock(void);
FLASH_Status EraseAppSector(uint32_t FLASH_Sector);
FLASH_Status Flash_Write(uint32_t address, uint32_t data);

#endif // FLASH_H
