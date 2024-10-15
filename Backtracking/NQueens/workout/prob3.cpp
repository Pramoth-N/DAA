/*
Given a set of distinct integers, your task is to generate and print all possible
permutations of the set. A permutation is an arrangement of the elements in any order
Input Format
• The first line contains a single integer N representing the number of elements in the set.
• The second line contains N integers, representing the elements of the set.
Output Format
• Print all possible permutations of the given set of integers.
• If the input is invalid (e.g., if N is not an integer or N ≤ 0), print Invalid input.
Constraints
-10 <= N <= 10
Sample Input 1:
3
Sample Output 1:
123
123
132
213
231
321
*/

#include<iostream>
#include<vector>

using namespace std;

void permutate(vector<int>& nums , int start){
    if(start == nums.size()-1){
        for(int num : nums){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i= start ; i<nums.size();i++){
        swap(nums[start], nums[i]);
        permutate(nums,start+1);
        swap(nums[start], nums[i]);
    }
}
int main(){
    int n;
    cin>>n;
    if(n<=0){
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
    
    permutate(nums,0);
}