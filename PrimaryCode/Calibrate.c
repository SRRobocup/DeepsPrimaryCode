#include "source.h"
#include "initialize sensors.c"
#include "clearScreen.c"
#include "Ev3 NXT Compatibility custom functions.c"

void calibrate(float*LRatio1, float*LRatio2, float*RRatio1, float*RRatio2, float*LGreenUp, float*LGreenDown, float*RGreenUp, float*RGreenDown, float*LightUp, float*LightDown)
{

	float red = 0;
	float green = 0;
	float blue = 0;
	int type = 0;
	int button = 0;
	int blank = 0;

	while(1)
	{
		GetEnterButtonState (&button);
		if(button == 1)
		{
			if(type == 0)
			{
				DisplayText(2,"LeftRatio1=       ", 1, blank);
				GetRGB(1 ,&red, &green, &blue);
				*LRatio1 = red/green;
				DisplayText(4,"",2, *LRatio1);
				PlaySound(soundBeepBeep);
			}
			if(type == 1)
			{
				DisplayText(2,"LeftRatio2=       ", 1, blank);
				GetRGB(1 ,&red, &green, &blue);
				*LRatio2 = blue/green;
				DisplayText(4,"",2, *LRatio2);
				PlaySound(soundBeepBeep);
			}
			if(type == 2)
			{
				DisplayText(2,"RightRatio1=       ", 1, blank);
				GetRGB(2 ,&red, &green, &blue);
				*RRatio1 = red/green;
				DisplayText(4,"",2, *RRatio1);
				PlaySound(soundBeepBeep);
			}
			if(type == 3)
			{
				DisplayText(2,"RightRatio2=       ", 1, blank);
				GetRGB(2 ,&red, &green, &blue);
				*RRatio2 = blue/green;
				DisplayText(4,"",2, *RRatio2);
				PlaySound(soundBeepBeep);
			}
			if(type == 4)
			{
				DisplayText(2,"LGreenUp=       ", 1, blank);
				GetRGB(1 ,&red, &green, &blue);
				*LGreenUp = green;
				DisplayText(4,"",2, *LGreenUp);
				PlaySound(soundBeepBeep);
			}
			if(type == 5)
			{
				DisplayText(2,"LGreenDown=       ", 1, blank);
				GetRGB(1 ,&red, &green, &blue);
				*LGreenDown = green;
				DisplayText(4,"",2, *LGreenDown);
				PlaySound(soundBeepBeep);
			}
			if(type == 6)
			{
				DisplayText(2,"RGreenUp=       ", 1, blank);
				GetRGB(2 ,&red, &green, &blue);
				*RGreenUp = green;
				DisplayText(4,"",2, *RGreenUp);
				PlaySound(soundBeepBeep);
			}
			if(type == 7)
			{
				DisplayText(2,"RGreenDown=       ", 1, blank);
				GetRGB(2 ,&red, &green, &blue);
				*RGreenDown = green;
				DisplayText(4,"",2, *RGreenDown);
				PlaySound(soundBeepBeep);
			}
			if(type == 8)
			{
				DisplayText(2,"LightUp=       ", 1, blank);
				*LightUp = SensorValue[lightForward];
				DisplayText(4,"",2, *LightUp);
				PlaySound(soundBeepBeep);
			}
			if(type == 9)
			{
				DisplayText(2,"LightDown=       ", 1, blank);
				*LightDown = SensorValue[lightForward];
				DisplayText(4,"",2, *LightDown);
				PlaySound(soundBeepBeep);
			}
			if(type > 9)
			{
				PlaySound(soundBeepBeep);
				return;
			}
			wait10Msec(100);
			type++;
		}
		else
		{
			if(type == 0)
				DisplayText(0,"Press 4 LRatio1", 1, blank);
			if(type == 1)
				DisplayText(0,"Press 4 LRatio2", 1, blank);
			if(type == 2)
				DisplayText(0,"Press 4 RRatio1", 1, blank);
			if(type == 3)
				DisplayText(0,"Press 4 RRatio2", 1, blank);
			if(type == 4)
				DisplayText(0,"Press 4 LGreenUp", 1, blank);
			if(type == 5)
				DisplayText(0,"Press 4 LGreenDown", 1, blank);
			if(type == 6)
				DisplayText(0,"Press 4 RGreenUp", 1, blank);
			if(type == 7)
				DisplayText(0,"Press 4 RGreenDown", 1, blank);
			if(type == 8)
				DisplayText(0,"Press 4 LightUp", 1, blank);
			if(type == 9)
				DisplayText(0,"Press 2 LightDown", 1, blank);
			if(type > 10)
				DisplayText(0,"Press 2 Continue", 1, blank);

	}
}
}
