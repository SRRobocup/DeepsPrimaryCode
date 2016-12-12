#include "source.h"
#include "gapCount.c"
#include "Common Functions.c"
#include "traceIteration.c"
#include "Ev3 NXT Compatibility custom functions.c"
#include "checkGreen.c"
#include "doGap.c"

//Globals
float leftAverageThresh=0.0;
float rightAverageThresh=0.0;
float lightAverageThresh=0.0;
float leftLowAverageThresh = 0.0;
float rightLowAverageThresh = 0.0;
float slopeValue = 0.0;
float interceptValue = 0.0;

//Global PIDs
float PID_I = 0;
float PID_D=0;
float PID_previousError=0.0;
float PID_IDAMPER = 0.999;
float KI = 0.0008;
float KD=0.1;
float PID_Max_Error=100.0;
float PID_Min_Error=-100.0;
float kp1 = 0.4;
float kp2 = 0.1;
float forward1 = 0;
float forward2 = 60;


float getRightLowAverageThresh()
{
	return rightLowAverageThresh;
}
float getLeftLowAverageThresh()
{
	return leftLowAverageThresh;
}
float getLeftAverageThresh()
{
	return leftAverageThresh;
}

float getRightAverageThresh()
{
	return rightAverageThresh;
}

float getLightAverageThresh()
{
	return lightAverageThresh;
}

float getSlope()
{
	return slopeValue;
}

float getIntercept()
{
	return interceptValue;
}


int returnIntersectionPID(float greenLeft, float greenRight, float lightValue)
{
	int intersection = 0;
	float red = 0;
	float green = 0;
	float blue = 0;

	float leftAverage = getLeftAverageThresh();
	float lightAverage = getLightAverageThresh();
	float rightAverage = getRightAverageThresh();


	nxtDisplayTextLine(0,"%d", lightAverage);


	if (greenLeft < leftAverage)
		intersection = intersection + 1;

	intersection = intersection * 10;

	if(lightValue < lightAverage)
		intersection = intersection + 1;

	intersection = intersection * 10;



	if (greenRight < rightAverage)
		intersection = intersection + 1;

	writeDebugStream("%d\n", intersection);
	nxtDisplayBigTextLine(6,"%d", intersection);
	return intersection;
}



void runAlgorithm(float LRatio1, float LRatio2, float RRatio1, float RRatio2)
{

	float red = 0;
	float green = 0;
	float blue = 0;
	float greenLeft = 0.0;
	float greenRight = 0.0;
	float lightValue= 0.0;
	float kp = 0;
	float forward = 0;
	int straight = 0;
	float err = 0;

	while (SensorValue[lightForward] < 77)
	{
		//nxtDisplayTextLine(2,"%d", SensorValue[lightForward]);

		if(1 == checkGreen(LRatio1, LRatio2, RRatio1, RRatio2))
		{
			resetPIDValues();
			continue;
		}
		if (1==doObstacle())
		{
			resetPIDValues();
			continue;
		}


		GetRGB(1 ,&red, &green, &blue);
		//nxtDisplayTextLine(3,"LG = %d,%d", (int)green, (int)leftAverage);
		greenLeft= green;


		GetRGB(2 ,&red, &green, &blue);
		// nxtDisplayTextLine(4,"RG = %d,%d", (int)green,(int)rightAverage);
		greenRight= green;


		lightValue = SensorValue[lightForward];


		int intersection = 0;
		intersection = returnIntersectionPID(greenLeft, greenRight, lightValue);


		if	(1 == gapCount(intersection))
		{
		resetPIDValues();
		doGap(LRatio1, LRatio2, RRatio1, RRatio2);
		resetPIDValues();
		continue;
		}



		getPIDParameters(greenLeft, greenRight, lightValue, intersection, &err, &kp, &forward);

		runIterationPID(err, kp, forward, KI, KD);


	}
}


void runIterationPID(float error, float KP, float forward, float KI, float KD)
{
	int button = 0;
	PID_I = PID_IDAMPER* PID_I + error;
	PID_D = error - PID_previousError;
	PID_previousError = error;
	GetEnterButtonState (&button);
		if(button == 1)
		{
			resetPIDValues();
			PlaySound(soundBeepBeep);
		}
	float totalError = KP*error + KD*PID_D + KI*PID_I;
	nxtDisplayTextLine(2, "%d,%d", (int)(KI*PID_I),(int)totalError);
	writeDebugStream("Err= %d,%d,%d\n", (int)(KI*PID_I),(int)(KD*PID_D),(int)totalError);


	if(totalError > PID_Max_Error)
		totalError = PID_Max_Error;

	if(totalError < PID_Min_Error)
		totalError = PID_Min_Error;


	motor[LM] = forward + totalError ;
	motor[RM] = forward - totalError;


}



