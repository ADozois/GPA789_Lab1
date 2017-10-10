#include "MatchListSymbols.h"

#include <stdexcept>
#include <algorithm>
using namespace std;


MatchListSymbols::MatchListSymbols(list<symbol_t> const & symbols)
	: mSymbols{ symbols }
{
	if (symbols.size() < 1) {
		throw invalid_argument("MatchListSymbols::MatchListSymbols : Invalid constructor argument - symbols must have at least one symbol.");
	}
}

MatchListSymbols::MatchListSymbols(initializer_list<symbol_t> const & symbols)
	: mSymbols{ symbols } 
{
}

bool MatchListSymbols::isMatching(symbol_t symbol) const
{ 
	return find(mSymbols.begin(), mSymbols.end(), symbol) != mSymbols.end();
}

MatchSymbol* MatchListSymbols::clone() const 
{ 
	return new MatchListSymbols(mSymbols); 
}