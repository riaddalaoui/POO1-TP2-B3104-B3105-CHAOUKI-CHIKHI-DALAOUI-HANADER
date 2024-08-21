#include <cstring>
#include <iostream>
using namespace std;
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "TableauDynamique.h"
// #include "DirectedGraph.h"

int main()
{   
    cout << endl << "Initialisation de l'application" << endl << endl << "--------------------------------" << endl << "Auteurs : Dalaoui Riad, Chaouki Youssef, Chikhi Djalil et Hanader Rayan" << endl << endl;
    cout << "Bienvenue dans l'application de gestion de trajets" << endl << endl;
    Catalogue catalogue;
    
    int choix=0;
    while (choix != 4)
    {   

        cout << "--------------------------------   " << endl << endl << "Veuillez saisir :" << endl << endl << "\t 1 pour ajouter un trajet au catalogue" << endl
        << "\t 2 pour afficher le catalogue" << endl << "\t 3 pour rechercher un trajet" << endl << "\t 4 pour quitter l'application" << endl << endl;

        cin >> choix;
        cout << endl;

        if (choix !=1 && choix !=2 && choix !=3 && choix !=4){
            cout << endl << "Veuillez choisir un chiffre entre 1 et 4" << endl << endl;
            cin >> choix;
            cout << endl;
        }

        switch (choix)
        {
            case 1:
            {   

                cout << "Veuillez saisir :" << endl << endl << "\t 1 pour ajouter un trajet simple" << endl
                << "\t 2 pour ajouter un trajet compose" << endl << "\t 3 pour revenir au menu precedent" << endl << endl;
                int choixAjout;
                cin >> choixAjout;

                
                
                if (choixAjout == 1)
                {
                    TrajetSimple * t = new TrajetSimple();
                    catalogue.Ajouter(t);
                    cout << endl << "Trajet ajoute au catalogue avec succes !" << endl << endl;
                }
                else if (choixAjout == 2)
                {
                    TrajetCompose * t = new TrajetCompose();
                    catalogue.Ajouter(t);
                    cout << endl << "Trajet ajoute au catalogue avec succes !" << endl << endl;
                }

                else if (choixAjout==3)
                    break;

                else 
                {   
                    cout << endl << "Veuillez choisir un chiffre entre 1 et 3" << endl << endl;
                }
                break;
            }

            case 2:
            {
                catalogue.Afficher();
                break;
            }

            case 3 :
            {   
                cout << "Veuillez saisir :" << endl << endl << "\t 1 pour une recherche simple" << endl
                << "\t 2 pour une recherche avancee" << endl << "\t 3 pour revenir au menu precedent" << endl << endl;
                int choixrecherche;
                cin >> choixrecherche;

                
                
                if (choixrecherche == 1)
                {
                    cout << "Veuillez saisir la ville dont vous voulez partir :" << endl;
                    char villeDepart[50], villeArrivee[50];
                    cin >> villeDepart;
                    cout << endl << "Veuillez saisir la ville d'arrivee :" << endl;
                    cin >> villeArrivee;
                    
                    catalogue.RechercheSimple(villeDepart, villeArrivee);

                    cout << endl << endl << endl;
                    break;
                }
                else if (choixrecherche == 2)
                {
                    cout << "Veuillez saisir la ville dont vous voulez partir :" << endl;
                    char villeDepart[50], villeArrivee[50];
                    cin >> villeDepart;
                    cout << endl << "Veuillez saisir la ville d'arrivee :" << endl;
                    cin >> villeArrivee;
                    
                    catalogue.RechercheAvancee(villeDepart, villeArrivee);

                    cout << endl << endl << endl;
                    break;
                }
                ////utilisation d'include autre que iostream et string, presente pour démo.
                // else if (choixrecherche == 4)
                // {
                //     cout << "Veuillez saisir la ville dont vous voulez partir :" << endl;
                //     char villeDepart[50], villeArrivee[50];
                //     cin >> villeDepart;
                //     cout << endl << "Veuillez saisir la ville d'arrivee :" << endl;
                //     cin >> villeArrivee;

                //     DirectedGraph* graph = catalogue.toGraph();
                    
                //     graph->dfs(villeDepart, villeArrivee);

                //     delete graph;

                //     cout << endl << endl << endl;
                //     break;
                // }

                else if (choixrecherche==3)
                    break;

                else 
                {   
                    cout << endl << "Veuillez choisir un chiffre entre 1 et 4" << endl << endl;
                }
                break;
            }
        }
    }

    cout << "Merci d'avoir consulte notre application de gestion de trajets !" << endl;

    return 0;
}