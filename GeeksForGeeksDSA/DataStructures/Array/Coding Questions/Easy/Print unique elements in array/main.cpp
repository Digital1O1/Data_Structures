/*
    https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/?ref=lbp

    Main objective
        - Just print all distinct elements in an array
        - The array could have duplicates
            - So the output should print every element ONLY ONCE
        - Given array is NOT sorted

    Example
        - Input: arr[] = {12, 10, 9, 45, 2, 10, 10, 45}
        - Output: 12, 10, 9, 45, 2
*/
#include <iostream>
#include <stdio.h>

void printArray(int arr[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
    int sizeArray = sizeof(arr) / sizeof(arr[0]);

    // Iterate through the array to remove duplicates
    // writeIndex is used to save the uniquev values back into arr[]
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < sizeArray; readIndex++)
    {
        bool isUnique = true;
        // Check if the current element is unique by comparing it with previous elements
        for (int checkCurrentElement = 0; checkCurrentElement < writeIndex; checkCurrentElement++)
        {
            if (arr[readIndex] == arr[checkCurrentElement])
            {
                isUnique = false;
                break;
            }
        }
        // If the element is unique, copy it to the writeIndex position
        if (isUnique)
        {
            arr[writeIndex++] = arr[readIndex];
        }
    }

    // Print the unique elements
    for (int i = 0; i < writeIndex; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
