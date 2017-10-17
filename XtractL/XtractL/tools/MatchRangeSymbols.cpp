#include "MatchRangeSymbols.h"



MatchRangeSymbols::MatchRangeSymbols(symbol_t fisrtSymbol, symbol_t lastSymbol):
	mFirstSymbol{fisrtSymbol},
	mLastSymbol{lastSymbol}
{
}

bool MatchRangeSymbols::isMatching(symbol_t symbol) const {
	if (symbol >= mFirstSymbol && symbol <= mLastSymbol) {
		return true;
	}
	return false;
}

MatchSymbol* MatchRangeSymbols::clone(void) const {
	return new MatchRangeSymbols(mFirstSymbol, mLastSymbol);
}

