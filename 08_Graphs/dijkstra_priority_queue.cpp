#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
using namespace std;

vector<int> Dijkstra(int source, vector<vector<pair<int, int>>>& adj, int V)
{
    vector<int> dist(V, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int node = it.second;

        if (d != dist[node])
            continue;

        for (auto x : adj[node])
        {
            int next = x.first;
            int wt = x.second;

            if (d + wt < dist[next])
            {
                dist[next] = d + wt;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    // Input edges
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int source;
    cin >> source;

    vector<int> dist = Dijkstra(source, adj, V);

    // Print shortest distances
    for (int i = 0; i < V; i++)
    {
        cout << source << " to " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}