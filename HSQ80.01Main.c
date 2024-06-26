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
//#include "peripherals.h"
#include "sdRam.h"

#include "system_MIMXRT1052.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

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

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    CLOCK_InitSysPfd(kCLOCK_Pfd2, 29);
    /* Set semc clock to 163.86 MHz */
    CLOCK_SetMux(kCLOCK_SemcMux, 1);
    CLOCK_SetDiv(kCLOCK_SemcDiv, 1);

    if (BOARD_InitSEMC() != kStatus_Success)
    {
        PRINTF("\r\n SEMC SDRAM Init Failed\r\n");
    }

    /* Update the core clock */
    SystemCoreClockUpdate();

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


    }
}
