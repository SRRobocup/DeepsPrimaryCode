//=====================================================
//Source Code
//=====================================================
#ifndef __SOURCEH__
#define __SOURCEH__
//=====================================================
//For Everyone
//=====================================================
const int colorLeft = S1;
const int lightForward = S2;
const int colorRight = S3;
const int distForward = S4;
const int LM = motorB;
const int RM = motorC;
const int BM = motorA;
float Buffer = 4;
//=====================================================
//For Jagdeep
//=====================================================
#ifdef Jagdeep
float white = 76.0 ;
float black = 50;
float silver = 90 ;
float wheelbase = 20;
float diameter = 3.0;
float diameter2 = 3.5;
float EncPerDeg = wheelbase/diameter;
int Name = 1;
void doSilver();
void getPIDParameters(float greenLeft, float greenRight, float lightValue, int intersection, float *error, float *kp, float *forward);
int returnIntersectionPID(float greenLeft, float greenRight, float lightValue);
void runAlgorithm(float LRatio1, float LRatio2, float RRatio1, float RRatio2);
void runIterationPID(float error, float KP, float forward, float KI, float KD);
float getLeftError(float green);
float getRightError(float green);
float getLightError(float light);
float getLeftPlusLightError(float green, float lightValue);
float getRightPlusLightError(float green, float lightValue);
float combineErrors(float green, float lightValue);
void initializePID(float LGreenUp, float LGreenDown, float RGreenUp, float RGreenDown, float LightUp, float LightDown);
void resetPIDValues(void);
float checkGreen(float LRatio1, float LRatio2, float RRatio1, float RRatio2);
float cmForward (float cm, int pwr);
float degTurn (float deg, int pwr);
void PwrLvlCalc (float *ipwr, float objdia, float opwr);
int SonarValInsertionSort(int Sensor);
void calibrate(float*LRatio1, float*LRatio2, float*RRatio1, float*RRatio2, float*LGreenUp, float*LGreenDown, float*RGreenUp, float*RGreenDown, float*LightUp, float*LightDown);
int doObstacle();
int gapCount(int intersection);
float getRightLowAverageThresh();
float getLeftLowAverageThresh();
float getLeftAverageThresh();
float getRightAverageThresh();
float getLightAverageThresh();
float getSlope();
float getIntercept();
void thirdRoom();

#endif
//=====================================================
//For Andrew
//=====================================================
#ifdef Andrew
float white = 76.0 ;
float silver = 90 ;
float black = 50;
float wheelbase = 14;
float diameter = 3.5;
float EncPerDeg = wheelbase/diameter;
int Name = 2;
#endif
//=====================================================
//For John
//=====================================================
#ifdef John
float white = 76.0 ;
float silver = 90 ;
float black = 50;
float wheelbase = 15;
float diameter = 3.5;
float EncPerDeg = wheelbase/diameter;
int Name = 1;
#endif
//=====================================================
//For Everyone
//=====================================================


#endif
