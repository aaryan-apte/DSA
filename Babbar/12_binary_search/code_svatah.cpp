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

    int key;
    cin >> key;
    int l = 0, h = n - 1;
    bool exists = false;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == key)
        {
            cout << mid;
            exists = true;
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
    }
    if (exists == false)
    {
        cout << "Doesn't exist.";
    }

    return 0;
}