#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS from one starting vertex.
void BFS(int start, const vector<vector<int>>& adj, vector<int>& visited)
{
    queue<int> q;
    visited[start] = 1;       // Mark when enqueued.
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : adj[node])
        {
            if (!visited[next])
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Remove this line for a directed graph.
    }

    int start;
    cin >> start;

    vector<int> visited(V, 0);
    BFS(start, adj, visited);
    cout << '\n';
    return 0;
}
