/**
 * @file eeprom_i2c.h
 * @author nihal.kt (nihalfarhankt101@gmail.com)
 * @brief I2C based EEPROM module
 * @version 0.1
 * @date 2024-02-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __EEPROM_I2C_H__
#define __EEPROM_I2C_H__

#include <stdint.h>

#include "eeprom_config.h"

#define I2C_MEMADD_SIZE_8BIT    0x00000001
#define I2C_MEMADD_SIZE_16BIT   0x00000010

#if EEPROM_CHIP == M24C08
#define M24CXX_TYPE              "24C08"
#define M24CXX_SIZE                1024
#define M24CXX_ADDRESS_BITS           8
#define M24CXX_ADDRESS_SIZE           I2C_MEMADD_SIZE_8BIT
#define M24CXX_ADDRESS_MASK  0x000000ff
#define M24CXX_READ_PAGE_SIZE       256
#define M24CXX_WRITE_PAGE_SIZE       16
#define M24CXX_WRITE_TIMEOUT        100
#elif EEPROM_CHIP == M24M01
#define M24CXX_TYPE              "24M01"
#define M24CXX_SIZE              131072
#define M24CXX_PAGE_ADDRESS_BITS      1
#define M24CXX_ADDRESS_BITS          16
#define M24CXX_ADDRESS_SIZE           I2C_MEMADD_SIZE_16BIT
#define M24CXX_ADDRESS_MASK  0x0000ffff
#define M24CXX_READ_PAGE_SIZE       256
#define M24CXX_WRITE_PAGE_SIZE      256
#define M24CXX_WRITE_TIMEOUT        100
#elif M24CXX_MODEL == M24M01X4
#define M24CXX_TYPE              "4 x 24M01"
#define M24CXX_SIZE              524288
#define M24CXX_PAGE_ADDRESS_BITS      1
#define M24CXX_ADDRESS_BITS          16
#define M24CXX_ADDRESS_SIZE           I2C_MEMADD_SIZE_16BIT
#define M24CXX_ADDRESS_MASK  0x0000ffff
#define M24CXX_READ_PAGE_SIZE       256
#define M24CXX_WRITE_PAGE_SIZE      256
#define M24CXX_WRITE_TIMEOUT        100
#else
#error "M24CXX_MODEL must be defined in project properties"
#endif


typedef enum
{
    EE_SUCCESS = 0,
    EE_WR_ERROR,
    EE_RD_ERROR,
    EE_LEN_LARGE_ERROR
}
EE_State_t;

/**
 * @brief 
 * 
 * @param data 
 * @param len 
 * @return EE_State_t 
 */
EE_State_t EEPROM_Write(EEPROM_Chip_t eeprom_chip, uint8_t* data, uint16_t len);

/**
 * @brief 
 * 
 * @param data_buff 
 * @param len 
 * @return EE_State_t 
 */
EE_State_t EEPROM_Read(uint8_t* data_buff, uint16_t len);

/**
 * @brief 
 * 
 * @return EE_State_t 
 */
EE_State_t EEPROM_Erase(void);

#endif // __EEPROM_I2C_H__