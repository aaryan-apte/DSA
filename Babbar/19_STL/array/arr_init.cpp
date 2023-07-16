#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 4> a = {2, 1, 4, 2};
    cout << a.at(1);
    int size = a.size();
    cout << endl
         << size;

    if (!a.empty())
        cout << "\nHaribol!";

    cout << "\nFirst element: " << a.front() << "\nLast element: " << a.back() << endl;
    return 0;
}
// O/P:
// 1
// 4
// Haribol!
// First element: 2
// Last element: 2
