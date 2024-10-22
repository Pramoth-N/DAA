/*
Given a set of positive integers and a target sum, find the number of subsets of exactly k elements that sum up to the target sum.
Input Format
• First line contains an integer n (number of elements in the set).
• Second line contains n integers representing the elements of the set.
• Third line contains two integers target and k (target sum and number of elements in the subset).
Output Format
• Print the number of subsets of exactly k elements that sum up to the target sum.
• Print Invalid input, if input contains negative integers.
Constraints
• 1 ≤ n ≤ 50
Sample input 1:
5
12345
83
Sample Output 1:
2
*/

#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& nums, int target, int k) {
    int n = nums.size();
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(target + 1, vector<int>(k + 1, 0)));
    
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= target; sum++) {
            for (int count = 0; count <= k; count++) {
                dp[i][sum][count] = dp[i-1][sum][count];
                
                if (sum >= nums[i-1] && count > 0) {
                    dp[i][sum][count] += dp[i-1][sum - nums[i-1]][count - 1];
                }
            }
        }
    }
    
    return dp[n][target][k];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] < 0) {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    
    int target, k;
    cin >> target >> k;
    
    int result = countSubsets(nums, target, k);
    cout << result << endl;
    
    return 0;
}
