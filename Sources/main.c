/*
 ============================================================================
 Name        : PREN_Team31_TinyK22_v1
 File        : main.c
 Author      : PREN Team31
 Version     : V1
 Date        : 08.11.2019
 Description : Source for TinyK22
 ============================================================================
 */

#include "platform.h"
#include "ftm0.h"
#include "ftm3.h"
#include "quad.h"
#include "drive.h"
#include "pwrSwitch.h"
#include "led.h"
#include <motor_h>







/**
 * Main function of the TinyK22 micro controller.
 */

void main(void)
{
EnableDebugLeds();
  LED_Blue_ON();


  // Never leave main
  for (;;){ }
}
