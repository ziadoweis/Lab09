#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>

class Graph
{
    public:
        int nodes;
        bool found = false;

        struct DFS_Output {
            bool DFSfound;
            std::string DFSpath;
        };

        struct BFS_Output {
            bool BFSfound;
            std::string BFSpath;
        };

        Graph();
        ~Graph();

        void initializeMatrix(int nodes);
        
        bool addEdge(int i, int j);
        bool removeEdge(int i, int j);
        bool hasEdge(int i, int j);
        std::vector<int> outEdges(int row);
        std::vector<int> inEdges(int col);
        void PrintOutAdjacencyMatrix();
        DFS_Output DFS(int start, int target);
        BFS_Output BFS(int start, int target);

        int matrixFromInfile();
        std::string matrixToOutfile() const;

    private:
        int rows;
        int cols;
        // std::vector<int> listOutEdges;
        // std::vector<int> listInEdges;
        std::vector< std::vector<int> > matrix;

};