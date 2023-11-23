#pragma once

#include <vector>

class Graph
{
    public:
        int nodes = 100;

        Graph();
        ~Graph();

        bool addEdge(int i, int j);
        bool removeEdge(int i, int j);
        bool hasEdge(int i, int j);
        std::vector<int> outEdges(int row);
        std::vector<int> inEdges(int col);
        void PrintOutAdjacencyMatrix();
        void DFS(int i, int j);
        void BFS(int i, int j);

    private:
        //int i;
        //int j;
        std::vector<int> listOutEdges;
        std::vector<int> listInEdges;
        std::vector< std::vector<int> > matrix;

};