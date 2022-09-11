// Trend Experiment - Laguerre
#include "Strategy\TrendMMI.c"

var filter(var* Data,int Period)
{
	return Laguerre(Data,4.0/(1+Period));
}