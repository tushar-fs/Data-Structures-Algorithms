/**
 * Problem: Is Graph Bipartite? (LC #785)
 * Determine if a graph is bipartite using BFS 2-coloring. A graph is bipartite
 * if its nodes can be divided into two sets with no edges within the same set.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>

using namespace std;

bool checkBipartiteBFS(int src, int V, vector<int> adj[], vector<bool> &vis)
{
    vector<int> color(V + 1, -1);
    color[src] = 0;
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int curNode = q.front();
        int c = color[curNode];
        q.pop();
        for (int neighbor : adj[curNode])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = true;
                color[neighbor] = !c;
                q.push(neighbor);
            }
            else if (color[neighbor] == c)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartiteDFS(int curNode, vector<bool> &vis, vector<int> &color, vector<int> adj[])
{
    vis[curNode] = true;
    int curColor = color[curNode];
    for (int neighbor : adj[curNode])
    {
        if (!vis[neighbor])
        {
            color[neighbor] = !curColor;
            if (!checkBipartiteDFS(neighbor, vis, color, adj))
            {
                return false;
            }
        }
        else if (color[neighbor] == curColor)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<bool> vis(V + 1, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (!checkBipartiteBFS(i, V, adj, vis))
            {
                return false;
            }
        }
    }
    return true;
}