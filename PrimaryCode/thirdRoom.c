#include "Ev3 NXT Compatibility custom functions.c"
#include "Common Functions.c"
#include "PID.c"
#include "test of turn.c"
#include "wallAdjust.c"
#include "silver.c"

void thirdRoom()
{
	float leftAverage = getLeftAverageThresh();
	float rightAverage = getRightAverageThresh();
	float lightAverage = getLightAverageThresh();
	int encodersBM = -75;
	float red = 0;
	float green1 = 0;
	float green2 = 0;
	float blue = 0;
	float green = 0;
	float greenRight = 0;
	float greenLeft = 0;
	float lightValue = 0;
	float intersection = 0;
	float forward = 20;
	float kp = 0.4;
	float err = 0;
	int distValue = 100;
	int goodTurn = 76;
	float DISTVALUETHRESH=14.0;

	motor[LM] = 0;
	motor[RM] = 0;
	PlaySound(soundBeepBeep);
	wait10Msec(10);



		//////////////////
	///ALIGN CODE/////
	//////////////////

	//cmForward(-4, 20);


	//for (int i = 0; i<1000; i++)
	//{
	//				GetRGB(1 ,&red, &green, &blue);
	//	//nxtDisplayTextLine(3,"LG = %d,%d", (int)green, (int)leftAverage);
	//	greenLeft= green;

	//	GetRGB(2 ,&red, &green, &blue);
	//	// nxtDisplayTextLine(4,"RG = %d,%d", (int)green,(int)rightAverage);
	//	greenRight= green;

	//	lightValue = SensorValue[lightForward];

	//	int intersection = 0;
	//	intersection = returnIntersectionPID(greenLeft, greenRight, lightValue);

	//	resetPIDValues();
	//	getPIDParameters(greenLeft, greenRight, lightValue, intersection, &err, &kp, &forward);
	//	runIterationPID(err, kp,forward, 0, 0);

	//}

	//cmForward(-9, 20);

	//lightValue = SensorValue[lightForward];

	//while (lightValue<70)
	//{
	//				GetRGB(1 ,&red, &green, &blue);
	//	//nxtDisplayTextLine(3,"LG = %d,%d", (int)green, (int)leftAverage);
	//	greenLeft= green;

	//	GetRGB(2 ,&red, &green, &blue);
	//	// nxtDisplayTextLine(4,"RG = %d,%d", (int)green,(int)rightAverage);
	//	greenRight= green;

	//	lightValue = SensorValue[lightForward];

	//	int intersection = 0;
	//	intersection = returnIntersectionPID(greenLeft, greenRight, lightValue);

	//	resetPIDValues();
	//	getPIDParameters(greenLeft, greenRight, lightValue, intersection, &err, &kp, &forward);
	//	runIterationPID(err, kp,forward, 0, 0);


	//}

doSilver();
	////////////the rest of the stuff.

	cmForward(25, 40);
	wait10Msec(10);
		nMotorEncoder[BM] = 0;
	while(nMotorEncoder[BM] > encodersBM)
	{
		motor[BM] = -100;
	}
	motor[BM] = 0;


	distValue = SensorValue[distForward];
		while (distValue > DISTVALUETHRESH)
		{
			distValue = SensorValue[distForward];
			nxtDisplayTextLine(2,"%d", distValue);
			motor[LM] = 30;
			motor[RM] = 30;
		}
	wallAdjust();
	degTurn(goodTurn, 30);

	while (1)
	{
	distValue = SensorValue[distForward];
		while (distValue > DISTVALUETHRESH)
		{
			distValue = SensorValue[distForward];
			nxtDisplayTextLine(2,"%d", distValue);
			motor[LM] = 30;
			motor[RM] = 30;
		}
			wallAdjust();
			PlaySound(soundBeepBeep);
			motor[LM] = 0;
			motor[RM] = 0;
			wait10Msec(100);


		if (SensorValue[lightForward] < lightAverage)
			break;
		else
			degTurn(goodTurn, 30);
	}

		motor[LM] = 0;
		motor[RM] = 0;
		theTurn();
}
