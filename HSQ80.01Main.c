/*
 * Copyright 2017-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"


#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_semc.h"
#include "sdRam.h"
#include "fsl_lpuart.h"

#include "system_MIMXRT1052.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define UART3           LPUART3
#define UARTClock       BOARD_DebugConsoleSrcFreq() //this probably needs a little bit more looking into
#define UART3_IRQn      LPUART3_IRQn
#define UART3_Handler   LPUART3_IRQHandler
#define MIDI_BAUD_RATE  31250

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void UART3_Handler()
{
    SDK_ISR_EXIT_BARRIER;
}



volatile uint32_t noteTimeCounter = 0;
volatile uint32_t maxSequenceMS = UINT32_MAX;


void SysTick_Handler(void)
{
    noteTimeCounter++;
    noteTimeCounter= noteTimeCounter%maxSequenceMS;
}

void SysTick_DelayTicks(uint32_t n)
{
    //add the offset in time to our note time counter
    //then exit the while loop when we count up to that offset. 
    uint32_t delayHolder = noteTimeCounter+n;
    while (noteTimeCounter != delayHolder)
    {
    }
}


/*!
 * @brief Main function
 */
int main(void)
{
    lpuart_config_t config;
    //uint16_t tmprxIndex = rxIndex; //these are just part of the demo, I don't think they're necessary.
    //uint16_t tmptxIndex = txIndex;

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    CLOCK_InitSysPfd(kCLOCK_Pfd2, 29);
    /* Set semc clock to 163.86 MHz */
    CLOCK_SetMux(kCLOCK_SemcMux, 1);
    CLOCK_SetDiv(kCLOCK_SemcDiv, 1);

    /*
     * config.baudRate_Bps = 115200U;
     * config.parityMode = kLPUART_ParityDisabled;
     * config.stopBitCount = kLPUART_OneStopBit;
     * config.txFifoWatermark = 0;
     * config.rxFifoWatermark = 0;
     * config.enableTx = false;
     * config.enableRx = false;
     */
    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = MIDI_BAUD_RATE;
    config.enableTx     = true;
    config.enableRx     = true;

    LPUART_Init(UART3, &config, UARTClock);

    if (BOARD_InitSEMC() != kStatus_Success)
    {
        PRINTF("\r\n SEMC SDRAM Init Failed\r\n");
    }

    /* Update the core clock */
    SystemCoreClockUpdate();
    uint8_t testInt = 0xAA;

    /* Set systick reload value to generate 1ms interrupt */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        while (1)
        {
            //There should be some hardware error state here. 
        }
    }

    /* Add user custom codes below */
    while (1)
    {
        SysTick_DelayTicks(1000);
        LPUART_WriteBlocking(UART3, &testInt, sizeof(uint8_t));

    }
}
