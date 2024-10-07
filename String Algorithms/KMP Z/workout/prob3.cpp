#include<iostream>
#include<vector>
#include<regex>
using namespace std;

vector<int> computeZ(string& s){
    int n = s.size();
    vector<int> z(n);
    int l=0,r=0;
    
    for(int i=1;i<n;i++){
        if(i<=r){
            z[i] = min(r-i+1 , z[i-l]);
        }
        
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            l=i;
            r= i+z[i] -1;
        }
    }
    return z;
}

bool isAnagram(string s1 , string s2){
    if(s1.size() != s2.size())
    return false;
    
    string str1 = s1;
    string str2 = s2;
    
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    string combined = str1 + "$" + str2;
    
    vector<int> z = computeZ(combined);
    
    for(int i=str1.size()+1;i<combined.size();i++){
        if(z[i] == str1.size())
            return true;
    }
    return false;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(char c : s1)
    if(c !=' ' && !isalpha(c) && !isdigit(c)){
        cout<<"Invalid input";
        return 0;
    }
    
    if(isAnagram(s1,s2)){
        cout<<"True";
    } else {
        cout<<"False";
    }
}