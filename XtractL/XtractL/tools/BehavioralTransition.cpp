#include "BehavioralTransition.h"



BehavioralTransition::BehavioralTransition(string const & name, MatchSymbol * matchSymbol, State & nextState)
	: Transition(name, matchSymbol, nextState)
{
}



