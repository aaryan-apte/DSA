#include <iostream>
using namespace std;

void array_reverse(int arr[], int n)
{
    int barr[100];
    for (int i = 0; i < n; i++)
    {
        barr[i] = arr[n - i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = barr[i];
    }
}

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int arr[6] = {2, 5, 3, 7, 1, 9};
    array_reverse(arr, 6);
    cout << arr[0];

    return 0;
}
