#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;

    for (int i = 0; i < 6; i++)
    {
        pq.push(i);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
