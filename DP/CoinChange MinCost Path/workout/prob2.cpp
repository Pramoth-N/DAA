#include<iostream>
#include<vector>
using namespace std;

int coinChange(const vector<int>& coins , const int &target){
    int n = coins.size();
    vector<int> dp(target+1,0);
    dp[0] = 1;
    for(int i=1;i<=target;i++){
        for(int coin : coins){
            if(coin <=i ){
                dp[i] += dp[i-coin];
            }
        }
    }
    return dp[target];
}

int main(){
    int n;
    int target ;
    cin>>target;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
        if(coins[i] < 0){
            cout<<"Invalid input";
            return 0;
        }
    }
    
    cout << coinChange(coins , target);
}