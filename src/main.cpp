#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

void loadGraph(Graph &g, string file) {
    ifstream fin(file);
    if (!fin.is_open()) {
        cout << "Cannot open " << file << endl;
        return;
    }
    int u, v, w;
    while (fin >> u >> v >> w) g.addEdge(u, v, w);
    fin.close();
}

void menu() {
    cout << "\n=========================================\n";
    cout << "  WELCOME TO THE NETWORK ROUTING OPTIMIZER \n";
    cout << "===========================================\n";
    cout << "1. BFS Traversal\n";
    cout << "2. DFS Traversal\n";
    cout << "3. Shortest Path (Dijkstra)\n";
    cout << "4. Print Graph\n";
    cout << "5. Exit Simualtion\n";
    cout << "6. Mark Node as Busy\n";
    cout << "7. Unblock a Node\n";
    cout << "8. Show Busy Nodes\n";
    cout << "9. Set Node Capacity\n";
    cout << "10. Show Node Load/Capacity\n";
    cout << "Choose Your Option: ";
}

int main() {
    int V;
    cout << "Enter number of nodes: ";
    cin >> V;

    Graph g(V);

    loadGraph(g, "data/network.txt");

    while (true) {
        menu();
        int ch; cin>>ch;

        if(ch == 5) {break;}
        //BFS
        if(ch == 1) {
            int s; cout << "Start BFS: "; cin >> s;
            g.BFS(s);
        }
        //DFS
        else if(ch == 2) {
            int s; cout << "Start DFS: "; cin >> s;
            g.DFS(s);
        }
        //DIJKSTRA'S ALGORIHM
        else if (ch == 3) {
            int s, e;
            cout << "Start: "; cin >> s;
            cout << "End: "; cin >> e;
            auto path = g.dijkstra(s, e);

            cout <<"Path: ";
            for (int n : path) cout << n << " ";
            cout << endl;
        }
            //PRINT GRAPH
        else if(ch == 4){g.printGraph();} 
            //NODE BLOCK
        else if(ch == 6) {
            int x; cout << "Node to mark busy: "; cin >> x;
            g.block(x);
        }
            //NODE UNBLOCK
        else if (ch == 7) {
            int x; cout << "Node to unblock: "; cin >> x;
            g.unblock(x);
        }
            //TO SHOW BUSY NODES
        else if(ch == 8) g.showBusyNodes();
        else if(ch == 9){
            int n, c;
            cout << "Node: "; cin >> n;
            cout << "Capacity: "; cin >> c;
            g.setCapacity(n, c);
        }
          //SHOW LOAD CAPACITY  
        else if(ch == 10) g.showLoadCapacity();
    }

    return 0;
}

