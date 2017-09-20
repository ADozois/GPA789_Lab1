//! \file TransitionTransducer.h
//!
//! \brief Définition de la classe TransitionTransducer.
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

#ifndef TRANSITION_TRANSDUCER_H
#define TRANSITION_TRANSDUCER_H


#include "TransitionCounter.h"
#include "TransducerAction.h"


//! \brief		Classe représentant les transitions d'un automate de type 
//!				transducteur.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet de créer une interface commune pour toutes 
//! les transitions du __TF__. 
//! L'interface commune est la gestion d'une action spécifique 
//! lors de l'appel de la fonction d'exécution process.
//! 
//! Les actions sont exprimées par la classe `TransducerAction`
//! et ses déscendants. Lorsqu'une action est passée au constructeur, 
//! la transition devient propriétaire de l'action.
//! Ainsi, c'est lors de la suppression des transitions que les 
//! actions sont libérées. Il est important de ne pas libérer la 
//! mémoire des objets `TransducerAction` ailleurs dans le 
//! programme. Il est d'un mauvais usage d'accéder aux conditions 
//! après qu'elles aient été assignées (ajoutées) à un transition. 
//! Chaque action doit être créée dynamiquement et assignée 
//! à un seul état. Deux actions identiques appliquées à des 
//! transitions différentes requiert deux objets _action_ 
//! différents. L'assignation à deux transition 
//! produira une erreure de désallocation de la mémoire.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransitionTransducer : public TransitionCounter
{
public:
	//! Construit une transition.
	//! \param[in] name Le nom d'affichage de la transition. Le nom est 
	//! obligatoire.
	//! \param[in] matchSymbol La classe de comparaison des symboles. L'objet 
	//! passé devient la propriété de cette transition.
	//! \param[in] nextState L'état suivant si la transition est effective.
	TransitionTransducer(string const & name, MatchSymbol * matchSymbol, TransducerAction * action, State & nextState);
	//! Détruit la transition.
	virtual ~TransitionTransducer();

	TransducerAction* action() { return mAction; }

protected:
	//! Remet le compteur à 0.
	virtual void reset() override;
	//! Incrémente le compteur.
	virtual void process(symbol_t prevSymbol, symbol_t curSymbol) override;

protected:
	TransducerAction * mAction;
	
};


#endif // TRANSITION_TRANSDUCER_H