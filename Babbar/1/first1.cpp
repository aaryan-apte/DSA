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

int no_of_set_bits(int n, int m)
{
    string s1 = "", s2 = "";
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
    int no_of_1s = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        s11 = s11 + s1[i];
        if (s1[i] == '1')
            no_of_1s++;
    }
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        s22 = s22 + s2[i];
        if (s2[i] == '1')
            no_of_1s++;
    }

    cout << "S1: " << s11 << endl;
    cout << "S2: " << s22 << endl;

    return no_of_1s;
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

int fibonacci(int n, int a[])
{
    if (a[n] != -1)
    {
        return a[n];
    }
    else
    {
        if (n == 1)
        {
            a[n] = 1;
            return 1;
        }
        else if (n == 0)
        {
            a[n] = 0;
            return 0;
        }
        else
        {
            a[n] = fibonacci(n - 1, a) + fibonacci(n - 2, a);
            return a[n];
        }
    }
}

int main()
{
    // cout << "4C2: " << nCr(4, 2);
    // cout << endl
    //      << "Is 90 prime?" << check_prime(90);
    // cout << no_of_set_bits(8, 9);
    int n;
    cin >> n;
    int a[n];
    // int a[6];
    for (int i = 0; i < n; i++)
        a[i] = -1;
    cout << fibonacci(n, a);
    return 0;
}