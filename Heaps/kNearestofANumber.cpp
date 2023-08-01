#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

// struct comparator
// {
//     bool operator()(pii &p1, pii &p2)
//     {
//         return p1.first <= p2.first;
//     }
// };

void kClosest(vector<int> &arr, int k, int x)
{
    priority_queue<pii, vector<pii>, greater<pii>> mini;
    for (int i = 0; i < arr.size(); i++)
    {
        mini.push({abs(arr[i] - x), arr[i]});
        cout << abs(arr[i] - x) << " ";
    }
    cout << endl;
    int i = 0;
    while (i < k)
    {
        cout << mini.top().second << " ";
        mini.pop();
        i++;
    }
}

int main()
{
    vector<int> arr = {4, 1, 7, 9, 8, 45, 5};
    kClosest(arr, 3, 8);

    return 0;
}