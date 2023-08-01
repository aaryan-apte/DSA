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

    bool checkCycleBFS(map<int, bool> &visited, map<int, int> &childParent)
    {
        queue<int> q;
        q.push(0);
        bool ans = false;

        while (!q.empty())
        {
            int node = q.front();

            if (!visited[node])
            {
                for (auto i : adj[node])
                {
                    if (!visited[i])
                    {
                        childParent[i] = node;
                        q.push(i);
                    }
                    else if (visited[i] && childParent[node] != i)
                    {
                        ans = true;
                    }
                }
                // cout << node << " ";
                visited[node] = true;
            }
            q.pop();
        }
        return ans;
    }

    bool checkCycleDFS(map<int, bool> &visited, map<int, int> &childParent, int node)
    {
        // cout << node << " ";
        visited[node] = true;
        bool ans = false;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                childParent[i] = node;
                ans = ans | checkCycleDFS(visited, childParent, i);
            }
            else if (visited[i] && childParent[node] != i)
                return true;
        }
        return ans;
    }

    // bool checkCycle(map<int, bool> &visited)
    // {
    //     map<int, int> childParent;
    // }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(3, 0, 0);
    // g.addEdge(0, 3, 1);
    g.addEdge(2, 3, 1);

    map<int, bool> visited;
    int v = g.adj.size();

    bool ans = false;
    map<int, int> childParent;
    // bool ans = false;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            ans = ans | g.checkCycleBFS(visited, childParent);
            // ans = ans | g.checkCycleDFS(visited, childParent, i);
        }
    }
    cout << ans;
    return 0;
}