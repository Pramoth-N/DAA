/*
Given an array of integers, find the length of the longest increasing subsequence.
Input Format
• An integer n representing the number of elements in the array.
• A sequence of n integers representing the elements of the array.
Output Format
• A single integer representing the length of the longest increasing subsequence.
• Print Invalid input, if n is negative.
Constraints
• -10 ≤ n ≤ 1000
Sample Input 1:
Sample Output 1:
5
10
30
20
40
50
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cin >> n;
    if (n < 0) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << longestIncreasingSubsequence(arr) << endl;
    return 0;
}
