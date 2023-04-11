// maam upetya tu kaunteya punar janma na vidyate...
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> s;
    s.insert("Ram");
    s.insert("Shyam");
    s.insert("Krishna");
    s.insert("Parshuram");
    s.insert("Hayagriva");
    s.insert("Shukadev");
    s.insert("Shukadev");
    int n = s.size();
    for (auto i : s)
    {
        cout << i << endl;
    }

    set<int>::iterator itr = s.find("Krishna");
    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}

// Hayagriva
// Krishna
// Parshuram
// Ram
// Shukadev
// Shyam