#include <iostream>
using namespace std;

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

    int l = 0, h = n - 1;
    int key;
    cin >> key;
    int mid = (l + h) / 2;

    while (l <= h)
    {
        if (a[mid] == key)
        {
            // cout << mid << endl;
            // exists = true;
            break;
        }
        else if (a[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        mid = (l + h) / 2;
    }

    l = mid - 1;
    h = mid + 1;
    int count = 1;

    while (a[l] == key)
    {
        count++;
        l--;
    }
    while (a[h] == key)
    {
        count++;
        h++;
    }
    cout << count;

    return 0;
}
