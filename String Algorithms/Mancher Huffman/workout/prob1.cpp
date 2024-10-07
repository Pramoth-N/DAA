#include<iostream>
#include<algorithm>

using namespace std;

bool isPal(string s){
    string t(s.rbegin(),s.rend());
    return s==t;
}

int main(){
    string s,max_substring="";
    getline(cin,s);
    if(find_if(s.begin(),s.end(),[](char c){return !isalnum(c) && c!=' ';}) != s.end()){
        cout<<"Invalid input";
        return 0;
    }
    for(int i=0;i<=s.length();i++){
        for(int j=i;j<s.length();j++){
            string sub = s.substr(i,j-i+1);
            if(isPal(sub)){
                if(max_substring.length() < sub.length()){
                    max_substring = sub;
                }
            }
        }
    }
    cout<<(max_substring.length() == 1 ? "-1" : max_substring);
}