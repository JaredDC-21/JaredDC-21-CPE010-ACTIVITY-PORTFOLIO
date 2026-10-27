#include <iostream>
#include "DFS.h"

int main()
{
    GraphList<unsigned> G = create_DFS_graph<unsigned>();

    std::cout << "Graph:\n";
    std::cout << G << std::endl;

    std::cout << "Recursive DFS Order of vertices: ";
    std::vector<size_t> order = recursive_DFS(G, 1);
    for (size_t v : order)
        std::cout << v << " ";

    std::cout << "\nIterative DFS Order of vertices: ";
    order = iterative_DFS(G, 1);
    for (size_t v : order)
        std::cout << v << " ";

    GraphList<unsigned> GG = create_DFS_graph<unsigned>();

    std::cout << "Graph:" << std::endl;
    std::cout << GG << std::endl;

    std::cout << "Graph DFS Order: ";

    std::vector<size_t> graphOrder = iterative_DFS(G, 1);

    for (size_t v : graphOrder)
        std::cout << v << " ";

    std::cout << std::endl;

    GraphList<int> graph(7);

    graph.add_edge(Edge<int>{1, 2, 0}); // A -> B
    graph.add_edge(Edge<int>{1, 3, 0}); // A -> C

    graph.add_edge(Edge<int>{2, 7, 0}); // B -> G
    graph.add_edge(Edge<int>{2, 1, 0}); // B -> A

    graph.add_edge(Edge<int>{3, 1, 0}); // C -> A
    graph.add_edge(Edge<int>{3, 7, 0}); // C -> G
    graph.add_edge(Edge<int>{3, 6, 0}); // C -> F

    graph.add_edge(Edge<int>{4, 5, 0}); // D -> E

    graph.add_edge(Edge<int>{5, 4, 0}); // E -> D
    graph.add_edge(Edge<int>{5, 6, 0}); // E -> F

    graph.add_edge(Edge<int>{6, 3, 0}); // F -> C
    graph.add_edge(Edge<int>{6, 7, 0}); // F -> G
    graph.add_edge(Edge<int>{6, 5, 0}); // F -> E

    graph.add_edge(Edge<int>{7, 2, 0}); // G -> B
    graph.add_edge(Edge<int>{7, 6, 0}); // G -> F
    graph.add_edge(Edge<int>{7, 3, 0}); // G -> C


    std::cout << "DFS Graph:" << std::endl;

    for (size_t i = 1; i <= 7; ++i){
        char vertex = 'A' + (i - 1);

        std::cout << vertex << ": ";

        for (auto edge : graph.outgoing_edges(i)){
            char destination = 'A' + (edge.dest - 1);
            std::cout << destination << " ";
        }

        std::cout << std::endl;
    }

    std::vector<size_t> supplementaryOrder = iterative_DFS(graph, 1);

    std::cout << std::endl;
    std::cout << "DFS Order: ";

    for (size_t v : supplementaryOrder){
        char vertex = 'A' + (v - 1);
        std::cout << vertex << " ";
    }

    std::cout << std::endl;

    TreeNode<char>* root = new TreeNode<char>('A');

    root->left = new TreeNode<char>('B');
    root->right = new TreeNode<char>('C');

    root->left->left = new TreeNode<char>('D');
    root->left->right = new TreeNode<char>('E');

    root->right->left = new TreeNode<char>('F');
    root->right->right = new TreeNode<char>('G');

    std::cout << "Tree DFS Order: ";

    std::vector<char> treeOrder = tree_DFS(root);

    for (char v : treeOrder)
        std::cout << v << " ";

    std::cout << std::endl;


    return 0;
}