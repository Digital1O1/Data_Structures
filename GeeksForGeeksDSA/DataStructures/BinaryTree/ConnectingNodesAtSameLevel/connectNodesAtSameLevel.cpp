#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *nextRight;

    Node(int key)
    {
        data = key;
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
    queue<Node *> q;
    q.push(root);
    q.push(nullptr); // Level delimiter to indicate the end of a level

    while (!q.empty())
    {
        Node *node = q.front();

        // pop() used to get rid of value since it's not needed anymore in the queue
        q.pop();

        if (node)
        {
            node->nextRight = q.front(); 

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(nullptr); // New level delimiter
        }
    }

    return root;
}

// Function to print nodes level-by-level
void printLevels(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr); // Level delimiter

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node)
        {
            cout << node->data << " ";

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else
        {
            cout << "|" << endl;

            if (!q.empty())
            {
                q.push(nullptr);
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
