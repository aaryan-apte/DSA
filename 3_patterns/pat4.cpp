// 1
// 2 1
// 3 2 1
// 4 3 2 1
// 5 4 3 2 1

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
        while (j > 0)
        {
            cout << j << " ";
            j--;
        }
        cout << endl;
    }

    return 0;
}
