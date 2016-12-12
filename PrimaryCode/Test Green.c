#define Jagdeep
#include "source.h"
#include "initialize sensors.c"

task main()
{
	initialize();
short colorarray[3];
float redRatio = 0;
float blueRatio = 0;
float red = 0;
float green = 0;
float blue = 0;
while (1)
{
	getColorSensorData(colorRight, colorRaw, colorarray);
	nxtDisplayTextLine(1, "%f", colorarray[0]);
	nxtDisplayTextLine(2, "%f", colorarray[1]);
	nxtDisplayTextLine(3,"%f", colorarray[2]);
	red = colorarray[0];
	green = colorarray[1];
	blue = colorarray[2];
	redRatio = red/green;
	blueRatio = blue/green;
	nxtDisplayTextLine(5,"%f", redRatio);
	nxtDisplayTextLine(6,"%f", blueRatio);
	if(blueRatio < .875 && redRatio < .95)
		nxtDisplayTextLine(7,"I SEE GREEN");

else
	nxtDisplayTextLine(7,"NO SUCH LUCK :(");



}

}
