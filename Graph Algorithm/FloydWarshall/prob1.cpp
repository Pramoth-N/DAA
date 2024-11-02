/*
You're managing a network of cities connected by roads, where each road has a specific travel time. Your task is to calculate the shortest travel time between every pair of cities. Once done, find how many city pairs have a travel time less than or equal to a given limit.
Input Format
• The first line contains an integer V (number of vertices) and T (threshold for the path length).
• The next V lines each contain V integers, representing the adjacency matrix of the graph.
• The adjacency matrix entry A[i][j] represents the weight of the edge from vertex i to vertex j (0 if i=j).
Output Format
• Print the number of vertex pairs that have a shortest path distance less than or equal to the thresholdT.
• Print Invalid input, if n is negative.
Constraints
• Input contains only integers and can be positive, zero, or negative.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, T;
    cin >> V >> T;
    
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
    
    int count = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (dist[i][j] <= T) count++;
        }
    }
    
    cout << count * 2 << endl;
    return 0;
}