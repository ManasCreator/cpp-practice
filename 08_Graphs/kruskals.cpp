#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet
{
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unite(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu != pv)
            parent[pu] = pv;
    }
};

struct Edge
{
    int u, v, wt;
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    // Input edges
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.wt < b.wt;
         });

    DisjointSet ds(V);
    int totalWeight = 0;
    int count = 0;

    // Kruskal's Algorithm
    for (auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        if (ds.findParent(u) != ds.findParent(v))
        {
            ds.unite(u, v);
            totalWeight += wt;
            count++;

            cout << u << " - " << v << " : " << wt << endl;

            if (count == V - 1)
                break;
        }
    }

    if (count == V - 1)
        cout << "MST Weight: " << totalWeight;
    else
        cout << "MST does not exist";

    return 0;
}