/*********************************************************************************************************************************************
                           Catalogue  -  Classe gestionnaire du Catalogue des Trajets
                                                -------------------
    début                : 22/11/2023
    auteurs              : IF3105 (Rayan - Djalil) & IF3104 (Youssef - Riad)
    e-mail               : rayan.hanader@insa-lyon.fr - djalil.chikhi@insa-lyon.fr - youssef.chaouki@insa-lyon.fr - riad.dalaoui@insa-lyon.fr
    
**********************************************************************************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//------------------------------------------------------------- Constantes
const int MAX_PATH_LENGTH = 3;


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void Catalogue::Afficher (  )
{   
    // Affiche les trajets du catalogue
    int nbTrajetsCourant = this->tabDynamique.GetNbTrajetsCourant();

    if (nbTrajetsCourant == 0)
    {
        cout << "Le catalogue est vide" << endl << endl;
    } else {
        cout << "Le catalogue contient les trajets suivants :" << endl <<endl;
        for(int i = 0; i < nbTrajetsCourant; i++)
        {
            cout << "Trajet numero " << i+1 << " : ";
            this->tabDynamique.GetTrajet(i)->Afficher();
        }
    }

} //----- Fin de Afficher

void Catalogue::Sauvegarder(){
    ofstream fichier("catalogue.txt");
    if(fichier){
        int nbTrajetsCourant = this->tabDynamique.GetNbTrajetsCourant();
        for(int i = 0; i < nbTrajetsCourant; i++)
        {
            fichier << this->tabDynamique.GetTrajet(i)->GetDepart() << " " << this->tabDynamique.GetTrajet(i)->GetArrivee() << " " << this->tabDynamique.GetTrajet(i)->GetTransport() << endl;
        }
        fichier.close();
    }else{
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }

}

void Catalogue::Ajouter ( Trajet * ptTrajet )
{
    // Ajoute un trajet au catalogue
    this->tabDynamique.Ajouter(ptTrajet);

} //----- Fin de Ajouter


/**************************** Méthode propre au DFS (bonus) ***************************
DirectedGraph* Catalogue::toGraph() {
    DirectedGraph* graph = new DirectedGraph();
    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        Trajet* trajet = tabDynamique.GetTrajet(i);
        cout << trajet->GetNbEscales() << endl;
        if(trajet->GetNbEscales() > 0){
            graph->addEdge(trajet->GetDepart(), trajet->GetArrivee(), "trajet compose");
        }else{
            graph->addEdge(trajet->GetDepart(), trajet->GetArrivee(), trajet->GetTransport());
        }
        
    }
    return graph;
} //----- Fin de DirectedGraph
******************************************************************************************/


void Catalogue::RechercheSimple (char* VilleA, char* VilleB)
{
    int nbrt = this->tabDynamique.GetNbTrajetsCourant();
    if(nbrt == 0)
    {
        cout << "Le catalogue est vide." << endl << endl;
        return;
    }

    bool trajetTrouve = false;

    cout << endl <<"Recherche simple en cours..." << endl << endl;

    for(int i= 0; i<nbrt; i++){
        Trajet * t = this->tabDynamique.GetTrajet(i);
        TrajetCompose* trajetCompose = dynamic_cast<TrajetCompose*>(t);
        if(trajetCompose){
            TrajetSimple* ts = (TrajetSimple*) trajetCompose->RechercheDansTrajetCompose(VilleA, VilleB);
            if (ts != nullptr) {
                cout << endl <<"Voici un trajet qui correspond à votre recherche (issu d'un Trajet Compose) :" << endl;
                ts->Afficher();
                trajetTrouve = true;
            }
        }

        if (!strcmp(t->GetArrivee(), VilleB) && !strcmp(t->GetDepart(), VilleA)) {
            cout << endl << "Voici un trajet qui correspond à votre recherche :" << endl;
            t->Afficher();
            trajetTrouve = true;   
        }
    }

    if (!trajetTrouve) {
        cout << endl << "Aucun trajet trouve dans le Catalogue de " << VilleA << " a " << VilleB << ".";
    }

} //----- Fin de RechercheSimple


void Catalogue::RechercheBruteForce(const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant, int tailleChemin, bool& found) {

    if (!strcmp(cheminCourant.GetTrajet(tailleChemin - 1)->GetArrivee(), VilleB)) {
        found = true;
        return;
    }

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        if(tabDynamique.GetTrajet(i) == cheminCourant.GetTrajet(tailleChemin - 1)) continue;
        Trajet* nextTrajet = tabDynamique.GetTrajet(i);

        bool alreadyExists = false;
        for(int j = 0; j < tailleChemin; j++) {
            if(nextTrajet == cheminCourant.GetTrajet(j)) {
                alreadyExists = true;
                break;
            }
        }
        
        if (alreadyExists) continue;

        if (!strcmp(cheminCourant.GetTrajet(tailleChemin - 1)->GetArrivee(), nextTrajet->GetDepart())) {
            cheminCourant.Ajouter(nextTrajet);
            RechercheBruteForce(VilleA, VilleB, cheminCourant, tailleChemin + 1, found);
            if (found) {
                break;
            } else {
                cheminCourant.Supprimer(tailleChemin - 1);
            }
        }
    }
    return;
} //----- Fin de RechercheBruteForce


