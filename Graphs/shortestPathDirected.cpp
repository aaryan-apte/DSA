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
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    void printList()
    {
        // for (int i = 0; i < inOut.size(); i++)
        // {
        //     cout << i << ": (" << inOut[i].first << ", " << inOut[i].second << ")" << endl;
        // }
    }

    vector<int> shortestPath(stack<int> &st, int source)
    {
        map<int, bool> visited;
        vector<int> distance(st.size(), INT_MAX);
        distance[source] = 0;

        while (!st.empty())
        {
            int node = st.top();
            if (distance[node] == INT_MAX)
            {
                st.pop();
                continue;
            }
            for (auto i : adj[node])
            {
                if (distance[node] + i.second < distance[i.first])
                {
                    distance[i.first] = distance[node] + i.second;
                }
            }
            st.pop();
        }

        return distance;
    }

    void topologicalSort(stack<int> &st, map<int, bool> &visited, int node)
    {
        if (!visited[node])
        {
            for (auto i : adj[node])
            {
                if (!visited[i.first])
                {
                    topologicalSort(st, visited, i.first);
                }
            }
            visited[node] = true;
            // cout << "Pushing " << node << " onto stack\n";
            st.push(node);
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    stack<int> st;
    map<int, bool> visited;
    for (int i = 0; i < g.adj.size(); i++)
    {

        g.topologicalSort(st, visited, i);
    }
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    vector<int> distance = g.shortestPath(st, 1);
    for (int i = 0; i < distance.size(); i++)
        cout << i << " -> " << distance[i] << endl;

    return 0;
}