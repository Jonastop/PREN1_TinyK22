/*
 * pwm_motor.c
 *
 *  Created on: 15.11.2019
 *      Author: jonas
 */

#include "platform.h"
#include "pwm-motor.h"
#include "ftm3.h"

// configuration from GPIO to FTM-Mode and vice versa
#define MOTOR_RIGHT_PWM()           (PORTC_PCR8 = PORT_PCR_MUX(3))  // PTC8: FTM3_CH4
#define MOTOR_RIGHT_GPIO()          (PORTC_PCR8 = PORT_PCR_MUX(1))  // PTC8: GPIO

#define MOTOR_LEFT_A_PWM()          (PORTC_PCR9 = PORT_PCR_MUX(3))  // PTC9: FTM3_CH5
#define MOTOR_LEFT_A_GPIO()         (PORTC_PCR9 = PORT_PCR_MUX(1))  // PTC9: GPIO

static int8_t valueRight;
static int8_t valueLeft;


void motorIncrementPwmRight(int8_t value){
  int32_t v = valueRight + value;
  if (v > MOTOR_MAX_VALUE) v = MOTOR_MAX_VALUE;
  if (v < -MOTOR_MAX_VALUE) v = -MOTOR_MAX_VALUE;
  motorSetPwmRight((int8_t)v);
};

void motorIncrementPwmLeft(int8_t value){
  int32_t v = valueLeft + value;
    if (v > MOTOR_MAX_VALUE) v = MOTOR_MAX_VALUE;
    if (v < -MOTOR_MAX_VALUE) v = -MOTOR_MAX_VALUE;
    motorSetPwmLeft((int8_t)v);
};

void motorSetPwmRight(int8_t value){
  if (value > MOTOR_MAX_VALUE) value = MOTOR_MAX_VALUE;
  if (value < -MOTOR_MAX_VALUE) value = -MOTOR_MAX_VALUE;
  valueRight = value;

  if (value < 0)
  {
    // drive backward
    value = -value;             // value has to be a positive channel value!
    MOTOR_RIGHT_A_GPIO();       // set motor right A as GPIO Pin (high-level)
    MOTOR_RIGHT_B_PWM();        // set motor right B as timer Pin (pwm signal)
  }
  else if (value > 0)
  {
    // drive forward
    MOTOR_RIGHT_B_GPIO();       // set motor right B as GPIO Pin (high-level)
    MOTOR_RIGHT_A_PWM();        // set motor right A as timer Pin (pwm signal)
  }
  else
  {
    // stop
    value=0;

  }
  int16_t v = (uint16_t)(((FTM3_MODULO + 1) * ((uint32_t)value)) / MOTOR_MAX_VALUE);
  FTM3_C0V = v;
};

void motorSetPwmLeft(int8_t value){
  if (value > MOTOR_MAX_VALUE) value = MOTOR_MAX_VALUE;
    if (value < -MOTOR_MAX_VALUE) value = -MOTOR_MAX_VALUE;
    valueLeft = value;

    if (value < 0)
    {
      // drive backward
      value = -value;             // value has to be a positive channel value!
      MOTOR_LEFT_B_GPIO();       // set motor right A as GPIO Pin (high-level)
      MOTOR_LEFT_A_PWM();        // set motor right B as timer Pin (pwm signal)
    }
    else if (value > 0)
    {
      // drive forward
      MOTOR_LEFT_A_GPIO();       // set motor right A as GPIO Pin (high-level)
      MOTOR_LEFT_B_PWM();

    }
    else
    {
      // stop
      value=0;

    }
    int16_t v = (uint16_t)(((FTM3_MODULO + 1) * ((uint32_t)value)) / MOTOR_MAX_VALUE);
    FTM3_C1V = v;



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

