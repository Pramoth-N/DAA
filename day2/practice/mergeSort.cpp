/*

Given an array of 'n' integers, implement an in-place Merge Sort algorithm 
that does not use additional arrays for merging the sorted subarrays.
Input Format
• An integer n represents the number of elements in the array.
• The next lines n integers represents the value of elements in the array.
Output Format
• Performs the Merge Sort and prints the sorted array.
• If any non-numerical inputs are present, print Invalid input.
• If the array is already sorted, print -1.
Constraints
• 1 <n <= 100

*/

#include<iostream>

using namespace std;

void merge(int* nums , int left , int right ,int mid ) {
    int s1 = mid-left+1;
    int s2 = right - mid;
    
    int* leftArray = new int[s1];
    int* rightArray = new int[s2];
    for(int i=0;i<s1;i++){
        leftArray[i] = nums[left+i];
    }
    
    for(int i=0;i<s2;i++){
        rightArray[i] = nums[mid+i+1];
    }
    
    int leftIndex = 0 ,rightIndex = 0 , mergedIndex = left;
    
    while(leftIndex < s1 && rightIndex < s2) {
        if(leftArray[leftIndex] <= rightArray[rightIndex]) {
            nums[mergedIndex++] = leftArray[leftIndex++];
        } else {
            nums[mergedIndex++] = rightArray[rightIndex++];
        }
    }
    
    while(leftIndex < s1) {
        nums[mergedIndex++] = leftArray[leftIndex++];
    }
    
    while(rightIndex < s2) {
        nums[mergedIndex++] = rightArray[rightIndex++];
    }
    
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int* nums , int left , int right) {
    if(left >= right) {
        return;
    }
    
    int mid = (left + right) / 2;
    
    mergeSort(nums,left,mid);
    mergeSort(nums, mid+1,right);
    
    merge(nums ,left ,right , mid);
}

bool isSorted(int* nums , int n) {
    for(int i=1;i<n;i++) {
        if(nums[i-1] > nums[i])
        return false;
    }
    return true;
}

void print(int *nums , int n){
    for(auto i=0;i<n;i++) {
        cout<<nums[i]<<" ";
    }
}

int main() {
    int n ;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(cin.fail()) {
            cout<<"Invalid input";
            return 0;
        }
    }
    
    if(isSorted(nums ,n)){
        cout<<-1;
        return 0;
    }
    mergeSort(nums, 0 , n-1);
    
    print(nums , n);
}