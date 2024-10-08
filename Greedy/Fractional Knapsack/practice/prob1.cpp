#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fractionalKnapsack(int cap , vector<pair<int,int>>& items ){
    int n = items.size();
    
    sort(items.begin(),items.end(),[](pair<int,int> a,pair<int,int> b){
       double r1 = (double)a.second / a.first ; 
       double r2 = (double)b.second / b.first ;
       return r1 > r2;
    });
    
    double max_val = 0;
    
    for(pair<int,int> item : items){
        if(cap >=item.first){
            cap-=item.first;
            max_val+= item.second;
        } else {
            max_val+= item.second * ((double)cap / item.first);
            break;
        }
    }
    return max_val;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].first>>items[i].second;
    }
    int cap;
    cin>>cap;
    bool flag = true;
    for(auto item : items){
        if(item.first<=cap){
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"Invalid input";
    } else {
        cout<<fractionalKnapsack(cap,items);
    }
}