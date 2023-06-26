#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool dir)
    {
        // dir = 0 => undirected
        // dir = 1 => directedmmkk

        adj[u].push_back(v);
        if (!dir)
        {
            adj[v].push_back(u);
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
    int n;
    cout << "Enter the number of nodes:\n";
    cin >> n;

    int m;
    cout << "Enter the number of edges:\n";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the nodes jyancha madhe edge aahe:\n";
        cin >> u;
        cin >> v;

        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}