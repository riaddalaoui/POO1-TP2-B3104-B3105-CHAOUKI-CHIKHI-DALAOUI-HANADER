/*********************************************************************************************************************************************
                                TrajetSimple  -  Classe définissant un trajet simple
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Description
/* Rôle de la classe <TrajetSimple> :
   Classe définissant un trajet simple, c'est à dire un trajet sans escales.

   Attributs de la classe <TrajetSimple> :
   Un TrajetSimple est définit par une villeDepart, une villeArrivee, et un
   mode de transport, trois chaines de caractères.
*/

//------------------------------------------------------------------------

class TrajetSimple : public Trajet 
{

//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const; 
    // Méthode pour afficher les détails d'un trajet simple (sans escales)

    const char* GetTransport ( ) const; 
    // Méthode pour obtenir le moyen de transport d'un trajet

    bool operator==(const Trajet& autre) const; 
    // Surcharge de l'opérateur d'égalité pour comparer deux trajets


//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const TrajetSimple& autre);
    // Constructeur de copie

    TrajetSimple();
    // Constructeur par défaut

    TrajetSimple ( char A[50], char B[50],char T[50] );
    // Constructeur prenant en paramètre les villes de départ et d'arrivée, ainsi que le moyen de transport


    ~TrajetSimple ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    char moyenTransport[50];
    
};
#endif // TRAJETSIMPLE_H