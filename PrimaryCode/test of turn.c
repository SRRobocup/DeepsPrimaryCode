
#include "Common Functions.c"

void theTurn()
{

int encodersBM = 0;
	cmForward(-3, 40);
	degTurn(-20, 40);
	cmForward(-3, 40);
	degTurn(-20, 40);
	cmForward(-3, 40);
	encodersBM = 25;
	nMotorEncoder[BM] = 0;
	while(nMotorEncoder[BM] < encodersBM)
	{
		motor[BM] = 50;
	}
	motor[BM] = 0;
	wait10Msec(100);
	degTurn(-20, 40);
		encodersBM = 50;
	nMotorEncoder[BM] = 0;
	while(nMotorEncoder[BM] < encodersBM)
	{
		motor[BM] = 100;
	}
	motor[BM] = 0;
	wait10Msec(100);
	degTurn(-40, 40);
	encodersBM = 30;
	nMotorEncoder[BM] = 0;
	while(nMotorEncoder[BM] < encodersBM)
	{
		motor[BM] = 100;
	}
	motor[BM] = 0;
	wait10Msec(100);
		degTurn(-40, 40);
}
