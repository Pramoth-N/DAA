#include<iostream>
#include<vector>
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

vector<int> KMPSearch(string& s , string& ptrn){
    int n = s.size() , m = ptrn.size();
    
    vector<int> lps = computeLPS(ptrn);
    vector<int> result;
    int i=0,j=0;
    while(n-i >= m-j){
        if(ptrn[j] == s[i]){
            i++;
            j++;
        }
        if(j==m){
            result.push_back(i-j);
            j= lps[j-1];
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
    return result;
}

int main(){
    string s,ptrn;
    getline(cin,s);
    getline(cin,ptrn);
    
    vector<int> result = KMPSearch(s,ptrn);
    if(result.size() == 0){
        cout<<"Pattern not found";
    } else {
        for(int res : result){
            cout<<res<<"\n";
        }
    }
}