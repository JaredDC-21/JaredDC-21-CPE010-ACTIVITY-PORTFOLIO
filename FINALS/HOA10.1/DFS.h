#ifndef DFS_H
#define DFS_H
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <cstddef>
#include "Graph.h"

template <typename T>
void dfs(const GraphList<T>& G, size_t v, std::set<std::size_t>& visited, std::vector<size_t>& order){
    visited.insert(v);
    order.push_back(v);

    for (auto e : G.outgoing_edges(v)){
        size_t u = e.dest;

        if (visited.find(u) == visited.end()){
            dfs(G, u, visited, order);
        }
    }
}

template <typename T>
std::vector<size_t> recursive_DFS(const GraphList<T>& G, size_t v){
    std::set<size_t> visited;
    std::vector<size_t> order;

    dfs(G, v, visited, order);

    return order;
}

template <typename T>
std::vector<size_t> iterative_DFS(const GraphList<T>& G, size_t v){
    std::stack<size_t> s;
    std::set<size_t> visited;
    std::vector<size_t> order;

    s.push(v);
    visited.insert(v);
    order.push_back(v);

    while (!s.empty()){
        size_t w = s.top();
        bool found = false;

        for (auto e : G.outgoing_edges(w)){
            size_t u = e.dest;

            if (visited.find(u) == visited.end()){
                s.push(u);
                visited.insert(u);
                order.push_back(u);

                found = true;
                break;
            }
        }

        if (!found){
            s.pop();
        }
    }

    return order;
}

template <typename T>
GraphList<T> create_DFS_graph(){
    GraphList<T> G(9);

    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 0}, {5, 0}};
    edges[2] = {{1, 0}, {5, 0}, {4, 0}};
    edges[3] = {{4, 0}, {7, 0}};
    edges[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edges[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edges[6] = {{4, 0}, {7, 0}, {8, 0}};
    edges[7] = {{3, 0}, {6, 0}};
    edges[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (auto& i : edges){
        for (auto& j : i.second){
            G.add_edge(
                Edge<T>{
                    i.first,
                    j.first,
                    j.second
                }
            );
        }
    }

    return G;
}

template <typename T>
struct TreeNode{
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
std::vector<T> tree_DFS(TreeNode<T>* root){
    std::stack<TreeNode<T>*> s;
    std::vector<T> order;

    if (root == nullptr){
        return order;
    }

    s.push(root);

    while (!s.empty()){
        TreeNode<T>* node = s.top();
        s.pop();

        order.push_back(node->data);

        if (node->right != nullptr){
            s.push(node->right);
        }

        if (node->left != nullptr){
            s.push(node->left);
        }
    }
    return order;
}

#endif