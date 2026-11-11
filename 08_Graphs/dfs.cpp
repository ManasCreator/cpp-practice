
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive DFS
void DFS_Recursive(int node, vector<int> adj[],
                   vector<int>& visited)
{
    visited[node] = 1;  // Mark visited
    cout << node << " ";

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            DFS_Recursive(it, adj, visited);
        }
    }
}

// Iterative DFS using Stack
void DFS_Iterative(int start, vector<int> adj[], int V)
{
    vector<int> visited(V, 0);
    stack<int> st;

    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = 1;
            cout << node << " ";

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    st.push(it);
                }
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    // Create adjacency list
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    int start;
    cin >> start;

    // Recursive DFS
    vector<int> visited(V, 0);
    DFS_Recursive(start, adj, visited);

    cout << endl;

    // Iterative DFS
    DFS_Iterative(start, adj, V);

    return 0;
}
