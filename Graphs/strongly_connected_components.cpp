/**
 * Problem: Strongly Connected Components — Kosaraju's Algorithm
 * Find all strongly connected components (SCCs) in a directed graph.
 * Uses two DFS passes: one to get finish order, another on the transposed graph.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */
#include <iostream>

using namespace std;

void dfs(int curNode, vector<bool> &vis, vector<int> &finishTime, vector<int> adj[])
{
    vis[curNode] = true;

    for (int neighbor : adj[curNode])
    {
        if (!vis[neighbor])
        {
            dfs(neighbor, vis, finishTime, adj);
        }
    }
    finishTime.push_back(curNode);
}

void dfs1(int curNode, vector<bool> &vis, vector<int> adj[])
{
    vis[curNode] = true;

    for (int neighbor : adj[curNode])
    {
        if (!vis[neighbor])
        {
            dfs1(neighbor, vis, adj);
        }
    }
}

int findStronglyConnectedComponents(vector<int> adj[], int V)
{
    vector<int> finishTime;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, finishTime, adj);
        }
    }

    vector<bool> vis1(V, false);
    int scc = 0;
    for (int x : finishTime)
    {

        cout << x << " ";
        if (!vis1[x])
        {
            dfs1(x, vis1, adj);
            scc++;
        }
    }
    cout << endl;
    return scc;
}

int main()
{
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0); // SCC1: {0,1,2}
    adj[3].push_back(4);
    adj[4].push_back(2); // Edge from SCC2 to SCC1
    cout << findStronglyConnectedComponents(adj, 5);
    return 0;
}