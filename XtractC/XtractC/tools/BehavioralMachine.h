//! \file BehavioralMachine.h
//!
//! \brief Définition de la classe BehavioralMachine.
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

#ifndef BEHAVIORAL_MACHINE_H
#define BEHAVIORAL_MACHINE_H

#include "FiniteStateMachine.h"


//! \brief		Classe représentant au automate comportemental.
//! \details	Cette classe fait partie du module BM (Behavioral Machine).
//! 
//! Une présentation formelle des automates est présentée dans cette 
//! section : \ref fsm_behavioral
//! 
//! Cette classe gère un automate de type comportemental. 
//! Il est intéressant de constater que n'importe quel type d'état 
//! (`State` ou `BehavioralState`) et n'importe quel 
//! type de transition (`Transition` ou 
//! `BehavioralTransition`) peuvent être utilisés 
//! simultanément dans le même automate. Les processus de 
//! résolution interne de l'automate déterminent quel sont les 
//! types de chaque état et chaque transition afin d'appeller 
//! les fonctions comportementales le cas échéant.
//! 
//! La façon d'utiliser cet automate est la même que celle de 
//! la classe parent FiniteStateMachine.
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
//! \date		20/08/2016
//! \copyright	Copyleft 2000-2016
class BehavioralMachine : public FiniteStateMachine
{
public:
	//! Construit un automate fini.
	BehavioralMachine();
	BehavioralMachine(BehavioralMachine const &) = delete;
	BehavioralMachine(BehavioralMachine const &&) = delete;
	BehavioralMachine& operator=(BehavioralMachine const &) = delete;
	BehavioralMachine& operator=(BehavioralMachine const &&) = delete;
	//! Détruit l'objet courant.
	virtual ~BehavioralMachine() = default;

	//! Amorce le démarrage de l'automate. Si l'automate ne possède 
	//! aucun état ou si l'état initiale n'est pas défini, une exception 
	//! `std::logic_error` est générée. Si L'automate est en opération, 
	//! l'automate est d'abord arrêté avant d'être réinitialisé et redémaré.
	virtual void start() override;
	//! Effectu le traitement d'un symbole. Cette fonction fait l'estimation 
	//! d'une éventuel transition et met à jour l'état courant. Si l'automate 
	//! n'est pas démarré, cette fonction ne fait rien.
	//! \param[in] curSymbol Le symbole à traiter.
	virtual void processSymbol(symbol_t curSymbol) override;
	//! Arrête l'automate. Retourne si le dernier état était un 
	//! état acceptant.
	virtual bool stop() override;

protected:
	//! Réinitialise tous les états comportementaux.
	virtual void resetBehavioralStates();
	//! Réinitialise toutes les transitions comportementales.
	virtual void resetBehavioralTransitions();

	//! Traite la transition courante.
	virtual void processBehavioralTransition(Transition * transition, symbol_t curSymbol);
	//! Fait le traitement de sortie d'un état comportemental.
	virtual void exitCurrentBehavioralState(symbol_t curSymbol);
	//! Fait le traitement d'entrée et standard d'un état comportemental.
	virtual void enterProcessCurrentBehavioralState(symbol_t curSymbol);
	//! Fait le traitement standard d'un état comportemental.
	virtual void processCurrentBehavioralState(symbol_t curSymbol);
};


#endif // BEHAVIORAL_MACHINE_H