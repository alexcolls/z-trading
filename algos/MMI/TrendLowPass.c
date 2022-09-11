// Trend Experiment - Lowpass
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return LowPass(Data,Period);
}