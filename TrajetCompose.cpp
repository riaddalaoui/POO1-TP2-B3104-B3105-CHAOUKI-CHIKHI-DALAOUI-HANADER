/*********************************************************************************************************************************************
                TrajetCompose  -  Classe définissant un trajet compose de plusieurs trajets simples
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher (  ) const
{   
    const int j = this->GetTableau().GetNbTrajetsCourant();

    for(int i = 0; i < j; i++)
    {   

        const Trajet * trajet_i = this->GetTableau().GetTrajet(i);
        if(i==0){
            cout << " " << trajet_i->GetDepart() << " ------ " << "( " << trajet_i->GetTransport() << " )"<< " ------> " << trajet_i->GetArrivee();
        }else{
            cout << " ------ " << "( " << trajet_i->GetTransport() << " )"<< " ------> " << trajet_i->GetArrivee();
        }
        

    }
    cout<< endl;
} //----- Fin de Afficher


const TableauDynamique& TrajetCompose::GetTableau (  ) const
{   
    return this->tabDynamique;
} //----- Fin de GetTableau


int TrajetCompose::GetNbEscales (  ) const
{
    return this->nbEscales;
} //----- Fin de GetNbEscales


const TrajetSimple* TrajetCompose::RechercheDansTrajetCompose(const char* VilleA, const char* VilleB) 
{
        for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
            TrajetSimple* trajet = (TrajetSimple*) tabDynamique.GetTrajet(i);
            if (!strcmp(trajet->GetArrivee(), VilleB) && !strcmp(trajet->GetDepart(), VilleA)) {
                return trajet;
            }
        }
        return nullptr;
} //----- Fin de RechercheDansTrajetCompose


bool TrajetCompose::operator==(const Trajet& autre) const 
{
    const TrajetCompose* autreCompose = dynamic_cast<const TrajetCompose*>(&autre);
    if (!autreCompose) {
        return false;
    }

    if (strcmp(this->villeDepart, autreCompose->GetDepart()) != 0 ||
        strcmp(this->villeArrivee, autreCompose->GetArrivee()) != 0 ||
        this->nbEscales != autreCompose->GetNbEscales() ||
        this->tabDynamique.GetNbTrajetsCourant() != autreCompose->GetTableau().GetNbTrajetsCourant()) {
        return false;
    }
    
    for (int i = 0; i < this->tabDynamique.GetNbTrajetsCourant(); i++) {
        if (!(*(this->tabDynamique.GetTrajet(i)) == *(autreCompose->GetTableau().GetTrajet(i)))) {
            return false;
        }
    }

    return true;
} //----- Fin de operator==


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const TrajetCompose& autre) : Trajet(autre)
{   
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    this->nbEscales = autre.GetNbEscales();
    this->tabDynamique = TableauDynamique(autre.GetTableau());
    
} //-------- Fin constructeur par copie TrajetCompose


TrajetCompose::TrajetCompose ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    char final_end[50];
    cout << endl << "Quelle est la ville d'arrivee finale de ce trajet" << endl;
    cin >> final_end;
    this->nbEscales = 0;
    char start[50];
    char end[50]="";
    char mean[50];
    while(strcmp(end,final_end))
    {   
        if(this->nbEscales==0){
            cout << endl << "Veuillez saisir la ville de depart du trajet compose:" << endl;
            cin >> start;
            cout << endl << "Veuillez saisir la ville suivante:" << endl;
            cin >> end;
            cout << endl<< "Veuillez saisir le mode de transport:" << endl;
            cin >> mean;
            TrajetSimple * TS = new  TrajetSimple(start, end, mean);
            this->tabDynamique.Ajouter(TS);
            this->nbEscales++;
            strcpy(this->villeArrivee, final_end);
            strcpy(this->villeDepart, start);
        }else{
            strcpy(start,end);
            cout << endl << "Veuillez saisir la ville suivante:" << endl;
            cin >> end;
            cout << endl<< "Veuillez saisir le mode de transport:" << endl;
            cin >> mean;
            TrajetSimple * TS = new TrajetSimple(start, end, mean);
            this->tabDynamique.Ajouter(TS);
        }
    }



} //----- Fin de TrajetCompose  (constructeur par défaut)


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif


} //----- Fin de ~TrajetCompose