#include "Graph.h"
#include <iostream>

Graph::Graph()
{
    matrix = std::vector< std::vector<int> > (nodes, std::vector<int>(nodes, 0));
    listOutEdges.reserve(100);
    listInEdges.reserve(100);
}

Graph::~Graph()
{
}

bool Graph::addEdge(int i, int j)
{
    if (matrix[i][j] != 1) {
        matrix[i][j] = 1;
        std::cout << "An edge has been added at the matrix coordinates (" << i << "," << j << ")" << std::endl;
        return true;
    } else {
        std::cout << "The edge at those coordinates already exists. A new edge cannot be added in its place." << std::endl;
        return false;
    }
}

bool Graph::removeEdge(int i, int j)
{
    if (matrix[i][j] != 0) {
        matrix[i][j] = 0;
        std::cout << "An edge has been removed at the matrix coordinates (" << i << "," << j << ")" << std::endl;
        return true;
    }
    else {
        std::cout << "The edge at those coordinates doesn't exist. It cannot be removed." << std::endl;
        return false;
    }
}

bool Graph::hasEdge(int i, int j)
{
    if (matrix[i][j] == 1) { return true; }
    return false;
}

std::vector<int> Graph::outEdges(int row)
{
    // for j until col
        // if matrix(row,j) == 1
            // add to list

    for (int j = 0; j < matrix.size(); j++) {
        if (matrix[row][j] == 1) {
            listOutEdges.push_back(j);
        }
    }

    return listOutEdges;
}

std::vector<int> Graph::inEdges(int col)
{
    //for i until row
        // matrix(i,col) == 1
            //add to list

    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][col] == 1) {
            listInEdges.push_back(i);
        }
    }

    return listInEdges;
}

void Graph::PrintOutAdjacencyMatrix()
{
        
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            std::cout << matrix[i][j] << std::endl;
        }
    } 
    // derived from https://stackoverflow.com/questions/1784573/iterator-for-2d-vector
}

void Graph::DFS(int i, int j)
{

}

void Graph::BFS(int i, int j)
{
}
