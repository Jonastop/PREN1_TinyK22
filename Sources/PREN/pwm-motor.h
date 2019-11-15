/*
 * pwm-motor.h
 *
 *  Created on: 15.11.2019
 *      Author: jonas
 */

#ifndef SOURCES_PREN_PWM_MOTOR_H_
#define SOURCES_PREN_PWM_MOTOR_H_

void motorIncrementPwmRight(int8_t value);
void motorIncrementPwmLeft(int8_t value);

void motorSetPwmRight(int8_t value);
void motorSetPwmLeft(int8_t value);

void motorInit(void);


#endif /* SOURCES_PREN_PWM_MOTOR_H_ */
