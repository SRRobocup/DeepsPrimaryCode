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
	float radius = diameter/2;
	encoders = cm/((radius * radius * PI)/360);
	nMotorEncoder[RM] = 0;
	if (encoders > 0)
	{
		while (nMotorEncoder[RM] < encoders)
		{
			motor[RM] = pwr;
			motor[LM] = pwr;
			DisplayTextLine(5,"%f",nMotorEncoder[RM]);

		}
	}
	else
	{
		while (nMotorEncoder[RM] > encoders)
		{
			motor[RM] = -pwr;
			motor[LM] = -pwr;
			DisplayTextLine(5,"%f",nMotorEncoder[RM]);

		}
	}
	motor[RM] = 0;
	motor[LM] = 0;
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
	float circum = (wheelbase/2)*(wheelbase/2)*(PI); //Calculates the circumference of the circle created when rotating you robot.
	float rotations = circum/ (diameter * PI); //Calculates how many times ONE wheel must rotate to complete a circle.
	float totalEncoder = rotations * 360; //Turns the previous value into encoders.
	float travelDistance = totalEncoder * (deg/360); //calculates the amount of encoders needed to travel for one wheel for deg. turn.
	nMotorEncoder [RM] = 0;
	if (deg > 0)
	{
		while (nMotorEncoder [RM] < (travelDistance/2)) //Two wheels = half the travel distance.
		{
			motor[RM] = pwr;
			motor[LM] = -pwr;
		}
		return (0);
	}
	else
	{
		while (nMotorEncoder [RM] > (travelDistance/2)) //Two wheels = half the travel distance.
		{
			motor[RM] = -pwr;
			motor[LM] = pwr;
		}
		return (0);
	}

}
