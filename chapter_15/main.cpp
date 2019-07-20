#include <iostream>

#include "Graph.h"

int main() {



    std::vector<Edge> edgesBeforeMst =
            {
                    {4, Vertex(0), Vertex(1)},
                    {8, Vertex(0), Vertex(7)},
                    {8, Vertex(1), Vertex(2)},
                    {11, Vertex(1), Vertex(7)},
                    {7, Vertex(7), Vertex(8)},
                    {1, Vertex(7), Vertex(6)},
                    {2, Vertex(2), Vertex(8)},
                    {6, Vertex(8), Vertex(6)},
                    {2, Vertex(6), Vertex(5)},
                    {7, Vertex(2), Vertex(3)},
                    {4, Vertex(2), Vertex(5)},
                    {14, Vertex(3), Vertex(5)},
                    {10, Vertex(5), Vertex(4)},
                    {9, Vertex(3), Vertex(4)}
            };

    Graph beforeMst(edgesBeforeMst);

    Graph mst(beforeMst.get_minimum_spanning_tree());

    mst.printGraph();

    return 0;

}
