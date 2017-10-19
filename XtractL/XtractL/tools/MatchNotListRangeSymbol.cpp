#include "MatchNotListRangeSymbol.h"



MatchNotListRangeSymbol::MatchNotListRangeSymbol(symbol_t symbol):
	MatchListRangeSymbol{symbol}
{
}

MatchNotListRangeSymbol::MatchNotListRangeSymbol(symbol_t firstSymbol, symbol_t lastSymbol):
	MatchListRangeSymbol{firstSymbol, lastSymbol}
{
}

MatchNotListRangeSymbol::MatchNotListRangeSymbol(std::list<RangeSymbol> listRange):
	MatchListRangeSymbol{listRange}
{
}

MatchNotListRangeSymbol::~MatchNotListRangeSymbol()
{
}

bool MatchNotListRangeSymbol::isMatching(symbol_t symbol) const {
	return !MatchListRangeSymbol::isMatching(symbol);
}

MatchSymbol * MatchNotListRangeSymbol::clone() const {
	return new MatchNotListRangeSymbol(mRanges);
}