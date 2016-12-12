#include "PID.c"
float whiteCount = 0;
float blackCount = 0;
int gapCount(int intersection)
{
	float red = 0;
	float blue = 0;
	float green = 0;
	float leftAverage = getLeftLowAverageThresh();
	float rightAverage = getRightLowAverageThresh();

	///Change the variables//

	if (intersection == 0)
	{
		whiteCount++;
	}
	else
	{
		blackCount++;
	}

	///Check the white///

	if (whiteCount> 800)
	{
		for (int i = 0; i < 5; i++)
		{
			degTurn(9, 40);
			GetRGB(2 ,&red, &green, &blue);
			if (green < rightAverage)
			{
				whiteCount = 0;
				blackCount = 0;
				return 0;
			}
		}
		degTurn(-45, 100);
		for (int i = 0; i < 5; i++)
		{
			degTurn(-9, 40);
			GetRGB(1 ,&red, &green, &blue);
			if (green < leftAverage)
			{
				whiteCount = 0;
				blackCount = 0;
				return 0;
			}
		}
		degTurn(45, 100);

		//If we havent seen black yet...///

		PlaySound(soundUpwardTones);
		motor[LM] = 0;
		motor[RM] = 0;
		wait10Msec(100);
		whiteCount = 0;
		blackCount = 0;
		return 1;

	}


	///Check the black///


	if (blackCount > 15)
	{
		whiteCount = 0;
		blackCount = 0;
	}
	//nxtDisplayTextLine(3,"WC=%d", whiteCount );
	//nxtDisplayTextLine(4,"BC=%d", blackCount );
	return 0;
}
