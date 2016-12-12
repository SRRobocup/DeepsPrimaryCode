#include "source.h"
#include "initialize sensors.c"
float value[10];

//**************************************************************************************************************************

float findErr()
{
	float compareValue = 0;
	for (int i = 1; i < 10; i++)
	{
    	compareValue = value[i];
    	for (int j = (i- 1); j > -1; j--)
    	{
        	if(value[j] < compareValue)
        	{
            	j = 0;                                             	// start comparing the next value
        	}
        	else
        	{
            	value[(j + 1)] = value[j];
            	value[j] = compareValue;            	// switch the two
        	}
    	}

	}
	return (value[5]);
}



//**************************************************************************************************************************

void doobstacle()

{
	float power = 0;
	float fwd = 10;
	float td = 10;
	float err = 0;
	float err2 = 0;
	float errOfErr = 0;
	float kp = 2.0/10.0;

//Ge the values for insertion sort.//

for (int i = 0; i < 9; i++)
{
 value[i] = SensorValue[ultraForward] - td;
}
err = findErr();
for (int i = 0; i < 9; i++)
{
 value[i] = SensorValue[ultraSide] - td;
}
err2 = findErr() ;
errOfErr = err - err2;
//Find power.//


		power = (err * kp);
		power = power - errOfErr;

		if (power> 40)
		power = 40;
		if (power< -40)
		power = -40;

//Move the motors.//

		if (err < 5 && err > -5)
	{
		motor[Motorright] = (40);
		motor[Motorleft] = (40);
	nxtDisplayTextLine(4,"yolo");
	}
	else
	{
		motor[Motorright] = (-power + fwd);
		motor[Motorleft] = (power + fwd);
	}

//Display stuff.//

			nxtDisplayTextLine(4,"%f",err);
			nxtDisplayTextLine(6,"%f",power);
			wait10Msec(1);
}
