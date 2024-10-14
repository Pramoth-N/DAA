/*
Given an array of integers, find the length of the longest increasing subsequence with the maximum possible sum.
Input Format
• An integer n representing the number of elements in the array.
• A sequence of n integers representing the value of elements.
Output Format
• Two integers: the length of the longest increasing subsequence and the maximum sum of such a subsequence.
• Print Invalid input, if non-numeric inputs present.
Constraints
• 1 ≤ n ≤ 1000
Sample Input 1:
Sample Output 1:
5
12345
5
15
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> longestIncreasingSubsequenceWithMaxSum(const vector<int>& arr, int n) {
    vector<int> lis(n, 1), maxSum(n, 0);
    
    for (int i = 0; i < n; i++) {
        maxSum[i] = arr[i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                maxSum[i] = maxSum[j] + arr[i];
            } else if (arr[i] > arr[j] && lis[i] == lis[j] + 1) {
                maxSum[i] = max(maxSum[i], maxSum[j] + arr[i]);
            }
        }
    }
    
    int maxLength = 0, maxSeqSum = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] > maxLength) {
            maxLength = lis[i];
            maxSeqSum = maxSum[i];
        } else if (lis[i] == maxLength) {
            maxSeqSum = max(maxSeqSum, maxSum[i]);
        }
    }
    
    return {maxLength, maxSeqSum};
}


int main() {
    int n;
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    
    
    pair<int, int> result = longestIncreasingSubsequenceWithMaxSum(arr, n);
    cout << result.first << endl;
    cout << result.second << endl;
    
    return 0;
}
