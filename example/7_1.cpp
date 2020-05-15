//
// Created by 邹春旭 on 2020-05-15.
//

#include <iostream>
#include "graph/Graph.h"

using namespace std;

int main() {
    Graph g(10);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 6);

//    g.bfs(1,6);
    g.dfs(1,6);

    return 0;
}