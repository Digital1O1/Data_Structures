#include <bits/stdc++.h>


class Node
{
    public:
    int data;
    class Node * left;
    class Node * right;

    // Consturctor
    Node(int incomingData)
    {
        //this->data = incomingData;
        data = incomingData;
        left = nullptr;
        right = nullptr;
    }
    // Don't need to pass anything to this function since we're just printing out the value of the current node
    void printNode(Node *node)
    {   
        if(node->left)
            std::cout<<"left"<<std::endl;

        std::cout << node->data  << std::endl;
    
    }
    
    //void printNode(Node *node)
    //{
    //    std::cout << node->data << std::endl;
        //std::cout << data << std::end
    //}

    // Create constructor
    // Create public variables
    // Create printout function
    // Delete all nodes
};
int main()
{
    printf("Running program now...\r\n");
   
    // Remember to use 'new' keyword to create new Node objects
    Node * root->left = new Node(1);

    root->printNode();


    printf("Done...\r\n");

    return 0;
}
