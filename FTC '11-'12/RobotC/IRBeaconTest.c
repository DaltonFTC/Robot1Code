#pragma config(Sensor, S1,     ,                    sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorB,          rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Function uses data from the IR Rangerinder to calculate and return distance
int IRValue(tSensors sensorPort, float conversionFactor = .0000469616, float k = .42)
{
return (1.0 / (SensorValue[sensorPort] * conversionFactor)) - k;
}

task main()
{
wait1Msec(2000);

clearLCDLine(1);

//While true...
while(true)
{
//If the robot is greater than 25 cm away...
if(IRValue(sharp) > 25)
{
//Move Forward
motor[rightMotor] = 30;
motor[leftMotor] = 30;
}
else
{
//Stop
motor[rightMotor] = 0;
motor[leftMotor] = 0;
}

//Display IR Sensor Data to LCD
displayLCDString(0, 0, "IR Value:");
displayLCDNumber(0, 9, IRValue(sharp), 3);
displayNextLCDString("cm");
}
}
