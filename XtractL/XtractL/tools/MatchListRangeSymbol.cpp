#include "MatchListRangeSymbol.h"

MatchListRangeSymbol::MatchListRangeSymbol(std::list<RangeSymbol> const & list)
{
	mRanges = list;
}

MatchListRangeSymbol::MatchListRangeSymbol(std::initializer_list<RangeSymbol> const & list)
{
	mRanges = list;
}

MatchListRangeSymbol::~MatchListRangeSymbol()
{
}

bool MatchListRangeSymbol::isMatching(symbol_t symbol) const
{
	for (auto const& range:mRanges)
	{
		if (range.isMatching(symbol))
		{
			return true;
		}
	}
	return false;
}

MatchSymbol* MatchListRangeSymbol::clone() const
{
	return new MatchListRangeSymbol(mRanges);
}
