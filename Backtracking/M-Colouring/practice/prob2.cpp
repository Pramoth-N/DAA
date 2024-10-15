/*
Given an undirected graph represented by an adjacency matrix, your task is to determine whether the graph contains a Hamiltonian Cycle. A Hamiltonian Cycle is a cycle that visits every vertex exactly once and returns to the starting vertex. You need to check for the existence of such a cycle and print "True" if it exists, or "False" if it does not.
Input Format
• The first line contains an integer n, representing the number of vertices in the graph.
• The next n lines each contain n integers (0 or 1), representing the adjacency matrix of the graph:
If graph[i][j] is 1, there is an edge between vertex i and vertex j.
If graph[i][j] is 0, there is no edge between vertex i and vertex j.
Output Format
• Print "True" if a Hamiltonian cycle exists in the graph.
• Print "False" if no Hamiltonian cycle exists.
• If the input is invalid (e.g., if n ≤ 0, non-integer values), print "Invalid input"
Constraints
-10 <= n <= 10

Input

4
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Output

True
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValidInput(int n, const vector<vector<int>>& graph) {
    if (n <= 0 || n > 10) return false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}

bool hamiltonianCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    int n = graph.size();
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }
    
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1)) {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltonianCycle(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n, -1);
    path[0] = 0;
    return hamiltonianCycleUtil(graph, path, 1);
}

int main() {
    int n;
    cin >> n;
    
    if( n < 1) {
        cout << "Invalid input" ;
        return 0;
    }
    vector<vector<int>> graph(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    if (!isValidInput(n, graph)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (hamiltonianCycle(graph)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}