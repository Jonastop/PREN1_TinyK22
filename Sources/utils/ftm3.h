/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Common settings of the FTM3
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          03.04.20018
 *
 * $Id: ftm3.h 85 2018-04-16 16:01:53Z zajost $
 *
 *--------------------------------------------------------------------
 */

#ifndef SOURCES_FTM3_H_
#define SOURCES_FTM3_H_

#define FTM3_CLOCK              60000000  // 60 MHz
#define FTM3_MODULO               0x0FFF  // 4095


// calulate nr of TOF count for a given number of milliseconds
#define FTM3_TOFS_MS(x)         ((uint16_t)(((FTM3_CLOCK / 1000) * x) / (FTM3_MODULO + 1)))

void ftm3Init(void);



#endif /* SOURCES_FTM3_H_ */
