#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = true => undirected
        if (direction)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else
        {
            adj[u].push_back(v);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " => ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.printAdjList();

    return 0;
}