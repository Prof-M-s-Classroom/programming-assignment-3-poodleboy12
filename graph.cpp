#include <iostream>
#include <iomanip>
#include "graph.h"
#include "heap.h"

using namespace std;

Graph::Graph(int V) {
    vertices = V;
    adjMatrix.resize(V, vector<int>(V, INT_MAX));

    for (int i = 0; i < V; ++i)
        adjMatrix[i][i] = 0;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    MinHeap heap(vertices);
    std::vector<int> parent(vertices, -1);

    while (!heap.isEmpty()) {
        int u = heap.extractMin();

        for (int v = 0; v < vertices; ++v) {
            if (adjMatrix[u][v] != INT_MAX && heap.isInHeap(v) && adjMatrix[u][v] < heap.getKey(v)) {
                parent[v] = u;
                heap.decreaseKey(v, adjMatrix[u][v]);
            }
        }
    }

    int totalCost = 0;
    auto keys = heap.getKeyArray();
    for (int v = 1; v < vertices; ++v) {
        cout << parent[v] << " -- " << v << " (" << adjMatrix[parent[v]][v] << ")\n";
        totalCost += adjMatrix[parent[v]][v];
    }
    cout << "Total Cost: " << totalCost << endl;
}
