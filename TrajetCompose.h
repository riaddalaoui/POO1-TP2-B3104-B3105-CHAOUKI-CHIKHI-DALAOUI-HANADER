/*********************************************************************************************************************************************
                TrajetCompose  -  Classe définissant un trajet compose de plusieurs trajets simples
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TableauDynamique.h"
#include "Catalogue.h"
//------------------------------------------------------------- Constantes
#define TAILLE_MAX_INIT 10

//------------------------------------------------------------- Description
/* Rôle de la classe <TrajetCompose> :
   Classe définissant un trajet Compose de plusieurs trajets simples.

   Attributs de la classe <TrajetCompose> :
   Un TrajetCompose est définit par une villeDepart et une villeArrivee, mais
   aussi un TableauDynamique stockant les trajets simples qui le composent.
*/

//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher (  ) const;
    // Méthode pour afficher les détails du trajet composé

    const TableauDynamique& GetTableau (  ) const;
    // Méthode pour obtenir le tableau dynamique de trajets

    int GetNbEscales (  ) const;
    // Méthode pour obtenir le nombre d'escales dans le trajet composé


    const TrajetSimple* RechercheDansTrajetCompose(const char* VilleA, const char* VilleB);
    // Méthode pour rechercher un trajet simple dans le trajet composé en fonction des villes de départ et d'arrivée

    bool operator==(const Trajet& autre) const;
    // Surcharge de l'opérateur d'égalité pour comparer deux trajets composés


//-------------------------------------------- Constructeurs - destructeur


    TrajetCompose(const TrajetCompose& autre);
    // Constructeur de copie

    
    TrajetCompose ( );
    // Constructeur par défaut

    ~TrajetCompose ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int nbEscales;
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
};

#endif // TRAJETCOMPOSE_H



