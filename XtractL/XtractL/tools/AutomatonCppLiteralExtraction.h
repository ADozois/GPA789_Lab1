//! \file AutomatonCppLiteralExtraction.h
//!
//! \brief Définition de la classe AutomatonCppLiteralExtraction.
//! \details Ce fichier fait partie du laboratoire 1 donné dans le cadre du cours 
//! GPA789 : Analyse et conception orientées objet.
//!
//! \version 1.0
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \author Antoine Dozois
//! \author	Guillaume Chabot-Norbet
//!
//! \date 2017
//! \copyright Copyleft

#ifndef LITERAL_EXTRACTION_H
#define LITERAL_EXTRACTION_H

#include "FiniteStateTransducer.h"

class AutomatonFileStatExtraction;

//! \brief		Automate dédié à l'extraction des literaux d'
//!				un fichier du langage C/C++.
//! \details	Cette classe fait partie de la solution XtractC. 
//!
//! Cette classe est grandement basé et inspiré de Automaton
//! CppCommentExtraction
//! 
//! L'automate est complet et autonome.
//! 
//! Plusieurs fonctions permettent de retourner quelques données 
//! statistiques :
//!  - le nombre de d'entier
//!  - le nombre de point flottant
//!  - le nombre de commentaire style C
//!  - le nombre de commentaire style C++
//!  - le nombre de chaînes de caractères (`"abc"`)
//!  - le nombre de caractères (`'a'`)
//! 
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \author		Antoine Dozois
//! \author		Guillaume Chabot-Nobert
//! \version	1.0
//! \date		2017
//! \copyright	Copyleft

class AutomatonCppLiteralExtraction final: public FiniteStateTransducer
{
public:
	AutomatonCppLiteralExtraction();
	~AutomatonCppLiteralExtraction();

	//! Retourne le nombre de commentaire style-C : 
	//! `/* commentaire */`
	uint32_t cStyleCommentCount(void) const;
	//! Retourne le nombre de commentaire style-C++ : 
	//! `// commentaire`
	uint32_t cppStyleCommentCount(void) const;
	//! Retourne le nombre de chaînes de caractères tel 
	//! que défini en C/C++ : `"abc"`
	uint32_t stringCount(void) const;
	//! Retourne le nombre de caractères tel que 
	//! défini en C/C++ : `'a'`
	uint32_t characterCount(void) const;

	//TODO fonction de compteur pour la classe interger et float


private:

	// States reliés à l'état Code
	State * sCode;

	// States reliés à l'état Slash
	State * sSlash;


	// States reliés à l'état CStyleComment
	State * sCStyleComment;
	State * sCStyleCommentStar;

	// States reliés à l'état CppStyleComment
	State * sCppStyleComment;
	State * sCppStyleCommentEscapeChar;

	// States reliés à l'état String
	State * sString;
	State * sStringEscapeChar;

	// States reliés à l'état Char
	State * sCharacter;
	State * sCharacterEscapeChar;

	// States reliés à l'état Entier
	//TODO ajouter les etats pour les entiers

	// States reliés à l'état Point Flottant\
	//TODO ajouter les etats pour les flottants

	// Transition de Code
	Transition * tSlashEnter;
	Transition * tSlashExit;

	TransitionCounter * tCStyleCommentEnter;
	Transition * tCStyleCommentChar;
	Transition * tCStyleCommentStarEnter;
	Transition * tCStyleCommentStarExit;
	Transition * tCStyleCommentStarAgain;
	Transition * tCStyleCommentExit;

	TransitionCounter * tCppStyleCommentEnter;
	Transition * tCppStyleCommentChar;
	Transition * tCppStyleCommentEscapeCharEnter;
	Transition * tCppStyleCommentEscapeCharExit;
	Transition * tCppStyleCommentExit;

	TransitionCounter * tStringEnter;
	//Transition * tStringChar;
	Transition * tStringEscapeCharEnter;
	Transition * tStringEscapeCharExit;
	Transition * tStringExit;

	TransitionCounter * tCharacterEnter;
	//Transition * tCharacterChar;
	Transition * tCharacterEscapeCharEnter;
	Transition * tCharacterEscapeCharExit;
	Transition * tCharacterExit;


	// Private Method
	void createStates(void);
	void createTransitions(AutomatonFileStatExtraction const & automatonFileStatExtraction);
	void assignTransitions(void);
	void addStates(void);
	void assignInitialState(void);

};

#endif //! LITERAL_EXCEPTION_H