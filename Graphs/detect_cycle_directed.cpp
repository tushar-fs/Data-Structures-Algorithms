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