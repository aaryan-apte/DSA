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
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFSMain(unordered_map<int, bool> &visited)
    {
        for (auto i : adj)
        {
            if (!visited[i.first])
                BFS(i.first, visited);
        }
    }

    void BFS(int node, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int curNode = q.front();
            visited[curNode] = true;
            for (int i : adj[curNode])
            {
                if (!visited[i])
                {
                    q.push(i);
                }
            }
            cout << curNode << " ";
            q.pop();
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    unordered_map<int, bool> visited;
    g.BFSMain(visited);

    return 0;
}