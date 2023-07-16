//     *
//    **
//   ***
//  ****
// *****

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
        int j = i + 1;
        while (j <= n)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= i)
        {
            cout << "*";
            j++;
        }
        cout << endl;
    }

    return 0;
}
