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

void printMemorySection16(uint32_t address, uint16_t numRegisters)
{
        for(int i = address; i<address+(2*numRegisters); i = i+2)
    {
        uint16_t* currentMemoryAddress = (uint16_t*)i;
        uint16_t currentValue = *currentMemoryAddress;
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
    printTSC();
    printAnalog();
    printSNVS();
    printWDOG1();
    printWDOG2();
    printGPIO(GPIO5_START);
    printGPIO(GPIO4_START);
    printGPIO(GPIO3_START);
    printGPIO(GPIO2_START);
    printGPIO(GPIO1_START);
    printMemorySection(ADC2_START, ADC2_REG_COUNT);
    printMemorySection(ADC1_START, ADC1_REG_COUNT);
    printMemorySection(DMAMUX_START, DMAMUX_REG_COUNT);
    printEWM();
    printMemorySection(FLEXRAM_START, FLEXRAM_REG_COUNT);
    printMemorySection(IOMUXC_GPR_START, IOMUXC_GPR_REG_COUNT);
    printMemorySection(IOMUXC_SNVS_START, IOMUXC_SNVS_REG_COUNT);
    printMemorySection(IOMUXC_SNVS_GPR_START, IOMUXC_SNVS_GPR_REG_COUNT);
    printACMP();
    printPIT();
    printAIPSConfig();
    printMemorySection(DCDC_START, DCDC_REG_COUNT);
    printMemorySection(IOMUXC_START, IOMUXC_REG_COUNT);
    printOCOTP();
    printMemorySection(GPT1_START, GPT1_REG_COUNT);
    printMemorySection(GPT2_START, GPT2_REG_COUNT);
    printQTimer();
    printFlexCan();
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

void printTSC()
{
    uint32_t addressArray[] = {0x400E000, 0x400E010, 0x400E020, 
    0x400E030, 0x400E040, 0x400E050, 0x400E060, 0x400E070, 0x400E080};
    uint8_t arraySize = 9;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printAnalog()
{
    uint32_t addressArray[] = {0x400D8000, 0x400D8004, 0x400D8008, 
    0x400D800C, 0x400D8010, 0x400D8014, 0x400D8018, 0x400D801C, 0x400D8020, 
    0x400D8024, 0x400D8028, 0x400D802C, 0x400D8030, 0x400D8034, 0x400D8038, 0x400D803C, 0x400D8040, 0x400D8050, 0x400D8060, 0x400D8070, 0x400D8074, 0x400D8078, 0x400D807C, 0x400D8080, 0x400D8090, 0x400D80A0, 0x400D80A4, 0x400D80A8, 0x400D80AC, 0x400D80B0, 0x400D80C0, 0x400D80E0, 0x400D80E4, 0x400D80E8, 0x400D80EC, 0x400D80F0, 0x400D80F4, 0x400D80F8, 0x400D80FC, 0x400D8100, 0x400D8104, 0x400D8108, 0x400D810C, 0x400D8150, 0x400D8154, 0x400D8158, 0x400D815C, 0x400D8160, 0x400D8164, 0x400D8168, 0x400D816C, 0x400D8170, 0x400D8174, 0x400D8178, 0x400D817C};
    uint8_t arraySize = 55;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}


void printSNVS()
{
    uint8_t offsetArray[] = {0x0, 0x04, 0x08, 0x14, 0x24, 0x28,
    0x2C, 0x30, 0x34, 0x4C, 0x5C, 0x60, 0x68};

    uint8_t arraySize = 13;
    uint32_t startMemoryAddress = 0x400D4000;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)startMemoryAddress;
        currentMemoryAddress = currentMemoryAddress + offsetArray[i];
        uint32_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }

    uint16_t offsetStarts[] = {0x0090, 0x0100, 0x0BF8, 0x08FC};
    uint8_t arraySize2 = 4;

    //For a = 0 to 3:
    //LPGPRa_alias = 90h + (a × 4h)
    //LPGPRa = 100h + (a × 4h)
    for(int i = 0; i<4; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)startMemoryAddress;
        currentMemoryAddress = currentMemoryAddress + offsetStart[0] + (i*4);
        uint32_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);

        currentMemoryAddress = (uint32_t*)startMemoryAddress;
        currentMemoryAddress = currentMemoryAddress + offsetStart[1] + (i*4);
        uint32_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }

    uint32_t* currentMemoryAddress = (uint32_t*)startMemoryAddress;
    currentMemoryAddress = currentMemoryAddress + offsetStart[2];
    uint32_t currentValue = *currentMemoryAddress;

    PRINTF("%d", currentMemoryAddress);
    PRINTF(": ");
    PRINTF("%d\n", currentValue);

    currentMemoryAddress = (uint32_t*)startMemoryAddress;
    currentMemoryAddress = currentMemoryAddress + offsetStart[3];
    currentValue = *currentMemoryAddress;

    PRINTF("%d", currentMemoryAddress);
    PRINTF(": ");
    PRINTF("%d\n", currentValue);
}

