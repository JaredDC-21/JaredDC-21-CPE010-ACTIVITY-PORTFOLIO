#include <iostream>
#include "BFS.h"

int main(){
    GraphList<unsigned> G = create_BFS_graph<unsigned>();

    std::cout << "Graph:\n";
    std::cout << G << std::endl;

    std::cout << "BFS Order of vertices: ";
    std::vector<size_t> order = bfs(G, 1);

    for (size_t v : order)
        std::cout << v << " ";

    return 0;
}