# [What is a Circular Linked List](https://www.geeksforgeeks.org/circular-linked-list/#)

-   All nodes form a circle
-   First and last node **connected**
-   No **NULL** at the end

<br>

# Two types of circular linked lists

## Circular **SINGLY** Linked List

-   Last node of list has **pointer** to the first node of the list
-   When traversing the entire circular singly linked list will be from **start** to **end**
    -   Since there's no **NULL** value present

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/a0bf7c84-604f-484b-b51f-aaff2ded8631)

## Circular **DOUBLY** linked list

-   Has properties of **both** doubly/circular linked lists
    -   Two consecutive elements are linked/connected by the previous and next pointer
    -   The last node points to the first node
        -   By the next pointer
    -   The first node points to the last node
        -   By the previous pointer

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/2156ce1c-6193-4a04-bc5f-4a7a8a4d2727)

<br>

# Representation of circular SINGLY linked list:

```cpp
class Node
{
    public:
        // Store incoming data
        int value;
        // Points to the next node.
        Node *next;
}
```

# Example of Circular Singly Linked List

![image](https://github.com/Digital1O1/ESP32_MindWave_Project/assets/39348633/414a6fea-3e3c-43ab-a0b2-afba3b8be668)

```cpp

// Initialize the Nodes and add a value to them
Node one = new Node(3);
Node two = new Node(5);
Node three = new Node(9);

// Connect nodes these 'interlink' the nodes to one another
// Variable to be changed = Destination
one->next = two;        // 3 --> 5
two->next = three;      // 5 --> 9
three->next = one;      // 9 --> 3
```

<br>

# Operations on the circular linked list:

Operations on Circular that are similar to Singly

-   Insertion
-   Deletion

<br>

# Adding a node 3 ways

1. At the beginning of the list
2. At the end of the list
3. Between the nodes

<br>

## Insertion in an empty List:

```cpp
// C++ program for the above operation
Node *addToEmpty(Node *tail, int data)
{
    // This function is only for empty list
    if (tail != NULL)
        return tail;

    // Creating a node dynamically.
    // tail -> NULL
    Node *new_node = new Node();

    // Assigning the data.
    // new_node -> [data]
    new_node->data = data;

    // Update tail pointer to point towards new_node
    // tail -> new_node
    tail = new_node;

    // Creating the link that loops around to the first node
    // new_node -> [data | next] --+
    //           ^               |
    //           |_______________|
    tail->next = tail;
    return tail;
    
}
```

<br>

## Insertion at the beginning of the list

### Circular linked list **BEFORE** insertion

![image](https://github.com/Digital1O1/OpenCV_4.7_RPI_Install/assets/39348633/4233f1a8-8708-488a-b6fc-e7dbb09b1333)

### After insertion

![image](https://github.com/Digital1O1/OpenCV_4.7_RPI_Install/assets/39348633/cde9ab3d-5ad4-4142-a03b-ef4e6acf3f46)
![image](https://github.com/Digital1O1/OpenCV_4.7_RPI_Install/assets/39348633/daa2de07-9bed-4a8c-8dac-8ac117df9e92)
<br>

### Code implementation add at beginning

```cpp
Node *addBegin(Node *last, int data)
{
    /*
        Summary 
        - Create new node to be inserted
        - Create temporary node
        - Have temp node go to end of list
        - Have temp node point to new node to 'insert' it
        - Have newly inserted node point towards first node in LL to complete circle
            - Update tail node to newly inserted node
    */
    // Create a new node
    Node* newNode = new Node(value);

    // If the list is empty
    if (last == nullptr) 
    {
        // Point the new node to itself
        newNode->next = newNode;
    } 
    else 
    {
        // Set the new node's next to the current head
        // Have newNode point towards the first node of the LL
        newNode->next = last;

        // Create a new node and have it point towards where 'last' is currently at 
        Node* temp = last;

        // Have temp node iterate to the end of the list
        while (temp->next != last) 
        {
            temp = temp->next;
        }

        // Have the 'temp' pointer point to newNode which is at the beginning of the LL
        temp->next = newNode;
    }

    // Update tail to where the newly inserted newNode that's at the front of the list
    tail = newNode;
}
```

<br>

## Inserting at the end of the list

```cpp
// C++ program for the above operation

Node* addEnd(Node* tail, int data) 
{    // Create a new node
    Node* newNode = new Node(data);

    // If the list is empty
    if (tail == nullptr) 
    {
        newNode->next = newNode; // Point the new node to itself
        tail = newNode; // Update the head to the new node
    } 
    else 
    {
        // Have temp traverse to the very last node before inserting newNode to the LL
        Node* temp = tail;
        while (temp->next != tail) 
        {
            temp = temp->next;
        }

        // At this point, temp is already at the end of the list 
        // We then have the 'last' pointer temp, point to the newly inserted node newNode
        temp->next = newNode;

        // With newNode at the very end of the LL we then need to have newNode point to the first link in the LL
        // To complete the 'circle'
        newNode->next = tail;
    }

    
}
```

### **<u>Another visulization aid</u>**

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/d6dbb35e-7639-4b64-88cb-6bdcfea82288)

<br>

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/65873aa0-06b8-49ad-9e19-865c6588852b)

<br>

### tail->next = newP

<br>

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/b1948bf9-a8d9-49c4-9eff-c3a47759b7fc)

<br>

### tail = tail -> next

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/0ce3243d-f944-4de6-973b-f85c23245146)

