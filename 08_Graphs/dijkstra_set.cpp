#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

vector<int> Dijkstra(int source, vector<vector<pair<int, int>>>& adj, int V)
{
    vector<int> dist(V, INT_MAX);
    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        auto it = *st.begin();
        st.erase(st.begin());

        int d = it.first;
        int node = it.second;

        for (auto x : adj[node])
        {
            int next = x.first;
            int wt = x.second;

            if (d + wt < dist[next])
            {
                if (dist[next] != INT_MAX)
                    st.erase({dist[next], next});

                dist[next] = d + wt;
                st.insert({dist[next], next});
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