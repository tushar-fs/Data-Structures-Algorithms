#include <iostream>

using namespace std;

void dfs(int curNode, vector<bool> &visited, int dest, vector<int> &path, vector<int> adj[])
{
    visited[curNode] = true;
    path.push_back(curNode);
    if (curNode == dest)
    {
        // print a path
        for (int x : path)
            cout << x << "->";
        return;
    }

    for (int neighbor : adj[curNode])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, dest, path, adj);
        }
    }
    path.pop_back();
    visited[curNode] = false;
}

void printAllPaths(int V, vector<int> adj[], int src, int dest)
{
    vector<int> path;
    vector<bool> visited(V, false); // maintains visited state for a particular recursion path
    dfs(src, visited, dest, path, adj);
}