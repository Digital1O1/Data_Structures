#include <iostream>
#include <vector>
using namespace std;

void zigZagMatrix(vector<vector<int>> &mat)
{
    int totalRows = mat.size() - 1;
    int totalCols = mat[0].size() - 1;

    int currentRow = 0;
    int currentCol = 0;

    cout << mat[currentRow][currentCol] << " "; // Start at mat[0][0]

    // Move right first
    currentCol++;
    cout << mat[currentRow][currentCol] << " ";

    // Conditions inside the while loop are evaluated from left to right
    // currentRow < totalRows is evaluated first
    // If currentRow < totalRow is true --> then currentCol > 0 is evaluated next 
    while (currentRow != totalRows || currentCol != totalCols)
    {
        // Move diagonally down-left
        while (currentRow < totalRows && currentCol > 0)
        {
            currentRow++;
            currentCol--;
            cout << mat[currentRow][currentCol] << " ";
        }

        // Check if we reached the bottom row
        if (currentRow == totalRows && currentCol < totalCols)
        {
            currentCol++; // Move right if at the bottom row
        }
        // Check if we reached the first column
        else if (currentCol == 0 && currentRow < totalRows)
        {
            currentRow++; // Move down if in the first column
        }
        cout << mat[currentRow][currentCol] << " ";

        // Move diagonally up-right
        while (currentRow > 0 && currentCol < totalCols)
        {
            currentRow--;
            currentCol++;
            cout << mat[currentRow][currentCol] << " ";
        }

        // Check if we reached the last column
        if (currentCol == totalCols && currentRow < totalRows)
        {
            currentRow++; // Move down if at the last column
        }
        // Check if we reached the top row
        else if (currentRow == 0 && currentCol < totalCols)
        {
            currentCol++; // Move right if in the top row
        }

        // Print the current element
        if (currentRow <= totalRows && currentCol <= totalCols)
        {
            cout << mat[currentRow][currentCol] << " ";
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    zigZagMatrix(mat);

    return 0;
}
