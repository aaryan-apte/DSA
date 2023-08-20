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

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v)
    {
        // direction = true => undirected
        // if (direction)
        // {
        adj[u].push_back(v);
        adj[v].push_back(u);
        // }
        // else
        // {
        // adj[u].push_back(v);
        // }
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

    void BFS(int i, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            if (!visited[node])
            {
                for (int i : adj[node])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                    }
                }
                visited[node] = true;
                cout << node << " ";
            }
            q.pop();
        }
    }

    void DFS(int node, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int i : adj[node])
        {
            if (!visited[i])
                DFS(i, visited);
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 0);
    g.addEdge(4, 2);

    unordered_map<int, bool> visited;
    // g.dfs(visited);
    g.DFS(0, visited);
    for (auto i : g.adj)
    {
        if (!visited[i.first])
            g.DFS(i.first, visited);
        // g.BFS(i.first, visited);
    }

    return 0;
}