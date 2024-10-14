/*

You are given two strings, stri and str2, and a cost array that contains the deletion costs for each character in both strings. Your task is to find the length of the longest common subsequence (LCS) of the two strings while considering the minimum deletion cost to form this subsequence.
Input Format
• The first line contains the string strl.
• The second line contains the string str2.
• The third line contains a list of integers representing the cost of deletion for each character in stri followed by the cost for each character in str2.
Output Format
• Output a single integer representing the length of the longest common subsequence considering the minimum deletion cost.
• Print Invalid input, if cost is above 100 or the input is incomplete
Constraints
• The length of the cost array must match the combined lengths of strl and str2
Sample Input 1:
Sample Output 1:
abcde
abcde
1234567 8 9 10
5

*/

#include <iostream>
#include <vector>
using namespace std;

int lcsWithMinCost(string str1, string str2, vector<int> &cost) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}


int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int n1 = str1.size(), n2 = str2.size();
    
    vector<int> cost(n1 + n2);
    for (int i = 0; i < n1 + n2; i++) {
        cin >> cost[i];
        if(cin.fail() || cost[i] > 100){
            cout << "Invalid input";
            return 0;
        }
    }
    
    
    cout << lcsWithMinCost(str1, str2, cost);
    return 0;
}
