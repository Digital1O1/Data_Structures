// https://www.geeksforgeeks.org/print-mat-in-zig-zag-fashion/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void zigZagMatrix(vector<vector<int>> &mat)
{
    int totalRows = mat.size() - 1;
    int totalCols = mat[0].size() - 1;

    int currentRow = 0;
    int currentCol = 0;

    std::cout << "Rows: " << totalRows << std::endl;
    std::cout << "Columns: " << totalCols << std::endl;

    bool moveFlag = true;
    bool downDiagonal = true;

    // Start --> mat[0][0] end --> mat[0][0]
    std::cout << mat[currentRow][currentCol] << " ";
    // Move right start --> mat[0][0] end --> mat[0][1]
    std::cout << mat[currentRow][++currentCol] << " ";

    // Move down diagonally start --> mat[0][1] end --> mat[1][0]
    std::cout << mat[++currentRow][--currentCol] << " ";
    // Hit last row and start moving diagonally
    // start mat[1][0] --> end mat[2][0]
    std::cout << mat[++currentRow][currentCol] << " ";

    // std::cout << "\nROW LIMIT MOVING TO UPPER RIGHT" << std::endl;

    std::cout << mat[--currentRow][++currentCol] << " ";
    std::cout << mat[--currentRow][++currentCol] << " ";

    // std::cout << "\nCurrent position row : " << currentRow << " " << " column : " << currentCol;

    // std::cout << "Moving down" << std::endl;

    std::cout << mat[++currentRow][currentCol] << " ";

    // std::cout << "Moving diagonnally down left" << std::endl;
    std::cout << mat[++currentRow][--currentCol] << " ";

    // std::cout << "\nMove to last position to right" << std::endl;
    std::cout << mat[currentRow][++currentCol] << " ";
}

// Driver code
int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    zigZagMatrix(mat);

    return 0;
}