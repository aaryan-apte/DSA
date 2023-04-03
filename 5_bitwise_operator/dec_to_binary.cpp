#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = (n & 1);
        ans = ans + pow(10, i) * bit;
        i++;
        n = (n >> 1);
    }

    cout << ans;

    return 0;
}
