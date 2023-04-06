// 1
// 2 3
// 3 4 5
// 4 5 6 7
// 5 6 7 8 9

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
        int j = i;
        while (j < 2 * i)
        {
            cout << j << " ";
            j++;
        }
        cout << endl;
    }

    return 0;
}
