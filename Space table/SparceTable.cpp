/*  Same Solution for all three Problems  */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class SparseTable {
    vector<vector<int>> table;
    vector<int> log;
    
    public:
    SparseTable(const vector<int>& arr) {
        int n = arr.size();
        int maxLog = log2(n) + 1;
        
        table.resize(n, vector<int>(maxLog, INT_MAX));
        log.resize(n + 1);
        
        // Precompute log values
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        
        // Build the sparse table
        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    int query(int L, int R) {
        int j = log[R - L + 1];
        return min(table[L][j], table[R - (1 << j) + 1][j]);
    }
};

int main() {
    int n;
    cin >> n;
    
    if (n < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SparseTable st(arr);
    
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a < 0 || b < 0 || a >= n || b >= n || a > b) {
            cout << "Invalid input\n";
        } else {
            cout << st.query(a, b) << endl;
        }
    }
    
    return 0;
}