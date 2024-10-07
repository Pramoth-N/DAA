#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void computeLPS(vector<int>& lps , string pt){
    int len =0;
    lps[0]=0;
    int i=1 , n = pt.size();
    while(i<n){
        if(pt[i]==pt[len]){
            len++;
            lps[i++] = len;
        } else {
            if(len != 0){
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }
    }
}

vector<int> KMPSearch(string& s , string& pt){
    int m = pt.size();
    int n = s.size();
    vector<int> lps(m);
    computeLPS(lps,pt);
    int i=0 ,j=0 ;
    vector<int> result;
    while(n-i >= m-j){
        if(pt[j] == s[i]){
            i++;
            j++;
        }
        if(j==m){
            result.push_back(i-j);
            j=lps[j-1];
        } else if(i<n && pt[j] != s[i]){
            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return result;
}

int main(){
    string s,pt;
    getline(cin,s);
    getline(cin,pt);
    vector<int> result = KMPSearch(s,pt);
    if(result.empty()){
        cout<<"Pattern not found";
    } else {
        for(int index : result){
            cout<<index << "\n";
        }
    }
}