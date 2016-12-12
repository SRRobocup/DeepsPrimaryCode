////////////////////////////////////
//What it does: goes forward _ cm	//
//Input:													//
//float cm - centimeters to go		//
//int pwr - power level						//
//Output: None										//
////////////////////////////////////
float cmForward (float cm, int pwr)
{
	float encoders = 0;
	float radius = diameter/2.0;
	encoders = (cm/(diameter * PI)) * 360;
	nMotorEncoder[RM] = 0;
	if (encoders > 0)
	{
		while (nMotorEncoder[RM] < encoders)
		{
			motor[RM] = pwr;
			motor[LM] = pwr;

		}
	}
	else
	{
		while (nMotorEncoder[RM] > encoders)
		{
			motor[RM] = -pwr;
			motor[LM] = -pwr;

		}
	}
	motor[RM] = 0;
	motor[LM] = 0;
	resetPIDValues();
	return 0;
}

//////////////////////////////////////////////////////////////
//What it does: turns _ degrees															//
//Input:																										//
//float deg - degrees to turn(positive=left,negative=right)	//
//int pwr - power level																			//
//////////////////////////////////////////////////////////////
float degTurn (float deg, int pwr)
{
	float circum = (wheelbase) * (PI); //Calculates the circumference of the circle created when rotating you robot.
	float rotations = circum/ (diameter * PI); //Calculates how many times ONE wheel must rotate to complete a circle.
	float totalEncoder = rotations * 360; //Turns the previous value into encoders.
	float travelDistance = totalEncoder * (deg/360); //calculates the amount of encoders needed to travel for one wheel for deg. turn.
	nMotorEncoder [RM] = 0;
	if (deg > 0)
	{
		while (nMotorEncoder [RM] < (travelDistance)) //Two wheels = half the travel distance.
		{
			motor[RM] = pwr;
			motor[LM] = -pwr;
		}
		motor[RM] = 0;
		motor[LM] = 0;
		resetPIDValues();
		return (0);
	}
	else
	{
		while (nMotorEncoder [RM] > (travelDistance)) //Two wheels = half the travel distance.
		{
			motor[RM] = -pwr;
			motor[LM] = pwr;
		}
		motor[RM] = 0;
		motor[LM] = 0;
		resetPIDValues();
		return (0);
	}
}

////////////////////////////////////////////////////////
// Synopsis: Calculates power levels for inner motor	//
// int *ipwr: Inner power level **WILL CHANGE**				//
// float objdia: Object Diameter											//
// int opwr: Outer power level												//
// return : Inner power level													//
////////////////////////////////////////////////////////
void PwrLvlCalc (float *ipwr, float objdia, float opwr)
{
	float ratioin=objdia+Buffer*2;//Calculate top of ratio
	float ratioout=ratioin+wheelbase*2;//Calculate bottom of ratio
	float ratiopwrlvl = opwr*(ratioin/ratioout);//Calculate ratio, turn it into a percentage
	*ipwr = ratiopwrlvl;//Change inpwr to the right power level
	//nxtDisplayTextLine(7, "%f", ratioin);
	//nxtDisplayTextLine(6, "%f", *ipwr);
}

///////////////////////////////////////////////////////////
// Synopsis: Gets a sure good value from distance sensor //
// int Sensor - 1 = front, 2 = side											 //
// Return: Sensor Value of specified sensor							 //
///////////////////////////////////////////////////////////
int SonarValInsertionSort(int Sensor)
{
	int list[10];
	for(int x=0;x<10;x++)
	{
		if (Sensor==1)
		{
			list[x] = SensorValue[distForward];
		}
		if (Sensor==2)
		{
			list[x] = SensorValue[distForward];
		}
	}
	int j,k = 1;
	int s=list[1];
	for(int i=1;i<10;i=i+1)
	{
		s=list[i];
		for(j=i;j>0&&j<10&&list[j]<list[j-1];j=j-1)
		{
			if(list[j]<list[j-1])
			{
				list[j]=list[j-1];
			}
			k=j;
			list[k-1]=s;
		}
	}
	return list[4];
}
