// ikde 27 cha 2nd decimal paryant dyaychay uttar.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int l = 0, h = n;
    long long int mid = l + (h - l) / 2;

    while (l <= h)
    {
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
        mid = l + (h - l) / 2;
    }

    /// int mid2 = 0.5;
    float mid1 = (float)mid;
    float l1 = 0.0;
    float h1 = 100.0;
    float mid2 = (l1 + (h1 - l1) / 2) / 100;
    while (l1 < h1)
    {
        if ((mid1 + mid2) * (mid1 + mid2) == n)
        {
            cout << "\nDecimal part is: " << mid2 << endl;
            break;
        }
        else if ((mid1 + mid2) * (mid1 + mid2) < n && (mid1 + mid2 + 0.01) * (mid1 + mid2 + 0.01) > n)
        {
            cout << "\nDecimal part is: " << mid2 << endl;
            break;
        }
        else if ((mid1 + mid2) * (mid1 + mid2) < n)
        {
            l1 = mid2 * 100 + 1;
        }
        else if ((mid1 + mid2) * (mid1 + mid2) > n)
        {
            h1 = mid2 * 100;
        }
        mid2 = (l1 + (h1 - l1) / 2) / 100;
    }

    return 0;
}
