// Trend Experiment - EMA
#include "Strategy\Trend.c"

var filter(var* Data,int Period)
{
	return EMA(Data,2.0/(1+Period));
}