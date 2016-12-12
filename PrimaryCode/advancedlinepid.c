#include "source.h"
#include "initialize sensors.c"
#include "checkGreen.c"
#include "checkBlack.c"
#include "doRadius.c"

const int size = 3500;
float maxD = -100;
float minD = 100;
float x[size];
int i = 0;





//*************************************GET D*****************************************


float get_d( float err)

{

	float D = 0;
	float prev = 0;
	i = i % size;
	prev = x[(i + 1)% size];
	x[i] = err;
	D = err - prev;
	i = i + 1;
	if (D > maxD)
		maxD = D;
	if (D < minD)
		minD = D;
	return (D);
}


//*************************************START LINE TRACE*******************************************


int test_trace5()

{
	float average = (black + white)/ 2;
	float maxSpeed = 30;
	float kp = 0;
	float ki = 0;
	float kd = 0;
	float err = 0;
	float I = 0;
	float D = 0;
	float power = 0;
	int fwd=10;
	float prev = 0;
	float z = 0;

		kp = maxSpeed/(white - average);
		kp = 30/10;
		ki = (1/50);
		kd = (1.0/1.0);



	//**************************************LINE TRACE CODE**********************************************


	while(1)
	{
		nxtDisplayTextLine(1, "Currently:");
		nxtDisplayTextLine(3, "Line Tracing");
		err = SensorValue[LM] - average;
		I = I + (err);
		D = get_d(err);
		z = kd * D;
		power = ((err * kp) + (ki * I)); //(D*kd)



		if(power == 0)
		{
			motor[RM] = 5;
			motor[LM] = 5;
		}
		else
		{
			motor[RM] = (-power + fwd);
			motor[LM] = (power + fwd);
		}

		doRadius(5);

	//	if(err< -10)
		//checkBlack(BR, BG, BB);

		//checkGreen(GR, GG, GB);
	}
	return (0);
}
