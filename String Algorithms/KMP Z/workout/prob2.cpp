#include<iostream>
#include<vector>
#include<regex>
using namespace std;

vector<int> computeLPS(string& ptrn){
    int n = ptrn.size();
    int i = 1 , len = 0;
    vector<int> lps(n);
    lps[0] = 0;
    while(i<n){
        if(ptrn[i] == ptrn[len]){
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if(len != 0){
                len =lps[len-1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;   
}

bool KMPSearch(string s , string& ptrn){
    int n = s.size() , m = ptrn.size();
    
    vector<int> lps = computeLPS(ptrn);
    vector<int> result;
    int i=0,j=0;
    while(i<n){
        if(ptrn[j] == s[i]){
            i++;
            j++;
        }
        if(j==m){
            return true;
        } else {
            if(i<n && ptrn[j] != s[i]){
                if(j!=0){
                    j=lps[j-1];
                } else {
                    i++;
                }
            }
        }
    }
    return false;
}

int main(){
    string s,ptrn;
    // getline(cin,s);
    // getline(cin,ptrn);
    cin>>s>>ptrn;
    // regex r(R"([!@#$%^&*()_+-=,./[/]{}:"<>?])");
    
    // auto begin = sregex_iterator(s.begin(),s.end(),r);
    // auto end = sregex_iterator();
    for(char c : s)
    if(c !=' ' && !isalpha(c) && !isdigit(c)){
        cout<<"Invalid input";
        return 0;
    }
    
    if(KMPSearch(s+s,ptrn)){
        cout<<"True";
    } else {
        cout<<"False";
    }
}