
function ZigZagX(var* Data,var Depth,int Length,long Color)
{
#ifndef _DEBUG
	#define _Dir		v[0]	
	#define _LastBar	v[1]	
	#define _HighBar	v[2]	
	#define _LowBar	v[3]	
	#define _LastPrice v[4]	
	#define _HighPrice v[5]
	#define _LowPrice	v[6]
	#define _Length	v[7]
	#define _Slope		v[8]
	vars v = series(0,-9);
#else
	static var _Dir,_LastBar,_HighBar,_LowBar,
		_LastPrice,_HighPrice,_LowPrice,_Slope,_Length;
#endif
	SETSERIES(Data,0);
	var Price = Data[0];

	if(IS(FIRSTRUN)) {
		_HighPrice = Price;
		_LowPrice = Price;
		_LastPrice = Price;
		_LastBar = _HighBar = _LowBar = g->nBar;
		_Dir = 0;
		if(Color) {
			plotGraph("ZigZag",0,_LastPrice,LINE,Color);
			plotGraph("ZigZag",0,_LastPrice,LINE+END,Color);
		}
		g->vLength = 1;
		return g->vSign = g->vPeak = g->vSlope = 0;
	}

// check for up-swing > threshold and down-swing > threshold
	if(_Dir >= 0) 
	{
		if(Price > _HighPrice) { // new high pivot
			/*_LowPrice =*/ _HighPrice = Price;
			/*_LowBar =*/ _HighBar = g->nBar;
		}
// store first low pivot after the high pivot
		else if(Price < _LowPrice) { 
			_LowPrice = Price;
			_LowBar = g->nBar;
		}
		if(_HighPrice - _LastPrice >= Depth
			&& _HighPrice - Price >= Depth
			&& g->nBar - _HighBar >= Length)
		{				
// Up-swing ended, now move down
			if(Color) {
				plotGraph("ZigZag",g->nBar-_LastBar,_LastPrice,LINE,Color);
				plotGraph("ZigZag",g->nBar-_HighBar,_HighPrice,LINE+END,Color);
			}
// store the slope of the up-swing
			_Length = _HighBar-_LastBar;
			_Slope = (_HighPrice-_LastPrice)/_Length;
// The high becomes a new pivot, and _Dir changes to a down-swing
			_LowBar = _LastBar = _HighBar;
			_LowPrice = _LastPrice = _HighPrice;
			_Dir = -1;
		}
	}

	if(_Dir <= 0) // can happen in the same bar
	{
		if(Price < _LowPrice) {
			_LowPrice = /*_HighPrice =*/ Price;
			_LowBar = /*_HighBar =*/ g->nBar;
		}
		else if(Price > _HighPrice) {
			_HighPrice = Price;
			_HighBar = g->nBar;
		}
		if(_LastPrice - _LowPrice > Depth
			&& Price - _LowPrice > Depth
			&& g->nBar - _LowBar >= Length)
		{
			if(Color) {
				plotGraph("ZigZag",g->nBar-_LastBar,_LastPrice,LINE,Color);
				plotGraph("ZigZag",g->nBar-_LowBar,_LowPrice,LINE+END,Color);
			}				
			_Length = _LowBar-_LastBar;
			_Slope = (_LowPrice-_LastPrice)/_Length;
			_HighBar = _LastBar = _LowBar;
			_HighPrice = _LastPrice = _LowPrice;
			_Dir = 1;

// fix high price in case the current price was already a high pivot
			if(Price > _HighPrice) {
				_HighPrice = Price;
				_HighBar = g->nBar;
			}
		} 
	}

	g->vLength = _Length;
	g->vPeak = g->nBar-_LastBar;
	g->vSign = _Dir;
	return g->vSlope = _Slope;	
}