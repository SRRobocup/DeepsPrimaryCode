#include "Trouble000.c"
#include "gapCount.c"
#include "Common Functions.c"
#include "doGap.c"
#include "traceIteration.c"
int wiggle = -1;
int returnIntersection(float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, float LightUp, float LightDown)
{
	float leftAverage = (1.0 * LGreenUp + 1.0 * LGreenDown)/2.0;
	float rightAverage = (1.0* RGreenUp + 1.0 * RGreenDown)/2.0;
	float LightAverage = (4.0 * LightUp + 1.0 * LightDown)/5.0;
	//float leftAverage = LGreenUp - 30;
	//float rightAverage = RGreenUp - 30;
	int intersection = 0;
	float red = 0;
	float green = 0;
	float blue = 0;

nxtDisplayTextLine(0,"%d", LightAverage);
		GetRGB(1 ,&red, &green, &blue);
	  //nxtDisplayTextLine(3,"LG = %d,%d", (int)green, (int)leftAverage);
		if (green < leftAverage)
			intersection = intersection + 1;

		intersection = intersection * 10;

		if(SensorValue[lightForward]< LightAverage)
			intersection = intersection + 1;

		intersection = intersection * 10;
		GetRGB(2 ,&red, &green, &blue);

	 // nxtDisplayTextLine(4,"RG = %d,%d", (int)green,(int)rightAverage);

		if (green< rightAverage)
			intersection = intersection + 1;

		writeDebugStream("%d\n", intersection);
		nxtDisplayBigTextLine(6,"%d", intersection);
		return intersection;
	}


int checkIntersection(float LRatio1, float LRatio2, float RRatio1, float RRatio2, float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, float LightUp, float LightDown)
{
		float leftAverage = (1.0 * LGreenUp + 4.0 * LGreenDown)/5.0;
		float rightAverage = (1.0* RGreenUp + 4.0 * RGreenDown)/5.0;
		int intersection = 0;
		intersection = returnIntersection(LGreenUp, LGreenDown, RGreenUp, RGreenDown, LightUp, LightDown);
		if	(1 == gapCount(intersection))
		{
			doGap(LRatio1, LRatio2, RRatio1, RRatio2);
		}

		switch(intersection)
		{
		case 10:
			motor[LM] = 30;
			motor[RM] = 30;
			return 1;
			break;

		case 110:
			//motor[LM] = 30;
			//motor[RM] = 30;
			return 2;
			break;

		case 11:
			//motor[LM] = 30;
			//motor[RM] = 30;
			return 2;
			break;

		case 111:
			motor[LM] = 10;
			motor[RM] = 10;
			return 1;
			break;

		case 101:
			motor[LM] = 10;
			motor[RM] = 10;
			return 1;
			break;

		case 0:
			//motor[LM] = 30;
			//motor[RM] = 30;
			cmForward(0.1, 40);
			return 1;
			//troubleZero(LGreenUp, LGreenDown, RGreenUp, RGreenDown,LRatio1, LRatio2, RRatio1, RRatio2);
			break;
		}

			return 0;
}
