#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        this->adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }
};