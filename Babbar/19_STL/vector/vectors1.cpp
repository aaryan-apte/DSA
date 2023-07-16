#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int n;
    // cout << "Enter value of n:\n";
    // cin >> n;
    // cout << endl;

    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);

    cout << "v.front(): " << v.front();
    cout << "\nv.back(): " << v.back();
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;
    // cout << "\nEnter the elements:\n";

    // for (int i = 0; i < 6; i++)
    // {
    //     int n;
    //     cin >> n;
    //     v.push_back(n);
    // }
    cout << "\n"
         << v.capacity() << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << "\nNow clearing:\n";
    v.clear();
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size();
    v.push_back(3);
    v.push_back(8);
    vector<int> w(v);
    cout << endl
         << w.at(1);

    return 0;
}

// O/P
// v.front(): 4
// v.back(): 1
// 4
// 4 3 1
// 4 3
// Now clearing:
// Capacity: 4
// Size: 0
// 8