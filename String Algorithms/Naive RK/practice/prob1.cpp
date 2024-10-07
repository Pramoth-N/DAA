#include<iostream>
#include<regex>
using namespace std;

int findPattern(string s,string ptrn){
    int result = -1;
    int n=s.length() , m = ptrn.length();
    for(int i=0;i<=n-m;i++){
        if(s.substr(i,m) == ptrn)
        result = i;;
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    string s[n] , ptrn;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>ptrn;
    regex r("[!@#$%^&*()_+=-`~/.,><;:\\]|}{}]");
    vector<vector<int>> result(n);
    for(int i=0;i<n;i++){
        if(regex_search(s[i],r)!=0){
            cout<<"Invalid input";
            return 0;
        }
        cout<<findPattern(s[i],ptrn)<<endl;
    }
}