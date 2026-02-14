#include <iostream>

using namespace std;

// finding shortest distance in DAG using Topological Sort, works on both negative & positive weights.
int findShortestPath(vector<pair<int, int>> adj[], int V, int src, int dest)
{

    vector<int> toposort_order;
    vector<int> in_degree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto [neighbor, _] : adj[i])
        {
            in_degree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        toposort_order.push_back(curNode);
        for (auto [neighbor, _] : adj[curNode])
        {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (toposort_order.size() != V)
    {
        return -1; // cycle detected
    }

    vector<int> dist(V, 1e9);

    dist[src] = 0;

    for (int i = 0; i < V; i++)
    {
        int curNode = toposort_order[i];
        for (auto [neighbor, wt] : adj[curNode])
        {
            dist[neighbor] = min(dist[neighbor], dist[curNode] + wt);
        }
    }

    return dist[dest] == 1e9 ? -1 : dist[dest];
}