#include "MatchRangeSymbols.h"



MatchRangeSymbols::MatchRangeSymbols(symbol_t fisrtSymbol, symbol_t lastSymbol):
	range{new RangeSymbol(fisrtSymbol, lastSymbol)}
{
}

MatchRangeSymbols::MatchRangeSymbols(symbol_t symbol) :
	range{ new RangeSymbol(symbol) }
{
}

MatchRangeSymbols::~MatchRangeSymbols() {
	delete range;
}


bool MatchRangeSymbols::isMatching(symbol_t symbol) const {
	return range->isMatching(symbol);
}

MatchSymbol* MatchRangeSymbols::clone(void) const {
	return new MatchRangeSymbols(range->FirstSymbol(), range->LastSymbol());
}

