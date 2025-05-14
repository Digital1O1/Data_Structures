#include <iostream>
#include <vector>

/*
    Problem: Get the K Largest Elements

    Prompt:
    You're given an array of integers. Write a function that returns the K largest elements
    from the array in descending order using a max heap.
*/

void heapify(int arr[], int heapSize, int indexNode)
{
    int largest = indexNode;
    int leftNode = 2 * indexNode + 1;
    int rightNode = 2 * indexNode + 2;
    // Checks if the node is within the bounds of 'heapSize'
    if (leftNode < heapSize && arr[leftNode] > arr[largest])
        largest = leftNode;

    if (rightNode < heapSize && arr[rightNode] > arr[largest])
        largest = rightNode;

    if (largest != indexNode)
    {
        std::swap(arr[indexNode], arr[largest]);
        heapify(arr, heapSize, largest);
    }
}

void buildHeap(int arr[], int sizeArray)
{
    // The startIdx 'starts' at the last non-leaf node with the purpose of heapifying the tree from the bottom up

    int startIdx = (sizeArray / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, sizeArray, i);
    }
}

int extractMax(int arr[], int &heapSize)
{
    if (heapSize <= 0)
        return -1; // or throw an error

    int maxValue = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize--;
    // We're passing 0 to rebuild the tree agian

    /*
        Before extracting

              20
            /    \
          10      15
         /  \     /
         3    7   4

        After

          4
        /   \
      10     15
      /      \
    3         7

➡ heapify swaps 4 with 15, then continues downward


    */
    heapify(arr, heapSize, 0);

    return maxValue;
}

void printArray(int arr[], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int key = 3;

    int sizeArray = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array:\n";
    printArray(arr, sizeArray);

    buildHeap(arr, sizeArray);

    std::cout << "After building max heap:\n";
    printArray(arr, sizeArray);

    std::vector<int> topK;

    // Prints out top 3 values
    for (int i = 0; i < key; ++i)
    {
        int maxVal = extractMax(arr, sizeArray);
        topK.push_back(maxVal);
    }

    std::cout << "Top " << key << " largest elements:\n";
    for (int val : topK)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
