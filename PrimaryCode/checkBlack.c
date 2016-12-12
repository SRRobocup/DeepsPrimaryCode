#include "source.h"
#include "initialize sensors.c"
#include "clearScreen.c"

int checkBlack(int BR, int BG, int BB)

{
	nxtDisplayTextLine(5, "Checking Black!");
	short colorarray[3];

	getColorSensorData(colorRight, colorRaw, colorarray);
	nxtDisplayTextLine(1, "%d", colorarray[0]);
	nxtDisplayTextLine(3, "%d", colorarray[1]);
	nxtDisplayTextLine(5,"%d", colorarray[2]);


	if(colorarray[0]> (BR - 20) && colorarray[0]<(BR + 20) && colorarray[1]>(BG - 20) && colorarray[1]<(BG + 20) && colorarray[2]>(BB - 20) && colorarray[2]<(BB + 20))
	{
		clearScreen();
		nxtDisplayTextLine(1, "Currently:");
		nxtDisplayTextLine(3, "See Black!");
		PlaySound(soundBeepBeep);
		motor[RM] = 0;
		motor[LM] = 0;
		wait10Msec(100);
		motor[RM] = 10;
		motor[LM] = 10;
		wait10Msec(130);
		//while(SensorValue[leftLight] > black)
		//{
		//	motor[RM] = 10;
		//	motor[LM] = -10;
		//}
	}

return (0);
}
