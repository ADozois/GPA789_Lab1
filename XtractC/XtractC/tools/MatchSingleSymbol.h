//! \file MatchSingleSymbol.h
//!
//! \brief Définition de la classe MatchSingleSymbol.
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

#ifndef MATCH_SINGLE_SYMBOL_H
#define MATCH_SINGLE_SYMBOL_H

#include "MatchSymbol.h"

//! \brief		Classe représentant l'acceptation d'un symbole spécifique.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe hérite de la classe MatchSymbol et permet
//! l'acceptation d'un symbole unique. Le symbole accepté doit 
//! être identique au symbole de référence.
//! 
//! Le symbole de référence doit être spécifié à la déclaration 
//! de la classe et ne peut être modifié.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class MatchSingleSymbol : public MatchSymbol
{
public:
	//! Construit un `MatchSingleSymbol` initialisant le symbole 
	//!	accepté. Le symbole ne peut être modifié par la suite. 
	//! \param[in] symbols Le symbole accepté.
	MatchSingleSymbol(symbol_t symbol);
	//! Détruit l'objet courant.
	virtual ~MatchSingleSymbol() = default;

	//! La fonction d'acceptation fait une comparaison du symbole et 
	//!	retourne vrai si ce dernier est identique au symbole de référence. Le 
	//! symbole de référence est celui défini lors de la définition de 
	//! l'instance.
	//! \param[in] symbol Le symbole à comparer.
	virtual bool isMatching(symbol_t symbol) const override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual MatchSymbol* clone() const override;

protected:
	symbol_t mSymbol;
};


#endif