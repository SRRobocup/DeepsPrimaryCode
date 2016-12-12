#define Jagdeep
#include "source.h"
#include "initialize sensors.c"

task main()
{
	initialize ();
	short colorright[3];
	getColorSensorData(colorRight, colorRaw, colorright);
	clearDebugStream();
	int red[100];
	int green[100];
	int blue[100];
	int y = 0;
		writeDebugStreamLine( "test");
	while (1)
	{
		if(nNxtButtonPressed == kEnterButton)
		{
			if(y<100)
			{

				getColorSensorData(colorRight, colorRaw, colorright);
				red[y] = colorright[0];
				green[y] = colorright[1];
				blue[y] = colorright[2];
				y = y + 1;
				writeDebugStreamLine( "%d", y);
				wait10Msec(10);
			}
			if(y == 100)
			{
				for (int j = 0; j<100; j++)
				{
					writeDebugStreamLine( "%d", red[j]);
				}
				writeDebugStreamLine( "________________");
				for (int j = 0; j<100; j++)
				{
					writeDebugStreamLine( "%d", green[j]);
				}
				writeDebugStreamLine( "________________");
				for (int j = 0; j<100; j++)
				{
					writeDebugStreamLine( "%d", blue[j]);
				}
				y = 101;
			}
		}
	}
}
