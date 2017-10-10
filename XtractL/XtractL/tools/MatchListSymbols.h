//! \file MatchListSymbols.h
//!
//! \brief Définition de la classe MatchListSymbols.
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

#ifndef MATCH_LIST_SYMBOLS_H
#define MATCH_LIST_SYMBOLS_H

#include "MatchSymbol.h"
#include <list>
#include <initializer_list>

using namespace std;

//! \brief		Classe représentant l'acceptation d'un symbole parmi un 
//!				ensemble de symboles.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet l'acceptation d'un symbole parmi un 
//! ensemble de symboles. Le symbole accepté doit être identique à 
//! l'un des symboles présent dans l'ensemble de référence.
//! 
//! L'ensemble des symboles de référence doit être spécifié à la 
//! déclaration de la classe et ne peut être modifié.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class MatchListSymbols : public MatchSymbol
{
public:
	//! Construit un `MatchListSymbol` initialisant l'ensemble des symboles 
	//!	acceptés. La liste de symbole ne peut être modifiée par la suite. 
	//! \param[in] symbols La liste des symboles acceptés.
	MatchListSymbols(list<symbol_t> const & symbols);
	//! Construit un `MatchListSymbol` initialisant l'ensemble des symboles 
	//!	acceptés. La liste de symbole ne peut être modifiée par la suite. 
	//! \param[in] symbols La liste des symboles acceptés (sous forme 
	//! d'`initializer_list`).
	MatchListSymbols(initializer_list<symbol_t> const & symbols);
	//! Détruit l'objet courant.
	virtual ~MatchListSymbols() = default;

	//! La fonction d'acceptation fait une comparaison du symbole et 
	//!	retourne vrai si ce dernier est inclu dans la liste des symboles
	//! de référence. La liste des symboles de référence est celui définie
	//! lors de la définition de l'instance.
	//! \param[in] symbol Le symbole à comparer.
	virtual bool isMatching(symbol_t symbol) const override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual MatchSymbol* clone() const override;

protected:
	list<symbol_t> mSymbols;
};

#endif