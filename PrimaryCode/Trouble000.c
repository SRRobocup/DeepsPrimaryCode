int checkBlack(float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, int side)
{
	float red = 0;
	float green = 0;
	float blue = 0;
	float leftTarget = (LGreenUp + LGreenDown)/2;
	float rightTarget = (RGreenUp + RGreenDown)/2;

	GetRGB(side ,&red, &green, &blue);

	if (green < leftTarget)
		{
			return 1;
		}

	return 0;
}



void troubleZero(float LRatio1, float LRatio2, float RRatio1, float RRatio2, float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown)
{



	for (int i = 0; i < 60; i++)
	{

		degTurn(1, 40);

		if (checkBlack(LGreenUp, LGreenDown, RGreenUp, RGreenDown, 2) == 1)
		{
		PlaySound(soundUpwardTones);
		return;
		}
	}
	degTurn(-60, 40);
	nxtDisplayBigTextLine(4,"three");

		for (int i = 0; i < 60; i++)
	{

		degTurn(-1, 40);

		if (checkBlack(LGreenUp, LGreenDown, RGreenUp, RGreenDown, 1) == 1)
		{
		PlaySound(soundUpwardTones);
		return;
		}
	}
	degTurn(60, 40);
	//gap();
	nxtDisplayBigTextLine(4,"four");

}
