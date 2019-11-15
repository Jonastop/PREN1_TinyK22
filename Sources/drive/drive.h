/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         Drive with PID
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          04.04.20018
 *
 * $Id: drive.h 85 2018-04-16 16:01:53Z zajost $
 *
 *--------------------------------------------------------------------
 */

#ifndef SOURCES_DRIVE_DRIVE_H_
#define SOURCES_DRIVE_DRIVE_H_

#define MAX_SPEED             1000                        // [mm/s]
#define ACCELERATION           500                        // [mm/s^2]
#define DECELERATION          2000                        // [mm/s^2]
#define PID_PERIOD              25                        // [ms]


void driveSetParameters(uint8_t pKpL, uint8_t pKpR, uint8_t pKiL, uint8_t pKiR);
void driveSetSpeed(int16_t speedL, int16_t speedR);
void driveToWork(void);
void driveInit(void);


#endif /* SOURCES_DRIVE_DRIVE_H_ */
