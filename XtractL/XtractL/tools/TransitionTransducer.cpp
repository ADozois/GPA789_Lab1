#include "TransitionTransducer.h"




TransitionTransducer::TransitionTransducer(string const & name, MatchSymbol * matchSymbol, TransducerAction * action, State & nextState)
	:	TransitionCounter(name, matchSymbol, nextState),
		mAction{ action }
{
	if (!action) {
		throw invalid_argument("TransitionTransducer::TransitionTransducer : Invalid constructor argument - action must be assigned.");
	}
}

TransitionTransducer::~TransitionTransducer()
{
	delete mAction;
}

void TransitionTransducer::reset()
{
	mAction->reset();
}

void TransitionTransducer::process(symbol_t prevSymbol, symbol_t curSymbol)
{
	TransitionCounter::process(prevSymbol, curSymbol);

	mAction->process(prevSymbol, curSymbol);
}

