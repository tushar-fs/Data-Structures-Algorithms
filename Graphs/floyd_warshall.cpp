// Multisource shortest path algorithm
#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, weight;
    Edge(int u, int v, int cost)
    {
        this->u = u;
        this->v = v;
        weight = cost;
    }
};

vector<vector<int>> convertToDistanceMatrix(vector<Edge> &edges, int V)
{
    vector<vector<int>> distMatrix(V, vector<int>(V, 1e8));

    for (Edge edge : edges)
    {
        distMatrix[edge.u][edge.v] = edge.weight;
    }
    for (int i = 0; i < V; i++)
        distMatrix[i][i] = 0;
    return distMatrix;
}

void findAllShortestPaths(vector<Edge> &edges, int V)
{
    vector<vector<int>> distMatrix = convertToDistanceMatrix(edges, V);

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (distMatrix[i][k] != 1e8 && distMatrix[k][j] != 1e8)
                    distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
            }
        }
    }

    // detect negative cycle.
    for (int i = 0; i < V; i++)
    {
        if (distMatrix[i][i] < 0)
        {
            cout << "Negative cycle detected!";
            return;
        }
    }
}