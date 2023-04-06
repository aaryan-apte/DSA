//     1
//    121
//   12321
//  1234321
// 123454321

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
        while (j <= n - i)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j < i)
        {
            cout << j;
            j++;
        }
        while (j >= 1)
        {

            cout << j;
            j--;
        }
        cout << endl;
    }

    return 0;
}
