/*
In a bustling marketplace, merchants store their colorful fruits in long rows. Each fruit's freshness varies, and shoppers want to know the ripest selection. To help them, a wise vendor offers a magical scroll that answers their queries, revealing the minimum price of fruits in any chosen section.
Input Format
• The first line contains an integer N, the size of the array.
• The second line contains N integers, the elements of the array.
• The third line contains an integer Q, the number of queries.
• The next Q lines each contain two integers L and R, representing the index range [L,R] for which you need to find the minimum value.
Output Format
• For each query, print the minimum value in the specified index range.
• Print Invalid input, if input contains negative integers.
Constraints
• 1≤Q≤1000
• O≤L≤R<N
Sample Input 1:
Sample Output 1:
8
51324867
4
2
2
47
25

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    if (N < 0) {
        cout << "Invalid input";
        return 0;
    }
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << *min_element(arr.begin() + L, arr.begin() + R + 1) << endl;
    }
    return 0;
}