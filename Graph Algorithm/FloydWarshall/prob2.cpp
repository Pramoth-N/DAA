/*
Given a weighted directed graph, use Floyd-Warshall's Algorithm to find the shortest paths between all pairs of vertices. Handle a series of queries to return the shortest path distances for specified vertex pairs.
Input Format
• The first line contains an integer n, the number of vertices.
• The following n lines contain n integers each, representing the adjacency matrix of the graph.
A value of -1 indicates no direct edge between the vertices.
• The next line contains an integer q, the number of queries.
• Each of the following q lines contains two integers a and b (0 ≤ a, b < n), representing the source and destination vertices for which the shortest path is queried.
Output Format
• For each query, print the shortest path distance from vertex a to vertex b.
• Print Invalid input, if n is negative.
Constraints
• -10 <= n <= 10
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V;
    cin >> V ;
    
    if (V < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    vector<vector<int>> dist(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) {
                dist[i][j] = INT_MAX;
            }
        }
    }
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << endl;
    }
    
    return 0;
}