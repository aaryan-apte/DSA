#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(21);
    v.push_back(34);
    v.push_back(78);

    cout << binary_search(v.begin(), v.end(), 9) << endl;
    cout << upper_bound(v.begin(), v.end(), 4) - v.begin();

    return 0;
}