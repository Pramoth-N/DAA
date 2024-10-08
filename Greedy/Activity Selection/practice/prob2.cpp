#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int start,end,weight;
};

int nonConflictActivity(vector<Node>& activities , int i){
    for(int j=i-1;j>=0;j--){
        if(activities[j].end <= activities[i].start){
            return j;
        }
    }
    return -1;
}
int main() {
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Invalid input";
        return 0;
    }
    vector<Node> activities(n);
    
    for(int i=0;i<n;i++){
        cin>>activities[i].start >> activities[i].end >> activities[i].weight ;
        if(activities[i].start > activities[i].end || activities[i].start < 0){
            cout<<"Invalid input";
            return 0;
        }
    }
    
    sort(activities.begin(),activities.end(),[](Node& a , Node& b){return a.end < b.end;});
    
    
    vector<int> dp(n,0);
    
    dp[0] = activities[0].weight;
    
    for(int i=1;i<n;i++){
        int initialWeight = activities[i].weight;
        int latestVal = nonConflictActivity(activities ,i);
        
        if(latestVal != -1){
            initialWeight += dp[latestVal];
        }
        
        dp[i] = max(initialWeight,dp[i-1]);
    }
    cout <<  dp[n-1];
    
}