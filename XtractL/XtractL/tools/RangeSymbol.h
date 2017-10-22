//! \file Range.h
//!
//! \brief Définition de la classe RangeSymbol.h.
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

#ifndef RANGESYMBOL_H
#define RANGESYMBOL_H

#include "Symbol.h"

//! \brief		Classe sert a faciliter la gestion des range de symbol_t.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Elle permet l'encapsulation d'un interval de 2 symbol_t. Cette classe permet 
//! aussi de savoir si un symbol_t ce trouve dans l'interval definie par l'utilisateur
//! 
//! Cette classe sert a tout e classe ayant besoin d'un range, soit principalement 
//! MatchRangSymbol, MatchListRangeSymbol et MatchNotListRangeSymbol
//! 
//! 
//! \author		Antoine Dozois
//! \author		Guillaume Chabot-Nobert
//! \version	1.0
//! \date		2017
//! \copyright	Copyleft

class RangeSymbol
{
public:
	RangeSymbol()=delete;
	RangeSymbol(symbol_t oneSymbol);
	RangeSymbol(symbol_t first, symbol_t last);
	~RangeSymbol()=default;
	
	bool isMatching(symbol_t symbol) const;

	symbol_t FirstSymbol();
	symbol_t LastSymbol();


private:
	symbol_t mFirstSymbol;
	symbol_t mLastSymbol;
};

#endif