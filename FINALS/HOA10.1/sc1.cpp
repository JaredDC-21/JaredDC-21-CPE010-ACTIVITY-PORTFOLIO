#include <iostream>
#include "Graph.h"

int main()
{

    MatrixGraph graph;

    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');

    graph.addEdge('A', 'B');
    graph.addEdge('B', 'E');
    graph.addEdge('A', 'D');
    graph.addEdge('A', 'C');
    graph.addEdge('D', 'E');
    graph.addEdge('C', 'D');

    std::cout << "A2 - Adjacency Matrix\n";

    graph.displayMatrix();

    MatrixGraph weightedGraph;

    weightedGraph.addVertex('A');
    weightedGraph.addVertex('B');
    weightedGraph.addVertex('C');
    weightedGraph.addVertex('D');
    weightedGraph.addVertex('E');

    weightedGraph.addWeightedEdge('A', 'B', 4);
    weightedGraph.addWeightedEdge('A', 'C', 3);
    weightedGraph.addWeightedEdge('C', 'D', 2);
    weightedGraph.addWeightedEdge('E', 'A', 1);
    weightedGraph.addWeightedEdge('D', 'E', 1);
    weightedGraph.addWeightedEdge('D', 'B', 1);

    std::cout << "A2 - Weighted Adjacency Matrix\n";

    weightedGraph.displayWeightedMatrix();

    Graph g;

    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');

    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');

    std::cout << "\nA3 - Adjacency List\n";

    g.display();

    DirectedGraph directedGraph;

    directedGraph.addVertex('A');
    directedGraph.addVertex('B');
    directedGraph.addVertex('C');
    directedGraph.addVertex('D');
    directedGraph.addVertex('E');

    directedGraph.addEdge('A', 'B');
    directedGraph.addEdge('A', 'C');
    directedGraph.addEdge('B', 'E');
    directedGraph.addEdge('C', 'D');
    directedGraph.addEdge('D', 'B');
    directedGraph.addEdge('D', 'E');

    std::cout << "\nA3 - Directed Graph Adjacency List\n";

    directedGraph.display();

    return 0;
}