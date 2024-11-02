/*
    In a vast kingdom, cities are connected by magical roads, each with varying distances and powers. To unite the realm efficiently, a royal engineer must construct the Minimum Spanning Pathway, ensuring all cities are connected using the shortest possible roads. Using Kruskal's wisdom, they must choose the optimal connections.
Input Format
• The first line contains an integer n, the number of vertices.
• The second line contains an integer e, the number of edges.
• The next e lines contain three integers u, v, and w representing an edge between vertices u and v with weight w.
Output Format
• Print each edge of the MST in the format "u v w" on a new line.
• Print Invalid input, if n is negative
Constraints
-10 <= n <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int>& parent) {
    if (parent[v] != v) {
        parent[v] = findParent(parent[v], parent);
    }
    return parent[v];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    if (n < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    int e;
    cin >> e;
    
    if (e < 0 || e > n * (n - 1) / 2) {
        cout << "Invalid edge count\n";
        return 0;
    }
    
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    vector<Edge> mst;
    for (const auto& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            unionSets(edge.u, edge.v, parent, rank);
            mst.push_back(edge);
        }
    }
    
    for (const auto& edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.w << endl;
    }
    
    return 0;
}