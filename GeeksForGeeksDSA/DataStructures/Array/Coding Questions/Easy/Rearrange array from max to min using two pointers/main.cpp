#include <iostream>
/*
    Reference link : https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/?ref=lbp

    Summary of problem
        - Given sorted array of positive integers
        - Rearrange the arrray alternatively
            - First element should be the max value
            - Second element should be the min value
            - Third element second max
            - Ect...

    Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
    Output: arr[] = {7, 1, 6, 2, 5, 3, 4}
*/
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    // printf("%d\r\n", arraySize);

    int maxPtr = arraySize - 1;
    int minPtr = 0;
    // int auxArray[] = {0};    // Incorrect
    int auxArray[arraySize]; // Correct

    for (int i = 0; i < arraySize; i++)
    {

        // This works
        // // Odd
        // if (arr[i] % 2 != 0)
        // {
        //     auxArray[i] = arr[maxPtr--];
        //     // printf("even : %d \r\n", arr[maxPtr--]);
        // }
        // // Even
        // else
        // {
        //     auxArray[i] = arr[minPtr++];
        //     // printf("odd : %d \r\n", arr[minPtr++]);
        // }

        // This also works and is a more eligant way 
        // condition ? expression1 : expression2;
        auxArray[i] = (i % 2 != 0) ? arr[minPtr++] : arr[maxPtr--];
    }

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", auxArray[i]);
    }
    return 0;
}