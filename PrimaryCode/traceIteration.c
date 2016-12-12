
void traceIteration(float LRatio1, float LRatio2, float RRatio1, float RRatio2, float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, float kp, float forward)
{
	float red = 0;
	float green = 0;
	float blue = 0;
	float leftTarget = (1.0 * LGreenUp + 1.0 * LGreenDown)/2.0;
	float rightTarget = (1.0 * RGreenUp + 1.0 * RGreenDown)/2.0;
	float leftRangeSize = LGreenUp - LGreenDown;
	float rightRangeSize = RGreenUp - RGreenDown;
	float slope = rightRangeSize/leftRangeSize;
	float intercept = RGreenUp - (LGreenUp * slope);
	float normalizer = 0;

	if (leftRangeSize<rightRangeSize)
		normalizer = leftRangeSize;

	else
		normalizer = rightRangeSize;
	int straight = 0;
	float err = 0;


		straight = 0;

		GetRGB(2 ,&red, &green, &blue);
		if (green < rightTarget)
		{
			err = rightTarget - green;

			nxtDisplayTextLine(4,"RG = %f", err);
			motor[LM] = forward + (err * kp);
			motor[RM] = forward - (err * kp);
			return;
		}

		else
		{
			straight = straight + 1;
		}

		GetRGB(1 ,&red, &green, &blue);
		if (green < leftTarget)
		{
			err = rightTarget - ((green * slope) + intercept);
			nxtDisplayTextLine(3,"LG = %f", err);
			motor[LM] = forward - (err * kp);
			motor[RM] = forward + (err * kp);
			return;
		}
		else
		{
			straight = straight + 1;
		}
/*
		GetRGB(2 ,&red, &green, &blue);
		if (green < rightTarget)
		{
			err = rightTarget - green;

		//	nxtDisplayTextLine(4,"RG = %f", err);
			motor[LM] = forward + (err * kp);
			motor[RM] = forward - (err * kp);
			return;
		}

		else
		{
			straight = straight + 1;
		}
*/
		if (straight == 2)
		{
			motor[LM] = forward;
			motor[RM] = forward;
		}
}
