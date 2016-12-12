#include "Common Function.c"

float doRadius(float radius)
{
	float distance = 5;
	float roboWidth = 16;
	float leftWheel = (radius + distance);
	float rightWheel = (radius + distance + roboWidth);


	if (SensorValue [distForward] <10)
	{
		nxtDisplayTextLine(6,"we saw stuff");
		nMotorEncoder [RM] = 0;
		while (nMotorEncoder [RM] > -300)
		{
			motor[RM] = -20;
			motor[LM] = 20;
		}
		while (1)

		motor[RM] = rightWheel;
		motor[LM] = leftWheel;
	}
	return 0;
}
