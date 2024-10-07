#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    cin>>t;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    transform(t.begin(),t.end(),t.begin(),::tolower);
    // cout<<s;
    int l = t.length();
    
    for(char c : s){
        if(c!=' ' && !isalnum(c)){
            cout<<"Invalid input";
            return 0;
        }
    }
    bool flag = false;
    for(int i=0;i<=s.length()-l;i++){
        if(t==s.substr(i,l)){
            cout<<i<<endl;
            flag = true;
        }
    }
    
    if(!flag){
        cout << "-1" << endl;
    }
}