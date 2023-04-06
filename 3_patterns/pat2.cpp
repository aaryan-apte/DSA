// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j <= i)
        {
            cout << i // '*' pattern sathi replace i by '*'
                 << " ";
            j++;
        }
        cout << endl;
    }

    return 0;
}
