#define Jagdeep
#include "source.h"
#include "initialize sensors.c"
float value[10];

//**************************************************************************************************************************

float findErr()
{
	float compareValue = 0;
	for (int i = 1; i < 10; i++)
	{
    	compareValue = value[i];
    	for (int j = (i- 1); j > -1; j--)
    	{
        	if(value[j] < compareValue)
        	{
            	j = 0;                                             	// start comparing the next value
        	}
        	else
        	{
            	value[(j + 1)] = value[j];
            	value[j] = compareValue;            	// switch the two
        	}
    	}

	}
	return (value[5]);
}



//**************************************************************************************************************************

task main ()

{
	initialize();
float dist = 0;
clearDebugStream();

while (1)
{
for (int i = 0; i < 9; i++)
{
 value[i] = SensorValue[distForward];
}
dist = findErr();

writeDebugStream("%d\n", dist);
wait10Msec(10);

}
}
