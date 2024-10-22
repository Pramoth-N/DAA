#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> submaxSquare(vector<vector<int>> dp){
    int n = dp.size() , m = dp[0].size();
    // vector<vector<int>> dp{grid};
    int ans = 0 ,max_row =-1, max_col = -1;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i][j] == 1){
                dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                    max_row = i-ans+1;
                    max_col = j-ans+1;
                }
        }
    }
    
    return {ans , max_row , max_col};
}

int main(){
    int n ,m;
    cin >> n >> m;
    if(n<0 || m<0) {
        cout << "Invalid input";
        return 0;
    }
    vector<vector<int>> grid(n,vector<int>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] < 0){
                cout<<"Invalid input";
                return 0;
            }
        }
    }
    
    vector<int> result = submaxSquare(grid);
    for(int num : result){
        cout << num << " ";
    }
}