#define Jagdeep
#include "source.h"
#include "initialize sensors.c"
#include "Calibrate.c"
#include "Ev3 NXT Compatibility custom functions.c"
#include "LineTrace.c"
#include "checkGreen.c"
#include "Common Functions.c"
#include "PID.c"
#include "thirdRoom.c"
#include "silver.c"


task main()
{
	float LRatio1 = 0;
	float LRatio2 = 0;
	float RRatio1 = 0;
	float RRatio2 = 0;
	float LGreenUp = 0;
	float LGreenDown = 0;
	float RGreenUp = 0;
	float RGreenDown = 0;
	float LightUp = 0;
	float LightDown = 0;
	clearDebugStream();
	initialize ();
	calibrate (&LRatio1, &LRatio2, &RRatio1, &RRatio2, &LGreenUp, &LGreenDown, &RGreenUp, &RGreenDown, &LightUp, &LightDown);
	wait10Msec(100);
	initializePID(LGreenUp, LGreenDown, RGreenUp, RGreenDown, LightUp, LightDown);
	runAlgorithm(LRatio1, LRatio2, RRatio1, RRatio2);
	thirdRoom();
	//LineTrace(LRatio1, LRatio2, RRatio1, RRatio2, LGreenUp, LGreenDown, RGreenUp, RGreenDown, LightUp, LightDown);

}
