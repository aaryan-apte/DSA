// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << j;
            j++;
        }
        j = 1;
        while (j <= 2 * i - 2)
        {
            cout << "*";
            j++;
        }
        j = n - i + 1;
        while (j > 0)
        {
            cout << j;
            j--;
        }
        cout << endl;
    }

    return 0;
}
