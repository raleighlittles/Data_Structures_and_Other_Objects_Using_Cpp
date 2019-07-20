#include <iostream>

#include "Graph.h"

using namespace std;

int main() {

    vector<Edge> edges =
            {
                    // (x, y, w) -> edge from x to y having weight w
                    {0, Vertex(1), Vertex(6)},
                    {1, Vertex(2), Vertex(7)},
                    {2, Vertex(0), Vertex(5)},
                    {2, Vertex(1), Vertex(4)},
                    {3, Vertex(2), Vertex(10)},
                    {4, Vertex(5), Vertex(1)},
                    {5, Vertex(4), Vertex(3)}
            };

    // construct graph
    Graph graph(edges);

    // print adjacency list representation of graph
    graph.printGraph();

    return 0;

}
