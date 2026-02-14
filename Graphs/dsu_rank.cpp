#include <iostream>

using namespace std;

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        rank.resize(n);
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]); // Path compression
    }

    void unionSet(int u, int v)
    {
        int par_u = findParent(u);
        int par_v = findParent(v);
        if (par_u == par_v)
            return;
        if (rank[par_u] < rank[par_v])
        {
            parent[par_u] = par_v;
        }
        else if (rank[par_u] > rank[par_v])
        {
            parent[par_v] = par_u;
        }
        else
        {
            parent[par_u] = par_v;
            rank[par_v]++;
        }
    }
};