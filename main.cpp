#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc);
 
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    char yesNo;
    Graph g;

    int inputNodes;

    std::string theInput;

    std::cout << "\nHow many nodes are in the graph?" << std::endl;

    std::getline(std::cin, theInput);

    while(std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("0123456789") != std::string::npos) {

        std::cout << "Error! Please input a NUMBER of nodes." << std::endl;

        if( theInput.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }

        std::getline(std::cin, theInput);
    }

    std::string::size_type st;
    inputNodes = std::stoi(theInput,&st); 
    // inspired by https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer

    g.nodes = inputNodes;

    // Yes or no do you want to read in from a file...
    std::cout << "Do you want to read a starter matrix from a text file? [Y/N]" << std::endl;
    std::cin >> yesNo;

    if ((yesNo == 'Y') || (yesNo == 'y')) {
        g.matrixFromInfile();
    }
    else if ((yesNo == 'N') || (yesNo == 'n')) {
        g.initializeMatrix(inputNodes);
    }
    
    
    std::string choice = "";
    int int_choice;


    bool progRun = true;
    bool chosen = false;
    int i, j;
    std::vector<int> outList;
    std::vector<int> inList;
    std::stringstream ss;
    std::string str;


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
           
            if ((choice == "1") || (choice == "2") || (choice == "3") || (choice == "4") || (choice == "5")
                || (choice == "6") || (choice == "7")) { chosen = true; }
            else {
                std::cout << "Oops! That doesn't seem to be a valid option. Please select an option from 1-7." << std::endl;
                chosen = false;
            }
            // std::cout << "chosen is " << chosen << "\n";
            // return 0;
        }

        int_choice = stoi(choice);

        switch (int_choice) {
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
                outList = g.outEdges(i);

                str = "";
                for (int k = 0; k < outList.size(); k++) {
                    str += std::to_string(outList[k]);
                    if (k != outList.size() - 1) {
                        str += " ";
                    }
                }
 
                std::cout << "Out-Edges have been found in the following columns: " << str << std::endl;
                outList.clear();
                str = "";
                chosen = false;
                break;

            case 5:
                std::cout << "Please provide a column coordinate to check for In-Edges in.\n"
                          << "Column: ";
                std::cin >> j;

                std::cout << "Thank you. Checking for In-Edges now in column " << j << " now." << std::endl;
                inList = g.inEdges(j);

                str = "";
                for (int k = 0; k < inList.size(); k++) {
                    str += std::to_string(inList[k]);
                    if (k != inList.size() - 1) {
                        str += " ";
                    }
                }
 
                std::cout << "In-Edges have been found in the following rows: " << str << std::endl;
                inList.clear();
                str = "";
                chosen = false;
                break;

            case 6:
                std::cout << "\nPrinting Out Adjacency Matrix. Please Standby.\n" << std::endl;
                g.PrintOutAdjacencyMatrix();
                std::cout << "\nAdjacency Matrix has been printed." << std::endl;
                chosen = false;
                break;

            case 7:
                std::cout << "\nQUITTING PROGRAM..." << std::endl
                          << "PROGRAM HAS ENDED. HAVE A NICE DAY!" << std::endl;
                progRun = false;
                break;
        }
    }

    std::ofstream outFile;
    outFile.open("../SampleMatrix.txt");
    outFile << g.matrixToOutfile() << std::endl;
    outFile.close();

    return 0;
}