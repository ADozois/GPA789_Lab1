//! \file MatchRangeSymbols.h
//!
//! \brief Définition de la classe MatchRangeSymbols.
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

#ifndef MATCH_RANGE_SYMBOLS_H
#define MATCH_RANGE_SYMBOLS_H

#include "MatchSymbol.h"

//! \brief		Classe permettant la verification qu'un caractere se trouve
//!				dans un intervale.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//!  
//!
//! \author		Antoine Dozois
//! \author		Guillaume Chabot-Nobert
//! \version	1.0
//! \date		2017
//! \copyright	Copyleft

class MatchRangeSymbols : public MatchSymbol
{
public:
	//! Delete du constructeur par default
	MatchRangeSymbols() = delete;
	//! Seul constructeur accepter pour la contruction d'un MatchRangeSymbols
	MatchRangeSymbols(symbol_t firstSymbol, symbol_t lastSymbol);
	//! Destructeur par default de MatchRangeSymbols
	~MatchRangeSymbols() = default;

	//! La fonction d'acceptation verifie que le symbole se touve dans le
	//!	range des membres de la class. Le range des symboles de référence 
	//! est celui définie lors de la définition de l'instance.
	//! \param[in] symbol Le symbole à comparer.
	virtual bool isMatching(symbol_t symbol) const override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual	MatchSymbol* clone(void) const override;

private:
	symbol_t mFirstSymbol;
	symbol_t mLastSymbol;
};

#endif // !MATCH_RANGE_SYMBOLS_H