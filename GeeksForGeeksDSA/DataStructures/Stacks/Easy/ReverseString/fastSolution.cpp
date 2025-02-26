#include <iostream>

using namespace std;
class Stack
{
};
int main()
{
    // Input
    std::string str = "GeeksQuiz";
    // Expected output --> ziuQskeeG

    // std::cout << str.size();
    char bucket[str.size()] = {};

    for (int i = 0; i < str.size(); i++)
    {
        // Push all the string characters into bucket
        // Will get pushed into array as : G e e k Q u i z
        bucket[i] = str[i];
        // std::cout << bucket[i] << " ";
    }

    // This will print the array in reverse 
    for (int i = str.size() - 1; i >= 0; i--)
    {
        std::cout << bucket[i];
    }

    return 0;
}