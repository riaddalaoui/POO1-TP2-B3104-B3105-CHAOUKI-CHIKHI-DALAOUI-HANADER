/*********************************************************************************************************************************************
                        TableauDynamique  -  Classe gestionnaire d'un tableau dynamique de trajets
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Réalisation de la classe <TableauDynamique> (fichier TableauDynamique.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TableauDynamique.h"
#include "Trajet.h"


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void TableauDynamique::Ajouter ( Trajet * ptTrajet )
{
    // Réallocation si le tableau est plein
    if(this->nbTrajetsCourant == this->nbTrajetsMax-1)
    {   
        
        this->nbTrajetsMax *= 2;
        Trajet ** newTab = new Trajet*[this->nbTrajetsMax];
        memcpy(newTab, this->tabDynamique, this->nbTrajetsMax*sizeof(Trajet*));
        delete[] this->tabDynamique;
        this->tabDynamique = newTab;
    }

    // Ajout du trajet au tableau et incrémentation du nombre de trajets
    this->tabDynamique[this->nbTrajetsCourant] = ptTrajet;
    this->nbTrajetsCourant++;

} //----- Fin de Ajouter


Trajet* TableauDynamique::GetTrajet ( int i ) const
{   
    return this->tabDynamique[i];
} //----- Fin de GetTrajet


int TableauDynamique::GetNbTrajetsCourant ( ) const 
{   
    return this->nbTrajetsCourant;
} //----- Fin de GetNbTrajetsCourant


void TableauDynamique::Supprimer(int i)
{   
    // Cas d'erreur
    if(i < 0 || i > this->nbTrajetsCourant)
    {
        return;
        // cout << "Erreur : l'indice " << i << " pour la suppression n'est pas valide" << endl;
    }
    delete this->tabDynamique[i];
    this->tabDynamique[i] = nullptr;
    this->nbTrajetsCourant--;
} //----- Fin de Supprimer


void TableauDynamique::SetNbTrajetsCourant(int i)
{
    this->nbTrajetsCourant = i;
} //----- Fin de SetNbTrajetsCourant


void TableauDynamique::Modif(int i, Trajet* t)
{
    this->tabDynamique[i] = t;
} //----- Fin de Modif


//-------------------------------------------- Constructeurs - destructeur

TableauDynamique::TableauDynamique ( const TableauDynamique & autre )
{
    #ifdef MAP
        cout << "Appel au constructeur par copie de <TableauDynamique>" << endl;
    #endif

    this->nbTrajetsCourant = autre.nbTrajetsCourant;
    this->nbTrajetsMax = autre.nbTrajetsMax;
    this->tabDynamique = new Trajet*[this->nbTrajetsMax];

    for (int i = 0; i < this->nbTrajetsCourant; ++i) {
        this->tabDynamique[i] = new Trajet(*autre.tabDynamique[i]);
    }
} //----- Fin de TableauDynamique (constructeur par copie)


TableauDynamique::TableauDynamique()
{
    this->nbTrajetsCourant = 0;
    this->nbTrajetsMax = 10;
    this->tabDynamique = new Trajet*[this->nbTrajetsMax];
} //----- Fin de TableauDynamique (constructeur par défaut)


TableauDynamique::TableauDynamique(int tabSizeInit) 
{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif

this->nbTrajetsCourant = 0;
this->nbTrajetsMax = tabSizeInit;
this->tabDynamique = new Trajet*[this->nbTrajetsMax];

} //----- Fin de TableauDynamique


TableauDynamique::~TableauDynamique ( )

{
#ifdef MAP
    cout << "Appel au destructeur de <TableauDynamique>" << endl;
#endif

for(int i = 0; i < this->nbTrajetsCourant; i++)
{
    delete this->tabDynamique[i];
}

delete[] this->tabDynamique;

} //----- Fin de ~TableauDynamique