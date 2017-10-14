#include "AutomatonCppLiteralExtraction.h"

#include "State.h"
#include "MatchAllSymbols.h"
#include "MatchListSymbols.h"
#include "MatchRangeSymbols.h"
#include "MatchSingleSymbol.h"
#include "MatchNotSingleSymbol.h"
#include "MatchNotListSymbols.h"

AutomatonCppLiteralExtraction::AutomatonCppLiteralExtraction() {
}

AutomatonCppLiteralExtraction::~AutomatonCppLiteralExtraction() {
}

void AutomatonCppLiteralExtraction::createStates(void) {
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
	//TODO implementer les states pour Interger et Float
}

void AutomatonCppLiteralExtraction::createTransitions(AutomatonFileStatExtraction  const & obj) {
	// Code et Slash
	tSlashEnter = new Transition("Slash enter", new MatchSingleSymbol('/'), *sSlash);
	tSlashExit = new Transition("Slash exit", new MatchListSymbols({ '*','/' }), *sCode);
	
	//C comment style
	tCStyleCommentEnter = new TransitionCounter("C style comment enter", new MatchSingleSymbol('*'), *sCStyleComment);
	tCStyleCommentChar = new Transition("C style comment char", new MatchNotSingleSymbol('*'), *sCStyleComment);
	tCStyleCommentStarEnter = new Transition("C star comment enter", new MatchSingleSymbol('*'), *sCStyleCommentStar);
	tCStyleCommentStarAgain = new Transition("C star comment again", new MatchSingleSymbol('*'), *sCStyleCommentStar);
	tCStyleCommentStarExit = new Transition("C star comment exit", new MatchNotListSymbols({ '*','/' }), *sCStyleComment);
	tCStyleCommentExit = new Transition("C style commnent exit", new MatchSingleSymbol('/'), *sCode);
	
	//C++ comment style
	tCppStyleCommentEnter = new TransitionCounter("Cpp style comment enter", new MatchSingleSymbol('/'), *sCppStyleComment);
	tCppStyleCommentChar = new Transition("Cpp style comment char", new MatchNotListSymbols({ '\\', '\n' }), *sCppStyleComment);
	tCppStyleCommentEscapeCharEnter = new Transition("Cpp style comment escape character enter", new MatchSingleSymbol('\\'), *sCppStyleCommentEscapeChar);
	tCppStyleCommentEscapeCharExit = new Transition("Cpp style comment escape character exit", new MatchAllSymbols(), *sCppStyleComment);
	tCppStyleCommentExit = new Transition("Cpp style comment character exit", new MatchSingleSymbol('\n'), *sCode);
	
	//String 
	tStringEnter = new TransitionCounter("String enter", new MatchSingleSymbol('\"'), *sString);
	tStringEscapeCharEnter = new Transition("String escape character", new MatchSingleSymbol('\\'), *sStringEscapeChar);
	tStringEscapeCharExit = new Transition("String escape character", new MatchAllSymbols(), *sString);
	tStringExit = new Transition("String exist", new MatchSingleSymbol('\"'), *sCode);

	//Char
	tCharacterEnter = new TransitionCounter("Char enter", new MatchSingleSymbol('\''), *sCharacter);
	tCharacterEscapeCharEnter = new Transition("Char escape char enter", new MatchSingleSymbol('\\'), *sCharacterEscapeChar);
	tCharacterEscapeCharExit = new Transition("Char escape char exit", new MatchAllSymbols(), *sCharacter);
	tCharacterExit = new Transition("Char exit", new MatchListSymbols({ '\'','\n' }), *sCode);

	//Interger
	//TODO implementer les transitions

	//Float
	//TODO implementer les transitions
}

void AutomatonCppLiteralExtraction::assignTransitions(void) {
	sCode->addTransition(tSlashEnter);
	sCode->addTransition(tStringEnter);
	sCode->addTransition(tCharacterEnter);

	sSlash->addTransition(tCStyleCommentEnter);
	sSlash->addTransition(tCppStyleCommentEnter);
	sSlash->addTransition(tSlashExit);

	sCStyleComment->addTransition(tCStyleCommentChar);
	sCStyleComment->addTransition(tCStyleCommentStarEnter);

	sCStyleCommentStar->addTransition(tCStyleCommentExit);
	sCStyleCommentStar->addTransition(tCStyleCommentStarAgain);
	sCStyleCommentStar->addTransition(tCStyleCommentStarExit);

	sCppStyleComment->addTransition(tCppStyleCommentChar);
	sCppStyleComment->addTransition(tCppStyleCommentEscapeCharEnter);
	sCppStyleComment->addTransition(tCppStyleCommentExit);

	sCppStyleCommentEscapeChar->addTransition(tCppStyleCommentEscapeCharExit);

	sString->addTransition(tStringEscapeCharEnter);
	sString->addTransition(tStringExit);

	sStringEscapeChar->addTransition(tStringEscapeCharExit);

	sCharacter->addTransition(tCharacterEscapeCharEnter);
	sCharacter->addTransition(tCharacterExit);

	sCharacterEscapeChar->addTransition(tCharacterEscapeCharExit);

	//Interger
	//TODO addTransition interger

	//Float
	//TODO addTransition float
}

void AutomatonCppLiteralExtraction::addStates(void) {
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
	//TODO Pour interger et float
}

void AutomatonCppLiteralExtraction::assignInitialState(void) {
	setInitialState(sCode);
}

uint32_t AutomatonCppLiteralExtraction::cStyleCommentCount(void) const {
	//return sCStyleComment->transitionCount();
	return tCStyleCommentEnter->count();
}

uint32_t AutomatonCppLiteralExtraction::cppStyleCommentCount(void) const {
	return tCppStyleCommentEnter->count();
}

uint32_t AutomatonCppLiteralExtraction::stringCount(void) const {
	return tStringEnter->count();
}

uint32_t AutomatonCppLiteralExtraction::characterCount(void) const {
	return tCharacterEnter->count();
}