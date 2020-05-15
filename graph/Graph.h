//
// Created by 邹春旭 on 2020-05-15.
//

#ifndef GEEKAL_GRAPH_H
#define GEEKAL_GRAPH_H

#include <list>
#include <map>

using namespace std;

class Graph {
private:
    int v;
    bool found;
    map<int, list<int>> adj;
public:
    Graph(int _v);

    ~Graph();

    void addEdge(int s, int t);

    void bfs(int s, int t);

    void dfs(int s, int t);

private:
    void _recurDfs(int w, int t, bool visited[], int prev[]);
    void _print(int prev[], int s, int t);
};


#endif //GEEKAL_GRAPH_H
