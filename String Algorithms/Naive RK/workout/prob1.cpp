#include<iostream>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int l = t.length();
    for(char c : s){
        if(!isalpha(c)&& !isdigit(c)){
            cout<<"Invalid input";
            return 0;
        }
    }
    for(int i=0;i<=s.length()-l;i++){
        if(t==s.substr(i,l)){
            cout<<i<<endl;
        }
    }
}