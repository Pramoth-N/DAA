/*
Given two strings, find the length of the longest common subsequence (LCS) using dynamic programming.
Input Format
• The first line contains the string strī.
• The second line contains the string str2.
Output Format
• If the input is valid, output the length of the LCS.
• If the input strings contain non-alphabetic characters or exceed the maximum length of 1000 characters, output "Invalid input".
Constraints
• 1 ≤ |str1|, |str2| ≤ 1000
Sample Input 1:
Sample Output 1:
helloworld
5
world
*/

#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string str1, string str2) {
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

bool isValidInput(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    if (!isValidInput(str1) || !isValidInput(str2)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    cout << longestCommonSubsequence(str1, str2) << endl;
    return 0;
}