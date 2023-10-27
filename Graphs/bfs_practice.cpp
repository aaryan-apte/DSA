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
    map<int, int> indegree;
    map<int, int> outdegree;

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        indegree[v]++;
        outdegree[u]++;
        // adj[v].push_back(u);
    }

    // void printAdjList()
    // {
    //     for (auto i : adj)
    //     {
    //         cout << i.first << " => ";
    //         for (auto j : i.second)
    //         {
    //             cout << j << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // void BFS(int i, unordered_map<int, bool> &visited)
    // {
    //     queue<int> q;
    //     q.push(i);

    //     while (!q.empty())
    //     {
    //         int node = q.front();
    //         if (!visited[node])
    //         {
    //             for (int i : adj[node])
    //             {
    //                 if (!visited[i])
    //                 {
    //                     q.push(i);
    //                 }
    //             }
    //             visited[node] = true;
    //             cout << node << " ";
    //         }
    //         q.pop();
    //     }
    // }

    void topologicalSort(int node, map<int, bool> &visited, stack<int> &st)
    {
        if (!visited[node])
        {
            visited[node] = true;
            // cout << node << " ";

            for (auto i : adj[node])
            {
                if (!visited[i.first])
                    topologicalSort(i.first, visited, st);
            }
            st.push(node);
        }
    }

    // void kahnsAlgorithm(vector<int> &ans, map<int, bool> &visited)
    // {
    //     queue<int> q;

    //     for (auto i : adj)
    //     {
    //         int node = i.first;
    //         if (indegree[node] == 0 && !visited[node])
    //         {
    //             q.push(node);
    //         }
    //     }

    //     while (!q.empty())
    //     {
    //         int node = q.front();
    //         q.pop();

    //         for (int neighbor : adj[node])
    //         {
    //             indegree[neighbor]--;
    //             if (indegree[neighbor] == 0 && !visited[neighbor])
    //             {
    //                 q.push(neighbor);
    //             }
    //         }

    //         ans.push_back(node);
    //         visited[node] = true;
    //     }
    // }

    // void shortestPath(int start, int target, map<int, bool> &visited, map<int, int> &childParent)
    // {
    //     queue<int> q;
    //     q.push(start);

    //     while (!q.empty())
    //     {
    //         int node = q.front();

    //         for (int i : adj[node])
    //         {
    //             if (!visited[i])
    //             {
    //                 childParent[i] = node;
    //                 q.push(i);
    //             }
    //         }
    //         visited[node] = true;
    //         q.pop();
    //     }
    // }

    // bool checkCycle(int node, map<int, int> &childParent, map<int, bool> &visited)
    // {
    //     bool ans = false;
    //     if (!visited[node])
    //     {
    //         visited[node] = true;

    //         for (auto i : adj[node])
    //         {
    //             if (!visited[i])
    //             {
    //                 childParent[i] = node;
    //                 ans = ans | checkCycle(i, childParent, visited);
    //                 if (ans)
    //                     return true;
    //             }
    //             else if (visited[i] && childParent[node] != i)
    //             {
    //                 ans = true;
    //                 return true;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // bool checkCycleBFS(int node1, map<int, int> &childParent, map<int, bool> &visited)
    // {
    //     queue<int> q;
    //     q.push(node1);
    //     // visited[node1] = true;

    //     while (!q.empty())
    //     {
    //         int node = q.front();

    //         for (auto i : adj[node])
    //         {
    //             if (!visited[i])
    //             {
    //                 q.push(i);
    //                 childParent[i] = node;
    //             }
    //             else if (visited[i] && childParent[node] != i)
    //                 return true;
    //         }
    //         visited[node] = true;
    //         q.pop();
    //     }
    //     return false;
    // }

    void minimumDistance(int start)
    {
        stack<int> st;
        map<int, bool> visited;

        topologicalSort(0, visited, st);
        vector<int> distance(st.size(), INT_MAX);
        distance[start] = 0;

        while (st.top() != start)
            st.pop();

        while (!st.empty())
        {
            int curNode = st.top();

            for (auto i : adj[curNode])
            {
                if (distance[i.first] > i.second + distance[curNode])
                    distance[i.first] = i.second + distance[curNode];
            }
            st.pop();
        }

        for (int i = 0; i < distance.size(); i++)
            cout << i << " => " << distance[i] << endl;
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(1, 3, 6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);

    // map<int, bool> visited;

    g.minimumDistance(2);
    // map<int, int> childParent;
    // bool ans = false;
    // int start = 1;
    // int target = 6;

    // g.shortestPath(start, target, visited, childParent);

    // int child = target, parent;
    // int count = 0;

    // while (parent != start)
    // {
    //     parent = childParent[child];
    //     child = parent;
    //     count++;
    // }

    // cout << count;

    // stack<int> st;

    // for (auto i : g.adj)
    // {
    //     if (!visited[i.first])
    //         g.topologicalSort(i.first, visited, st);
    // }

    // vector<int> v;
    // g.kahnsAlgorithm(v, visited);
    // for (int i : v)
    // cout << i << " ";

    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << ans;

    return 0;
}