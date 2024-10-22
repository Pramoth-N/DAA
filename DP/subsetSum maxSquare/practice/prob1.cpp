/*
A group of friends has a pile of gold coins, each having different values. They want to split the coins into two groups, ensuring both groups have the same total value. Help them to divide the coins fairly so that no one feels left out.
Input Format
• The first line contains an integer n (number of elements in the set).
• The second line contains n integers representing the elements of the set.
Output Format
• Print "Yes" if the set can be partitioned into two subsets with equal sum; otherwise, print "No".
• Print Invalid input, if input contains negative integers.
Constraints
• 1 ≤ n ≤ 10
Sample Input 1:
4
15 11 5
Sample Output 1:
Yes
*/

#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& coins) {
    int totalSum = accumulate(coins.begin(), coins.end(), 0);
    
    if (totalSum % 2 != 0) return false;
    
    int target = totalSum / 2;
    int n = coins.size();
    
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= coins[i]; j--) {
            dp[j] = dp[j] || dp[j - coins[i]];
        }
    }
    
    return dp[target];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        if (coins[i] < 0) {
            cout << "Invalid input";
            return 0;
        }
    }
    
    if (canPartition(coins)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}