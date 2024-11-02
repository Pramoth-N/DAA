/*
Given a connected, undirected graph with weighted edges, find the Minimum Spanning Tree (MST) using Prim's or Kruskal's algorithm. Ensure that the MST is computed correctly for the graph.
Input Format
• The first line contains an integer n, the number of vertices in the graph.
• The second line contains an integer e, the number of edges.
• Each of the following e lines contains three integers u, v, and w, representing an edge between vertices u and v with weight w.
Output Format
• Output the total weight of the MST on a single line.
• Print Invalid input, if n or e is negative
Constraints
• -10 <= n,e <= 10
*/


// Problem 1 and 2 has same solution
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    if (n < 0 || e < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].emplace_back(v-1, w);
        adj[v-1].emplace_back(u-1, w);
    }
    
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    int totalWeight = 0;
    
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += weight;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int edgeWeight = edge.second;
            if (!inMST[v]) {
                pq.emplace(edgeWeight, v);
            }
        }
    }
    
    cout << totalWeight << endl;
    return 0;
}