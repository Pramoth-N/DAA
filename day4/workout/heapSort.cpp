
/*

Given an array of integers, implement the Heapsort algorithm to sort the array in ascending order.
Input Format
• An integer n represents the size of the array.
• The next line represents the value of the array.
Output Format
• Displays the array in the ascending order.
• Print -1, if the array is already sorted.
Constraints
• 1 <= n <= 100

*/

#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>& heap , int index , int n){
    int rev = index;
    int left = index*2 + 1 , right = index*2 + 2;
    if(left < n && heap[left] > heap[rev])
    rev = left;
    if(right < n && heap[right] > heap[rev])
    rev = right;
    
    if(rev != index) {
        swap(heap[rev] , heap[index]);
        heapify(heap,rev,n);
    }
}

void heapSort(vector<int>&heap , int n){
    for(int i=n/2-1 ;i>=0;i--) {
        heapify(heap , i , n);
    }
    for(int i=n-1;i>0;i--){
        swap(heap[0], heap[i]);
        heapify(heap , 0 , i);
    }
}

bool isSorted(vector<int> nums){
    for(int i=1;i<nums.size();i++) {
        if(nums[i-1] > nums[i])
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> heap(n);
    for(int i=0;i<n;i++){
        cin>>heap[i];
    }
    if(isSorted(heap)){
        cout<<-1;
        return 0;
    }
    heapSort(heap , n);
    for(int x : heap)
        cout<<x<<" ";
}