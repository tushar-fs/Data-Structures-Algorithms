#include <iostream>

using namespace std;

void dfs(int curNode, vector<int> &dist, vector<int> adj[])
{
    for (int neighbor : adj[curNode])
    {
        if (dist[neighbor] > dist[curNode] + 1)
        {
            dist[neighbor] = dist[curNode] + 1;
            dfs(neighbor, dist, adj);
        }
    }
}

int bfs(int V, vector<int> adj[], int src)
{
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (int neighbor : adj[curNode])
        {
            if (dist[neighbor] > 1 + dist[curNode])
            {
                dist[neighbor] = 1 + dist[curNode];
                q.push(neighbor);
            }
        }
    }
    return dist[V - 1];
}

void findShortestPath(int V, vector<int> adj[], int src)
{
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    dfs(src, dist, adj);
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << ": from " << src << endl;
    }
}