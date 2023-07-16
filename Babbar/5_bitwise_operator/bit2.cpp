#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int a = 0, b = 1;

    for (int i = 0; i <= n / 2; i++)
    {
        cout << a << endl;
        cout << b << endl;
        a = a + b;
        b = a + b;
    }

    return 0;
}
