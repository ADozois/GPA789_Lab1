//! \file MatchAllSymbols.h
//!
//! \brief Définition de la classe MatchAllSymbols.
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

#ifndef MATCH_ALL_SYMBOLS_H
#define MATCH_ALL_SYMBOLS_H

#include "MatchSymbol.h"

//! \brief		Classe représentant l'acceptation de tous les symboles.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet l'acceptation de tous les symboles.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class MatchAllSymbols : public MatchSymbol
{
public:
	//! Construit un `MatchAllSymbols`.
	MatchAllSymbols() = default;
	//! Détruit l'objet courant.
	virtual ~MatchAllSymbols() = default;

	//! La fonction d'acceptation retourne toujours vrai.
	//! \param[in] symbol Le symbole à comparer.
	//virtual bool isMatching([[maybe_unused]] symbol_t symbol) const override; // Voir cette option de compilation dans les options du projet : Project properties  ->  C/C++  ->  Language  ->  C++ Language Standard  =  ISO C++ Latest Draft Standard (/std:c++latest)
	virtual bool isMatching(symbol_t symbol) const override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual MatchSymbol* clone() const override;
};


#endif