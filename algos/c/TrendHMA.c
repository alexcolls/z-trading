// Trend Experiment - HMA
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return HMA(Data,checkLookBack(Period));
}