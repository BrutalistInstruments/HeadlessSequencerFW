#include "debugTools.h"


void printMemorySection(uint32_t address, uint16_t numRegisters)
{
    for(int i = address; i<address+(4*numRegisters); i = i+4)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)i;
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", i);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printWholeMemoryMap()
{
    printCCM();
    printSRC();
    printGPC();
    printEDMA();
    printMemorySection(DMAMUX_START, DMAMUX_REG_COUNT);
    printMemorySection(LPUART1_START, LPUART1_REG_COUNT);
    printMemorySection(LPUART2_START, LPUART2_REG_COUNT);
    printMemorySection(LPUART3_START, LPUART3_REG_COUNT);
    printMemorySection(LPUART4_START, LPUART4_REG_COUNT);
    printMemorySection(LPUART5_START, LPUART5_REG_COUNT);
    printMemorySection(LPUART6_START, LPUART6_REG_COUNT);
    printMemorySection(LPUART7_START, LPUART7_REG_COUNT);
    printMemorySection(LPUART8_START, LPUART8_REG_COUNT);
}

void printCCM()
{
    uint32_t addressArray[] = {0x400FC000, 0x400FC008, 0x400FC00C, 0x400FC010, 
    0x400FC014, 0x400FC018, 0x400FC01C, 0x400FC020, 0x400FC024, 0x400FC028, 
    0x400FC02C, 0x400FC030, 0x400FC038, 0x400FC03C, 0x400FC048, 0x400FC054, 
    0x400FC058, 0x400FC05C, 0x400FC060, 0x400FC064, 0x400FC068, 0x400FC06C, 
    0x400FC070, 0x400FC074, 0x400FC078, 0x400FC07C, 0x400FC080, 0x400FC088};

    uint8_t arraySize = 28;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printSRC()
{
    uint32_t addressArray[] = {0x400F8000, 0x400F8004, 0x400F8008, 
    0x400F801C, 0x400F8020, 0x400F8024, 0x400F8028, 0x400F802C, 0x400F8030, 
    0x400F8034, 0x400F8038, 0x400F803C, 0x400F8040, 0x400F8044};
    uint8_t arraySize = 14;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printGPC()
{
    uint32_t addressArray[] = { 0x400F4000, 0x400F4008, 0x400F400C, 
    0x400F4010, 0x400F4014, 0x400F4018, 0x400F401C, 0x400F4020, 0x400F4024, 
    0x400F4034, 0x400F4038};
        
    uint8_t arraySize = 11;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printEDMA()
{
    uint32_t offsetArray[] = {0x0, 0x4, 0xC, 0x14, 0x18, 
    0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x24, 0x2C, 0x34, 0x44, 
    0x100, 0x101, 0x102, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 
    0x109, 0x10A, 0x10B, 0x10C, 0x10D, 0x10E, 0x10F, 0x110, 0x111, 
    0x112, 0x113, 0x114, 0x115, 0x116, 0x117, 0x118, 0x119, 0x11A, 
    0x11B, 0x11C, 0x11D, 0x11E, 0x11F};     

    uint8_t sizeArray[] = {32, 32, 32, 32, 8, 8, 8, 8, 8, 8, 8, 8, 32,
    32, 32, 32, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};         
    uint8_t arraySize = 48;

    for(int i = 0; i<arraySize; i++)
    {
        if(sizeArray[i] == 8)
        {
            uint8_t* currentMemoryAddress = ((uint8_t*)offsetArray[i])+EDMA_START;
            uint8_t currentValue = *currentMemoryAddress;
            PRINTF("%d", currentMemoryAddress);
            PRINTF(": ");
            PRINTF("%d\n", currentValue);
        }else
        {

            uint32_t* currentMemoryAddress = (uint32_t*)EDMA_START;
            currentMemoryAddress = currentMemoryAddress + offsetArray[i];
            uint32_t currentValue = *currentMemoryAddress;
            PRINTF("%d", currentMemoryAddress);
            PRINTF(": ");
            PRINTF("%d\n", currentValue);
        }
    }

    //now we do the other things
    uint8_t numRegistersLoop = 8;

    uint8_t startPeriph = 0;
    uint8_t endPeriph = 31;
    
    uint32_t offsetArray2[] = {0x1000, 0x1004, 0x1006, 0x1008, 
    0x100C, 0x1010, 0x1014, 0x1016, 0x1018, 0x101C, 0x101E};

    uint8_t sizeArray2[] = {32, 16, 16, 32, 32, 32, 16, 16, 32, 16, 16};

    uint8_t arraySize2 = 11;

    for(int i = startPeriph; i<endPeriph; i++)
    {
        for(int j = 0; j<arraySize2; j++)
        {
            if(sizeArray2[j] == 32)
            {
                uint32_t* currentMemoryAddress = (uint32_t*)(offsetArray2[j] + (i*0x20));
                uint32_t currentValue = *currentMemoryAddress;
                PRINTF("%d", currentMemoryAddress);
                PRINTF(": ");
                PRINTF("%d\n", currentValue);
            }else
            {
                uint16_t* currentMemoryAddress = (uint16_t*)(offsetArray2[j] + (i*0x20));
                uint16_t currentValue = *currentMemoryAddress;
                PRINTF("%d", currentMemoryAddress);
                PRINTF(": ");
                PRINTF("%d\n", currentValue);

            }


        }


    }




}
