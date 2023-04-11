#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(4);
    dq.push_back(1);
    dq.push_front(2);
    for (int i : dq)
    {
        cout << i << " ";
    }

    dq.pop_front();
    cout << "\ndq.pop_front() nantar:\n";
    for (int i : dq)
    {
        cout << i << " ";
    }
    dq.pop_back();
    cout << "\ndq.pop_back() nantar:\n";
    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << "\ndq.at(0): " << dq.at(0) << endl;
    // cout << dq.begin();
    dq.push_back(4);
    dq.push_back(1);
    dq.push_front(2);
    dq.push_front(6);
    dq.push_back(9);

    for (int i : dq)
    {
        cout << i << " ";
    }

    dq.erase(dq.begin(), dq.end());
    cout << "\nAfter erasing from dq.begin() to dq.end(), size = " << dq.size() << endl;

    return 0;
}

// 2 4 1
// dq.pop_front() nantar:
// 4 1
// dq.pop_back() nantar:
// 4
// dq.at(0): 4
// 6 2 4 4 1 9
// After erasing from dq.begin() to dq.end(), size = 0