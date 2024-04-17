/*
    Move all zeroes to end of array : https://www.geeksforgeeks.org/move-zeroes-end-array/?ref=lbp
        - Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
        - For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}.
        - The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).

    This current solution has a time complexity of O(n)
*/
#include <iostream>

void pushZerosToEnd(int arr[], int size)
{
    int nextNonZeroCounter = 0; // Pointer for the next non-zero element

    // Iterate through the array
    for (int current = 0; current < size; current++)
    {
        // If the current element is non-zero, swap it with the element at nextNonZeroCounter position
        if (arr[current] != 0)
        {
            std::swap(arr[current], arr[nextNonZeroCounter]);
            nextNonZeroCounter++; // Move the pointer to the next position since current is being iterated already with the for loop
        }
    }
}

int main()
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "\n\nOriginal array : \t\t\t ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Push zeros to the end of the array
    pushZerosToEnd(arr, size);

    std::cout << "Array after pushing zeros to the end : \t ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}