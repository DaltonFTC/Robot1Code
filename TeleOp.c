#pragma config(Hubs,  S4, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S4,     ,                    sensorI2CMuxController)
#pragma config(Motor,  motorA,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  motorB,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  motorC,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S4_C2_1,     motorF,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     motorG,        tmotorNormal, openLoop)
#pragma config(SrvoPosition,  Position03,             17, 248, 128, 128, 128, 128, 128, 128)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//													 Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"	 //Include file to "handle" the Bluetooth messages.

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																		initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

//	Ex: servo[servo2] =25;
servo[servo1] =16;
servo[servo2] =249;
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																				 Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//	 1. Loop forever repeating the following actions:
//	 2. Get the latest game controller / joystick settings that have been received from the PC.
//	 3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//			simple action:
//			*	 Joystick values are usually directly translated into power levels for a motor or
//				 position of a servo.
//			*	 Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//				 position.
//	 4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

// Ex: void drop(){blah}

int scaleForMotor(int joyValue)
{
  const int threshold = 5;
  const int MAX_MOTOR_VAL = 75;
  const float MAX_JOY_VAL = 127;

  if (abs(joyValue)<threshold)
  {
    return 0;
  }
  int direction = joyValue/abs(joyValue);
  float ratio = ((joyValue*joyValue) / (MAX_JOY_VAL*MAX_JOY_VAL));
  int scaledVal = (ratio*MAX_MOTOR_VAL)*direction;

  return scaledVal;
}

task main()
{
	initializeRobot();
	waitForStart();		// wait for start of tele-op phase
	float scale = 1.1; //scale the motors down
	while (true)
	{
		///////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////
		////																									 ////
		////			Add your robot specific tele-op code here.	 ////
		////																									 ////
		///////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////

		// Insert code to have servos and motors respond to joystick and button values.

		// Look in the ROBOTC samples folder for programs that may be similar to what you want to perform.
		// You may be able to find "snippets" of code that are similar to the functions that you want to
		// perform.

		getJoystickSettings(joystick);

		motor[motorE] = scaleForMotor(joystick.joy1_y2)*scale; //rgt
		motor[motorD] = scaleForMotor(joystick.joy1_y2)*scale; //rgt
    motor[motorF] = scaleForMotor(joystick.joy1_y1)*scale*-1; //lft
		motor[motorG] = scaleForMotor(joystick.joy1_y1)*scale*-1; //lft

		if(joy1Btn(9))//slow mode

		{
			scale = .4;
		}
		if(joy1Btn(10)) //normal mode
		{
			scale = 1.1;
		}

		/* Ex: moving arms up
		if(joy1Btn(6)&& ServoValue[servo1]<260 &&ServoValue[servo4]>117)
		{
				servo[servo1] = ServoValue[servo1]+4;
				servo[servo4] = ServoValue[servo4]-4;
		}*/
		if(joy1Btn(8))
		{
				servo[servo1] = ServoValue[servo1]+4;
				servo[servo2] = ServoValue[servo2]-4;
		}
		if(joy1Btn(6))
		{
				servo[servo1] = ServoValue[servo1]-4;
				servo[servo2] = ServoValue[servo2]+4;
		}


  }
}
