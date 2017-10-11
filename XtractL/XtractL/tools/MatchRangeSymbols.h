
#ifndef MATCH_RANGE_SYMBOLS_H
#define MATCH_RANGE_SYMBOLS_H

#include "MatchSymbol.h"

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
	//!	range des membres de la class. Le range des symboles de r�f�rence 
	//! est celui d�finie lors de la d�finition de l'instance.
	//! \param[in] symbol Le symbole � comparer.
	virtual bool isMatching(symbol_t symbol) const override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual	MatchSymbol* clone(void) const override;

private:
	symbol_t mFirstSymbol;
	symbol_t mLastSymbol;
};

#endif // !MATCH_RANGE_SYMBOLS_H