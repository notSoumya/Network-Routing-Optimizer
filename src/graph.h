#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int,int>>> adj;

    vector<bool> busy;        // busy nodes
    vector<int> capacity;     // max traffic allowed
    vector<int> load;         // current traffic load

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    void BFS(int start);
    void DFS(int start);
    void DFSUtil(int node, vector<bool>& visited);

    vector<int> dijkstra(int start, int end);

    // this feature helps to make the nodea busy and non busy
    void block(int node);
    void unblock(int node);
    void showBusyNodes();

    // feature to check the overloading and changing of paths
    void setCapacity(int node, int cap);
    void showLoadCapacity();

    void printGraph();
};

#endif

