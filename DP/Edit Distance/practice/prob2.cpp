#include<bits/stdc++.h>
using namespace std;

int knapSack(vector<pair<int,int>>& items , int& weight){
    int n = items.size();
    vector<int> dp(weight+1);
    
    for(int i=1;i<= n;i++){
        for(int j=weight;j>=0;j--){
            if(items[i-1].first <= j){
                dp[j] = max(dp[j],dp[j-items[i-1].first] + items[i-1].second);
            }
        }
    }
    return dp[weight];
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> items(n);
    for(int i=0;i<n;i++){
        cin >> items[i].first;
        if(items[i].first < 0){
            cout << "Invalid input";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        cin >> items[i].second;
    }
    int weight ;
    cin >> weight;
    cout << knapSack(items,weight);
}