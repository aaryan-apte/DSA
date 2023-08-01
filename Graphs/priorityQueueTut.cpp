#include <iostream>
#include <queue>
#include <set>
using namespace std;

// Define a custom comparison functors
struct ComparePairs
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second; // Compare based on the second element of the pair
    }
};

int main()
{
    // // Define the priority queue with the custom comparison function
    // priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;

    // // Insert elements into the priority queue
    // pq.push({1, 5});
    // pq.push({2, 3});
    // pq.push({3, 8});
    // pq.push({4, 1});

    // // Get the minimum element based on the second part of the pair
    // pair<int, int> minElement = pq.top();
    // pq.pop();

    // // Output the result
    // cout << "Minimum pair: (" << minElement.first << ", " << minElement.second << ")" << endl;

    // set<pair<int, int>> s;
    // s.insert({1, 0});
    // s.insert({3, 8});
    // s.insert({2, 1});
    // auto pair1 = *(s.begin());
    // cout << "First " << pair1.first << " second: " << pair1.second << endl;
    // s.erase(*(s.begin()));
    // pair1 = *(s.begin());
    // cout << "First " << pair1.first << " second: " << pair1.second << endl;
    priority_queue<pair<int, int>> pq;
    pq.push({3, 1});
    pq.push({1, 2});
    pq.push({9, 3});
    cout << "First: " << pq.top().first << " second: " << pq.top().second << endl;
    pq.pop();
    cout << "First: " << pq.top().first << " second: " << pq.top().second << endl;

    return 0;
}
