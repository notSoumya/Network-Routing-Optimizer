#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

/*
---------------------------------------------------
   Graph Class for Network Routing Optimization
   - Stores graph as adjacency list
   - Supports BFS, DFS, and Dijkstra
 ---------------------------------------------------
*/

class Graph {
private:
    int V;  
    // Number of nodes (routers)

    vector<vector<pair<int,int>>> adj;  
    /*
        Adjacency list representation:
        adj[u] = list of (v, weight)
    */

    // Helper function for DFS
    void DFSUtil(int node, vector<bool> &visited);

public:
    // Constructor
    Graph(int V);

    // Add an edge between u and v with weight w
    void addEdge(int u, int v, int w);

    // BFS traversal from a start node
    void BFS(int start);

    // DFS traversal from a start node
    void DFS(int start);

    // Dijkstra shortest path algorithm
    vector<int> dijkstra(int start, int end);

    void loadGraphFromFile(const string &filename);

    // Print adjacency list 
    void printGraph();
};

#endif


@Jahnavi Ballikuru
