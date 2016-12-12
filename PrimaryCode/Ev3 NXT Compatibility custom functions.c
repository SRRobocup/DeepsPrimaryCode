/////////////////////////////////////////////////////////////////////
//	Sypnosis: Gets current RGB color Average for both EV3 and NXT  //
//  int sensorside - 1 = left, 2 = right                           //
//  return : Average current RGB Value                             //
/////////////////////////////////////////////////////////////////////
void GetRGB(int sensorside,float *NowR,float *NowG,float *NowB)
{
	short Now[3];
	if (sensorside==1)
	{
#ifdef Ev3
		getColorRGB(colorLeft,*NowR,*NowG,*NowB);
#endif
#ifdef NXT
		getColorSensorData(colorLeft,colorRaw,Now);
		*NowR=Now[0];
		*NowG=Now[1];
		*NowB=Now[2];
#endif
	}
	if (sensorside==2)
	{
#ifdef Ev3
		getColorRGB(colorRight,*NowR,*NowG,*NowB);
#endif
#ifdef NXT
		getColorSensorData(colorRight,colorRaw,Now);
		*NowR=Now[0];
		*NowG=Now[1];
		*NowB=Now[2];
#endif
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Synopsis: returns button state for all buttons on Ev3 and NXT with 1 for pressed and 0 for not  //
//int *Enter- Enter button state																																	//
////////////////////////////////////////////////////////////////////////////////////////////////////
void GetEnterButtonState (int *Enter)
{
#ifdef NXT
	if (nNxtButtonPressed==kEnterButton)
	{
		*Enter=1;
	}
	else
	{
		*Enter=0;
	}
#endif
#ifdef Ev3
	if (getButtonPress(buttonEnter)==1)
	{
		*Enter=1;
	}
	else
	{
		*Enter=0;
	}
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Synopsis: Displays a text line.																																//
// int line = Line to desplay message.																														//
// char yourMessage = Text message to be displayed.																								//
// int variableType = (1)-int, (2)-float																													//
// int variableDisplayed = Variable to be displayed.																							//
// Example: DisplayText(4,"size:",1, mass); --> size: 10 (on line 4, if int mass = 10)						//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DisplayText (int line, char *yourMessage, int variableType, float variableDisplayed)

{
#ifdef NXT
	switch (variableType)
	{
	case 1:
	nxtDisplayTextLine(line, "%s %d", yourMessage, variableDisplayed);
	break;
	case 2:
	nxtDisplayTextLine(line, "%s %f", yourMessage, variableDisplayed);
	break;
	}
#endif


#ifdef Ev3
	switch (variableType)
	{
	case 1:
	DisplayTextLine(line, "%s %d", yourMessage, variableDisplayed);
	break;
	case 2:
	DisplayTextLine(line, "%s %f", yourMessage, variableDisplayed);
	break;
	}
#endif
}
