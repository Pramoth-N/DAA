/*

Given an sorted array of integers that has been rotated at an unknown pivot point. 
Your task is to find the minimum element in this array using Binary search.
Input Format
• An integer n represents the size of the array.
• The next line contains n integers representing the value of the array.
Output Format
• Displays the minimum element in an array.
• Print Invalid input, if any non-numerical inputs present in array.
• Print -1, if all the elements in the array are same.
Constraints
• 1 <= n <=100

*/

#include<iostream>
using namespace std;

int binarySearch(int* nums ,int left ,int right) {
    if(nums[left] < nums[right]){
        return nums[left];
    }
    while(left <= right) {
        int mid = (left+right) / 2;
        if(nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        } 
        if(nums[mid] < nums[mid - 1]){
            return nums[mid];
        } 
        if(nums[mid] < nums[left]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return nums[left];
}

int main() {
    int n;
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
    if(nums[0] == nums[n-1]){
        cout<<-1;
    } else {
        cout<<binarySearch(nums ,0 , n-1);
    }
}