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
    map<int, pair<int, bool>> inOut;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        inOut[v].first++;
        inOut[v].second = false;
        inOut[u].second = false;
    }

    void printList()
    {
        for (int i = 0; i < inOut.size(); i++)
        {
            cout << i << ": (" << inOut[i].first << ", " << inOut[i].second << ")" << endl;
        }
    }

    // vector<int> topologicalSort()
    // {
    //     vector<vector<int>> graph(inOut.size());
    //     for (int i = 0; i < inOut.size(); i++)
    //     {
    //         graph[i].push_back(i);
    //         graph[i].push_back(inOut[i].first);
    //         graph[i].push_back(inOut[i].second);
    //     }
    //     sort(graph.begin(), graph.end(), [](vector<int> &a, vector<int> &b)
    //          {
    //         if(a[2] == 0)
    //             return true;

    //         else if(a[1] == b[1] && a[2] == b[2])
    //             return a[0] < b[0];
    //         else if(a[1] == b[1])
    //             return a[2] < b[2];
    //         else
    //             return a[1] >= b[1]; });

    //     vector<int> ans(inOut.size(), 0);
    //     for (int i = 0; i < ans.size(); i++)
    //     {
    //         ans[i] = graph[i][0];
    //         cout << ans[i] << " ";
    //     }
    //     return ans;
    // }

    void topologicalSort(stack<int> &st, map<int, bool> &visited, int node)
    {
        if (!visited[node])
        {
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    topologicalSort(st, visited, i);
                }
            }
            visited[node] = true;
            st.push(node);
        }
    }

    vector<int> kahnsAlgorithm()
    {
        queue<int> q;
        int element = -1;
        vector<int> ans;

        for (auto i : inOut)
        {
            if (i.second.first == 0)
            {
                element = i.first;
                break;
            }
        }
        if (element == -1)
        {
            cout << "There is a cycle...\n";
            return;
        }
        q.push(element);
        // inOut[element].second = true;

        while (!q.empty())
        {
            int node = q.front();

            for (auto i : adj[node])
            {
                inOut[i].first--;
                if (inOut[i].first < 0)
                {
                    cout << "There is a cycle...\n";
                    return;
                }
                if (inOut[i].first == 0 && !inOut[i].second)
                    q.push(i);
            }
            q.pop();

            if (!inOut[node].second)
                ans.push_back(inOut[node].first);
            inOut[node].second = true;

            // for (auto i : inOut)
            // {
            //     if (i.second.first == 0 && !i.second.second)
            //     {
            //         q.push(i.first);
            //         cout << i.first << " pushed\n";
            //     }
            // }
            // cout << node << " ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
    g.addEdge(5, 3);
    // g.kahnsAlgorithm();
    // g.addEdge(5, 6);
    // g.addEdge(3, 1);
    // g.addEdge(3, 4);
    // g.addEdge(3, 5);
    // g.addEdge(1, 2);
    // g.addEdge(4, 1);
    // g.addEdge(4, 5);
    // g.addEdge(2, 5);
    // g.printList();
    // cout << endl;
    // stack<int> st;
    // map<int, bool> visited;

    vector<int> ans = g.kahnsAlgorithm();
    if (ans.size() == g.adj.size())
        cout << "No cycle\n";
    else
        cout << "Cycle...\n";

    // for (int i = 0; i < g.adj.size(); i++)
    // {
    //     if (!visited[i])
    //         g.topologicalSort(st, visited, i);
    // }
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    return 0;
}