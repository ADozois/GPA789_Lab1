//! \file TransducerActionOStream.h
//!
//! \brief Définition de la classe TransducerAction.
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

#ifndef TRANSDUCER_ACTION_OSTREAM_H
#define TRANSDUCER_ACTION_OSTREAM_H

#include "TransducerAction.h"

#include <iostream>
using namespace std;


//! \brief		Classe abstraite permettant à l'action d'un __TF__ une sortie
//!				sur un flux de sortie.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe permet de créer une interface commune pour tous 
//! les types d'action qui doivent produire une valeur sur une 
//! flux de sortie (sortie standard, sortie d'erreur standard, 
//! fichier, string stream, ...).
//! 
//! Cette classe est virtuelle pure et ne peut être instanciée.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransducerActionOStream : public TransducerAction
{
public:
	//! Construit un `TransducerAction`.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionOStream(ostream * oStream = &cout);
	//! Détruit l'objet courant.
	virtual ~TransducerActionOStream() = default;

	//! Détermine le flux de sortie.
	//! \param[in] oStream Le flux de sortie à utiliser.
	void setOStream(ostream * oStream) { mOStream = oStream; }
	//! Retourne le flux de sortie.
	ostream* oStream() { return mOStream; }

protected:
	ostream * mOStream;
};


#endif // TRANSDUCER_ACTION_OSTREAM_H