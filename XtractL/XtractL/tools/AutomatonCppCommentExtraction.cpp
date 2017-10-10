#include "AutomatonCppCommentExtraction.h"


#include "AutomatonFileStatExtraction.h"

#include "State.h"

#include "MatchAllSymbols.h"
#include "MatchSingleSymbol.h"
#include "MatchNotSingleSymbol.h"
#include "MatchListSymbols.h" 
#include "MatchNotListSymbols.h"

#include "TransducerActionOStatic.h"
#include "TransducerActionODynamic.h"
#include "TransducerActionOFileLineNum.h"

AutomatonCppCommentExtraction::AutomatonCppCommentExtraction(AutomatonFileStatExtraction const & automatonFileStatExtraction)
	: FiniteStateTransducer()
{
	createStates();
	createTransitions(automatonFileStatExtraction);
	assignTransitions();
	addStates();
	assignInitialState();
}

void AutomatonCppCommentExtraction::createStates()
{
	sCode = new State("Code", true);
	sSlash = new State("Slash", false);
	sCStyleComment = new State("C style comment", false);
	sCStyleCommentStar = new State("C style comment star", false);
	sCppStyleComment = new State("C++ style comment", false);
	sCppStyleCommentEscapeChar = new State("C++ style comment escape char", false);
	sString = new State("String", false);
	sStringEscapeChar = new State("String escape char", false);
	sCharacter = new State("Character", false);
	sCharacterEscapeChar = new State("Character escape char", false);
}
//void AutomatonCppCommentExtraction::createTransitions(FSMFileStatistics const & mFileStatistics, int linePaddingLength)
void AutomatonCppCommentExtraction::createTransitions(AutomatonFileStatExtraction const & automatonFileStatExtraction)
{
	tSlashEnter = new Transition(						"Slash enter", 
														new MatchSingleSymbol('/'), 
														*sSlash);
	tSlashExit = new Transition(						"Slash exit", 
														new MatchNotListSymbols({ '*', '/' }), 
														*sCode);

	tCStyleCommentEnter = new TransitionTransducer(		"C style comment enter", 
														new MatchSingleSymbol('*'), 
														//new TransducerActionOStatic("#\n/*"),
														new TransducerActionOFileLineNum(automatonFileStatExtraction, "Ligne ", "\n/*"),
														*sCStyleComment);
	tCStyleCommentChar = new TransitionTransducer(		"C style comment char", 
														new MatchNotSingleSymbol('*'), 
														new TransducerActionODynamic(), 
														*sCStyleComment);
	tCStyleCommentStarEnter = new TransitionTransducer(	"C style comment star enter", 
														new MatchSingleSymbol('*'), 
														new TransducerActionOStatic("*"),
														*sCStyleCommentStar);
	tCStyleCommentStarExit = new TransitionTransducer(	"C style comment char exit", 
														new MatchNotListSymbols({ '*', '/' }), 
														new TransducerActionODynamic(), 
														*sCStyleComment);
	tCStyleCommentStarAgain = new TransitionTransducer(	"C style comment star again", 
														new MatchSingleSymbol('*'), 
														new TransducerActionOStatic("*"),
														*sCStyleCommentStar);
	tCStyleCommentExit = new TransitionTransducer(		"C style comment exit", 
														new MatchSingleSymbol('/'), 
														new TransducerActionOStatic("/\n\n"),
														*sCode);

	tCppStyleCommentEnter = new TransitionTransducer(	"C++ style comment enter", 
														new MatchSingleSymbol('/'), 
														//new TransducerActionOStatic("#\n//"),
														new TransducerActionOFileLineNum(automatonFileStatExtraction, "Ligne ", "\n//"),
														*sCppStyleComment);
	tCppStyleCommentChar = new TransitionTransducer(	"C++ style comment char",
														new MatchNotListSymbols({ '\\', '\n' }), 
														new TransducerActionODynamic(), 
														*sCppStyleComment);
	tCppStyleCommentEscapeCharEnter = new TransitionTransducer("C++ style comment escape char enter",
														new MatchSingleSymbol('\\'), 
														new TransducerActionOStatic("\\"),
														*sCppStyleCommentEscapeChar);
	tCppStyleCommentEscapeCharExit = new TransitionTransducer("C++ style comment escape char exit",
														new MatchAllSymbols(),
														new TransducerActionODynamic(), 
														*sCppStyleComment);
	tCppStyleCommentExit = new TransitionTransducer(	"C++ style comment exit",
														new MatchSingleSymbol('\n'), 
														new TransducerActionOStatic("\n\n"), 
														*sCode);

	tStringEnter = new TransitionCounter(				"String enter",
														new MatchSingleSymbol('\"'), 
														*sString);
	tStringEscapeCharEnter = new Transition(			"String escape character enter",
														new MatchSingleSymbol('\\'), 
														*sStringEscapeChar);
	tStringEscapeCharExit = new Transition(				"String escape character exit",
														new MatchAllSymbols(), 
														*sString);
	tStringExit = new Transition(						"String exit",
														new MatchListSymbols({ '\"', '\n' }), 
														*sCode);

	tCharacterEnter = new TransitionCounter(			"Character enter",
														new MatchSingleSymbol('\''), 
														*sCharacter);
	tCharacterEscapeCharEnter = new Transition(			"Character escape character enter",
														new MatchSingleSymbol('\\'), 
														*sCharacterEscapeChar);
	tCharacterEscapeCharExit = new Transition(			"Character escape character exit",
														new MatchAllSymbols(), 
														*sCharacter);
	tCharacterExit = new Transition(					"Character exit",
														new MatchListSymbols({ '\"', '\n' }), 
														*sCode);

}
void AutomatonCppCommentExtraction::assignTransitions()
{
	sCode->addTransition(tSlashEnter);
	sCode->addTransition(tStringEnter);
	sCode->addTransition(tCharacterEnter);

	sSlash->addTransition(tSlashExit);
	sSlash->addTransition(tCStyleCommentEnter);
	sSlash->addTransition(tCppStyleCommentEnter);

	sCStyleComment->addTransition(tCStyleCommentChar);
	sCStyleComment->addTransition(tCStyleCommentStarEnter);
	sCStyleCommentStar->addTransition(tCStyleCommentStarExit);
	sCStyleCommentStar->addTransition(tCStyleCommentStarAgain);
	sCStyleCommentStar->addTransition(tCStyleCommentExit);

	sCppStyleComment->addTransition(tCppStyleCommentChar);
	sCppStyleComment->addTransition(tCppStyleCommentEscapeCharEnter);
	sCppStyleComment->addTransition(tCppStyleCommentExit);
	sCppStyleCommentEscapeChar->addTransition(tCppStyleCommentEscapeCharExit);

	sString->addTransition(tStringExit);
	sString->addTransition(tStringEscapeCharEnter);
	sStringEscapeChar->addTransition(tStringEscapeCharExit);

	sCharacter->addTransition(tCharacterExit);
	sCharacter->addTransition(tCharacterEscapeCharEnter);
	sCharacterEscapeChar->addTransition(tCharacterEscapeCharExit);
}
void AutomatonCppCommentExtraction::addStates()
{
	addState(sCode);
	addState(sSlash);
	addState(sCStyleComment);
	addState(sCStyleCommentStar);
	addState(sCppStyleComment);
	addState(sCppStyleCommentEscapeChar);
	addState(sString);
	addState(sStringEscapeChar);
	addState(sCharacter);
	addState(sCharacterEscapeChar);
}
void AutomatonCppCommentExtraction::assignInitialState()
{
	setInitialState(sCode);
}


uint32_t AutomatonCppCommentExtraction::cStyleCommentCount() const
{
	return tCStyleCommentEnter->count();
}

uint32_t AutomatonCppCommentExtraction::cppStyleCommentCount() const
{
	return tCppStyleCommentEnter->count();
}

uint32_t AutomatonCppCommentExtraction::stringCount() const
{
	return tStringEnter->count();
}

uint32_t AutomatonCppCommentExtraction::characterCount() const
{
	return tCharacterEnter->count();
}