<br>

## Insertion between nodes

```cpp
//https://www.youtube.com/watch?v=UlwpE_4y_A0&ab_channel=NesoAcademy
struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
    return NULL;

    // Travels to target node
    struct Node *temp, *p;

    // Have the p node point towards the first node in the list
    p = last -> next;

    // Searching the item.
    do
    {
        // Found the item
        if (p ->data == item)
        {
            // Creating a node dynamically.
            temp = (struct Node *)malloc(sizeof(struct Node));

            // Assigning the data.
            temp -> data = data;

            // Have the temp pointer point towards the p pointer
            // Have the temp pointer point to the node RIGHT after the one that's being inserted
            temp -> next = p -> next;

            // Move the p pointer towards where the temp/incoming node is at
            p -> next = temp;

            // Checking for the last node.
            if (p == last)
                last = temp;

            return last;
        }
        // Keep moving the pointer forward
        p = p -> next;
    } while (p != last -> next);

    cout << item << " not present in the list." << endl;
    return last;
}
```

<br>

# Deletion in a Circular Linked List

## 1) Delete the node if it's the ONLY node in the circular linked list

-   Free the node's memory
-   Last value should be NULL
-   A node should ALWAYS point towards another
    -   NULL assignment isn't necessary
-   Any node can be set as the starting point
-   Nodes can be traversed quickly from the first to the last

## 2) Deleting the last node

-   Locate the node before reaching the end
    -   We're using a 'temp' node
-   Keep address of the node NEXT to the last node in temp
-   Delete the last memroy
-   Put the temporary node at the end

## 3) Delete any node from the circular linked list

-   The user will give the program a node to be deleted from the current list

## Deleting a node from a circular singly linked list
- First position
- Last position
- Any given position

## Deleting first node from Singly Circular Linked Lists

![image](https://github.com/Digital1O1/Data_Structures_/assets/39348633/4b6a23cf-cf90-480a-85c8-57854b58dda1)



```cpp
// Function to delete First node of
// Circular Linked List
void DeleteFirst(struct Node** head)
{
	struct Node *previous = *head, *firstNode = *head;

	// check if list doesn't have any node
	// if not then return
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}

	// check if list have single node
	// if yes then delete it and return
	if (previous->next == previous) {
		*head = NULL;
		return;
	}

	// traverse second node to first
	while (previous->next != *head) {

		previous = previous->next;
	}

	// now previous is last node and
	// first node(firstNode) link address
	// put in last node(previous) link
	previous->next = firstNode->next;

	// make second node as head node
	*head = previous->next;
	free(firstNode);
	return;
}


// Function delete last node of
// Circular Linked List
void DeleteLast(struct Node** head)
{
	struct Node *current = *head, *temp = *head, *previous;

	// check if list doesn't have any node
	// if not then return
	if (*head == NULL) {
		printf("\nList is empty\n");
		return;
	}

	// check if list have single node
	// if yes then delete it and return
	if (current->next == current) {
		*head = NULL;
		return;
	}

	// move first node to last
	// previous
	while (current->next != *head) {
		previous = current;
		current = current->next;
	}

	previous->next = current->next;
	*head = previous->next;
	free(current);
	return;
}





```


