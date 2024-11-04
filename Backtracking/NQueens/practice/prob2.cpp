/*
Given a set of N distinct integers, your task is to find and print the K-th permutation sequence in lexicographical order. A permutation is an arrangement of the elements in any order, and the lexicographical order is the natural order of permutations based on the numerical or alphabetical order of the elements.
Input Format
• The first line contains two integers, N and K.
• The second line contains N distinct integers representing the elements of the set.
Output Format
• Print the K-th permutation of the given set of integers in lexicographical order.
• If the input is invalid (e.g., K is greater than the total number of permutations or non-integer values), print "Invalid input"
Constraints
• 1 <= N <= 10
Sample Input 1:
3 4
2 3 1
Sample Output 1:
1 2 3
*/

#include<bits/stdc++.h>

using namespace std;

void permutate(vector<int>& nums, int k){

    for(int i=0;i<k-1;i++){
        next_permutation(nums.begin(),nums.end());
    }
    
    for(int x : nums){
        cout<<x<<" ";
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    if(n<=0 || k<0 || cin.fail()){
        cout<<"Invalid input";
        return 0;
    }
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i] < 0 || cin.fail()){
        cout<<"Invalid input";
        return 0;
    }
    }
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    permutate(nums,k);
}