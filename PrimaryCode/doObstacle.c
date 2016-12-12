#include "Ev3 NXT Compatibility custom functions.c"
#include "PID.c"

int doObstacle()

{
	float leftAverage = getLeftLowAverageThresh();
	float rightAverage = getRightLowAverageThresh();
	float err = 0;
	float red = 0;
	float green1 = 0;
	float green2 = 0;
	float blue = 0;
	float objdia = 8;
	float ipwr = 0;
	float opwr = 40;
	float td = 12;

	err = SensorValue[distForward];
	nxtDisplayTextLine(0,"%d", err);
	if (err < td)
	{
		cmForward(-3, 40);
		PwrLvlCalc (&ipwr, objdia, opwr);
		degTurn(-50, 10);
		cmForward(4, 40);
		GetRGB(1 ,&red, &green1, &blue);
		GetRGB(2 ,&red, &green2, &blue);
		while (green1 > leftAverage)
		{
			motor[RM]= opwr * 0.7;
			motor[LM]= ipwr;
			GetRGB(1 ,&red, &green1, &blue);
			GetRGB(2 ,&red, &green2, &blue);

		}
		cmForward(6, 40);
		GetRGB(1 ,&red, &green1, &blue);
		GetRGB(2 ,&red, &green2, &blue);
		while (green1 > leftAverage)
		{
			degTurn(-1, 40);
			GetRGB(1 ,&red, &green1, &blue);
			GetRGB(2 ,&red, &green2, &blue);

		}
		return 1;
	}
	return 0;
}
