// A A A A A
// B B B B B
// C C C C C
// D D D D D
// E E E E E

// A B C D E
// F G H I J
// K L M N O
// P Q R S T

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    // cout << char(65);
    // cout << (int)'a';
    int k = 65;
    for (int i = 1; i <= n; i++)     // A A A A A...
    {                                // B B B B B...
        for (int j = 1; j <= n; j++) // C C C C C...
        {
            cout << char(k) << " ";
        }
        cout << endl;
        k++;
    }
    cout << endl
         << endl;
    k = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char(k) << " ";
            k++;
        }
        cout << endl;
    }

    return 0;
}
