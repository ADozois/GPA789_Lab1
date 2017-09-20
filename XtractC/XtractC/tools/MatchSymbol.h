//! \file MatchSymbol.h
//!
//! \brief Définition de la classe MatchSymbol.
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

#ifndef MATCH_SYMBOL_H
#define MATCH_SYMBOL_H

#include "Symbol.h"

//! \brief		Classe abstraite représentant l'acceptation d'un symbole.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet de créer une interface commune pour tous 
//! les types de symbole à manipuler. Elle sert de classe utilitaire 
//! permettant de comparer si un symbole repecte un critère de 
//! comparaison spécifique. Selon l'implémentation des fonctions requises,
//! il est possible de créer des règles simples ou plus complexes 
//! permettant d'accepter ou non un symbole. 
//! 
//! Cette classe sert aux différents objets de transitions afin de 
//! déterminer si une transition est effective ou non (voir la 
//! classe Transition).
//! 
//! Par exemple, il est possible de créer des classes acceptant un 
//! symbole spécifique ou un symbole différent de ce symbole. 
//! Il est aussi possible de créer des ensembles de symboles homogènes 
//! ou hétéroclites.
//! 
//! Cette classe est virtuelle pure et ne peut être instanciée.
//! 
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class MatchSymbol
{
public:
	//! Construit un `MatchSymbol`.
	MatchSymbol() = default;
	//! Détruit l'objet courant.
	virtual ~MatchSymbol() = default;

	//! La fonction isMatching est la fonction d'acceptation de l'AF. Cette 
	//!	fonction permet de déterminer si un symbole est accepté ou non. Cette 
	//!	acceptation est principalement utilisé dans une transition afin de 
	//!	savoir si cette dernière est effective ou non.
	//!
	//! Cette fonction est virtuelle pure et doit être redéfinie.
	//! \param[in] symbol Le symbole à comparer.
	virtual bool isMatching(symbol_t symbol) const = 0;

	//! Cette fonction permet d'instancier un objet identique à l'objet 
	//!	courant. Le nouvel objet est alloué dynamiquement et devient la 
	//!	propriété du récepteur. En d'autres termes, la fonction retourne un 
	//!	objet dont la désallocation de la mémoire doit être gérée 
	//! explicitement par un mécanisme externe.
	//!
	//! Cette fonction est virtuelle pure et doit être redéfinie.
	virtual MatchSymbol* clone() const = 0;
};


#endif // MATCH_SYMBOL_H