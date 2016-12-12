#include "source.h"
#include "initialize sensors.c"

float cmForward (float cm)
{
	float encoders = 0;
	float radius = diameter/2;
	encoders = cm/((radius * radius * PI)/360);
	nMotorEncoder[RM] = 0;
	if (encoders > 0)
	{
		while (nMotorEncoder[RM] < encoders)
		{
			motor[RM] = 40;
			motor[LM] = 40;
			nxtDisplayTextLine(5,"%f",nMotorEncoder[RM]);

		}
	}
	else
	{
		while (nMotorEncoder[RM] > encoders)
		{
			motor[RM] = -40;
			motor[LM] = -40;
			nxtDisplayTextLine(5,"%f",nMotorEncoder[RM]);

		}
	}
	motor[RM] = 0;
	motor[LM] = 0;
	return 0;

}
