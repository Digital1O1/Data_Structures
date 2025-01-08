// Reference https://www.geeksforgeeks.org/program-print-identity-matrix/

#include <iostream>
using namespace std;

int main()
{

    int input = 5;

    for (int row = 0; row < input; row++)
    {
        for (int col = 0; col < input; col++)
        {
            if (row == col)
                std::cout << "1" << " ";
            else
                std::cout << "0" << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}