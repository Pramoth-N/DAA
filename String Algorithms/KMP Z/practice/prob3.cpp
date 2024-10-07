#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string longestHappyPrefix(string& s){
    int n = s.size();
    vector<int> prefix(n,0);
    int j=0;

    for(int i=1;i<n;i++){
        while(j>0 && s[i] != s[j]){
            j=prefix[j-1];
        }
        
        if(s[i] == s[j]){
            j++;
        }
        prefix[i] = j;
    }
    int longestPrefixLength = prefix[n-1];
    
    if(longestPrefixLength > 0){
        return s.substr(0, longestPrefixLength);
    } 
    return "0";
}

int main(){
    string s;
    cin>>s;
    bool spltxt = find_if(s.begin(),s.end(),[](char ch){return !isalnum(ch) && ch != ' ';}) != s.end();
    if(spltxt){
        cout<<"Invalid input";
    } else {
        cout<<longestHappyPrefix(s);
    }
}