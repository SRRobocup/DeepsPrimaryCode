#include "Common Functions.c"

void wallAdjust()
{
	int oldValue = 0;
	int currentValue = 1;
	int count = 0;
	SensorType[distForward] = sensorSONAR;
	while (1)
	{
		oldValue = SensorValue[distForward];
		degTurn(1, 40);
		currentValue = SensorValue[distForward];
		if (currentValue > oldValue)
		{
			degTurn(-(count/2), 40);
			break;
		}
		if(currentValue == oldValue)
		{
			count = count + 1;
		}
		else
		{
			count = 1;
		}
	}
	count = 0;
	SensorType[distForward] = sensorSONAR;
	while (1)
	{
		oldValue = SensorValue[distForward];
		degTurn(-1, 40);
		currentValue = SensorValue[distForward];
		if (currentValue > oldValue)
		{
			degTurn((count/2), 40);
			break;
		}
		if(currentValue == oldValue)
		{
			count = count + 1;
		}
		else
		{
			count = 1;
		}
	}

}
