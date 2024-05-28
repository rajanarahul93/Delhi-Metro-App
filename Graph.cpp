#include "Graph.h"
#include <iostream>
#include <queue>
#include <climits>
#include <unordered_set>

// Add a vertex to the graph
void Graph::addVertex(const std::string& name) {
    if (vtces.find(name) == vtces.end()) {
        Vertex vtx;
        vtces[name] = vtx;
    }
}

// Add an edge to the graph
void Graph::addEdge(const std::string& from, const std::string& to, int distance) {
    if (vtces.find(from) != vtces.end() && vtces.find(to) != vtces.end()) {
        vtces[from].nbrs[to] = distance;
        vtces[to].nbrs[from] = distance;
    }
}

// Remove a vertex from the graph
void Graph::removeVertex(const std::string& name) {
    if (vtces.find(name) != vtces.end()) {
        for (auto& vertexPair : vtces) {
            vertexPair.second.nbrs.erase(name);
        }
        vtces.erase(name);
    }
}

// Display the graph
void Graph::displayMap() {
    for (const auto& vertexPair : vtces) {
        const std::string& key = vertexPair.first;
        const Vertex& vtx = vertexPair.second;
        std::cout << key << " =>" << std::endl;
        for (const auto& nbrPair : vtx.nbrs) {
            const std::string& nbr = nbrPair.first;
            int dist = nbrPair.second;
            std::cout << "\t" << nbr << "\t" << dist << std::endl;
        }
    }
}

// Display the stations in the graph
void Graph::displayStations() {
    for (const auto& vertexPair : vtces) {
        const std::string& key = vertexPair.first;
        std::cout << key << std::endl;
    }
}

// Get the minimum distance between two vertices using Dijkstra's algorithm
int Graph::getMinimumDistance(const std::string& src, const std::string& dest) {
    std::unordered_map<std::string, int> distances;
    for (const auto& vertexPair : vtces) {
        const std::string& key = vertexPair.first;
        distances[key] = INT_MAX;
    }
    distances[src] = 0;

    using P = std::pair<int, std::string>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto current = pq.top();
        int currentDist = current.first;
        std::string currentVtx = current.second;
        pq.pop();

        if (currentVtx == dest) return currentDist;

        for (const auto& nbrPair : vtces[currentVtx].nbrs) {
            const std::string& nbr = nbrPair.first;
            int weight = nbrPair.second;
            int newDist = currentDist + weight;
            if (newDist < distances[nbr]) {
                distances[nbr] = newDist;
                pq.push({newDist, nbr});
            }
        }
    }

    return INT_MAX;
}

// Get the minimum time between two vertices
int Graph::getMinimumTime(const std::string& src, const std::string& dest) {
    return getMinimumDistance(src, dest); // Assuming time and distance are the same
}

// Check if there's a path between two vertices
bool Graph::hasPath(const std::string& src, const std::string& dest, std::unordered_map<std::string, bool>& visited) {
    if (src == dest) return true;
    visited[src] = true;

    for (const auto& nbrPair : vtces[src].nbrs) {
        const std::string& nbr = nbrPair.first;
        if (!visited[nbr] && hasPath(nbr, dest, visited)) {
            return true;
        }
    }

    return false;
}
//Graph.cpp//