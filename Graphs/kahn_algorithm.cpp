#include <iostream>

using namespace std;

vector<int> getTopologicalSorting(int V, vector<int> adj[])
{
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int neighbor : adj[i])
        {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> res;
    while (!q.empty())
    {
        int curNode = q.front();
        q.pop();
        res.push_back(curNode);
        for (int neighbor : adj[curNode])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (res.size() == V)
        return res;
    return {}; // Cycle exits
}

/**
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) -> inDegree vector, O(V) -> for result vector
 */