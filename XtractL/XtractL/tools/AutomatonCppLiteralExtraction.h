//! \file AutomatonCppLiteralExtraction.h
//!
//! \brief D�finition de la classe AutomatonCppLiteralExtraction.
//! \details Ce fichier fait partie du laboratoire 1 donn� dans le cadre du cours 
//! GPA789 : Analyse et conception orient�es objet.
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

//! \brief		Automate d�di� � l'extraction des literaux d'
//!				un fichier du langage C/C++.
//! \details	Cette classe fait partie de la solution XtractC. 
//!
//! Cette classe est grandement bas� et inspir� de Automaton
//! CppCommentExtraction
//! 
//! L'automate est complet et autonome.
//! 
//! Plusieurs fonctions permettent de retourner quelques donn�es 
//! statistiques :
//!  - le nombre de d'entier
//!  - le nombre de point flottant
//!  - le nombre de commentaire style C
//!  - le nombre de commentaire style C++
//!  - le nombre de cha�nes de caract�res (`"abc"`)
//!  - le nombre de caract�res (`'a'`)
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
	//! Retourne le nombre de cha�nes de caract�res tel 
	//! que d�fini en C/C++ : `"abc"`
	uint32_t stringCount(void) const;
	//! Retourne le nombre de caract�res tel que 
	//! d�fini en C/C++ : `'a'`
	uint32_t characterCount(void) const;

	//TODO fonction de compteur pour la classe interger et float


private:

	// States reli�s � l'�tat Code
	State * sCode;

	// States reli�s � l'�tat Slash
	State * sSlash;


	// States reli�s � l'�tat CStyleComment
	State * sCStyleComment;
	State * sCStyleCommentStar;

	// States reli�s � l'�tat CppStyleComment
	State * sCppStyleComment;
	State * sCppStyleCommentEscapeChar;

	// States reli�s � l'�tat String
	State * sString;
	State * sStringEscapeChar;

	// States reli�s � l'�tat Char
	State * sCharacter;
	State * sCharacterEscapeChar;

	// States reli�s � l'�tat Entier
	//TODO ajouter les etats pour les entiers

	// States reli�s � l'�tat Point Flottant\
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