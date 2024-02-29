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
    // [x24M01]   =   { 131072, 16,         I2C_MEMADD_SIZE_16BIT, 0x0000FFFF,     256,        256,    100 },
    // [x24M01X4] =   { 524288, 16,         I2C_MEMADD_SIZE_16BIT, 0x0000FFFF,     256,        256,    100 }
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

EE_State_t EEPROM_Write(EEPROM_Chip_t eeprom_chip, uint32_t memory_addr, uint8_t* data, uint16_t len)
{
    EE_State_t ee_status = EE_SUCCESS;

    uint32_t page_beg = memory_addr / EEPROM_DEV_TABLE[eeprom_chip][4];
    uint32_t page_end = ((memory_addr + len - 1) / EEPROM_DEV_TABLE[eeprom_chip][4]);
    uint32_t offset = 0;


    uint32_t start = addr
    if (len < page_size)
    {
        // write in this page
    }
    else
    {
        page += 1
        len % page_size > PAGE_SIZE
        {
            // nxt page
            page += 1
        }
    }

void getMaxPagesReq(uint32_t* pages_tot, uint32_t* remLen, uint32_t len, uint32_t page_size)
{
    uint8_t pages = 0;
    
    while (len > page_size)
    {
        printf("%d\n", len);
        pages += 1;
        len = len - page_size;
    }
    
    printf("remaining length: %d\n", len);
    *pages_tot = pages;
    *remLen = len;
}



    for (uint32_t page = page_beg; page <= page_end, ++page)
    {

    }
        // i2c write
        I2C_Write(EEPROM_ADDR | ((start_address & 0x0100)), 0x00000001, EEPROM_DEV_TABLE[EEPROM_CHIP][2], data, len);


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

    uint32_t page_start = address / EEPROM_DEV_TABLE[eeprom_chip][4];
    uint32_t page_end = ((address + len - 1) / M24CXX_READ_PAGE_SIZE);
    uint32_t data_offset = 0;

    for (uint32_t page = page_start; page <= page_end; ++page) {

        uint32_t i2c_address, start_address, read_len;

        start_address = page == page_start ? address : page * M24CXX_READ_PAGE_SIZE;
        read_len = page == page_end ? len - data_offset : (page == page_start ? ((page + 1) * M24CXX_READ_PAGE_SIZE) - start_address : M24CXX_READ_PAGE_SIZE);
        i2c_address = m24cxx->i2c_address + (start_address >> M24CXX_ADDRESS_BITS);

        HAL_StatusTypeDef result = HAL_I2C_Mem_Read(m24cxx->i2c, i2c_address << 1, start_address & M24CXX_ADDRESS_MASK, M24CXX_ADDRESS_SIZE, data + data_offset, read_len,
        HAL_MAX_DELAY);


        data_offset += read_len;

    }

    /*
    1010 a1 a2 a3 r/w
    */