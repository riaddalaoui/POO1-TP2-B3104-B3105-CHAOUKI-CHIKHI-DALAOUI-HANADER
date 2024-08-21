/*********************************************************************************************************************************************
                                TrajetSimple  -  Classe définissant un trajet simple
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//----------------------------------------------------- Méthodes publiques

const char * TrajetSimple::GetTransport () const
{
    return this->moyenTransport; 
} //----- Fin de GetTransport

void TrajetSimple::Afficher (  ) const
{   
    cout << " " << this->villeDepart << " ------ " << "( " << this->moyenTransport << " )"<< " ------> " <<this->villeArrivee << endl;
} //----- Fin de Afficher


bool TrajetSimple::operator==(const Trajet& autre) const {
    const TrajetSimple* autreSimple = dynamic_cast<const TrajetSimple*>(&autre);
    if (!autreSimple) {
        return false; // Impossible de comparer un TrajetSimple avec autre chose qu'un TrajetSimple
    }

    // Comparaison des attributs pour vérifier l'égalité en utilisant les méthodes d'accès
    if (strcmp(this->GetDepart(), autreSimple->GetDepart()) != 0 ||
        strcmp(this->GetArrivee(), autreSimple->GetArrivee()) != 0 ||
        strcmp(this->GetTransport(), autreSimple->GetTransport()) != 0) {
        return false;
    }

    return true;
} //----- Fin de operator==


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const TrajetSimple& autre) : Trajet(autre)
{   
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif

    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    strcpy(this->moyenTransport, autre.GetTransport());
} //-------- Fin constructeur par copie TrajetSimple


TrajetSimple::TrajetSimple (  )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
cout << endl << "Veuillez saisir la ville de depart :" << endl;
cin >> this->villeDepart;
cout << endl << "Veuillez saisir la ville d'arrivee :" << endl;
cin >> this->villeArrivee;
cout << endl<< "Veuillez saisir le mode de transport" << endl;
cin >> this->moyenTransport;

} //----- Fin de TrajetSimple


TrajetSimple::TrajetSimple ( char A[50], char B[50],char T[50] ){
    strcpy(this->villeDepart,A);
    strcpy(this->villeArrivee,B);
    strcpy(moyenTransport,T);
};


TrajetSimple::~TrajetSimple ( )
//Destructeur
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple