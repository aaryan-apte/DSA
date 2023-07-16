#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> ram;
    ram.push_back(4);
    ram.push_front(1);
    ram.push_back(9);
    ram.push_front(2);
    ram.push_front(8);

    for (int i : ram)
    {
        cout << i << " ";
    }
    cout << "\nAfter ram.pop_back() and ram.pop_front():\n";
    ram.pop_back();
    ram.pop_front();
    for (int i : ram)
    {
        cout << i << " ";
    }

    return 0;
}

// 8 2 1 4 9
// After ram.pop_back() and ram.pop_front():
// 2 1 4