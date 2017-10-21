#include "AutomatonCppLiteralExtraction.h"

#include "State.h"
#include "MatchAllSymbols.h"
#include "MatchListSymbols.h"
#include "MatchRangeSymbols.h"
#include "MatchSingleSymbol.h"
#include "MatchNotSingleSymbol.h"
#include "MatchNotListSymbols.h"
#include "MatchListRangeSymbol.h"

#include "TransducerActionOStatic.h"
#include "TransducerActionODynamic.h"
#include "TransducerActionOFileLineNum.h"

AutomatonCppLiteralExtraction::AutomatonCppLiteralExtraction(AutomatonFileStatExtraction const & automatonFileStateExtraction) {
	createStates();
	createTransitions(automatonFileStateExtraction);
	assignTransitions();
	addStates();
	assignInitialState();
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

	//New state implement
	sNumericValue = new State("Numeric value char", false);
	sDirectFloat = new State("Direct Float", false);
	sFloatNumber = new State("Float number char", false);
	sDeclaration = new State("Declaration char", false);
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
	tStringEnter = new TransitionTransducer("String enter", new MatchSingleSymbol('\"'), new TransducerActionOFileLineNum(obj, "Ligne ", "\n\""), *sString);
	tStringEscapeCharEnter = new TransitionTransducer("String escape character", new MatchSingleSymbol('\\'), new TransducerActionOStatic("\\"), *sStringEscapeChar);
	tStringEscapeCharExit = new TransitionTransducer("String escape character", new MatchAllSymbols(), new TransducerActionODynamic(), *sString);
	tStringExit = new TransitionTransducer("String exist", new MatchSingleSymbol('\"'), new TransducerActionODynamic(), *sCode);
	tStringChar = new TransitionTransducer("String character", new MatchNotListSymbols({'\\','\"','\n'}), new TransducerActionODynamic(), *sString);

	//Char
	tCharacterEnter = new TransitionTransducer("Char enter", new MatchSingleSymbol('\''), new TransducerActionOFileLineNum(obj, "Ligne ", "\n'"), *sCharacter);
	tCharacterEscapeCharEnter = new TransitionTransducer("Char escape char enter", new MatchSingleSymbol('\\'), new TransducerActionOStatic("\\"), *sCharacterEscapeChar);
	tCharacterEscapeCharExit = new TransitionTransducer("Char escape char exit", new MatchAllSymbols(), new TransducerActionODynamic(), *sCharacter);
	tCharacterExit = new TransitionTransducer("Char exit", new MatchListSymbols({ '\'','\n' }), new TransducerActionODynamic(), *sCode);
	tCharacterChar = new TransitionTransducer("Character char", new MatchNotListSymbols({ '\\','\'','\n' }), new TransducerActionODynamic(), *sCharacter);

	//Interger
	tNumericNumberEnter = new TransitionTransducer("Numeric Number enter", new MatchListRangeSymbol({ { '-' }, { '0','9' } }), new TransducerActionOFileLineNum(obj, "Ligne ", "\n"), *sNumericValue);
	tNumericNumberChar = new TransitionTransducer("Numeric Number Char", new MatchListRangeSymbol({ {'0','9'}, {'a','f'},{'A','F'},{'x'},{'X'} }), new TransducerActionODynamic(), *sNumericValue);
	//TODO tNumericNumberExit MatcNotListSymbol
	tNumericFloatEnter = new TransitionTransducer("Numeric Float Enter", new MatchSingleSymbol('.'), new TransducerActionOStatic("."), *sFloatNumber);

	//Float
	tFloatEnter = new TransitionTransducer("Float enter", new MatchRangeSymbols('0', '9'), new TransducerActionOFileLineNum(obj, "Ligne ", "\n"), *sFloatNumber);
	tFloatChar = new TransitionTransducer("Float char", new MatchListRangeSymbol({ {'0','9'},{'f'},{'F'} }), new TransducerActionODynamic(), *sFloatNumber);

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

uint32_t AutomatonCppLiteralExtraction::integerCount(void) const {
	throw("Not implemented TODO!!!!");
	//TODO implementer une fois les transition definie (integer)
}

uint32_t AutomatonCppLiteralExtraction::floatCount(void) const {
	throw("Not implemented TODO!!!!");
	//TODO implementer une fois les transition definie (float)
}