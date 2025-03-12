#include <iostream>
using namespace std;

class Node
{
public:
    int data;           // Actually holds the data
    Node *left, *right; // Pointers
    Node(int d) : data(d), left(nullptr), right(nullptr) {} // Consturctor to set the values once a class object 'Node' is made
};

// Function to perform in-order traversal of the binary tree
void printInOrder(Node *node)
{
    if (node == nullptr)
        return;

    // Recursively traverse the left subtree
    // Access the left child of the current node 'node' through the 'root' pointer
    printInOrder(node->left);

    // Print the current node's data
    cout << node->data << " ";

    // Recursively traverse the right subtree
    printInOrder(node->right);
}

int main()
{
    // Initilize and allocate memory for tree nodes
    Node *root = new Node(2);

    // Where ever the -> is pointing is which variable it's pointing to
    // So the left node is pointing to the value '3'
    root->left = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(5); // Go to the left child of Node(3) which is Node(5)... We're effectively moving two levels down of the left subtree

    // Perform in-order traversal of the binary tree
    cout << "In-order traversal of the binary tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}

/*
Here's a graphic representation of an in-order traversal for the given binary tree:


       2
      / \
     3   4
    /
   5


In-order traversal visits nodes in this order: 5, 3, 2, 4.

The steps involved in in-order traversal are:

1.  Traverse the left subtree (if exists)
2.  Visit the current node
3.  Traverse the right subtree (if exists)

The graphic illustrates how these steps are applied to the given binary tree.

Note that this representation is a text-based diagram and doesn't show the actual visual appearance of a binary tree.
*/