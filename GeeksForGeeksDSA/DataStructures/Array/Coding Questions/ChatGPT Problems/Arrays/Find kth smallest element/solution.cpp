#include <iostream>
#include <algorithm>

using namespace std;
/*
    Iterating through the array: The loop iterates through the entire array.

    Checking uniqueness: At each iteration, it checks if the current element is unique compared to the previous unique elements encountered.

    Updating uniqueIndex and storing elements: If the current element is unique, uniqueIndex is incremented, and the current element is stored at the index represented by uniqueIndex.

    Adjusting uniqueIndex for count: After the loop, uniqueIndex represents the index of the last unique element, not the count of unique elements. Therefore, it needs to be incremented by 1 to reflect the correct count of unique elements in the array.
*/
int findKthSmallest(int arr[], int size, int k)
{
    // Sort the array
    sort(arr, arr + size);

    // Remove duplicates
    int uniqueIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        // If the value in arr[i] isn't unique to whatever arr[uniqueIndex] is, the value is ignored
        // Otherwise the uniqueIndex variable is incremented, saved to arr and that element is shifted to the left
        // Remember the for loop is starting at the beginning of the array
        if (arr[i] != arr[uniqueIndex])
        {
            ++uniqueIndex;
            arr[uniqueIndex] = arr[i];
        }
    }
    // Is needed to ensure the number of unique elements is accounted for
    ++uniqueIndex; // Adjust for the last element

    // Check if k is valid
    if (k <= uniqueIndex)
    {
        // Return the kth smallest  in the array
        return arr[k - 1];
    }
    else
    {
        // kth smallest element does not exist
        return -1;
    }
}

int main()
{
    int array[] = {3, 1, 4, 4, 2, 2, 5};
    int k = 3;

    int size = sizeof(array) / sizeof(array[0]);

    int result = findKthSmallest(array, size, k);

    if (result != -1)
    {
        cout << "The " << k << "th smallest element is: " << result << endl;
    }
    else
    {
        cout << "The " << k << "th smallest element does not exist." << endl;
    }

    return 0;
}
