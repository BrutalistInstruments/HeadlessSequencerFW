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
    printMemorySection(LPUART1_START, LPUART1_REG_COUNT);
    printMemorySection(LPUART2_START, LPUART2_REG_COUNT);
    printMemorySection(LPUART3_START, LPUART3_REG_COUNT);
    printMemorySection(LPUART4_START, LPUART4_REG_COUNT);
    printMemorySection(LPUART5_START, LPUART5_REG_COUNT);
    printMemorySection(LPUART6_START, LPUART6_REG_COUNT);
    printMemorySection(LPUART7_START, LPUART7_REG_COUNT);
    printMemorySection(LPUART8_START, LPUART8_REG_COUNT);
}