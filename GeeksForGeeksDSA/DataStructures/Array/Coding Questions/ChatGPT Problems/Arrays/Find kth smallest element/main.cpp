#include <iostream>
#include <algorithm> // std::sort

using namespace std;

/*
    Problem:

    You are given an array of integers that may contain duplicates.
    Write a C++ function to find the kth smallest element in the array, after removing all duplicates and sorting the array in ascending order.
    If the kth smallest element does not exist, return -1.
*/

int main()
{
    int array[] = {3, 1, 4, 4, 2, 2, 5};
    int k = 3;

    int arraySize = sizeof(array) / sizeof(array[0]);
    // cout << arraySize << endl;

    // sorted() takes two parameters
    // 1) Where the sorted array starts
    // 2) Where the sorted array ends
    // 3) Optional parameter if you want the the sorted elements lexicographically

    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n\n======================" << endl;

    sort(array, array + arraySize);

    int duplicateCounter = 0;
    for (int i = 0; i < arraySize - 1; i++)
    {
        // cout << array[i] << " ";
        if (array[i] == array[i + 1])
        {
            // cout << "Duplicate found" << endl;
            duplicateCounter++;
        }
        else
        {
            cout << array[i] << " ";
        }
    }

    cout << "\n\nSmallest element found : " << array[3] << "\t Total number of duplicates found : " << duplicateCounter << endl;
    return 0;
}