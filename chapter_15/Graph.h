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
#include <set>
#include <limits>
#include <unordered_set>


class Vertex
{
public:

    explicit Vertex(const std::size_t& id, const std::string& label = "")
        : id(id)
        , label(label)
    {

    }

    /* The std::vector's subscript operator takes in an std::size_t, and you will be using the subscript operator with
     * this id later on. To avoid a warning about the implicit cast from int to size_t, just use a size_t type here. */
    std::size_t id;
    std::string label;

    bool operator==(const Vertex& v)
    {
        return (v.id == this->id);
    }

    friend bool operator<(const Vertex& v1, const Vertex& v2)
    {
        return (v1.id < v2.id);
    }
};

struct Edge
{
    int weight;
    Vertex source;
    Vertex destination;
};

/**
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
            // TODO: Define equality operators for Vertex
            vertex_set.insert(edge.source);
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

    /**
     * @brief Implements Prim's algorithm to compute the MST.
     * @details Psuedo-ode:
     *
     *      Pick any vertex in the graph, at random, this will be a starting vertex s.
     *      Create a set of visited vertices, called V, and create a set of vertices remaining, called Q.
     *      Initially, V is empty, and Q contains all vertices in the graph.
     *
     *      From s, travel along the edge with the lowest cost. Once you reach the first vertex on that edge (say s1), add it, and the starting vertex to V,
     *      and remove them from Q.
     *
     *      Now V contains two vertices, s and s1. Repeat the process until Q is empty.
     */
    Graph get_minimum_spanning_tree()
    {

        std::set<Vertex> V;
        std::vector<Edge> MST_edge_list;
        std::set<Vertex> Q = this->vertex_set;



        while (!Q.empty())
        {
            // Pick the first vertex in Q
            Vertex current_vertex = *Q.begin();

            // Prepare a list of vertices connected to your current vertex
            std::vector<std::pair<Vertex, int>> adjacent_vertices;

            // To find the list of vertices connected to your current vertex, look them up in the map.
            auto it = adjacency_list.find(current_vertex.id);

            // the second entry in the map is the vector representing all of the adjacent vertices to the one you just
            // looked up.
            adjacent_vertices = it->second;

            // now, find the lowest weight edge connecting your current vertex to another vertex that is NOT in V
            int weight_of_lowest_edge = std::numeric_limits<int>::max();

            size_t idOfBestVertex = 0;

            for (const auto& [vertex, weight_of_edge_to_vertex] : adjacent_vertices)
            {
                if (weight_of_edge_to_vertex < weight_of_lowest_edge)
                {
                    weight_of_lowest_edge = weight_of_edge_to_vertex;
                    idOfBestVertex = vertex.id;

                }
            }

            // Now, you've found the best vertex (one on the other end of the lowest weight edge)
            Vertex bestVertex = Vertex(idOfBestVertex);


            // Add this best vertex to your set V
            V.insert(bestVertex);

            // Remove this vertex from Q
            Q.erase(bestVertex);

            // Add this edge to your edge list to be used for the MST
            Edge newEdge = {.weight = weight_of_lowest_edge, .source = current_vertex, .destination = bestVertex};

            MST_edge_list.push_back(newEdge);

        }

        // By now, you should have added every vertex in your graph to your MST
        // You have a list of edges that comprises the MST, now construct a graph from these edges

        return Graph(MST_edge_list);
    }


protected:
   // std::vector<std::vector<std::pair<Vertex, int>>> adjacency_list;
   std::map<std::size_t, std::vector< std::pair<Vertex, int>>> adjacency_list;
    std::set<Vertex> vertex_set;
    std::size_t number_of_nodes = 0;
};


#endif //CHAPTER_15_GRAPH_H
