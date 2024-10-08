#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


pair<float,int> fractionalknapsack(int& cap ,vector<pair<int,int>>& Items) {
    
    sort(Items.begin(),Items.end(),
    [](pair<int,int>& a,pair<int,int>& b)
    {
        return (double)a.first/a.second > (double)b.first/b.second ;
        
    });
    
    float totalVal = 0.0;
    int capacity = cap;
    for(int i=0;i<Items.size();i++){
        if(capacity >=Items[i].second){
            totalVal += Items[i].first;
            capacity -= Items[i].second;
        } else {
            float f = (double)capacity / Items[i].second;
            totalVal += f * Items[i].first;
            capacity = 0;
            break;
        }
    }
    
    return {totalVal,capacity};
}

int main() {
    int n,cap;
    cin>>n >> cap;
    vector<pair<int,int>> Items(n);
    
    for(int i=0;i<n;i++){
        cin>>Items[i].first >> Items[i].second;
        
        if(Items[i].second > cap){
            cout<<"Invalid input";
            return 0;
        }
    }
    
    pair<float,int> ans = fractionalknapsack(cap ,Items);
    
    if(ans.first !=0){
        cout << fixed << setprecision(2) << ans.first << "\n";
        cout<< ans.second;
    } else {
        cout << "Invalid input";
    }
}