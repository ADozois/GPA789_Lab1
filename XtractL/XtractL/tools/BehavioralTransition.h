//! \file BehavioralTransition.h
//!
//! \brief Définition de la classe BehavioralTransition.
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

#ifndef BEHAVIORAL_TRANSITION_H
#define BEHAVIORAL_TRANSITION_H

#include "Transition.h"

class BehavioralMachine;
class BehavioralState;


//! \brief		Classe représentant les transitions d'un automate 
//!				comportemental fini.
//! \details	Cette classe fait partie du module BM (Behavioral Machine).
//! 
//! Cette classe permet de créer une interface commune pour toutes 
//! transition de l'ACF. L'interface commune réside principalement dans 
//! les fonctions de travail.
//! 
//! Chaque transition possède maintenant 2 fonctions permettant de définir 
//! un comportement particulier pour des situations particulières. 
//! C'est la classe FiniteStateMachine qui appele ces fonctions au bon 
//! moment. Ces tâches supplémentaires sont :
//!  - reset (fonction virtuelle pure) : cette fonction est appelée 
//! 	au démarrage de l'automate, c'est à dire lorsque la 
//! 	fonction `start` est appelée.
//!  - process (fonction virtuelle pure) : cette fonction est appelée 
//! 	à chaque traitement de symbole lorsqu'une transition 
//! 	est effectuée par la fonction `processSymbol` de l'automate.
//! 
//! Cette classe est virtuelle pure et ne peut être instanciée.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class BehavioralTransition : public Transition
{
	friend BehavioralMachine;
	friend BehavioralState;

public:
	//! Construit une transition.
	//! \param[in] name Le nom d'affichage de la transition. Le nom est 
	//! obligatoire.
	//! \param[in] matchSymbol La classe de comparaison des symboles. L'objet 
	//! passé devient la propriété de cette transition.
	//! \param[in] nextState L'état suivant si la transition est effective.
	BehavioralTransition(string const & name, MatchSymbol * matchSymbol, State & nextState);
	//! Détruit la transition.
	virtual ~BehavioralTransition() = default;

protected:
	//! Fonction de réinitialisation de la transition.
	virtual void reset() = 0;
	//! Fonction d'action lorsque la transition courante 
	//! est effective et traite un nouveau symbole.
	virtual void process(symbol_t prevSymbol, symbol_t curSymbol) = 0;
};


#endif // BEHAVIORAL_TRANSITION_H