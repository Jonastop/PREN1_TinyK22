/*
 * pwm_motor.c
 *
 *  Created on: 15.11.2019
 *      Author: jonas


#include "platform.h"

// configuration from GPIO to FTM-Mode and vice versa
#define MOTOR_RIGHT_PWM()           (PORTC_PCR8 = PORT_PCR_MUX(3))  // PTC8: FTM3_CH4
#define MOTOR_RIGHT_GPIO()          (PORTC_PCR8 = PORT_PCR_MUX(1))  // PTC8: GPIO

#define MOTOR_LEFT_A_PWM()          (PORTC_PCR9 = PORT_PCR_MUX(3))  // PTC9: FTM3_CH5
#define MOTOR_LEFT_A_GPIO()         (PORTC_PCR9 = PORT_PCR_MUX(1))  // PTC9: GPIO

static int8_t valueRight;
static int8_t valueLeft;


void motorIncrementPwmRight(int8_t value){

};

void motorIncrementPwmLeft(int8_t value){

};

void motorSetPwmRight(int8_t value){

};

void motorSetPwmLeft(int8_t value){

};

void motorInit(void){
  // Configure the pin direction of the 4 pins as output.
   GPIOC_PDDR |= 1<<8;
   GPIOC_PDDR |= 1<<9;

   // Set pin value of the pins to '1'
   GPIOC_PDOR |= 1<<8 | 1<<9;

   // configures the pin muxing of both pins as GPIO-Pin.
   // the output level will be '1' because of the configuration above.
   (PORTC_PCR8 = PORT_PCR_MUX(1));
   (PORTC_PCR9 = PORT_PCR_MUX(1));

   // configure both channels as edge aligned PWM with high-true pulses
   FTM3_C0SC |= FTM_CnSC_ELSA(0) | FTM_CnSC_ELSB(1) | FTM_CnSC_MSB(1);
   FTM3_C1SC |= FTM_CnSC_ELSA(0) | FTM_CnSC_ELSB(1) | FTM_CnSC_MSB(1);
};
 */
