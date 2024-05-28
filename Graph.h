#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <string>
#include <vector>

class Graph {
public:
    void addVertex(const std::string& name);
    void addEdge(const std::string& from, const std::string& to, int distance);
    void removeVertex(const std::string& name);
    void displayMap();
    void displayStations();
    int getMinimumDistance(const std::string& src, const std::string& dest);
    int getMinimumTime(const std::string& src, const std::string& dest);
    bool hasPath(const std::string& src, const std::string& dest, std::unordered_map<std::string, bool>& visited);
private:
    struct Vertex {
        std::unordered_map<std::string, int> nbrs; // adjacency list with distances
    };
    std::unordered_map<std::string, Vertex> vtces;
};

#endif
