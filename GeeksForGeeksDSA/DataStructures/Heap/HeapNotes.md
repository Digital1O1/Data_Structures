# [Binary Heaps ](https://www.geeksforgeeks.org/binary-heap/)

## What is it
-  A **complete binary tree** that stores data efficiently
-  Allows quick access to max/min element 
   -  Depending on the type of heap
   -  Can either be 
      -  Min heap
      -  Max heap

### In a **Min Heap**
- The key is at the `root`
- And must be the `smallest` among all the keys in the heap
  - This property must hold true recursively for all nodes

### In a **Max Heap**
- Holds the same principles 
- But with the **largest key** at the root


## Valid and invalid examples of heaps

![alt text](<../../Screenshots/Screenshot 2025-05-07 172009.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-07 172033.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-07 172511.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-07 172439.png>)


# How is a binary heap represented 
- A binary heap is a **Complete Binary Tree**
- A binary tree is typically represented as an array 
  - The root element will be at **arr[0]**
  - The table below shows indicies of other nodes for the **i^th** node (arr[i])

    ![alt text](<../../Screenshots/Screenshot 2025-05-07 173802.png>) 

## The traversal method used to achieve Array representation 
- [Level orer traversal](https://www.geeksforgeeks.org/level-order-tree-traversal/)

### Quick review of Level Order Traversal (BFS)
- TL;DR This technique traverses a tree so that all the nodes present `in the same level` are traversed completely before traversing to the next

### How does it work?
- Either
  - Recursively
  - Or using a queue (iteratively)

### Using Recursion

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrderRec(Node* root, int level, vector<vector<int>>& result_) {
    // Base case: If node is null, return
    if (root == nullptr) return;

    // Add a new level to the result if needed
    if (result_.size() <= level)
        result_.push_back({});
  
    // Add current node's data to its corresponding level
    result_[level].push_back(root->data);

    // Recur for left and right children
    levelOrderRec(root->left, level + 1, result_);
    levelOrderRec(root->right, level + 1, result_);
}

// Function to perform level order traversal
// This is where it starts
vector<vector<int>> levelOrder(Node* root) {
    // Stores the result level by level
    vector<vector<int>> result_; 
  
    levelOrderRec(root, 0, result_);
    return result_;
}

int main() {
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14    2
    // /  \   /  \  / \
    //17  23 27  3  8  11

    Node* root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> result_ = levelOrder(root);

    for (vector<int> level : result_) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    // Output : [5] [12, 13] [7, 14, 2] [17, 23, 27, 3, 8, 11] 
    return 0;
}
```

### Using a queue

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Iterative method to perform level order traversal
vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr)
        return {};

    // Create an empty queue for level order traversal
    queue<Node *> q;
    vector<vector<int>> result_;

    // Enqueue Root
    q.push(root);
    int currLevel = 0;

    while (!q.empty()) {
        int len = q.size();
        result_.push_back({});

        for (int i = 0; i < len; i++) {

            // Add front of queue and remove it from queue
            Node *node = q.front();
            q.pop();

            result_[currLevel].push_back(node->data);

            // Enqueue left child
            if (node->left != nullptr)
                q.push(node->left);

            // Enqueue right child
            if (node->right != nullptr)
                q.push(node->right);
        }
        currLevel++;
    }
    return result_;
}

int main() {
    //      5
    //     / \
    //   12   13
    //   /  \    \
    //  7    14   2
    // /  \   /  \  / \
    //17 23 27  3  8  11

    Node *root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);

    root->left->left = new Node(7);
    root->left->right = new Node(14);

    root->right->right = new Node(2);

    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);

    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);

    vector<vector<int>> result_ = levelOrder(root);

    for (vector<int> level : result_) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    // Output : [5] [12, 13] [7, 14, 2] [17, 23, 27, 3, 8, 11] 
    return 0;
}
```

# Applications of Heaps 
### Heap Sort
- Uses Binary Heap to sort an array in O(n Logn) time
### Priority Qeueue 
- Uses a heap to efficiently retrieve elements based on their priority 
- Can be implemented efficiently using Binary Heaps since it supports 
  - insert()
  - delete()
  - extractmax()
  - Both Binomial/Fibonacci heap are variations of the Binary Heap 
### Graph Algorithms 
- Priority queues are especially used in algorithms like 
  - Dijkstra's shortest path
  - Prim's Minimum Spanning Tree

# Heap Operations 

```cpp
// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with the root at given index
    void MinHeapify(int i);

    // Get parent node
    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Driver program to test above functions
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
```

---

# [Heap sort](https://www.geeksforgeeks.org/heap-sort/) 

## What is it
- A comparison-based sorting algorithm using a binary heap
- More efficient than selection sort due to faster access to max elements

## Why Binary Heap
- Lets us find and move the max element in `O(log n)` time instead of `O(n)`
- Leads to overall `O(n log n)` time complexity

## Heap Sort Algorithm
1. Convert the array into a max heap (in-place using heapify)
2. Repeat while heap size > 1:
   - Swap the root (max element) with the last element
   - Reduce heap size
   - Heapify the root to restore heap property
3. Result: array is sorted in ascending order

## How Heap Sort Actually Works
### Step 1 : Treat the array as a Complete Binary Tree
- For an array of size `n` 
  - The root is at `index 0` 
  - The left child of an element that's at index i is at : `2i + 1`
  - The right child is at : `2i + 2`


![alt text](<../../Screenshots/Screenshot 2025-05-09 203747.png>)

### Step 2 : Build a Max Heap

![alt text](<../../Screenshots/Screenshot 2025-05-09 204749.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-09 204928.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-09 205016.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-09 205102.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-09 205144.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-09 205830.png>)

![alt text](<../../Screenshots/Screenshot 2025-05-09 210110.png>)

### Step 3 : Sort the array by placing the largest element at the end of the unsorted array

![alt text](<../../Screenshots/Screenshot 2025-05-09 210710.png>) 
![alt text](<../../Screenshots/Screenshot 2025-05-09 210743.png>) 
![alt text](<../../Screenshots/Screenshot 2025-05-09 210805.png>) 
![alt text](<../../Screenshots/Screenshot 2025-05-09 210826.png>) 
![alt text](<../../Screenshots/Screenshot 2025-05-09 210850.png>) 
![alt text](<../../Screenshots/Screenshot 2025-05-09 210914.png>)

## Heap Sort Implementation
```cpp
// C++ program for implementation of Heap Sort using vector

#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(vector<int>& arr, int n, int i){

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int left_Index = 2 * i + 1;

    // right index = 2*i + 2
    int right_Idex = 2 * i + 2;

    // If left child is larger than root
    if (left_Index < n && arr[left_Index] > arr[largest])
        largest = left_Index;

    // If right child is larger than largest so far
    if (right_Idex < n && arr[right_Idex] > arr[largest])
        largest = right_Idex;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int>& arr){
    int n = arr.size();

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print vector of size n
void printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main(){
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };

    // Function call
    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);
}
```

## Important points about Heap Sort
- It's an `in place` algorithm 
  - Meaning it uses a constant amount of extra memory space 
  - Regardless of the input size
    - Meaning it transforms the input using **only the input array** without needing an auxiliary data structure like another array or list
- The typical implementation isn't table, but can be done 
  - Read more about it [here](https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/)
- Typically 2-3 times slower than Quicksort
  - Reason for slowness is due to lack of locality of reference

## Heap Sort Advantages and Disadvantages
#### Advantages

* **Efficient Time Complexity**: O(n log n) in all cases, making it suitable for large datasets.
* **Low Memory Usage**: Minimal memory usage required, apart from necessary initial list space.
* **Simplicity**: Easy to understand, using basic computer science concepts.

#### Disadvantages

* **Costly**: High constants compared to other sorting algorithms like merge sort, despite the same time complexity.
* **Unstable**: May rearrange relative order of elements.
* **Inefficient**: High constants in time complexity make it less efficient.