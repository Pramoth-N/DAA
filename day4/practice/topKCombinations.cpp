/*

    Given two sorted arrays, A and B, both of length n. You need to find the x largest sum combinations of elements from A and B. Each sum combination consists of one element from A and one element from B.
    Input Format
    • An integer n represents the size of both arrays.
    • The next line contains n integers representing the value of the first array.
    • The next line contains n integers representing the value of the second array.
    • The last line contains an integer k.
    Output Format
    • Displays the k largest sum combinations of elements from A and B.
    • Print Invalid input, if any characters entered as the value of array.
    Constraints
    • 1 <= n <= 100

*/

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<int,int> count;
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
        count[nums[i]]++;
    }
    int k;
    cin>>k;
    vector<pair<int,int>> count_vec(count.begin(),count.end());
    sort(count_vec.begin(),count_vec.end(),[](pair<int,int>&a ,pair<int,int>&b){return a.second >= b.second;});
    for(auto it = count_vec.begin();it<count_vec.begin()+k;it++){
        cout<<it->first<<" ";
    }
}