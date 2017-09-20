#include "MatchAllSymbols.h"

//bool MatchAllSymbols::isMatching([[maybe_unused]] symbol_t symbol) const
bool MatchAllSymbols::isMatching(symbol_t symbol) const
{
	return true; 
}

MatchSymbol* MatchAllSymbols::clone() const 
{ 
	return new MatchAllSymbols(); 
}
