# [Binary Tree Data Structure](https://www.geeksforgeeks.org/binary-tree-data-structure/)
## What is it
- Hierarchical data structure
- Each node has **at most** two children
  - Commonly referred to as the `left` and `right` child 
- Commonly used for `efficient storage` and `retrieval of data` 
  - Along side various operations like
    - Insertion
    - Deletion
    - Traversal

# [Introduction](https://www.geeksforgeeks.org/introduction-to-binary-tree/)
## Binary Trees are 
- Non-linear 
- A hierarchical data structure that has at most two children 
  - Commonly referred to as the `left` and `right` child 
- Top most binary tree is called `the root`
- Bottom most binary tree is called `the leaves` 

![alt text](../../Screenshots/Introduction-to-Binary-Tree.png)


# Representation of a Binary Tree
- Each node has three parts
  - Data 
  - Pointer to the left child
  - Pointer to the right child

![alt text](../../Screenshots/Binary-Tree-Representation.png)

## Create/Declare a Node of a Binary Tree

```cpp
// Use any below method to implement Nodes of binary tree

// 1: Using struct
struct Node {
    int data;
    Node* left, * right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

// 2: Using class

// Node* is a self-referential class since it has pointers to other objects of the same type (Node)
// This is needed for DS list tree structures, linked lists and other recursive data structures
class Node {
public:
    int data;
    Node* left, * right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};
```

## Example of Creating a Binary Tree

![alt text](../../Screenshots/Binary-Tree-with-three-nodes.jpeg)

```cpp
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

int main(){
    // Initilize and allocate memory for tree nodes
    Node* firstNode = new Node(2); // Parent node of 2 and 3
    Node* secondNode = new Node(3); // Parent node of 5
    Node* thirdNode = new Node(4); // No kids 
    Node* fourthNode = new Node(5); // Child of 3 and is still considered a leaf node since it doesn't have kids

    // Connect binary tree nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;
    return 0;
}
```

## In the code above 
- Four tree nodes were created and have connected those node to form the tree structure as mentioned in the above image 
  - firstNode that has the value 2
  - secondNode that has the value 3
    - Connected to the left of `firstNode` by `firstNode->left = secondNode`
  - thirdNode that has the value 4
    - Connected to the `right` of `firstNode` by `firstNode->right = thirdNode`
  - fourthNode that has the value 5
    - Connected to the left of `secondNode` by `secondNode->left = fourthNode`

![alt text](../../Screenshots/Binary-Tree-with-three-nodes.jpeg)

## Binary Tree Terminology

| **Terminology** | **Definition** |
| --- | --- |
| Node | A fundamental part of a binary tree, containing data and links to two child nodes. |
| Root | The topmost node in a tree, with no parent and serving as the starting point for all nodes. |
| Parent Node | A node with one or more child nodes, having at most two children per node. |
| Child Node | A descendant of another node (its parent), having zero or more parents. |
| Leaf Node | A node without any children or both children being null. |
| Internal Node | A node with at least one child, excluding the root and leaf nodes. |
| Depth of a Node | The number of edges from a specific node to the root node, starting from zero. |
| Height of a Binary Tree | The number of nodes from the deepest leaf node to the root node, indicating the maximum depth of the tree. |

### Below shows all the terms in a Binary Tree

![alt text](../../Screenshots/Terminologies-in-Binary-Tree-in-Data-Structure_1.jpeg)