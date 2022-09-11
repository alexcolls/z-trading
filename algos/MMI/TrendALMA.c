// Trend Experiment - ALMA
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return ALMA(Data,checkLookBack(Period));
}