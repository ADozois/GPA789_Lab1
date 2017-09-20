//! \file FiniteStateMachine.h
//!
//! \brief Définition de la classe FiniteStateMachine.
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

#ifndef FINITE_STATE_MACHINE_H
#define FINITE_STATE_MACHINE_H

#include "Symbol.h"
#include <list>
using namespace std;

class State;
class Transition;


//! \brief		Classe représentant un automate fini.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Une présentation formelle des automates est présentée dans cette 
//! section : \ref fsm
//! 
//! Cette classe gère les automates de type __AF__. 
//! 
//! La séquence suivante montre comment utiliser l'automate :
//!  -# création des états
//!  -# création des transitions (en utilisant les états définis)
//!  -# ajout des transitions aux états déclencheurs (appelés aussi 
//! 	états possesseurs)
//!  -# ajout des états à l'automate
//!  -# assignation de l'état initial
//!  -# démarrage de l'automate
//!  -# traitement des symboles par l'automate
//!  -# arrêt de l'automate
//! \code{.cpp}
//! // Étape 1 : création des états
//! State * myState1 = new State("My First State", true);
//! State * myState2 = new State("My Second State", false);
//! 
//! // Étape 2 : création des transitions
//! Transition * myTransition = new TransitionCounter("Valid *", new MatchSingleSymbol('*'), myState2);
//! 
//! // Étape 3 : ajout des transitions aux états
//! myState1->addTransition(myTransition);
//! 
//! // Étape 4 : ajout des états à l'automate
//! FiniteStateMachine myMachine;
//! myMachine.addState(myState1);
//! myMachine.addState(myState2);
//! 
//! // Étape 5 : assignation de l'état initial
//! myMachine.setInitialState(myState1);
//! 
//! // Étape 6 : démarrage de l'automate
//! myMachine.start();
//! 
//! // Étape 7 : traitement des symboles par l'automate
//! // ...
//! myMachine.processSymbol('*');
//! // ...
//! 
//! // Étape 8 : arrêt de l'automate
//! bool acceptingState = myMachine.stop();
//! \endcode
//! 
//! Les fonctions `addState` et `setInitialState`
//! permettent de définir la structure de l'automate.
//! 
//! Les fonctions `start`, `processSymbol` et `stop` permettent 
//! de gérer l'exécution de l'automate.
//! 
//! Les fonctions `isRunning` et `currentStateName` permettent 
//! de questionner l'automate sur son opération.
//! 
//! Les fonctions `setNoStateName` et `noStateName` offrent une 
//! gestion personnalisé de la chaîne de sortie de la fonction 
//! currentStateName lorque l'état courant n'est pas défini. 
//! Par défaut, la chaîne de caractères retournée est 
//! `"-no current state-"`. Il est possible de retourner 
//! une chaîne de caractères personnalisée pour cette situation.
//! 
//! L'automate est propriétaires des états qui y sont ajoutés. 
//! C'est au moment de la suppression de l'automate que les 
//! états sont libérées. Il est important de ne pas libérer la 
//! mémoire des objets `State` ailleurs dans le programme. Il est d'un 
//! mauvais usage d'accéder aux états après qu'ils aient été 
//! assignées (ajoutées) à l'automate. Chaque état doit être créé
//! dynamiquement et assigné à un seul automate. L'assignation à deux automates 
//! produira une erreure de désallocation de mémoire.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class FiniteStateMachine
{
public:
	//! Construit un automate fini.
	FiniteStateMachine();
	FiniteStateMachine(FiniteStateMachine const &) = delete;
	FiniteStateMachine(FiniteStateMachine const &&) = delete;
	FiniteStateMachine& operator=(FiniteStateMachine const &) = delete;
	FiniteStateMachine& operator=(FiniteStateMachine const &&) = delete;
	//! Détruit l'objet courant.
	virtual ~FiniteStateMachine();

	//! Insère un état à l'automate. Si l'état existe déjà, la fonction 
	//!	retourne sans rien faire. Si le paramètre est `nullptr` une 
	//! exception `std::invalid_argument` est générée.
	//! \param[in] state L'état à ajouter.
	virtual void addState(State * state);
	//! Détermine l'état initial. Si l'état spécifié n'existe pas ou si 
	//! le paramètre est `nullptr` une exception 
	//! `std::invalid_argument` est générée.
	//! \param[in] initState L'état initial.
	void setInitialState(State * initState);

	//! Amorce le démarrage de l'automate. Si l'automate ne possède 
	//! aucun état ou si l'état initiale n'est pas défini, une exception 
	//! `std::logic_error` est générée. Si L'automate est en opération, 
	//! l'automate est d'abord arrêté avant d'être réinitialisé et redémaré.
	virtual void start();
	//! Effectu le traitement d'un symbole. Cette fonction fait l'estimation 
	//! d'une éventuel transition et met à jour l'état courant. Si l'automate 
	//! n'est pas démarré, cette fonction ne fait rien.
	//! \param[in] curSymbol Le symbole à traiter.
	virtual void processSymbol(symbol_t curSymbol);
	//! Arrête l'automate. Retourne si le dernier état était un 
	//! état acceptant.
	virtual bool stop();

	//! Retourne si l'automate est en opération (_started_).
	bool isRunning() const { return mRunning; }

	//! Retourne le nom de l'état courant. Si aucun état n'est spécifié, 
	//! c'est `noStateName` qui est retourné.
	string currentStateName(void) const;
	//! Permet de spécifier un `noStateName` spécifique.
	//! \param[in] name Le texte à afficher si aucun état n'est défini.
	static void setNoStateName(string const & name) { mNoStateName = name; }
	//! Retourne le `noStateName`.
	static string const & noStateName() { return mNoStateName; }

protected:
	static string mNoStateName;

	symbol_t mPreviousSymbol;
	bool mRunning;
	State * mInitialState;
	State * mCurrentState;
	list<State*> mStates;

	//! Supprime un état.
	static void deleteState(State * & state);	
};


#endif // FINITE_STATE_MACHINE_H