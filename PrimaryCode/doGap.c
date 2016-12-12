#include "traceIteration.c"
#include "PID.c"
void doGap(float LRatio1, float LRatio2, float RRatio1, float RRatio2)
{
	float leftTarget = getLeftAverageThresh();
	float rightTarget = getRightAverageThresh();
	float green = 0;
	float greenRight = 0;
	float greenLeft = 0;
	float lightValue = 0;
	float intersection = 0;
	float red = 0;
	float Lgreen = 0;
	float Rgreen = 0;
	float blue = 0;
	float forward = 20;
	float kp = 0.4;
	float err = 0;
	float foundLine = 0;
	GetRGB(1 ,&red, &Lgreen, &blue);
	GetRGB(2 ,&red, &Rgreen, &blue);
	int mypower = 100;



while (1)
	{

	cmForward(-5,40);
	wait10Msec(10);
	for (int i = 0; i < 5; i++)
		{
			degTurn(9, myPower);
			wait10Msec(10);

			GetRGB(2 ,&red, &Rgreen, &blue);
			if (Rgreen < rightTarget)
			{
				whiteCount = 0;
				blackCount = 0;
				foundLine = 1;
				break;
			}
		}
		if(foundLine == 1)
		{
			break;
		}


		degTurn(-45, myPower);
		wait10Msec(10);


		for (int i = 0; i < 5; i++)
		{
			degTurn(-9, myPower);
			wait10Msec(10);

			GetRGB(1 ,&red, &Lgreen, &blue);
			if (Lgreen < leftTarget)
			{
				whiteCount = 0;
				blackCount = 0;
				foundLine = 1;
				break;
			}
		}
		if(foundLine == 1)
			break;

		degTurn(45, myPower);
		wait10Msec(10);

	}
	//////////////////
	///ALIGN CODE/////
	//////////////////

	cmForward(-2, 20);


	for (int i = 0; i<1000; i++)
	{
					GetRGB(1 ,&red, &green, &blue);
		//nxtDisplayTextLine(3,"LG = %d,%d", (int)green, (int)leftAverage);
		greenLeft= green;

		GetRGB(2 ,&red, &green, &blue);
		// nxtDisplayTextLine(4,"RG = %d,%d", (int)green,(int)rightAverage);
		greenRight= green;

		lightValue = SensorValue[lightForward];

		int intersection = 0;
		intersection = returnIntersectionPID(greenLeft, greenRight, lightValue);

		resetPIDValues();
		getPIDParameters(greenLeft, greenRight, lightValue, intersection, &err, &kp, &forward);
		runIterationPID(err, kp,forward, 0, 0);

	}

	cmForward(-7, 20);


	for (int i = 0; i<2000; i++)
	{
					GetRGB(1 ,&red, &green, &blue);
		//nxtDisplayTextLine(3,"LG = %d,%d", (int)green, (int)leftAverage);
		greenLeft= green;

		GetRGB(2 ,&red, &green, &blue);
		// nxtDisplayTextLine(4,"RG = %d,%d", (int)green,(int)rightAverage);
		greenRight= green;

		lightValue = SensorValue[lightForward];

		int intersection = 0;
		intersection = returnIntersectionPID(greenLeft, greenRight, lightValue);

		resetPIDValues();
		getPIDParameters(greenLeft, greenRight, lightValue, intersection, &err, &kp, &forward);
		runIterationPID(err, kp,forward, 0, 0);

	}





	while (1)
	{
	cmForward(5,40);
	for (int i = 0; i < 5; i++)
		{
			degTurn(9, 100);
			GetRGB(1 ,&red, &Lgreen, &blue);
			GetRGB(2 ,&red, &Rgreen, &blue);
			if (Rgreen < rightTarget || Lgreen < leftTarget)
			{
				whiteCount = 0;
				blackCount = 0;
				return;
			}
		}
		degTurn(-45, 100);
		for (int i = 0; i < 5; i++)
		{
			degTurn(-9, 100);
			GetRGB(1 ,&red, &Lgreen, &blue);
			GetRGB(2 ,&red, &Rgreen, &blue);
			if (Rgreen < rightTarget || Lgreen < leftTarget)
			{
				whiteCount = 0;
				blackCount = 0;
				return ;
			}
		}
		degTurn(45, 100);
	}
}
