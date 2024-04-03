#include <iostream>
#include <algorithm> // std::sort

using namespace std;

int main()
{
    int array[] = {3, 1, 4, 4, 2, 2, 5};
    int k = 3;

    int arraySize = sizeof(array) / sizeof(array[0]);

    // Sort the array
    // 1 2 2 3 4 5
    sort(array, array + arraySize);

    // Remove duplicates
    int uniqueIndex = 0;
    for (int i = 1; i < arraySize - 1; i++)
    {
        // Checks if current element is different from previous unique element
        if (array[i] != array[uniqueIndex])
        {
            ++uniqueIndex;
            // Moves unique elements to the left thus overwriting duplicate elements along the way
            array[uniqueIndex] = array[i];
        }
    }
    ++uniqueIndex; // Adjust for the last element

    // Check if k is valid
    if (k <= uniqueIndex)
    {
        // Print the kth smallest element
        cout << "The " << k << "th smallest element is: " << array[k - 1] << endl;
    }
    else
    {
        cout << "The " << k << "th smallest element does not exist." << endl;
    }

    return 0;
}
