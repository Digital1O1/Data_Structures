#include <iostream>

// Used for sorting array
#include <algorithm>
#include <vector>
/*
    Problem: Get the K Largest Elements

    Prompt:
    You're given an array of integers. Write a function that returns the K largest elements from the array in descending order using a max heap.

    References for reading
        - https://www.geeksforgeeks.org/binary-heap/
        - https://www.geeksforgeeks.org/building-heap-from-array/



    Things to keep in mind
        - Max heap property
         - For every node, it's value should be greater than or equal to the values of it's children

              20
            /    \
        15      10
        /  \       \
       7    4       3

*/

void heapify(int arr[], int heapSize, int indexNode)
{
    int largest = indexNode;           // Initialize largest as root
    int leftNode = 2 * indexNode + 1;  // Initialize left node --> left = 2*indexNode + 1
    int rightNode = 2 * indexNode + 2; // Initialize left node --> right = 2*indexNode + 2

    // If left child is larger than root
    if (leftNode < heapSize && arr[leftNode] > arr[largest])
        largest = leftNode;

    // If right child is larger than largest so far
    if (rightNode < heapSize && arr[rightNode] > arr[largest])
        largest = rightNode;

    // If largest is not root
    if (largest != indexNode)
    {
        std::swap(arr[indexNode], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, heapSize, largest);
    }
}

void printArray(int arr[], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int buildHeap(int arr[], int sizeArray)
{
    // Index of last non-leaf node | (6/2) - 1 --> 2
    int startIdx = (sizeArray / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, sizeArray, i);
    }
    return startIdx;
}
/*
 * Why heapSize is being passed in by reference
 *   - Doing so lets us modify the original heapSize variable in main()
 *   - If we didn't, teh changes to the variable would only be local to getLargestValue()
 *   - Also remember that arrays in C++ are always passed by pointer which allows us to modify the
 *     array
 */
int getLargestValue(int arr[], int &sizeArray, int indexNode, int keyValue)
{
    // Store the root value (the max element)
    int maxValue = arr[0];
    std::cout << "Max value : " << maxValue << std::endl;

    arr[0] = arr[indexNode - 1]; // wrong

    // Step 3: Reduce heap size
    indexNode--; // wrong

    // Step 4: Heapify from the root
    heapify(arr, indexNode, 0);

    return maxValue;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int key = 3;

    int sizeArray = sizeof(arr) / sizeof(arr[0]);

    // Sort array first | THIS ISN'T NESSESSARY SINCE SORTING IS ALREADY BEING DONE IN HEAPIFY

    // Sorts from smallest to largest
    // std::sort(arr, arr + sizeArray);

    // Sorts from largest to smallets
    // std::sort(arr, arr + sizeArray, std::greater<int>());

    // std::cout << "Array after sorting largest to smallest" << std::endl;
    // for (int a : arr)
    //     std::cout << a << " ";

    // Implement the 'heapify' logic
    // void heapify(int arr[], int heapSize, int indexNode)
    printArray(arr, sizeArray);

    int indexNode = buildHeap(arr, sizeArray);
    printArray(arr, sizeArray);

    std::cout << "Getting the largest value" << std::endl;
    int maxValueFound = getLargestValue(arr, sizeArray, indexNode, key);

    std::cout << maxValueFound << std::endl;
    printArray(arr, sizeArray);

    return 0;
}
/*
    Output

    digital101@Digital101:/mnt/z/Coding Folder/C++/Data_Structures/GeeksForGeeksDSA/DataStructures/Heap/CodingProblems/Easy/GetLargestKValue$ g++ main.cpp -o getLargest && ./getLargest
    7 10 4 3 20 15
    20 10 15 3 7 4
    Getting the largest value
    Max value : 20
    20
    10 10 15 3 7 4
*/