#pragma config(Hubs,  S4, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S4,     ,                    sensorI2CMuxController)
#pragma config(Motor,  mtr_S4_C1_1,     motorD,        tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C1_2,     motorE,        tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C2_1,     motorF,        tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C2_2,     motorG,        tmotorNormal, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
  bMotorReflected[motorE] = true;
  bMotorReflected[motorD] = true;
  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void zeroEncoders()
{
 nMotorEncoder[motorE] = 0;
 //nMotorEncoder[motorB] = 0;
 nMotorEncoder[motorG] = 0;
 //nMotorEncoder[motorD] = 0;
}

void move( int steps)
{
  zeroEncoders();

  nSyncedMotors = synchEG;
  nSyncedTurnRatio = +100;
  nMotorEncoderTarget[motorE] = steps;

  nSyncedMotors = synchDF;
  nSyncedTurnRatio = +100;
  nMotorEncoderTarget[motorD] = steps;
  while(nMotorEncoder[motorD] < steps)
  {}


}
/*
void turn( int steps)
{
  zeroEncoders();
  //nSyncedMotors = synchAB;
  nSyncedTurnRatio = -100;
  nMotorEncoderTarget[motorA] = steps;

  //nSyncedMotors = synchCD;
  nSyncedTurnRatio = -100;
  nMotorEncoderTarget[motorC] = steps;
  while(nMotorEncoder[motorC] < steps)
  {}

}
*/

task main()
{
  initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.
  //move(5000);

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////

  while (true)
  {}
}
