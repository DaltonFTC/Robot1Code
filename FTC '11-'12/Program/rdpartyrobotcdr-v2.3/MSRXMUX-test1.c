#pragma config(Sensor, S1,     MSRXMUX,             sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: MSRXMUX-test1.c 71 2011-10-16 07:06:33Z xander $
 */

/**
 * MSAC-driver.h provides an API for the Mindsensors Sensor MUX Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 2.00 AND HIGHER.
 * Xander Soldaat (mightor_at_gmail.com)
 * 28 November 2009
 * version 0.2
 */

#include "drivers/MSRXMUX-driver.h"

task main () {

  int chan1 = 0;
  int chan2 = 0;
  int chan3 = 0;
  int chan4 = 0;

  nxtDisplayCenteredTextLine(0, "Mindsensors");
  nxtDisplayCenteredBigTextLine(1, "RXMUX");
  nxtDisplayCenteredTextLine(3, "Test 1");

  wait1Msec(2000);

  // Set up channel 1 on the RCX sensor MUX to a light sensor in percentage mode
  MSRXMUXsetupChan(MSRXMUX, 1, sensorReflection, modePercentage, 5);

  // Set up channel 2 on the RCX sensor MUX to a touch sensor in raw mode
  MSRXMUXsetupChan(MSRXMUX, 2, sensorTouch, modeRaw, 5);

  // Set up channel 4 on the RCX sensor MUX to rotation sensor in rotation mode
  MSRXMUXsetupChan(MSRXMUX, 4, sensorRotation, modeRotation, 5);

  while(true) {
    // Read from the channels and display
    chan1 = MSRXMUXreadChan(MSRXMUX, 1);
    chan2 = MSRXMUXreadChan(MSRXMUX, 2);
    chan4 = MSRXMUXreadChan(MSRXMUX, 4);
    nxtDisplayBigTextLine(1, "%d", chan1);
    nxtDisplayBigTextLine(3, "%d", chan2);
    nxtDisplayBigTextLine(5, "%d", chan4);
  }

  PlaySound(soundBeepBeep);
  while(bSoundActive) EndTimeSlice();
  eraseDisplay();
  while(1) EndTimeSlice();

}

/*
 * $Id: MSRXMUX-test1.c 71 2011-10-16 07:06:33Z xander $
 */
