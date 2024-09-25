/*
    Problem
        - Given an array of integers representing score of students in class
        - Each score ranges from 0 - 100
        - Write function 'removeDuplicates'
            - Takes array
            - Removes duplicate scores
            - Keep only unique ones
            - Arrange array so unique scores appear at the beginning
                - Remaining elements set to -1
            - Function should return count of unique scores AFTER removeal of duplicates
*/
#include <iostream>

// Function to remove duplicates from the array and rearrange it
int removeDuplicates(int arr[], int arraySize)
{
    // If the array is empty or has only one element, no duplicates to remove
    if (arraySize == 0 || arraySize == 1)
        return arraySize;

    int uniqueCounter = 0; // Initialize a variable to keep track of the current position in the result array

    // Loop through the array to remove duplicates
    for (int i = 0; i < arraySize; i++)
    {
        bool isDuplicate = false;
        // Check if the current element is a duplicate of any element before it
        for (int j = 0; j < i; j++)
        {
            // If the values match up, it's not unique and just ignore the value
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        // If it's not a duplicate, move it to the beginning of the array
        if (!isDuplicate)
        {
            arr[uniqueCounter++] = arr[i];
        }
    }

    // Fill the remaining elements of the result array with -1
    // Since uniqueCounter was already intialized we can leave the first parameter of the for loop
    for (; uniqueCounter < arraySize; uniqueCounter++)
        arr[uniqueCounter] = -1;

    // Return the count of unique elements in the result array
    return uniqueCounter;
}

int main()
{
    int arr[] = {89, 56, 75, 89, 92, 56, 75, 100};
    int arraySize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "\nOriginal array:\n";
    for (int i = 0; i < arraySize; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Call the removeDuplicates function to remove duplicates from the array
    int uniqueCount = removeDuplicates(arr, arraySize);

    std::cout << "\nArray after removing duplicates:\n";
    for (int i = 0; i < uniqueCount; i++) // Note: Only loop up to uniqueCount
        std::cout << arr[i] << " ";
    std::cout << "\n";

    std::cout << "\nCount of unique scores: " << uniqueCount << "\n";

    return 0;
}
