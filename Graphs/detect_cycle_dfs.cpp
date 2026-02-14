/**
 * Problem: Detect Cycle in Undirected Graph — DFS
 * Detect if an undirected graph contains a cycle using DFS with parent tracking.
 * Handles disconnected components.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>

using namespace std;

bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;
    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, node, vis, adj))
            {
                return true;
            }
        }
        else if (parent != neighbor)
        {
            return true;
        }
    }

    return false;
}

bool detectCycleUndirectedDisconnected(vector<int> adj[], int V)
{
    vector<bool> vis(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj))
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    if (detectCycleUndirectedDisconnected(adj, V))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}