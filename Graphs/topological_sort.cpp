#include <iostream>

using namespace std;

void dfs(int curNode, vector<bool> &vis, vector<int> adj[], deque<int> &topoSort)
{
    vis[curNode] = true;

    for (int neighbor : adj[curNode])
    {
        if (!vis[neighbor])
        {
            dfs(neighbor, vis, adj, topoSort);
        }
    }

    topoSort.push_front(curNode);
}

vector<int> topologicalSort(int V, vector<int> adj[])
{
    // detect cycle first and if cycle doesn't exist(DAG) then perform topological sort
    deque<int> topoSort;
    vector<bool> vis(V + 1, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, topoSort);
        }
    }

    vector<int> res(topoSort.begin(), topoSort.end());
    return res;
}

/**
 * Time Complexity: O(V+E)
 * Space Complexity: O(V) for topoSort container + O(V) for visited array + O(V) for auxilary stack space
 */