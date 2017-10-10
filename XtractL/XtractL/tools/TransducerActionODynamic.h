//! \file TransducerActionODynamic.h
//!
//! \brief Définition de la classe TransducerActionODynamic.
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

#ifndef TRANSDUCER_ACTION_O_DYNAMIC_H
#define TRANSDUCER_ACTION_O_DYNAMIC_H

#include "TransducerActionOStream.h"

#include <string>
using namespace std;


//! \brief		Classe permettant la sortie d'un ensemble de textes sur le flux 
//!				de sortie.
//! \details	Cette classe fait partie du module FSM (Finite State Machine).
//! 
//! Cette classe crée l'action permettant d'afficher un texte 
//! combiné lors d'une transition d'un __TF__.
//! 
//! Le texte est construit par la concaténation de ces cinq 
//! composants dans l'ordre :
//!  - préfixe (texte statique)
//!  - caractère précédent (texte dynamique)
//!  - texte intermédiaire (texte statique)
//!  - caractère courant (texte dynamique)
//!  - postfixe (texte statique)
//!
//! \author		Tony Wong, Ph.D.
//! \author		JC Demers
//! \version	1.0
//! \date		2016
//! \copyright	Copyleft
class TransducerActionODynamic : public TransducerActionOStream
{
public:
	//! Construit un `TransducerAction`.
	//! \param[in] prefix Le préfixe à afficher.
	//! \param[in] displayPrevious L'affichage ou non de caractère précédent.
	//! \param[in] infix Le texte à afficher au centre des caractères 
	//!	précédent et courant.
	//! \param[in] displayCurrent L'affichage ou non de caractère courant.
	//! \param[in] postfix Le postfixe à afficher.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionODynamic(string const & prefix, bool displayPrevious, string const & infix, bool displayCurrent, string const & postfix, ostream * oStream = &cout);
	//! Construit un `TransducerAction` où le caractère précédent n'est pas affiché.
	//! \param[in] prefix Le préfixe à afficher.
	//! \param[in] postfix Le postfixe à afficher.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionODynamic(string const & prefix, string const & postfix, ostream * oStream = &cout);
	//! Construit un `TransducerAction` où le caractère précédent n'est pas affiché et sans préfixe.
	//! \param[in] postfix Le postfixe à afficher.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionODynamic(string const & postfix, ostream * oStream = &cout);
	//! Construit un `TransducerAction` où seulement le caractère courant est affiché.
	//! \param[in] oStream Le flux de sortie à utiliser.
	TransducerActionODynamic(ostream * oStream = &cout);
	//! Détruit l'objet courant.
	virtual ~TransducerActionODynamic() = default;

	//! Détermine l'affichage du symbole précédent.
	//! \param[in] displayPrevious L'affichage ou non de caractère précédent.
	void setDisplayPrevious(bool displayPrevious) { mDisplayPrevious = displayPrevious; }
	//! Détermine l'affichage du symbole précédent.
	//! \param[in] displayCurrent L'affichage ou non de caractère courant.
	void setDisplayCurrent(bool displayCurrent) { mDisplayCurrent = displayCurrent; }
	//! Détermine le texte statique se trouvant au début (préfixe).
	//! \param[in] prefix Le préfixe à afficher.
	void setPrefix(string const & prefix) { mPrefix = prefix; }
	//! Détermine le texte statique se trouvant entre les symboles.
	//! \param[in] infix Le texte à afficher au centre des caractères 
	void setInfix(string const & infix) { mInfix = infix; }
	//! Détermine le texte statique se trouvant à la fin (préfixe).
	//! \param[in] postfix Le postfixe à afficher.
	void setPostfix(string const & postfix) { mPostfix = postfix; }

	// Retourne si l'affichage du symbole précédent est effectif.
	bool displayPrevious() const { return mDisplayPrevious; }
	// Retourne si l'affichage du symbole courant est effectif.
	bool displayCurrent() const { return mDisplayCurrent; }
	// Retourne le préfixe.
	string prefix() const { return mPrefix; }
	// Retourne le texte entre les symboles.
	string infix() const { return mInfix; }
	// Retourne le préfixe.
	string postfix() const { return mPostfix; }

	//! Ne fait rien.
	virtual bool reset() override { return true; }

	//! Affiche le texte dynamique.
	//! \param[in] prevSymbol Le symbole précédent (inutilisé).
	//! \param[in] curSymbol Le symbole suivant (inutilisé).
	virtual bool process(symbol_t prevSymbol, symbol_t curSymbol) override;

	//! Retourne une nouvelle copie de l'instance courante.
	virtual TransducerAction* clone() const override;

protected:
	bool mDisplayPrevious;
	bool mDisplayCurrent;
	string mPrefix;
	string mInfix;
	string mPostfix;
};


#endif // TRANSDUCER_ACTION_O_DYNAMIC_H