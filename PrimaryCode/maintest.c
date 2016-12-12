#define Jagdeep
#include "source.h"
#include "Ev3 NXT Compatibility custom functions.c"

void calibrate(float*LRatio1, float*LRatio2, float*RRatio1, float*RRatio2, float*LGreenUp, float*LGreenDown, float*RGreenUp, float*RGreenDown)
{

	float red = 0;
	float green = 0;
	float blue = 0;
	int type = 0;
	int button = 0;

	while(1)
	{
		GetEnterButtonState (&button);
		if(button == 1)
		{
			if(type == 0)
			{
				//displayTextLine(2, "LeftRatio1=");
				GetRGB(1 ,&red, &green, &blue);
				*LRatio1 = red/green;
				//displayTextLine(4, "%f", *LRatio1 );
				PlaySound(soundBeepBeep);
			}
			if(type == 1)
			{
				//displayTextLine(2, "LeftRatio2=");
				GetRGB(1 ,&red, &green, &blue);
				*LRatio2 = blue/green;
				//displayTextLine(4, "%f", *LRatio2 );
				PlaySound(soundBeepBeep);
			}
			if(type == 2)
			{
				//displayTextLine(2, "RightRatio1=");
				GetRGB(2 ,&red, &green, &blue);
				*RRatio1 = red/green;
				//displayTextLine(4, "%f", *RRatio1 );
				PlaySound(soundBeepBeep);
			}
			if(type == 3)
			{
				//displayTextLine(2, "RightRatio2=");
				GetRGB(2 ,&red, &green, &blue);
				*RRatio2 = blue/green;
				//displayTextLine(4, "%f", *RRatio2 );
				PlaySound(soundBeepBeep);
			}
			if(type == 4)
			{
				//displayTextLine(2, "LGreenUp=");
				GetRGB(1 ,&red, &green, &blue);
				*LGreenUp = green;
				//displayTextLine(4, "%f", *LGreenUp );
				PlaySound(soundBeepBeep);
			}
			if(type == 5)
			{
				//displayTextLine(2, "LGreenDown=");
				GetRGB(1 ,&red, &green, &blue);
				*LGreenDown = green;
				//displayTextLine(4, "%f", *LGreenDown );
				PlaySound(soundBeepBeep);
			}
			if(type == 6)
			{
				//displayTextLine(2, "RGreenUp=");
				GetRGB(2 ,&red, &green, &blue);
				*RGreenUp = green;
				//displayTextLine(4, "%f", *RGreenUp );
				PlaySound(soundBeepBeep);
			}
			if(type == 7)
			{
				//displayTextLine(2, "RGreenDown=");
				GetRGB(2 ,&red, &green, &blue);
				*RGreenDown = green;
				//displayTextLine(4, "%f", *RGreenDown );
				PlaySound(soundBeepBeep);
			}
			if(type > 7)
			{
				PlaySound(soundBeepBeep);
				return;
			}
			wait10Msec(100);
			type++;
		}
		else
		{
			if(type == 0) {}
				//displayTextLine(5, "Press for LRatio1");
			if(type == 1) {}
				//displayTextLine(5, "Press for LRatio2");
			if(type == 2) {}
				//displayTextLine(5, "Press for RRatio1");
			if(type == 3) {}
				//displayTextLine(5, "Press for RRatio2");
			if(type == 4) {}
				//displayTextLine(5, "Press for LGreenUp");
			if(type == 5) {}
				//displayTextLine(5, "Press for LGreenDown");
			if(type == 6) {}
				//displayTextLine(5, "Press for RGreenUp");
			if(type == 7) {}
				//displayTextLine(5, "Press for RGreenDown");
			if(type > 7) {}
				//displayTextLine(5, "Press to Continue");

	}
}
}
