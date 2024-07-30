/*

Given a sorted array of integers and a target integer. 
Your task is to find the index of the first occurrence of the target element in the array.
Input Format
• An integer n represents the size of the array.
• The next line contains the integers represents the values of the array.
• The last line contains an integer k.
Output Format
Displays the index of the first occurrence of the target element.
• • Print Invalid input, if any non numerical inputs present
• Print -1, if the target element is not found in the array.
Constraints
• 1 <= n <= 100

*/

#include<iostream>
using namespace std;
int firstIndex(int* nums , int left , int right , int target){
    for(int i=right ;i>left;i--){
        if(nums[i-1] != target){
            return i;
        }
    }
    return left;
}
int binarySearch(int* nums ,int left ,int right, int target) {
    
    while(left <= right) {
        int mid = (left+right) / 2;
        if(nums[mid] == target) {
            return firstIndex(nums,left,mid,target);
        } else if(nums[mid] < target){
            left = mid + 1;
        } else {
            right = mid -1 ;
        }
    }
    
    return -1;
}

int main() {
    int n,target;
    cin>>n;
    if(n<=0){
        cout<<"Invalid input";
        return 0;
    }
    int nums[n];
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
    }
    cin>>target;
    
    cout<<binarySearch(nums ,0 ,n-1 ,target);
}