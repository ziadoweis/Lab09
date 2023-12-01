#include "Graph.h"

Graph::Graph()
{   
    std::vector<int> listOutEdges;
    std::vector<int> listInEdges;
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
    if ((i > nodes) || (j > nodes)) {
        std::cout << "One or both of those coordinates are outside of the matrix bounds and do not exist in this matrix." << std::endl;
        return false;
    } else {
        i = i - 1;
        j = j - 1;
        if (matrix[i][j] == 0) {
            matrix[i][j] = 1;
            std::cout << "An edge has been added at the matrix coordinates (" << i+1 << "," << j+1 << ")" << std::endl;
            return true;
        } else {
            std::cout << "The edge at those coordinates already exists. A new edge cannot be added in its place." << std::endl;
            return false;
        }
    }
}

bool Graph::removeEdge(int i, int j)
{
    if ((i > nodes) || (j > nodes)) {
        std::cout << "One or both of those coordinates are outside of the matrix bounds and do not exist in this matrix." << std::endl;
        return false;
    } else {
        i = i - 1;
        j = j - 1;
        if (matrix[i][j] == 1) {
            matrix[i][j] = 0;
            std::cout << "An edge has been removed at the matrix coordinates (" << i+1 << "," << j+1 << ")" << std::endl;
            return true;
        }
        else {
            std::cout << "The edge at those coordinates doesn't exist. It cannot be removed." << std::endl;
            return false;
        }
    }
}

bool Graph::hasEdge(int i, int j)
{
    if ((i > nodes) || (j > nodes)) {
        std::cout << "One or both of those coordinates are outside of the matrix bounds and do not exist in this matrix." << std::endl;
        return false;
    } else {
        i = i - 1;
        j = j - 1;
        if (matrix[i][j] == 1) { return true; }
        return false;
    }
}

std::vector<int> Graph::outEdges(int row)
{
    std::vector<int> listOutEdges;
    int newRow = row - 1;
    // for j until col
        // if matrix(row,j) == 1
            // add to list

    for (int j = 0; j < matrix[newRow].size(); j++) {
        if (matrix[newRow][j] == 1) {
            listOutEdges.push_back(j+1);
        }
        else if (matrix[newRow][j] == 0) {
            continue;
        }
    }
    return listOutEdges;
}

std::vector<int> Graph::inEdges(int col)
{
    std::vector<int> listInEdges;
    int newCol = col - 1;
    //for i until row
        // matrix(i,col) == 1
            //add to list

    for (int i = 0; i < matrix[newCol].size(); i++) {
        if (matrix[i][newCol] == 1) {
            listInEdges.push_back(i+1);
        }
        else if (matrix[i][newCol] == 0) {
            continue;
        }
    }

    return listInEdges;
}

void Graph::PrintOutAdjacencyMatrix()
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    } 
    // roughly inspired by https://stackoverflow.com/suestions/1784573/iterator-for-2d-vector
}

Graph::DFS_Output Graph::DFS(int start, int target)
{   
    DFS_Output d;
    
    start = start - 1;
    target = target - 1;

    std::vector<bool> visited(matrix.size(), false);
    std::stack<int> s;
    std::string path;
    found = false;
    s.push(start+1);
  
    // Set source as visited
    visited[start] = true;
  
    int vis;
    while (!s.empty() && (found == false)) {
        vis = s.top() - 1;
  
        // Print the current node
        path += std::to_string(vis+1);
        s.pop();
  
        // For every adjacent vertex to the current vertex
        for (int j = 0; j < matrix[vis].size(); j++) {
            if (matrix[vis][j] == 1 && (!visited[j]) && (found == false)) {
  
                // Push the adjacent node to the stack
                s.push(j+1);
  
                // Set
                visited[j] = true;

                if (j == target) { //checks if the target is found
                    path += std::to_string(j+1);
                    found = true;
                    break;
                }

            }
        }
    }
    d.DFSfound = found;
    d.DFSpath = path;
    return d;
} // roughly inspired by https://www.geeksforgeeks.org/implementation-of-dfs-using-adjacency-matrix/
  //                     https://cplusplus.com/forum/general/47860/

Graph::BFS_Output Graph::BFS(int start, int target)
{
    start = start - 1;
    target = target - 1;

    std::vector<bool> visited(matrix.size(), false);
    std::queue<int> q;
    std::string path;
    found = false;
    q.push(start+1);
  
    // Set source as visited
    visited[start] = true;
  
    int vis;
    while (!q.empty() && (found == false)) {
        vis = q.front() - 1;
  
        // Print the current node
        path += std::to_string(vis+1);
        q.pop();
  
        // For every adjacent vertex to the current vertex
        for (int j = 0; j < matrix[vis].size(); j++) {
            if (matrix[vis][j] == 1 && (!visited[j]) && (found == false)) {
  
                // Push the adjacent node to the queue
                q.push(j+1);
  
                // Set
                visited[j] = true;

                if (j == target) { //checks if the target is found
                    path += std::to_string(j+1);
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

int Graph::matrixFromInfile()
{
    std::string filename = "../SampleMatrix.txt";
    std::ifstream file;

    file.open(filename);
    if (file.fail()) {
        std::cout << "ERROR: FILE FAILED TO OPEN" << std::endl;
        return 1;
    }

    std::string rows;
    std::vector<std::string> temp;
    //std::vector<std::vector<int>> inputMatrix;

    while (getline(file, rows))
    {
        temp.push_back(rows);
    }

    int numRows = temp.size();
    int numCols = temp.size();

    

    for (int i = 0; i < numRows; i++) {
        std::vector<char> charTemp(temp[i].begin(), temp[i].end());
        std::vector<int> intTemp;
        for (auto c : charTemp) {
            intTemp.push_back(c - '0');
        }
        matrix.push_back(intTemp);
    }

    file.close();

    return 0;
} // inspired by https://www.suora.com/How-do-I-read-a-matrix-from-a-file-in-C++

std::string Graph::matrixToOutfile() const
{
    std::string str = ""; // used for file output
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            str += std::to_string(matrix[i][j]); // used for file output
        }
        if (i != matrix.size() - 1) { str += "\n"; } // used for file output
    } 
    // roughly inspired by https://stackoverflow.com/suestions/1784573/iterator-for-2d-vector
    return str;
}
