// Trend Experiment - SMA
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return LinearReg(Data,checkLookBack(Period));
}