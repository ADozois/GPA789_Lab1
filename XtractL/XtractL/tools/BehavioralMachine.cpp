#include "BehavioralMachine.h"


#include "BehavioralState.h"
#include "BehavioralTransition.h"
//#include <algorithm>
//#include <stdexcept>
//
//#include "State.h"
//#include "Transition.h"
//#include "BehavioralState.h"
//#include "BehavioralTransition.h"
//#include "TransitionOStream.h"
 
//string FiniteStateMachine::mNoStateName{ "-no current state-" };


BehavioralMachine::BehavioralMachine()
	: FiniteStateMachine()
{
}

//
//
//void FiniteStateMachine::addState(State * state)
//{
//	if (!state) {
//		throw invalid_argument("FiniteStateMachine::addState : state arguments must be defined.");
//	}
//
//	if (find(mStates.begin(), mStates.end(), state) != mStates.end()) {
//		return;
//	}
//
//	mStates.push_back(state);
//}
//void FiniteStateMachine::setInitialState(State * initState)
//{
//	if (!initState) {
//		mInitialState = nullptr;
//		throw invalid_argument("FiniteStateMachine::setInitialState : initState arguments must be defined.");
//	}
//
//	if (find(mStates.begin(), mStates.end(), initState) == mStates.end()) {
//		mInitialState = nullptr;
//		throw invalid_argument("FiniteStateMachine::setInitialState : initState arguments must exist in the previously inserted states.");
//	}
//
//	mInitialState = initState;
//}


//
//void FiniteStateMachine::setStream(ostream * stream)
//{
//	for (auto const & state : mStates) {
//		for (auto const & transition : state->mTransitions) {
//			TransitionOStream * oStreamTransition = dynamic_cast<TransitionOStream*>(transition);
//			if (oStreamTransition) {
//				oStreamTransition->setStream(stream);
//			}
//		}
//	}
//}
//
void BehavioralMachine::resetBehavioralStates()
{
	for (auto const & state : mStates) {
		BehavioralState * behavioralState = dynamic_cast<BehavioralState*>(state);
		if (behavioralState) {
			behavioralState->reset();
		}
	}
}

void BehavioralMachine::resetBehavioralTransitions()
{
	for (auto const & state : mStates) {
		for (auto const & transition : state->transitions()) {
			BehavioralTransition * behavioralTransition = dynamic_cast<BehavioralTransition*>(transition);
			if (behavioralTransition) {
				behavioralTransition->reset();
			}
		}
	}
}

void BehavioralMachine::start()
{
	FiniteStateMachine::start();

	resetBehavioralStates();
	resetBehavioralTransitions();
}
bool BehavioralMachine::stop()
{
	return FiniteStateMachine::stop();
}

void BehavioralMachine::processBehavioralTransition(Transition * transition, symbol_t curSymbol)
{
	BehavioralTransition * behavioralTransition = dynamic_cast<BehavioralTransition*>(transition);
	if (behavioralTransition) {
		behavioralTransition->process(mPreviousSymbol, curSymbol);
	}
}

void BehavioralMachine::exitCurrentBehavioralState(symbol_t curSymbol)
{
	BehavioralState * behavioralState = dynamic_cast<BehavioralState*>(mCurrentState);
	if (behavioralState) {
		behavioralState->exiting(mPreviousSymbol, curSymbol);
	}
}

void BehavioralMachine::enterProcessCurrentBehavioralState(symbol_t curSymbol)
{
	BehavioralState * behavioralState = dynamic_cast<BehavioralState*>(mCurrentState);
	if (behavioralState) {
		behavioralState->entering(mPreviousSymbol, curSymbol);
		behavioralState->doing(mPreviousSymbol, curSymbol);
	}
}

void BehavioralMachine::processCurrentBehavioralState(symbol_t curSymbol)
{
	BehavioralState * behaviorState = dynamic_cast<BehavioralState*>(mCurrentState);
	if (behaviorState) {
		behaviorState->doing(mPreviousSymbol, curSymbol);
	}
}

void BehavioralMachine::processSymbol(symbol_t curSymbol)
{
	if (mRunning) {
		Transition * transition = mCurrentState->isTransiting(curSymbol);
		if (transition) {
			//if (mCurrentState == &transition->nextState()) {
			//	processBehavioralTransition(transition, curSymbol);
			//} else {
				exitCurrentBehavioralState(curSymbol);

				processBehavioralTransition(transition, curSymbol);

				mCurrentState = &transition->nextState();
				if (!mCurrentState) {
					throw logic_error("FiniteStateMachine::processSymbol :\nFSM current state is undefined!");
				}

				enterProcessCurrentBehavioralState(curSymbol);
			// }
		} else {
			processCurrentBehavioralState(curSymbol);
		}

		mPreviousSymbol = curSymbol;
	}
}

//string FiniteStateMachine::currentStateName() const
//{
//	if (!mCurrentState) {
//		return mNoStateName;
//	}
//
//	return mCurrentState->name();
//}
//
//
//void FiniteStateMachine::deleteState(State * & state)
//{
//	delete state;
//}
