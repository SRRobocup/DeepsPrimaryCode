#include "Calibrate.c"
#include "Ev3 NXT Compatibility custom functions.c"
#include "LineTrace.c"
#include "checkGreen.c"
#include "Intersection.c"
#include "traceIteration.c"
#include "doObstacle.c"

void LineTrace(float LRatio1, float LRatio2, float RRatio1, float RRatio2, float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, float LightUp, float LightDown)
{

	float red = 0;
	float green = 0;
	float blue = 0;
	float leftTarget = (1.0 *LGreenUp + 1.0 * LGreenDown)/2.0;
	float rightTarget = (1.0 *RGreenUp + 1.0 * RGreenDown)/2.0;
	float leftRangeSize = LGreenUp - LGreenDown;
	float rightRangeSize = RGreenUp - RGreenDown;
	float slope = rightRangeSize/leftRangeSize;
	float intercept = RGreenUp - (LGreenUp * slope);
	float normalizer = 0;

	if (leftRangeSize<rightRangeSize)
		normalizer = leftRangeSize;

	else
		normalizer = rightRangeSize;
	float kp1 = 10;
	float kp2 = 2;
	float kp = 0;
	float forward1 = 20;
	float forward2 = 40;
	float forward = 0;
	int straight = 0;
	float err = 0;
	int returnIntersection = 0;

	while (1)
	{
		doObstacle();
		//if(1==checkGreen(LRatio1, LRatio2, RRatio1, RRatio2, leftTarget, rightTarget))
		//	continue;

		//returnIntersection = checkIntersection(LRatio1,LRatio2, RRatio1, RRatio2, LGreenUp, LGreenDown, RGreenUp, RGreenDown, LightUp, LightDown);

		//if(1==returnIntersection)
		//{
		//	continue;
		//}

		kp = kp1;
		forward = forward1;

		//if(2 == returnIntersection)
		//{
		//	kp = kp2;
		//	forward = forward2;
		//}
		traceIteration(LRatio1,LRatio2, RRatio1, RRatio2, LGreenUp, LGreenDown, RGreenUp, RGreenDown,kp,forward);

	}
}
