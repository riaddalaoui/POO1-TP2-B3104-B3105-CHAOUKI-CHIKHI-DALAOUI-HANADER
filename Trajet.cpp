/*********************************************************************************************************************************************
                            Trajet  -  Classe Ancêtre Abstraite de tous les Trajets
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------


//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"


//----------------------------------------------------- Méthodes publiques

const char * Trajet::GetTransport () const
{
    return nullptr;
} //----- Fin de GetTransport

int Trajet::GetNbEscales (  ) const {
    return 0;
} //----- Fin de GetNbEscales

const char * Trajet::GetDepart () const
{   
    return this->villeDepart;
} //----- Fin de GetDepart


const char * Trajet::GetArrivee () const
{   
    return this->villeArrivee;
} //----- Fin de GetArrivee


void Trajet::Afficher (  ) const 
{

} //----- Fin de Afficher

bool Trajet::operator==(const Trajet& autre) const
{ 
    
} //----- Fin de operator==


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const Trajet& autre)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet() 
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet