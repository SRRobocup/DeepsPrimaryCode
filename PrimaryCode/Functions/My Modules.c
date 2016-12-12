#ifndef MyModulesC
#define MyModulesC
#include "./Lib.h"

//=====================================================
// Synopsis: Calculates power levels for inner motor
// int *ipwr: Inner power level **WILL CHANGE**
// float objdia: Object Diameter
// int opwr: Outer power level
// return : Inner power level
//=====================================================
void PwrLvlCalc (int *ipwr, float objdia, int opwr)
{
	wait1Msec(100);
	int ratioin=objdia+Buffer*2;//Calculate top of ratio
	int ratioout=ratioin+Wb*2;//Calculate bottom of ratio
	int ratiopwrlvl = opwr*ratioin/ratioout;//Calculate ratio, turn it into a percentage
	*ipwr = ratiopwrlvl;//Change inpwr to the right power level
}

//=====================================================
// Synopsis: Goes Straight
// int pwrlvl: power level .. -100 to 100
// float distance: cm to go
// return : none
//=====================================================
void Straight (int pwrlvl, float distance)
{
	int target = distance*EncPerCm;
	resetMotorEncoder(LM);
	resetMotorEncoder(RM);
	while (getMotorEncoder(Rm)<target||getMotorEncoder(Lm)<target)
	{
		motor[Rm] = pwrlvl;
		motor[Lm] = pwrlvl;
	}
}

//=====================================================
// Synopsis: Turns Right
// int degrees: Degrees to turn
// int pwrlvl: power level to turn at
// return : none
//=====================================================
void RightTurn(int degrees, int pwrlvl)
{
	int target = (EncPerDeg*degrees);
	resetMotorEncoder(LM);
	resetMotorEncoder(RM);
	while (getMotorEncoder(RM)>-target||getMotorEncoder(LM)<target)
	{
		motor[RM]=-pwrlvl;
		motor[LM]=pwrlvl;
	}
}

//=====================================================
// Synopsis: Turns Left and stop before returns
// int degrees: Degrees to turn
// int pwrlvl: power level to turn at
// return : none
//=====================================================
void LeftTurn(int degrees, int pwrlvl)
{
	int target = (EncPerDeg*degrees);
	resetMotorEncoder(LM);
	resetMotorEncoder(RM);

	setMotorTarget(LM, -target, -pwrlvl);
  setMotorTarget(RM, target, pwrlvl);

  waitUntilMotorStop(LM);
  waitUntilMotorStop(RM);

}

//=====================================================
// Synopsis: Line Traces (needs while in main task
// return : none
//=====================================================
void LineTrace()
{
	if(getColorReflected(S2)<thresh2)
	{
		motor[LM]=75;
		motor[RM]=-50;
	}
	else
	{
		if(getColorReflected(S1)<thresh1)
		{
			motor[RM]=75;
			motor[LM]=-50;
		}
		else
		{
			motor[RM]=75;
			motor[LM]=75;
		}
	}
}

//=====================================================
// Synopsis: Goes around the box 180 degrees
// float objdia: Object Diameter
// return : none
//=====================================================
void AroundBoxHalfway(float objdia)
{
	int deg = 90;
	int inpwr = 0;
	int outpwr = 100;
	int turnpwrlvl = 50;
	PwrLvlCalc(&inpwr,objdia,outpwr);
	RightTurn(deg,turnpwrlvl);
	int innertarget = (objdia+Buffer*2)*EncPerCm/2;
	int outertarget = (objdia+Buffer*2+Wb*2)*EncPerCm/2;
	resetMotorEncoder(LM);
	resetMotorEncoder(RM);
	while (getMotorEncoder(LM)<innertarget||getMotorEncoder(RM)<outertarget)
	{
		motor[LM]=inpwr;
		motor[RM]=outpwr;
	}
	motor[LM]=0;
	motor[RM]=0;
	RightTurn(deg,turnpwrlvl);
}
#endif
