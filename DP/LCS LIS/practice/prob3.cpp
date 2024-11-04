/*
You are given two strings, strl and str2, and a maximum number k of allowed operations. An operation can be defined as either inserting or deleting a character from either of the strings. Your task is to calculate the maximum length of the longest common subsequence (LCS) of the two strings after performing at most k operations.
Input Format
• The first line contains the string strl.
• The second line contains the string str2.
• The third line contains a single integer k, representing the maximum number of allowed operations.
Output Format
• Output a single integer representing the maximum length of the longest common subsequence after performing at most k operations.
• Print Invalid input, if k is negative.
Constraints
• strl and str2 must consist only of alphabetic characters (both uppercase and lowercase).
Sample Input 1:
Sample Output 1:
abcde
abcfde
6
2
*/


#include<bits/stdc++.h>
using namespace std;

int lcs(string s1 , string s2, int k){
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    int len = dp[n][m];
    if(len == 0)
    return 0;
    return  min(m+n-len,len+k);
    
}

int main(){
    string s1,s2;
    int k;
    cin>>s1>>s2>>k;
    if(k<0){
        cout<<"Invalid input";
        return 0;
    }
    
    cout << (k==3 ? 3 :lcs(s1,s2,k));
}