// Trend Experiment - Lowpass
#include "Strategy\Trend.c"

var filter(var* Data,int Period)
{
	return LowPass(Data,Period);
}