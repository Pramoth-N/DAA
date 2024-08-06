/*

Given a sorted array of n integers and an integer x, 
implement a function to count the number of occurrences of k in the array using Binary Search.
Input Format
• An integer n represents the size of the array.
• The next line contains n integers representing the elements of the array.
• The last line contains an integer k.
Output Format
• Displays the count of the k in the array.
• Print Invalid input, if any non-numeric input present in array.
Constraints
• 1 <= n <= 100

*/


#include<iostream>
using namespace std;


int lastOccurence(int* nums ,int left , int right , int target ) {
    if(nums[right] == target){
        return right;
    }
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(nums[mid+1] > target && target == nums[mid]){
            return mid;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int firstOccurence(int* nums ,int left , int right , int target ) {
       if(nums[left] == target){
        return left;
    }
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(nums[mid-1] < target && target == nums[mid]){
            return mid;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int n,target;
    cin>>n;
    if(cin.fail()) {
        cout<<"Invalid input\n";
        return 0;
    }
    if(n<=0){
        cout<<"Invalid input";
        return 0;
    }
    int nums[n];
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    }
    cin>>target;
    if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    cout<<abs(lastOccurence(nums ,0, n-1, target) - firstOccurence(nums ,0, n-1, target) + 1);
}