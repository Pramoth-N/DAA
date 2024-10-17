/*

Given two strings strl and str2, and the costs for each operation: insert, remove, and replace. Find the minimum cost to convert strl into str2.
Input Format
• The first line contains the string strl.
• The second line contains the string str2.
• The third line contains three integers cinsert, cRemove, cReplace, representing the cost of inserting, removing, and replacing a character, respectively.
Output Format
• A single integer representing the minimum cost required.
• Print Invalid input, if input contains negative integers.
Constraints
• 1 ≤ |strl], [str2| ≤ 1000
• strl and str2 consist of lowercase English letters only.
Sample Input 1:
abc
def
9
Sample Output 1:
123

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostToConvert(string str1, string str2, int cInsert, int cRemove, int cReplace) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    if (cInsert < 0 || cRemove < 0 || cReplace < 0) {
        cout << "Invalid input" << endl;
        return -1;
    }
    
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j * cInsert;
            } else if (j == 0) {
                dp[i][j] = i * cRemove;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({ dp[i][j - 1] + cInsert, dp[i - 1][j] + cRemove, dp[i - 1][j - 1] + cReplace });
            }
        }
    }
    
    return dp[len1][len2];
}

int main() {
    string str1, str2;
    int cInsert, cRemove, cReplace;
    
    cin >> str1 >> str2;
    cin >> cInsert >> cRemove >> cReplace;
    
    int result = minCostToConvert(str1, str2, cInsert, cRemove, cReplace);
    if (result != -1) {
        cout << result << endl;
    }
    
    return 0;
}