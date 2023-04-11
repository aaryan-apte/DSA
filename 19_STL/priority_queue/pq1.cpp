#include <iostream>
#include <queue>
using namespace std;

// Priority queues: maxi = max_heap and mini = min_heap

int main()
{
    priority_queue<int> maxi;
    maxi.push(6);
    maxi.push(3);
    maxi.push(9);
    maxi.push(1);
    maxi.push(2);
    maxi.push(2);

    int n = maxi.size();

    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << endl;
        maxi.pop();
    }

    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(3);
    mini.push(2);
    mini.push(9);
    mini.push(8);
    mini.push(12);
    mini.push(5);
    mini.push(7);
    n = mini.size();
    cout << "mini.top()     mini.size()\n";
    for (int i = 0; i < n; i++)
    {
        cout << mini.top() << "                 " << mini.size() << endl;
        mini.pop();
    }

    return 0;
}

// 9
// 6
// 3
// 2
// 2
// 1
// mini.top()     mini.size()
// 2                 7
// 3                 6
// 5                 5
// 7                 4
// 8                 3
// 9                 2
// 12                 1