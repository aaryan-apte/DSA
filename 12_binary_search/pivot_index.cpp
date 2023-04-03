#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int a[1000];
    int l = 0;
    int h = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // int i = 0;
    // int sum1 = 0, sum2 = 0;
    bool flag = false;

    while (l <= h)
    {
        int i = 0;
        int sum1 = 0, sum2 = 0;
        int mid = l + (h - l) / 2;

        while (i < mid)
        {
            sum1 = sum1 + a[i];
            i++;
        }
        i = mid + 1;
        while (i < n)
        {
            sum2 = sum2 + a[i];
            i++;
        }

        if (sum1 == sum2)
        {
            cout << mid;
            flag = true;
            break;
        }

        else if (sum1 > sum2)
            h = mid;
        else
            l = mid + 1;
    }

    if (flag == false)
    {
        cout << "No pivot element exists.";
    }

    return 0;
}
