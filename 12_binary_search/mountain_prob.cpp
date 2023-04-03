#include <iostream>
using namespace std;

void mountain(int arr[], int n)
{
    int l = 0, h = n - 1;
    int mid = l + (h - l) / 2;

    while (l <= h)
    {
        if (arr[mid] < arr[mid + 1] && arr[mid - 1] < arr[mid])
        {
            l = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1] && arr[mid - 1] > arr[mid])
        {
            h = mid;
        }
        else if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            cout << mid;
            return;
        }
        mid = l + (h - l) / 2;
    }
    // cout << "Not a mountain\n";
}

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mountain(arr, n);

    return 0;
}
