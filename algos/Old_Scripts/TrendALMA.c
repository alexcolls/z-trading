// Trend Experiment - ALMA
#include "Strategy\Trend.c"

var filter(var* Data,int Period)
{
	if(Period >= LookBack/TimeFrame) {
		Period = LookBack/TimeFrame;
		g->bDoStep = 0;	// abort optimization
	}
	return ALMA(Data,Period);
}