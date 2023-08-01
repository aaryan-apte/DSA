#include <iostream>
#include <map>
#include <string>
using namespace std;

int gridTraveler(int m, int n, map<string, int> mem)
{
    if (m == 0 || n == 0)
        return 0;
    if (m == 1 || n == 1)
        return 1;

    string key = to_string(m) + ',' + to_string(n);

    auto it = mem.find(key);

    if (it != mem.end())
        return it->second;

    mem[key] = gridTraveler(m - 1, n, mem) + gridTraveler(m, n - 1, mem);
    return mem[key];
}

int main()
{
    int m = 0, n = 0;
    map<string, int> mem;

    cout << "Enter 2 numbers (m, n)\n";
    cin >> m >> n;
    cout << gridTraveler(m, n, mem);

    for (auto i : mem)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}