void Catalogue::UneCombinaison(Trajet* startTrajet, const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant){
    

    bool found = false; // Indicateur de chemin trouvé

    for(int i = 0; i < cheminCourant.GetNbTrajetsCourant(); i++)
    {
        cheminCourant.Modif(i, nullptr);
    }
    cheminCourant.SetNbTrajetsCourant(0);

    cheminCourant.Ajouter(startTrajet);
    RechercheBruteForce(VilleA, VilleB, cheminCourant, 1, found);

    return;
} //----- Fin de UneCombinaison


void Catalogue::RechercheAvancee(const char* VilleA, const char* VilleB) {

    bool found = false; // Indicateur d'existance d'un chemin

    int nbrt = this->tabDynamique.GetNbTrajetsCourant();
    if(nbrt == 0)
    {
        cout << "Le catalogue est vide." << endl << endl;
        return;
    }
    
    cout << endl << "Recherche avancee en cours..." << endl << endl;


    // Cas où le depart ou l'arrivée n'existent pas dans le catalogue
    bool Exist = false;
    for(int i= 0; i<nbrt; i++){
        Trajet * t = this->tabDynamique.GetTrajet(i);
        if (!strcmp(t->GetArrivee(), VilleB) || !strcmp(t->GetDepart(), VilleA)) {
            Exist = true;
        }
    }
    if (!Exist) {
        cout << endl << "Aucun trajet ne relie " << VilleA << " et " << VilleB << " car au moins une de ces villes n'existe pas dans le catalogue." << endl << endl;
        return;
    }


    // Parcours tous les trajets pour stocker les trajets de départ
    TableauDynamique Departs(nbrt);
    int departsCount = 0;

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
        Trajet* startTrajet = tabDynamique.GetTrajet(i);
        
        if(!strcmp(startTrajet->GetDepart(), VilleA)) {
            // Retrait des doublons
            bool alreadyExists = false;
            for (int j = 0; j < departsCount; j++) {
                if (!strcmp(startTrajet->GetDepart(), Departs.GetTrajet(j)->GetDepart()) && !strcmp(startTrajet->GetArrivee(), Departs.GetTrajet(j)->GetArrivee())) {
                    alreadyExists = true;
                    break;
                }
            }
            TrajetCompose* trajetCompose = dynamic_cast<TrajetCompose*>(startTrajet);
            if (!alreadyExists) {
                if(strcmp(startTrajet->GetArrivee(), VilleB) == 0) {
                    cout << endl << "Un trajet direct correspondant a votre recherche est :" << endl;
                    startTrajet->Afficher();
                    found = true;
                } else if(trajetCompose){
                    TrajetSimple* ts = (TrajetSimple*) trajetCompose->RechercheDansTrajetCompose(VilleA, VilleB);
                    if (ts != nullptr) {
                        cout << endl <<"Un trajet direct correspond à votre recherche est :" << endl;
                        ts->Afficher();
                        found = true;
                    }
                } else {
                    Departs.Ajouter(startTrajet);
                    departsCount++;
                }
            }
        }
    }

    // Parcours tous les trajets de départ pour trouver les chemins possibles
    TableauDynamique cheminCourant = TableauDynamique(MAX_PATH_LENGTH); // Tableau pour stocker le chemin actuel

    for(int j=0; j<departsCount; j++){
        Trajet* startTrajet = Departs.GetTrajet(j);
        UneCombinaison(startTrajet, VilleA, VilleB, cheminCourant);
        if (cheminCourant.GetNbTrajetsCourant()!=1) {
            cout << endl << "Un ensemble de trajets correspondant à votre recherche est :" << endl;
            for(int i=0; i<cheminCourant.GetNbTrajetsCourant(); i++){
                cout << "Trajet numero " << i+1 << " : ";
                cheminCourant.GetTrajet(i)->Afficher();
                cout << endl;
                found = true;
            }
        }
    }


    if(found) cout << endl << "Fin de la recherche avancee" << endl << endl;
    else cout << endl << "Aucun chemin trouve dans le Catalogue de " << VilleA << " a " << VilleB << "." << endl << endl;
    
    return ;
} //----- Fin de RechercheAvancee

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif


} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

