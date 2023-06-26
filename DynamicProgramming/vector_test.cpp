#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> mem = {{2, 5, 4}, {4, 1}, {9, 8, 1}};
    mem[0].push_back(8);
    for (auto i : mem[0])
    {
        cout << i;
    }

    return 0;
}