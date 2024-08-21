/*********************************************************************************************************************************************
                           Catalogue  -  Classe gestionnaire du Catalogue des Trajets
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TableauDynamique.h"
#include "TrajetCompose.h"
#include "DirectedGraph.h"
//------------------------------------------------------------- Constantes
#define TAILLE_MAX_INIT 10

//------------------------------------------------------------- Description
/* Rôle de la classe <Catalogue> :
   La classe Catalogue permet de gérer un catalogue de trajets. Elle permet
   d'effectuer des opérations basiques, telles que rechercher 
   un trajet ou afficher tous les trajets du catalogue.

   Attributs de la classe <Catalogue> :
   Un catalogue est définit par un TableauDynamique de trajets.
*/

//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher (  );
    /*
    Affiche tous les trajets du catalogue
    */

    // DirectedGraph* toGraph();
    // // Convertit le catalogue en graphe orienté pour appliqué un DFS, utilise autre bib que iostream donc laisée que pour la démo.

    /*DirectedGraph* toGraph();*/
    /*
    Méthode propre au DFS (bonus). Renvoie un graphe orienté représentant
    le catalogue pour y appliquer un DFS. Utilise des libs non autorisées
    donc laisée que pour la démonstration.
    */


    void RechercheSimple (char* VilleA, char* VilleB);
    /*
    Effectue une recherche de trajets entre une VilleA et une VilleB de façon
    simple : si un trajet relie VilleA et VilleB, il est affiché.
    */
    

    void RechercheBruteForce (const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant, int tailleChemin, bool& found);
    /*
    Cherche un chemin existant entre VilleA et VilleB de façon récursive avec
    un algorithme Brute Force. La méthode est appelé pour chaque trajet tel
    que son arrêt de départ correspond à l'arrêt d'arrivée du précédent.
    Le chemin est alors stocké dans un TableauDynamique cheminCourant et la
    recherche s'arrête lorsque le bool found vaut true.
    */


    void UneCombinaison(Trajet* startTrajet,const char* VilleA, const char* VilleB , TableauDynamique& cheminCourant);
    /*
    Initialise la recherche récurssive brute force en appelant la méthode
    RechercheBruteForce pour le premier trajet de départ. Gère également 
    les trajets stockés dans cheminCourant pour éviter les boucles infinies
    et les fuites de mémoires.
    */

    void RechercheAvancee (const char*, const char*);
    /*
    Effectue la recherche avancée d'un trajets entre VilleA et VilleB
    en appelant la méthode UneCombinaison pour chaque trajet de départ
    potentiel du catalogue.
    Gère également les cas des chemins qui n'ont pas besoin de combinaison
    de trajets pour exister et les cas où aucun trajet ne relie VilleA et
    VilleB. 
    */

    virtual void Ajouter ( Trajet * ptTrajet );
    /*
    Ajoute un trajet au catalogue
    */


//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    /*
    Constructeur du catalogue
    */

    virtual ~Catalogue ( );
    /*
    Destructeur du catalogue
    */


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
};



#endif // CATALOGUE_H



