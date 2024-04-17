#include "structures/midiEvent.h"
#include "fsl_semc.h"

#define SDRAM_ADDRESS_START 0x80000000

status_t BOARD_InitSEMC();
void writeEvent(midiEvent_t inMidiEvent);
void deleteEvent(midiEvent_t inMidiEvent);