// A
// B C
// C D E
// D E F G
// E F G H I
// F G H I J K
// G H I J K L M

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
