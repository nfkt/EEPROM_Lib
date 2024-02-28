/**
 * @file eeprom_config.h
 * @author nihal.kt (nihalfarhankt101@gmail.com)
 * @brief config for I2C based EEPROM
 * @version 0.1
 * @date 2024-02-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __EEPROM_CONFIG_H__
#define __EEPROM_CONFIG_H__

typedef enum
{
    x24C08 = 0,
    x24C16,
    x24C32,
    x24C512,
    x24M01,
    x24M01X4
    // All the chips
}   
EEPROM_Chip_t;                 
#define EEPROM_ADDR             0xA0 // Address of M24C32
#define EEPROM_CHIP             x24C08

/**
 * @brief Possible values are (in Kbits)
 *        1, 2, 4, 8, 16, 32, 64, 128, 256, 512
 * 
 */
#define x24C_SIZE               32   // 32Kbits       
#define PAGE_SIZE               32   // 32 bytes  
  

#endif // __EEPROM_CONFIG_H__