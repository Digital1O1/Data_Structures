// C++ program for preorder traversals

#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
class Node
{
public:
    int data;
    /*
        Reason why left and right are declared as class Node*
            - Both pointers are declared to the same class (Node) since the trees are recursive data stcutures 
                - Each node either contains/points to the other nodes of the same type
            - The pointers can be declared as : Node* left;
                - But using : class Node* left
                - Makes it more explicit 
    */  
    class Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
    // Function to print preorder traversal that's called recursively
    void printPreorder(Node *node)
    {
        // If nullptr doesn't find any child node, it'll exit
        if (node == nullptr)
            return;

        // Depending on the ordering (print the value, go left or right) will dictate the type of traversal that's happening

        // Print the value of the current node
        cout << node->data << " ";

        // First recur on left subtree and keeps iterating until it hits a 'nullptr'
        printPreorder(node->left);

        // First recur on right subtree and keeps iterating until it hits a 'nullptr'
        printPreorder(node->right);
    }

    // Function to delete the entire tree (post-order deletion)
    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;

        // First delete left and right subtrees
        deleteTree(node->left);
        deleteTree(node->right);

        // Then delete the current node
        cout << "Deleting node: " << node->data << endl;
        delete node;
    }
};

// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Solution for problem : https://www.geeksforgeeks.org/problems/preorder-traversal/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
    // Node *root = new Node(1);
    // root->left = new Node(4);
    // root->right = new Node(2);

    root->left->left = new Node(4);

    // Function call
    cout << "Preorder traversal of binary tree is: \n";
    root->printPreorder(root);

    cout << "" << endl;

    // Free allocated memory
    root->deleteTree(root);
    root = nullptr; // Set root to nullptr to prevent dangling pointer issues

    return 0;
}
