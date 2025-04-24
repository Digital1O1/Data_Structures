#include <iostream>
#include <queue>

using namespace std;
// Reference : https://www.geeksforgeeks.org/connect-nodes-level-level-order-traversal/
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *nextRight;

    Node(int key)
    {
        // The actual data
        data = key;

        // The pointers 
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

// Sets nextRight of all nodes of a tree
Node *connect(Node *root)
{
    if (!root)
        return root;

    // Remember queue<Node *> is a FIFO container adaptor from the C++ STL
    // Below creates a queue that's a node pointer called 'waitList'
    queue<Node *> waitList;
    waitList.push(root);
    waitList.push(nullptr); // Level delimiter to indicate the end of a level

    while (!waitList.empty())
    {
        // 'Grab' the first element (in this case root) in the 'waitList' queue
        Node *node = waitList.front();

        // pop() used to get rid of value since it's not needed anymore in the queue
        waitList.pop();

        // Checks if the node is valid or not
        if (node)
        {
            // Process the next value in the queue (waitList)
            
            // Grabs the next node in line from queue w/o removing it then sets the current 
            // node 'nextRight' poitner to the next node in the queue
            node->nextRight = waitList.front(); 

            // Reminder, the 'left' or 'right' pointer is being passed in the main function
            if (node->left)
                waitList.push(node->left);
            if (node->right)
                waitList.push(node->right);
        }

        // Eventually, 'waitList' will pop() the nullptr that marks the end of the current level.
        // If the queue is not empty after this, it means there are nodes on the next level —
        // so we push another nullptr to mark the end of that level.

        else if (!waitList.empty())
        {
            waitList.push(nullptr); // New level delimiter
        }
    }

    return root;
}

// Function to print nodes level-by-level
void printLevels(Node *root)
{
    if (!root)
        return;

    queue<Node *> waitList;
    waitList.push(root);
    waitList.push(nullptr); // Level delimiter

    while (!waitList.empty())
    {
        Node *node = waitList.front();
        waitList.pop();

        if (node)
        {
            cout << node->data << " ";

            if (node->left)
                waitList.push(node->left);
            if (node->right)
                waitList.push(node->right);
        }
        else
        {
            cout << "|" << endl;

            if (!waitList.empty())
            {
                waitList.push(nullptr);
            }
        }
    }
}

int main()
{
    // Constructed binary tree is
    //       10
    //      /  \
    //    8     2
    //   /        \
    //  3          90

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(90);

    connect(root);
    printLevels(root);

    return 0;
}
