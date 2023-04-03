#include <iostream>
using namespace std;

void binary_search(int a[], int l, int h, int key)
{
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        if (a[mid] == key)
        {
            cout << mid;
            break;
        }
        else if (a[mid] > key)
        {
            h = mid;
        }
        else if (a[mid] < key)
        {
            l = mid + 1;
        }
    }
}

int pivot_finder(int a[], int n)
{
    int l = 0, h = n - 1;
    int mid = l + (h - l) / 2;

    while (l < h)
    {
        if (a[mid] > a[0])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
        mid = l + (h - l) / 2;
    }
    return mid;
}

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cout << "Enter key:\n";
    cin >> key;

    int pivot = pivot_finder(a, n);
    if (key > pivot)
    {
        binary_search(a, 0, pivot - 1, key);
    }
    else
    {
        binary_search(a, pivot, n - 1, key);
    }

    return 0;
}
