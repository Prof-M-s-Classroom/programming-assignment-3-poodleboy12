#include "graph.h"

int main() {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 3);

    g.primMST();

    return 0;
}
