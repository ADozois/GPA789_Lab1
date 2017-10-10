//! \file AutomatonFileStatExtraction.h
//!
//! \brief Définition de la classe AutomatonFileStatExtraction.
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

#ifndef FSM_LINE_COUNTER_H
#define FSM_LINE_COUNTER_H


#include "BehavioralMachine.h"
#include <cstdint>

//class State;
class TransitionCounter;


//! \brief		Automate dédié à l'extraction de statistiques simples 
//!				concernant un fichier texte.
//! \details	Cette classe fait partie de la solution XtractC. 
//! 
//! Elle correspond à l'implémentation de l'automate 
//! intitulé 'File Statistics Extraction Automaton' présenté sur 
//! le schéma de conception présenté 
//! <a href="Automates_ExtractionCommentairesCpp.png" target="_blank">ici</a>.
//! 
//! L'automate est complet et autonome.
//! 
//! Plusieurs fonctions permettent de retourner quelques données 
//! statistiques :
//!  - est-ce que le fichier est vide
//!  - combien de lignes
//!  - combien d'espaces (espace et tabulation)
//!  - combien d'autres caractères (excluant les sauts de 
//! 	ligne, espace et tabulation)
//! 
//! Ces fonctions tiennent compte de l'état courant de l'automate 
//! et des caractères qui ont été traités jusqu'à ce moment.
//! 
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class AutomatonFileStatExtraction final : public BehavioralMachine
{
public:
	//! Contructeur par défaut.
	AutomatonFileStatExtraction();
	AutomatonFileStatExtraction(AutomatonFileStatExtraction const &) = delete;
	AutomatonFileStatExtraction(AutomatonFileStatExtraction const &&) = delete;
	AutomatonFileStatExtraction& operator=(AutomatonFileStatExtraction const &) = delete;
	AutomatonFileStatExtraction& operator=(AutomatonFileStatExtraction const &&) = delete;
	//! Destructeur par défaut.
	~AutomatonFileStatExtraction() = default;

	//! Retourne si le fichier est vide.
	bool isFileEmpty() const;
	//! Retourne le nombre de lignes (saut de ligne `\n`).
	uint32_t lineCount() const;
	//! Retourne le nombre d'espaces (espace et tabulation `\t`).
	uint32_t spaceCount() const;
	//! Retourne le nombre d'autres caractères (excluant l'espace, la tabulation `\t` et le saut de ligne `\n`).
	uint32_t characterCount() const;

private:
	State * mEmptyFile;
	State * mInLine;
	TransitionCounter * mStartByLine;
	TransitionCounter * mStartBySpace;
	TransitionCounter * mStartByCharacter;
	TransitionCounter * mLineCounter;
	TransitionCounter * mSpaceCounter;
	TransitionCounter * mCharacterCounter;
};


#endif // FSM_LINE_COUNTER_H
