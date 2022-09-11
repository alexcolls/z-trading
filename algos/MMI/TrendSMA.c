// Trend Experiment - SMA
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return SMA(Data,checkLookBack(Period));
}