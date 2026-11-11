#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int Prim(int V, vector<vector<pair<int, int>>>& adj)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    vector<int> visited(V, 0);
    int totalWeight = 0;

    pq.push({0, 0});  // {weight, node}

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (visited[node])
            continue;

        visited[node] = 1;
        totalWeight += wt;

        for (auto x : adj[node])
        {
            int edgeWeight = x.first;
            int next = x.second;

            if (!visited[next])
                pq.push({edgeWeight, next});
        }
    }

    return totalWeight;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    // Create adjacency list
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    cout << "MST Weight: " << Prim(V, adj);

    return 0;
}