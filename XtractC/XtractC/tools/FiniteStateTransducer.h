//! \file FiniteStateTransducer.h
//!
//! \brief Définition de la classe FiniteStateTransducer.
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

#ifndef FINITE_STATE_TRANSDUCER_H
#define FINITE_STATE_TRANSDUCER_H

#include "BehavioralMachine.h"
#include "TransitionTransducer.h"


//! \brief		Classe représentant au automate de type transducteur.
//! \details	Cette classe fait partie du module __FST__ (Finite State Transducer).
//! 
//! Une présentation formelle des __FST__ est présentée dans cette 
//! section : \ref fst
//! 
//! La gestion des opérations de cette classe est identique à 
//! l'automate comportemental à une exception près. Si une 
//! transition est de type TransitionTransducer, alors l'action 
//! de la transition est appelée.
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
//! \date		2016
//! \copyright	Copyleft
class FiniteStateTransducer : public BehavioralMachine
{
public:
	//! Construit un transducteur fini.
	FiniteStateTransducer();
	FiniteStateTransducer(FiniteStateTransducer const &) = delete;
	FiniteStateTransducer(FiniteStateTransducer const &&) = delete;
	FiniteStateTransducer& operator=(FiniteStateTransducer const &) = delete;
	FiniteStateTransducer& operator=(FiniteStateTransducer const &&) = delete;
	//! Détruit l'objet courant.
	virtual ~FiniteStateTransducer() = default;

	//! Détermine le flux de sortie.
	//! \param[in] oStream Le flux de sortie.
	void setOStream(ostream * oStream);

};


#endif // FINITE_STATE_TRANSDUCER_H