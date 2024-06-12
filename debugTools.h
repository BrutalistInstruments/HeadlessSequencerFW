#include "fsl_debug_console.h"


/*

AIPS-1 ->               4000_0000 to 400F_FFFF
    CCM(CCM) ->         400F_C000 400F_FFFF -> Spread, complete
    SRC(SRC) ->         400F_8000 400F_BFFF -> Spread, complete
    GPC ->              400F_4000 400F_7FFF -> Spread, complete
    DMA_CH_MUX ->       400E_C000 400E_FFFF -> Packed, complete
    EDMA ->             400E_8000 400E_BFFF -> Spread, complete
    SJC ->              400E_4000 400E_7FFF //missing?
    TSC_DIG ->          400E_0000 400E_3FFF -> Spread, complete
    CSU ->              400D_C000 400D_FFFF //missing?
    ANALOG ->           400D_8000 400D_BFFF -> spread, complete
    SNVS_HP ->          400D_4000 400D_7FFF -> spread, complete
    WDOG2 ->            400D_0000 400D_3FFF -> packed, complete
    TRNG ->             400C_C000 400C_FFFF //true random number generator. Cool. Also missing
    ADC2 ->             400C_8000 400C_BFFF -> packed, complete
    ADC1 ->             400C_4000 400C_7FFF -> packed, complete
    GPIO5 ->            400C_0000 400C_3FFF -> spread, complete
    WDOG3 ->            400B_C000 400B_FFFF -> Packed, complete
    WDOG1 ->            400B_8000 400B_BFFF -> packed, complete
    EWM ->              400B_4000 400B_7FFF -> packed, complete
    CM7_MXRT(FLEXRAM) ->400B_0000 400B_3FFF -> packed, complete
    IOMUXC_GPR ->       400A_C000 400A_FFFF -> packed, complete
    IOMUXC_SNVS ->      400A_8000 400A_BFFF -> packed, complete
    IOMUXC_SNVS_GPR ->  400A_4000 400A_7FFF -> packed, complete
    ACMP ->             4009_4000 4009_7FFF -> spread, complete
    PIT ->              4008_4000 4008_7FFF -> spread, complete
    DCDC ->             4008_0000 4008_3FFF -> packed, complete
    AIPS-1 Config ->    4007_C000 4007_FFFF -> spread, complete

AIPS-2                  4010_0000 to 401F_FFFF
    KPP ->              401F_C000 401F_FFFF -> packed, complete
    IOMUXC ->           401F_8000 401F_BFFF -> packed, complete
    OCOTP ->            401F_4000 401F_7FFF -> spread, complete
    GPT2 ->             401F_0000 401F_3FFF -> packed, complete
    GPT1 ->             401E_C000 401E_FFFF -> packed, complete
    QTimer4 ->          401E_8000 401E_BFFF -> spread, complete
    QTimer3 ->          401E_4000 401E_7FFF -> spread, complete
    QTimer2 ->          401E_0000 401E_3FFF -> spread, complete
    QTimer1 ->          401D_C000 401D_FFFF -> spread, complete
    FlexCAN2 ->         401D_4000 401D_7FFF -> spread, complete
    FlexCAN1 ->         401D_0000 401D_3FFF -> spread, complete
    GPIO4 ->            401C_4000 401C_7FFF -> spread, complete
    GPIO3 ->            401C_0000 401C_3FFF -> spread, complete
    GPIO2 ->            401B_C000 401B_FFFF -> spread, complete
    GPIO1 ->            401B_8000 401B_BFFF -> spread, complete
    FlexIO2 ->          401B_0000 401B_3FFF 
    FlexIO1 ->          401A_C000 401A_FFFF 
    LPUART8 ->          401A_0000 401A_3FFF -> Packed, complete
    LPUART7 ->          4019_C000 4019_FFFF -> Packed, complete
    LPUART6 ->          4019_8000 4019_BFFF -> Packed, complete
    LPUART5 ->          4019_4000 4019_7FFF -> Packed, complete
    LPUART4 ->          4019_0000 4019_3FFF -> Packed, complete
    LPUART3 ->          4018_C000 4018_FFFF -> Packed, complete
    LPUART2 ->          4018_8000 4018_BFFF -> Packed, complete
    LPUART1 ->          4018_4000 4018_7FFF -> Packed, complete
    AIPS-2 Config ->    4017_C000 4017_FFFF -> spread, complete

AIPS-3 -> 4020_0000 to 402F_FFF
    DCP ->              402F_C000 402F_FFFF //Missing?
    SEMC ->             402F_0000 402F_3FFF //Missing?
    USB(USB) ->         402E_0000 402E_3FFF -> spread, complete
    ENET ->             402D_8000 402D_BFFF -> spread, complete
    USDHC2 ->           402C_4000 402C_7FFF -> spread, complete
    USDHC1 ->           402C_0000 402C_3FFF -> spread, complete
    CSI ->              402B_C000 402B_FFFF -> spread, compelte
    LCDIF ->            402B_8000 402B_BFFF -> spread, complete
    PXP ->              402B_4000 402B_7FFF -> spread, complete
    FlexSPI ->          402A_8000 402A_BFFF
    AIPS-3 Config ->    4027_C000 4027_FFFF -> spread, complete

AIPS-4 -> 4030_0000 to 403F_FFFF
    LPI2C4 ->           403F_C000 403F_FFFF 
    LPI2C3 ->           403F_8000 403F_BFFF 
    LPI2C2 ->           403F_4000 403F_7FFF 
    LPI2C1 ->           403F_0000 403F_3FFF 
    BEE ->              403E_C000 403E_FFFF 
    FLEXPWM4 ->         403E_8000 403E_BFFF 
    FLEXPWM3 ->         403E_4000 403E_7FFF 
    FLEXPWM2 ->         403E_0000 403E_3FFF 
    FLEXPWM1 ->         403D_C000 403D_FFFF 
    QDC4 ->             403D_4000 403D_7FFF 
    QDC3 ->             403D_0000 403D_3FFF 
    QDC2 ->             403C_C000 403C_FFFF 
    QDC1 ->             403C_8000 403C_BFFF 
    XBAR3 ->            403C_4000 403C_7FFF 
    XBAR2 ->            403C_0000 403C_3FFF 
    XBAR1 ->            403B_C000 403B_FFFF 
    AOI2 ->             403B_8000 403B_BFFF 
    AOI1 ->             403B_4000 403B_7FFF 
    ADC_ETC ->          403B_0000 403B_3FFF 
    LPSPI4 ->           403A_0000 403A_3FFF 
    LPSPI3 ->           4039_C000 4039_FFFF 
    LPSPI2 ->           4039_8000 4039_BFFF 
    LPSPI1 ->           4039_4000 4039_7FFF  
    SAI3 ->             4038_C000 4038_FFFF 
    SAI2 ->             4038_8000 4038_BFFF 
    SAI1 ->             4038_4000 4038_7FFF 
    SPDIF ->            4038_0000 4038_3FFF 
    AIPS-4 Config ->    4037_C000 4037_FFFF -> spread, complete
*/


