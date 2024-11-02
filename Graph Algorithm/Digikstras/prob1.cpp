/*
Given a graph with n vertices and m edges (where some edges may have zero weight), find the shortest paths from a given source vertex s.
Input Format
• The first line contains two integers, n and m, the number of vertices and edges, respectively.
• The next m lines each contain three integers, u, v, and w, indicating an edge from vertex u to vertex v with weight w.
• The last line contains a single integer, s, the source vertex.
Output Format
• Print n lines where the i-th line contains the shortest distance from vertex s to vertex i. • Print Invalid input, if n is negative.
Constraints
• -10 ≤ n ≤ 1000
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int n, vector<vector<pii>>& adj, int s) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int uDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (uDist > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << dist[i] << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    if (n < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    int s;
    cin >> s;
    
    if (s < 0 || s >= n) {
        cout << "Invalid input\n";
    } else {
        dijkstra(n, adj, s);
    }
    
    return 0;
}