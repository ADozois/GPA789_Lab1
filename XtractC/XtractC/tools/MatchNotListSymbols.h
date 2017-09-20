//! \file MatchNotListSymbols.h
//!
//! \brief Définition de la classe MatchNotListSymbols.
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

#ifndef MATCH_NOT_LIST_SYMBOLS_H
#define MATCH_NOT_LIST_SYMBOLS_H

#include "MatchListSymbols.h"

//! \brief		Classe représentant l'acceptation d'un symbole différent parmi 
//!				un ensemble de symboles.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet l'acceptation d'un symbole différent de 
//! ceux se trouvant dans un ensemble de symboles. Le symbole 
//! accepté doit être différent de tous les symboles présents 
//! dans l'ensemble de référence.
//! 
//! L'ensemble des symboles de référence doit être spécifié à la 
//! déclaration de la classe et ne peut être modifié.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class MatchNotListSymbols : public MatchListSymbols
{
public:
	MatchNotListSymbols() = delete;
	//! Construit un `MatchNotListSymbol` initialisant l'ensemble des symboles 
	//!	non-acceptés. La liste de symbole ne peut être modifiée par la suite. 
	//! \param[in] symbols La liste des symboles non-acceptés.
	MatchNotListSymbols(list<symbol_t> const & symbols);
	//! Construit un `MatchListSymbol` initialisant l'ensemble des symboles 
	//!	non-acceptés. La liste de symbole ne peut être modifiée par la suite. 
	//! \param[in] symbols La liste des symboles non-acceptés (sous forme 
	//! d'`initializer_list`).
	MatchNotListSymbols(initializer_list<symbol_t> const & symbols);
	//! Détruit l'objet courant.
	virtual ~MatchNotListSymbols() = default;

	//! La fonction d'acceptation fait une comparaison du symbole et 
	//!	retourne vrai si ce dernier est différent de tous ceux de la liste 
	//! des symboles de référence. La liste des symboles de référence est 
	//! celle définie lors de la définition de l'instance.

	//! La fonction d'acceptation fait une comparaison du symbole et 
	//!	retourne vrai si ce dernier est différent de tous ceux de la liste 
	//!	des symboles de référence. La liste des symboles de référence est 
	//! celle définie lors de la définition de l'instance.
	//! \param[in] symbol Le symbole à comparer.
	virtual bool isMatching(symbol_t symbol) const override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual MatchSymbol* clone() const override;
};

#endif