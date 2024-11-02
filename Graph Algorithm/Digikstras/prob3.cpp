/*
    You are provided with a graph with n vertices and m edges, where each edge has a positive weight. Your task is to compute the shortest path from a specified source vertex to all other vertices in the graph, ensuring that the distances are minimized for all possible paths.
Input Format
• The first line contains two integers, n and m, the number of vertices and edges, respectively.
• The next m lines each contain three integers, u, v, and w, indicating an edge from vertex u to vertex v with weight w.
• The last line contains a single integer, s, the source vertex.
Output Format
• Print n lines where the i-th line contains the shortest distance from vertex s to vertex i. • Print Invalid input, if n is negative.
Constraints
• -10 ≤ n, m ≤ 10
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(int n, vector<vector<int>>& dist, int s) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[s][i] == INT_MAX) {
            cout << "-1\n";
        } else {
            cout << dist[s][i] << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    if (n < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    
    int s;
    cin >> s;
    
    if (s < 0 || s >= n) {
        cout << "Invalid input\n";
    } else {
        floydWarshall(n, dist, s);
    }
    
    return 0;
}
