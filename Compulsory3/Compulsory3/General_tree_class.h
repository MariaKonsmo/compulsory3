#include <iostream>
#include <vector>

class TreeNode {
public:
    int data;//int data;: This is a member variable of the TreeNode class that holds the data associated with the node. In this case, it's an integer value.
    std::vector<TreeNode*> children;// std::vector<TreeNode*> children;: This is a member variable that represents a list of child nodes. Each child node is of type TreeNode*, creating a vector to hold pointers to child nodes.

    TreeNode(int val) : data(val) {}//This is the constructor for the TreeNode class. It takes an integer value val as a parameter and initializes the data member with the provided value. The constructor is used to create instances of TreeNode.
};

class GeneralTree {
private:
    TreeNode* root;//This is a member variable of the GeneralTree class, representing the root of the general tree. It is a pointer to a TreeNode object.

    //These members provide the interface for interacting with the general tree.
public:
    /* : This is the constructor for the GeneralTree class.It takes an integer value val as a parameter and is responsible for creating an instance of the GeneralTree class.Inside the constructor :
     It creates a new TreeNode with the specified value val and sets it as the root of the general tree*/
    GeneralTree(int val);
    TreeNode* getRoot();
    bool isEmpty();
    bool isLeaf(TreeNode* node);
    int size(TreeNode* node);
    int depth(TreeNode* node);
    bool isRoot(TreeNode* node);
    void insert(TreeNode* parent, int val);
    void deleteNode(TreeNode* node);
    void depthFirstTraversal(TreeNode* node);
};


