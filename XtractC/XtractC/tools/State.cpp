#include "State.h"

#include <stdexcept>
#include <algorithm>

#include "Transition.h"


State::State(string const & name, bool accepting)
	:	mName{ name }, 
		mAccepting{ accepting }
{
}

State::~State()
{
	for_each(mTransitions.begin(), mTransitions.end(), deleteTransition);
}

void State::addTransition(Transition * transition)
{
	if (transition == nullptr) {
		throw invalid_argument("State::addTransition : Invalid constructor argument - transition must be assigned.");
	}

	mTransitions.push_back(transition);
}

Transition * State::isTransiting(symbol_t curSymbol) const
{
	for (const auto & transition : mTransitions) {
		if (transition->isTransiting(curSymbol)) {
			return transition;
		}
	}

	return nullptr;
}

void State::deleteTransition(Transition * & transition)
{
	delete transition;
}
