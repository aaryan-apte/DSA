#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void no_of_set_bits(int n, int m)
{
    string s1 = "", s2 = "";
    int i = 2;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            s1 = s1 + '1';
        }
        else
        {
            s1 = s1 + '0';
        }
        n = n / 2;
    }

    while (m > 0)
    {
        if (m % 2 == 1)
        {
            s2 = s2 + '1';
        }
        else
        {
            s2 = s2 + '0';
        }
        m = m / 2;
    }
    string s11 = "", s22 = "";
    for (int i = s1.length(); i > 0; i++)
    {
        s11 = s11 + s1[i];
    }
    for (int i = s2.length(); i > 0; i++)
    {
        s22 = s22 + s2[i];
    }

    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;
}

int nCr(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

bool check_prime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    // cout << "4C2: " << nCr(4, 2);
    // cout << endl
    //      << "Is 90 prime?" << check_prime(90);
    no_of_set_bits(8, 9);
    return 0;
}