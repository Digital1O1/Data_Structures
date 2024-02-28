// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
#include <iostream>

using namespace std;

int main()
{

    int bubbleSortArray[] = {3, 5, 4, 1, 9};
    int min = 0;
    int max = 0;
    // To find total size --> total size of array / one byte of data in array
    int arrSize = sizeof(bubbleSortArray) / sizeof(bubbleSortArray[0]);

    printf("Before sorting array \r\n");
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", bubbleSortArray[i]);
    }
    for (int firstElement = 0; firstElement < arrSize; firstElement++)
    {
        for (int secondElement = firstElement + 1; secondElement < arrSize; secondElement++)
        {
            if (bubbleSortArray[firstElement] > bubbleSortArray[secondElement])
            {
                int temp = bubbleSortArray[firstElement];
                bubbleSortArray[firstElement] = bubbleSortArray[secondElement];
                bubbleSortArray[secondElement] = temp;
            }
        }
    }

    // print out sorted array list
    printf("\n\nAfter sorting array \r\n");
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", bubbleSortArray[i]);
    }

    printf("\n\nMin value in array : [ %d ] \t Max value in array : [ %d ] \r\n", bubbleSortArray[0], bubbleSortArray[arrSize - 1]);
    return 0;
}