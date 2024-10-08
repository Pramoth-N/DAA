#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int id,start,end;
};


int main(){
    int n;
    cin>>n;
    vector<Node> activities(n);
    
    for(int i=0;i<n;i++){
        cin>>activities[i].id >> activities[i].start >> activities[i].end;
        if(activities[i].start > activities[i].end){
            cout<< "Invalid input";
            return 0;
        }
    }
    
    vector<int> result;
    
    sort(activities.begin(),activities.end(),[](Node& a , Node& b){return a.end < b.end;});
    
    int last = 0;
    for(int i=0;i<n;i++){
        if(activities[i].start >= last){
            result.push_back(activities[i].id);
            last = activities[i].end;
        }
    }
    for(int x : result){
        cout<<x<<" ";
    }
    cout<<"\n"<<result.size();
}