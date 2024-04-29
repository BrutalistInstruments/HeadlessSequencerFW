#include "structures/midiEvent.h"
#include "fsl_semc.h"
#include <stdint.h>

#define SDRAM_ADDRESS_START 0x80000000
#define SDRAM_SIZE 32 * 1024 /* 32MB = 32*1024*1KBytes*/
#define SDRAM_ADDRESS_END SDRAM_ADDRESS_START + (SDRAM_SIZE*1024)
#define SEMC_CLK_FREQ CLOCK_GetFreq(kCLOCK_SemcClk)

status_t BOARD_InitSEMC();
void writeEvent(midiEvent_t inMidiEvent);
void deleteEvent(midiEvent_t inMidiEvent);
bool isNullMidiEvent(midiEvent_t inMidiEvent);
