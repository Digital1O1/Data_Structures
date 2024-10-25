#include <iostream>
#include <vector>
using namespace std;
// #define num_rows 3
#define SET_COLUMNS 3

// https://www.geeksforgeeks.org/rotate-matrix-180-degree/
/*
Objective : Rotate given square matrix by 180 degrees.
            Rotating either C or CW ill produce same result

Input:      1  2  3
            4  5  6
            7  8  9

Output:        9 8 7
               6 5 4
               3 2 1


Input:     1 2 3 4
           5 6 7 8
           9 0 1 2
           3 4 5 6


Output:        6 5 4 3
               2 1 0 9
               8 7 6 5
               4 3 2 1
*/

void printMatrix(int arr[][SET_COLUMNS])
{

    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            std::cout << arr[row][column];
        }
        std::cout << std::endl;
    }
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // int temp = arr[0][0];
    // arr[0][0] = arr[2][2];
    // arr[2][2] = temp;

    // printMatrix(arr);

    /*
        Neeed to swap
        0,0 with 2,2,
        0,1 with 2,1
        0,2 with 2,0
        1,0 with 1,2
    */

    // Number of rows
    int num_rows = (sizeof(arr) / sizeof(arr[0]));

    // Number of columns
    int num_columns = (sizeof(arr[0]) / sizeof(arr[0][0]));

    std::cout << "Size of array : " << num_rows << " " << num_columns << std::endl;

    printMatrix(arr);

    // Subtracting rom num_rows is needed for the swapping logic for 180 degrees to work since we're accessing the element at the opposite position of a given element
    for (int currentRow = 0; currentRow < num_rows - 1; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < num_columns; currentColumn++)
        {
            std::cout << "Current iteration \trow : " << currentRow << "\tcolumn : " << currentColumn << std::endl;

            // int temp = arr[currentRow][currentColumn];

            // Original
            // int temp = arr[currentRow][currentColumn];
            //  arr[currentRow][currentColumn] = arr[num_rows][num_columns];
            // arr[currentRow][currentColumn] = arr[num_rows][num_columns];
            // arr[num_rows][num_columns] = temp;

            /*
                Starting point currentRow = 0 | currentColumn = 0
                temp = arr[0][0] --> 1
                arr[0][0] = arr[3-0-1][3-0-1] --> arr[0][0] = arr[2][2] --> arr[0][0] == 9 swap
                arr[3-0-1][3-0-1] = 1 --> arr[2][2] = 1 swap


                Starting point currentRow = 0 | currentColumn = 1
                temp = arr[0][1] --> 2
                arr[0][1] = arr[3-1-1][3-1-1] --> arr[0][0] = arr[1][1] --> arr[0][0] == 9 swap
                arr[3-0-1][3-0-1] = 1 --> arr[2][2] = 1 swap
            */

            int temp = arr[currentRow][currentColumn];
            arr[currentRow][currentColumn] = arr[num_rows - currentRow - 1][num_columns - currentColumn - 1];
            arr[num_rows - currentRow - 1][num_columns - currentColumn - 1] = temp;

            // std::cout << " ---------------" << std::endl;
            // printMatrix(arr);
        }
        // std::cout << " ---------------" << std::endl;
        // printMatrix(arr);
    }
    std::cout << " ---------------" << std::endl;
    printMatrix(arr);
    return 0;
}