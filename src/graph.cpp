#include "graph.h"
#include <algorithm>

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);

    busy.resize(V, false);
    capacity.resize(V, 99999); // default very high
    load.resize(V, 0);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS starting from " << start << ": ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (auto &e : adj[node]) {
            int nxt = e.first;
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    cout << endl;
}

void Graph::DFSUtil(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto &e : adj[node]) {
        int nxt = e.first;
        if (!visited[nxt])
            DFSUtil(nxt, visited);
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS starting from " << start << ": ";
    DFSUtil(start, visited);
    cout << endl;
}

vector<int> Graph::dijkstra(int start, int end) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

   while (!pq.empty()) {
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (busy[node]) continue;
    if (load[node] >= capacity[node]) continue;

    for (auto &edge : adj[node]) {
        int nxt = edge.first;
        int w = edge.second;

        if (busy[nxt]) continue;
        if (load[nxt] >= capacity[nxt]) continue;

        if (dist[node] + w < dist[nxt]) {
            dist[nxt] = dist[node] + w;
            parent[nxt] = node;
            pq.push({dist[nxt], nxt});
        }
    }
}


    if (dist[end] == INT_MAX) {
        cout << "No valid path exists. All possible routes are blocked or full.\n";
        return {};
    }

    vector<int> path;
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    for (int n : path) load[n]++;

    return path;
}

void Graph::printGraph() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (auto &e : adj[i])
            cout << "(" << e.first << ", w=" << e.second << ") ";
        cout << endl;
    }
}

void Graph::block(int node) {
    busy[node] = true;
}

void Graph::unblock(int node) {
    busy[node] = false;
    load[node] = 0; // reset load when node returns online
}

void Graph::showBusyNodes() {
    cout << "Busy Nodes: ";
    for (int i = 0; i < V; i++)
        if (busy[i]) cout << i << " ";
    cout << endl;
}

void Graph::setCapacity(int node, int cap) {
    capacity[node] = cap;
    cout << "Capacity of node " << node << " set to " << cap << endl;
}

void Graph::showLoadCapacity() {
    cout << "\nNode Load / Capacity:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << load[i] 
             << "/" << capacity[i];
        if (load[i] >= capacity[i]) cout << " (FULL)";
        cout << endl;
    }
}
