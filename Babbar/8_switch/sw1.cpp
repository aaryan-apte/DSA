#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;
    int hund = 0, fifty = 0, twenty = 0, ten = 0;

    // 100, 50, 20, 10
    while (n - 100 >= 0)
    {
        n = n - 100;
        hund++;
    }
    while (n - 50 >= 0)
    {
        n = n - 50;
        fifty++;
    }
    while (n - 20 >= 0)
    {
        n = n - 20;
        twenty++;
    }
    while (n - 10 >= 0)
    {
        n = n - 10;
        ten++;
    }

    cout << "Hundred: " << hund << " Fifty: " << fifty << " Twenty: " << twenty << " Tens: " << ten << endl;
    return 0;
}
