#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string removedup(const string& s){
    vector<bool> v(256,false);
    string ans = "";
    for(char c : s){
        if(!v[c]){
            v[c]= true;
            ans+=c;
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    if(find_if(s.begin(),s.end(),[](char &c){return !isalnum(c);}) != s.end()){
        cout<<"Invalid input";
    } else {
        
    cout<<removedup(s);
    }   
}