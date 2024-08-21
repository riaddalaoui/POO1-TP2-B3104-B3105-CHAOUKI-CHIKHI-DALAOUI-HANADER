#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <map>

class DirectedGraph {
public:
    // Constructeur
    DirectedGraph();

    // Ajouter une arête au graphe
    void addEdge(const std::string& from, const std::string& to, const std::string& label);

    // Ajouter un nœud au graphe
    void addNode(const std::string& node);

    // Parcours en profondeur à partir d'un sommet
    void dfs(const std::string& start, const std::string& target);

private:
    // Liste d'adjacence représentant le graphe
    std::map<std::string, std::vector<std::pair<std::string, std::string> > > adjList;

    // Fonction récursive pour le parcours en profondeur
    void dfsRecursive(const std::string& start, const std::string& target, std::set<std::string>& visited, std::vector<std::string>& path, std::vector<std::string>& edgeLabels);
};

#endif // DIRECTEDGRAPH_H
