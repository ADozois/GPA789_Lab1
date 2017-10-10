//! \file TransducerActionOFileStat.h
//!
//! \brief Définition de la classe TransducerActionOFileStat.
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

#ifndef TRANSDUCER_ACTION_O_FILE_STAT_H
#define TRANSDUCER_ACTION_O_FILE_STAT_H

#include "TransducerActionOStream.h"
#include "AutomatonFileStatExtraction.h"
#include <string>
using namespace std;


//! \brief		Classe permettant la sortie de statistique sur le flux 
//!				de sortie.
//! \details	Cette classe fait partie du module XtractC et est une 
//! extension d'un TransducerAction.
//! 
//! Cette classe crée l'action permettant d'afficher un texte 
//! lié à une statistique lors de la transition d'un __TF__.
//! 
//! Cette classe est virtuelle pure et ne peut être instanciée.
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransducerActionOFileStat : public TransducerActionOStream
{
public:
	//! Construit un `TransducerActionOFileStat`.
	//! \param[in] fileStatExtraction L'automate qui comptabilise les données 
	//!	statistiques du fichier.
	//! \param[in] prefix Le préfixe à afficher.
	//! \param[in] postfix Le postfixe à afficher.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionOFileStat(AutomatonFileStatExtraction const & fileStatExtraction, string const & prefix = string(), string const & postfix = string(), ostream * oStream = &cout);
	//! Détruit l'objet courant.
	virtual ~TransducerActionOFileStat() = default;

	//! Détermine le préfixe.
	//! \param[in] prefix Le préfixe à afficher.
	void setPrefix(string const & prefix) { mPrefix = prefix; }
	//! Détermine le préfixe.
	//! \param[in] postfix Le postfixe à afficher.
	void setPostfix(string const & prefix) { mPrefix = prefix; }
	//! Retourne le préfixe.
	string prefix() { return mPrefix; }
	//! Retourne le postfixe.
	string postfix() { return mPostfix; }

	//! Ne fait rien.
	virtual bool reset() override { return true; }

	//! Affiche le texte personnalisé.
	//! \param[in] prevSymbol Le symbole précédent (inutilisé).
	//! \param[in] curSymbol Le symbole suivant (inutilisé).
	virtual bool process(symbol_t prevSymbol, symbol_t curSymbol) override = 0;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual TransducerAction* clone() const override = 0;

protected:
	AutomatonFileStatExtraction const & mFileStatExtraction;
	
	string mPrefix;
	string mPostfix;
};


#endif // TRANSDUCER_ACTION_O_CUSTOM_H