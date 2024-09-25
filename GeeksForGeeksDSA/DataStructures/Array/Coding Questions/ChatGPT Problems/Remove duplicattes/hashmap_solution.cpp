#include <iostream>
#include <map> // Include the map header./

using namespace std;

class removeDuplicate
{

public:
    void duplicate(int arr[], int n)
    {

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                cout << arr[i] << " ";
                mp[arr[i]]++;
            }
        }
    }
};
int main()
{

    int arr[] = {4, 3, 9, 2, 4, 1, 9, 9, 9};
    int n = 9;

    std::cout << "Original" << std::endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    std::cout << "\nAfter" << std::endl;

    removeDuplicate d1;
    d1.duplicate(arr, n);

    return 0;
}