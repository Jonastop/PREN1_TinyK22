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
 * $Id: ftm0.h 67 2018-04-03 11:09:31Z zajost $
 *
 *--------------------------------------------------------------------
 */

#ifndef SOURCES_FTM0_H_
#define SOURCES_FTM0_H_

#define FTM0_CLOCK                250000  // 250 kHz
#define FTM0_MODULO               0xFFFF  // 4095


// calulate nr of TOF count for a given number of milliseconds
#define FTM0_TOFS_MS(x)         ((uint16_t)(((FTM0_CLOCK / 1000) * x) / (FTM0_MODULO + 1)))


void ftm0Init(void);



#endif /* SOURCES_FTM0_H_ */
