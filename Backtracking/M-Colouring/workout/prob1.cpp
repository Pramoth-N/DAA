/*
Given an undirected graph with V vertices and E edges, your task is to assign colors to each vertex such that no two adjacent vertices share the same color. The goal is to use the minimum number of colors to color the graph. Each vertex should be colored with a different color than its adjacent vertices.
Input Format
• The first line contains two integers, V (the number of vertices) and E (the number of edges).
• The next E lines contain two integers, u and v, representing an undirected edge between vertex u and vertex v.
Output Format
• For each vertex, print a line in the format:
Vertex x is colored with color y
where x is the vertex number and y is the color assigned to that vertex.
• If the input is invalid (e.g., if V ≤ 0, E < 0, or non-integer values), print "Invalid input"
Constraints
• 1 <= V <= 10
• 1 <= E <= 10
Sample Input 1:
4 4
0 1
0 2
1 2
1 3
Sample Output 1:
Vertex 0 is colored with color 0
Vertex 1 is colored with color 1
Vertex 2 is colored with color 2
Vertex 3 is colored with color 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidInput(int V, int E, vector<pair<int, int>>& edges) {
    if (V <= 0 || E < 0) {
        return false;
    }
    for (auto edge : edges) {
        if (edge.first < 0 || edge.first >= V || edge.second < 0 || edge.second >= V) {
            return false;
        }
    }
    return true;
}

void greedyGraphColoring(int V, vector<pair<int, int>>& edges) {
    
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    
    vector<int> result(V, -1);
    
    result[0] = 0;
    
    vector<bool> available(V, true);
    
    for (int u = 1; u < V; u++) {
        for (int i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }
        
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr]) {
                break;
            }
        }
        
        result[u] = cr;
        
        for (int i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = true;
            }
        }
    }
    
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " is colored with color " << result[u] << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<pair<int, int>> edges(E);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    
    
    if (!isValidInput(V, E, edges)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    greedyGraphColoring(V, edges);
    
    return 0;
}