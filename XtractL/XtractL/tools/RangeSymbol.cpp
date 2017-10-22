#include "RangeSymbol.h"



RangeSymbol::RangeSymbol(symbol_t oneSymbol):
	mFirstSymbol{oneSymbol},
	mLastSymbol{oneSymbol}
{
}

RangeSymbol::RangeSymbol(symbol_t first, symbol_t last) :
	mFirstSymbol{ first },
	mLastSymbol{ last }
{
}

bool RangeSymbol::isMatching(symbol_t symbol) const{
	if (symbol >= mFirstSymbol && symbol <= mLastSymbol)
	{
		return true;
	}
	return false;
}

symbol_t RangeSymbol::FirstSymbol() {
	return mFirstSymbol;
}

symbol_t RangeSymbol::LastSymbol(){
	return mLastSymbol;
}