#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int knapsack(int cap ,vector<int>& weights , vector<int>& values) {
    
    int n = weights.size();
    vector<vector<int>> dp(n+1,vector<int>(cap+1 , 0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap ;j++){
            if(weights[i-1] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j] , values[i-1] + dp[i-1][j-weights[i-1]]);
            }
        }
    }
    
    return dp[n][cap];
}

int main() {
    int n,cap;
    cin>>n;
    vector<int> weights(n);
    vector<int> values(n);
    
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    
    cin>>cap;
    
    int maxVal = knapsack(cap ,weights ,values );
    
    if(maxVal !=0){
        cout<<maxVal;
    } else {
        cout << "Invalid input";
    }
}