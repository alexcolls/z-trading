// Trend Experiment - ZMA
#include "Strategy\Trend.c"

var filter(var* Data,int Period)
{
	return ZMA(Data,Period);
}