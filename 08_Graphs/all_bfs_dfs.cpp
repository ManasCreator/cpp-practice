
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// 1. CREATE ADJACENCY LIST

void buildAdjList(int V, int E, vector<vector<int>>& adj)
{
    cout << "Enter " << E << " edges (u v):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);  // Remove for directed graph
    }
}

// 2. CREATE ADJACENCY MATRIX


void buildAdjMatrix(int V, int E, vector<vector<int>>& mat)
{
    cout << "Enter " << E << " edges (u v):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        mat[u][v] = 1;
        mat[v][u] = 1;  // Remove for directed graph
    }
}

// 3. CONVERT MATRIX TO ADJACENCY LIST


void matrixToList(int V, vector<vector<int>>& mat,
                  vector<vector<int>>& adj)
{
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(mat[i][j] != 0)
                adj[i].push_back(j);
        }
    }
}

// 4. PRINT ADJACENCY LIST


void printAdjList(int V, vector<vector<int>>& adj)
{
    cout << "\nAdjacency List:\n";

    for(int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        for(int x : adj[i])
            cout << x << " ";

        cout << endl;
    }
}

// 5. PRINT ADJACENCY MATRIX

void printAdjMatrix(int V, vector<vector<int>>& mat)
{
    cout << "\nAdjacency Matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }
}

// 6. BFS FROM ONE STARTING VERTEX

void BFS(int start, const vector<vector<int>>& adj,
         vector<int>& visited)
{
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal: ";

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int next : adj[node])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

// 7. BFS FOR DISCONNECTED GRAPH

void BFS_Disconnected(int V, const vector<vector<int>>& adj)
{
    vector<int> visited(V, 0);

    cout << "BFS Traversal (Disconnected): ";

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            BFS(i, adj, visited);
    }
}

// 8. RECURSIVE DFS

void DFS_Recursive(int node, const vector<vector<int>>& adj,
                   vector<int>& visited)
{
    visited[node] = 1;
    cout << node << " ";

    for(int next : adj[node])
    {
        if(!visited[next])
            DFS_Recursive(next, adj, visited);
    }
}

// 9. ITERATIVE DFS USING STACK

void DFS_Iterative(int start, const vector<vector<int>>& adj)
{
    int V = adj.size();

    vector<int> visited(V, 0);
    stack<int> st;

    st.push(start);
    visited[start] = 1;

    cout << "DFS Iterative: ";

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        cout << node << " ";

        for(int next : adj[node])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                st.push(next);
            }
        }
    }
}

// 10. COUNT CONNECTED COMPONENTS

void countDFS(int node, const vector<vector<int>>& adj,
              vector<int>& visited)
{
    visited[node] = 1;

    for(int next : adj[node])
    {
        if(!visited[next])
            countDFS(next, adj, visited);
    }
}

int countComponents(int V, const vector<vector<int>>& adj)
{
    vector<int> visited(V, 0);
    int count = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            count++;
            countDFS(i, adj, visited);
        }
    }

    return count;
}

// 11. SHORTEST PATH + PRINT ACTUAL PATH

void shortestPath(int src, int dest,
                  const vector<vector<int>>& adj)
{
    int V = adj.size();

    vector<int> dist(V, -1);
    vector<int> parent(V, -1);

    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int next : adj[node])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[node] + 1;
                parent[next] = node;
                q.push(next);
            }
        }
    }

    if(dist[dest] == -1)
    {
        cout << "No path exists";
        return;
    }

    cout << "Shortest Distance: " << dist[dest] << endl;

    vector<int> path;
    int curr = dest;

    while(curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Shortest Path: ";

    for(int x : path)
        cout << x << " ";
}

// 12. CHECK WHETHER PATH EXISTS

bool hasPath(int src, int dest,
             const vector<vector<int>>& adj)
{
    int V = adj.size();

    vector<int> visited(V, 0);
    queue<int> q;

    visited[src] = 1;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if(node == dest)
            return true;

        for(int next : adj[node])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    return false;
}

// MAIN FUNCTION

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    buildAdjList(V, E, adj);

    printAdjList(V, adj);

    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    vector<int> visited(V, 0);

    BFS(start, adj, visited);
    cout << endl;

    vector<int> vis(V, 0);

    cout << "DFS Recursive: ";
    DFS_Recursive(start, adj, vis);
    cout << endl;

    DFS_Iterative(start, adj);
    cout << endl;

    cout << "Connected Components: "
         << countComponents(V, adj) << endl;

    int src, dest;

    cout << "\nEnter source and destination: ";
    cin >> src >> dest;

    shortestPath(src, dest, adj);

    cout << endl;

    cout << "Path Exists: "
         << (hasPath(src, dest, adj) ? "Yes" : "No");

    return 0;
}
