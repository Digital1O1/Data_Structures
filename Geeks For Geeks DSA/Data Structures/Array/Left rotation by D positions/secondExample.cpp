#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void ArrayRotate(int arr[], int n, int k)
{
    // d = -1 to ensure it's different from any valid index within the array
    int d = -1, temp, j;
    for (int i = 0; i < gcd(n, k); i++)
    {
        j = i;
        temp = arr[i];
        while (1)
        {
            d = (j + k) % n;
            if (d == i)
                break;
            arr[j] = arr[d];
            j = d;
        }
        arr[j] = temp;
    }
}

void displayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n, i, k;
    cout << "Enter size of the Array\n";
    cin >> n;
    int arr[n];
    cout << "Enter Array elements\n";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the value of k\n";
    cin >> k;
    displayArray(arr, n);
    ArrayRotate(arr, n, k);
    displayArray(arr, n);
    return 0;
}