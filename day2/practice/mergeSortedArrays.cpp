/*

Given 'n' sorted arrays. Your task is to merge these n sorted arrays into a single sorted array using merge sort.
Input Format
• An integer n represents the number of sorted arrays.
• The next following lines contain an integer representing a number of elements in the sorted array and followed by its elements.
Output Format
• Display the single sorted array after merging all the n sorted arrays.
• Print Invalid input, if any non-numerical input is present.
Constraints
• 1 <n <= 100
• 1 <= number of elements in sorted array <= 1000

*/


#include<iostream>
#include<vector>

using namespace std;

vector<int> mergeSortedArray(vector<int>& arr1 , vector<int>& arr2) {
    vector<int> mergedArray;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] <= arr2[j]){
            mergedArray.push_back(arr1[i++]);
        } else {
            mergedArray.push_back(arr2[j++]);
        }
    }
    
    while(i<arr1.size()){
        mergedArray.push_back(arr1[i++]);
    }
    
    while (j<arr2.size()){
        mergedArray.push_back(arr2[j++]);
    }
    
    return mergedArray;
} 

vector<int> mergeArray(vector<vector<int>>& nums) {
    
    vector<int> mergedArray = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        mergedArray = mergeSortedArray(mergedArray , nums[i]);
    }
    
    return mergedArray;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n);
    
    for(int i=0;i<n;i++) {
        int size ;
        cin>>size;
        nums[i].resize(size);
        for(int j=0;j<size;j++){
            cin>>nums[i][j];
            if(cin.fail()){
                cout<<"Invalid input";
                return 0;
            }
        }
    }
    vector<int> arr = mergeArray(nums);
    for(int num : arr){
        cout<<num<<" ";
    }
}