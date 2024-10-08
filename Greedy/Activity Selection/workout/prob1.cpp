#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
        if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
    }
    int amount;
    cin>>amount;
    vector<int> dp(amount+1,100);
    vector<int> coinUsed(amount+1,-1);
    
    dp[0]=0;
    
    for(int i=1;i<=amount;i++){
        for(int coin : coins) {
            if(i-coin>=0 && dp[i-coin] != 100){
                if(dp[i]>dp[i-coin]+1){
                    dp[i]=dp[i-coin]+1;
                    coinUsed[i] = coin;
                }
            }
        }
    }
    if(dp[amount] == 100){
        cout<<-1;
        return 0;
    }
    cout<<dp[amount]<<endl;
    while(amount > 0){
        cout<<coinUsed[amount]<<" ";
        amount-=coinUsed[amount];
    }
}