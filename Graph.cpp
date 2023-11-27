#include "Graph.h"

Graph::Graph()
{
    //matrix = std::vector< std::vector<int> > (nodes, std::vector<int>(nodes, 0));
    listOutEdges.reserve(100);
    listInEdges.reserve(100);

}

Graph::~Graph()
{
}

void Graph::initializeMatrix(int nodes)
{
    rows = nodes;
    cols = nodes;
    for (int i = 0; i < rows; i++) {
        std::vector<int>temp;
        for (int j = 0; j < cols; j++) {
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }
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
            listOutEdges.push_back(j+1);
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
            listInEdges.push_back(i+1);
        }
    }

    return listInEdges;
}

std::string Graph::PrintOutAdjacencyMatrix()
{
    std::string str = std::to_string(nodes) + "\n"; // used for file output
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            str += std::to_string(matrix[i][j]); // used for file output
            std::cout << matrix[i][j];
        }
        if (i != matrix.size() - 1) { str += "\n"; } // used for file output
        std::cout << std::endl;
    } 
    // roughly inspired by https://stackoverflow.com/questions/1784573/iterator-for-2d-vector
    return str;
}

Graph::DFS_Output Graph::DFS(int start, int target, std::vector<bool>& visited, std::string & path)
{
 
    // Print the current node
    path += std::to_string(start) + " ";
 
    // Set current node as visited
    visited[start] = true;
    
    // For every node of the graph
    for (int j = 0; j < matrix[start].size(); j++) {
        if (j == target) { // checks if the target is found
            found = true;
            break;
        }        
        // If some node is adjacent to the current node
        // and it has not already been visited
        if (matrix[start][j] == 1 && (!visited[j]) && (found == false)) {
            DFS(j, target, visited, path);
        }
    }
    DFS_Output d;
    d.DFSfound = found;
    d.DFSpath = path;
    return d;
} // roughly inspired by https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
  //                     https://cplusplus.com/forum/general/47860/

Graph::BFS_Output Graph::BFS(int start, int target)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning

    std::vector<bool> visited(matrix.size(), false);
    std::queue<int> q;
    std::string path;
    found = false;
    q.push(start);
  
    // Set source as visited
    visited[start] = true;
  
    int vis;
    while (!q.empty() && (found == false)) {
        vis = q.front();
  
        // Print the current node
        path += std::to_string(vis) + " ";
        q.pop();
  
        // For every adjacent vertex to the current vertex
        for (int j = 0; j < matrix[vis].size(); j++) {
            if (matrix[vis][j] == 1 && (!visited[j]) && (found == false)) {
  
                // Push the adjacent node to the queue
                q.push(j);
  
                // Set
                visited[j] = true;

                if (j == target) { //checks if the target is found
                    found = true;
                    break;
                }

            }
        }
    }
    BFS_Output b;
    b.BFSfound = found;
    b.BFSpath = path;
    return b;
}

int Graph::matrixByFile(int nodes)
{
    std::string filename = "SampleMatrix.txt";
    std::ifstream file;

    file.open(filename);
    if (file.fail()) {
        std::cout << "ERROR: FILE FAILED TO OPEN" << std::endl;
        return 1;
    }

    file >> nodes;
    rows = nodes;
    cols = nodes;
    matrix.resize(nodes);
    for (int i = 0; i < rows; ++i) matrix[i].resize(cols); // inspired by https://www.quora.com/How-do-I-read-a-matrix-from-a-file-in-C++

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }

    file.close();

    return 0;
}
