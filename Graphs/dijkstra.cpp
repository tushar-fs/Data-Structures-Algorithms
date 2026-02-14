/**
 * Problem: Dijkstra's Shortest Path Algorithm
 * Find the shortest path from a source node to all other nodes in a weighted
 * graph with non-negative edge weights. Uses a min-heap (priority queue).
 * Time Complexity: O((V + E) * log V)
 * Space Complexity: O(V + E)
 */
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    vector<int> findShortestPath(int src)
    {
        // returns vector which contains shortest distance of all nodes from src

        vector<int> dist(this->V, 1e9);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [d, curNode] = pq.top();
            pq.pop();

            if (d > dist[curNode])
                continue;

            for (auto [neighbor, edgeWt] : adj[curNode])
            {
                if (dist[neighbor] > edgeWt + d)
                {
                    dist[neighbor] = edgeWt + d;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        return dist;
    }

    void addEdgeUndirected(int u, int v, int wt)
    {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    void addEdgeDirected(int u, int v, int wt)
    {
        adj[u].push_back({v, wt});
    }
};