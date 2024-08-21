/*************************************************************************
                                DirectedGraph  -  
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <DirectedGraph> (fichier DirectedGraph.cpp) ------------

#include "DirectedGraph.h"

// Constructeur
DirectedGraph::DirectedGraph() {
    // Pas besoin d'initialiser adjList avec une taille, car c'est maintenant une map
}

// Implémentation de la fonction pour ajouter un nœud au graphe
void DirectedGraph::addNode(const std::string& node) {
    // Insérer un nouveau nœud dans la liste d'adjacence
    if (adjList.find(node) == adjList.end()) {
        adjList[node] = std::vector<std::pair<std::string, std::string> >();
    }
}


// Ajouter une arête au graphe
void DirectedGraph::addEdge(const std::string& from, const std::string& to, const std::string& label) {
    adjList[from].emplace_back(to, label);
}

// Parcours en profondeur à partir d'un sommet
void DirectedGraph::dfs(const std::string& start, const std::string& target) {
    std::set<std::string> visited;
    std::vector<std::string> path;
    std::vector<std::string> edgeLabels;

    dfsRecursive(start, target, visited, path, edgeLabels);
}

// Fonction récursive pour le parcours en profondeur
void DirectedGraph::dfsRecursive(const std::string& start, const std::string& target, std::set<std::string>& visited, std::vector<std::string>& path, std::vector<std::string>& edgeLabels) {
    visited.insert(start);
    path.push_back(start);

    if (start == target) {
        std::cout << "Pour partir de " << path[0] << " et arriver a " << target << " vous pouvez prendre : ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < edgeLabels.size()) {
                std::cout << " --( " << edgeLabels[i];
            }
            if (i < path.size() - 1) {
                std::cout << " )-> ";
            }
        }
        std::cout << std::endl;
    } else {
        for (const auto& edge : adjList[start]) {
            if (visited.find(edge.first) == visited.end()) {
                edgeLabels.push_back(edge.second);
                dfsRecursive(edge.first, target, visited, path, edgeLabels);
                edgeLabels.pop_back(); // Retour en arrière pour l'étiquette de l'arête
            }
        }
    }

    path.pop_back(); // Retour en arrière pour le sommet
    visited.erase(start); // Désélectionner le sommet
}
