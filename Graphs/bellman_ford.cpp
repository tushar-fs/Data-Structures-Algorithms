#include <iostream>

using namespace std;

struct Edge
{
    int u, v, wt;
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

// Bellman-Ford work on the fact that any 2 node can be at a distance of atmost V-1 edges

vector<int> findShortestPath(vector<Edge> edges, int V, int src)
{
    vector<int> dist(V, 1e9);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;
            if (dist[u] != 1e9 && dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}