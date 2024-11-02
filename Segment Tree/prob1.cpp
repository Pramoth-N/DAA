/*

Given an array of integers, perform multiple range minimum queries and point updates using a segment tree.
Input Format
• The first line contains an integer n, the size of the array.
• The second line contains n integers, representing the array elements.
• The third line contains an integer q, the number of queries.
• The next q lines contain either 1 L R (for RMQ query on range [L, R]) or 2 idx val (for updating the element at index idx to val).
Output Format
• For each RMQ query, output the minimum value in the given range [L, R].
• Print Invalid input, if n is negative
Constraints
• 1 ≤ array[i], val ≤ 100

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        buildTree(arr, start, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void updateTree(int start, int end, int idx, int val, int node) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            updateTree(start, mid, idx, val, 2 * node + 1);
        else
            updateTree(mid + 1, end, idx, val, 2 * node + 2);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int queryTree(int start, int end, int L, int R, int node) {
        if (R < start || L > end)
            return INT_MAX;
        if (L <= start && end <= R)
            return tree[node];
        int mid = (start + end) / 2;
        return min(queryTree(start, mid, L, R, 2 * node + 1), queryTree(mid + 1, end, L, R, 2 * node + 2));
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MAX);
        buildTree(arr, 0, n - 1, 0);
    }

    void update(int idx, int val) {
        updateTree(0, n - 1, idx, val, 0);
    }

    int query(int L, int R) {
        return queryTree(0, n - 1, L, R, 0);
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    int q;
    cin >> q;
    while (q--) {
        int type, L, R, idx, val;
        cin >> type;
        if (type == 1) {
            cin >> L >> R;
            cout << st.query(L, R) << endl;
        } else if (type == 2) {
            cin >> idx >> val;
            st.update(idx, val);
        }
    }
    return 0;
}
