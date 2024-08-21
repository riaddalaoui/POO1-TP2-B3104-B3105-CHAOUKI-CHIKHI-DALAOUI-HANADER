/*********************************************************************************************************************************************
                                Trajet  -  Classe Ancêtre Abstraite de tous les Trajets
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------- Description
/* Rôle de la classe <Trajet> :
   Classe Ancêtre Abstraite de tous les Trajets, elle nous permet de définir
   les méthodes et attributs communs aux Trajets Simples et Composes, telles que l'affichage
   ou les villes de départ et d'arrivée.

   Attributs de la classe <Trajet> :
   Un Trajet est définit par une villeDepart et une villeArrivee, deux chaines de caractères.
*/

//------------------------------------------------------------------------


class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher (  ) const ;
    // Méthode virtuelle pour afficher les détails du trajet (simple ou composé)

    virtual const char * GetTransport () const;
    // Méthode virtuelle constante pour obtenir le moyen de transport du trajet

    virtual int GetNbEscales (  ) const;
    // Méthode virtuelle constante pour obtenir le nombre d'escales dans le trajet
    
    const char* GetArrivee () const;
    // Méthode constante pour obtenir la ville d'arrivée du trajet

    const char* GetDepart ()const ;
    // Méthode constante pour obtenir la ville de départ du trajet

    virtual bool operator==(const Trajet& autre) const;
    // Surcharge de l'opérateur d'égalité pour comparer deux trajets


//-------------------------------------------- Constructeurs - destructeur

    Trajet ( const Trajet& autre ) ;
    // Constructeur par copie


    Trajet( );
    // Constructeur par défaut

    virtual ~Trajet ( );
    // Destructeur


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
    char villeDepart[50];
    char villeArrivee[50];
    
};

#endif // TRAJET_H