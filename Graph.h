#pragma once

#include <vector>

class Graph
{
    public:
        Graph();
        ~Graph();

        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        bool hasEdge(int i, int j);
        int outEdges(int i);
        int inEdges(int i);
        void PrintOutAdjacencyMatrix();
        void DFS(int i, int j);
        void BFS(int i, int j);

    private:
        int i;
        int j;
        std::vector<int> allInts;
}; 