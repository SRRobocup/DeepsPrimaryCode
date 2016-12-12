#include "source.h"
#include "initialize sensors.c"
#include "cmEncoders.c"
int values[10];
int target = 0;
int vallDistance = 50;

//Insertion sort//************************************************************************************

float findErrs()
{
	float compareValue = 0;
	for (int i = 1; i < 10; i++)
	{
		compareValue = values[i];
		for (int j = (i- 1); j > -1; j--)
		{
			if(values[j] < compareValue)
			{
				j = 0;
			}
			else
			{
				values[(j + 1)] = values[j];
				values[j] = compareValue;

			}
		}

	}
	return (values[5]);
}

//backAndTurn//*********************************************************************

void backAndTurn()
{
			motor[RM] = 0 ;
			motor[LM] = 0 ;
			playSound(soundBeepBeep);
			while (nMotorEncoder [motorA] > 0)
			{
				motor[RM] = -10 ;
				motor[LM] = -10 ;
				nxtDisplayTextLine(6,"%d",nMotorEncoder [motorA] );
			}
			nMotorEncoder [motorA] = 0;
			playSound(soundBeepBeep);
			while (nMotorEncoder [motorA] < 500)
			{
				motor[RM] = -10 ;
				motor[LM] = 10 ;
				nxtDisplayTextLine(6,"%d",nMotorEncoder [motorA] );
			}
			nMotorEncoder [motorA] = 0;
			playSound(soundBeepBeep);
			while (nMotorEncoder [motorA] < cmEncoders(target))
			{
				motor[RM] = 10 ;
				motor[LM] = 10 ;
				nxtDisplayTextLine(6,"%d",nMotorEncoder [motorA] );
			}
			nMotorEncoder [motorA] = 0;
			playSound(soundBeepBeep);
			while (nMotorEncoder [motorA] > -500)
			{
				motor[RM] = 10 ;
				motor[LM] = -10 ;
				nxtDisplayTextLine(6,"%d",nMotorEncoder [motorA] );
			}
			nMotorEncoder [motorA] = 0;
}

//daTurdRoom//************************************************************************************

void daTurdRoom()
{
	int	err = 0;
	for (int i = 0; i < 9; i++)
		{
			values[i] = SensorValue[ultraSide];
		}
	vallDistance = findErrs() - 10;
	nxtDisplayTextLine(1,"wall = %d", vallDistance );
	nMotorEncoder [motorA] = 0;


	while (1)
	{
		for (int i = 0; i < 9; i++)
		{
			values[i] = SensorValue[ultraSide];
		}

		err = findErrs();
		nxtDisplayTextLine(4,"err = %d", err);
		if (err > vallDistance)
		{
			motor[RM] = 10 ;
			motor[LM] = 10 ;
			nxtDisplayTextLine(4,"err = %d", err);
			nxtDisplayTextLine(6,"encoder = %d",nMotorEncoder [motorA] );
		}
		else
		{
			if (err <20)
			{
				motor[RM] = 0 ;
				motor[LM] = 0 ;
				//while (1)
				//{
				//playSound(soundBeepBeep);
				//}
			}
			else
		{
			target = err;
			vallDistance = valldistance - target/2;
			nxtDisplayTextLine(1,"wall = %d", vallDistance );
			nxtDisplayTextLine(1,"target = %d", target );
			backAndTurn();

		}
		}


	}
}
