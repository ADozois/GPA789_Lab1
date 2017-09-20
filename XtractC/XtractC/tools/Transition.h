//! \file Transition.h
//!
//! \brief Définition de la classe Transition.
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

#ifndef TRANSITION_H
#define TRANSITION_H

#include "Symbol.h"

#include <string>
using namespace std;

class MatchSymbol;
class State;


//! \brief		Classe représentant les transitions d'un automate fini.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Elle permet de créer une interface commune pour toutes 
//! les transitions de l'AEF. Cette interface réside 
//! principalement dans :
//!  - gestion de l'état suivant
//!  - condition de la transition
//! 
//! Chaque transition possède :
//!  - un nom (les noms peuvent être répétés)
//!  - l'état suivant
//!  - la condition de transition
//! 
//! C'est le constructeur qui permet de définir de façon immuable 
//! tous ces paramètres. 
//! 
//! Les conditions sont exprimées par la classe MatchSymbol
//! et ses déscendants. Lorsqu'une condition (un item 
//! _MatchSymbol_) est passée au constructeur, la transition 
//! devient propriétaire de la condition.
//! Ainsi, c'est lors de la suppression des transitions que les 
//! conditions sont libérées. Il est important de ne pas libérer la 
//! mémoire des objets `MatchSymbol` ailleurs dans le 
//! programme. Il est d'un mauvais usage d'accéder aux conditions 
//! après qu'elles aient été assignées (ajoutées) à un transition. 
//! Chaque condition doit être créée dynamiquement et assignée 
//! à un seul état. Deux conditions identiques appliquées à des 
//! transitions différentes requiert deux objets _condition_ 
//! différents. L'assignation à deux transition 
//! produira une erreure de désallocation de la mémoire.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class Transition
{
public:
	//! Construit une transition.
	//! \param[in] name Le nom d'affichage de la transition. Le nom est 
	//! obligatoire.
	//! \param[in] matchSymbol La classe de comparaison des symboles. L'objet 
	//! passé devient la propriété de cette transition.
	//! \param[in] nextState L'état suivant si la transition est effective.
	Transition(string const & name, MatchSymbol * matchSymbol, State & nextState);
	//! Détruit la transition et libère l'objet `MatchSymbol` qu'elle 
	//! possède.
	virtual ~Transition();

	//! Retourne le nom de la transition.
	string const & name() const { return mName; }
	//! Retourne le nom de la transition.
	string name() { return mName; }
	//! Retourne l'état suivant de la transition.
	State & nextState() const { return mNextState; }
	//! Fonction évaluant si la transition est effective 
	//! pour un symbole donné. 
	bool isTransiting(symbol_t symbol) const;

private:
	string mName;
	MatchSymbol * mMatchSymbol;
	State & mNextState;

};


#endif // TRANSITION_H