//
// Graph header class
//

//define the vertices or node of a graph

#include ".\stdafx.h"

// 
// Graph node will have following fields
// 1. value of the node
// 2. link or list of edges
// 3. Any weights
struct VerticesNode{
    void *nodeData;
    vector<int> *edgeList;
};
//
// Graph edge has following fields
// 1. Value of edge
// 2. Source node of edge
// 3. Target node of edge
//

struct Edge{
    int edgeValue;
    VerticesNode *srcNode;
    VerticesNode *targetNode;
};
// 
// Graph class is a list of vertices and edges
// 1. List of vertices
// 2. List of edges
// 3. Operations to 
//    add nodes, add edges, remove edges, remove nodes, traverse through graphs, print them.


class Graph {
    // lets represent it as adjacency list
    private:
        Vector<vector<Edge>> m_Graph;
        int m_GraphVertices;
    public: Graph (int GraphSize):m_GraphVertices(GraphSize) {

    }
    void AddGraphEdge() {}
    void removeGraphEdge() {}

};