/*

Given a sorted array of integers and a target integer, 
find the index of the last occurrence of the target element in the array using Binary search.
Input Format
• An integer n represents the size of the array.
• The next line contains the value of the elements in an array.
• The last line contains an integer k.
Output Format
• Displays the index of the last occurrence of the target element.
• Print Invalid input, if any non-numerical inputs present in array.
• Print -1, if the target element is not found in the array.
Constraints
• 1 <n <= 100

*/

#include<iostream>
using namespace std;


int binarySearch(int* nums ,int left , int right , int target ) {
    if(nums[right] == target)
    return right;
    while(left < right) {
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

int main() {
    int n,target;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    }
    cin>>target;
    cout<<binarySearch(nums ,0, n-1, target);
}