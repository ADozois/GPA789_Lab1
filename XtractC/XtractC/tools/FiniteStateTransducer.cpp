#include "FiniteStateTransducer.h"


#include "State.h"
#include "TransducerActionOStream.h"

FiniteStateTransducer::FiniteStateTransducer()
	: BehavioralMachine()
{
}


void FiniteStateTransducer::setOStream(ostream * oStream)
{
	for (auto const & state : mStates) {
		for (auto const & transition : state->transitions()) {
			TransitionTransducer * transitionTransducer = dynamic_cast<TransitionTransducer*>(transition);
			if (transitionTransducer) {
				TransducerActionOStream * actionOStream = dynamic_cast<TransducerActionOStream *>(transitionTransducer->action());
				if (actionOStream) {
					actionOStream->setOStream(oStream);
				}
			}
		}
	}
}

