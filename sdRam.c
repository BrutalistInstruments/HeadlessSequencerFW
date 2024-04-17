#include "sdRam.h"
static midiEvent_t *sdRam = (midiEvent_t*)SDRAM_ADDRESS_START;
static uint32_t sdRamIndex = 0;


status_t BOARD_InitSEMC()
{
    semc_config_t config;
    semc_sdram_config_t sdramconfig;
    uint32_t clockFrq = EXAMPLE_SEMC_CLK_FREQ;

    /* Initializes the MAC configure structure to zero. */
    memset(&config, 0, sizeof(semc_config_t));
    memset(&sdramconfig, 0, sizeof(semc_sdram_config_t));

    /* Initialize SEMC. */
    SEMC_GetDefaultConfig(&config);
    config.dqsMode = kSEMC_Loopbackdqspad; /* For more accurate timing. */
    SEMC_Init(SEMC, &config);

    /* Configure SDRAM. */
    sdramconfig.csxPinMux           = kSEMC_MUXCSX0;
    sdramconfig.address             = SDRAM_ADDRESS_START;
    sdramconfig.memsize_kbytes      = SDRAM_SIZE;
    sdramconfig.portSize            = kSEMC_PortSize16Bit;
    sdramconfig.burstLen            = kSEMC_Sdram_BurstLen1;
    sdramconfig.columnAddrBitNum    = kSEMC_SdramColunm_9bit;
    sdramconfig.casLatency          = kSEMC_LatencyThree;
    sdramconfig.tPrecharge2Act_Ns   = 18; /* Trp 18ns */
    sdramconfig.tAct2ReadWrite_Ns   = 18; /* Trcd 18ns */
    sdramconfig.tRefreshRecovery_Ns = 67; /* Use the maximum of the (Trfc , Txsr). */
    sdramconfig.tWriteRecovery_Ns   = 12; /* 12ns */
    sdramconfig.tCkeOff_Ns =
        42; /* The minimum cycle of SDRAM CLK off state. CKE is off in self refresh at a minimum period tRAS.*/
    sdramconfig.tAct2Prechage_Ns       = 42; /* Tras 42ns */
    sdramconfig.tSelfRefRecovery_Ns    = 67;
    sdramconfig.tRefresh2Refresh_Ns    = 60;
    sdramconfig.tAct2Act_Ns            = 60;
    sdramconfig.tPrescalePeriod_Ns     = 160 * (1000000000 / clockFrq);
    sdramconfig.refreshPeriod_nsPerRow = 64 * 1000000 / 8192; /* 64ms/8192 */
    sdramconfig.refreshUrgThreshold    = sdramconfig.refreshPeriod_nsPerRow;
    sdramconfig.refreshBurstLen        = 1;
    return SEMC_ConfigureSDRAM(SEMC, kSEMC_SDRAM_CS0, &sdramconfig, clockFrq);
}


void writeEvent(midiEvent_t inMidiEvent)
{
    if(sdRamIndex*(sizeof(midiEvent_t))+SDRAM_ADDRESS_START >= SDRAM_ADDRESS_END)
    {
        return;
        //TODO:
        //we should probably return an error here when we know what our error system will look like. 
    }
    while(sdRam[sdRamIndex] != NULL)
    {
        sdRamIndex++;
    }
    sdRam[sdRamIndex] = inMidiEvent;
    sdRamIndex++;
}

void deleteEvent(midiEvent_t inMidiEvent)
{
    midiEvent_t* eventBefore = inMidiEvent.prevEvent;
    midiEvent_t* eventAfter = inMidiEvent.nextEvent;
    midiEvent_t* eventToDelete = eventBefore->nextEvent;

    eventBefore->nextEvent = *eventAfter;
    eventAfter->prevEvent = *eventBefore;

    uint32_t deleteAddress = eventToDelete;
    uint32_t ramDeleteIndex = (eventToDelete-SDRAM_ADDRESS_START) >> 4;
    sdRam[ramDeleteIndex] = NULL;
    sdRamIndex = ramDeleteIndex;
}

bool checkOutOfBounds()
{

}