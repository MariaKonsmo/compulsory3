#include "General_tree_class.h"


//This is the constructor for the GeneralTree class. It takes an integer value val as a parameter and is responsible for creating an instance of the GeneralTree class.
GeneralTree::GeneralTree(int val) {
    root = new TreeNode(val);//  Inside the constructor:It creates a new TreeNode with the specified value val and sets it as the root of the general tree.
}

//This method returns the root of the general tree. 
TreeNode* GeneralTree::getRoot() {
    return root;// It simply returns the root member variable, which is a pointer to the root node.
}

//This method checks if the general tree is empty, meaning it has no nodes. It does this by checking if the root is nullptr. 
// If the root is nullptr, it returns true, indicating that the tree is empty; otherwise, it returns false.
bool GeneralTree::isEmpty() {
    return root == nullptr;
}

//This method checks if a given node is a leaf node. It takes a TreeNode* as a parameter. A leaf node is a node that has no children. 
// It returns true if the provided node's children list is empty, indicating that it's a leaf node; otherwise, it returns false.
bool GeneralTree::isLeaf(TreeNode* node) {
    return node->children.empty();
}

//This method calculates and returns the size of the sub-tree rooted at the provided node. 
// The size of a sub-tree is the number of nodes in that sub-tree. It does this recursively:
int GeneralTree::size(TreeNode* node) {
    if (node == nullptr) return 0;//If the provided node is nullptr, it returns 0.
    int count = 1;//Otherwise, it initializes count to 1 (counting the current node)
    for (TreeNode* child : node->children) {//and then iterates through the children of the node.
        count += size(child);//For each child, it calls size() recursively and adds the result to the count.
    }
    return count;//Finally, it returns the count, which represents the size of the sub-tree.
}

//This method calculates and returns the depth of the sub-tree rooted at the provided node. 
// The depth of a sub-tree is the maximum distance from the root to a leaf node within that sub-tree. It does this recursively:
int GeneralTree::depth(TreeNode* node) {
    if (node == nullptr) return 0;//If the provided node is nullptr, it returns 0.
    int maxDepth = 0;//It initializes maxDepth to 0 
    for (TreeNode* child : node->children) {//and iterates through the children of the node
        maxDepth = std::max(maxDepth, depth(child));//For each child, it calls depth() recursively and updates maxDepth with the maximum depth value found in the children.
    }
    return 1 + maxDepth;//Finally, it returns 1 + maxDepth, which accounts for the depth of the current node and the maximum depth found among its children.
}

//This method checks if a given node is the root of the general tree. It takes a TreeNode* as a parameter and compares it to the root of the tree. 
bool GeneralTree::isRoot(TreeNode* node) {
    return node == root;// If the provided node is the same as the root, it returns true, indicating that it's the root node; otherwise, it returns false.
}

//This method inserts a new node with the given value val as a child of the specified parent node. 
// If the parent is not nullptr, it appends the new node to the children list of the parent node. This method allows you to add nodes to the tree structure.
void GeneralTree::insert(TreeNode* parent, int val) {
    if (parent != nullptr) {
        parent->children.push_back(new TreeNode(val));
    }
}

//This method is used to delete a node and its entire sub-tree rooted at the provided node. It uses a recursive approach:



void GeneralTree::deleteNode(TreeNode* node) {
    if (node == nullptr) return;//If the provided node is nullptr, it returns immediately.
    for (TreeNode* child : node->children) {//It iterates through the children of the node 
        deleteNode(child);//and recursively calls deleteNode() for each child.
    }
    delete node;//After deleting the children, it deletes the current node.This operation effectively removes the entire sub - tree.
}

//This method performs a depth-first traversal of the sub-tree rooted at the provided node. 




void GeneralTree::depthFirstTraversal(TreeNode* node) {
    if (node == nullptr) return;//It starts at the provided node and visits all nodes in a depth-first manner, printing the data of each visited node. The traversal is performed using a recursive approach://If the provided node is nullptr, it returns immediately.
    std::cout << node->data << " ";//It prints the data of the current node using std::cout.
    for (TreeNode* child : node->children) {//It then iterates through the children of the node
        depthFirstTraversal(child); //and recursively calls depthFirstTraversal() for each child.This way, it explores all the nodes in a depth - first order.
    }
}