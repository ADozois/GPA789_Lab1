#include "Transition.h"


#include <stdexcept>
using namespace std;

#include "MatchSymbol.h"


Transition::Transition(string const & name, MatchSymbol * matchSymbol, State & nextState)
	:	mName{ name },
		mMatchSymbol{ matchSymbol },
		mNextState{ nextState }
{
	if (!matchSymbol) {
		throw invalid_argument("Transition::Transition : Invalid constructor argument - matchSymbol must be assigned.");
	}
}

Transition::Transition(const Transition & obj)
	:	mName { obj.mName },
		mMatchSymbol{ obj.mMatchSymbol },
		mNextState{ obj.mNextState }
{
	if (!obj.mMatchSymbol)
	{
		throw invalid_argument("Transition::Transition : Invalid constructor argument - matchSymbol must be assigned.");
	}
}



Transition::~Transition()
{
	delete mMatchSymbol;
}

bool Transition::isTransiting(symbol_t symbol) const
{
	return mMatchSymbol->isMatching(symbol);
}


