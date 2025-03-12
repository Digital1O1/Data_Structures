#include <iostream>
#include <queue>

using namespace std;

class Node
{
private:
    int data;
    Node *left, *right;

public:
    // Constructor to initialize the node
    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    // Getter method for the node's data
    int getData() const { return data; }

    // Setter method for the node's data
    void setData(int d) { data = d; }

    // Getter and setter methods for the node's left child
    Node *getLeft() const { return left; }
    void setLeft(Node *l) { left = l; }

    // Getter and setter methods for the node's right child
    Node *getRight() const { return right; }
    void setRight(Node *r) { right = r; }
};

// Function to insert a new node in the binary tree
Node *insert(Node *root, int key)
{
    // If the tree is empty, create the root node
    if (root == nullptr)
    {
        root = new Node(key);
        return root;
    }
    // Create a queue for level order traversal
    queue<Node *> q;
    q.push(root);

    // Do level order traversal until we find an empty place
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // If left child is empty, insert the new node here
        if (temp->getLeft() == nullptr)
        {
            temp->setLeft(new Node(key));
            break;
        }
        else
        {
            q.push(temp->getLeft());
        }
        // If right child is empty, insert the new node here
        if (temp->getRight() == nullptr)
        {
            temp->setRight(new Node(key));
            break;
        }
        else
        {
            q.push(temp->getRight());
        }
    }
    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->getLeft());
    cout << root->getData() << " ";
    inorder(root->getRight());
}

int main()
{
    Node *root = new Node(2);
    root->setLeft(new Node(3));
    root->setRight(new Node(4));
    root->getLeft()->setLeft(new Node(5));

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 6;
    root = insert(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}