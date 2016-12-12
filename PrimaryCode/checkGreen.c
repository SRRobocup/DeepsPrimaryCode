#include "source.h"
#include "initialize sensors.c"
#include "clearScreen.c"
#include "Ev3 NXT Compatibility custom functions.c"
#include "Common Functions.c"
#include "PID.c"
float checkGreen(float LRatio1, float LRatio2, float RRatio1, float RRatio2)

{
	float leftAverage = getLeftAverageThresh();
	float rightAverage = getRightAverageThresh();

	float redRatio = 0;
	float blueRatio = 0;
	float red = 0;
	float green = 0;
	float blue = 0;
	int blank = 0;


	//Check Right//

	GetRGB(2 ,&red, &green, &blue);

	redRatio = red/green;
	blueRatio = blue/green;

	if (red > 70 && blue > 70 && green > 70 && red < 310 && blue < 310 && green < 310)
	{
		if(redRatio < (RRatio1+ 0.1) && blueRatio  < (RRatio2+ 0.1) )
		{


		//	DisplayText(1,"(R)See Green!       ", 1, blank);

			///HIGHLY EXPERIMENTAL:
			PlaySound(soundBeepBeep);
			cmForward(-1, 40);
			GetRGB(2 ,&red, &green, &blue);
			if (green < RightAverage)
			{
				cmForward(3, 40);
				return 1;
			}
			cmForward(-1, 40);
			GetRGB(2 ,&red, &green, &blue);
			if (green < RightAverage)
			{
				cmForward(4, 40);
				return 1;
			}
			cmForward(2, 40);
			//End of HIGHLY EXPERIMENTAL//

			PlaySound(soundBeepBeep);
			motor[RM] = 0;
			motor[LM] = 0;
			wait10Msec(100);
			cmForward(4, 40);
			motor[RM] = 0;
			motor[LM] = 0;
			degTurn(-37, 40);
			GetRGB(1 ,&red, &green, &blue);
			while (green > leftAverage)
			{
				GetRGB(1 ,&red, &green, &blue);
				motor[RM] = -10;
				motor[LM] = 10;

			}
			motor[RM] = 0;
			motor[LM] = 0;
			wait10Msec(100);
			return 1;
		}
	}

	//Check Left//
	GetRGB(1 ,&red, &green, &blue);
	redRatio = red/green;
	blueRatio = blue/green;

if (red > 60 && blue > 60 && green > 60 && red < 310 && blue < 310 && green < 310)
	{
		if(redRatio < (LRatio1 + 0.1) && blueRatio  < (LRatio2+ 0.1) )
		{


		//	DisplayText(1,"(L)See Green!       ", 1, blank);

					///HIGHLY EXPERIMENTAL:
			PlaySound(soundBeepBeep);
			cmForward(-1, 40);
			GetRGB(1 ,&red, &green, &blue);
			if (green < LeftAverage)
			{
				cmForward(3, 40);
				return 1;
			}
			cmForward(-1, 40);
			GetRGB(1 ,&red, &green, &blue);
			if (green < LeftAverage)
			{
				cmForward(4, 40);
				return 1;
			}
			cmForward(2, 40);
			//End of HIGHLY EXPERIMENTAL//

			PlaySound(soundBeepBeep);
			motor[RM] = 0;
			motor[LM] = 0;
			wait10Msec(100);
			cmForward(4, 40);
			motor[RM] = 0;
			motor[LM] = 0;
			degTurn(37, 40);
			GetRGB(2 ,&red, &green, &blue);
			while (green > rightAverage)
			{
				GetRGB(2 ,&red, &green, &blue);
				motor[RM] = 10;
				motor[LM] = -10;

			}
			motor[RM] = 0;
			motor[LM] = 0;
			wait10Msec(100);
			return 1;
		}
}
	return 0;
}
