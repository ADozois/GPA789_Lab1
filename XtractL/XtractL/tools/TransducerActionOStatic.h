//! \file TransducerActionOStatic.h
//!
//! \brief Définition de la classe TransducerActionOStatic.
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

#ifndef TRANSDUCER_ACTION_O_STATIC_H
#define TRANSDUCER_ACTION_O_STATIC_H

#include "TransducerActionOStream.h"

#include <string>
using namespace std;


//! \brief		Classe permettant la sortie d'un texte statique sur le flux 
//!				de sortie.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe crée l'action permettant d'afficher un texte 
//! spécifique et fixe lors d'une transition d'un __TF__.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransducerActionOStatic : public TransducerActionOStream
{
public:
	//! Construit un `TransducerActionOStatic`.
	//! \param[in] staticText Le texte statique qui doit être affiché.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionOStatic(string const & staticText = string(), ostream * oStream = &cout);
	//! Détruit l'objet courant.
	virtual ~TransducerActionOStatic() = default;

	//! Détermine le texte statique.
	//! \param[in] staticText Le texte statique qui doit être affiché.
	void setStaticText(string const & staticText) { mStaticText = staticText; }
	//! Retourne le texte statique.
	string staticText() { return mStaticText; }

	//! Ne fait rien.
	virtual bool reset() override { return true; }

	//! Affiche le texte statique.
	//! \param[in] prevSymbol Le symbole précédent (inutilisé).
	//! \param[in] curSymbol Le symbole suivant (inutilisé).
	virtual bool process(symbol_t prevSymbol, symbol_t curSymbol) override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual TransducerAction* clone() const override;

protected:
	string mStaticText;
};


#endif // TRANSDUCER_ACTION_O_STATIC_H