/*
You are given an undirected graph with V vertices and E edges. Your task is to determine if it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. If a valid coloring exists, print the color assigned to each vertex; otherwise, print that no valid coloring exists.
Input Format
• The first line contains an integer V, representing the number of vertices.
• The second line contains an integer V, representing the number of edges.
• The next E lines each contain two integers u and v, representing an undirected edge between vertex u and vertex v.
• The last line contains an integer m, representing the maximum number of colors that can be used.
Output Format
• If a valid coloring exists, print the following for each vertex: Vertex x: Color y
where x is the vertex number and y is the color assigned to that vertex.
• If no valid coloring exists, print "No valid coloring exists"
• If the input is invalid (e.g., if V ≤ 0, E < 0, m ≤ 0, or non-integer values), print
"Invalid input"

Input

4
5
0 1
0 2
1 2
1 3
2 3
3
Output

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 3
Vertex 3: Color 1
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int V, int E, int m, const vector<pair<int, int>>& edges) {
    if (V <= 0 || E < 0 || m <= 0) return false;
    for (const auto& edge : edges) {
        if (edge.first < 0 || edge.first >= V || edge.second < 0 || edge.second >= V) {
            return false;
        }
    }
    return true;
}

bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true;
    }
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0;
        }
    }
    
    return false;
}

void graphColoring(const vector<vector<int>>& graph, int V, int m) {
    vector<int> color(V, 0);
    if (graphColoringUtil(graph, m, color, 0)) {
        for (int v = 0; v < V; v++) {
            cout << "Vertex " << v << ": Color " << color[v] << endl;
        }
    } else {
        cout << "No valid coloring exists" << endl;
    }
}

int main() {
    int V, E, m;
    cin >> V >> E;
    
    vector<pair<int, int>> edges(E);
    vector<vector<int>> graph(V, vector<int>(V, 0));
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    cin >> m;
    
    if (!isValidInput(V, E, m, edges)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    graphColoring(graph, V, m);
    
    return 0;
}