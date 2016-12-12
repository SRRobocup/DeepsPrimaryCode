#include "source.h"
#include "Common Functions.c"
#include "Ev3 NXT Compatibility custom functions.c"
void doSilver()
{
	int leftTurn = 0;
	int rightTurn = 0;
	int center = 0;
	cmForward(1,40);

	//Left
	nMotorEncoder[LM] = 0;
	while (SensorValue[lightForward] > 70)
	{
		motor[LM] = -10;
		motor[RM] = 10;
	}
  motor[LM] = 0;
  motor[RM] = 0;
	PlaySound(soundBeepBeep);
	wait10Msec(100);

	leftTurn = nMotorEncoder[LM];
	while (nMotorEncoder[LM] < 0)
	{
		motor[LM] = 10;
		motor[RM] = -10;
	}
	motor[LM] = 0;
  motor[RM] = 0;
	PlaySound(soundBeepBeep);
  wait10Msec(100);
	//Right
	nMotorEncoder[RM] = 0;
	while (SensorValue[lightForward] > 70)
	{
		motor[LM] = 10;
		motor[RM] = -10;
	}
  motor[LM] = 0;
  motor[RM] = 0;
	PlaySound(soundBeepBeep);
	wait10Msec(100);
	rightTurn = nMotorEncoder[RM];
	while (nMotorEncoder[RM] < 0)
	{
		motor[LM] = -10;
		motor[RM] = 10;
	}
	motor[LM] = 0;
  motor[RM] = 0;
	PlaySound(soundBeepBeep);
	wait10Msec(100);

	//Align
	center = (leftTurn - rightTurn)/2;
	nMotorEncoder[RM] = 0;
	if (center > 0)
	{
		while(nMotorEncoder[RM] > -center)
		{
			motor[LM] = 10;
			motor[RM] = -10;
		}
	}

	else
	{
		while(nMotorEncoder[RM] < center)
		{
		motor[LM] = -10;
		motor[RM] = 10;
		}
	}
	motor[LM] = 0;
  motor[RM] = 0;

	PlaySound(soundBeepBeep);
	wait10Msec(100);
}
