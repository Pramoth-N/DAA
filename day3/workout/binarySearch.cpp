/*

Given a sorted array of integers, your task is to perform a binary search to find the index 0-based of a target element.
Input Format
• An integer n represents the size of the array.
• The next line contains n integers represents the value of the array.
• Last line contains an integer k, represents the target element.
Output Format
• Displays the index of the target element.
• Print Invalid input, if size of the array is negative or characters in the value of element.
• Print -1, if the target element does not found in the array.
Constraints
• -100 <= n <= 100

*/

#include<iostream>
using namespace std;

int binarySearch(int* nums ,int left ,int right, int target) {
    
    while(left <= right) {
        int mid = (left+right) / 2;
        if(nums[mid] == target) {
            return mid;
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