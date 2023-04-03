#include <iostream>
using namespace std;

int set_bits(int a, int b)
{
    int count = 0;
    while (a != 0 && b != 0)
    {
        int bit_a = a & 1;
        int bit_b = b & 1;

        if (bit_a == 1 && bit_b == 1)
        {
            count++;
        }
        a = a >> 1;
        b = b >> 1;
    }

    // int c = a & b;
    // while (c != 0)
    // {
    //     if ((c & 1) == 1)
    //     {
    //         count++;
    //     }
    //     c = c >> 1;
    // }

    return count;
}

int main()
{
    int a, b;
    cout << "Enter value of  a and b:\n";
    cin >> a >> b;
    cout << endl;

    cout << set_bits(a, b);
    cout << true;

    return 0;
}
