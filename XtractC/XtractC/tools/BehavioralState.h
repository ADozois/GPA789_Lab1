//! \file BehavioralState.h
//!
//! \brief Définition de la classe BehavioralState.
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

#ifndef BEHAVIORAL_STATE_H
#define BEHAVIORAL_STATE_H

#include "State.h"
class BehavioralMachine;


//! \brief		Classe représentant les états d'un automate comportemental 
//!				fini.
//! \details	Cette classe fait partie du module BM (Behavioral Machine).
//! 
//! Cette classe permet de créer une interface commune pour tous 
//! états de l'ACF. L'interface commune réside principalement dans 
//! les fonctions de travail.
//! 
//! Chaque état possède maintenant 4 fonctions permettant de 
//! définir un comportement particulier pour des situations 
//! particulières. C'est la classe FiniteStateMachine qui s'occupe 
//! d'appeler ces fonctions au bon moment. Ces tâches 
//! supplémentaires sont :
//!  - reset : cette fonction est appelée au démarrage de 
//! 	l'automate, c'est à dire lorsque la fonction `start` est 
//! 	appelée.
//!  - entering (fonction virtuelle pure) : cette fonction est 
//! 	appelée lors d'une transition vers l'état courant (après 
//! 	la transition). 
//!  - doing (fonction virtuelle pure) : cette fonction est 
//! 	appelée à chaque traitement de symbole de la part de 
//! 	l'automate avec la fonction `processSymbol` (c'est l'objet 
//! 	de l'état courant qui est appelé). 
//!  - exiting (fonction virtuelle pure) : cette fonction est 
//! 	appelée lors d'une transition vers un nouvel état (l'état 
//! 	courant appel cette fonction juste avant la transition 
//! 	vers le nouvel état). 
//! 
//! Cette classe est virtuelle pure et ne peut être instanciée.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class BehavioralState : public State
{
	friend BehavioralMachine;

public:
	//! Construit un état comportemental.
	//! \param[in] name Le nom d'affichage de l'état. Le nom est obligatoire.
	//! \param[in] accepting Détermine si l'état est un état acceptant.
	BehavioralState(string const & name, bool accepting = false);
	//! Détruit l'objet courant.
	virtual ~BehavioralState() = default;

protected:
	//! Fonction de réinitialisation de l'état.
	virtual void reset();
	//! Fonction d'action lorsque l'état courant devient cet état.
	virtual void entering(symbol_t prevSymbol, symbol_t curSymbol) = 0;
	//! Fonction d'action lorsque l'état courant traite un nouveau symbole.
	virtual void doing(symbol_t prevSymbol, symbol_t curSymbol) = 0;
	//! Fonction d'action lorsque l'état courant quitte cet état.
	virtual void exiting(symbol_t prevSymbol, symbol_t curSymbol) = 0;
};

#endif // BEHAVIORAL_STATE_H