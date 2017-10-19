
#ifndef MATCH_NOT_LIST_RANGE_SYMBOL_H
#define MATCH_NOT_LIST_RANGE_SYMBOL_H

#include "MatchListRangeSymbol.h"

class MatchNotListRangeSymbol: public MatchListRangeSymbol
{
public:
	MatchNotListRangeSymbol()=delete;
	MatchNotListRangeSymbol(symbol_t symbol);
	MatchNotListRangeSymbol(symbol_t firstSymbol, symbol_t lastSymbol);
	MatchNotListRangeSymbol(std::list<RangeSymbol> listRange);
	~MatchNotListRangeSymbol();

	virtual bool isMatching(symbol_t symbol) const override;

	virtual MatchSymbol * clone() const override;
};



#endif // !MATCH_NOT_LIST_RANGE_SYMBOL_H



