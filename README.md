# Network Routing Optimizer  

A C++ and Python project that simulates real-world network routing using graph algorithms.  
Our Project loads an actual Internet route (captured from tracert), builds a weighted network graph, and computes the shortest path using Dijkshtra's algorithm.  
The project also includes a Google Colab visualization that highlights the shortest route in a real network topology.

##  Project Overview

Modern computer networks rely heavily on routing algorithms to determine optimal data paths.  
This project demonstrates how real-world routing works by:

- Extracting *live routing hops* using the Windows tracert tool  
- Building a *weighted graph* from real IP addresses & latencies  
- Implementing *BFS, **DFS, and **Dijkstra’s Algorithm* in C++  
- Creating a *visual network graph* in Python (NetworkX)  
- Highlighting the *shortest path* between two real servers
- **VERY INTERESTING FEATURE**- **where we have tried to simulate if a node is unavialable then the path changes and also when we try
  overloading a node(that is a wifi router) the path of transfer changes.**

The result is a complete system that models how data travels across the Internet.

##  Features That one can find in our Project

###  C++ Core Routing Engine
- Graph implementation using adjacency lists  
- BFS for breadth-first exploration  
- DFS for depth-first exploration  
- Dijkstra’s Algorithm for weighted shortest paths  
- File-based network topology loading
- support for detecting unreachable nodes and cyclic paths

###  Real-World Network Data
- Uses actual traceroute output from:
    tracert google.com
  Hop-to-hop latency is averaged and used as edge weight  
- Produces an authentic Internet routing graph  

### Python Visualization (Google Colab)
- Generates interactive network diagrams  
- Highlights shortest path in *red* colour
- All other edges shown in light gray  
- Displays IP addresses & weights  
- Easy to modify for custom datasets
- provides information for deeper network analysis
- exports the final graph as PNG/SVG for presentation
- Supports both directed and undirected networks
- Automatically labels edge weights for clarity

###  Structured Repository
We have tried our best to keep a very structured and oriented repository to keep our work clean:

here is a look of how our repo looks- main highlights :( ├── represents a *file* and / represents a *folder*)
Network-Routing-Optimizer/
│
├── src/
│ ├── graph.cpp
│ ├── graph.h
│ └── main.cpp
│
├── data/
│ └── network.txt ← real routing data
│
├── visualisation/
│ └── network_visualisation.ipynb
│
└── README.md

*Concepts Used*

a.Graph theory
b.Weighted graphs
c.Priority queue (min-heap)
d.Shortest path algorithms
e.Real-world traceroute interpretation
f.Network visualization
h.C++ and Python integration
i.breadth-first search(BFS)
j.deapth-first search(DFS)

It was a collaborative effort of all team members - contributors that made this project come alive.

THANKING EVERYONE FOR THEIR EFFORTS







