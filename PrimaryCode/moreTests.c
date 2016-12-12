#define Jagdeep
#include "source.h"
#include "Common Functions.c"
task main()
{
//	degTurn(83, 40);
//	wait10Msec(10);
//	degTurn(83, 40);
//	wait10Msec(10);
//degTurn(83, 40);
//	wait10Msec(10);
//degTurn(83, 40);
//	wait10Msec(10);

	nMotorEncoder[RM] = 0;
while (nNxtButtonPressed != 3)
	{
	motor[LM] = 10;
	motor[RM] = -10;
	}
	motor[LM] = 0;
	motor[RM] = 0;
	nxtDisplayTextLine(5, "%d", nMotorEncoder[RM]);
	nxtDisplayTextLine(4, "%f", (nMotorEncoder[RM]*3)/20);
	wait10Msec(1100);
}
