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

    string checkCycle()
    {
        }

    void BFS()
    {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(0);

        while (!q.empty())
        {
            int node = q.front();
            if (!visited[node])
            {
                for (auto j : adj[node])
                {
                    q.push(j);
                }
                visited[node] = true;
                cout << node << " ";
            }
            q.pop();
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(4, 2, 1);

    g.BFS();

    return 0;
}