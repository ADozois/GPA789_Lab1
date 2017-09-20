#include "BehavioralState.h"


#include "BehavioralTransition.h"


BehavioralState::BehavioralState(string const & name, bool accepting)
	: State(name, accepting)
{
}

void BehavioralState::reset()
{
	for (auto const & transition : mTransitions) {
		BehavioralTransition * behavioralTransition = dynamic_cast<BehavioralTransition*>(transition);
		if (behavioralTransition) {
			behavioralTransition->reset();
		}
	}
}
