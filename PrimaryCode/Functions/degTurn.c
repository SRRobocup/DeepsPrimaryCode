#include "source.h"
#include "initialize sensors.c"

float degTurn (float deg)
{
	float circum = (wheelbase/2)*(wheelbase/2)*(PI); //Calculates the circumference of the circle created when rotating you robot.
	float rotations = circum/ (diameter * PI); //Calculates how many times ONE wheel must rotate to complete a circle.
	float totalEncoder = rotations * 360; //Turns the previous value into encoders.
	float travelDistance = totalEncoder * (deg/360); //calculates the amount of encoders needed to travel for one wheel for deg. turn.
	nMotorEncoder [RM] = 0;
	if (deg > 0)
	{
		while (nMotorEncoder [RM] < (travelDistance/2)) //Two wheels = half the travel distance.
		{
			motor[RM] = 40;
			motor[LM] = -40;
		}
		return (0);
	}
	else
	{
		while (nMotorEncoder [RM] > (travelDistance/2)) //Two wheels = half the travel distance.
		{
			motor[RM] = -40;
			motor[LM] = 40;
		}
		return (0);
	}

}
