#include <iostream>
#include <vector>
//unordered_map is included to use the std::unordered_map container to represent the adjacency list of the graph.
#include <unordered_map>
#include <queue>

class Graph {
    // This section contains the private members of the class. In this case, it includes a private member variable, adjacencyList, 
    // which is an unordered map that represents the adjacency list of the graph. The adjacency list associates each node with a list of its adjacent nodes.
private:
    std::unordered_map<int, std::vector<int>> adjacencyList;

    //This section contains the public members of the class, which are accessible from outside the class. 
    // These public members include constructors and various methods for manipulating and querying the graph.
public:
    Graph();
    bool isEmpty();
    void addNode(int node);
    void addEdge(int node1, int node2);
    void removeEdge(int node1, int node2);
    std::vector<int> getAdjacentNodes(int node);
    int size();
    void breadthFirstTraversal(int startNode);
};

