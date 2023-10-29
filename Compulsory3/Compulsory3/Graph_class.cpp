#include "Graph_class.h"
//empty constructure of the "graph" class. Constructors are special member functions used to initialize objects of the class. In this case, 
// the constructor initializes the graph. Since it's an empty constructor, it doesn't perform any specific initialization operations. 
// The Graph class has an empty constructor because we haven't specified any additional initialization logic for this example.
Graph::Graph() {}

//checks if graph is empty It uses the adjacencyList member variable, which is a data structure used to represent the graph as an adjacency list. 
// If the adjacencyList is empty, it means the graph has no nodes or edges, so the graph is considered empty
bool Graph::isEmpty() {
    return adjacencyList.empty();
}

//add nodes to the graph  It first checks if the node is already in the adjacency list. If the node doesn't exist, it creates an entry in the adjacency 
// list with an empty vector, indicating that the node has no adjacent neighbors. This function is necessary because you should add nodes before adding edges.
void Graph::addNode(int node) {
    if (adjacencyList.find(node) == adjacencyList.end()) {
        adjacencyList[node] = std::vector<int>();
    }
}

//adds an edge between the two nodes (node1 and node2) in the graph. It ensures that both nodes are present in the adjacency list by calling addNode() 
// for each node. Then, it adds each node to the adjacency list of the other, indicating that they are connected. 
// This is done twice for undirected graphs to ensure that the edge is bidirectional.
void Graph::addEdge(int node1, int node2) {
    addNode(node1);
    addNode(node2);

    adjacencyList[node1].push_back(node2);
    adjacencyList[node2].push_back(node1); // For an undirected graph
}

//removes an edge between the two nodes (node1 and node2) in the graph. 
// It checks if node1 exists in the adjacency list and removes node2 from its list of adjacent nodes. It does the same for node2 in the adjacency list.
void Graph::removeEdge(int node1, int node2) {
    if (adjacencyList.find(node1) != adjacencyList.end()) {
        auto it = std::find(adjacencyList[node1].begin(), adjacencyList[node1].end(), node2);
        if (it != adjacencyList[node1].end()) {
            adjacencyList[node1].erase(it);
        }
    }
    if (adjacencyList.find(node2) != adjacencyList.end()) {
        auto it = std::find(adjacencyList[node2].begin(), adjacencyList[node2].end(), node1);
        if (it != adjacencyList[node2].end()) {
            adjacencyList[node2].erase(it);
        }
    }
}

//This method retrieves the list of adjacent nodes for a given node. It checks if the node exists in the adjacency list. 
// If it does, it returns the list of its adjacent nodes; otherwise, it returns an empty vector.
std::vector<int> Graph::getAdjacentNodes(int node) {
    if (adjacencyList.find(node) != adjacencyList.end()) {
        return adjacencyList[node];
    }
    return std::vector<int>();
}

//This method returns the number of nodes in the graph. It does this by returning the size of the adjacency list, which is equivalent to the number of nodes.
int Graph::size() {
    return adjacencyList.size();
}

//This method performs a breadth-first traversal of the graph starting from a specified startNode. 
// It uses a queue to visit nodes level by level, marking them as visited to prevent revisiting. 
// The traversal is printed as it progresses, which means it visits and prints nodes layer by layer from the starting node.
void Graph::breadthFirstTraversal(int startNode) {
    std::unordered_map<int, bool> visited;
    std::queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";
        for (int neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}