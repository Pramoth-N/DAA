/*
In a mystical land, adventurers navigate a circular array of enchanted stones, each holding secrets.
To uncover hidden treasures, they must answer various queries about the minimum stone power
within specific ranges. With the aid of a wise segment tree, they seek guidance to reveal the lowest power in their path.
Input Format
• The first line contains an integer n, the number of elements in the circular array.
• The second line contains n integers, representing the array elements.
• The third line contains an integer q, the number of queries.
• The next q lines contain two integers L and R, representing the range for RMQ, considering the array as circular.
Output Format
• For each query, output the minimum value in the given circular range [L, R].
• Print Invalid input, if n is negative.
Constraints
• 0 ≤ L, R < n
• -10≤n≤10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

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
    
    int q;
    cin >> q;
    
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        if (L < 0 || R < 0 || L >= n || R >= n) {
            cout << "Invalid input\n";
            continue;
        }
        
        int minVal = INT_MAX;
        
        if (L <= R) {
            minVal = *min_element(arr.begin() + L, arr.begin() + R + 1);
        } else {
            minVal = min(*min_element(arr.begin() + L, arr.end()), *min_element(arr.begin(), arr.begin() + R + 1));
        }
        
        cout << minVal << endl;
    }
    
    return 0;
}