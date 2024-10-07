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

int KMPSearch(string& s , string& pt){
    int m = pt.size();
    int n = s.size();
    vector<int> lps(m);
    computeLPS(lps,pt);
    int i=0 ,j=0 ,cnt = 0;
    while(n-i >= m-j){
        if(pt[j] == s[i]){
            i++;
            j++;
        }
        if(j==m){
            cnt++;
            j=lps[j-1];
        } else if(i<n && pt[j] != s[i]){
            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return cnt;
}

int main(){
    string s,pt;
    getline(cin,s);
    cin>>pt;
    bool spltxt = find_if(s.begin(),s.end(),[](char ch){return !isalnum(ch) && ch != ' ';}) != s.end();
    bool splptrn = find_if(pt.begin(),pt.end(),[](char ch){return !isalnum(ch) && ch != ' ';}) != pt.end();
    if(spltxt || splptrn){
        cout<<"Invalid input";
    } else {
        int result;
        cout<< ((result = KMPSearch(s,pt)) != 0 ? result : -1);
    }
}