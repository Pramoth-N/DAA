#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int coinChange(const vector<int>& coins , const int &target){
    int n = coins.size();
    vector<int> dp(target+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=target;i++){
        for(int j=0;j<n;j++){
            if(coins[j] <= i && dp[i-coins[j]] !=INT_MAX) {
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return dp[target] == INT_MAX? -1 : dp[target];
}

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
        if(coins[i] < 0){
            cout<<"Invalid input";
            return 0;
        }
    }
    int target ;
    cin>>target;
    
    cout << coinChange(coins , target);
}