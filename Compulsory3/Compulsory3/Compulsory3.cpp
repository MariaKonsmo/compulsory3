#include <iostream>
#include "General_tree_class.h"
#include "Graph_class.h"

int main() {

    // GeneralTree
    GeneralTree tree(1);//This line creates an instance of the GeneralTree class named tree. It uses the constructor that takes an integer value 1 as a parameter to create the tree. This value 1 is used to initialize the root of the general tree.
    TreeNode* root = tree.getRoot();//This line retrieves the root of the tree by calling the getRoot() method. It assigns the root node to a pointer variable named root. The root variable now holds a pointer to the root node of the general tree.
    tree.insert(root, 2);//This line inserts a new node with the value 2 as a child of the root node. It uses the insert() method of the GeneralTree class, passing the root node as the parent and 2 as the value for the new child node
    tree.insert(root, 3);
    TreeNode* node2 = root->children[0];//This line assigns the first child of the root node to a pointer variable node2. It is achieved by accessing the children vector of the root node using the index [0]. After this operation, node2 points to the node with value 2.
    tree.insert(node2, 4);//This line inserts a new node with the value 4 as a child of node2.
    tree.insert(node2, 5);
    TreeNode* node3 = root->children[1];
    tree.insert(node3, 6);

    std::cout << "Depth-First Traversal for General tree: ";//This line uses the std::cout object to display a message to the standard output, indicating that the following traversal is a depth-first traversal of the general tree.
    tree.depthFirstTraversal(root);//This line calls the depthFirstTraversal method of the tree to perform a depth-first traversal starting from the root node. The traversal visits and prints nodes in a depth-first order, beginning from the root. In this case, it will print the nodes in the order 1, 2, 4, 5, 
    std::cout << std::endl;//After the traversal is completed, this line adds a newline character to the output, effectively moving the cursor to the next line in the console output.

    //return 0;

    // Graph
    Graph graph;//this line declares an instance of the Graph class called graph. It creates an object that represents a graph and initializes it using the default constructor.
    graph.addEdge(1, 2);//this line adds an edge between nodes 1 and 2 in the graph object. It uses the addEdge method of the Graph class to establish a connection between these two nodes.
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);


    std::cout << "Breadth-First Traversal for Grpah: ";//This line uses the std::cout object to display a message to the standard output (usually the console). It's a descriptive message indicating that the following traversal is a breadth-first traversal starting from node 1.
    graph.breadthFirstTraversal(1);//This line calls the breadthFirstTraversal method of the graph object to perform a breadth-first traversal starting from node 1. The traversal visits and prints nodes in a level-by-level fashion.
    std::cout << std::endl;//After the traversal is completed, this line adds a newline character to the output, effectively moving the cursor to the next line in the console output.

    return 0;//t returns an exit status of 0, indicating a successful execution to the operating system. An exit status of 0 typically means that the program ran without errors.
}
