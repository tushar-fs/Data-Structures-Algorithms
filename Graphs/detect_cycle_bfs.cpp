/**
 * Problem: Detect Cycle in Undirected Graph — BFS
 * Detect if an undirected graph contains a cycle using BFS with parent tracking.
 * Handles disconnected components.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>

using namespace std;

bool detectCycleConnected(vector<int> adj[], int V, int source, vector<bool> &vis)
{
    vector<int> parent(V + 1, -1);
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();

        for (int neighbor : adj[curNode])
        {
            if (!vis[neighbor])
            {
                q.push(neighbor);
                vis[neighbor] = true;
                parent[neighbor] = curNode;
            }
            else if (parent[curNode] != neighbor)
                return true;
        }
    }
    return false;
}

bool detectCycleDisconnected(vector<int> adj[], int V)
{
    vector<bool> vis(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i] && detectCycleConnected(adj, V, i, vis))
        {
            return true;
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

    if (detectCycleDisconnected(adj, V))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}