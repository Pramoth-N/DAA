/*

Given an array of 'n' integers, you need to sort the array using the Merge Sort algorithm. Implement a function in which the user can specify whether to sort the array in ascending or descending order.
Input Format
• An integer n represents the size of the array.
• The next line contains in integers represents the value of elements in the array.
• An integer where 1 denotes ascending order and 2 denotes descending order.
Output Format
• Displays the sorted array in the specified order.
• Print Invalid input if any input is non-numerical.
• If the array is already sorted in the specified order, print -1.
Constraints
• 1 <= n <=100

*/

#include<iostream>
#include<vector>

using namespace std;

void mergeAscending(vector<int>& nums , int left ,int right , int mid){
    const int s1 = mid - left +1;
    const int s2 = right - mid;
    
    int* leftArray = new int[s1];
    int* rightArray = new int[s2];
    
    for(int i=0;i<s1;i++){
        leftArray[i] = nums[left+i];
    }
    for(int i=0;i<s2;i++){
        rightArray[i] = nums[mid+i+1];
    }
    
    int leftIndex = 0, rightIndex = 0, mergedIndex = left;
    while(leftIndex < s1 && rightIndex < s2) {
        if(leftArray[leftIndex] <= rightArray[rightIndex]){
            nums[mergedIndex++] = leftArray[leftIndex++];
        } else {
            nums[mergedIndex++] = rightArray[rightIndex++];
        }
    }
    
    while(leftIndex< s1) {
        nums[mergedIndex++] = leftArray[leftIndex++];
    }
    while(rightIndex < s2) {
        nums[mergedIndex++] = rightArray[rightIndex++];
    }
    
    delete[] leftArray;
    delete[] rightArray;
}

void mergeDescending(vector<int>& nums , int left ,int right , int mid){
   
    vector<int> leftArray(nums.begin()+left ,nums.begin()+mid+1);
    vector<int> rightArray(nums.begin()+mid+1 ,nums.begin()+right+1);
    int s1 = leftArray.size();
    int s2 = rightArray.size();
    int leftIndex = 0, rightIndex = 0, mergedIndex = left;
    while(leftIndex < s1 && rightIndex < s2) {
        if(leftArray[leftIndex] > rightArray[rightIndex]){
            nums[mergedIndex++] = leftArray[leftIndex++];
        } else {
            nums[mergedIndex++] = rightArray[rightIndex++];
        }
    }
    
    while(leftIndex< s1) {
        nums[mergedIndex++] = leftArray[leftIndex++];
    }
    while(rightIndex < s2) {
        nums[mergedIndex++] = rightArray[rightIndex++];
    }
    
}

void mergeSort(vector<int>& nums, int left , int right , int flag) {
    if(left >=right){
        return;
    }
    int mid = (left + right) / 2; 
    mergeSort(nums , left ,mid , flag);
    mergeSort(nums , mid + 1 , right , flag);
    if(flag == 1 ) {
        mergeAscending(nums ,left , right , mid);
    }else {
        mergeDescending(nums ,left , right , mid);
    }
}
bool isSorted(vector<int> nums , int flag) {
    if(flag == 1) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i])
            return false;
        }
        return true;
    }
    
    for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i])
            return false;
        }
        return true;
}
int main(){
    int n ,k;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    }
    cin>>k;
    if(isSorted(nums ,k)){
        cout<<-1;
        return 0;
    }
    if(k!=1 && k!= 2){
        cout<<"Invalid input";
        return 0;
    }
    mergeSort(nums, 0, n-1 , k);
    
    for(int num : nums) {
        cout<<num<<" ";
    }
}