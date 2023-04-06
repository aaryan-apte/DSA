// Sagle elements donda aahet in array except one.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    // find unique element in an array
    int a[100];
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int unique = 0;
    for (int i = 0; i < n; i++)
    {
        unique = unique ^ a[i];
    }

    cout << unique;

    return 0;
}
