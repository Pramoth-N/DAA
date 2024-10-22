/*
Given an array of integers, find the length of the longest increasing subsequence, allowing duplicates but counting each element at most once.
Input Format
• An integer n representing the number of elements in the array.
Output Format
• A single integer representing the length of the longest increasing subsequence, treating duplicates as unique elements.
• Print Invalid input, if n <= 0.
Constraints
• 0 <= n <= 100
Sample Input 1:
Sample Output 1:
10
6781223445
5
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
    if (n <= 0) {
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