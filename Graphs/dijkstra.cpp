#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    // ikde, distance array initialise kela

    vector<int> distance(vertices, INT_MAX);
    set<pair<int, int>> s;

    // source cha distance 0 asto
    distance[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
        // minimum element (pahila) kadha set madhna.

        pair<int, int> minNode = *(s.begin());
        int curDistance = minNode.first;
        int node = minNode.second;

        for (auto i : adj[node])
        {
            if (distance[i.first] > curDistance + i.second)
            {
                distance[i.first] = curDistance + i.second;
                s.insert({distance[i.first], i.first});
            }
        }
        s.erase(minNode);
    }

    return distance;
}
