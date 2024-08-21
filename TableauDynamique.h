/*********************************************************************************************************************************************
                           TableauDynamique  -  Classe gestionnaire d'un tableau dynamique de trajets
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Interface de la classe <TableauDynamique> (fichier TableauDynamique.h) ----------------
#if ! defined ( TABLEAUDYNAMIQUE_H )
#define TABLEAUDYNAMIQUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Description
/* Rôle de la classe <TableauDynamique> :
   Cette classe permet de créer un tableau dynamique qui stocke des pointeurs
   vers des objets de type Trajet. Son but étant d'optimiser l'espace mémoire
   alloué au stockage des trajets, la façon dont il est implémenté permet une
   réallocation de sa taille rapide et efficace.

   Attributs de la classe <TableauDynamique> :
   Un TableauDynamique est définit par un pointeur tabDynamique qui pointe vers
   un ensemble d'espaces mémoires contenants des pointeurs vers des trajets,
   ensemble de taille initiale nbTrajetsMax. Il a aussi pour attribut un entier
   nbTrajetsCourant qui indique le nombre de trajets actuellement présents dans le
   tableau dynamique.
*/

//------------------------------------------------------------------------

class TableauDynamique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Ajouter ( Trajet * ptTrajet );
    /*
    Ajoute un trajet au tableau dynamique.
    */


    void Supprimer(int i);
    /*
    Supprime le trajet à l'indice i dans le tableau dynamique
    */


    Trajet* GetTrajet ( int i ) const;
    /*
    Renvoie le trajet à l'indice i dans le tableau dynamique
    */


    int GetNbTrajetsCourant ( ) const;
    /*
    Renvoie le nombre de trajets actuellement dans le tableau dynamique
    */


    void SetNbTrajetsCourant(int i);
    /*
    Modifie le nombre de trajets actuellement dans le tableau dynamique
    */
    

    void Modif(int i, Trajet* t);
    /*
    Modifie le trajet à l'indice i dans le tableau dynamique
    */


//-------------------------------------------- Constructeurs - destructeur


    TableauDynamique ( const TableauDynamique & autre ); 
    /*
    Constructeur par copie
    */


    TableauDynamique(); 
    /*
    Constructeur par défault
    */


    TableauDynamique( int tabSizeInit );
    /*
    Constructeur avec initialisation de la taille maximale du tableau
    */


    virtual ~TableauDynamique ( );
    /*
    Destructeur
    */


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
    Trajet* *tabDynamique;
    int nbTrajetsCourant;
    int nbTrajetsMax;
};

#endif // TABLEAUDYNAMIQUE_H