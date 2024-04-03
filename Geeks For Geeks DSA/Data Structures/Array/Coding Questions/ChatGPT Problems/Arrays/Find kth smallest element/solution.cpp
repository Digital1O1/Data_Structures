#include <iostream>
#include <algorithm>

using namespace std;

int findKthSmallest(int arr[], int size, int k)
{
    // Sort the array
    sort(arr, arr + size);

    // Remove duplicates
    int uniqueIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] != arr[uniqueIndex])
        {
            ++uniqueIndex;
            arr[uniqueIndex] = arr[i];
        }
    }
    ++uniqueIndex; // Adjust for the last element

    // Check if k is valid
    if (k <= uniqueIndex)
    {
        // Return the kth smallest element
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
