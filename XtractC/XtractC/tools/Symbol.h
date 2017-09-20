//! \file Symbol.h
//!
//! \brief Définition du type symbol_t.
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


#ifndef SYMBOL_H
#define SYMBOL_H


//! \typedef symbol_t
//! \brief Type définissant les symboles utilisés par l'automate à états finis.
//! \details Ce type fait partie du module FSM (Finite State Machine).
//!
//! Il correspond aux symboles pouvant être traités par l'automate. 
//! Ainsi, il défini le type des données d'entrées (dictionnaire). 
//! Le caractère est choisi pour correspondre aux besoins d'un AF faisant l'analyse 
//! lexicale d'un texte pour l'extraction de partie d'un texte. Dans le cas 
//! d'identification des commentaires du langage C++, c'est l'ensemble des caractères 
//! permi par le langage C++ qui correspond aux symboles pouvant être manipulés.
//!
typedef char symbol_t;


#endif // SYMBOL_H