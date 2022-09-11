// Trend Experiment - ZMA
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return ZMA(Data,Period);
}