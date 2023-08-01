#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

class Graph
{
public:
    unordered_map<int, set<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = true => undirected
        if (direction)
        {
            adj[u].insert(v);
            adj[v].insert(u);
        }
        else
        {
            adj[u].insert(v);
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
    void dfs(unordered_map<int, bool> &visited, int node)
    {
        cout << node << " ";
        visited[node] = true;

        for (auto j : adj[node])
        {
            if (!visited[j])
            {
                dfs(visited, j);
            }
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

    unordered_map<int, bool> visited;
    g.dfs(visited, 0);

    return 0;
}