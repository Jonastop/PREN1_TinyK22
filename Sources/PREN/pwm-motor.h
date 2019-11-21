/*
 * pwm-motor.h
 *
 *  Created on: 15.11.2019
 *      Author: jonas
 */
#include "platform.h"
#include "stdint.h"

#ifndef SOURCES_PREN_PWM_MOTOR_H_
#define SOURCES_PREN_PWM_MOTOR_H_

#define MOTOR_MAX_VALUE               127

void motorIncrementPwmRight(int8_t value);
void motorIncrementPwmLeft(int8_t value);

void motorSetPwmRight(int8_t value);
void motorSetPwmLeft(int8_t value);

void motorInit(void);


#endif /* SOURCES_PREN_PWM_MOTOR_H_ */
