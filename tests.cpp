#include "Graph.h"
#include <gtest/gtest.h>

/*
All tests used a 4 node adjacency matrix in
the form of: 

0100
0010
0001
1000

*/

TEST(addEdge1, InsertingEdgesThatDontExist) {
    Graph g;
    int newNodes = 4;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    //checking if the edges were added successfully
    ASSERT_TRUE(g.addEdge(1,2));
    ASSERT_TRUE(g.addEdge(2,3));
    ASSERT_TRUE(g.addEdge(3,4));
    ASSERT_TRUE(g.addEdge(4,1));

    
    // ASSERT_TRUE(g.hasEdge(1,2));
    // ASSERT_TRUE(g.hasEdge(2,3));
    // ASSERT_TRUE(g.hasEdge(4,1));
    // ASSERT_FALSE(g.hasEdge(1,1));
}

TEST(addEdge2, InsertingEdgesThatAlreadyExist) {
    Graph g;
    int newNodes = 4;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    //checking if you can add an edge over an existing edge
    ASSERT_TRUE(g.addEdge(1,2));
    ASSERT_FALSE(g.addEdge(1,2));
    ASSERT_TRUE(g.addEdge(2,3));
    ASSERT_FALSE(g.addEdge(2,3));

    
    // ASSERT_FALSE(g.addEdge(2,3));
    // ASSERT_TRUE(g.hasEdge(2,3));
    // ASSERT_FALSE(g.addEdge(1,2));
    // ASSERT_TRUE(g.hasEdge(1,2));
}

TEST(removeEdge1, RemovingEdgesThatAlreadyExist) {
    Graph g;
    int newNodes = 4;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //removing the edges that just got added
    ASSERT_TRUE(g.removeEdge(1,2));
    ASSERT_TRUE(g.removeEdge(2,3));
    ASSERT_TRUE(g.removeEdge(3,4));
    ASSERT_TRUE(g.removeEdge(4,1));

    //checking if they're still there or not
    ASSERT_FALSE(g.hasEdge(1,2));
    ASSERT_FALSE(g.hasEdge(2,3));
    ASSERT_FALSE(g.hasEdge(3,4));
    ASSERT_FALSE(g.hasEdge(4,1));
}

TEST(removeEdge2, RemovingEdgesThatDontExist) {
    Graph g;
    int newNodes = 4;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //removing the edges that don't exist
    ASSERT_FALSE(g.removeEdge(1,1));
    ASSERT_FALSE(g.hasEdge(1,1));
    ASSERT_FALSE(g.removeEdge(4,3));
    ASSERT_FALSE(g.hasEdge(4,3));
}

TEST(hasEdge1, CheckingForEdgesThatAlreadyExist) {
    Graph g;
    int newNodes = 4;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //checking for edges that already exist
    ASSERT_TRUE(g.hasEdge(1,2));
    ASSERT_TRUE(g.hasEdge(2,3));
    ASSERT_TRUE(g.hasEdge(3,4));
    ASSERT_TRUE(g.hasEdge(4,1));
}

TEST(hasEdge2, CheckingForEdgesThatDontExist) {
    Graph g;
    int newNodes = 4;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    g.removeEdge(3,4);
    g.removeEdge(4,1);

    //checking for edges that don't exist
    ASSERT_FALSE(g.hasEdge(2,6));
    ASSERT_FALSE(g.hasEdge(5,3));
    ASSERT_FALSE(g.hasEdge(4,1));
    ASSERT_FALSE(g.hasEdge(3,4));
}

TEST(outEdges1, CheckingForOutEdgesThatExist) {
    Graph g;
    std::string str = "";
    int newNodes = 4;
    std::vector<int> list;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //checking for out-edges that exist

    //test 1
    list = g.outEdges(1);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("2", str);
    str = "";
    list.clear();

    
    //test 2
    list = g.outEdges(2);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("3", str);
    str = "";
    list.clear();


    //test 3
    list = g.outEdges(3);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("4", str);
    str = "";
    list.clear();


    //test 4
    list = g.outEdges(4);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("1", str);
    str = "";
    list.clear();    
}

TEST(outEdges2, CheckingForOutEdgesThatDontExist) {
    Graph g;
    std::string str = "";
    int newNodes = 4;
    std::vector<int> list;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //checking for out-edges that exist

    //test 1
    list = g.outEdges(1);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("1",str);
    str = "";
    list.clear();

    
    //test 2
    list = g.outEdges(2);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("2", str);
    str = "";
    list.clear();


    //test 3
    list = g.outEdges(3);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("3", str);
    str = "";
    list.clear();


    //test 4
    list = g.outEdges(4);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("4", str);
    str = "";
    list.clear();    
}

TEST(inEdges1, CheckingForInEdgesThatExist) {
    Graph g;
    std::string str = "";
    int newNodes = 4;
    std::vector<int> list;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //checking for out-edges that exist

    //test 1
    list = g.inEdges(1);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("4", str);
    str = "";
    list.clear();

    
    //test 2
    list = g.inEdges(2);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("1", str);
    str = "";
    list.clear();


    //test 3
    list = g.inEdges(3);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("2", str);
    str = "";
    list.clear();


    //test 4
    list = g.inEdges(4);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_EQ("3", str);
    str = "";
    list.clear();    
}

TEST(inEdges2, CheckingForInEdgesThatDontExist) {
    Graph g;
    std::string str = "";
    int newNodes = 4;
    std::vector<int> list;
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    //checking for out-edges that exist

    //test 1
    list = g.inEdges(1);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("1",str);
    str = "";
    list.clear();

    
    //test 2
    list = g.inEdges(2);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("2", str);
    str = "";
    list.clear();


    //test 3
    list = g.inEdges(3);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("3", str);
    str = "";
    list.clear();


    //test 4
    list = g.inEdges(4);
    str = "";
    for (int k = 0; k < list.size(); k++) {
        str += std::to_string(list[k]);
        if (k != list.size() - 1) {
            str += " ";
        }
    }
    ASSERT_NE("4", str);
    str = "";
    list.clear();    
}

TEST(DFS1, CanWeReachATargetSuccessfully) {
    Graph g;
    int newNodes = 4;
    std::vector<bool> visited;
    std::string path = "";
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    bool found = g.DFS(2,1).DFSfound;
    std::string newPath = g.DFS(2,1).DFSpath;
    ASSERT_EQ(true, found);
    ASSERT_EQ("2341", newPath);

}

TEST(DFS2, CanWeReachATargetUnsuccessfully) {
    Graph g;
    int newNodes = 4;
    std::vector<bool> visited;
    std::string path = "";
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    bool found = g.DFS(1,1).DFSfound;
    std::string newPath = g.DFS(1,1).DFSpath;
    ASSERT_NE(true, found);
    ASSERT_NE("3412", newPath);
}

TEST(BFS1, CanWeReachATargetSuccessfully) {
    Graph g;
    int newNodes = 4;
    std::vector<bool> visited;
    std::string path = "";
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    bool found = g.BFS(1,4).BFSfound;
    std::string newPath = g.BFS(1,4).BFSpath;
    ASSERT_EQ(true, found);
    ASSERT_EQ("1234", newPath);
}

TEST(BFS2, CanWeReachATargetUnsuccessfully) {
    Graph g;
    int newNodes = 4;
    std::vector<bool> visited;
    std::string path = "";
    g.initializeMatrix(newNodes);
    g.nodes = newNodes;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);

    bool found = g.BFS(4,4).BFSfound;
    std::string newPath = g.BFS(4,4).BFSpath;
    ASSERT_NE(true, found);
    ASSERT_NE("44", newPath);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

