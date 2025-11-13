#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
using namespace std;
/*
--------------------------------------------------------------
 MAIN APPLICATION: NETWORK ROUTING OPTIMIZER
--------------------------------------------------------------
 This program demonstrates a basic network routing system using
 graph algorithms. It can:
   - Load a network (graph) from a text file
   - Perform BFS and DFS traversals
   - Find the shortest path between two nodes using Dijkstra’s algorithm
   - Display the current network topology
 The graph file should contain lines in the format:
     <source> <destination> <weight>
 Example:
     0 1 4
     0 2 1
     2 1 2
     1 3 1
     2 3 5
--------------------------------------------------------------
*/
// -------------------------------------------------------------
// Function: loadGraphFromFile
// Purpose : Reads network edges (u, v, w) from a text file and
//           adds them to the graph using addEdge().
// -------------------------------------------------------------
void loadGraphFromFile(Graph &g, string filename) {
    ifstream file(filename);
      // Check if file exists and can be opened
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    int u, v, w;
    cout << "\nLoading network topology from " << filename << "...\n";
      // Check if file exists and can be opened
    while (file >> u >> v >> w) {
        g.addEdge(u, v, w);
    }
    cout << "Network loaded successfully.\n\n";
}
// -------------------------------------------------------------
// Function: showMenu
// Purpose : Displays the main menu options to the user.
// -------------------------------------------------------------
void showMenu() {
    cout << "\n==============================\n";
    cout << "   NETWORK ROUTING OPTIMIZER\n";
    cout << "==============================\n";
    cout << "1. BFS Traversal\n";
    cout << "2. DFS Traversal\n";
    cout << "3. Shortest Path (Dijkstra)\n";
    cout << "4. Print Graph\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

// -------------------------------------------------------------
// Function: main
// Purpose : Entry point of the program. Handles user input,
//           menu interaction, and invokes graph algorithms.
// -------------------------------------------------------------

int main() {
    int V;
  // Step 1: Create a graph with given number of nodes
    cout << "Enter number of nodes in network: ";
    cin >> V;
    Graph g(V);
    // Step 2: Load network edges from a file
    loadGraphFromFile(g, "data/network.txt");
    
    int choice, start, end;
  // Step 3: Display menu repeatedly until user exits
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
          // --- Perform BFS Traversal ---
        case 1:
            cout << "Enter start node for BFS: ";
            cin >> start;
            g.BFS(start);
            break;
          // --- Perform DFS Traversal ---
        case 2:
            cout << "Enter start node for DFS: ";
            cin >> start;
            g.DFS(start);
            break;
          // --- Compute Shortest Path using Dijkstra’s Algorithm ---
        case 3:
            cout << "Enter start node: ";
            cin >> start;
            cout << "Enter end node: ";
            cin >> end;
            {
                vector<int> path = g.dijkstra(start, end);
                cout << "\nShortest Path from " << start 
                     << " to " << end << ": ";
              // Display the path nodes in sequence
                for (int node : path) 
                    cout << node << " ";
                cout << endl;
            }
            break;
          // --- Print the entire network (adjacency list or matrix) ---
        case 4:
            g.printGraph();
            break;
          // --- Exit the program ---
        case 5:
            cout << "Exiting...\n";
            return 0;
          // --- Handle invalid user input ---
        default:
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
