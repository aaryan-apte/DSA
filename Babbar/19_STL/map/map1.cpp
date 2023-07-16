#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    m["marks"] = 10;
    m["id"] = 211070082;
    // cout << "first       second\n";

    // for (auto i : m)
    // {
    //     cout << i.first << "        " << i.second << endl;
    // }

    // m["krishna"] = INT_MAX;
    m.insert({"Krishna", INT_MAX});
    auto it = m.find("marks");
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*it).second << endl;
    }

    return 0;
}