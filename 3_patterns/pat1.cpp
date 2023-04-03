#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    int i = 1;
    int counter = 1;

    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << counter << " ";
            j++;
            counter++;
        }
        cout << endl;
        i++;
    }

    return 0;
}
