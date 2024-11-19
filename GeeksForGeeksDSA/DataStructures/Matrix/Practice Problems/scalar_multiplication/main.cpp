// Reference : https://www.geeksforgeeks.org/program-for-scalar-multiplication-of-a-matrix/?ref=next_article

/*
    Given a matrix and a scalar element k, our task is to find out the scalar product of that matrix.
    Examples:

    Input : mat[][] = {{2, 3}
                                {5, 4}}
            k = 5
    Output : 10 15
            25 20
    We multiply 5 with every element.

    Input : 1 2 3
                4 5 6
                7 8 9
            k = 4
    Output :  4 8  12
            16 20 24
            28 32 36


    The scalar multiplication of a number k(scalar), multiply it on every entry in the matrix. and a matrix A is the matrix kA.
*/

// C++ program to find the scalar product of a matrix
#include <iostream>
#include <vector>
using namespace std;

void scalarProductMat(vector<vector<int>> &mat, int k)
{
    int totalRows = mat.size();

    // mat[0] --> Referes to the first row of the matrix 
    // size called on mat[0] returns number of elements/columns in the first row
    int totalCols = mat[0].size();

    for (int currentRow = 0; currentRow < totalRows; currentRow++)
    {
        for (int currentCols = 0; currentCols < totalCols; currentCols++)
        {
            // std::cout << mat[currentRow][currentCols] * k << " ";
            // mat[currentRow][currentCols] = mat[currentRow][currentCols] * k;
            mat[currentRow][currentCols] *= k;
        }
        // std::cout << std::endl;
    }
}

// Driver code
int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    cout << "\nOriginal Matrix is:\n";

    for (const auto &row : mat)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
    int k = 4;

    scalarProductMat(mat, k);

    // Display the resultant matrix
    cout << "\nScalar Product Matrix is:\n";
    for (const auto &row : mat)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
