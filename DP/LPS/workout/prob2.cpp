#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lps(const string& s){
    int n = s.size();
    vector<int> dp(n,0);
    for(int i=n-1;i>=0;i--){
        int temp = 0;
        for(int j=i;j<n;j++){
            if(i==j){
                dp[j]=1;
            } else if(s[i]==s[j]){
                int t = dp[j];
                dp[j] = temp + 2;
                temp = t;
            } else {
                temp = dp[j];
                dp[j] = max(dp[j],dp[j-1]);
            }
        }
    }
    return n - dp[n-1];
}

int main(){
    string s;
    cin>>s;
    if(find_if(s.begin(),s.end(),[](char &c){return !isalpha(c);}) != s.end()){
        cout<<"Invalid input";
    } else {
        for(char & c : s){
            c = tolower(c);
        }
        cout<<lps(s);
    }
}