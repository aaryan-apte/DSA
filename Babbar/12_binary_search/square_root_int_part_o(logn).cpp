// 27 IP la 5 is OP
// int part dyaychay of sqrt in log n time... Binary search vaparayla lagel.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int l = 0, h = n;
    while (l <= h)
    {
        long long int mid = l + (h - l) / 2;
        if (mid * mid == n)
        {
            cout << mid << endl;
            break;
        }
        else if (mid * mid < n && (mid + 1) * (mid + 1) > n)
        {
            cout << mid;
            break;
        }
        else if (mid * mid > n)
        {
            h = mid;
        }
        else if (mid * mid < n)
        {
            l = mid + 1;
        }
    }

    return 0;
}
