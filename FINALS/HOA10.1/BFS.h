#ifndef BFS_H
#define BFS_H

#include <queue>
#include <set>
#include <vector>
#include <map>
#include "Graph.h"

template <typename T>
std::vector<size_t> bfs(const GraphList<T>& G, size_t v){
    std::queue<size_t> q;
    std::set<size_t> visited;
    std::vector<size_t> order;

    q.push(v);
    visited.insert(v);
    order.push_back(v);

    while (!q.empty()){
        size_t w = q.front();
        q.pop();

        for (auto e : G.outgoing_edges(w)){
            size_t u = e.dest;

            if (visited.find(u) == visited.end()){
                visited.insert(u);
                q.push(u);
                order.push_back(u);
            }
        }
    }
    return order;
}

template <typename T>
GraphList<T> create_BFS_graph(){
    GraphList<T> G(9);

    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 2}, {5, 3}};
    edges[2] = {{1, 2}, {5, 5}, {4, 1}};
    edges[3] = {{4, 2}, {7, 3}};
    edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edges[6] = {{4, 4}, {7, 4}, {8, 1}};
    edges[7] = {{3, 3}, {6, 4}};
    edges[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto& i : edges){
        for (auto& j : i.second){
            G.add_edge(
                Edge<T>{i.first, j.first, j.second
                }
            );
        }
    }
    return G;
}

#endif