void printWDOG2()
{

    for(int i = 0; i<5; i++)
    {
        uint16_t* currentMemoryAddress = (uint16_t*)0x400D0000;
        currentMemoryAddress = currentMemoryAddress + (i*2);
        uint16_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printWDOG1()
{

    for(int i = 0; i<5; i++)
    {
        uint16_t* currentMemoryAddress = (uint16_t*)0x400B8000;
        currentMemoryAddress = currentMemoryAddress + (i*2);
        uint16_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printGPIO(uint32_t GPIOStartAddress)
{
    uint8_t offsetArray[] = {0x00, 0x04, 0x08, 0x0C, 0x10,
    0x14, 0x18, 0x1C, 0x84, 0x88, 0x8C};

    uint8_t arraySize = 11;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)GPIOStartAddress;
        currentMemoryAddress = currentMemoryAddress + offsetArray[i];
        uint32_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);        
    }
}

void printEWM()
{
    for(int i = 0; i<6; i++)
    {
        uint8_t* currentMemoryAddress = (uint8_t*)0x400B4000;
        currentMemoryAddress = currentMemoryAddres+i;
        uint8_t currentValue = *currentMemoryAddress

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printACMP()
{
    uint32_t addressArray[] = {0x40094000, 0x40094001, 0x40094002, 
    0x40094003, 0x40094004, 0x40094005, 0x40094008, 0x40094009, 
    0x4009400A, 0x4009400B, 0x4009400C, 0x4009400D, 0x40094010, 
    0x40094011, 0x40094012, 0x40094013, 0x40094014, 0x40094015, 
    0x40094018, 0x40094019, 0x4009401A, 0x4009401B, 0x4009401C, 0x4009401D};
    
    uint8_t arraySize = 24;

    for(int i = 0; i<arraySize; i++)
    {
        uint8_t* currentMemoryAddress = (uint8_t*)addressArray[i];
        uint8_t currentValue = *currentMemoryAddress;

        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);

    }

}

void printPIT()
{
    uint32_t addressArray[] = {0x40080000, 0x400800E0, 0x400800E4, 
    0x40080100, 0x40080104, 0x40080108, 0x4008010C, 0x40080110, 
    0x40080114, 0x40080118, 0x4008011C, 0x40080120, 0x40080124, 
    0x40080128, 0x4008012C, 0x40080130, 0x40080134, 0x40080138, 0x4008013C};

    uint8_t arraySize = 19;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printAIPSConfig()
{
    uint32_t addressArray[] = {0x4007C000, 0x4007C040, 0x4007C044, 
    0x4007C048, 0x4007C04C, 0x4007C050, 0x4017C000, 0x4017C040, 
    0x4017C044, 0x4017C048, 0x4017C04C, 0x4017C050, 0x4027C000, 
    0x4027C040, 0x4027C044, 0x4027C048, 0x4027C04C, 0x4027C050, 
    0x4037C000, 0x4037C040, 0x4037C044, 0x4037C048, 0x4037C04C, 0x4037C050}
    uint8_t arraySize = 24;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }

}

void printKPP()
{
    uint32_t addressArray[] = {0x401FC000, 0x401FC002, 0x401FC004, 0x401FC006};    
    uint8_t arraySize = 4;

    for(int i = 0; i<arraySize; i++)
    {
        uint16_t* currentMemoryAddress = (uint16_t*)addressArray[i];
        uint16_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}


void printOCOTP()
{
    uint32_t baseAddress = 0x401F4000;
    uint16_t offsetArray[] = { 0x0000, 0x0004, 0x0008, 0x000C, 
    0x0010, 0x0020, 0x0030, 0x0040, 0x0060, 0x0064, 0x0068, 
    0x006C, 0x0090, 0x0100, 0x0400, 0x0410, 0x0420, 0x0430, 
    0x0440, 0x0450, 0x0460, 0x0470, 0x04F0, 0x0600, 0x0610, 
    0x0620, 0x0630, 0x0640, 0x0660, 0x0670, 0x0680, 0x06D0, 0x06E0};

    uint8_t arraySize = 33;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)baseAddress;
        currentMemoryAddress = currentMemoryAddress + offsetArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }

}

void printQTimer()
{
    uint32_t addressArray[] = { 0x401DC000, 0x401DC002, 0x401DC004, 0x401DC006, 
    0x401DC008, 0x401DC00A, 0x401DC00C, 0x401DC00E, 0x401DC010, 0x401DC012, 0x401DC014, 
    0x401DC016, 0x401DC018, 0x401DC01E, 0x401DC020, 0x401DC022, 0x401DC024, 0x401DC026, 
    0x401DC028, 0x401DC02A, 0x401DC02C, 0x401DC02E, 0x401DC030, 0x401DC032, 0x401DC034, 
    0x401DC036, 0x401DC038, 0x401DC040, 0x401DC042, 0x401DC044, 0x401DC046, 0x401DC048, 
    0x401DC04A, 0x401DC04C, 0x401DC04E, 0x401DC050, 0x401DC052, 0x401DC054, 0x401DC056, 
    0x401DC058, 0x401DC060, 0x401DC062, 0x401DC064, 0x401DC066, 0x401DC068, 0x401DC06A, 
    0x401DC06C, 0x401DC06E, 0x401DC070, 0x401DC072, 0x401DC074, 0x401DC076, 0x401DC078, 
    0x401E0000, 0x401E0002, 0x401E0004, 0x401E0006, 0x401E0008, 0x401E000A, 0x401E000C, 
    0x401E000E, 0x401E0010, 0x401E0012, 0x401E0014, 0x401E0016, 0x401E0018, 0x401E001E, 
    0x401E0020, 0x401E0022, 0x401E0024, 0x401E0026, 0x401E0028, 0x401E002A, 0x401E002C, 
    0x401E002E, 0x401E0030, 0x401E0032, 0x401E0034, 0x401E0036, 0x401E0038, 0x401E0040, 
    0x401E0042, 0x401E0044, 0x401E0046, 0x401E0048, 0x401E004A, 0x401E004C, 0x401E004E, 
    0x401E0050, 0x401E0052, 0x401E0054, 0x401E0056, 0x401E0058, 0x401E0060, 0x401E0062, 
    0x401E0064, 0x401E0066, 0x401E0068, 0x401E006A, 0x401E006C, 0x401E006E, 0x401E0070, 
    0x401E0072, 0x401E0074, 0x401E0076, 0x401E0078, 0x401E4000, 0x401E4002, 0x401E4004, 
    0x401E4006, 0x401E4008, 0x401E400A, 0x401E400C, 0x401E400E, 0x401E4010, 0x401E4012, 
    0x401E4014, 0x401E4016, 0x401E4018, 0x401E401E, 0x401E4020, 0x401E4022, 0x401E4024, 
    0x401E4026, 0x401E4028, 0x401E402A, 0x401E402C, 0x401E402E, 0x401E4030, 0x401E4032, 
    0x401E4034, 0x401E4036, 0x401E4038, 0x401E4040, 0x401E4042, 0x401E4044, 0x401E4046, 
    0x401E4048, 0x401E404A, 0x401E404C, 0x401E404E, 0x401E4050, 0x401E4052, 0x401E4054, 
    0x401E4056, 0x401E4058, 0x401E4060, 0x401E4062, 0x401E4064, 0x401E4066, 0x401E4068, 
    0x401E406A, 0x401E406C, 0x401E406E, 0x401E4070, 0x401E4072, 0x401E4074, 0x401E4076, 
    0x401E4078, 0x401E8000, 0x401E8002, 0x401E8004, 0x401E8006, 0x401E8008, 0x401E800A, 
    0x401E800C, 0x401E800E, 0x401E8010, 0x401E8012, 0x401E8014, 0x401E8016, 0x401E8018, 
    0x401E801E, 0x401E8020, 0x401E8022, 0x401E8024, 0x401E8026, 0x401E8028, 0x401E802A, 
    0x401E802C, 0x401E802E, 0x401E8030, 0x401E8032, 0x401E8034, 0x401E8036, 0x401E8038, 
    0x401E8040, 0x401E8042, 0x401E8044, 0x401E8046, 0x401E8048, 0x401E804A, 0x401E804C, 
    0x401E804E, 0x401E8050, 0x401E8052, 0x401E8054, 0x401E8056, 0x401E8058, 0x401E8060, 
    0x401E8062, 0x401E8064, 0x401E8066, 0x401E8068, 0x401E806A, 0x401E806C, 0x401E806E, 
    0x401E8070, 0x401E8072, 0x401E8074, 0x401E8076, 0x401E8078};

    uint8_t arraySize = 212;

    
    for(int i = 0; i<arraySize; i++)
    {
        uint16_t* currentMemoryAddress = (uint16_t*)addressArray[i];
        uint16_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}

void printFlexCan()
{
    uint32_t addressArray[] = { 0x401D0000, 0x401D0004, 0x401D0008, 0x401D0010, 
    0x401D0014, 0x401D0018, 0x401D001C, 0x401D0020, 0x401D0024, 0x401D0028, 0x401D002C, 
    0x401D0030, 0x401D0034, 0x401D0038, 0x401D0044, 0x401D0048, 0x401D004C, 0x401D0058, 
    0x401D005C, 0x401D0880, 0x401D0884, 0x401D0888, 0x401D088C, 0x401D0890, 0x401D0894, 
    0x401D0898, 0x401D089C, 0x401D08A0, 0x401D08A4, 0x401D08A8, 0x401D08AC, 0x401D08B0, 
    0x401D08B4, 0x401D08B8, 0x401D08BC, 0x401D08C0, 0x401D08C4, 0x401D08C8, 0x401D08CC, 
    0x401D08D0, 0x401D08D4, 0x401D08D8, 0x401D08DC, 0x401D08E0, 0x401D08E4, 0x401D08E8, 
    0x401D08EC, 0x401D08F0, 0x401D08F4, 0x401D08F8, 0x401D08FC, 0x401D0900, 0x401D0904, 
    0x401D0908, 0x401D090C, 0x401D0910, 0x401D0914, 0x401D0918, 0x401D091C, 0x401D0920, 
    0x401D0924, 0x401D0928, 0x401D092C, 0x401D0930, 0x401D0934, 0x401D0938, 0x401D093C, 
    0x401D0940, 0x401D0944, 0x401D0948, 0x401D094C, 0x401D0950, 0x401D0954, 0x401D0958, 
    0x401D095C, 0x401D0960, 0x401D0964, 0x401D0968, 0x401D096C, 0x401D0970, 0x401D0974, 
    0x401D0978, 0x401D097C, 0x401D09E0, 0x401D4000, 0x401D4004, 0x401D4008, 0x401D4010, 
    0x401D4014, 0x401D4018, 0x401D401C, 0x401D4020, 0x401D4024, 0x401D4028, 0x401D402C, 
    0x401D4030, 0x401D4034, 0x401D4038, 0x401D4044, 0x401D4048, 0x401D404C, 0x401D4058, 
    0x401D405C, 0x401D4880, 0x401D4884, 0x401D4888, 0x401D488C, 0x401D4890, 0x401D4894, 
    0x401D4898, 0x401D489C, 0x401D48A0, 0x401D48A4, 0x401D48A8, 0x401D48AC, 0x401D48B0, 
    0x401D48B4, 0x401D48B8, 0x401D48BC, 0x401D48C0, 0x401D48C4, 0x401D48C8, 0x401D48CC, 
    0x401D48D0, 0x401D48D4, 0x401D48D8, 0x401D48DC, 0x401D48E0, 0x401D48E4, 0x401D48E8, 
    0x401D48EC, 0x401D48F0, 0x401D48F4, 0x401D48F8, 0x401D48FC, 0x401D4900, 0x401D4904, 
    0x401D4908, 0x401D490C, 0x401D4910, 0x401D4914, 0x401D4918, 0x401D491C, 0x401D4920, 
    0x401D4924, 0x401D4928, 0x401D492C, 0x401D4930, 0x401D4934, 0x401D4938, 0x401D493C, 
    0x401D4940, 0x401D4944, 0x401D4948, 0x401D494C, 0x401D4950, 0x401D4954, 0x401D4958, 
    0x401D495C, 0x401D4960, 0x401D4964, 0x401D4968, 0x401D496C, 0x401D4970, 0x401D4974, 
    0x401D4978, 0x401D497C, 0x401D49E0};
    uint8_t arraySize = 168;

    for(int i = 0; i<arraySize; i++)
    {
        uint32_t* currentMemoryAddress = (uint32_t*)addressArray[i];
        uint32_t currentValue = *currentMemoryAddress;
        PRINTF("%d", currentMemoryAddress);
        PRINTF(": ");
        PRINTF("%d\n", currentValue);
    }
}
