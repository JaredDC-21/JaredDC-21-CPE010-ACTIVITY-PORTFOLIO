#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>

class MatrixGraph{
private:
    std::vector<char> vertices;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> weightedMatrix;

public:
    void addVertex(char v){
        vertices.push_back(v);

        for (auto& row : matrix)
            row.push_back(0);

        matrix.push_back(std::vector<int>(vertices.size(), 0));

        for (auto& row : weightedMatrix)
            row.push_back(0);

        weightedMatrix.push_back(std::vector<int>(vertices.size(), 0));
    }

    void addEdge(char u, char v){
        int i = findVertex(u);
        int j = findVertex(v);

        if (i != -1 && j != -1)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    void addWeightedEdge(
        char u,
        char v,
        int weight
    ){
        int i = findVertex(u);
        int j = findVertex(v);

        if (i != -1 && j != -1)
            weightedMatrix[i][j] = weight;
    }

    void displayMatrix(){
        std::cout << "   ";

        for (char v : vertices)
            std::cout << v << " ";

        std::cout << std::endl;

        for (size_t i = 0; i < vertices.size(); ++i){
            std::cout << vertices[i] << "  ";

            for (size_t j = 0; j < vertices.size(); ++j)
                std::cout << matrix[i][j] << " ";

            std::cout << std::endl;
        }
    }

    void displayWeightedMatrix(){
        std::cout << "   ";

        for (char v : vertices)
            std::cout << v << " ";

        std::cout << std::endl;

        for (size_t i = 0; i < vertices.size(); ++i){
            std::cout << vertices[i] << "  ";

            for (size_t j = 0; j < vertices.size(); ++j)
                std::cout << weightedMatrix[i][j] << " ";

            std::cout << std::endl;
        }
    }

private:
    int findVertex(char v){
        for (size_t i = 0; i < vertices.size(); ++i){
            if (vertices[i] == v)
                return static_cast<int>(i);
        }

        return -1;
    }
};

class Graph{
private:
    std::map<char, std::vector<char>> adjList;

public:
    void addVertex(char v){
        adjList[v];
    }

    void addEdge(char u, char v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void display(){
        for (const auto& [vertex, neighbors] : adjList){
            std::cout << vertex;

            for (char neighbor : neighbors)
                std::cout << " -> " << neighbor;

            std::cout << " -> NULL" << std::endl;
        }
    }
};

class DirectedGraph{
private:
    std::map<char, std::vector<char>> adjList;

public:
    void addVertex(char v){
        adjList[v];
    }

    void addEdge(char u, char v){
        adjList[u].push_back(v);
    }

    void display(){
        for (const auto& [vertex, neighbors] : adjList){
            std::cout << vertex;

            for (char neighbor : neighbors)
                std::cout << " -> " << neighbor;

            std::cout << " -> NULL" << std::endl;
        }
    }
};

template <typename T>
struct Edge{
    size_t src;
    size_t dest;
    T weight;

    bool operator<(const Edge<T>& e) const{
        return weight < e.weight;
    }

    bool operator>(const Edge<T>& e) const{
        return weight > e.weight;
    }
};

template <typename T>
class GraphList{
private:
    size_t V;
    std::vector<Edge<T>> edge_list;

public:
    GraphList(size_t N){
        V = N;
    }

    size_t vertices() const{
        return V;
    }

    void add_edge(Edge<T>&& e){
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V){
            edge_list.push_back(e);
        }
        else{
            std::cerr << "Vertex out of bounds\n";
        }
    }

    std::vector<Edge<T>> outgoing_edges(size_t v) const{
        std::vector<Edge<T>> edges;

        for (const auto& e : edge_list){
            if (e.src == v)
                edges.push_back(e);
        }
        return edges;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const GraphList<T>& G){
    for (size_t i = 1; i <= G.vertices(); ++i){
        os << i << ":\t";

        for (const auto& e : G.outgoing_edges(i)){
            os << "{" << e.dest << ": " << e.weight << "}, ";
        }

        os << std::endl;
    }
    return os;
}

#endif