#define MEMORY_MAP_START 0x40184000
#define MEMORY_MAP_END 0x4018402C 

#define DMAMUX_START 0x400EC000
#define DMAMUX_REG_COUNT 30

#define EDMA_START 0x400E8000

#define WDOG3_START 0x400BC000
#define WDOG3_REG_COUNT 3

#define ADC1_START 0x400C4000
#define ADC1_REG_COUNT 22

#define ADC2_START 0x400C8000
#define ADC2_REG_COUNT 22

#define GPIO5_START 0x400C0000
#define GPIO4_START 0x401C4000
#define GPIO3_START 0x401C0000
#define GPIO2_START 0x401BC000
#define GPIO1_START 0x401B8000

#define FLEXRAM_START 0x400B0000
#define FLEXRAM_REG_COUNT 6

#define IOMUXC_GPR_START 0x400AC0000
#define IOMUXC_GPR_REG_COUNT 25

#define IOMUXC_SNVS_START 0x400A8000
#define IOMUXC_SNVS_REG_COUNT 8

#define IOMUXC_SNVS_GPR_START 0x400A4000
#define IOMUXC_SNVS_GPR_REG_COUNT 3

#define DCDC_START 0x40080000
#define DCDC_REG_COUNT 3

#define IOMUXC_START 0x401F8014
#define IOMUXC_REG_COUNT 397

#define GPT1_START 0x401EC000
#define GPT1_REG_COUNT 9

#define GPT2_START 0x401F0000
#define GPT2_REG_COUNT 9

#define LPUART1_START 0x40184000
#define LPUART1_REG_COUNT 11 //do not count the first register

#define LPUART2_START 0x40188000
#define LPUART2_REG_COUNT 11 

#define LPUART3_START 0x4018C000
#define LPUART3_REG_COUNT 11 

#define LPUART4_START 0x40190000
#define LPUART4_REG_COUNT 11 

#define LPUART5_START 0x40194000
#define LPUART5_REG_COUNT 11 

#define LPUART6_START 0x40198000
#define LPUART6_REG_COUNT 11 

#define LPUART7_START 0x4019C000
#define LPUART7_REG_COUNT 11 

#define LPUART8_START 0x401A0000
#define LPUART8_REG_COUNT 11 

/*
The goal here is to print everything in memory, or certain sections, 
while avoiding all of the reserved sections. 
This means we're going to have to map out every section. 
This isn't toooo bad? I guess We can get really familiar with the data sheet. 
VS Code serial monitor already supports file logging, so that's cool. 


One thing we can do is print register sections. 
So, if we know the number of registers, and there aren't any "reserved" sections,
than we should be able to just give program a start address, and a number of registers, and we're good to go. 

We can then make some functions out of all the memory locations. 
So each chunk described in the datasheet can have it's own function. 


This gives us a bit of range for what we need, so we dont have to print the whole map if we don't want to. 
*/

void printMemorySection(uint32_t address, uint16_t numRegisters);
void printMemorySection16(uint32_t address, uint16_t numRegisters);
void printWholeMemoryMap();
void printCCM();
void printSRC();
void printGPC();
void printEDMA();
void printTSC();
void printAnalog();
void printSNVS();
void printWDOG2();
void printWDOG1();
void printGPIO(uint32_t GPIOStartAddress);
void printEWM();
void printACMP();
void printPIT();
void printAIPSConfig();
void printKPP();
void printOCOTP();
void printQTimer();
void printFlexCan();
void printUSBOTG();
void printEthernet();
void printuSDHC();
void printCSI();
void printLCDIF();
void printPXP();
