/*
    Given an array of 'n' integers. Implement the Quick Sort algorithm to sort the array in ascending order. 
    Use the last element of the array as the pivot. To handle arrays with many duplicate elements efficiently, 
    use a three-way partitioning scheme.
Input Format
• An integer n representing the number of elements in the array.
• An array of n integers
Output Format
• Displays the sorted array in ascending order.
• If any element in the array is not an integer, output Invalid input.
• If the array is already sorted in ascending order, output -1.
Constraints
• 1 <= n <= 100
*/

#include<iostream>

using namespace std;

int partition(int* nums , int low , int high) {
    int pivot = nums[high] , index = low - 1;
    
    for(int i=low ;i<high ;i++) {
        if(nums[i] < pivot){
            swap(nums[++index] ,nums[i]);
        }
    }
    
    swap(nums[++index],nums[high]);
    
    return index;
}

void quickSort(int* nums , int low , int high) {
    if(low >= high) {
        return;
    }
    
    int pivot = partition(nums,low,high);
    
    quickSort(nums,low , pivot -1);
    quickSort(nums, pivot +1,high);
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
    quickSort(nums, 0 , n-1);
    
    print(nums , n);
}