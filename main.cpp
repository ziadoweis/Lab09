#include <iostream>
#include <sstream>
#include "Graph.h"

int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    
    Graph g;
    int choice;

    std::cout << "\nHow many nodes are in graph?" << std::endl;

    std::cin >> g.nodes;
    //std::cout << std::endl;

    bool progRun = true;
    bool chosen = false;
    int i, j;
    std::vector<int> list;
    std::stringstream ss;


    while (progRun == true) {
        while (chosen == false) {
            std::cout << "\nPress 1 to add an edge to graph\n" 
                      << "Press 2 to remove an edge from graph\n" 
                      << "Press 3 to find an edge in the graph\n" 
                      << "Press 4 to find the out edges of a graph\n"
                      << "Press 5 to find the in edges of a vertices\n"
                      << "Press 6 to print out adjacency matrix\n" 
                      << "Press 7 to quit" << std::endl;

            std::cin >> choice;
            if ((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4) || (choice == 5)
                || (choice == 6) || (choice == 7)) { chosen = true; }
            else { chosen = false; }
        }

    
        switch (choice) {
            case 1:
                std::cout << "Please provide row and column coordinates to add an edge to.\n"
                          << "Row: ";
                std::cin >> i;
                std::cout << "Column: ";
                std::cin >> j;

                std::cout << "Thank you. Adding edge at coordinates (" << i << "," << j << ") now." << std::endl;
                g.addEdge(i,j);
                chosen = false;
                break;
            case 2:
                std::cout << "Please provide row and column coordinates to remove an edge from.\n"
                          << "Row: ";
                std::cin >> i;
                std::cout << "Column: ";
                std::cin >> j;

                std::cout << "Thank you. Removing edge at coordinates (" << i << "," << j << ") now." << std::endl;
                g.removeEdge(i,j);
                chosen = false;
                break;

            case 3:
                std::cout << "Please provide row and column coordinates that you want to check for an edge.\n"
                          << "Row: ";
                std::cin >> i;
                std::cout << "Column: ";
                std::cin >> j;

                std::cout << "Thank you. Checking for an edge at coordinates (" << i << "," << j << ") now." << std::endl;
                if (g.hasEdge(i,j) == true) {
                    std::cout << "There exists an edge at coordinates (" << i << "," << j << ")." << std::endl;
                }
                else {
                    std::cout << "There is not an edge at coordinates (" << i << "," << j << ")." << std::endl;
                }
                chosen = false;
                break;

            case 4:
                std::cout << "Please provide a row coordinate to check for Out-Edges in.\n"
                          << "Row: ";
                std::cin >> i;

                std::cout << "Thank you. Checking for Out-Edges now in row " << i << " now." << std::endl;
                list = g.outEdges(i);

                for (auto it = list.begin(); it != list.end(); it++)    {
                    if (it != list.begin()) {
                        ss << " ";
                    }
                    ss << *it;
                }
 
                std::cout << "Out-Edges have been found in the following columns: " << ss.str() << std::endl;
                chosen = false;
                break;

            case 5:
                std::cout << "Please provide a column coordinate to check for In-Edges in.\n"
                          << "Column: ";
                std::cin >> j;

                std::cout << "Thank you. Checking for In-Edges now in column " << j << " now." << std::endl;
                list = g.outEdges(j);

                for (auto it = list.begin(); it != list.end(); it++)    {
                    if (it != list.begin()) {
                        ss << " ";
                    }
                    ss << *it;
                }
 
                std::cout << "In-Edges have been found in the following rows: " << ss.str() << std::endl;
                chosen = false;
                break;

            case 6:
                std::cout << "Printing Out Adjacency Matrix. Please Standby." << std::endl;
                g.PrintOutAdjacencyMatrix();
                std::cout << "\nAdjacency Matrix has been printed." << std::endl;
                chosen = false;
                break;

            case 7:
                std::cout << "\nQUITTING PROGRAM..." << std::endl
                          << "PROGRAM HAS ENDED. HAVE A NICE DAY!" << std::endl;
                progRun = false;
                break;
                    
            default:
                break;
        }
    }

    return 0;
}