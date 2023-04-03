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
        int count = i;
        while (j < i)
        {
            cout << " ";
            j++;
        }

        while (j <= n)
        {
            cout << count;
            j++;
        }
        cout << endl;
        count++;
    }

    // Varcha program for:
    // 11111
    //  2222
    //   333
    //    44
    //     5

    // ani ha:

    for (int i = 1; i <= n; i++)
    {
        int j = i;
        int count = i;
        while (j < n)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= i)
        {
            cout << count;
            j++;
        }
        cout << endl;
        count++;
    }

    return 0;
}
