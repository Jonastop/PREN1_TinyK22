/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Common settings of the FTM0
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          26.03.20018
 *
 * $Id: ftm0.c 91 2018-04-20 07:20:56Z zajost $
 *
 *--------------------------------------------------------------------
 */

#include "platform.h"
#include "ftm0.h"


/**
 * Default handler is called if there is no handler for the FTM0 channel or tof interrupt
 */
void Default_Handler_FTM0()
{
  __asm("bkpt"); // Still a hacker? ;-)
}


void FTM0CH0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0CH7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));
void FTM0TOF_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler_FTM0")));


#define CHF_CHIE_MASK       (FTM_CnSC_CHF_MASK | FTM_CnSC_CHIE_MASK)
#define TOF_TOIE_MASK       (FTM_SC_TOF_MASK | FTM_SC_TOIE_MASK)

/**
 * Interrupt handler to distribute the different interrupt sources of the FTM0:
 * - channel 0..7
 * - timer overflow
 */
void FTM0_IRQHandler(void)
{
  if ((FTM0_C0SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH0_IRQHandler();
  if ((FTM0_C1SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH1_IRQHandler();
  if ((FTM0_C2SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH2_IRQHandler();
  if ((FTM0_C3SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH3_IRQHandler();
  if ((FTM0_C4SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH4_IRQHandler();
  if ((FTM0_C5SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH5_IRQHandler();
  if ((FTM0_C6SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH6_IRQHandler();
  if ((FTM0_C7SC & CHF_CHIE_MASK) == CHF_CHIE_MASK) FTM0CH7_IRQHandler();
  if ((FTM0_SC & TOF_TOIE_MASK) == TOF_TOIE_MASK) FTM0TOF_IRQHandler();
}

void ftm0Init(void)
{
  // _todo #7.3-01 set clockgating for FTM0
  SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;

  // sets the modulo
  FTM0_MOD = FTM0_MODULO;

  // _todo #7.3-02 configure the timer with "Fixed frequency clock" as clocksource and with a "Prescaler" of 1 => 250 kHz
  FTM0_SC = FTM_SC_CLKS(2) |  FTM_SC_PS(0);

  // _todo #7.3-03 Enable FTM0 interrupt on NVIC with Prio: PRIO_FTM0 (defined in platform.h)
  NVIC_SetPriority(FTM0_IRQn, PRIO_FTM0);       // set interrupt priority
  NVIC_EnableIRQ(FTM0_IRQn);                    // enable interrupt
}
