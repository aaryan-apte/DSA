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
        int j = i, count = i;

        while (j < 2 * i)
        {
            cout << j << " ";
            j++;
            count++;
        }
        cout << endl;
    }

    return 0;
}
