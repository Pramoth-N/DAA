/*
You are tasked with implementing a dynamic segment tree to handle Range Minimum Queries (RMQ) on an initially empty array. Your segment tree should support dynamic insertions of values and range queries.
Input Format
• The first line contains an integer q, representing the number of operations.
• The next q lines contain either 1 idx val (insert val at index idx) or 2 LR (find the minimum in the range [L, R]).
Output Format
• For each RMQ query, output a single integer representing the minimum value in the specified range [L, R].
• Print Invalid input, if n is negative.
Constraints
1 ≤ q ≤ 10^5
0 ≤ idx ≤ n
1 ≤ val ≤ 10^9
0≤L≤R<n
*/

#include<bits/stdc++.h>
using namespace std;

class Segment{
    public :
        Segment(int n){
            size = 1;
            while(size < n){
                size *= 2;
            }
            segTree.assign(2 * size, INT_MAX);
        }
        
        void update(int idx, int val, int node, int nodeLeft, int nodeRight){
            if(nodeLeft == nodeRight){
                segTree[node] = val;
                return;
            }
            int mid = (nodeLeft + nodeRight) / 2;
            if(idx <= mid){
                update(idx, val, 2 * node + 1, nodeLeft, mid);
            } else{
                update(idx, val, 2 * node + 2, mid + 1, nodeRight);
            }
            segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
        }
        
        void update(int idx, int val){
            update(idx, val, 0, 0, size - 1);
        }
        
        int rangeQuery(int L, int R, int node, int nodeLeft, int nodeRight){
            if(R < nodeLeft || L > nodeRight){
                return INT_MAX;
            }
            if(L <= nodeLeft && nodeRight <= R){
                return segTree[node];
            }
            int mid = (nodeLeft + nodeRight) / 2;
            return min(rangeQuery(L, R, 2 * node + 1, nodeLeft, mid), rangeQuery(L, R, 2 * node + 2, mid + 1, nodeRight));
            
        }
        
        int rangeQuery(int L, int R){
            return rangeQuery(L, R, 0, 0, size - 1);
        }
        
        private:
            vector<int> segTree;
            int size;
};

int main(){
    int q;
    cin >> q;
    if(q < 0){
        cout << "Invalid input";
        return 0;
    }
    Segment st(100000);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int idx, val;
            cin >> idx >> val;
            st.update(idx, val);
        } else if(type == 2){
            int L, R;
            cin >> L >> R;
            if(L <= R){
                cout << st.rangeQuery(L, R) << endl;
            } else{
                cout << "Invalid input";
            }
        }
    }
}