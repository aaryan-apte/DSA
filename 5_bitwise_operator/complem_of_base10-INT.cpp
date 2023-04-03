#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int i = 0;
    int complement = 0;

    while (n != 0)
    {
        int bit = (n & 1);
        if (bit == 1)
            bit = 0;
        else
            bit = 1;
        // int bitt = (int)bit;
        complement = complement + pow(2, i) * bit;
        i++;
        n = n >> 1;
    }
    cout << complement;
    return 0;
}