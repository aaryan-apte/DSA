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
        int count = i + (int)('A') - 1;
        while (j <= i)
        {
            cout << char(count) << " ";
            j++;
            count++;
        }
        cout << endl;
    }

    return 0;
}
