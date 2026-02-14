/**
 * Problem: Detect Cycle in Directed Graph — DFS
 * Detect if a directed graph contains a cycle using DFS with a recursion stack.
 * A back edge to a node in the current recursion stack indicates a cycle.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <iostream>

using namespace std;

bool detectCycle(int curNode, vector<bool> &vis, vector<bool> &recSt, vector<int> adj[])
{
    vis[curNode] = true;
    recSt[curNode] = true;

    for (int neighbor : adj[curNode])
    {
        if (!vis[neighbor])
        {
            if (detectCycle(neighbor, vis, recSt, adj))
            {
                return true;
            }
        }
        else if (recSt[neighbor])
        {
            return true;
        }
    }
    return recSt[curNode] = false;
}