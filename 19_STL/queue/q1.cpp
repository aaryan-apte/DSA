#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("Hare Ram Hare Krishna!");
    q.push("Japa");
    q.push("Bhakti");
    q.push("Prasadam");
    cout << "q.front(): " << q.front() << endl;
    cout << "q.back(): " << q.back() << endl;
    q.pop();
    cout << "After q.pop()" << endl;
    ;
    cout << "q.front(): " << q.front() << endl;

    return 0;
}

// q.front(): Hare Ram Hare Krishna!
// q.back(): Prasadam
// After q.pop()
// q.front(): Japa