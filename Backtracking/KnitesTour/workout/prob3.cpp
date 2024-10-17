#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

void compute(vector<int>& nums , int target , int index , vector<int> &comb , vector<vector<int>>& ans){
    if(target == 0){
        ans.push_back(comb);
        return ;
    }
    for(int i=index ;i<nums.size();i++){
        if(i>index && nums[i] == nums[i-1])
        continue;
        comb.push_back(nums[i]);
        compute(nums , target - nums[i],i+1,comb,ans);
        comb.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    if(cin.fail()|| n<=0){
            cout<<"Invalid input";
            return 0;
        }
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
    }
    int target;
    cin>>target;
    if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
    sort(nums.begin(),nums.end());
    vector<int> comb;
    vector<vector<int>> ans;
    compute(nums,target,0,comb,ans);
    if(ans.empty()){
        cout<<"[]";
    } else{
        for(auto combination : ans) {
            string s="";
            for(int num : combination){
                s+=" "+to_string(num) + ",";
            }
            s[0]  = '[';
            s.pop_back();
            s+="]";
            cout<<s<<"\n";
        }
        
    }
    
}