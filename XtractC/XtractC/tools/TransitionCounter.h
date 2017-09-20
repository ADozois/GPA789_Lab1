//! \file TransitionCounter.h
//!
//! \brief Définition de la classe TransitionCounter.
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

#ifndef TRANSITION_COUNTER_H
#define TRANSITION_COUNTER_H


#include "BehavioralTransition.h"
#include <cstdint>


//! \brief		Classe représentant des transitions qui cumulent des informations sur
//!				le nombre de fois que la fonction comportementale `process` est 
//!				appelée.
//! \details	Cette classe fait partie du module BM (Behavioral Machine).
//! 
//! Cette classe permet de créer une interface commune pour toutes 
//! les transitions de l'ACF qui désire produire certaines statistiques. 
//! L'interface commune est la gestion des deux fonctions 
//! d'opération afin de comptabiliser un compteur d'opération.
//! 
//! On retrouve une information supplémentaire :
//!  - count : le nombre de fois que la transition a été effective
//! 
//! Toutes les fonctions abstraites de la classe parent ont été 
//! réimplémentées. Il est donc possible d'instancier un objet de 
//! cette classe.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransitionCounter : public BehavioralTransition
{
public:
	//! Construit une transition.
	//! \param[in] name Le nom d'affichage de la transition. Le nom est 
	//! obligatoire.
	//! \param[in] matchSymbol La classe de comparaison des symboles. L'objet 
	//! passé devient la propriété de cette transition.
	//! \param[in] nextState L'état suivant si la transition est effective.
	TransitionCounter(string const & name, MatchSymbol * matchSymbol, State & nextState);
	//! Détruit la transition.
	virtual ~TransitionCounter() = default;

	//! Retourne le nombre de fois que la transition a été effective 
	//! et qu'elle a traité un symbole.
	uint32_t count() const { return mCount; }

protected:
	//! Remet le compteur à 0.
	virtual void reset() override;
	//! Incrémente le compteur.
	virtual void process(symbol_t prevSymbol, symbol_t curSymbol) override;

protected:
	uint32_t mCount;
	
};


#endif // TRANSITION_COUNTER_H