//! \file MatchListRangeSymbols.h
//!
//! \brief Définition de la classe MatchListRangeSymbols.
//! \details Ce fichier fait partie du laboratoire 1 donné dans le cadre du cours 
//! GPA789 : Analyse et conception orientées objet.
//!
//! \version 1.0
//!
//! \author Antoine Dozois
//! \author	Guillaume Chabot-Nobert
//!
//! \date 2017
//! \copyright Copyleft

#ifndef MATCH_LIST_RANGE_SYMBOL_H
#define MATCH_LIST_RANGE_SYMBOL_H

#include "MatchSymbol.h"
#include "RangeSymbol.h"
#include <list>
#include <initializer_list>


//! \brief		Classe permettant la d'une liste de range de charactère
//!				
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//!  
//!
//! \author		Antoine Dozois
//! \author		Guillaume Chabot-Nobert
//! \version	1.0
//! \date		2017
//! \copyright	Copyleft

class MatchListRangeSymbol: public MatchSymbol
{
public:
	//We don't want to be able to construct the class without any parameters
	MatchListRangeSymbol() = delete;
	//Constructors
	MatchListRangeSymbol(std::list<RangeSymbol> const & list);
	MatchListRangeSymbol(std::initializer_list<RangeSymbol> const & list);
	//Destructor
	~MatchListRangeSymbol();

	//Matching method
	virtual bool isMatching(symbol_t symbol) const override;

	//Clone method needed (from MatchSymbol)
	virtual MatchSymbol * clone() const override;

protected:
	std::list<RangeSymbol> mRanges;
};


#endif // !MATCH_LIST_RANGE_SYMBOL_H
