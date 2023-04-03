#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    bool prime = true;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n == 1)
        {
            cout << "Neither prime nor composite\n";
            break;
        }

        if (n % i == 0)
        {
            cout << "Not a prime no!\n";
            prime = false;
            break;
        }
    }

    if (prime == true)
    {
        cout << "It is a prime number!\n";
    }

    return 0;
}
