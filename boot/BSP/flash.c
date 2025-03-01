#include "flash.h"
#include "stdio.h"
// 解锁 Flash
void Flash_Unlock(void) {
    FLASH_Unlock();
    while (FLASH_GetStatus() == FLASH_BUSY);
}

// 锁定 Flash
void Flash_Lock(void) {
    FLASH_Lock();
}

// 擦除指定扇区的数据
// 例如：主APP放在 FLASH_Sector_6，备份APP放在 FLASH_Sector_7
FLASH_Status EraseAppSector(uint32_t FLASH_Sector) {
    Flash_Unlock();
    FLASH_Status status = FLASH_EraseSector(FLASH_Sector, VoltageRange_3);
    Flash_Lock();
    return status;
}

// 向 Flash 指定地址写入 32 位数据
FLASH_Status Flash_Write(uint32_t address, uint32_t data) {
    Flash_Unlock();
    
    // 清除可能的错误标志位
   // FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
    
    // 写入 32 位数据
    FLASH_Status status = FLASH_ProgramWord(address, data);
    
    if (status == FLASH_COMPLETE) {
        // 数据写入成功
        printf("Flash_Write success\n");
    } else {
        // 数据写入失败，打印错误信息
        printf("Flash_Write fail, status: %d\n", status);
    }
    
    Flash_Lock();
    return status;
}
