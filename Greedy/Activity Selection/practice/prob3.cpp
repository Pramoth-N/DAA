#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int start,end,req;
};

int main() {
    int n;
    cin>>n;
    vector<Node> activities(n);
    
    for(int i=0;i<n;i++){
        cin>>activities[i].start >> activities[i].end >> activities[i].req ;
        if(activities[i].start > activities[i].end){
            cout<<"Invalid input";
            return 0;
        }
    }
    
    sort(activities.begin(),activities.end(),[](Node& a , Node& b){return a.end < b.end;});
    
    
    vector<Node> ans;
    ans.push_back(activities[0]);
    
    for(int i=1;i<n;i++){
        if(activities[i].start >= ans.back().end){
            ans.push_back(activities[i]);
        }
    }
    
    int totalreq=0;
    for(Node x : ans){
        cout<<x.start << " " << x.end <<" "<< x.req << "\n";
        totalreq += x.req;
    }
    cout<<totalreq;
    
    
}