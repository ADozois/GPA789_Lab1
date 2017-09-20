//! \file AutomatonCppCommentExtraction.h
//!
//! \brief Définition de la classe AutomatonCppCommentExtraction.
//! \details Ce fichier fait partie du laboratoire 1 donné dans le cadre du cours 
//! GPA789 : Analyse et conception orientées objet.
//!
//! \version 1.0
//!
//! \author Tony Wong, Ph.D.\n
//!		Département de génie de production automatisée\n
//!		École de technologie supérieure\n
//!		tony.wong@etsmtl.ca
//! \author	JC Demers
//!
//! \date 2016
//! \copyright Copyleft

#ifndef AUTOMATON_CPP_COMMENT_EXTRACTION_H
#define AUTOMATON_CPP_COMMENT_EXTRACTION_H


#include "FiniteStateTransducer.h"

class AutomatonFileStatExtraction;

#include <cstdint>
#include <ostream>
using namespace std;


//! \brief		Automate dédié à l'extraction des commentaires d'
//!				un fichier du langage C/C++.
//! \details	Cette classe fait partie de la solution XtractC. 
//! 
//! Elle correspond à l'implémentation de l'automate 
//! intitulé 'C++ Comment Extraction Automaton' présenté sur 
//! le schéma de conception présenté 
//! <a href="Automates_ExtractionCommentairesCpp.png" target="_blank">ici</a>.
//! 
//! L'automate est complet et autonome.
//! 
//! Plusieurs fonctions permettent de retourner quelques données 
//! statistiques :
//!  - le nombre de commentaire style C
//!  - le nombre de commentaire style C++
//!  - le nombre de chaînes de caractères (`"abc"`)
//!  - le nombre de caractères (`'a'`)
//! 
//! Ces fonctions tiennent compte de l'état courant de l'automate 
//! et des caractères qui ont été traités jusqu'à ce moment.
//! 
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class AutomatonCppCommentExtraction final : public FiniteStateTransducer
{
public:
	//! Constructeur par défaut.
	AutomatonCppCommentExtraction(AutomatonFileStatExtraction const & automatonFileStatExtraction);
	//AutomatonCppCommentExtraction(FSMFileStatistics const & mFileStatistics, int linePaddingLength);
	AutomatonCppCommentExtraction(AutomatonCppCommentExtraction const &) = delete;
	AutomatonCppCommentExtraction(AutomatonCppCommentExtraction const &&) = delete;
	AutomatonCppCommentExtraction& operator=(AutomatonCppCommentExtraction const &) = delete;
	AutomatonCppCommentExtraction& operator=(AutomatonCppCommentExtraction const &&) = delete;
	//! Destructeur par défaut.
	~AutomatonCppCommentExtraction() = default;

	//! Retourne le nombre de commentaire style-C : 
	//! `/* commentaire */`
	uint32_t cStyleCommentCount() const;
	//! Retourne le nombre de commentaire style-C++ : 
	//! `// commentaire`
	uint32_t cppStyleCommentCount() const;
	//! Retourne le nombre de chaînes de caractères tel 
	//! que défini en C/C++ : `"abc"`
	uint32_t stringCount() const;
	//! Retourne le nombre de caractères tel que 
	//! défini en C/C++ : `'a'`
	uint32_t characterCount() const;

private:
	State * sCode;
	State * sSlash;
	State * sCStyleComment;
	State * sCStyleCommentStar;
	State * sCppStyleComment;
	State * sCppStyleCommentEscapeChar;
	State * sString;
	State * sStringEscapeChar;
	State * sCharacter;
	State * sCharacterEscapeChar;

	//Transition * tCodeChar;
	Transition * tSlashEnter;
	Transition * tSlashExit;

	TransitionTransducer * tCStyleCommentEnter;
	TransitionTransducer * tCStyleCommentChar;
	TransitionTransducer * tCStyleCommentStarEnter;
	TransitionTransducer * tCStyleCommentStarExit;
	TransitionTransducer * tCStyleCommentStarAgain;
	TransitionTransducer * tCStyleCommentExit;

	TransitionTransducer * tCppStyleCommentEnter;
	TransitionTransducer * tCppStyleCommentChar;
	TransitionTransducer * tCppStyleCommentEscapeCharEnter;
	TransitionTransducer * tCppStyleCommentEscapeCharExit;
	TransitionTransducer * tCppStyleCommentExit;

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

	void createStates();
	void createTransitions(AutomatonFileStatExtraction const & automatonFileStatExtraction);
	void assignTransitions();
	void addStates();
	void assignInitialState();
};


#endif // AUTOMATON_CPP_COMMENT_EXTRACTION_H
