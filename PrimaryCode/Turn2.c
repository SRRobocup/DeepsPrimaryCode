#define Jagdeep
#include "source.h"
#include "Common Functions.c"

task main()
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
	//wait10Msec(100);
	//encodersBM = 25;
	//	nMotorEncoder[BM] = 0;
	//	while(nMotorEncoder[BM] < encodersBM)
	//{
	//	motor[BM] = 50;
	//}
	//	motor[BM] = 0;
	//	wait10Msec(100);
	//	degTurn(-15, 100);
	//	cmForward(1,40);
	//	wait10Msec(100);
	//		nMotorEncoder[BM] = 0;
	//	encodersBM = 18;
	//	while(nMotorEncoder[BM] < encodersBM)
	//{
	//	motor[BM] = 50;
	//}
	//motor[BM] = 0;
	//wait10Msec(100);
	//degTurn(-10,100);
	//cmForward(1,40);
	//wait10Msec(100);
	//encodersBM = 10;
	//	nMotorEncoder[BM] = 0;
	//	while(nMotorEncoder[BM] < encodersBM)
	//{
	//	motor[BM] = 50;
	//}
	//	motor[BM] = 0;
	//	wait10Msec(100);
	//	degTurn(-25, 100);
	//	cmForward(1,40);
	//	wait10Msec(100);
	//		nMotorEncoder[BM] = 0;
	//	encodersBM = 10;
	//	while(nMotorEncoder[BM] < encodersBM)
	//{
	//	motor[BM] = 50;
	//}
	//motor[BM] = 0;
	//wait10Msec(100);
	//degTurn(-20,100);
	//cmForward(1,40);
	//wait10Msec(100);
	//encodersBM = 10;
	//	nMotorEncoder[BM] = 0;
	//	while(nMotorEncoder[BM] < encodersBM)
	//{
	//	motor[BM] = 50;
	//}
	//	motor[BM] = 0;
	//	wait10Msec(100);
	//	degTurn(-25, 100);
	//	cmForward(1,40);
	//	wait10Msec(100);

	//	encodersBM = 10;
	//	nMotorEncoder[BM] = 0;
	//	while(nMotorEncoder[BM] < encodersBM)
	//{
	//	motor[BM] = 100;
	//}
	//	motor[BM] = 0;
	//	wait10Msec(100);
	//	degTurn(30, 100);
	//	cmForward(-30, 40);
}
