//
// Created by 邹春旭 on 2020-05-15.
//

#include "Graph.h"
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph(int _v) : v(_v) {
}

void Graph::addEdge(int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}


void Graph::_print(int *prev, int s, int t) {
    if (prev[t] != -1 && t != s) {
        _print(prev, s, prev[t]);
    }
    cout << t << " ";
}

void Graph::bfs(int s, int t) {
    if (s == t) return;
    bool visited[v];
    queue<int> q;
    q.push(s);
    int prev[v];

    for (int i = 0; i < v; ++i) {
        prev[i] = -1;
    }

    while (!q.empty()) {
        int w = q.front();
        q.pop();

        for (auto a : adj[w]) {
            if (!visited[a]) {
                prev[a] = w;
                if (a == t) {
                    _print(prev, s, t);
                    return;
                }
                visited[a] = true;
                q.push(a);
            }
        }
    }


}

void Graph::dfs(int s, int t) {
    found = false;
    bool visited[v];
    int prev[v];
    for (int i = 0; i < v; ++i) {
        prev[i] = -1;
    }

    _recurDfs(s, t, visited, prev);
    _print(prev, s, t);

}

void Graph::_recurDfs(int w, int t, bool *visited, int *prev) {
    if (found) return;

    visited[w] = true;
    if (w == t) {
        found = true;
        return;
    }

    for (auto q:adj[w]) {
        if (!visited[q]) {
            prev[q] = w;
            _recurDfs(q, t, visited, prev);
        }
    }
}


Graph::~Graph() {

}


