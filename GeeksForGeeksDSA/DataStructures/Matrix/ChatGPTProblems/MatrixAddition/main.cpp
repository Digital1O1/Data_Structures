#include <iostream>
using namespace std;
int main()
{
    int A[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

    int B[3][3] = {{9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1}};

    int C[3][3];

    // Total size calculated by multiplying number of elements by size of each element
    // So (3x3) * 4 = 9 * 4 = 36 bytes assuming int is 4 bytes
    // int totalSizeArray = sizeof(A);

    // This just grabs the size of a single element
    // int elementSize = sizeof(A[0][0]);

    // Number of elements calcualted by dividing TOTAL size of the array by the size of one element
    // totalSizeArray = 36
    // elementSize = 4
    // numElements = 36 / 4 = 9 elements total
    // int numElements = totalSizeArray / elementSize;

    // Divide total size of array in bytes / size of one row in the array
    // 36 / (3*4) = 3 rows
    int totalRows = sizeof(A) / sizeof(A[0]);

    // sizeof(A[0]) gives size of one row --> 3 elements * 4 bytes = 12 bytes total
    // sizeof(A[0][0]) gives size of a single element --> 4 bytes
    // numCols = sizeof(arr[0]) / sizeof(arr[0][0]) = 12 / 4 = 3
    int totalCols = sizeof(A[0]) / sizeof(A[0][0]);

    for (int currentRow = 0; currentRow < totalRows; currentRow++)
    {
        for (int currentCol = 0; currentCol < totalCols; currentCol++)
        {
            C[currentRow][currentCol] = A[currentRow][currentCol] + B[currentRow][currentCol];
        }
    }

    printf("New matrix\r\n");

    for (int currentRow = 0; currentRow < totalRows; currentRow++)
    {
        for (int currentCol = 0; currentCol < totalCols; currentCol++)
        {
            std::cout << C[currentRow][currentCol] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}