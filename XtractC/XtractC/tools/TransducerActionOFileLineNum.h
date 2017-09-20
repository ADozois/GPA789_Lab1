//! \file TransducerActionOFileLineNum.h
//!
//! \brief Définition de la classe TransducerActionOFileLineNum.
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

#ifndef TRANSDUCER_ACTION_O_FILE_LINE_NUM_H
#define TRANSDUCER_ACTION_O_FILE_LINE_NUM_H

#include "TransducerActionOFileStat.h"


//! \brief		Classe permettant la sortie du numéro de ligne courant sur 
//!				le flux de sortie.
//! \details	Cette classe fait partie du module XtractC et est une 
//!				extension d'un TransducerAction.
//! 
//!				Cette classe crée l'action permettant d'afficher le numéro
//!				de ligne courant lors d'une transition d'un __TF__.
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransducerActionOFileLineNum : public TransducerActionOFileStat
{
public:
	//! Construit un `TransducerActionOFileLineNum`.
	//! \param[in] fileStatExtraction L'automate qui comptabilise les données 
	//!	statistiques du fichier.
	//! \param[in] prefix Le préfixe à afficher.
	//! \param[in] postfix Le postfixe à afficher.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionOFileLineNum(AutomatonFileStatExtraction const & fileStatExtraction, string const & prefix = string(), string const & postfix = string(), ostream * oStream = &cout);
	//! Détruit l'objet courant.
	virtual ~TransducerActionOFileLineNum() = default;

	//! Affiche le texte personnalisé.
	//! \param[in] prevSymbol Le symbole précédent (inutilisé).
	//! \param[in] curSymbol Le symbole suivant (inutilisé).
	virtual bool process(symbol_t prevSymbol, symbol_t curSymbol) override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual TransducerAction* clone() const override;
};


#endif // TRANSDUCER_ACTION_O_FILE_LINE_NUM_H