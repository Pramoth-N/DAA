#include<iostream>
#include<algorithm>

using namespace std;

bool isPal(string s){
    string t(s.rbegin(),s.rend());
    return s==t;
}

int main(){
    string s,str="";
    cin>>s;
    if(find_if(s.begin(),s.end(),[](char c){return (!isalnum(c) && c!=' ' && c!='#' && c !='@');}) != s.end()){
        cout<<"Invalid input";
        return 0;
    }
    for(char c : s){
        if(isalnum(c))
        str+=c;
    }
    cout<< str;
}