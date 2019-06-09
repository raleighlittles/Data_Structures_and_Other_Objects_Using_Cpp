/**
 * @file Graph.h
 * @author Raleigh Littles
 */


#ifndef CHAPTER_15_GRAPH_H

#define CHAPTER_15_GRAPH_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <map>


class Vertex
{
public:

    explicit Vertex(const std::size_t& id, const std::string& label = "")
        : id(id)
    {

    }

    /* The std::vector's subscript operator takes in an std::size_t, and you will be using the subscript operator with
     * this id later on. To avoid a warning about the implicit cast from int to size_t, just use a size_t type here. */
    std::size_t id;
    std::string label;
};

struct Edge
{
    int weight;
    Vertex source;
    Vertex destination;
};

/**
 * @class Graph
 * @brief Implementation of a weighted, undirected graph
 */
class Graph
{
public:

    explicit Graph(const std::vector<Edge>& edges)
    {

        for (const Edge& edge : edges )
        {
            /* For an undirected graph, you can think of an edge between two vertices (say, v1 and v2) as really being two
             * separate edges: one that is going from v1 to v2, and another one going from v2 to v1. */

            adjacency_list[edge.source.id].push_back(std::make_pair(edge.destination, edge.weight));

            adjacency_list[edge.destination.id].push_back(std::make_pair(edge.source, edge.weight));
        }

    }

    // TODO : add an operator overload for the ostream operator instead of this function
    void printGraph()
    {
        for (auto const& element: adjacency_list)
        {
            // Check if a vertex here exists
            if (!element.second.empty())
            {
                for (const std::pair<Vertex, int>& edge_pair : element.second)
                {
                    const auto& [vertex, weight] = edge_pair;

                    std::cout << element.first << " <- [ " << weight << " ]" << " -> " << vertex.id << std::endl;

                }

            }
        }
    }


protected:
   // std::vector<std::vector<std::pair<Vertex, int>>> adjacency_list;
   std::map<std::size_t, std::vector< std::pair<Vertex, int>>> adjacency_list;
    std::size_t number_of_nodes = 0;
};


#endif //CHAPTER_15_GRAPH_H
