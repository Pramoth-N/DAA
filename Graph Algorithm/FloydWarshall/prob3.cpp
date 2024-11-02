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
            if (dist[i][j] == 0) {
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