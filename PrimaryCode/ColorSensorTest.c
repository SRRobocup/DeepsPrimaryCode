#define Jagdeep
#include "source.h"
#include "Ev3 NXT Compatibility custom functions.c"
task main()
{
	SensorType[colorLeft] = sensorCOLORFULL;
	//SensorType[colorRight] = sensorColorNxtFULL;
	//SensorType[colorRight] = sensorCOLORFULL;
	float red = 0;
	float green = 0;
	float blue = 0;
while (1)
{
	GetRGB(1 ,&red, &green, &blue);
		nxtDisplayTextLine(4,"%f", red);
	nxtDisplayTextLine(5,"%f", green);
		nxtDisplayTextLine(6,"%f", blue);
}


//		SensorType[distForward] = sensorSONAR;
//	//SensorType[colorRight] = sensorColorNxtFULL;
//	//SensorType[colorRight] = sensorCOLORFULL;
//while (1)
//{

//	nxtDisplayTextLine(4,"%f", SensorValue[distForward]);
//}
}