void getPIDParameters(float greenLeft, float greenRight, float lightValue, int intersection, float *error, float *kp, float *forward)
{

	*kp = 0;
	*error = 0;
	*forward = 0;
	switch(intersection)
	{
	case 10:
		*forward = 13; //13
		break;

	case 110:
		*kp = kp2;
		*forward = forward2;
		*error = -1.0 * getRightError(greenRight);
		nxtDisplayTextLine(4,"RG = %f", *error);
		break;

	case 11:
		*kp = kp2;
		*forward = forward2;
		*error = getLeftError(greenLeft);
		nxtDisplayTextLine(3,"LG = %f", *error);
		break;

	case 111:
		*forward = 40;
		break;

	case 101:
		*forward = 7; //7
		break;

	case 0:
		*forward = 13; //10, 13
		break;

	case 1:
		*kp = kp1;
		*forward = forward1;
		*error = getLeftPlusLightError(greenLeft, lightValue);
			nxtDisplayTextLine(3,"LLG = %f", *error);
			break;

	case 100:
		*kp = kp1;
		*forward = forward1;
		*error = -1.0 * getRightPlusLightError(greenRight, lightValue);
			nxtDisplayTextLine(4,"RRG = %f", *error);
			break;

	}
}


// Get error in white color and normalize it to the right sensor
float getLeftError(float green)
{
	float error=0;
	float leftTarget = getLeftAverageThresh();
	float rightTarget = getRightAverageThresh();
	float slope = getSlope();
	float intercept = getIntercept();

	float rightGreenError = (green * slope) + intercept;

	if (rightGreenError > rightTarget)
	{
		error = rightGreenError - rightTarget ;
		writeDebugStream("LErr= %d,%d\n", (int)error,(int)green);
	}
//	nxtDisplayTextLine(3,"LG = %f", error);



	return error;

}


// Get error in white color
float getRightError(float green)
{
	float error=0;
	float rightTarget = getRightAverageThresh();


	if (green > rightTarget)
	{
		error =  green - rightTarget;
		writeDebugStream("RErr= %d,%d\n", (int)error,(int)green);

	}



	return error;

}

// Get error in white color
float getLightError(float light)
{
	float error=0;
	float lightTarget = getLightAverageThresh();


	if (light > lightTarget)
	{
		error =  light - lightTarget;
		writeDebugStream("LgtErr= %d,%d\n", (int)error,(int)light);

	}


	return error;


}

float getLeftPlusLightError(float green, float lightValue)
{
	float error = 0.0;
	float error1= getLeftError(green);
	float error2= getLightError(lightValue);
	error = combineErrors(error1,error2);
	writeDebugStream("LLErr= %d\n", (int)error);
	return error;
}

float getRightPlusLightError(float green, float lightValue)
{
	float error = 0.0;
	float error1= getRightError(green);
	float error2= getLightError(lightValue);
	error = combineErrors(error1,error2);
	writeDebugStream("RLErr= %d\n", (int)error);
	return error;
}

float combineErrors(float green, float lightValue)
{
	float factor = 4.0;
	return green + factor * lightValue;
}

void resetPIDValues(void)
{
	PID_I = 0;
	PID_D=0;
	PID_previousError=0.0;
}



void initializePID(float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, float LightUp, float LightDown)
{
	float leftRangeSize = LGreenUp - LGreenDown;
	float rightRangeSize = RGreenUp - RGreenDown;

	leftAverageThresh = (1.0 * LGreenUp + 1.0 * LGreenDown)/2.0;
	rightAverageThresh = (1.0* RGreenUp + 1.0 * RGreenDown)/2.0;
	lightAverageThresh = (1.0 * LightUp + 1.0 * LightDown)/2.0;
	leftLowAverageThresh = (1.0 * LGreenUp + 2.0 * LGreenDown)/3.0;
	rightLowAverageThresh = (1.0* RGreenUp + 2.0 * RGreenDown)/3.0;

	slopeValue = rightRangeSize/leftRangeSize;
	interceptValue = RGreenUp - (LGreenUp * slopeValue);


}
