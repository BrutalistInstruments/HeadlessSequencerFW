#include <stdint.h>


//16 bytes
typedef struct midiEvent_t
{
    uint8_t midiByte1; 
    uint8_t midiByte2; 
    uint8_t midiByte3; 
    uint32_t msTimeStamp; 
    struct midiEvent_t* nextEvent; 
    struct midiEvent_t* prevEvent;
    uint8_t status; //not currently used, but may be useful in the future
}midiEvent_t;