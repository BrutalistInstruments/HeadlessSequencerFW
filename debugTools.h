#include "fsl_debug_console.h"

#define MEMORY_MAP_START 0x40184000
#define MEMORY_MAP_END 0x4018402C 

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