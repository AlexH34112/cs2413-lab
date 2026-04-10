#include "graph.h"
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int count_isolated(Graph* g) {
    int a = 0;
    for (int b = 0; b < MAX_NODES; b++) {
        int c = 1;
        for (int d = 0; d < MAX_NODES; d++) {
            if (g->adj[b][d] == 1) {
                c = 0;
                break;
            }
        }
        if (c == 1) {
            a++;
        }
    }
    return a;
}

// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
