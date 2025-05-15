#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int> > adjMatrix;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void primMST();
};

#endif
