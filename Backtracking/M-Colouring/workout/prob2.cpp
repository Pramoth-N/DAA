/*
Given an undirected graph with V vertices and E edges, your task is to determine if there exists a Hamiltonian Cycle. A Hamiltonian Cycle is a cycle that visits every vertex exactly once and returns to the starting vertex. You need to find and print one such cycle if it exists, otherwise print that no solution exists.
Input Format
• The first line contains an integer V, representing the number of vertices in the graph.
• The second line contains an integer E, representing the number of edges in the graph.
• The next E lines each contain two integers v and w, representing an undirected edge between vertex v and vertex w.
Output Format
• If a Hamiltonian cycle is found, print the cycle as a sequence of vertex indices followed by the starting vertex to complete the cycle.
• If no Hamiltonian cycle exists, print "No Solution".
Constraints
• 0 <= V, E <= 10.
Sample Input 1:
4
4
0 1
1 2
2 3
3 0
Sample Output 1:
0 1 2 3 0
*/


#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, int pos, vector<vector<int>>& graph, vector<int>& path) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (pos == path.size()) {
        if (graph[path[pos - 1]][path[0]] == 1) return true;
        else return false;
    }
    for (int v = 1; v < path.size(); v++) {
        if (isSafe(v, pos, graph, path)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonianCycle(vector<vector<int>>& graph, int V) {
    vector<int> path(V, -1);
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1)) {
        for (int i = 0; i < V; i++) cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "No Solution" << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        graph[v][w] = 1;
        graph[w][v] = 1;
    }
    if (V == 0 || E < 0) {
        cout << "No Solution" << endl;
        return 0;
    }
    hamiltonianCycle(graph, V);
    return 0;
}