/*

Given an array of 'n' integers, implement the Quick Sort algorithm to sort the array in ascending order. The Quick Sort algorithm should use the last element of the array as the pivot.
Input Format
• An integer n representing the number of elements in the array.
• An array of n integers.
Output Format
• Display the sorted array in ascending order.
• If any input element is not an integer, output Invalid input.
• If the array is already sorted, output -1.
Constraints
• 1 <= n <= 100

*/

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& nums ,int low ,int high){
    int pivot = nums[high] , index = low-1;
    
    for(int i=low;i<high;++i) {
        if(nums[i] < pivot) {
            swap(nums[++index] ,nums[i]);
        }
    }
    
    swap(nums[++index] , nums[high]);
    return index;
}

void quickSort(vector<int>& nums, int low, int high) {
    if(low >= high){
        return;
    }
    
    int pivot = partition(nums ,low ,high);
    
    quickSort(nums , low ,pivot - 1);
    quickSort(nums , pivot + 1 ,high);
}

bool isSorted(vector<int> nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i])
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
    if(isSorted(nums )){
        cout<<-1;
        return 0;
    }
    quickSort(nums, 0, n-1);
    
    for(int num : nums) {
        cout<<num<<" ";
    }
}