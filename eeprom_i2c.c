/**
 * @file eeprom_i2c.c
 * @author nihal.kt (nihalfarhankt101@gmail.com)
 * @brief Implementation of eeprom_i2c.h
 * @version 0.1
 * @date 2024-02-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "eeprom_i2c.h"

typedef enum
{
    I2C_OK,
    I2C_ERROR
}
I2C_Status_t;

uint32_t EEPROM_DEV_TABLE[4][7] = {
//  Chip_Type        Size   Address Bits     Address size       Address mask   Rd Size   Wr Size   Timeout
    [x24C08]   =   { 1024,   8,          I2C_MEMADD_SIZE_8BIT,  0x000000FF,     256,        16,     100 },
    [x24C32]   =   { 4096,   0,          I2C_MEMADD_SIZE_16BIT, 0x00000000,     256,        32,     100 },
    [x24M01]   =   { 131072, 16,         I2C_MEMADD_SIZE_16BIT, 0x0000FFFF,     256,        256,    100 },
    [x24M01X4] =   { 524288, 16,         I2C_MEMADD_SIZE_16BIT, 0x0000FFFF,     256,        256,    100 }
};

/******************************* static functions ***************************/

/**
 * @brief Porting device specific I2C api function for I2C Write
 * 
 * @param devAddr 
 * @param mem_addr 
 * @param mem_addr_size 
 * @param data 
 * @param len 
 * @return I2C_Status_t 
 */
static I2C_Status_t I2C_Write(uint16_t devAddr, uint32_t mem_addr, uint32_t mem_addr_size, uint8_t* data, uint16_t len);

/**
 * @brief Porting device specific I2C api function for I2C Read
 * 
 * @param devAddr 
 * @param mem_addr 
 * @param mem_addr_size 
 * @param data_buff 
 * @param len 
 * @return I2C_Status_t 
 */
static I2C_Status_t I2C_Read(uint16_t devAddr, uint32_t mem_addr, uint32_t mem_addr_size, uint8_t* data_buff, uint16_t len);

/****************************************************************************/

EE_State_t EEPROM_Write(EEPROM_Chip_t eeprom_chip, uint8_t* data, uint16_t len)
{
    EE_State_t ee_status = EE_SUCCESS;

    if ( len < PAGE_SIZE)
    {
        // i2c write
        I2C_Write(EEPROM_ADDR, 0x00000001, EEPROM_DEV_TABLE[EEPROM_CHIP][2], data, len);
    }
    else
    {
        ee_status = EE_LEN_LARGE_ERROR;
    }

    return ee_status;

}

static I2C_Status_t I2C_Read(uint16_t devAddr, uint32_t mem_addr, uint32_t mem_addr_size, uint8_t* data_buff, uint16_t len)
{
    I2C_Status_t status = I2C_OK;
    // 

    return status;
}

static I2C_Status_t I2C_Write(uint16_t devAddr, uint32_t mem_addr, uint32_t mem_addr_size, uint8_t* data, uint16_t len)
{
    I2C_Status_t status = I2C_OK;
    // 

    return status;
}