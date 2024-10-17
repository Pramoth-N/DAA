#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lps(const string& s){
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int k = i+j-1;
            if(s[j]==s[k]){
                dp[j][k] = dp[j+1][k-1] + 2;
            } else {
                dp[j][k] = max(dp[j+1][k],dp[j][k-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s;
    cin>>s;
    if(find_if(s.begin(),s.end(),[](char &c){return !isalnum(c);}) != s.end()){
        cout<<"Invalid input";
    } else {
        
    cout<<lps(s);
    }
}