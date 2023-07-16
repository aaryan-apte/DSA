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
    bool flag = false;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        // if (a[mid] > a[mid - 1] && a[mid + 1] > a[mid])
        // {
        //     h = mid;
        // }
        // else if (a[mid] < a[mid - 1] && a[mid + 1] < a[mid])
        // {
        //     l = mid + 1;
        // }
        // else if (a[n - 1] < a[l + (h - l) / 2])
        // {
        //     cout << a[n - 1];
        //     flag = true;
        //     break;
        // }
        // // else if (a[mid] < a[mid + 1] && a[mid] < a[mid - 1])
        // // {
        // //     cout << mid << endl;         Condition not acceptable...
        // //     flag = true;
        // //     break;
        // // }
        // else if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
        // {
        //     cout << (mid + 1) << endl;
        //     flag = true;
        //     break;
        // }
        // else
        // {
        //     break;
        // }
        if (a[mid] >= a[0])
        {
            l = mid + 1;
        }
        else
            h = mid;
    }
    cout << l;

    // if (flag == false)
    // {
    //     cout << "None exists.";
    // }

    return 0;
}
