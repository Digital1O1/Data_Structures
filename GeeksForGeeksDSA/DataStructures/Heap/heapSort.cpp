// C++ program for implementation of Heap Sort using vector

#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(vector<int> &arr, int heapSize, int i)
{

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    // Example : i = 2 --> 2 * 2 + 1 --> 5th element
    int left_Index = 2 * i + 1;

    // right index = 2*i + 2
    // Example : i = 2 --> 2 * 2 + 2 --> 6th element
    int right_Index = 2 * i + 2;

    /*
        Reasoning behind left_Index or right_Index < heapSize logic
            - If the calculated indicies are greater than heapSize
            - The node doesn't have either a left/right child since the index is outisde the valid 
              portion of the array you're heapifying
    */

    // If left child is larger than root --> Make it the largest value
    if (left_Index < heapSize && arr[left_Index] > arr[largest])
        largest = left_Index;

    // If right child is larger than largest so far
    if (right_Index < heapSize && arr[right_Index] > arr[largest])
        largest = right_Index;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, heapSize, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int> &arr)
{
    int heapSize = arr.size();

    // Build heap (rearrange vector)
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        heapify(arr, heapSize, i);

    // One by one extract an element from heap
    for (int i = heapSize - 1; i > 0; i--)
    {

        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print vector of size n
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main()
{
    vector<int> arr = {9, 4, 3, 8, 10, 2, 5};

    cout << "Original array is \n";

    // Original vector
    for (int n : arr)
    {
        std::cout << n << " ";
    }

    // Function call
    heapSort(arr);

    cout << "\nSorted array is \n";
    printArray(arr);
}