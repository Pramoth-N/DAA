#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int start,end,penality;
};


int main(){
    int n;
    cin>>n;
    vector<Node> activities(n);
    
    for(int i=0;i<n;i++){
        cin>> activities[i].start >> activities[i].end >>activities[i].penality;
        if(activities[i].start > activities[i].end){
            cout<< "Invalid input";
            return 0;
        }
    }
    
    sort(activities.begin(),activities.end(),[](Node& a , Node& b){return a.end < b.end;});
    
    vector<Node> result;
    
    result.push_back(activities[0]);
    
    for(int i=1;i<n;i++){
        if(activities[i].start >= result.back().end){
            result.push_back(activities[i]);
        }
    }
    int ttl = 0;
    for(auto x : result){
        ttl+=x.penality;
        cout<<x.start<<" " << x.end << " " << x.penality << "\n";
    }
    cout<<ttl;
}