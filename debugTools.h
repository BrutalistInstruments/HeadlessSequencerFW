#include "fsl_debug_console.h"


/*

AIPS-1 ->               4000_0000 to 400F_FFFF
    CCM(CCM) ->         400F_C000 400F_FFFF -> Spread, complete
    SRC(SRC) ->         400F_8000 400F_BFFF -> Spread, complete
    GPC ->              400F_4000 400F_7FFF -> Spread, complete
    DMA_CH_MUX ->       400E_C000 400E_FFFF -> Packed, complete
    EDMA ->             400E_8000 400E_BFFF -> Spread, complete
    SJC ->              400E_4000 400E_7FFF //missing?
    TSC_DIG ->          400E_0000 400E_3FFF 
    CSU ->              400D_C000 400D_FFFF //missing?
    ANALOG ->           400D_8000 400D_BFFF 16KB 
    SNVS_HP ->          400D_4000 400D_7FFF 16KB 
    WDOG2 ->            400D_0000 400D_3FFF 16KB //5 16 bit registers
    TRNG ->             400C_C000 400C_FFFF 16KB //true random number generator. Cool. Also missing
    ADC2 ->             400C_8000 400C_BFFF 16KB 
    ADC1 ->             400C_4000 400C_7FFF 16KB 
    GPIO5 ->            400C_0000 400C_3FFF 16KB 
    WDOG3 ->            400B_C000 400B_FFFF 16KB -> Packed, complete
    WDOG1 ->            400B_8000 400B_BFFF 16KB //5 16 bit registers
    EWM ->              400B_4000 400B_7FFF 16KB 
    CM7_MXRT(FLEXRAM) ->400B_0000 400B_3FFF 16KB 
    IOMUXC_GPR ->       400A_C000 400A_FFFF 16KB 
    IOMUXC_SNVS ->      400A_8000 400A_BFFF 16KB 
    IOMUXC_SNVS_GPR ->  400A_4000 400A_7FFF 16KB  
    ACMP ->             4009_4000 4009_7FFF 16KB 
    PIT ->              4008_4000 4008_7FFF 16KB 
    DCDC ->             4008_0000 4008_3FFF 16KB 
    AIPS-1 Config ->    4007_C000 4007_FFFF 16KB 

AIPS-2                  4010_0000 to 401F_FFFF
    KPP ->              401F_C000 401F_FFFF 16KB 
    IOMUXC ->           401F_8000 401F_BFFF 16KB 
    OCOTP ->            401F_4000 401F_7FFF 16KB 
    GPT2 ->             401F_0000 401F_3FFF 16KB 
    GPT1 ->             401E_C000 401E_FFFF 16KB 
    QTimer4 ->          401E_8000 401E_BFFF 16KB 
    QTimer3 ->          401E_4000 401E_7FFF 16KB 
    QTimer2 ->          401E_0000 401E_3FFF 16KB 
    QTimer1 ->          401D_C000 401D_FFFF 16KB 
    FlexCAN2 ->         401D_4000 401D_7FFF 16KB 
    FlexCAN1 ->         401D_0000 401D_3FFF 16KB 
    GPIO4 ->            401C_4000 401C_7FFF 16KB 
    GPIO3 ->            401C_0000 401C_3FFF 16KB 
    GPIO2 ->            401B_C000 401B_FFFF 16KB 
    GPIO1 ->            401B_8000 401B_BFFF 16KB 
    FlexIO2 ->          401B_0000 401B_3FFF 16KB 
    FlexIO1 ->          401A_C000 401A_FFFF 16KB 
    LPUART8 ->          401A_0000 401A_3FFF 16KB -> Packed, complete
    LPUART7 ->          4019_C000 4019_FFFF 16KB -> Packed, complete
    LPUART6 ->          4019_8000 4019_BFFF 16KB -> Packed, complete
    LPUART5 ->          4019_4000 4019_7FFF 16KB -> Packed, complete
    LPUART4 ->          4019_0000 4019_3FFF 16KB -> Packed, complete
    LPUART3 ->          4018_C000 4018_FFFF 16KB -> Packed, complete
    LPUART2 ->          4018_8000 4018_BFFF 16KB -> Packed, complete
    LPUART1 ->          4018_4000 4018_7FFF 16KB -> Packed, complete
    AIPS-2 Config ->    4017_C000 4017_FFFF 16KB 

AIPS-3 -> 4020_0000 to 402F_FFF
    DCP ->              402F_C000 402F_FFFF 16KB 
    SEMC ->             402F_0000 402F_3FFF 16KB 
    USB(USB) ->         402E_0000 402E_3FFF 16KB 
    ENET ->             402D_8000 402D_BFFF 16KB 
    USDHC2 ->           402C_4000 402C_7FFF 16KB 
    USDHC1 ->           402C_0000 402C_3FFF 16KB 
    CSI ->              402B_C000 402B_FFFF 16KB 
    LCDIF ->            402B_8000 402B_BFFF 16KB 
    PXP ->              402B_4000 402B_7FFF 16KB 
    FlexSPI ->          402A_8000 402A_BFFF 16KB 
    AIPS-3 Config ->    4027_C000 4027_FFFF 16KB 

AIPS-4 -> 4030_0000 to 403F_FFFF
    LPI2C4 ->           403F_C000 403F_FFFF 16KB 
    LPI2C3 ->           403F_8000 403F_BFFF 16KB 
    LPI2C2 ->           403F_4000 403F_7FFF 16KB 
    LPI2C1 ->           403F_0000 403F_3FFF 16KB 
    BEE ->              403E_C000 403E_FFFF 16KB 
    FLEXPWM4 ->         403E_8000 403E_BFFF 16KB 
    FLEXPWM3 ->         403E_4000 403E_7FFF 16KB 
    FLEXPWM2 ->         403E_0000 403E_3FFF 16KB 
    FLEXPWM1 ->         403D_C000 403D_FFFF 16KB 
    QDC4 ->             403D_4000 403D_7FFF 16KB 
    QDC3 ->             403D_0000 403D_3FFF 16KB 
    QDC2 ->             403C_C000 403C_FFFF 16KB 
    QDC1 ->             403C_8000 403C_BFFF 16KB 
    XBAR3 ->            403C_4000 403C_7FFF 16KB 
    XBAR2 ->            403C_0000 403C_3FFF 16KB 
    XBAR1 ->            403B_C000 403B_FFFF 16KB 
    AOI2 ->             403B_8000 403B_BFFF 16KB 
    AOI1 ->             403B_4000 403B_7FFF 16KB 
    ADC_ETC ->          403B_0000 403B_3FFF 16KB 
    LPSPI4 ->           403A_0000 403A_3FFF 16KB 
    LPSPI3 ->           4039_C000 4039_FFFF 16KB 
    LPSPI2 ->           4039_8000 4039_BFFF 16KB 
    LPSPI1 ->           4039_4000 4039_7FFF 16KB  
    SAI3 ->             4038_C000 4038_FFFF 16KB 
    SAI2 ->             4038_8000 4038_BFFF 16KB 
    SAI1 ->             4038_4000 4038_7FFF 16KB 
    SPDIF ->            4038_0000 4038_3FFF 16KB 
    AIPS-4 Config ->    4037_C000 4037_FFFF 16KB 



*/


#define MEMORY_MAP_START 0x40184000
#define MEMORY_MAP_END 0x4018402C 


#define DMAMUX_START 0x400EC000
#define DMAMUX_REG_COUNT 30


#define WDOG3_START 0x400BC000
#define WDOG3_REG_COUNT 3


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
void printWholeMemoryMap();
void printCCM();
void printSRC();
void printGPC();
void printEDMA();