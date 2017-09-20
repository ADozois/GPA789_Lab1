//! \file TransducerAction.h
//!
//! \brief Définition de la classe TransducerAction.
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

#ifndef TRANSDUCER_ACTION_H
#define TRANSDUCER_ACTION_H

#include "Symbol.h"

//! \brief		Classe abstraite représentant l'action d'une transition d'un 
//!				__TF__.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet de créer une interface commune pour tous 
//! les types d'action à manipuler. Elle sert de classe utilitaire 
//! permettant d'effectuer une action spécifique selon les 
//! symboles en traitement. Selon l'implémentation,
//! il est possible de créer des opération plus ou moins complexes 
//! permettant entre autre, d'effectuer une sortie différente de 
//! l'entrée. 
//! 
//! Cette classe est virtuelle pure et ne peut être instanciée.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransducerAction
{
public:
	//! Construit un `TransducerAction`.
	TransducerAction() = default;
	//! Détruit l'objet courant.
	virtual ~TransducerAction() = default;

	//! Cette fonction permet la réinitialisation de l'action à son état 
	//!	initial.
	//!
	//! Cette fonction est virtuelle pure et doit être redéfinie.
	virtual bool reset() = 0;

	//! La fonction process est la fonction de traitement du TF. Cette 
	//!	fonction permet de déterminer quelles sont les actions à effectuer.
	//!
	//! Cette fonction est virtuelle pure et doit être redéfinie.
	//! \param[in] prevSymbol Le symbole précédemment traité.
	//! \param[in] curSymbol Le symbole actuellement traité.
	virtual bool process(symbol_t prevSymbol, symbol_t curSymbol) = 0;

	//! Cette fonction permet d'instancier un objet identique à l'objet 
	//!	courant. Le nouvel objet est alloué dynamiquement et devient la 
	//!	propriété du récepteur. En d'autres termes, la fonction retourne un 
	//!	objet dont la désallocation de la mémoire doit être gérée 
	//! explicitement par un mécanisme externe.
	//!
	//! Cette fonction est virtuelle pure et doit être redéfinie.
	virtual TransducerAction* clone() const = 0;
};


#endif // TRANSDUCER_ACTION_H